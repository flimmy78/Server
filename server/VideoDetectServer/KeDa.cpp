#define _CRT_SECURE_NO_WARNINGS

#include "KeDa.h"
#include <sstream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#undef _WINSOCK_DEPRECATED_NO_WARNINGS
#include "LogMacros.h"

#undef _CRT_SECURE_NO_WARNINGS
ITS::KeDa::CameraMessageCallback ITS:: KeDa::cb_; //define

void ITS::KeDa::initKeda(int MaxNumConnect)
{
	auto ret = IvhsStart(MaxNumConnect);
	if (ret == -1)
	{
		std::ostringstream str;
		str << "IvhsStart failed with MaxNumConnect: " << MaxNumConnect;
		throw std::runtime_error(str.str());
	}
	IvhsSetMsgCBFun(cameraMessageCallback);
}

int ITS::KeDa::connectAndLogin(const std::string& ip, uint16_t port,
	const std::string & user_name, const std::string & password, KOSA_HANDLE& dwHandle)
{
	auto g_dwHandle = IvhsFwdConnect(inet_addr(ip.c_str()), port);
	if (g_dwHandle == 0)
	{
		VIDEODETECTSERVER_ERROR("connect camera(%s:%d) failed", ip.c_str(), port);
		return -1;
	}
	dwHandle = g_dwHandle;

	TItsMessage tMessage;
	TLoginReqInfo tLoginInfo;
	memset(&tMessage, 0, sizeof(tMessage));
	memset(&tLoginInfo, 0, sizeof(tLoginInfo));

	/*���ӿƴ����*/
	strcpy(tLoginInfo.achDevId, "F5C4805B08E54E616DF4B31F14EA7A70");
	/*���ӿƴ������������дIPC*/
	strcpy(tLoginInfo.achProductType, "IPC625-A-C");
	/*���ӿƴ������Ĭ��kedacom*/
	strcpy(tLoginInfo.achVender, "kedacom");
	/*���ӿƴ������������û���*/
	strcpy(tLoginInfo.achUsername, user_name.c_str());
	/*���ӿƴ������������û�����*/
	strcpy(tLoginInfo.achPassword, password.c_str());
	/*���ӿƴ������Ĭ��0*/
	tLoginInfo.dwImgoverlay = 0;
	/*2�����Լ��ǿͻ��˽��룬������ղ���ͼƬ*/
	tLoginInfo.nDevType = 2;

	/*��·���*/
	tMessage.dwHandle = g_dwHandle;
	/*��Ϣ����*/
	tMessage.wMsgType = EV_REGISTER_REQ;
	/*��Ϣ��*/
	tMessage.szMsgBody = reinterpret_cast<char *>(&tLoginInfo);
	/*��Ϣ����*/
	tMessage.dwMsgLen = sizeof(tLoginInfo);

	auto ret = IvhsPostMsg(&tMessage);
	if (ret == -1)
		VIDEODETECTSERVER_ERROR("post login message to camera(%s:%d) failed", ip.c_str(), port);
	return 0;
}

int ITS::KeDa::disconnect(KOSA_HANDLE dwHandle)
{
	auto ret = IvhsDisconnect(dwHandle);
	if (ret == -1)
	{
		VIDEODETECTSERVER_ERROR("IvhsDisconnect failed");
		return -1;
	}
	return 0;
}

int ITS::KeDa::stopKeda()
{
	for (auto keda : keda_camera_dwHandle_)
	{
		if (keda.second)
			disconnect(keda.second);
	}
	
	auto ret = IvhsStop();
	if (ret == -1)
	{
		VIDEODETECTSERVER_ERROR("IvhsStop failed");
		return -1;
	}
	return 0;
}





