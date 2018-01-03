#pragma once
#ifndef SERVER_CLIENT_UPDATECLIENT_H
#define SERVER_CLIENT_UPDATECLIENT_H
#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include "UpdateClientDef.h"

namespace update { 
	namespace client { 
		class IoServicePool;
		//class Session;
	} 
}

namespace update
{
	namespace client
	{
		class Client
		{
		private:
			std::shared_ptr<IoServicePool> io_service_pool_ptr_;
		public:
			typedef std::function<void(const std::string&)> InstallMessageCallback;
			typedef std::function<void(int, int)> InstallProgressCallback;
		public:
			static Client& Instance();
			void makeSession(const std::string& ip, const uint16_t port,
				const std::string& intsall_file_name, const std::string& update_file_path,
				const std::vector<std::string>& update_file_name_vec,
				const UpdateStatusCallback& updateStatusCb);
			void run();
			void stop();
		private:
			Client(){}
			Client(const Client& client) = delete;
			Client& operator=(const Client&) = delete;
		};
	}
}
#endif