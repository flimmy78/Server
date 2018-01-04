#include"UpdateClient.h"
#include <thread>

int main()
{
	begin();
	addSession("192.168.1.142",7000,"iVP8000_Server_V4.2.190.27723_GMI_x86_gt_A28A96DD.exe","./"
		, std::vector<std::string>{"iVP8000_Server_V4.2.0.0_BNA_x86_g_A28A96DD.exe"}
	, [](int error_code, uint64_t file_size, uint64_t offset, std::string error_message)
	{
		if (file_size != 0)
		{
			printf("file_size:%lld,offset:%lld\n", file_size, offset);
		}
		if (error_message != "")
			printf("%s\n", error_message.c_str());
	});
	stop();
	return 0;
}