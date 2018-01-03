#pragma once
#ifndef SERVER_CLIENT_UPDATECLIENTSDK_H
#define SERVER_CLIENT_UPDATECLIENTSDK_H
#include <cstdint>
#include <string>
#include <vector>
#include <functional>
#include "UpdateClientDef.h"

int begin();
int addSession(const std::string & ip, const uint16_t port,
	const std::string & intsall_file_name, const std::string & update_file_path,
	const std::vector<std::string>& update_file_name_vec, const UpdateStatusCallback& updateStatusCb);
int stop();

#endif