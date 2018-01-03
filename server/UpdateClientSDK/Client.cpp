#include "Client.h"
#include <thread>
#include "IoServicePool.h"
#include "Session.h"

update::client::Client & update::client::Client::Instance()
{
	static Client obj;
	return obj;
}

void update::client::Client::makeSession(const std::string & ip, const uint16_t port,
	const std::string & intsall_file_name, const std::string & update_file_path, 
	const std::vector<std::string>& update_file_name_vec,
	const UpdateStatusCallback& updateStatusCb)
{
	auto session_ptr_ = std::make_shared<Session>(io_service_pool_ptr_->get_io_service(), ip,
		port, intsall_file_name, update_file_path, update_file_name_vec);
	session_ptr_->go(updateStatusCb);
}

void update::client::Client::run()
{
	int cpu_size = std::thread::hardware_concurrency();
	io_service_pool_ptr_ = std::make_shared<IoServicePool>(cpu_size);
	io_service_pool_ptr_->start();
}

void update::client::Client::stop()
{
	io_service_pool_ptr_->stop();
}
