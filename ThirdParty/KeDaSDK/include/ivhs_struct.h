#ifndef _IVHS_STRUCT_H_
#define _IVHS_STRUCT_H_

#pragma pack(push, 1)
#ifdef _MSC_VER
	#define PACKED
#else
    #define PACKED
#endif //LINUX

#include <stdio.h>
#include <string.h>

#include "ivhs_define.h"

/*----------------------------------------------------------
*ͨ�ýṹ��
*----------------------------------------------------------*/

//Υ����Ƶ��Ϣ
typedef struct
{
	//Υ����Ƶ�洢���� 0: HTTP, 1: FTP
	Uint32 dwIllvideotype;
	//Υ����Ƶ��ʼʱ�䣨20140905100010��
	Char achIllvideostarttime[MAX_LEN_VIDEOR_TIME];
	//Υ����Ƶ����ʱ�䣨20140905100030��
	Char achIllvideoendtime[MAX_LEN_VIDEOR_TIME];
	//Υ����Ƶȫ·��
	Char achIllvideofullurl[MAX_LEN_VIDEOR_URL];
}TVideInfo;

//ʵʱ������Ϣ
typedef struct
{
    /*��Ҫ  ������¼���*/
    Uint32 dwSeqNumber;
    /*��ѡ  �豸���ƣ������������ַ�*/
    Char achPointNum [MAX_SIZE_POINT_NUM];
    /*��Ҫ  ǰ���豸��ţ������ַ���*/
    Char achDevId[MAX_SIZE_DEV_ID] ;
    /*��Ҫ  ����ʱ�䣬��ǰ��ץ��ͼƬ��ʱ��*/
    Int64 qwThroughTime;
    /*��Ҫ  ������(��1��2��3��)*/
    Uint32 dwLaneNum ;
    /*��ѡ  ������ʻ����*/
    Char achDirection[MAX_SIZE_DIRECTION];
    /*��Ҫ  ����ֵ*/
    Uint32 dwSpeedLimit;
    /*��Ҫ  ������ʻ�ٶ�*/
    Uint32 dwVehicleSpeed;
    /*��Ҫ  ��ͷ���ƺ��루�義A12345��*/
    Char achFrontPlateNum[MAX_SIZE_PLATE_NUM];
    /*��ѡ  ��ͷ������ɫ����������ɫ���壩*/
    Uint32 dwFrontPlateColor;
    /*��ѡ  ��ͷ��������*/
    Uint32 dwFrontPlateType;
    /*��ѡ  ��β���ƺ��루�義A12345��*/
    Char achBackPlateNum[MAX_SIZE_PLATE_NUM];
    /*��ѡ  ��β������ɫ����������ɫ���壩*/
    Uint32 dwBackPlateColor;
    /*��ѡ  ��β��������*/
    Uint32 dwBackPlateType;
    /*��ѡ  ����һ��*/
    Uint32 dwConsistency;
    /*��ѡ  ������ɫ*/
    Uint32 nVehiclecColor;
    /*��ѡ  ��������*/
    Uint32 dwVehicleType;
    /*��ѡ  ������*/
    Uint32 dwVehicleLength ;
    /*��Ҫ  0Ϊ������1ΪΥ����2Ϊ�¼�*/
    Uint32 dwIllegalState ;
    /*��Ҫ  Υ�����¼�����*/
    Char achIllegalType[MAX_SIZE_ILLEGAL_TYPE];
    /*��Ҫ  0-ͼƬ���ݣ�1-ͼƬURL*/
    Int32 nPhotoType;
    /*��ѡ  �����������Ͻ�X����*/
    Uint32 dwPlatePointLeftX;
    /*��ѡ  �����������Ͻ�Y����*/
    Uint32 dwPlatePointLeftY;
    /*��ѡ  �����������Ͻ�X����*/
    Uint32 dwPlatePointRightX;
    /*��ѡ  �����������Ͻ�Y����*/
    Uint32 dwPlatePointRightY;
    /*��ѡ  ����ƣ����ʱ��*/
    //Uint32 dwRushedTime[MAX_NUM_IMAGE];
    /*��ѡ  ��ƿ�ʼʱ��*/
    Int64  qwRLampStartTime;
    /*��ѡ  ��ƽ���ʱ��*/
    Int64  qwRLampStopTime;
    /*������ʶ������ڣ�*/
    Char achVehiclelogo[MAX_SIZE_LEN32];
    /*ϸ�����ͣ���ɣ����3000����ע���복�����������𣨴��С�С��*/
    Char achDetailedtype[MAX_SIZE_LEN32];
	/*��ѡ	����ʶ�� �������ࣨ���������μ��������ࣩ*/
	Uint32 dwVehicleclass;
	/*��ѡ	������ʶ�� ���������ࣨ�μ����������Ͷ��壩*/
	Uint32 dwVehiclesubclass;
	//Υ����Ƶ����
	Uint32 dwIllvideonum;
	//Υ����Ƶ��Ϣ
	TVideInfo atVideoInfo[MAX_NUM_VIDEOR_INFO];
    /*��·����*/
    Char szSceneName[64];
    /*��·����*/
    Char szRoadCode[32];

	/*����Ϊ������ͼ����Ϣ��ѡ��*/
	/*ͼƬ�ɼ���ʽ,�ο�enum EInfoKind*/
	Int32 dwInfoKind;
	/*ͼƬ�ĸ�ʽ,�ο�enum EFileFormat*/ 
	Uint32 dwFileFormat;
	/*ͼƬ��Ϣ��Դ,�ο�enum EDataSourceType*/ 
	Uint32 dwDataSourceType;
	/*����������Ӿ����ڻ����е��������Ͻ�X����*/
	Uint32 dwVehcPointLeftX;
	/*����������Ӿ����ڻ����е��������Ͻ�Y����*/
	Uint32 dwVehcPointLeftY;
	/*����������Ӿ����ڻ����е��������Ͻ�X����*/
	Uint32 dwVehcPointRightX;
	/*����������Ӿ����ڻ����е��������Ͻ�Y����*/
	Uint32 dwVehcPointRightY;
	/*ͼƬ�Ŀ��*/
	Uint32 dwImgWidth;
	/*ͼƬ�ĸ߶�*/
	Uint32 dwImgHeight;
	/*ͼ���������Ƶĺ�������*/
	Char achTitle[STRING_MAX_LENGTH_128];
	/*��ͼ�����ݵļ�Ҫ����*/
	Char achContentDescription[STRING_MAX_LENGTH_256];
	/*�Զ������¼�����,�ο�enum EEventSort*/
	Int32 dwEventSort;
	/*��ѡ ע��ΨһPUID,*/
    Char achPuId[MAX_SIZE_DEV_ID] ;

	/*�ɼ����ش���*/
	Char achCapDepartment[MAX_SIZE_LEN16];

}PACKED TVechileInfo;

typedef struct
{
    /*ͼƬ�Ĵ�С*/
    Uint32 dwSize;
    /*ͼƬץ��ʱ��*/
    Int64 qwTime;
    /*ͼƬ����*/
    Uint32 dwType;
    /*ͼƬ��α��*/
    Char szAntifake[16+1];
	/*ͼƬ���ݵ�url*/
	Char achUrl[STRING_MAX_LENGTH_256];
    /*ͼƬ����*/
    void *szBuf;
}PACKED TImageData;

typedef struct
{
    TVechileInfo tInfo;
    /*ͼƬ����*/
    Uint32 dwImageNum;
    TImageData atImage[MAX_NUM_IMAGE];
}PACKED TVechileData;

/*���չ������ݷ������*/
typedef struct
{
    /*��Ҫ  ������¼���*/
    Uint32  dwSeqNumber;
    /*��Ҫ  0-�ɹ�����0-ʧ��*/
    Uint32  nReturncode;
	/*��Ҫ  ǰ���豸��ţ������ַ���*/
    Char achDevId[MAX_SIZE_DEV_ID] ;

}PACKED TIPC_VechileDataAck;

typedef struct
{
    /*��Ҫ �豸���*/
    Char achDevId[MAX_SIZE_DEV_ID];
    /*��Ҫ Уʱʱ�䣨2011-04-21 17:23:22)*/
    Char achControlsetTime[64];
    /*��Ҫ Ĭ���ǣ�GMT+8*/
    Char achTimeZone[16];
}PACKED TTimeSycCfg;


typedef struct
{
    /*��Ҫ �豸PUID*/
    Char achDevId[MAX_SIZE_DEV_ID];
    Int32 nRetCode;
}PACKED TTimeSycRspInfo;

/*�ϴ����*/
typedef struct
{
    /*��Ҫ	�豸���*/
    Int8 achDevId[64];
}PACKED TUpLoadFinishedInfo;

typedef struct
{
    /*ͼƬץ��ʱ�䡣����ʱ�䣬��GB/T 7408-2005��׼��
    5.4.1��ʱ����չ��ʽ��YYYY-MM-DDTHH:mm:ss.sss*/
    Char szSnapTime[32];
    /*ͼƬ��־��0-ͼƬ��������1-ͼƬURL*/
    Char szPicFlag[2];
    /*ͼƬ��� ȡֵΪ��0-ȫ��ͼƬ��1-��дͼƬ ��2-����˾����ԱͼƬ*/
    Char szPicType[2];
    /*ͼƬURL*/
    Char szPicUrl[256];
    /*ͼƬ����������ID��Ψһ��ʾ*/
    Char szPicStreamId[58];
    /*ͼƬ����д�����꣬��ʾΪ������X������Y������X������Y��?    ���?,1,100,110������������꣬ʹ��";"�ָ�*/
    Char szFtrCoord[64];
}PACKED TPicDtl;

typedef struct
{
    /*ͼƬ����*/
    Int32 nPicNum;
    TPicDtl atPicDlt[MAX_NUM_IMAGE];
}PACKED TCommonPicInfo;

typedef struct
{
    /*ͼƬ������Ϣ*/
    TCommonPicInfo tPicInfo;
    /*�豸ID*/
    Char achDevId[50];
    /*�豸ͨ����*/
    Int32 nChannelId;
    /*Ŀ�����ʱ�䡣����ʱ�䣬
    ��GB/T 7408-2005��׼��5.4.1��ʱ����չ��ʽ��YYYY-MM-DDTHH:mm:ss.sss*/
    Char achInTime[32];
    /*Ŀ����ʧʱ�䡣*/
    Char achOutTime[32];
    /*�����ﶨ������ʱ�䣬��Ŀ����������ʱ�䡣
    Ŀǰֻ����ƵժҪ�㷨�ܸ�����*/
    Char achBestTime[32];
    /*����ʶ���㷨����*/
    Char achIAlgType[32];
    /*������*/
    Int32 nLane;
    /*���޳��ƣ�0���ޡ�1����*/
    Bool bIfHavePlt;
    /*�������ࣺ�硰01-�����������ƣ�02-С���������ƣ�
    03-ʹ���������ơ�����GA24.7-2005����*/
    Char achPltType[32];
    /*������ɫ��0-��ɫ;1-��ɫ;2-��ɫ;3-��ɫ;4-����(GA/T 669.9-2008��A.7)*/
    Char achPltCol[32];
    /*���ƺ���*/
    Char achPltNum[32];
    /*�Ƿ�Ϳ��*/
    Bool bIsPltAlt;
    /*�Ƿ��ڵ�*/
    Bool bIsPltBlc;
    /*������ʻ�ٶȣ���λkm/h*/
    Int32 nSpeed;
    /*���������ٶȣ�������٣���λkm/h*/
    Int32 nLimitSpeed;
    /*��������״̬��0��������1�����ɣ�2072���٣�
    2027���� ��GA/T 669.9-2008��A.1*/
    Char achStatus[32];
    /*����ע������Ʒ�ƣ��복��һ��*/
    Char achBrand[32];
    /*����ע�����Ŀ�ʽ�ͺţ���GB/T 9417-1998����*/
    Char achStyle[32];
    /*�������ȣ���λΪCM*/
    Int32 nVLength;
    /*������ȣ���λΪCM*/
    Int32 nVWidth;
    /*�����߶ȣ���λΪCM*/
    Int32 nVHeight;
    /*������ɫ����GA24.8-2005����*/
    Char achVColType[32];
    /*Υ��ģ�ͣ���Ϊ����Զ��ŷָ���0:���� 1:���� 2:����� 3:��ֹ��ͷ
    4:����������ʻ  5:���䳬��  6:�޳��� 7:Υ��ͣ�� 8:ѹʵ��*/
    Char achTrafficOffence[32];
}PACKED TPicVehcInfo;

typedef struct
{
    /*����*/
    Char achPose[10];
    /*�������*/
    Char BoduSFtr[10];
    /*�Ƿ��ʻԱ-*/
    Bool bIsDriver;
}PACKED TPersonPicInfo;

typedef struct
{
    TCommonPicInfo tPicInfo;
    /*������״*/
    Char achShape[10];
    /*�����С*/
    Char achSize[50];
    /*������ɫ*/
    Char achColour[2];
    /*�����ٶ�*/
    Int32 nSpeed;
}PACKED TObjectPicInfo;

typedef struct xmlCommMsgData
{
    /* ͸��ͨ����Ϣ���ͣ�5000 բ����������5001 բ������ȷ�� .... */
    Uint16 wMsgType;
    /*͸����Ϣ����*/
    Uint16 wMsgLen;
    /*������Ϣ, ��Ϊբ���������������TOpDoorReq*/
    Int8 xmlTransDataBuf[MAX_TRAN_DATA_NUM];
}PACKED TCommMsgData;

/*�������ݹ�����*/
typedef union
{
    /*���ڿ���ʱ��1:����2:�أ�*/
    Uint32 POpDoor;
    /*���ڿ���ʱ���豸����Э�顣*/
    Int8 SOpDoor[MAX_CON_PROT_DATA];
}PACKED TOpDoorData;

/*բ����������*/
typedef struct
{
    /*1�����ڣ�2������*/
    Uint16 OpPortType;
    /*���ڻ��ߴ���ID��*/
    Uint16 PortId;
    /*��ˮ��*/
    Uint16 wTransNum;
    /*���ڿ���ʱ���豸����Э��ĳ���*/
    Uint16 OpDoorDataLen;
    /*���ڿ���ʱ��1:����2:�أ����ڿ���ʱ���豸����Э��,address�������tOpDoorData.SOpDoor�ڡ�*/
    TOpDoorData  tOpDoorData;
}PACKED TOpDoorReq;

/*բ������ȷ��*/
typedef struct
{
    /*�Ƿ�ɹ�  1�ɹ���0 ʧ��*/
    Uint32 nRetCode;
    /*��ˮ��*/
    Uint16 wTransNum;
}PACKED TOpDoorAck;

/*������Ϣ*/
typedef struct
{
    /*����id*/
    Uint16 wSerialId;
    /*������Ϣ*/
    Int8 achState[MAX_CON_PROT_DATA];
}PACKED TSerialStateInfo;

/*��Ƶ��������*/
typedef struct
{
    /*ͨ��ID*/
    Uint8        byChnId;
    /*��������˿�*/
    Uint16       wStreamPort;
    /*���������ַ*/
    Uint32       dwStreamIpAddr;
    /*��������ʱ��SSRc*/
    Int32        nSsrc;
}PACKED TMediaCtrl;

/*��ȡ���ʱ����Ϣȷ��*/
typedef struct
{
    /*��Ҫ �豸PUID*/
    Char achDevId[MAX_SIZE_DEV_ID];
    long int CamTime_Sec;
    long int CamTime_uSec;
}PACKED TCamTimeRspInfo;

/*----------------------------------------------------------
 *Э��ṹ��
 *----------------------------------------------------------*/
typedef struct
{
    /*���ֽ�Ϊ���汾�ţ����ֽ�Ϊ���汾*/
    Uint16 wVersion;
    /*��Ϣ����*/
    Uint16 wMsgType;
    /*���к�*/
    Uint32 dwSerialId;
    /*�豸��ţ���'\0'����*/
    Int8 achPuId[MAX_SIZE_PUID];
    /*��Ϣ�峤��*/
    Uint32 dwMsgLen;
}PACKED TIvhsMsgHead;

typedef struct
{
    /*��·���*/
    KOSA_HANDLE dwHandle;
    /*��Ϣ����*/
    Uint32 wMsgType;
    /*Դ���к� ��Ӧ��Ϣʱ���������ͬ��������Բ���*/
    Uint32 dwSrcSeqId;
    /*��Ϣ��*/
    Char *szMsgBody;
    /*��Ϣ����*/
    Uint32 dwMsgLen;
    /*ԴIP��ַ, ��Ӧ��ϢʱЭ���Զ����*/
    Uint32 dwSrcIP;
    /*��ȫ������, Э���Զ����*/
    Uint32 dwContex;
    /*������Э���Զ����*/
    Char achTime[64];
}PACKED TItsMessage;


typedef struct
{
    KOSA_HANDLE dwHandle;
    char   szPuId[MAX_SIZE_DEV_ID];
    Uint32 dwIp;
    Uint16 wPort;
    Int16  wProtclType;
    Uint32 dwDataTypes; //�ϴ���������(��EITS_DATA_TYPE)
    char   szUsername[MAX_SIZE_USRNAME];
    char   szPassword[MAX_SIZE_PASSWORD];
    char   szSavePath[MAX_SIZE_PATH_LEN];
    char   szRegulation[STRING_MAX_LENGTH_128];
}PACKED TIvhsPlatInfo;

typedef struct
{
    /*��Ҫ �豸���*/
    Char achDevId[MAX_SIZE_DEV_ID];
    /*��Ҫ 0-ǰ���豸,1-�����������2-�ͻ��˽��� */
    Int32 nDevType;
    /*��ѡ �û���*/
    Char achUsername[MAX_SIZE_USRNAME];
    /*��ѡ ����*/
    Char achPassword[MAX_SIZE_PASSWORD];
    /*��Ҫ �Ƿ�֧��ͼƬ���ַ����ӣ�0����֧�֣�1��֧��*/
    Uint32 dwImgoverlay;
    /*��Ҫ ��Ʒ�ͺ�*/
    Char achProductType[MAX_SIZE_PRODUCT];
    /*��Ҫ ����*/
    Char achVender[MAX_SIZE_VENDER];
}PACKED TIvhsDevInfo;

/*
typedef struct
{
    Int32 bUsed;
    ELinkState eState;
    TIvhsPlatInfo *ptPlatInfo;
    KOSA_SEMHANDLE hIvhsLinkLock;
    //KOSA_MutexHndl hAbppLinkLock;
    //KOSA_TskObj hFwdTaskObj;
}PACKED TIvhsLinkInfo;
*/

typedef struct
{
    Uint32 dwFunctionSupport;   //��EFUNCTION_SUPPORTö��
    Uint8 byMaxClientSize;
}PACKED TIvhsInitParam;

typedef struct
{
    Uint32 dwIp;
    Uint16 wPort;
    ELinkState eState;
    Uint16 wLinkType;      //�Զ���� ��EIVHSLINKTYPE
}PACKED TIvhsNotifyInfo;

typedef struct
{
	Uint32 dwIp;
	Uint16 wPort;
	Uint8 bySendState;   // 0�ɹ� 1ʧ��
}PACKED TIvhsSendState;

typedef struct
{
	Uint32 dwSeqNumber;
	Uint8 bySendType;    // 0ʵʱ 1��ʷ
	TVechileData *ptData;
    Uint32 dwPlatNum;
	TIvhsSendState tSendState[MAX_NUM_SERVER];
}PACKED TIvhsSendPicCb;

/*----------------------------------------------------------
 *ҵ��ṹ�壨ITS200��
 *----------------------------------------------------------*/
typedef struct
{
    /*��Ҫ �豸���*/
    Char achDevId[MAX_SIZE_DEV_ID];
    /*��Ҫ 0-ǰ���豸,1-���������*/
    Int32 nDevType;
    /*��ѡ �û���*/
    Char achUsername[MAX_SIZE_USRNAME];
    /*��ѡ ����*/
    Char achPassword[MAX_SIZE_PASSWORD];
    /*��ѡ ����ip��ַ����192.168.1.111*/
    Char achIpAddr[MAX_SIZE_STR_IPADDR];
    /*��ѡ ͼƬ�˿�*/
    Uint16 wImagePort;
    /*��Ҫ ��Ƶ�˿�*/
    Uint16 wvideoPort;
    /*��Ҫ �Ƿ�֧��ͼƬ���ַ����ӣ�0����֧�֣�1��֧��*/
    Uint32 dwImgoverlay;
    /*��Ҫ ��Ʒ�ͺ�*/
    Char achProductType[MAX_SIZE_PRODUCT];
    /*��Ҫ ����*/
    Char achVender[MAX_SIZE_VENDER];
}PACKED TLoginReqInfo;

typedef struct
{
    /*��Ҫ �豸���*/
    Char achDevId[MAX_SIZE_DEV_ID];
    /*��Ҫ 0-ǰ���豸,1-���������*/
    Int32 nDevType;
    /*��Ҫ 0�ɹ�����0-��������롣*/
    Int32 nRetCode;
    /*��ѡ 0-MJPEG��1-H.264*/
    Int32 nStreamType;
}PACKED TLoginRspInfo;

typedef struct
{
    char    szUserName[MAX_SIZE_USRNAME];
    char    szPassWd[MAX_SIZE_PASSWORD];
    char*   szRemotePath[MAX_SIZE_PATH_LEN];
    //char* pFileRule;
}PACKED TITS_FtpCfg;

//ftpͼƬת��
typedef struct
{
    Bool    bIsData;
    //TImageData�е�bufʵʱ��imagebuffer����ʷ������·��
    TVechileData    tVechileData;
    TITS_FtpCfg     tFtpCfg;
}PACKED TITS_FtpInfo;

/*���ַ���*/
typedef struct
{
    Bool    bEnable;                        // �Ƿ�����
    Uint16  wType;                          // ��������(�ͻ�����) ������duilib��EMLABLELAYOUTTYPE
    Uint16  wNumber;                        // ������Ŀ
    Uint16  wRow;                           // ����
    Uint16  wCol;                           // ����
    Uint16  wRowStart[MAX_MERGE_PIC_NUM];   // ����ʼλ��
    Uint16  wRowWidth[MAX_MERGE_PIC_NUM];   // �п��
    Uint16  wColStart[MAX_MERGE_PIC_NUM];   // ����ʼλ��
    Uint16  wColWidth[MAX_MERGE_PIC_NUM];   // �п��
}PACKED TLayoutInfo;

typedef struct
{
    Uint8   byImageSrc;     //ͼƬ��Դ  �μ�ENUM_ITS_IMAGE_SRC
    Bool    bSaveOriginal;  //�Ƿ���ԭͼ
}PACKED TImageSrc;

/*�ϲ�����*/
typedef struct
{
    Bool    bEnable;           	// �Ƿ�����
    Uint8   byLayoutSize;       // ���ֵ�������Ŀ
    Uint8   abyLayoutIndex[MAX_MERGE_LAYOUT_NUM];       // ���ֵ����Ϳ��԰���4����ͬ��ͬ����
    TImageSrc   tImageSrc[MAX_MERGE_LAYOUT_NUM][MAX_MERGE_PIC_NUM]; // ��ͬ�������͵�ͼƬ��Դ
}PACKED TMergeInfo;

/*ͼƬ�ϳ�����*/
typedef struct
{
    Uint32  dwIP;   //
    Uint32  dwSizeType;         // ͼƬ��С �μ�ENUM_ITS_IMAGE_SIZE
    Uint16  wCompress;          //ѹ���� eg: 75-->75%
    // ���ַ���
    TLayoutInfo	atLayoutInfo[MAX_MERGE_PIC_NUM];
    //�ϲ�����
    TMergeInfo	atMergeSrcInfo[MAX_MERGE_PIC_NUM];
}PACKED TImageMergeCfg;

/*��ȡͼƬ�ϳ���Ӧ*/
typedef struct
{
    TImageMergeCfg tImageMerge;
    Int32 nRetCode;
}PACKED TImageMergeRsp;

/*ͼƬ�洢*/
typedef struct
{
    Int16 wStoreType;   //�洢���� ��1:ʵʱ�洢 2:���ߴ洢
}PACKED TImageStore;

typedef struct
{
    TImageStore tStore;
    Int32 nRetCode;
}PACKED TImageStoreRsp;


// OSD������Ϣ;
typedef struct
{
    Bool    bEnable;            // �Ƿ�����OSD����
    Int32   dwType;             // ���ͣ�0: all/����_ԭͼ,1:����_�ϳ�21, 2:����_�ϳ�41, 3:����_��� �μ�ENUM_ITS_OSD_IMAGE_TYPE
    Int32   dwRowNumber;        // 1~16 ������ ����16 ָ�����ظ߶ȵģ�
    Int32   dwBKColor;          // ����ɫ, ������ɫ��ʾ͸��  �μ�ENUM_ITS_OSD_BKCLR
    Bool    bAutoLinefeed;      // �Ƿ��Զ�����
    Int32   dwAlignType;        // ���䷽ʽ   �μ�ENUM_ITS_OSD_ALIGN
    Int32   dwPosType;          // λ������   �μ�ENUM_ITS_OSD_POS
    char    szWildcard[5];        // ͨ��� #/*/-/@ ѡ��
    char    szDateTimeFormat[33]; // YY-MM-DD hh:mm:ss; YYYY-MM-DD hh:mm:ss;MM-DD-YY hh:mm:ss;
    char    szOsdFormat[MAX_OSD_OVERLAY_COUNT][256];    // OSD��ʾ��ʽ;
}PACKED TOsdCfgInfo;

// OSD����;
typedef struct
{
    Int32   dwFontSize;    //�μ� ENUM_ITS_OSD_FONTSIZE
    Int32   dwFontColor;   // ���Ӻڰ�ɫ �μ�ENUM_ITS_OSD_FONTCLR
}PACKED TOsdFont;

// OSD��������;
typedef struct
{
    Int32       dwType;             // ���ͣ�all/����_ԭͼ,����_�ϳ�21,����_�ϳ�41, ����_���
    char        szFontName[17];     // �������ƣ�
    TOsdFont    atFont[MAX_OSD_TYPE_COUNT];
}PACKED TOsdFontCfg;

/*��ȡosd������Ӧ*/
typedef struct
{
    TOsdCfgInfo tOsdCfg;
    Int32 nRetCode;
}PACKED TOsdCfgRsp;

/*��ȡosd������Ӧ*/
typedef struct
{
    TOsdFontCfg tOsdFontCfg;
    Int32 nRetCode;
}PACKED TOsdFontCfgRsp;

/*���ķ�����*/
typedef struct
{
    Bool    bEnable;
    char    szPuId[MAX_SIZE_DEV_ID];
    Uint32  dwIpAddr;
    Uint16  wPort;
    Uint8   byServerType;
    Uint32  dwDataTypes;    //�������͸�ѡ ÿһbit����һ������,
    Uint32  dwUploadType;   // HISDATA_TRANS_MODE  0 �����ϴ�  1 �����ϴ�  2 ���ϴ�
    Char    szUsername[MAX_SIZE_USRNAME];
    Char    szPassword[MAX_SIZE_PASSWORD];
    char    szSavePath[MAX_SIZE_PATH_LEN];
    char    szRegulation[STRING_MAX_LENGTH_128];   //��������
}PACKED TITS_CenterServer;

/*��ȡ���ķ�����������Ӧ*/
typedef struct
{
    Int32       nRetCode;
    Uint16      wServerSize;                    //���ķ���������
    TITS_CenterServer tServer[MAX_NUM_SERVER];  //���ķ�����
}PACKED TITS_GetServerRsp;

/*�������ķ�������������*/
typedef struct
{
    Uint16      wServerSize;                        //���ķ���������
    TITS_CenterServer tServer[MAX_NUM_SERVER];      //���ķ�����
}PACKED TITS_SetServerReq;

/*�豸����*/
typedef struct
{
    Uint32  dwIpAddr;
    Uint16  wPort;
    Uint8   byDevType;
}PACKED TITS_Device;

//��ӡ�ɾ���豸��Ϣ
typedef struct
{
    Uint8   byDevSize;
    TITS_Device tDevice[MAX_NUM_DEVICE];
}PACKED TITS_DevList;

//��ȡ�豸�б���Ӧ
typedef struct
{
    Int32 nRetCode;
    Uint8 byDevSize;
    TITS_Device tDevice[MAX_NUM_DEVICE];
}PACKED TITS_GetDevListRsp;

/*�������*/
typedef struct
{
    Bool    bUsed;
    Int16   nFilterSec;
    Uint16  wFilterLength;
}PACKED TITS_Filter;

/*�������������*/
typedef struct
{
    Bool    bEnable;
    Uint32  dwIpAddr;
    Uint16  wPort;
    Uint16  wSectionNumber;
    Uint8   byMatchMode;
    TITS_Filter tMatchFilter;
    Uint16  wSpeedDistance;     //���پ���
}PACKED TITS_AuxCamera;

/*�����������Ϣ*/
typedef struct
{
    Uint16      wAuxCameraSize;     //�������������
    TITS_AuxCamera  tAuxCamera[MAX_NUM_AUX_CAMERA]; //���������
}PACKED TITS_AuxCameraInfo;

/*¼���ȡ*/
typedef struct
{
    Char    szVideoFormat[MAX_SIZE_LEN8];
    Uint16  wSectionType;       //¼���ȡ����,��VIDEO_CAPTURE_TYPEö��
    Bool    bUsed;
    Uint16  wVideoPreSec;       //Ԥ¼ʱ�䣨s��
    Uint16  wVideoDelaySec;     //�Ӻ�ʱ�䣨s��
}PACKED TITS_VideoSectCfg;

/*�豸����*/
typedef struct
{
    Bool    bIsAux;             //�Ƿ��Ǹ������
    char    szDevName[MAX_SIZE_USRNAME];
    char    szDevNo[MAX_SIZE_DEV_ID];
    char    szLaneNumber[MAX_SIZE_LEN64];
    Uint16  wSectionNumber;

    TITS_Filter tSectionFilter;     //�������
}PACKED TITS_DeviceParam;

/*��ȡ�豸��ϸ��Ϣ���󡢻�ȡ���������Ϣ����*/
typedef struct
{
    Uint32  dwDevId;            //��ǰָ��Ϊ�豸IP
}PACKED TITS_GetDevInfoReq;

/*��ȡ�豸��ϸ��Ϣ��Ӧ*/
typedef struct
{
    Int32 nRetCode;
    TITS_DeviceParam tDevParam;
}PACKED TITS_GetDevInfoRsp;

typedef struct
{
    Uint32             dwDevId;      //��ǰָ��Ϊ�豸IP
    TITS_DeviceParam    tDevParam;
}PACKED TITS_SetDevInfoReq;

typedef struct
{
    Int32              nRetCode;
    TITS_AuxCameraInfo  tCameraInfo;
}PACKED TITS_GetAuxCameraRsp;

typedef struct
{
    Uint32             dwDevId;    //��ǰָ��Ϊ�豸IP
    TITS_AuxCameraInfo  tCameraInfo;
}PACKED TITS_SetAuxCameraReq;

typedef struct
{
    Uint32  dwVidSectType;     //¼���ȡ����
}PACKED TITS_GetVideoCfgReq;

typedef struct
{
    Int32           nRetCode;
    TITS_VideoSectCfg   tVideoCfg;
}PACKED TITS_GetVideoCfgRsp;

/**************************ʵʱ���************************/
typedef struct
{
    //�豸����ַ������ԡ�,���ָ�ÿһ���豸���
    char    szDeviceNoStr[MAX_SIZE_DEV_ID*MAX_NUM_DEVICE];
}PACKED TITS_RtVehicleReq;


typedef struct
{
    TVechileData tVehicleData;
    Int32 nRetCode;
}PACKED TITS_RtVehicleRsp;


 /**************************���ݲ�ѯ************************/
// typedef struct
// {
//  Uint32 dwQueryType;     //��ѯ����
//  Uint32 dwLimit;         //ÿҳ��ʾ������
//  Uint32 dwOffset;        //��ʾ�ڼ�ҳ
//
//  Bool IsHasAccess(Uint32 dwType)
//  {
//      return ((dwQueryType & dwType) != 0);
//  }
// }PACKED TItsQueryBase;
//
// //���ݲ�ѯ
// struct TDataQuery : public TItsQueryBase
// {
// public:
//  Int64   qwStartTime;                    //��ʼʱ��
//  Int64   qwStopTime;                     //����ʱ��
//  Uint8   byDataType;                     //�������: 1ȫ������; 2:ȫ��Υ��; 3:...
//  Int8    szDevId[MAX_SIZE_DEV_ID];       //������: Ŀǰ�ݶ�Ϊ �豸���ָ��������
//  Int8    szCarPlate[MAX_SIZE_PLATE_NUM]; //���ƺ���
//  Uint8   byUploadState;                  //�ϴ�״̬��1:���ϴ���2��δ�ϴ�
//  Uint16  wMinSpeed;                      //��С�ٶ�
//  Uint16  wMaxSpeed;                      //����ٶ�
//  Uint8   byAscType;                      //��������	1:ʱ������ 2:ʱ�併�� 3:������� 4:��Ž���
// }PACKED;

typedef struct
{
    char    szDevId[MAX_SIZE_DEV_ID];
    Int64   qwThroughTime;
    char    szCarPlate[MAX_SIZE_PLATE_NUM];
    Uint32  dwPlateColor;
    char    szChannelNo[MAX_SIZE_LEN64];
    char    szLaneNo[MAX_SIZE_LEN64];
    Int16   wEventType;
    Uint32  dwCarType;
    Uint16  wCarSpeed;
    Uint8   byUploadState;
}PACKED TITS_QueryResult;

typedef struct
{
    Int32 nTotal;
    Int16 nResultSize;
    TITS_QueryResult tResult[MAX_NUM_PER_PAGE];
    Int32 nRetCode;
}PACKED TITS_QueryResultRsp;

/*----------------------------------------------------------
 *ҵ��ṹ�壨IPC V7��
 *----------------------------------------------------------*/
/*��*/
typedef struct
{
    /*������ѯʹ��*/
	Uint32 dwLaneNumEnable;
    /*������*/
	Uint32 dwLaneNum;
    /*��ʼʱ��ʹ��*/
	Uint32 dwStartTimeEnable;
    /*��ʼʱ��*/
	Uint32 dwStartTime;
    /*����ʱ��ʹ��*/
	Uint32 dwEndTimeEnable;
    /*����ʱ��*/
	Uint32 dwEndTime;
    /*���ƺ���ʹ��*/
	Uint32 dwFrontPlateNumEnable;
    /*�Ƿ�ģ��ƥ��*/
	Uint32 dwVaguePlateMatch;
    /*���ƺ���*/
	Char achFrontPlateNum[MAX_SIZE_PLATE_NUM];
    /*Υ������ʹ��*/
	Uint32 dwIllegalTypeEnable;
    /*Υ������*/
	Char achIllegalType[MAX_SIZE_ILLEGAL_TYPE];
    /*����״̬ʹ��*/
	Uint32 dwUpdateFlagEnable;
    /*����״̬*/
	Uint32 dwUpdateFlag;
    /*ÿ�β�ѯ��ʼλ�ã���ʼΪ0 limit dwBeignNum,dwQueryNum*/
	Uint32 dwQueryBeginNum;
	/*ÿ��ϣ����ѯ����Ŀ*/
	Uint32 dwQueryNum;
} PACKED TIPC_PicQuery;

/*��ѯ���ؽṹ��*/
/*��¼�ṹ��*/
typedef struct
{
    /*��¼���*/
    Uint32 dwRecordID;
    /*�������*/
	Uint32 dwLaneNum;
	/*����ʱ�� time_t*/
	Uint32 dwThroughTime;
    /*���ƺ���*/
    Char achFrontPlateNum[MAX_SIZE_PLATE_NUM];
    /*������ɫ*/
	Uint32 dwPlateColor;
    /*Υ������*/
	Char achIllegalType[MAX_SIZE_ILLEGAL_TYPE];
    /*����*/
	Uint32 dwSpeed;
	/*����ͼƬ��Ŀ*/ 
	Uint32 dwPicNum; 
	/*������Ƶ����*/ 
	Uint32 dwVioNum; 
	/*����ͼƬ·��������������ֶ���*/ 
	Char achPicPath[MAX_LEN_VIDEOR_URL]; 
	/*������Ƶ·��������������ֶ���*/ 
	Char achVioPath[MAX_LEN_VIDEOR_URL]; 
    /*���±�־��ȡ��4λ��0x0011 ��ʾ��һ���ڶ���ƽ̨�Ѿ��ϴ�*/
	Uint32 dwUploadState;
}PACKED TIPC_PicFileInfo;

typedef struct
{
    /*��ѯ��¼����*/
    Uint32 dwMaxNum;
    /*��ǰ��ѯ��ʼλ��,��0��ʼ*/
    Uint32 dwBeignNum;
    /*ʵ�ʲ�ѯ�����ļ���������Ҫ����MAX_NVR_PIC_QUERY_NUM*/
    Uint32 dwNum;
    /*��¼�б�*/
    TIPC_PicFileInfo aPicFileInfo[MAX_NUM_PER_PAGE];
}PACKED TIPC_PicQueryResult;

/*----------------------------------------------------------
 *ҵ��ṹ�壨IPC V7��
 *----------------------------------------------------------*/
/*��*/
typedef struct
{
    Int32 X;
    Int32 Y;
}PACKED TPoint_S;

/*��*/
typedef struct
{
    Int32 X1;
    Int32 Y1;
    Int32 X2;
    Int32 Y2;
}PACKED TLine_S;

/*������*/
typedef struct
{
    /*ʹ��*/
    Bool bEnable;
    /*�����߱��*/
    Uint32 LineLabel;
    /*ֱ��*/
    TLine_S tLine;
}PACKED TRuleLine_S;

/*������*/
typedef struct
{
    /*���������*/
    TRuleLine_S tRdLineL;
    /*�����ұ���*/
    TRuleLine_S tRdLineR;
}PACKED TRoadLine_S;

/*����*/
typedef struct
{
    Int32 X;
    Int32 Y;
    Int32 W;
    Int32 H;
}PACKED TRECTANGLE_S;

/*����*/
typedef struct
{
    Int32 X1;
    Int32 Y1;
    Uint32 W1;
    Int32 X2;
    Int32 Y2;
    Uint32 W2;
}PACKED TECHELON_S;

/*Υͣ����*/
typedef struct
{
    Bool        bEnable;
    Uint32      dwRoiLabel;
    Uint16      wPointNum;
    TPoint_S    tPoint[ROI_AREA_POINT_MAX];
}PACKED TRoiArea_S;

/*�����ǿ*/
typedef struct
{
    Bool   bEnable;
    /*�������*/
    Uint32 dwStartX;
    Uint32 dwStartY;
    Uint32 dwWidth;
    Uint32 dwHeight;
    /*��С����*/
    Uint32 dwPixMin;
    /*������ǿ�ȼ�*/
    Uint32 dwLevelDay;
    /*ҹ����ǿ�ȼ�*/
    Uint32 dwLevelNight;
    /*��ɫ*/
    Uint8 byR;
    Uint8 byG;
    Uint8 byB;
    /*�ο���λ: REDLAMP_PHASETURNRIGHT.......*/
    Uint32 dwRefPhase;
}PACKED TIPC_RedSigEnhance;

/*������*/
typedef struct
{
    /*�������*/
    Uint32 dwLaneLabel;
    /*��ʻ����: ��DRIVE_DIR_TYPEö��*/
    Uint32 dwDriveDir;
    /*��������: �����򱱡��ɱ�����................*/
    Char   szLaneDir[MAX_SIZE_LEN16+1];
    /*��������: bit3--���ת��bit2--��ת��bit1--ֱ�У�bit0--��ת*/
    Uint32 dwLaneAttribute;
    /*���첹�ⷽʽ*/
    Uint32 dwDaySnapLight;
    /*ҹ���ⷽʽ*/
    Uint32 dwNightSnapLight;
    /*�����ı�����: bit0--F1��bit1--F2��bit2--F3��bit3--F4*/
    Uint32 dwSnapF;
    /*������LED��: bit0--����LED��bit1--LED1��bit2--LED2*/
    Uint32 dwSnapLED;
    /*��ⷽʽ: ��Ƶ��⡢��Ȧ��⡢�״��⡢��Ƶ+�״����*/
    Uint32 dwDetType;

    /*������*/
    Uint32 dwTruckLmSpd;
    /*�������ٶ�*/
    Uint32 dwTruckSnapSpd;
    /*С������*/
    Uint32 dwCarLmSpd;
    /*С�������ٶ�*/
    Uint32 dwCarSnapSpd;
    /*ץ������: bit0--���ڡ����١�...��LOGIC_ROAD_TYPE_KK��ض���*/
    Uint32 dwSnapType;
}PACKED TIPC_PhysicLane;

typedef struct
{
    /*�豸����*/
    Char    szDevName[MAX_SIZE_LEN64];
    /*�豸���*/
    Char    szDevLabel[MAX_SIZE_LEN32];
	/*�豸�ͺ�*/
    Char    szDevType[MAX_SIZE_LEN32];
    /*����汾��*/
    Char    szSoftWareVer[MAX_SIZE_LEN64];
	/*��������汾��*/
	Char    szSoftWareBaseVer[MAX_SIZE_LEN64];
	/*��������*/
    Char    szSceneName[MAX_SCENE_NUM][MAX_SIZE_LEN64];
	/*����*/
	Uint32	dwVender;
	/*���к�*/
	Char	szSn[MAX_SIZE_LEN16+1];
	/*��Ա*/
	Uint8	szLicense[MAX_SIZE_LEN16+1];
}PACKED TIPC_DevInfo;

/*��������*/
typedef struct
{
    /*Ԥ��λid*/
    Uint16  wPrePosId;
    /*��·����*/
    Char    szRoadCode[MAX_SIZE_LEN32];
    /*��������*/
    Uint32  dwLaneNum;
    /*������*/
    Uint32  dwLaneWidth;
    TIPC_PhysicLane tPhyLane[ROAD_NUM_MAX];
    /*���������*/
    TRuleLine_S tRdLineL;
    /*�����ұ���*/
    TRuleLine_S tRdLineR;
    /*����12�ָ���*/
    TRuleLine_S tRdLine12;
    /*����23�ָ���*/
    TRuleLine_S tRdLine23;
    /*����34�ָ���*/
    TRuleLine_S tRdLine34;
    /*�����*/
    TRuleLine_S tScanLine;
    /*��ת�ж���*/
    TRuleLine_S tTurnLeftLine;
    /*ֱ���ж���*/
    TRuleLine_S tStraightLine;
    /*��ת�ж���*/
    TRuleLine_S tTurnRightLine;
    /*ͣ����*/
    TRuleLine_S tStopLine[ROAD_NUM_MAX];
    /*��������*/
    //TRECTANGLE_S  tTrackArea;
    TRoiArea_S  tTrackArea;
    /*����������*/
    TRuleLine_S   tRuleLine[USER_RULE_LINE_NUM_MAX];
    /*Υͣ�������*/
    Uint32        dwRoiAreaNum;
    TRoiArea_S    tRoiArea[VEH_DET_ROI_NUM_MAX];
}PACKED TIPC_SceneConfig;

/*�״�����*/
typedef struct
{
    /*���*/
    Uint32  dwLoopLabel;
    /*ʹ��*/
    Bool    bEnable;
    /*��Ӧ����ͨ����*/
    Uint32  dwSerialChnId;
    /*�״�����: խ���״2D�״�*/
    Uint32  dwRadarType;
    /*�״�ģʽ: ����ģʽ������ģʽ*/
    Uint32  dwRadarMode;
    /*�״��������ˮƽ����: �״�����Ϊ�����״�����Ϊ��*/
    float   fH_distance;
    /*�ٶ�����ϵ��*/
    float   fCorrectRate;
    /*��Ӧ��������*/
    Uint32  dwPhyLaneNo;
}PACKED TIPC_RadarLoopCfg;

/*��Ȧ�����*/
typedef struct
{
    /*���*/
    Uint32  dwCoilLabel;
    /*ʹ��*/
    Bool    bEnable;
    /*��Ӧ����ͨ����*/
    Uint32  dwSerialChnId;
    /*��Ȧͨ����*/
    Uint32  dwCoilChnId;
    /*����*/
    Uint32  dwDirection;
    /*��Ȧ���: ��ǰһ����Ȧ�ľ���*/
    Uint32  dwV_distance;
    /*��Ȧ���*/
    Uint32  dwCoilWidth;
    /*�ٶ�����ϵ��*/
    float   fCorrectRate;
    /*����IO���*/
    Uint32  dwIOLabel;
    /*��Ӧ��������*/
    Uint32  dwPhyLaneNo;
    /*��Ȧ���*/
    Uint32  dwCoilType;
}PACKED TIPC_CoilLoopCfg;

/*Video Detector.....*/
typedef struct
{
    /*���*/
    Uint32  dwLoopLabel;
    /*ʹ��*/
    Bool    bEnable;
    /*���������*/
    Uint32  dwStartX;
    Uint32  dwStartY;
    Uint32  dwWidth;
    Uint32  dwHeight;
    /*��ⷽʽ*/
    Uint32  dwMethod;
    /*����*/
    Uint32  dwDirection;
    /*Ŀ��Ŀ�ȡ��߶�
      �˶����������Ŀ���ߣ�
      ���Ƽ�������ƿ�ߣ�
      ͷ�Ƽ�����ͷ����С�ߴ����ߴ磻
      β�Ƽ�����β�Ƴߴ��β�Ƽ�ࣻ
      ���̵Ƽ�������С���غ���󶶶���Χ;*/
    Uint32  dwTargetWidth;
    Uint32  dwTargetHeight;
    /*���ƽǶ�(1: ���ż�(C��); 2: A�ˣ�������������; 3: A�ˣ�������������; 4: �Ƕȷ��򲻶�)*/
    Uint16  wPlateAngle;
    /*������Ȧ����ʱ�䣬��λΪ�룬�ͱ�����ģ�����й�???*/
    Uint32  dwPresentTime;
    /*������Ȧ��Ե������ȷ�Χ��һ��ȡֵ20����*/
    Uint32  dwSensitive;
    /*�����������ٴμ�⵽�Ժ����ʽ�ж�Ϊ�л�û��*/
    Uint32  dwFilterOnTimes;
    Uint32  dwFilterOffTimes;

    //cst todo: Э���в�����ҵ���ڲ�����
}PACKED TIPC_VidLoopCfg;

/*����źż����*/
typedef struct
{
    /*��������*/
    Uint32  dwLoopLabel;
    /*ʹ��*/
    Bool    bEnable;
    /*����: 0-�����ԣ�1-������*/
    Bool    bPolarity;
    /*����ͨ����*/
    Uint32  dwSerialChnId;
    /*ͨ����*/
    Uint32  dwChnId;
    /*�����λ: REDLAMP_PHASETURNRIGHT.......*/
    Uint32  dwDetPhase;
}PACKED TIPC_RedLampSigLoop;

/*ʶ������*/
typedef struct
{
    /*��������*/
    TECHELON_S tArea;
    /*���ƿ��*/
    Uint32  dwPlateWidth;
    /*���ƽǶ�*/
    Uint32  dwPlateAngle;
    /*�����ӽ�:  1 Ϊץ�ĳ���ͷ����2 Ϊץ�ĳ���β��;*/
    Uint32  dwShootRear;
}PACKED TIPC_RecogArea;

/*����ʶ�����*/
typedef struct
{
    /*����ʶ��*/
    Bool    bFastRecog;
    /*���ڿ���ʶ��ʱ��(ms)����ֹ��ʱ; 0 Ϊ������*/
    Uint32  dwTimeControl;
    /*��������ռ80%����*/
    Bool    bLocalPlate;
    /*Ĭ��ʡ��*/
    Char    szDefaultProvince[3];
    /*Ĭ�ϵ�������*/
    Char    chDefaultArea;
    /*������Ӱ����*/
    Bool    bShadowRemove;
    /*����ʶ��*/
    Bool    bLprRecog;
    /*Ħ�г���ʶ��*/
    Bool    bRecogMT;
    /*������ɫʶ��*/
    Bool    bVehColorRecog;
    /*����ʶ��*/
    Bool    bVehLogoRecog;
    /*˾����Ա������λ*/
    Bool    bFaceLocate;
    /*��ʻԱ������绰*/
    Bool    bPhoneCheck;
    /*��ʻԱδ�İ�ȫ��*/
    Bool    bSeatbeltCheck;
    /*����δ�İ�ȫ��*/
    Bool    bCopilotCheck;
    /*�������ڵ�����*/
    Bool    bSunvisorCheck;
}TIPC_RecogParam;

/*��ʱץ��*/
typedef struct
{
    /*ʱ��θ���: ���4��ʱ���*/
    Uint32 num;
	/*��ʼʱ��: ��ȷ������*/
    Uint32 startTimeHour[MAX_NUM_DECT_TIME];
    Uint32 startTimeMin[MAX_NUM_DECT_TIME];
    /*����ʱ��: ��ȷ������*/
    Uint32 stopTimeHour[MAX_NUM_DECT_TIME];
    Uint32 stopTimeMin[MAX_NUM_DECT_TIME];
}TIPC_SnapTiming;

/*�߼�����*/
typedef struct
{
    /*�߼��������*/
    Uint32 dwLgRdId;
    /*ʹ��*/
    Bool   bEnable;
    /*�߼���������*/
    Uint32 dwLgRdType;
    /*����ID*/
    Uint32 dwLaneId;
    /*���첹�ⷽʽ*/
    Uint32 dwDaySnapLight;
    /*ҹ�䲹�ⷽʽ*/
    Uint32 dwNightSnapLight;
    /*�����ع�ģʽ*/
    Bool   bFaceMode;
    /*ʶ������*/
    Uint32 dwRecAreaID;
    /*��������: ���������(��������)1��2��3;ƥ��ȷ�ϼ����4*/
    Uint32 dwDectorLabel[MAX_DECT_LABEL_NUM];
    /*�������Ŷ�*/
    Uint32 dwConfidenceLevel;
    /*ƥ���ַ���*/
    Uint32 dwMatchCnt;
    /*���ƹ���: bit0--���ơ�bit1--���ơ�bit2--����*/
    Uint32 dwFilterLpr;
	/*�������*/
	Uint32 dwFilterDir;
    /*��Сץ�ļ��*/
    Uint32 dwMinInterval;
    /*���������λ: REDLAMP_PHASE_TURNRIGHT*/
    Uint32 dwRedLightPhase;
    /*�����ʱ��*/
    Uint32 dwMaxRedLight;
    /*��С���ʱ��*/
    Uint32 dwMinRedLight;
    /*��Ƽ���: 0-�����ԣ�1-������*/
    Bool bPolarity;
    /*ץ������*/
    Uint32 dwNeedCnts;
    /*ץ�Ŀ���ģʽ: ��ʱ�䡢������*/
    Uint32 dwSnapCtrlMode;
    union
    {
        /*1|2���ʱ��*/
        Uint32 dwTime;
        /*1|2�������*/
        Uint32 dwDistance;
    }ShareData1;
    union
    {
        /*2|3���ʱ��*/
        Uint32 dwTime;
        /*2|3�������*/
        Uint32 dwDistance;
    }ShareData2;
    /*������*/
    Uint32  dwSensitivity;
    /*ץ����ͼ*/
    Bool    bLprSubPic;
    Uint32  dwLprPicW;
    Uint32  dwLprPicH;
    Bool    bVehSubPic;
    Uint32  dwVehPicW;
    Uint32  dwVehPicH;
    Bool    bFaceSubPic;
    Uint32  dwFacePicW;
    Uint32  dwFacePicH;
    /*8λ����: Υ�´���*/
    Uint32  dwWzCode;
    /**********************����***********************/
    /*������*/
    Uint32  dwTruckLmSpd;
    /*�������ٶ�*/
    Uint32  dwTruckSnapSpd;
    /*С������*/
    Uint32  dwCarLmSpd;
    /*С�������ٶ�*/
    Uint32  dwCarSnapSpd;
    /*������Ƶ����У��*/
    Bool    bUseVidSpdChk;
    /*����ƫ��*/
    Uint32  dwSpdOffset;
    /********************��ʱ����**********************/

	TIPC_SnapTiming tSnapTiming[MAX_NUM_SNAPTIMING];

	 /*��ʱ����: ��λСʱ*/
    Uint32 dwTimingSnap;

}PACKED TIPC_LogicLane;

/*�������ֱ���*/
typedef struct
{
    Uint32  dwMaxWidth;
    Uint32  dwMaxHeight;
}PACKED TIPC_SceneMaxParam;

/*��ȡ����������Ӧ*/
typedef struct
{
    Int32           nRetCode;
    Uint32          dwSceneSize;
    /*����id*/
    Uint32          dwSceneId;
    TIPC_SceneMaxParam  tMaxParam;
    TIPC_SceneConfig    tSceneCfg;
}PACKED TIPC_GetSceneCfgRsp;

typedef struct
{
    /*����id*/ 
    Uint32          dwSceneId;
    TIPC_SceneConfig    tSceneCfg;
}PACKED TIPC_SetSceneCfgReq;

/*��ȡipc�豸��Ϣ��Ӧ*/
typedef struct
{
    TIPC_DevInfo tDev;
    Int32       nRetCode;
}PACKED TIPC_GetDevRsp;


/*PTZ��������*/
typedef struct
{
    /*����������� ��PTZ_EVENT_TYPEö��*/
    Uint16  wEventType;
    Uint16  wP1;
    Uint16  wP2;
    Uint16  wP3;
    Uint16  wP4;
}PACKED TIPC_PTZCtrl;

/*��Ƶ����*/
typedef struct
{
    /*ʹ��*/
    Bool   bEnable;
    /*������İ�װ�߶�*/
    float  fCameraHeight;
    /*ͼ���ϱ��ؾ������˵�ʵ�ʾ���*/
    float fTopLineDist;
    /*ͼ���м��߾������˵�ʵ�ʾ���*/
    float fMidLineDist;
    /*ͼ���±��ؾ������˵�ʵ�ʾ���*/
    float fBottomLineDist;
    /*�����±��ؾ������ĸ߶�*/
    float  fPlateB2G;
    /*��Ŀ���״���������*/
    float  fRadarXShift;
    /*�ٶ�����ϵ��*/
    float  fCorrectRate;
}PACKED TIPC_VidSpdDet;

/*ͼ����� ��Χ0~100*/
typedef struct
{
    /*����*/
    Uint8 byBright;
    /*�Աȶ�*/
    Uint8 byContrast;
    /*GAMA*/
    Uint8 byGama;
    /*���Ͷ�*/
    Uint8 bySaturation;
    /*���*/
    Uint8 bySharpness;
    /*2D����*/
    Uint8 bydeNoise2D;
}PACKED TIPC_ImageCtrlParam;

/*�ع�*/
typedef struct
{
    /*֧�ֵ�ģʽ�б�KISP_2A_AE_INVALID*/
    Uint32 dwSptAEModeList;
    /*�ع�ģʽ: KISP_2A_AE_INVALID*/
    Uint32 dwAEmode;
    /*�ֶ��ع����ֵ: 0~40*1000us*/
    Uint32 dwManuShutter;
    /*�ֶ��ع�����: 0~100db*/
    Uint32 dwManuAgain;
    /*�Զ��ع��������: 0~40*1000us*/
    Uint32 dwMaxShuter;
    /*�Զ��ع���������: 0~100db*/
    Uint32 dwMaxAgain;
    /*�Զ��ع�: Ĭ��Ŀ������: 0~100*/
    Uint32 dwTargetY;
    /*ʹ�ܺ��Ʋ��: 0--��ʹ�ܣ�1--ʹ��*/
    Uint32 dwLPRAEenable;
    /*������������:0~100*/
    Uint32 dwEptLPRBright;
    /*Ŀ�����ȷ�Χ: 0~100*/
    Uint32 dwMinTargetY;
    Uint32 dwMaxTargetY;
}PACKED TIPC_ExposureParam;

/*��ƽ��*/
typedef struct
{
    /*֧�ֵ�ģʽ�б�KISP_2A_AWB_INVALID*/
    Uint32 dwSptAWBModeList;
    /*��ƽ��ģʽ:E_KISP_AWB_MODE*/
    Uint32 dwAWBMode;
    /*����R\G\B����: 0~100*/
    Uint32 dwExpRgain;
    Uint32 dwExpBgain;
    /*�̶���ƽ��R\B: 0~100*/
    Uint32 dwWbRgain;
    Uint32 dwWbBgain;
}PACKED TIPC_WhiteBalParam;

/*ץ�����*/
typedef struct
{
    /*ץ�Ŀ�������*/
    Uint32 dwSnapMaxShuter;
    /*ץ����������*/
    Uint32 dwSnapMaxAgain;
    /*�����Ʒ���ʱ��*/
    Uint32 dwFLightTime;
    /*ҹ�䱬���Ʒ��ⷽʽ: FLASH_LIGHT_NIGHT_MODE_1������ �������� */
    Uint32 dwFLightMode;
    /*LED�Ʒ���ʱ��*/
    Uint32 dwLedTime;
    /*�Ҷ�����1��2��3*/
    Bool   bGStretch;
    Uint32 byGStretchCutOff;
    /*�������: ����ͼƬ��С���̶�ѹ������*/
    Uint32 dwEncCtrl;
    /*ͼƬ��С: 100~1024 KB*/
    Uint32 dwPicSize;
    /*ѹ������0~100*/
    Uint32 dwJpegQp;
}PACKED TIPC_SnapParam;

/*PLƫ�⾵����*/
typedef struct
{
    /*PL���Ʒ�ʽ: KISP_PL_AUTO���,�Զ�������������*/
    Uint32 dwPLCtrlMode;
    /*����PLƫ�⾵ESֵ*/
    Uint32 dwPLenableEs;
    /*ͣ��PLƫ�⾵ESֵ*/
    Uint32 dwPLdisableEs;
}PACKED TIPC_PLCtrlParam;

/*LED���Ʋ���*/
typedef struct
{
    /*LED���Ʒ�ʽ: KISP_LED_AUTO���*/
    Uint32 dwLedCtrlMode;
    /*LED��Ƶ��: 50\100*/
    Uint32 dwLedLightHz;
    /*LED������: 0~100*/
    Uint32 dwLedLightTime;
}PACKED TIPC_LedLightParam;

/*���ڲ���*/
typedef struct
{
    /*�豸��*/
    Char szDevName[MAX_SERIAL_NAME_LEN];
    /*������*/
    Uint32 dwBaudRate;
    /*ֹͣλ*/
    Uint32 dwStopBit;
    /*����λ*/
    Uint32 dwDataBit;
    /*��żУ��λ*/
    Uint32 dwParity;
    /*����Э������ESerialProtocol*/
    Uint32 dwProtocolType;
}PACKED TIPC_SerialParam;

/*�������ò���*/
typedef struct
{
    /*��������*/
    Uint32 dwSerialNum;
    /*���ڲ���*/
    TIPC_SerialParam atSerialParams[MAX_SERIAL_NUM];
}PACKED TIPC_SerialCfg;

/*ͼƬ����*/
typedef struct
{
    /*ͼ����� ����0���� 1ҹ��*/
    TIPC_ImageCtrlParam atImageCtrl[2];
    /*�ع� ͬ��*/
    TIPC_ExposureParam  atExposure[2];
    /*��ƽ�� ͬ��*/
    TIPC_WhiteBalParam  atWhiteBal[2];
    /*ץ�����*/
    TIPC_SnapParam      atSnap[2];
    /*��ҹ�л�*/
    /*��ҹ�л�ESֵ*/
    Uint32         dwDayNightSwitchEs;
    /*PLƫ�⾵����*/
    TIPC_PLCtrlParam   tPLCtrl;
    /*LED�ƿ��� 0:���á�1:����1��2:����2*/
    TIPC_LedLightParam atLedLight[3];
}PACKED TIPC_KdISPCfg;

/*��λ������*/
typedef struct 
{
    /*��Ч����*/
    Uint32 dwEsValue;
    /*��λ*/
    Uint32 dwPhase;
}PACKED TIPC_PhaseTableCfg;

/*��Դͬ������λ*/
typedef struct
{
    /*ʹ�ܵ�Դͬ��*/
    Bool   bEnablePwrSync;
    /*ʹ���Զ���λͬ�� False:�̶���λ True:�Զ�ͬ����λ��*/
    Bool   bAutoPhaseSync;
    /*�̶���λֵ0~180*/
    Uint32 dwFixPhase;
    /*��λ��*/
    TIPC_PhaseTableCfg atPhaseTable[MAX_PHASE_NUM];
}PACKED TIPC_PowerPhaseSync;

/*������������*/
typedef struct
{
    /*����ģʽ: ��E_STREAM_MODE*/
    Uint32 dwDebugMode;
    /*���ն�ip*/
    Uint32 dwIp;
    /*����port*/
    Uint16 wPort;
    char   szUsername[MAX_SIZE_USRNAME+1];
    char   szPassword[MAX_SIZE_PASSWORD+1];
    /*��ʶֵ:���������*/
    Uint32 dwSSRc;
}PACKED TIPC_BitStreamInfo;

/*����������Ӧ*/
typedef struct
{
    /*1:Error ����:�ɹ��ľ��*/
    Uint32 dwRetCode;
    /*����ģʽ: ��E_STREAM_MODE*/
    Uint32 dwDebugMode;
    /*���ն�ip*/
    Uint32 dwIp;
    /*����port*/
    Uint16 wPort;
    /*��ʶֵ,��Ӧ��ԭֵ����*/
    Uint32 dwSSRc;
}PACKED TIPC_BitStreamRsp;

/*�ر�������Ӧ*/
typedef struct
{
    /*1:ʧ�� 0:�ɹ�*/
    Uint32 dwRetCode;
    /*������ֵԭֵ����*/
    Uint32 dwStreamHd;
}PACKED TIPC_StopBitStreamRsp;

typedef struct
{
    /*��������������E_STREAM_MODE*/
    Uint32 dwBufType;
    /*�����ܳ���*/
    Uint32 dwLen;
    /*bufƫ����*/
    Uint32 dwOffset;
}PACKED TStreamSockHead;

/*����ģʽ�����Բ���*/
typedef struct 
{
    /*��Ƶ���*/
    Bool bVideoLoop;
    /*��Ƶ׷��*/
    Bool bVideotrack;
    /*�����Խ�*/
    Bool bAuxFocus;
    /*�ع����*/
    Bool bExposure;
    /*����״̬*/
    Bool bExDevice;
    /*2D�״�*/
    Bool b2DRadar;
    /*��Ʋ���*/
    Bool bRedLampTest;
    /*��Ч���� �̶�ֵ100~51200*/
    Uint32 dwEquShutter; 
    /*ͼƬ��С: 0--1/4��С��1--1/2��С��2--ԭͼ*/
    Uint32 dwPicSize;
    /*ѹ������*/
    Uint32 dwQpValue;
	/*Υͣģʽ*/
	Bool bIllMode;
}PACKED TIPC_DebugParam;

/*Osd����ͼƬ*/
typedef struct
{
    /*ͼƬ�Ĵ�С*/
    Uint32 dwSize;
    /*ͼƬץ��ʱ��*/
    Int64 qwTime;
    /*ͼƬ����*/
    Uint32 dwType;
    /*ͼƬ��*/
    Uint32 dwWidth;
    /*ͼƬ��*/
    Uint32 dwHeight;
    /*Osd����*/
    char szOsdContent[MAX_SIZE_LEN512];
    /*ͼƬ����*/
    void *szBuf;
}PACKED TIPC_OsdImgData;

/*��Ƶ�������ȡ������*/
typedef struct
{
    Int32       nRetCode;
    Uint32      dwSceneId;
    TIPC_VidLoopCfg tVideoLoop[VIDEO_LOOP_NUM_MAX];
}PACKED TIPC_GetVideoLoopRsp;

typedef struct
{
    Uint32      dwSceneId;
    TIPC_VidLoopCfg tVideoLoop[VIDEO_LOOP_NUM_MAX];
}PACKED TIPC_SetVideoLoopReq;

/*��Ȧ�������ȡ������*/
typedef struct
{
    Int32       nRetCode;
    Uint32      dwSceneId;
    TIPC_CoilLoopCfg    tCoilLoop[COIL_LOOP_CHANNEL_MAX];
}PACKED TIPC_GetCoilLoopRsp;

typedef struct
{
    Uint32          dwSceneId;
    TIPC_CoilLoopCfg    tCoilLoop[COIL_LOOP_CHANNEL_MAX];
}PACKED TIPC_SetCoilLoopReq;

/*�״�������ȡ������*/
typedef struct
{
    Int32       nRetCode;
    Uint32      dwSceneId;
    TIPC_RadarLoopCfg   tRadarLoop[RADAR_NUM_MAX];
}PACKED TIPC_GetRadarLoopRsp;

typedef struct
{
    Uint32          dwSceneId;
    TIPC_RadarLoopCfg   tRadarLoop[RADAR_NUM_MAX];
}PACKED TIPC_SetRadarLoopReq;

/*����źż������ȡ������*/
typedef struct
{
    Int32           nRetCode;
    Uint32          dwSceneId;
    TIPC_RedLampSigLoop tRedLoop[MAX_REDLAMP_DET_NUM];
}PACKED TIPC_GetRedLampSigRsp;

typedef struct
{
    Uint32          dwSceneId;
    TIPC_RedLampSigLoop tRedLoop[MAX_REDLAMP_DET_NUM];
}PACKED TIPC_SetRedLampSigReq;

/*ʶ�������ȡ������*/
typedef struct
{
    Int32       nRetCode;
    Uint32      dwSceneId;
    TIPC_RecogArea  tRecogArea[ROAD_NUM_MAX];
}PACKED TIPC_GetRecogAreaRsp;

typedef struct
{
    Uint32      dwSceneId;
    TIPC_RecogArea  tRecogArea[ROAD_NUM_MAX];
}PACKED TIPC_SetRecogAreaReq;

/*IO�������ȡ������*/
typedef struct
{
    Uint32  IOLabel;
    Int32   nRetCode;
}PACKED TIPC_GetIOLoopRsp;

typedef struct
{
    Uint32  IOLabel;
    Int32   nRetCode;
}PACKED TIPC_SetIOLoopRsp;

/*�����ǿ��ȡ������*/
typedef struct
{
    Int32       nRetCode;
    Uint32      dwSceneId;
    TIPC_RedSigEnhance tRedEnLoop[MAX_REDLAMP_DET_NUM];
}PACKED TIPC_GetRedEnRsp;

typedef struct
{
    Uint32         dwSceneId;
    TIPC_RedSigEnhance tRedEnLoop[MAX_REDLAMP_DET_NUM];
}PACKED TIPC_SetRedEnReq;

/*�߼�������ȡ������*/
typedef struct
{
    Int32   nRetCode;
    Uint32  dwSceneId;
    Uint16  wLogicLaneNum;
    TIPC_LogicLane  tLogicLane[LOGIC_ROAD_NUM_MAX];
}PACKED TIPC_GetLogicLaneRsp;

typedef struct
{
    Uint32      dwSceneId;
    Uint16      wLogicLaneNum;
    TIPC_LogicLane  tLogicLane[LOGIC_ROAD_NUM_MAX];
}PACKED TIPC_SetLogicLaneReq;

/*����ʶ�������ȡ*/
typedef struct  
{
    TIPC_RecogParam tParam;
    Int32       nRetCode;
}PACKED TIPC_GetRecogParamRsp;

/*��Ƶ�������û�ȡ*/
typedef struct
{
    Int32 nRetCode;
    TIPC_VidSpdDet tVidSpdDet;
}PACKED TIPC_GetVidSpdDetRsp;

/*ͼ��������û�ȡ*/
typedef struct
{
    Int32 nRetCode;
    TIPC_KdISPCfg tKdISPCfg;
}PACKED TIPC_GetKISPCfgRsp;

/*��ȡ��Դ��λͬ��*/
typedef struct  
{
    Int32 nRetCode;
    TIPC_PowerPhaseSync tPowerSync;
}PACKED TIPC_GetPowerSnycRsp;

/*��ȡipc���Բ���*/
typedef struct
{
    Int32 nRetCode;
    TIPC_DebugParam tDebugParam;
}PACKED TIPC_GetDebugParamRsp;

/*��ȡipc��������*/
typedef struct
{
    Int32 nRetCode;
    TIPC_SerialCfg tSerialCfg;
}PACKED TIPC_GetSerialCfgRsp;

/*----------------------------------------------------------
 *ǰ�˽ṹ�壨IPC V7��
 *----------------------------------------------------------*/
/*UI����������*/
typedef struct
{
    Int32       nRetCode;   // 
    Bool        bCap;       // 0:��֧��; 1��֧��
    Uint8       szCaps[EMUI_CAP_TYPE_COUNT]; // EMUI_CAP_TYPE��0:��֧�֣�> 0 ��֧��; 
                                             //1,һ���汾�� 2�������汾����ͬ�汾��˵����ö�ٶ���λ��˵��
}PACKED TIPC_GetUICapsRsp;

typedef struct {
    /*Υ������*/
    Uint32 illegalName;
    /*Υ�´���*/
    Uint32 wzCode;
}PACKED TIllegalDict;

typedef struct {
	/*ʵ��Υ��������*/
	Uint32 dwNum;
	/*Υ������*/
	TIllegalDict atIllegalDict[MAX_NUM_ILLEGAL_TYPE];
}PACKED TIllegalDictLisl;

typedef struct {
	/*�ļ����ݵĴ�С*/
	Uint32 dwSize;
	/*�ļ�����*/
	Char *szData;
}PACKED TDevAllConfig;


/*Υͣ�������*/
typedef struct {
    /*ʹ��*/
    Bool enable;
    /*��С�������*/
    Uint32 minVehWidth;
    /*��������*/
    Uint32 maxVehWidth;
    /*���������: 0--��, 1--��*/
    Uint32 level;
	/*�ϰ벿ɨ����ֵ*/
	float halfScanfVal;
	/*ɨ�貽��*/
	float scanfstep;
	/*��ֵ����*/
	float trimVal;
	/*�����˲�*/
	Uint32 filterOn;
	/*�뿪�˲�*/
	Uint32 filterOff;
    /*��������*/
    Uint32 pointNum;
    TPoint_S  tPoint[ROI_AREA_POINT_MAX];
}TIPC_illParkArea_S;

/*Υͣ���ò���: ���֧��4������*/
typedef struct {
	/*�Ƿ�ʹ��*/
	Bool enable;
	/*����ģʽ:����ץ��ģʽ������ȷ��ģʽ   ����ȷ��ģʽ*/
	Uint32 workMode;
	/*����ID��*/
	Uint32 parkId;
    /*֧�ֵĳ�������: ֻ������*/
    Uint32 sptSceneNum;
	/*Ԥ��λ���*/
    Uint32 PrePosLabel;
    /*��ѯʱ��: ��ȷ����*/
    Uint32 timeRetention;
    /*Υͣץ��ʱ��: ��ȷ����*/
    Uint32 illParkTime;
	/*Υͣ��������ʱ��: ��ȷ����*/
	Uint32 illParkNoticeTime;
    /*�������: ���4��*/
    Uint32 RoiAreaNum;
    /*�������*/
    TIPC_illParkArea_S tRoiArea[VEH_DET_ROI_NUM_MAX];
	/*����ʱ��*/
    TIPC_SnapTiming tSnapTiming[MAX_NUM_SNAPTIMING];
	/*����ץ�ļ�������ӣ�*/
	Uint32 dwSecSnapTime;
	/*��������*/
    Uint32 maxShutter;
    /*��������*/
    Uint32 maxAgain;
    /*���õ�1*/
    Uint32 internalLight1; 
    /*���õ�2*/
    Uint32 internalLight2;
    /*���õ�3*/
    Uint32 internalLight3;
    /*���õ�*/
    Uint32 externalLight;
	/*ͼƬ1--ȫ�� 2--�о� 3--���� 4--��д*/
	Uint32 picMode[VEH_DET_ROI_NUM_MAX];

}TIPC_illgParkPara;

/*��ȡΥͣ���ò�������*/
typedef struct {
	/*����ID��*/
	Uint32 parkId;
}TIPC_GetIllgParkParaReq;

/*�����Ȳ���*/
typedef struct
{
    /*1���Ŵ������*/
    Uint32 brightness1x;
    /*2���Ŵ������*/
    Uint32 brightness2x;
    /*3���Ŵ������*/
    Uint32 brightness3x;
    /*4���Ŵ������*/
    Uint32 brightness4x;
    /*5���Ŵ������*/
    Uint32 brightness5x;
    /*6���Ŵ������*/
    Uint32 brightness6x;
    /*7���Ŵ������*/
    Uint32 brightness7x;
    /*8���Ŵ������*/
    Uint32 brightness8x;
    /*9���Ŵ������*/
    Uint32 brightness9x;
    /*10���Ŵ������*/
    Uint32 brightness10x;
    /*11���Ŵ������*/
    Uint32 brightness11x;
    /*12���Ŵ������*/
    Uint32 brightness12x;
    /*13���Ŵ������*/
    Uint32 brightness13x;
    /*14���Ŵ������*/
    Uint32 brightness14x;
    /*15���Ŵ������*/
    Uint32 brightness15x;
    /*16���Ŵ������*/
    Uint32 brightness16x;
    /*17���Ŵ������*/
    Uint32 brightness17x;
    /*18���Ŵ������*/
    Uint32 brightness18x;
    /*19���Ŵ������*/
    Uint32 brightness19x;
    /*20���Ŵ������*/
    Uint32 brightness20x;
    /*21���Ŵ������*/
    Uint32 brightness21x;
    /*22���Ŵ������*/
	Uint32 brightness22x;
    /*23���Ŵ������*/
    Uint32 brightness23x;
    /*24���Ŵ������*/
    Uint32 brightness24x;
    /*25���Ŵ������*/
    Uint32 brightness25x;
    /*26���Ŵ������*/
    Uint32 brightness26x;
    /*27���Ŵ������*/
    Uint32 brightness27x;
    /*28���Ŵ������*/
    Uint32 brightness28x;
    /*29���Ŵ������*/
    Uint32 brightness29x;
    /*30���Ŵ������*/
    Uint32 brightness30x;
    /*31���Ŵ������*/
    Uint32 brightness31x;
    /*32���Ŵ������*/
    Uint32 brightness32x;
    /*33���Ŵ������*/
    Uint32 brightness33x;
    /*34���Ŵ������*/
    Uint32 brightness34x;
    /*35���Ŵ������*/
    Uint32 brightness35x;
    /*36���Ŵ������*/
    Uint32 brightness36x;
    /*37���Ŵ������*/
    Uint32 brightness37x;
}TIPC_LightParam;

typedef struct 
{
	/*�Ƿ�����*/
	Bool bEnable;
	/*Ԥ��λ*/
	Uint32 posId;
	/*ͣ��ʱ��*/
	Uint32 stayTime[MAX_NUM_SNAPTIMING][MAX_NUM_DECT_TIME];
	/*Ӧ������*/
	Uint32 appType;
	/*��������*/
    Uint32 maxShutter;
    /*��������*/
    Uint32 maxAgain;
    /*���õ�1*/
    Uint32 internalLight1; 
    /*���õ�2*/
    Uint32 internalLight2;
    /*���õ�3*/
    Uint32 internalLight3;
    /*���õ�1*/
    Uint32 externalLight1;
	/*���õ�2*/
    Uint32 externalLight2;
    /*����ʱ��*/
    TIPC_SnapTiming tSnapTiming[MAX_NUM_SNAPTIMING];

}PACKED TIPC_ScenePoll;

typedef struct
{
    Uint32 dwFlowCnt;
    Uint32 dwVehSpeed;
    /*����ƽ���ٶ�,�����ֳ���*/
	Uint32 dwVehAveSpd;
    Uint32 dwDeltaTimes;
    Uint32 dwDeltaDistance;
    float  fTimeOccupancy;
    float  fSpaceOccupancy;
    float  fVehQueLen;
    /*·�� ETrafficState*/
    Uint32 dwState;
}TIPC_LaneFlowInfo;

/*����ͳ����Ϣ*/
typedef struct
{
    /*ͳ��ʱ��*/
    Uint32 dwStatTime[E_UPDATE_PERIOD_TYPE_COUNT];
    /*ͳ������ֵ*/
    Uint32 dwStatCnts;
    Uint32 dwVehAveSpd;
}TIPC_LaneFlowStatInfo;

typedef struct
{
    Bool bEnable;
    /*���·�ʽ: 1δ��ʱ��� 2���ڸ���*/
    Uint8 byUpdateType;
    /*�������� ��ÿ2Сʱͳ�Ƹ��� dwUpdatePeriod[E_UPDATE_PERIOD_TYPE_HOUR] = 2*/
    Uint32 dwUpdatePeriod[E_UPDATE_PERIOD_TYPE_COUNT];
    /*�����������Ӧ��������� Զ�������ǰ*/
    float fDetPhyLen[RETENTION_NUM_MAX];
    /*IPC���ӽǶ��µĵ�·�ܳ���*/
    //float fPhyTotalLen;
    /*����Ҫ���µ�����ֵ*/
	Uint32 dwUpdateFlowCnts;
}TVidLopFlowCfg;

/*��ȡ�����������������Ӧ*/
typedef struct
{
    Int32   nRetCode;
    Uint32  dwSceneId;
    TVidLopFlowCfg  atFlowCfg[ROAD_NUM_MAX];
}TIPC_GetVidLoopFlowCfgRsp;

/*���ó������������������*/
typedef struct
{
    Uint32  dwSceneId;
    TVidLopFlowCfg atFlowCfg[ROAD_NUM_MAX];
}TIPC_SetVidLoopFlowCfgReq;

/*��������Ϣ֪ͨ*/
typedef struct
{
    Uint32  dwSceneId;
    TIPC_LaneFlowInfo  atFlowInfo[ROAD_NUM_MAX];
}TIPC_VehFlowInfoNty;

/*������ͳ��֪ͨ*/
typedef struct
{
    Uint32  dwSceneId;
	Uint32  dwLaneId; /*0: ���г������£�����:��Ӧ��������,ȡ�½ṹ���Ӧ������Ϣ*/
    TIPC_LaneFlowStatInfo  atFlowStat[ROAD_NUM_MAX];
}TIPC_VehFlowStatInfoNty;

typedef struct
{
    /*���к�*/
    Uint32 serial;
    /*Υ������*/
    Char illegalName[64];
    /*Υ������*/
    Uint32 code;
	 /*�¼����룬��Э���EIllegalTypeö��ֵ��Ӧ*/
    Uint32 ivhsEventCode;
}TIPC_IllegalCode;

typedef struct
{
    /*�ֵ����*/
    Uint32 sum;
    /*�ֵ�����*/
    TIPC_IllegalCode tIllegalCode[MAX_ILLEGAL_NUM];
}TIPC_IllegalDict;

typedef struct
{
    /*ǰ��Ӳ��id��*/
	Char achDevId[MAX_SIZE_DEV_ID];
    /*�������ͣ��ο�E_DEV_ERROR_NOTICE*/
    Uint32 dwErrorNotice;
	/*���ϵ�ǰ״̬,�ο�E_DEV_STATE*/
    Uint32 dwState;

}TIPC_DevStateNty;


// #ifdef _MSC_VER
//     #pragma pack(pop)
// #endif //WIN32

#pragma pack(pop)
#endif //_IVHS_STRUCT_H_




