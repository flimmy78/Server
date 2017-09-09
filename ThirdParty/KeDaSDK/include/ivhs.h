#ifndef _IVHS_H_
#define _IVHS_H_

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

/*�ϴ�ʵʱͼƬʧ�ܻص�
 *����:
 *      dwSeqNumber:    �����������
 *      dwIp:           ƽ̨��Ӧ��ip
 *      wPort:          ƽ̨��Ӧ��port
 */
typedef void (*IvhsUploadPicCBF)(Uint32 dwSeqNumber, TIvhsSendPicCb tSendPicCb, Uint32 dwMaxPlatNum);

/*��Ϣ�ص���������
 *����: 
 *      tHead:          ��Ϣͷ
 *      szMsgBody:      ��Ϣ���ݲο�������Ϣ����ע��
 *      dwMsgLen:       ��Ϣ����
 */
typedef void (*IvhsMessageEntryCBF)(TItsMessage *ptMsg);

/*���ý�����Ϣ�ص�����
 *����:
 *     cbFunMsgEntry:������Ϣ�ص�����
 */
API void CDECL IvhsSetMsgCBFun(IvhsMessageEntryCBF cbFunMsgEntry);

/*�����ϴ�ͼƬʧ�ܻص�
 *����:
 *     IvhsUploadPicCBF:������Ϣ�ص�����
 */
API void CDECL IvhsSetUploadPicCBFun(IvhsUploadPicCBF cbFunUploadPicEntry);

/*Э���ʼ��(��������ipc����)
 * ����: 
 *     TPlatCfgParam        ƽ̨���ò���
 *     dwFunctionSupport    Э��֧�ֹ���
 *     TPlatInfo            ƽ̨��Ϣ(ͬIvhsAddPlat)
 * ���: 0:�ɹ�   ����: ʧ��
 */
API Int32 CDECL  IvhsInit(TIvhsInitParam* ptInitCfg);


/*Э�����ʼ��(��������ipc����)
 */
API Int32 CDECL IvhsUnInit();


/*����������Ϣ
 *����:
 *     ptMsg:    ��Ϣ��
 *����ֵ:
 *     �ɹ�:0	   ʧ��:-1
 */
API Int32 CDECL IvhsPostMsg(TItsMessage *ptMsg);

/*ת��ͼƬ
 *����:
 *      TVechileData    ��������(������Ϣ+ͼƬ)
 *      byReal          �Ƿ�ʵʱ���� 1ʵʱ; 0��ʷ;
 *      dwIp  wport     0 ȫת��   ���� �ض�ip��port��Ӧ��ת��
 *����ֵ:	�ɹ�:0  ʧ��:-1(ƽ̨���ͱ��)
 */

API Int32 CDECL IvhsPostPic(TVechileData *ptData, Uint8 byReal, Uint32 dwIp/*=0*/, Uint16 wPort/*=0*/);


/*����ƽ̨��Ϣ
 *����: 
 *    TPlatInfo*  ƽ̨��Ϣָ��
 *    byPlatSize  ƽ̨����
 *����ֵ: �ɹ�:0  ʧ��:-1
 *˵��: �ڲ������ƽ̨����ӡ�ɾ���͸���
 */
API Int32 CDECL IvhsSetPlat(TIvhsPlatInfo* ptInfo, Uint8 byPlatSize);

/*��·��Ϣ֪ͨ
 *����: 
 *      szLinkInfo  ��·��Ϣ IP:Port
 *      szEState    ��·״̬
 *����: LinkSize    ��·����
 *˵��: ��·��Ϣ�ϱ���ҵ��
 */
API Int32 CDECL IvhsLinkInfoNotify(TIvhsNotifyInfo *pNotifyInfo);

/*����ע����Ϣ
 *����: 
 *      ptInfo  ע����Ϣ
 *����: null
 *˵��: 
 */
API Void CDECL IvhsSetDevInfo(TIvhsDevInfo *ptInfo);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif //_IVHS_H_


