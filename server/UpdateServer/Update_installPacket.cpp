#include "Update_installPacket.h"
#include <sstream>
#include <Windows.h>
#include "PlatformWin.h"

void update::server::UpdateInstallPacket::update(const std::string& install_packet_name, const std::string& last_time_components)
{
	std::string cmdLine = FILE_FOLDER;
	cmdLine.append("/").append(install_packet_name).append(" /COMPONENTS=")
		.append("\"").append(last_time_components).append("\"").append(" /verysilent /SUPPRESSMSGBOXES");
	PlatformWin::makeProcess(cmdLine);
}
