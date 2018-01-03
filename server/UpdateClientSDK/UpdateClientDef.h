#pragma once
#ifndef SERVER_CLIENT_UPDATECLIENTDEF_H
#define SERVER_CLIENT_UPDATECLIENTDEF_H

#include <functional>
#include <cstdint>

//parameter1--error_code
//parameter2--file size
//parameter3--file offset size
//parameter4--detailed error message
//if parameter is redundant in one callback,then parameter2¡¢parameter3 will be 0,parameter4 will be empty.
typedef std::function<void(int, uint64_t, uint64_t, std::string)> UpdateStatusCallback;



#endif