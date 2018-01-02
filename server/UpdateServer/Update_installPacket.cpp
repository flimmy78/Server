#include "Update_installPacket.h"
#include <sstream>
#include "PlatformWin.h"

void update::server::UpdateInstallPacket::update(const std::vector<std::string>& update_file_name_vec, const std::string & last_time_components)
{
	auto install_packet_name = update_file_name_vec[0];
	std::string cmdLine = FILE_FOLDER;
	cmdLine.append("/").append(install_packet_name).append(" /COMPONENTS=")
		.append("\"").append(last_time_components).append("\"").append(" /verysilent /SUPPRESSMSGBOXES");
	PlatformWin::makeProcess(cmdLine);
}
