#pragma once
#ifndef SERVER_SERVER_UPDATESERVER_UPDATEINSTALLPACKET_H
#define SERVER_SERVER_UPDATESERVER_UPDATEINSTALLPACKET_H

#include <string>
#include <vector>
namespace update
{
	namespace server
	{
		const std::string FILE_FOLDER = "../update";

		struct UpdateInstallPacket
		{
			void update(const std::vector<std::string>& update_file_name_vec, const std::string& last_time_components);
		};
	}
}
#endif