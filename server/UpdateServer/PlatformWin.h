#pragma once
#ifndef SERVER_SERVER_UPDATESERVER_PLATFORMWIN_H
#define SERVER_SERVER_UPDATESERVER_PLATFORMWIN_H
#include <string>

namespace update
{
	namespace server
	{
		class PlatformWin
		{
		public:
		public:
			static std::string getRegistryValue(const std::string& sub_key);
			static void makeProcess(const std::string& cmd_line);
			static void makeDirectory(const std::string& folder);
			static void* makeFile(const std::string& name);
			static bool isDirectory(const std::string& dir);
			static void deleteDirectory(const std::string& dir);
		};
	}
}
#endif