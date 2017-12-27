#include "Server.h"
#include "LogMacros.h"
#include <map>
#include <type_traits>
int main()
{
	try
	{
		glog_init("UpdateServer");
		UPDATESERVER_INFO("%s", "UpdateServer start");
		update::server::Server server;
		server.run();
	}
	catch (std::exception& e)
	{
		UPDATESERVER_ERROR("%s,server exit!!", e.what());
	}
	return 0;
}
