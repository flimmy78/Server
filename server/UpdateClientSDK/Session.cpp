#include "Session.h"
#include "boost/asio/spawn.hpp"
#include "boost/asio/write.hpp"
#include "boost/asio/read.hpp"


void update::client::Session::go(const UpdateStatusCallback& updateStatusCb)
{
	auto self(shared_from_this());
	boost::asio::spawn(socket_.get_io_service(),
		[this, self, &updateStatusCb](boost::asio::yield_context yield)
	{
		bool all_send = true;
		boost::system::error_code ec;
		char head[HEAD_SIZE] = { 0 };
		char data[SEND_SIZE_MAX - HEAD_SIZE] = { 0 };
		std::string last_version = "";
		try
		{
			//once send unsuccessfully,must do all again. All successfully or all unsuccessfully
			socket_.async_connect(endpoint_, yield);
			if (updateStatusCb)
			{
				std::string message = endpoint_.address().to_string();
				message.append(" begin to recv update file");
				updateStatusCb(0, (uint64_t)0, (uint64_t)0, message);
			}
			//send install_file_name£¬can not be more than SEND_SIZE_MAX - HEAD_SIZE
			sendInstallFileName(yield);

			//recv version
			boost::asio::async_read(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
			recvMessage(head, last_version, updateStatusCb, yield);

			int size = static_cast<int>(update_file_name_vec_.size());
			for (int i = 0; i < size; ++i)
			{
				if (file_.is_open())
					file_.close();
				uint64_t file_size = 0;
				auto path_update_file_name = update_file_path_.append(update_file_name_vec_[i]);
				auto handle = CreateFileA(path_update_file_name.c_str(), GENERIC_READ, FILE_SHARE_READ, 0,
					OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);
				if (handle != INVALID_HANDLE_VALUE)
				{
					file_.assign(handle);
					DWORD size_high = 0;
					auto size_low = GetFileSize(handle, &size_high);
					if (INVALID_FILE_SIZE == size_low && GetLastError() != NO_ERROR)
					{
						std::ostringstream message;
						message << "GetFileSize(" << path_update_file_name << ")" << "error with:" << GetLastError();
						throw std::runtime_error(message.str());
					}
					file_size = file_size & size_high;
					file_size = (file_size << 32) & size_low;
				}
				else
				{
					std::ostringstream message;
					message << "CreateFileA(" << path_update_file_name << ")" << "error with:" << GetLastError();
					throw std::runtime_error(message.str());
				}

				//send install_file_name£¬can not be more than SEND_SIZE_MAX - HEAD_SIZE
				sendInstallFileName(yield);

				uint64_t offset = 0;
				for (;;)
				{
					auto len = file_.async_read_some_at(offset, boost::asio::buffer(data, SEND_SIZE_MAX - HEAD_SIZE), yield[ec]);
					if (!ec)
					{
						offset += len;
						auto buffer_size1 = HEAD_SIZE + len;
						auto buffer_ptr1 = std::shared_ptr<char>(new char[buffer_size1], [](char*p) {delete[]p; });
						buffer_ptr1.get()[0] = 1; buffer_ptr1.get()[1] = 0; buffer_ptr1.get()[2] = 0; buffer_ptr1.get()[3] = 2;//content
						setPacketRemain(buffer_ptr1, data, static_cast<uint16_t>(len));
						boost::asio::async_write(socket_, boost::asio::buffer(buffer_ptr1.get(), buffer_size1), yield);
						if (updateStatusCb)
						{
							updateStatusCb(0, file_size, offset, "");
						}
					}
					else
					{
						if (ec.value() == 2 && ec.message() == "End of file")
						{
							if (1 == size) //install packet
							{
								head[0] = 1; head[1] = 0; head[2] = 0; head[3] = 3;
								boost::asio::async_write(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
								if (updateStatusCb)
								{
									std::string message = endpoint_.address().to_string();
									message.append(" begin to update");
									updateStatusCb(0, (uint64_t)0, (uint64_t)0, message);
								}
							}
							else if ((i + 1) == size) //all file send out ok,binary replace
							{
								head[0] = 1; head[1] = 0; head[2] = 0; head[3] = 4;
								boost::asio::async_write(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
								if (updateStatusCb)
								{
									std::string message = endpoint_.address().to_string();
									message.append(" begin to update");
									updateStatusCb(0, (uint64_t)0, (uint64_t)0, message);
								}
							}
							break;
						}
						else
						{
							std::ostringstream message;
							message << "read file(" << path_update_file_name << ")" << "error with:" << ec.message();
							throw std::runtime_error(message.str());
						}
					}
				}
			}
		}
		catch (const std::exception& e)
		{
			all_send = false;
			if (updateStatusCb)
			{
				std::string message = e.what();
				message.append(",").append(endpoint_.address().to_string());
				message.append(" update failed! Please try again for next time");
				updateStatusCb(-1, (uint64_t)0, (uint64_t)0, message);
			}
		}
		catch (...)
		{
			all_send = false;
			if (updateStatusCb)
			{
				std::string message = "unknow exception";
				message.append(",").append(endpoint_.address().to_string());
				message.append(" update failed! Please try again for next time");
				updateStatusCb(-1, (uint64_t)0, (uint64_t)0, message);
			}
		}

		// server can update
		if (all_send)
		{
			int connect_times = 5; //if all used ,server maybe failed with updating
			bool run = true;
			while (run)
			{
				//head[0] = 1; head[1] = 0; head[2] = 0; head[3] = 0; //for test alive
				boost::asio::async_read(socket_, boost::asio::buffer(head, HEAD_SIZE), yield[ec]);
				if (ec) // server close the connection because of begining to update
				{
					if (socket_.is_open())
						socket_.close();
					while (connect_times)
					{
						socket_.async_connect(endpoint_, yield[ec]);
						if (ec)
						{
							if (updateStatusCb)
							{
								std::string message = "connect";
								message.append(" ").append(endpoint_.address().to_string());
								message.append(" failed!");
								updateStatusCb(-1, (uint64_t)0, (uint64_t)0, message);
							}
							--connect_times;
						}
						else //connect ok;
						{
							//send install_file_name£¬can not be more than SEND_SIZE_MAX - HEAD_SIZE
							sendInstallFileName(yield);
							boost::asio::async_read(socket_, boost::asio::buffer(head, HEAD_SIZE), yield[ec]);
							std::string this_version = "";
							recvMessage(head, this_version, updateStatusCb, yield);
							if (last_version == this_version) //check version
							{
								if (updateStatusCb)
								{
									std::string message = "last version(";
									message.append(last_version).append(")").append(" is same as this version(")
										.append(this_version).append(")").append(",server(")
										.append(endpoint_.address().to_string()).append(")").append(" update failed!!");
									updateStatusCb(-1, (uint64_t)0, (uint64_t)0, message);
								}
							}
							else
							{
								if (updateStatusCb)
								{
									std::string message = "server(";
									message.append(endpoint_.address().to_string()).append(")").append(" should update ok");
									updateStatusCb(0, (uint64_t)0, (uint64_t)0, message);
								}
							}
							break;
						}
					}
					if (connect_times == 0)
					{
						if (updateStatusCb)
						{
							std::string message = "connect ";
							message.append(endpoint_.address().to_string()).append(")")
								.append(" failed with 5 times! server maybe failed with updating!!! please make sure by youself!");
							updateStatusCb(-1, (uint64_t)0, (uint64_t)0, message);
						}
					}
					run = false;
				}
				else // recv server error message
				{
					std::string error_message = "";
					recvMessage(head, error_message, updateStatusCb, yield);
					run = false;
				}
			}
		}

		if (socket_.is_open())
			socket_.close();
		if (file_.is_open())
			file_.close();
	});
}

void update::client::Session::setPacketRemain(std::shared_ptr<char> send_buffer, const char * data_buffer, const uint16_t data_size)
{
	auto length_net = boost::asio::detail::socket_ops::host_to_network_short(static_cast<uint16_t>(data_size));
	std::memcpy(send_buffer.get() + 4, &length_net, sizeof(uint16_t));
	std::memcpy(send_buffer.get() + HEAD_SIZE, data_buffer, data_size);
}

void update::client::Session::recvMessage(const char* head, std::string & message,
	const UpdateStatusCallback& updateStatusCb, boost::asio::yield_context & yield)
{
	char data[SEND_SIZE_MAX - HEAD_SIZE] = { 0 };
	uint16_t data_legth_net = 0;
	std::memcpy(&data_legth_net, head + 4, sizeof(uint16_t));
	auto data_legth = boost::asio::detail::socket_ops::network_to_host_short(data_legth_net);
	boost::asio::async_read(socket_, boost::asio::buffer(data, data_legth), yield);
	if (head[0] == 1 && head[1] == 0 && head[2] == 0 && head[3] == 5) //version message
	{
		message = data;
	}
	else if (head[0] == 1 && head[1] == 0 && head[2] == 0 && head[3] == 6) //error message
	{
		if (updateStatusCb)
		{
			std::string error_message = data;
			error_message.append(",server update failed");
			updateStatusCb(-1, (uint64_t)0, (uint64_t)0, error_message);
		}
	}
}

void update::client::Session::sendInstallFileName(boost::asio::yield_context & yield)
{
	auto buffer_size = HEAD_SIZE + install_file_name_.length() + 1;
	auto buffer_ptr = std::shared_ptr<char>(new char[buffer_size], [](char*p) {delete[]p; });
	buffer_ptr.get()[0] = 1; buffer_ptr.get()[1] = 0; buffer_ptr.get()[2] = 0; buffer_ptr.get()[3] = 1;
	setPacketRemain(buffer_ptr, install_file_name_.c_str(), static_cast<uint16_t>(install_file_name_.length() + 1));
	boost::asio::async_write(socket_, boost::asio::buffer(buffer_ptr.get(), buffer_size), yield);
}
