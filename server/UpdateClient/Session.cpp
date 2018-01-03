#include "Session.h"
#include "boost/asio/spawn.hpp"
#include "boost/asio/write.hpp"
#include "boost/asio/read.hpp"


void update::client::Session::go()
{
	auto self(shared_from_this());
	boost::asio::spawn(socket_.get_io_service(), [this, self](boost::asio::yield_context yield)
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
			printf("%s begin to recv update file\n", endpoint_.address().to_string().c_str());

			//send install_file_name£¬can not be more than SEND_SIZE_MAX - HEAD_SIZE
			sendInstallFileName(yield);

			/*auto buffer_size = HEAD_SIZE + install_file_name_.length() + 1;
			auto buffer_ptr = std::shared_ptr<char>(new char[buffer_size], [](char*p) {delete[]p; });
			buffer_ptr.get()[0] = 1; buffer_ptr.get()[1] = 0; buffer_ptr.get()[2] = 0; buffer_ptr.get()[3] = 1;
			setPacketRemain(buffer_ptr, install_file_name_.c_str(), static_cast<uint16_t>(install_file_name_.length() + 1));
			boost::asio::async_write(socket_, boost::asio::buffer(buffer_ptr.get(), buffer_size), yield);*/

			//recv version
			boost::asio::async_read(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
			recvMessage(head, last_version, yield);

			//boost::asio::async_read(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
			//uint16_t data_legth_net = 0;
			//std::memcpy(&data_legth_net, head + 4, sizeof(uint16_t));
			//auto data_legth = boost::asio::detail::socket_ops::network_to_host_short(data_legth_net);
			//std::string last_version = "";
			//if (head[0] == 1 && head[1] == 0 && head[2] == 0 && head[3] == 5) //version
			//{
			//	memset(data, 0, SEND_SIZE_MAX - HEAD_SIZE);
			//	boost::asio::async_read(socket_, boost::asio::buffer(data, data_legth), yield);
			//	last_version = data;
			//}

			int size = static_cast<int>(update_file_name_vec_.size());
			for (int i = 0; i < size; ++i)
			{
				if (file_.is_open())
					file_.close();
				auto path_update_file_name = update_file_path_.append(update_file_name_vec_[i]);
				file_.assign(CreateFile(path_update_file_name.c_str(), GENERIC_READ, FILE_SHARE_READ, 0,
					OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0));
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
					}
					else
					{
						if (ec.value() == 2 && ec.message() == "End of file")
						{
							if (1 == size) //install packet
							{
								head[0] = 1; head[1] = 0; head[2] = 0; head[3] = 3;
								boost::asio::async_write(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
								printf("%s begin to update\n", endpoint_.address().to_string().c_str());
							}
							else if ((i + 1) == size) //all file send out ok,binary replace
							{
								head[0] = 1; head[1] = 0; head[2] = 0; head[3] = 4;
								boost::asio::async_write(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
								printf("%s begin to update\n", endpoint_.address().to_string().c_str());
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
			printf("%s,%s update failed! Please try again for next time\n", e.what()
				, endpoint_.address().to_string().c_str());
		}
		catch (...)
		{
			all_send = false;
			printf("unknow exception,%s update failed! Please try again for next time\n",
				endpoint_.address().to_string().c_str());
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
							printf("connect %s failed!\n", endpoint_.address().to_string().c_str());
							--connect_times;
							//std::this_thread::sleep_for(std::chrono::milliseconds(3000));
						}
						else //connect ok;
						{
							//send install_file_name£¬can not be more than SEND_SIZE_MAX - HEAD_SIZE
							sendInstallFileName(yield);
							boost::asio::async_read(socket_, boost::asio::buffer(head, HEAD_SIZE), yield[ec]);
							std::string this_version = "";
							recvMessage(head, this_version, yield);
							if (last_version == this_version) //check version
							{
								printf("last version(%s) is same as this version(%s),server(%s) update failed!!",
									last_version.c_str(), this_version.c_str(), endpoint_.address().to_string().c_str());
							}
							else
								printf("server(%s) should update ok", endpoint_.address().to_string().c_str());
							break;
							//boost::asio::async_read(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
							//uint16_t data_legth_net = 0;
							//std::memcpy(&data_legth_net, head + 4, sizeof(uint16_t));
							//auto data_legth = boost::asio::detail::socket_ops::network_to_host_short(data_legth_net);
							//
							//if (head[0] == 1 && head[1] == 0 && head[2] == 0 && head[3] == 5) //version
							//{
							//	memset(data, 0, SEND_SIZE_MAX - HEAD_SIZE);
							//	boost::asio::async_read(socket_, boost::asio::buffer(data, data_legth), yield);
							//	this_version = data;
							//}
						}
					}
					if (connect_times == 0)
					{
						printf("connect %s failed with 5 times! server maybe failed with updating!!! please make sure by youself!\n"
							, endpoint_.address().to_string().c_str());
					}
					run = false;
				}
				else // recv server error message
				{
					std::string error_message = "";
					recvMessage(head, error_message, yield);
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

void update::client::Session::recvMessage(const char* head, std::string & message, boost::asio::yield_context & yield)
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
		printf("server updating failed ,%s\n", data);
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
