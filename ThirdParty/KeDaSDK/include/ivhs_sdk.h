#ifndef _IVHS_SDK_H_
#define _IVHS_SDK_H_

#include "ivhs_struct.h"

#ifdef __cplusplus
extern "C" {

#ifndef API
#ifdef WIN32
#define API   __declspec(dllexport)
#else
#define API 		
#endif
#endif

#ifndef CDECL
#ifdef WIN32
#define CDECL _cdecl
#else
#define CDECL   
#endif
#endif

#else

#ifndef API
#define API
#endif	
#ifndef CDECL
#define CDECL
#endif

#endif /* __cplusplus */

/*��Ϣ�ص���������
**����: tHead ��Ϣ��Ϣ
**      szMsgBody:��Ϣ���ݲο�������Ϣ����ע��
**      dwMsgLen:��Ϣ����
*/
typedef void (*IvhsMessageEntryCBF)(TItsMessage *ptMsg);

/*Э���ʼ��
**����:
**      dwMaxNumConnect :���֧����·����
**����ֵ:
**     �ɹ���0 ʧ�ܣ�-1
*/
API Int32 CDECL IvhsStart(Uint32 dwMaxNumConnect);

/*�˳�Э��
**����ֵ:
**     �ɹ���0 ʧ�ܣ�-1
*/
API Int32 CDECL IvhsStop();

/*������������
**����:
**     dwLocalIp������IP������Ĭ��Ϊ0
**     wLocalPort�������˿�
**����ֵ:
**     �ɹ���0 ʧ�ܣ�-1
*/
API Int32 CDECL IvhsStartListen(Uint32 dwLocalIp, Uint16 wLocalPort);

/*ֹͣ�������� 
**����ֵ:
**     �ɹ���0 ʧ�ܣ�-1
*/
API Int32 CDECL IvhsStopListen();

/*�������ӷ����
**����:
**     dwPeerIp�������IP
**     wPeerPort������˶˿�
**����ֵ:
**     �ɹ�����·��� ʧ�ܣ�0
*/
API Uint32 CDECL IvhsFwdConnect(Uint32 dwPeerIp, Uint16 wPeerPort);

/*�����Ͽ����������
**����:
**     dwHandle����·���
**����ֵ:
**     �ɹ���0 ʧ�ܣ�-1
*/
API Int32 CDECL IvhsDisconnect(KOSA_HANDLE dwHandle);

/*����������Ϣ
**����:
**     ptMsg����Ϣ��Ϣ
**����ֵ:
**     �ɹ���0 ʧ�ܣ�-1
*/
API Int32 CDECL IvhsPostMsg(TItsMessage *ptMsg);

/*���ý�����Ϣ�ص�����
**����:
**     cbFunMsgEntry��������Ϣ�ص�����
*/
API void CDECL IvhsSetMsgCBFun(IvhsMessageEntryCBF cbFunMsgEntry);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif //_IVHS_SDK_H_


