#pragma once
#ifndef SERVER_SERVER_UPDATESERVER_H
#define SERVER_SERVER_UPDATESERVER_H
#include <string>
#include <memory>
#include "ParseIni.h"
#include "PlatformWin.h"

namespace update
{
	namespace server
	{
		const std::string INI_DIR = "UpdateServer.ini";

		class UpdateBase
		{
		private:
			std::string update_file_name_;
		public:
			UpdateBase(const std::string& update_file_name) :update_file_name_(update_file_name) {}

			std::string getComponents()
			{
				auto pos1 = update_file_name_.find_last_of("_");
				auto pos2 = update_file_name_.find_last_of(".");
				auto uid_partial = update_file_name_.substr(pos1 + 1, pos2 - pos1 - 1);

				WwFoundation::ParseIni parser(INI_DIR);
				parser.parse();
				std::string uid = parser.getValue("UidConfig", uid_partial);
				std::string sub_key_front = "SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\";
				auto sub_key = sub_key_front.append(uid).append("_is1");
				return PlatformWin::getRegistryValue(sub_key, "Inno Setup: Selected Components");
			}

			std::string getDisplayVersion()
			{
				auto pos1 = update_file_name_.find_last_of("_");
				auto pos2 = update_file_name_.find_last_of(".");
				auto uid_partial = update_file_name_.substr(pos1 + 1, pos2 - pos1 - 1);

				WwFoundation::ParseIni parser(INI_DIR);
				parser.parse();
				std::string uid = parser.getValue("UidConfig", uid_partial);

				std::string sub_key_front = "SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\";
				auto sub_key = sub_key_front.append(uid).append("_is1");
				return PlatformWin::getRegistryValue(sub_key, "DisplayVersion");
			}

			std::string& getFileName() { return update_file_name_; }
		};

		template<typename UpdateMethod>
		class Update :private UpdateBase
		{
		private:
			std::shared_ptr<UpdateMethod> update_method_ptr_;
		public:
			Update(const std::string& update_file_name) :UpdateBase(update_file_name){}

			std::string getLastTimeComponents() { return UpdateBase::getComponents(); }

			std::string& getUpdateFileName() { return UpdateBase::getFileName(); }

			void startUpdate()
			{
				update_method_ptr_ = std::make_shared<UpdateMethod>();
				update_method_ptr_->update(getUpdateFileName(), getLastTimeComponents());
			}
		};

		template<>
		class Update<void> :private UpdateBase
		{
		public:
			Update(const std::string& update_file_name) :UpdateBase(update_file_name) {}

			std::string getLastTimeComponents() { return UpdateBase::getComponents(); }

			std::string getLastDisplayVersion() { return UpdateBase::getDisplayVersion(); }
		};
	}
}
#endif