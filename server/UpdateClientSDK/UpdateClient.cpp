#include "UpdateClient.h"
#include "Client.h"


int begin()
{
	try
	{
		update::client::Client::Instance().run();
		return 0;
	}
	catch (const std::exception&){}
	catch (...) {}
	return -1;
}

int addSession(const std::string & ip, const uint16_t port, const std::string & intsall_file_name, 
	const std::string & update_file_path, const std::vector<std::string>& update_file_name_vec, 
	const UpdateStatusCallback& updateStatusCb)
{
	try
	{
		update::client::Client::Instance().makeSession(ip, port, intsall_file_name, update_file_path,
			update_file_name_vec, updateStatusCb);
		return 0;
	}
	catch (const std::exception&) {}
	catch (...) {}
	return -1;
}

int stop()
{
	return 0;
}
