#pragma once
#ifndef SERVER_CLIENT_UPDATECLIENT_SESSION_H
#define SERVER_CLIENT_UPDATECLIENT_SESSION_H
#include <vector>
#include "boost/asio/ip/tcp.hpp"
#include "boost/asio/windows/random_access_handle.hpp"
#include "boost/asio/io_service.hpp"
#include <boost/asio/spawn.hpp>

namespace update
{
	namespace client
	{
		const int HEAD_SIZE = 16;
		const int SEND_SIZE_MAX = 1024;

		class Session :public std::enable_shared_from_this<Session>
		{
		private:
			boost::asio::ip::tcp::socket socket_;
			boost::asio::ip::tcp::endpoint endpoint_;
			boost::asio::windows::random_access_handle file_;
			std::string install_file_name_;
			std::string update_file_path_;
			std::vector<std::string> update_file_name_vec_;
		public:
			explicit Session(boost::asio::io_service& io_service, const std::string& server_addr,
				const uint16_t port, const std::string& install_file_name, const std::string& update_file_path,
				const std::vector<std::string>& update_file_name_vec)
				:socket_(io_service),
				endpoint_(boost::asio::ip::address::from_string(server_addr), port),
				file_(io_service),
				install_file_name_(install_file_name),
				update_file_path_(update_file_path),
				update_file_name_vec_(std::move(update_file_name_vec)) {}

			void go();
		private:
			void setPacketRemain(std::shared_ptr<char> send_buffer, const char* data_buffer, const uint16_t data_size);
			void recvMessage(const char* head, std::string& message, boost::asio::yield_context& yield);
			void sendInstallFileName(boost::asio::yield_context& yield);
		private:
			Session(const Session&) = delete;
			Session& operator=(const Session&) = delete;
		};
	}
}
#endif