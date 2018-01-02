#include "Session.h"
#include <boost/asio/write.hpp>
#include <boost/asio/write_at.hpp>
#include <boost/asio/read.hpp>
#include "LogMacros.h"
#include "Update.h"
#include "Update_installPacket.h"
#include "PlatformWin.h"

void update::server::Session::go()
{
	auto self = shared_from_this();
	boost::asio::spawn(socket_.get_io_service(), [this, self](boost::asio::yield_context yield)
	{
		try
		{
			auto ret = PlatformWin::isDirectory(FILE_FOLDER);
			if (ret)
				PlatformWin::deleteDirectory(FILE_FOLDER); //delete the update_file of last time

			char head[HEAD_SIZE] = { 0 };
			char data[SEND_SIZE_MAX - HEAD_SIZE] = { 0 };
			uint64_t offset = 0;
			//get install_file_name from client
			boost::asio::async_read(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
			uint16_t data_legth_net = 0;
			std::memcpy(&data_legth_net, head + 4, sizeof(uint16_t));
			auto data_legth = boost::asio::detail::socket_ops::network_to_host_short(data_legth_net);
			if (head[0] == 1 && head[1] == 0 && head[2] == 0 && head[3] == 1) //name
			{
				boost::asio::async_read(socket_, boost::asio::buffer(data, data_legth), yield);
				std::string install_file_name = data;

				//send version,can not be more than SEND_SIZE_MAX - HEAD_SIZE
				auto ptr = std::make_shared<Update<void>>(install_file_name);
				auto version = ptr->getLastDisplayVersion();
				auto buffer_size = HEAD_SIZE + version.length() + 1;
				auto buffer_ptr = std::shared_ptr<char>(new char[buffer_size], [](char*p) {delete[]p; });
				buffer_ptr.get()[0] = 1; buffer_ptr.get()[1] = 0; buffer_ptr.get()[2] = 0; buffer_ptr.get()[3] = 5;//version
				setPacketRemain(buffer_ptr, version.c_str(), static_cast<uint16_t>(version.length() + 1));
				boost::asio::async_write(socket_, boost::asio::buffer(buffer_ptr.get(), buffer_size), yield);
			}

			std::vector<std::string> update_file_name_vec; //record all update file name
			for (;;)
			{
				boost::asio::async_read(socket_, boost::asio::buffer(head, HEAD_SIZE), yield);
				std::memcpy(&data_legth_net, head + 4, sizeof(uint16_t));
				data_legth = boost::asio::detail::socket_ops::network_to_host_short(data_legth_net);

				if (head[0] == 1 && head[1] == 0 && head[2] == 0 && head[3] == 2) //content
				{
					boost::asio::async_read(socket_, boost::asio::buffer(data, data_legth), yield);
					boost::asio::async_write_at(file_, offset, boost::asio::buffer(data, data_legth), yield);
					offset += data_legth;
				}
				else if (head[0] == 1 && head[1] == 0 && head[2] == 0 && head[3] == 1) //name
				{
					memset(data, 0, SEND_SIZE_MAX - HEAD_SIZE);
					boost::asio::async_read(socket_, boost::asio::buffer(data, data_legth), yield);
					std::string update_file_name = data;
					update_file_name_vec.emplace_back(update_file_name);

					//make directory,write update file
					PlatformWin::makeDirectory(FILE_FOLDER);
					std::string path_and_name = FILE_FOLDER;
					path_and_name.append("/").append(update_file_name);
					if (file_.is_open())
						file_.close();
					file_.assign(PlatformWin::makeFile(path_and_name));
				}
				else if (head[0] == 1 && head[1] == 0 && head[2] == 0 && head[3] == 3) //can update now,update with installPacket
				{
					if (file_.is_open())
						file_.close();
					/*if (socket_.is_open())
						socket_.close();*/
					//the process will exit,then release the scoekt reasource. Do not release initiatively,or logic will be error!!
					UPDATESERVER_INFO("start update with install packet");
					auto update_ptr = std::make_shared<Update<UpdateInstallPacket>>(update_file_name_vec[0]);// must has only a element
					update_ptr->startUpdate();
				}
				else if (head[0] == 1 && head[1] == 0 && head[2] == 0 && head[3] == 4) //can update now,update with binaryReplace
				{
					if (file_.is_open())
						file_.close();
					/*if (socket_.is_open())
						socket_.close();*/
					UPDATESERVER_INFO("start update with binary replace");
				}
			}
		}
		catch (std::exception& e)
		{
			sendErrorMessage(e.what(), yield);
			UPDATESERVER_ERROR("%s,coroutine exit", e.what());
		}
		catch (...)
		{
			sendErrorMessage("unknow exception", yield);
			UPDATESERVER_ERROR("coroutine exit with unknow exception!!");
		}

		if (file_.is_open())
			file_.close();
		if (socket_.is_open())
			socket_.close();
	});
}

void update::server::Session::setPacketRemain(std::shared_ptr<char> send_buffer, const char * data_buffer, const uint16_t data_size)
{
	auto length_net = boost::asio::detail::socket_ops::host_to_network_short(static_cast<uint16_t>(data_size));
	std::memcpy(send_buffer.get() + 4, &length_net, sizeof(uint16_t));
	std::memcpy(send_buffer.get() + HEAD_SIZE, data_buffer, data_size);
}

void update::server::Session::sendErrorMessage(const std::string& message_content, boost::asio::yield_context & yield)
{
	auto error_message_size = message_content.length() + 1;
	auto buffer_size = HEAD_SIZE + error_message_size;
	if (buffer_size > SEND_SIZE_MAX - HEAD_SIZE)//can not be more than SEND_SIZE_MAX - HEAD_SIZE
	{
		std::ostringstream message;
		message << "ErrorMessage(" << message_content << ")" << "is too large! Please make it shorter";
		throw std::length_error(message.str());
	}
	auto buffer_ptr = std::shared_ptr<char>(new char[buffer_size], [](char*p) {delete[]p; });
	buffer_ptr.get()[0] = 1; buffer_ptr.get()[1] = 0; buffer_ptr.get()[2] = 0; buffer_ptr.get()[3] = 6;//error message
	setPacketRemain(buffer_ptr, message_content.c_str(), static_cast<uint16_t>(error_message_size));
	boost::system::error_code ec;
	boost::asio::async_write(socket_, boost::asio::buffer(buffer_ptr.get(), buffer_size), yield[ec]);
	if (ec)
		UPDATESERVER_WARN("send error message(%s) failed,%s", message_content.c_str(), ec.message().c_str());
}
