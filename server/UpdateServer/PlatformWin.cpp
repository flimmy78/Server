#include "PlatformWin.h"
#include <sstream>
#include <Windows.h>

std::string update::server::PlatformWin::getRegistryValue(const std::string & sub_key, const std::string& value_key)
{
	HKEY hkey;
	auto ret = RegCreateKeyExA(HKEY_LOCAL_MACHINE, sub_key.c_str(),
		0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hkey, NULL);
	if (ret == 0)
	{
		DWORD size = 1024;
		char buf[1024] = { 0 };
		DWORD type = REG_SZ;
		ret = RegQueryValueExA(hkey, value_key.c_str(), NULL, &type, reinterpret_cast<BYTE *>(buf), &size);
		if (0 == ret)
		{
			std::string components = buf;
			return components;
		}
		else
		{
			std::ostringstream message;
			message << "RegQueryValueExA(" << value_key << ")" << " failed with error_code:" << ret;
			throw std::runtime_error(message.str());
		}
	}
	else
	{
		std::ostringstream message;
		message << "RegCreateKeyExA(" << sub_key << ")" << " failed with error_code:" << ret;
		throw std::runtime_error(message.str());
	}
}

void update::server::PlatformWin::makeProcess(const std::string & cmd_line)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));
	auto ret = CreateProcessA(NULL, const_cast<char*>(cmd_line.c_str()),
		NULL, NULL, false, 0, NULL, NULL, &si, &pi);
	if (ret != 0)
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		std::ostringstream message;
		message << "CreateProcess(" << cmd_line << ")" << " failed with error_code:" << GetLastError();
		throw std::runtime_error(message.str());
	}
}

void update::server::PlatformWin::makeDirectory(const std::string & folder)
{
	auto dwAttrib = GetFileAttributesA(folder.c_str());
	if (!(INVALID_FILE_ATTRIBUTES != dwAttrib && 0 != (dwAttrib & FILE_ATTRIBUTE_DIRECTORY)))
	{
		auto ret = CreateDirectoryA(folder.c_str(), NULL);
		if (ret == 0)
		{
			std::ostringstream message;
			message << "CreateDirectoryA(" << folder << ")" << " failed with error_code:" << GetLastError();
			throw std::runtime_error(message.str());
		}
	}
}

void* update::server::PlatformWin::makeFile(const std::string & name)
{
	return CreateFileA(name.c_str(), GENERIC_WRITE, 0, 0,
		OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);
}

bool update::server::PlatformWin::isDirectory(const std::string & dir)
{
	std::string path = "";
	path.append(dir).append("/*.*");
	WIN32_FIND_DATAA FindFileData;
	ZeroMemory(&FindFileData, sizeof(WIN32_FIND_DATAA));

	HANDLE hFile = FindFirstFileA(path.c_str(), &FindFileData); /**< find first file by given path. */
	if (hFile == INVALID_HANDLE_VALUE)
	{
		FindClose(hFile);
		return false;
	}
	else
	{
		FindClose(hFile);
		return true;
	}
}

void update::server::PlatformWin::deleteDirectory(const std::string& dir)
{
	std::string path = "";
	path.append(dir).append("/*.*");
	WIN32_FIND_DATAA FindFileData;
	ZeroMemory(&FindFileData, sizeof(WIN32_FIND_DATAA));

	HANDLE hFile = FindFirstFileA(path.c_str(), &FindFileData);
	while (FindNextFileA(hFile, &FindFileData))
	{
		if (strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..")) //not "." and  ".." directory
		{
			std::string file_name = dir + "/" + FindFileData.cFileName;
			std::string file_name_temp;
			file_name_temp = file_name;
			if (isDirectory(file_name.c_str()))
			{
				deleteDirectory(file_name_temp.c_str());
			}
			else
			{
				auto ret = DeleteFileA(file_name_temp.c_str());
				if (ret == 0)
				{
					std::ostringstream message;
					message << "DeleteFileA(" << file_name_temp << ")" << " failed with error_code:" << GetLastError();
					throw std::runtime_error(message.str());
				}
			}
		}
	}
	FindClose(hFile);

	auto bRet = RemoveDirectoryA(dir.c_str());
	if (bRet == 0) 
	{
		std::ostringstream message;
		message << "RemoveDirectoryA(" << dir << ")" << " failed with error_code:" << GetLastError();
		throw std::runtime_error(message.str());
	}
}
