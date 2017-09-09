#ifndef _IVHS_DEFINE_H_
#define _IVHS_DEFINE_H_

#pragma pack(push, 1)
#ifdef _MSC_VER
#define PACKED
#else
#define PACKED
#endif //LINUX

#include "kosa.h"
//#include "kdvtype.h"

/*----------------------------------------------------------
*��Ϣ���Ͷ���(�ƴ���Ϣ    +    ͳһ�ӿڲ���Ϣ)
*----------------------------------------------------------*/

/*******************�ƴ���Ϣ���Ͷ���:���********************/
/*��������
������
*/
#define EV_KEDA_HEARTBEAT_CMD                       102
/*���͹�����Ϣ����
������TVechileData
*/
#define EV_VEHICLE_INFO_DATA_CMD                    1724
/*������ʷ��������
������
*/
#define EV_START_SEND_HISTORY_DATA_CMD              1725
/*ֹͣ������ʷ��������
������
*/
#define EV_STOP_SEND_HISTORY_DATA_CMD               1726
/*��ʷ�����ϴ����֪ͨ
������
*/
#define EV_UPLOAD_FINISHED_NTY                      1727
/*���չ������ݵ���Ӧ
������TVechileDataAck
*/
#define EV_VEHICLE_INFO_DATA_ACK                    1728
/*����ֹͣ�ɼ���Ƶ��������
������TVideoCapture
*/
#define EV_STOP_CAPTURE_VIDEO_CMD                   1729
/*ʵʱ��Ƶ����
������
*/
#define EV_REAL_TIME_VIDEO_CMD                      1730
/*�������������豸����
������
*/
#define EV_DEV_DISCOVERY_REQ                        1731
/*�������������豸��Ӧ
������
*/
#define EV_DEV_DISCOVERY_ACK                        1732
/*ǰ������ע������
������TLoginReq
*/
#define EV_REGISTER_REQ                             1733
/*ǰ������ע����Ӧ
������TLoginRsp
*/
#define EV_REGISTER_ACK                             1734
/*ǰ����������
������
*/
#define EV_DEV_REBOOT_CMD                           1735
/*ǰ��ʱ��ͬ������
������
*/
#define EV_TIME_SYNC_REQ                            1736
/*ǰ��ʱ��ͬ����Ӧ
������
*/
#define EV_TIME_SYNC_ACK                            1737
/*ǰ�˹����ϱ�
������TIPC_DevStateNty
*/
#define EV_DEV_BREAKDOWN_NTY                        1738
/*��ͨ������Ϣ�ϱ�
������
*/
#define EV_TRAFFIC_CFG_NTY                          1739
/*ǰ����������
������
*/
#define EV_DEV_OFFLINE_REQ                          1740
/*ǰ��������Ӧ
������
*/
#define EV_DEV_OFFLINE_ACK                          1741
/*ǰ�˶���֪ͨ
�������豸ID
*/
#define EV_DEV_DISCONNECT_NTY                      1742
/*��ȡǰ���豸��������
������achDevId
*/
#define EV_GET_DEV_CFG_REQ                          1743
/*��ȡǰ���豸����Ӧ��
������TCfgInfo
*/
#define EV_GET_DEV_CFG_ACK                          1744
/*����ǰ���豸��������
������TCfgInfo
*/
#define EV_SET_DEV_CFG_REQ                          1745
/*����ǰ���豸����Ӧ��
������achDevId(64)+retcode(u16)
*/
#define EV_SET_DEV_CFG_ACK                          1746
/*��������
������
*/
#define EV_ARRAGEMENT_REQ                           1747
/*������Ӧ
������
*/
#define EV_ARRAGEMENT_ACK                           1748
/*��������
������
*/
#define EV_REMOVE_ARRAGEMENT_REQ                    1749
/*������Ӧ
������
*/
#define EV_REMOVE_ARRAGEMENT_ACK                    1750
/*��ȡ�����б�����
������
*/
#define EV_GET_BAY0NET_LIST_REQ                     1751
/*��ȡ�����б���Ӧ
������
*/
#define EV_GET_BAY0NET_LIST_ACK                     1752
/*��ѯ�豸����״̬����
������
*/
#define EV_GET_DEV_STATE_REQ                        1753
/*��ѯ�豸����״̬��Ӧ
������
*/
#define EV_GET_DEV_STATE_ACK                        1754
/*���������ϱ�
������
*/
#define EV_ALARM_DATA_NTY                           1755
/*���Ŀ�������
������
*/
#define EV_SUBSCRIBE_CMD                            1756
/*ȡ�����Ŀ�������
������
*/
#define EV_SUBSCRIBE_CANCLE_CMD                     1757
/*����ͨ����Ϣ����*/
#define EV_SEND_COMMON_REQ                          1224
/*����ͨ����Ϣ��Ӧ*/
#define EV_SEND_COMMON_ACK                          1225
/*�½�����֪ͨ*/
#define EV_NEW_CONNECT_NTY                          1226

/*բ����������ƽ̨-->�豸��*/
#define EV_OP_DOOR_REQ                              5000
/*բ��������Ӧ���豸-->ƽ̨��*/
#define EV_OP_DOOR_ACK                              5001
/*�ϱ�����״̬��Ϣ ���豸-->ƽ̨��*/
#define EV_UPLOAD_SERIAL_INFO_NTY                   5002
/*��ʼ����ʱʵ��Ƶ��������*/
#define EV_START_SEND_VIDEO_STREAM_REQ              5003
/*��ʼ����ʱʵ��Ƶ������Ӧ*/
#define EV_START_SEND_VIDEO_STREAM_ACK              5004
/*ֹͣ����ʱʵ��Ƶ��������*/
#define EV_STOP_SEND_VIDEO_STREAM_REQ               5005
/*ֹͣ����ʱʵ��Ƶ������Ӧ*/
#define EV_STOP_SEND_VIDEO_STREAM_ACK               5006
/*��ȡ���ʱ������*/
#define EV_GET_CAM_TIME_REQ                         5007
/*��ȡ���ʱ����Ӧ*/
#define EV_GET_CAM_TIME_ACK                         5008
/*ϵͳ��������*/
#define EV_SYSTEM_UPGRADE_REQ                       5009
/*ϵͳ������Ӧ*/
#define EV_SYSTEM_UPGRADE_ACK                       5010

#define EV_SYN_SNP_REQ                              5011
#define EV_SYN_SNP_ACK                              5012

/*****************�ƴ���Ϣ���Ͷ���:�羯ҵ��******************/
/*��ȡͼƬ�ϳ�*/
#define EV_GET_IMAGE_MERGE_CFG_REQ                  5200    //NULL
#define EV_GET_IMAGE_MERGE_CFG_ACK                  5201    //TImageMergeRsp
/*����ͼƬ�ϳ�*/
#define EV_SET_IMAGE_MERGE_CFG_REQ                  5202    //TImageMergeCfg
#define EV_SET_IMAGE_MERGE_CFG_ACK                  5203    //NULL
/*��ȡosd����*/
#define EV_GET_OSD_CONFIG_REQ                       5204    //����u32 osd type ��ENUM_ITS_OSD_IMAGE_TYPE
#define EV_GET_OSD_CONFIG_ACK                       5205    //TOsdCfgRsp
/*����osd����*/
#define EV_SET_OSD_CONFIG_REQ                       5206    //TOsdCfgInfo
#define EV_SET_OSD_CONFIG_ACK                       5207    //NULL
/*��ȡosd����*/
#define EV_GET_OSD_FONT_CFG_REQ                     5208    //����u32 osd type ͬ��
#define EV_GET_OSD_FONT_CFG_ACK                     5209    //TOsdFontCfgRsp
/*����osd����*/
#define EV_SET_OSD_FONT_CFG_REQ                     5210    //TOsdFontCfg
#define EV_SET_OSD_FONT_CFG_ACK                     5211    //NULL
/*ͼƬ�洢*/
#define EV_GET_STORE_CONFIG_REQ                     5212    //NULL
#define EV_GET_STORE_CONFIG_ACK                     5213    //TImageStoreRsp
/*ͼƬ�洢*/
#define EV_SET_STORE_CONFIG_REQ                     5214    //TImageStore
#define EV_SET_STORE_CONFIG_ACK                     5215    //NULL
/*��ȡ���ķ�����*/
#define EV_GET_SERVER_CONFIG_REQ                    5216    //NULL
#define EV_GET_SERVER_CONFIG_ACK                    5217    //TITS_GetServerRsp
/*�������ķ�����*/
#define EV_SET_SERVER_CONFIG_REQ                    5218    //TITS_SetServerReq
#define EV_SET_SERVER_CONFIG_ACK                    5219    //NULL
/*���ǰ���豸*/
#define EV_ADD_DEVICE_REQ                           5220    //TITS_DevList
#define EV_ADD_DEVICE_ACK                           5221    //�ݲ��� NULL
/*ɾ��ǰ���豸*/
#define EV_DEL_DEVICE_REQ                           5222    //TITS_DevList
#define EV_DEL_DEVICE_ACK                           5223    //NULL
/*��ȡ�豸��Ϣ*/
#define EV_GET_DEVINFO_CONFIG_REQ                   5224    //TITS_GetDevInfoReq
#define EV_GET_DEVINFO_CONFIG_ACK                   5225    //TITS_GetDevInfoRsp
/*�����豸��Ϣ*/
#define EV_SET_DEVINFO_CONFIG_REQ                   5226    //TITS_SetDevInfoReq
#define EV_SET_DEVINFO_CONFIG_ACK                   5227    //NULL
/*��ȡ��������豸����*/
#define EV_GET_AUX_DEVINFO_REQ                      5228    //TITS_GetDevInfoReq
#define EV_GET_AUX_DEVINFO_ACK                      5229    //TITS_GetAuxCameraRsp
/*���ø�������豸����*/
#define EV_SET_AUX_DEVINFO_REQ                      5230    //TITS_SetAuxCameraReq
#define EV_SET_AUX_DEVINFO_ACK                      5231    //NULL
/*��ȡ�豸�б�*/
#define EV_GET_DEVLIST_CONFIG_REQ                   5232    //NULL
#define EV_GET_DEVLIST_CONFIG_ACK                   5233    //TITS_GetDevListRsp
/*��ȡ¼������*/
#define EV_GET_VIDEO_CONFIG_REQ                     5234    //TITS_GetVideoCfgReq
#define EV_GET_VIDEO_CONFIG_ACK                     5235    //TITS_GetVideoCfgRsp
/*����¼������*/
#define EV_SET_VIDEO_CONFIG_REQ                     5236    //TITS_VideoSectCfg
#define EV_SET_VIDEO_CONFIG_ACK                     5237    //NULL

/*ʵʱ������Ϣ����(���ڿͻ���)*/
#define EV_RT_VEHICLE_INFO_REC_REQ                  5238    //TITS_RtVehicleReq
/*���ݲ�ѯ*/
#define EV_QUERY_DATA_REQ                           5239    //TDataQuery
#define EV_QUERY_DATA_ACK                           5240    //TITS_QueryResultRsp

/*ͼƬ���͹���ͻָ�(Ŀǰ���ڿͻ���)*/
#define EV_POST_PIC_SUSPEND                         5241    //NULL
#define EV_POST_PIC_UNSUSPEND                       5242    //NULL

/***************�ƴ���Ϣ���Ͷ���:IPC V7ҵ��*****************/

/*IPCtrlץ��ͼƬ*/
#define EV_CAPTURE_PIC_REQ                          6000    //u32 capture_type
#define EV_CAPTURE_PIC_ACK                          6001    //NULL
/*��ȡ��������*/
#define EV_GET_SCENE_CFG_REQ                        6002    //u32 dwSceneId
#define EV_GET_SCENE_CFG_ACK                        6003    //TIPC_GetSceneCfgRsp
/*���ó�������*/
#define EV_SET_SCENE_CFG_REQ                        6004    //TIPC_SetSceneCfgReq
#define EV_SET_SCENE_CFG_ACK                        6005    //NULL
/*�Զ�������Ƶ�����*/
#define EV_AUTO_CREATE_VIDEO_LOOP_REQ               6006    //u32 dwSceneId
#define EV_AUTO_CREATE_VIDEO_LOOP_ACK               6007    //NULL
/*��ȡ��Ƶ���������*/
#define EV_GET_VIDEO_LOOP_CFG_REQ                   6008    //u32 dwSceneId
#define EV_GET_VIDEO_LOOP_CFG_ACK                   6009    //TIPC_GetVideoLoopRsp
/*������Ƶ���������*/
#define EV_SET_VIDEO_LOOP_CFG_REQ                   6010    //TIPC_SetVideoLoopReq
#define EV_SET_VIDEO_LOOP_CFG_ACK                   6011    //NULL
/*��ȡ��Ȧ���������*/
#define EV_GET_COIL_LOOP_CFG_REQ                    6012    //u32 dwSceneId
#define EV_GET_COIL_LOOP_CFG_ACK                    6013    //TIPC_GetCoilLoopRsp
/*������Ȧ���������*/
#define EV_SET_COIL_LOOP_CFG_REQ                    6014    //TIPC_SetCoilLoopReq
#define EV_SET_COIL_LOOP_CFG_ACK                    6015    //NULL
/*��ȡ�״���������*/
#define EV_GET_RADAR_LOOP_CFG_REQ                   6016    //u32 dwSceneId
#define EV_GET_RADAR_LOOP_CFG_ACK                   6017    //TIPC_GetRadarLoopRsp
/*�����״���������*/
#define EV_SET_RADAR_LOOP_CFG_REQ                   6018    //TIPC_SetRadarLoopReq
#define EV_SET_RADAR_LOOP_CFG_ACK                   6019    //NULL
/*��ȡIO���������*/
#define EV_GET_IO_LOOP_CFG_REQ                      6020    //δʵ��
#define EV_GET_IO_LOOP_CFG_ACK                      6021    //δʵ��
/*����IO���������*/
#define EV_SET_IO_LOOP_CFG_REQ                      6022    //δʵ��
#define EV_SET_IO_LOOP_CFG_ACK                      6023    //δʵ��
/*��ȡ��Ƽ��������*/
#define EV_GET_RED_LAMP_CFG_REQ                     6024    //u32 dwSceneId
#define EV_GET_RED_LAMP_CFG_ACK                     6025    //TIPC_GetRedLampSigRsp
/*���ú�Ƽ��������*/
#define EV_SET_RED_LAMP_CFG_REQ                     6026    //TIPC_SetRedLampSigReq
#define EV_SET_RED_LAMP_CFG_ACK                     6027    //NULL
/*��ȡʶ����������*/
#define EV_GET_RECOG_AREA_CFG_REQ                   6028    //u32 dwSceneId
#define EV_GET_RECOG_AREA_CFG_ACK                   6029    //TIPC_GetRecogAreaRsp
/*����ʶ����������*/
#define EV_SET_RECOG_AREA_CFG_REQ                   6030    //TIPC_SetRecogAreaReq
#define EV_SET_RECOG_AREA_CFG_ACK                   6031    //NULL
/*��ȡ�����ǿ����*/
#define EV_GET_ENHANCE_RED_CFG_REQ                  6032    //u32 dwSceneId
#define EV_GET_ENHANCE_RED_CFG_ACK                  6033    //TIPC_GetRedEnRsp
/*���ú����ǿ����*/
#define EV_SET_ENHANCE_RED_CFG_REQ                  6034    //TIPC_SetRedEnReq
#define EV_SET_ENHANCE_RED_CFG_ACK                  6035    //NULL
/*�Զ������߼�����*/
#define EV_AUTO_CREATE_LOGIC_LANE_REQ               6036    //u32 dwSceneId
#define EV_AUTO_CREATE_LOGIC_LANE_ACK               6037    //NULL
/*��ȡ�߼�����*/
#define EV_GET_LOGIC_LANE_CFG_REQ                   6038    //u32 dwSceneId
#define EV_GET_LOGIC_LANE_CFG_ACK                   6039    //TIPC_GetLogicLaneRsp
/*�����߼�����*/
#define EV_SET_LOGIC_LANE_CFG_REQ                   6040    //TIPC_SetLogicLaneReq
#define EV_SET_LOGIC_LANE_CFG_ACK                   6041    //NULL
/*��ȡʶ�����*/
#define EV_GET_RECOG_PARAM_CFG_REQ                  6042    //NULL
#define EV_GET_RECOG_PARAM_CFG_ACK                  6043    //TIPC_GetRecogParamRsp
/*����ʶ�����*/
#define EV_SET_RECOG_PARAM_CFG_REQ                  6044    //TIPC_RecogParam
#define EV_SET_RECOG_PARAM_CFG_ACK                  6045    //NULL
/*��ȡIPC�豸����*/
#define EV_GET_IPC_DEV_INFO_REQ                     6046    //NULL
#define EV_GET_IPC_DEV_INFO_ACK                     6047    //TIPC_GetDevRsp
/*����IPC�豸����*/
#define EV_SET_IPC_DEV_INFO_REQ                     6048    //TIPC_DevInfo
#define EV_SET_IPC_DEV_INFO_ACK                     6049    //NULL
/*PTZ����*/
#define EV_PTZ_CTRL_REQ                             6050    //TIPC_PTZCtrl
#define EV_PTZ_CTRL_ACK                             6051    //NULL
/*��ȡIPC��Ƶ����*/
#define EV_GET_VIDEO_SPD_DET_CFG_REQ                6052    //NULL
#define EV_GET_VIDEO_SPD_DET_CFG_ACK                6053    //TIPC_GetVidSpdDetRsp
/*����IPC��Ƶ����*/
#define EV_SET_VIDEO_SPD_DET_CFG_REQ                6054    //TIPC_VidSpdDet
#define EV_SET_VIDEO_SPD_DET_CFG_ACK                6055    //NULL
/*��ȡͼ����ڲ���*/
#define EV_GET_IPC_ISP_CFG_REQ                      6056    //NULL
#define EV_GET_IPC_ISP_CFG_ACK                      6057    //TIPC_GetKISPCfgRsp
/*����ͼ����ڲ���*/
#define EV_SET_IPC_ISP_CFG_REQ                      6058    //TIPC_KdISPCfg
#define EV_SET_IPC_ISP_CFG_ACK                      6059    //NULL
/*��ȡ��Դ��λͬ��*/
#define EV_GET_IPC_POWER_SYNC_REQ                   6060    //NULL
#define EV_GET_IPC_POWER_SYNC_ACK                   6061    //TIPC_GetPowerSnycRsp
/*���õ�Դ��λͬ��*/
#define EV_SET_IPC_POWER_SYNC_REQ                   6062    //TIPC_PowerPhaseSync
#define EV_SET_IPC_POWER_SYNC_ACK                   6063    //NULL
/*������ JPEG����*/
#define EV_IPC_BIT_STREAM_START_REQ                 6064    //TIPC_BitStreamInfo
#define EV_IPC_BIT_STREAM_START_ACK                 6065    //TIPC_BitStreamRsp
/*������ JPEG����*/
#define EV_IPC_BIT_STREAM_STOP_REQ                  6066    //u32 (start_ack���صľ��)
#define EV_IPC_BIT_STREAM_STOP_ACK                  6067    //TIPC_StopBitStreamRsp
/*��ȡ���Բ���*/
#define EV_GET_IPC_DEBUG_PARAM_REQ                  6068    //NULL
#define EV_GET_IPC_DEBUG_PARAM_ACK                  6069    //TIPC_GetDebugParamRsp
/*���õ��Բ���*/
#define EV_SET_IPC_DEBUG_PARAM_REQ                  6070    //TIPC_DebugParam
#define EV_SET_IPC_DEBUG_PARAM_ACK                  6071    //NULL
/*UI��������ȡ*/
#define EV_GET_IPC_UI_CAP_REQ                       6072    //NULL
#define EV_GET_IPC_UI_CAP_ACK                       6073    //TIPC_GetUICapsRsp
/*��ȡ��������*/
#define EV_GET_IPC_SERIAL_CFG_REQ                   6074    //NULL
#define EV_GET_IPC_SERIAL_CFG_ACK                   6075    //TIPC_GetSerialCfgRsp
/*���ô�������*/
#define EV_SET_IPC_SERIAL_CFG_REQ                   6076    //TIPC_SerialCfg
#define EV_SET_IPC_SERIAL_CFG_ACK                   6077    //NULL
/*��ȡ����IPC�汾��*/
#define EV_GET_IPC_VERSION_REQ                      6078    //NULL
#define EV_GET_IPC_VERSION_ACK                      6079    //char szVersion[64]

#define EV_UPLOAD_IPC_OSD_BACK_PIC                  6080    //TIPC_OsdImgData

/*��ȡΥ�����͵�������������,��Ϣ����Ϊ��*/
#define EV_GET_ILLEGAL_DICT_REQ						6081
/*��ȡΥ�����͵�����������Ӧ����Ϣ����TIllegalDictLisl*/
#define EV_GET_ILLEGAL_DICT_ACK						6082


/*��ȡΥ�����͵�������������,��Ϣ����ΪTIllegalDictLisl*/
#define EV_SET_ILLEGAL_DICT_REQ						6083
/*��ȡΥ�����͵�����������Ӧ����Ϣ����Ϊ��*/
#define EV_SET_ILLEGAL_DICT_ACK						6084


/*�ָ���������������Ϣ����Ϊpuid*/
#define EV_RESTORE_SETTINE_REQ						6085
/*�ָ�����������Ӧ����Ϣ����Ϊpuid*/
#define EV_RESTORE_SETTINE_ACK						6086

/*���������ļ�������Ϣ����Ϊpuid*/
#define EV_READ_CONFIG_REQ							6087
/*���������ļ���Ӧ����Ϣ����ΪTDevAllConfig*/
#define EV_READ_CONFIG_ACK							6088


/*��ȡΥͣ���ò�������Ϣ����ΪTIPC_GetIllgParkParaReq*/
#define EV_GET_ILLG_PARK_REQ						6089
/*��ȡΥͣ���ò�������Ϣ����ΪTIPC_illgParkPara*/
#define EV_GET_ILLG_PARK_ACK						6090

/*����Υͣ���ò�������Ϣ����ΪTIPC_illgParkPara*/
#define EV_SET_ILLG_PARK_REQ						6091
/*����Υͣ���ò�������Ϣ����Ϊpuid*/
#define EV_SET_ILLG_PARK_ACK						6092

/*��ѯ������¼����*/
#define EV_QUERY_RECORD_REQ                         6093    //TIPC_PicQuery
/*��ѯ������¼��Ӧ*/
#define EV_QUERY_RECORD_ACK                         6094    //TIPC_PicQueryResult
/*��ȡ������¼����*/
#define EV_GET_RECORD_REQ                           6095    //Uint32 RecordId ʵ�ʶ�Ӧdb�е�KeyId
/*��ȡ������¼��Ӧ*/
#define EV_GET_RECORD_ACK                           6096    //TVechileData

/*��ȡ�����Ȳ���������Ϣ����Ϊpuid*/
#define EV_GET_LIGHT_PARAM_REQ                      6097    //
/*��ȡ�������Ȳ�����Ӧ����Ϣ����ΪTIPC_LightParam*/
#define EV_GET_LIGHT_PARAM_ACK                      6098    //TIPC_LightParam
/*���õ����Ȳ���������Ϣ����ΪTIPC_LightParam*/
#define EV_SET_LIGHT_PARAM_REQ                      6099    //TIPC_LightParam 
/*���õ����Ȳ�����Ӧ����Ϣ����Ϊpuid*/
#define EV_SET_LIGHT_PARAM_ACK                      6100    //

/*��ȡScenePoll����������Ϣ����Ϊpuid*/
#define EV_GET_SCENEPOLL_REQ                        6101    //
/*��ȡ��ScenePoll������Ӧ����Ϣ����ΪTIPC_ScenePoll[MAX_NUM_SCENEPOLL]*/
#define EV_GET_SCENEPOLL_ACK                        6102    //
/*����ScenePoll����������Ϣ����ΪTIPC_ScenePoll[MAX_NUM_SCENEPOLL]*/
#define EV_SET_SCENEPOLL_REQ                        6103    //
/*����ScenePoll������Ӧ����Ϣ����Ϊpuid*/
#define EV_SET_SCENEPOLL_ACK                        6104    //

/*��ȡIPC���������������*/
#define EV_GET_IPC_FLOW_CFG_REQ                     6201    //u32 dwSceneId
#define EV_GET_IPC_FLOW_CFG_ACK                     6202    //TIPC_GetVidLoopFlowCfgRsp
/*����IPC���������������*/
#define EV_SET_IPC_FLOW_CFG_REQ                     6203    //TIPC_SetVidLoopFlowCfgReq
#define EV_SET_IPC_FLOW_CFG_ACK                     6204    //NULL
/*��������Ϣ֪ͨ ���->�ͻ���*/
#define EV_IPC_FLOWINFO_NTY                         6205    //TIPC_VehFlowInfoNty

/*����Υ���ֵ�����,��Ϣ����ΪTIPC_IllegalDict*/
#define EV_SET_ILLEGAL_CODE_LIST_REQ				6206
/*����Υ���ֵ���Ӧ����Ϣ����Ϊ��*/
#define EV_SET_ILLEGAL_CODE_LIST_ACK				6207

/*��ȡΥ���ֵ�����,��Ϣ����Ϊ��*/
#define EV_GET_ILLEGAL_CODE_LIST_REQ				6208
/*��ȡΥ���ֵ���Ӧ����Ϣ����TIPC_IllegalDict*/
#define EV_GET_ILLEGAL_CODE_LIST_ACK				6209

/*��������Ϣ����֪ͨ ���->�ͻ���*/
#define EV_IPC_FLOWINFO_REQ                         6210    //u32 dwSceneId (ask nty only client)
/*������ͳ����Ϣ֪ͨ ���->�ͻ���/����ƽ̨*/
#define EV_IPC_FLOWSTAT_REQ                         6211    //u32 dwSceneId(ask nty only client)
#define EV_IPC_FLOWSTAT_NTY                         6212    //TIPC_VehFlowStatInfoNty

/************************ͨ����Ϣ����***********************/
/*����*/
#define EV_COMM_HEARTBEAT                           10000
/*ʵʱ������Ϣ*/
#define EV_COMM_RT_VEHICLE_INFO                     10001
/*��ʷ������Ϣ*/
#define EV_COMM_HISTORY_VEHICLE_INFO                10002
/*��ȡ״̬��Ϣ*/
#define EV_COMM_STATUS_INFO                         10003
/*������ʷ��������*/
#define EV_COMM_START_SEND_HISTORY_DATA             10004
/*ֹͣ������ʷ��������*/
#define EV_COMM_STOP_SEND_HISTORY_DATA              10005
/*��ʷ�����ϴ����֪ͨ*/
#define EV_COMM_UPLOAD_FINISHED_NTY                 10006
/*���Ϳ�ʼ�ɼ���Ƶ��������
������TVideoCapture
*/
#define EV_COMM_START_CAPTURE_VIDEO                 10007
/*����ֹͣ�ɼ���Ƶ��������
������TVideoCapture
*/
#define EV_COMM_STOP_CAPTURE_VIDEO                  10008
/*ʵʱ��Ƶ����
������
*/
#define EV_COMM_REAL_TIME_VIDEO                     10009
/*�������������豸����
������
*/
#define EV_COMM_DEV_DISCOVERY_REQ                   10010
/*�������������豸��Ӧ
������
*/
#define EV_COMM_DEV_DISCOVERY_ACK                   10011
/*ǰ������ע������
������TLoginReq
*/
#define EV_COMM_REGISTER_REQ                        10012
/*ǰ������ע����Ӧ
������TLoginRsp
*/
#define EV_COMM_REGISTER_ACK                        10013
/*ǰ����������
������
*/
#define EV_COMM_DEV_REBOOT_CMD                      10014
/*ǰ��ʱ��ͬ������
������
*/
#define EV_COMM_TIME_SYNC_REQ                       10015
/*ǰ��ʱ��ͬ����Ӧ
������
*/
#define EV_COMM_TIME_SYNC_ACK                       10016
/*ǰ�˹����ϱ�
������
*/
#define EV_COMM_DEV_BREAKDOWN_NTY                   10017
/*��ͨ������Ϣ�ϱ�
������
*/
#define EV_COMM_TRAFFIC_CFG_NTY                     10018
/*ǰ����������
������
*/
#define EV_COMM_DEV_OFFLINE_REQ                     10019
/*ǰ��������Ӧ
������
*/
#define EV_COMM_DEV_OFFLINE_ACK                     10020
/*ǰ�˶���֪ͨ
������u32 dwPeerIp�Զ�IP��ַ+ u16 wPort
*/
#define EV_COMM_PEER_DISCONNECT_NTY                 10021
/*��ȡǰ���豸��������
������achDevId
*/
#define EV_COMM_GET_DEV_CFG_REQ                     10022
/*��ȡǰ���豸����Ӧ��
������TCfgInfo
*/
#define EV_COMM_GET_DEV_CFG_ACK                     10023
/*����ǰ���豸��������
������TCfgInfo
*/
#define EV_COMM_SET_DEV_CFG_REQ                     10024
/*����ǰ���豸����Ӧ��
������achDevId(64)+retcode(u16)
*/
#define EV_COMM_SET_DEV_CFG_ACK                     10025
/*��������
������
*/
#define EV_COMM_ARRAGEMENT_REQ                      10026
/*������Ӧ
������
*/
#define EV_COMM_ARRAGEMENT_ACK                      10027
/*��������
������
*/
#define EV_COMM_REMOVE_ARRAGEMENT_REQ               10028
/*������Ӧ
������
*/
#define EV_COMM_REMOVE_ARRAGEMENT_ACK               10029
/*��ȡ�����б�����
������
*/
#define EV_COMM_GET_BAY0NET_LIST_REQ                10030
/*��ȡ�����б���Ӧ
������
*/
#define EV_COMM_GET_BAY0NET_LIST_ACK                10031
/*��ѯ�豸����״̬����
������
*/
#define EV_COMM_GET_DEV_STATE_REQ                   10032
/*��ѯ�豸����״̬��Ӧ
������
*/
#define EV_COMM_GET_DEV_STATE_ACK                   10033
/*���������ϱ�
������
*/
#define EV_COMM_ALARM_DATA_NTY                      10034
/*���Ŀ�������
������
*/
#define EV_COMM_SUBSCRIBE_CMD                       10035
/*ȡ�����Ŀ�������
������
*/
#define EV_COMM_SUBSCRIBE_CANCLE_CMD                10036
/*����ͨ����Ϣ����*/
#define EV_COMM_SEND_COMMON_REQ                     10037
/*����ͨ����Ϣ��Ӧ*/
#define EV_COMM_SEND_COMMON_ACK                     10038
/*�½�����֪ͨ*/
#define EV_COMM_NEW_CONNECT_NTY                     10039
/*��λ״̬��Ϣ*/
#define EV_COMM_PARKING_STATUS                      10040
/*Ӧ�����ָ��*/
#define EV_COMM_REC_ACK_CTRL                        10041
/*����ָ��*/
#define EV_COMM_CONTROL_CMD                         10042
/*Ӧ�������Ϣ*/
#define EV_COMM_REC_RECD_INFO_ACK                   10043
/*�ͻ������ý��յ�ת����������(ͬƽ̨������������)*/
#define EV_COMM_SET_POST_DATA_TYPE_CMD              10044
/*ǰ�˶���֪ͨ
������u32 dwPeerIp�Զ�IP��ַ+ u16 wPort
*/
#define EV_PEER_DISCONNECT_NTY                      10045
/*���չ������ݷ������
������TIPC_VechileDataAck
*/
#define EV_COMM_VEHICLE_INFO_DATA_ACK               10046

/*----------------------------------------------------------
 *ͨ�ó��ȶ���
 *----------------------------------------------------------*/
 /*�豸�ַ���*/
#define MAX_SIZE_DEV_ID          64
/*�û����ַ���*/
#define MAX_SIZE_USRNAME         32
/*�����ַ���*/
#define MAX_SIZE_PASSWORD        32
/*IP��ַ�ַ���*/
#define MAX_SIZE_STR_IPADDR      32
/*��Ʒ�ͺ��ַ���*/
#define MAX_SIZE_PRODUCT         32
/*�����ַ���*/
#define MAX_SIZE_VENDER          32
/*���ڱ���ַ���*/
#define MAX_SIZE_POINT_NUM       64
/*������ʻ�����ַ���*/
#define MAX_SIZE_DIRECTION       32
/*���ƺ����ַ���*/
#define MAX_SIZE_PLATE_NUM       16
/*Υ�����¼������ַ���*/
#define MAX_SIZE_ILLEGAL_TYPE    64
/*ͼƬ����*/
#define MAX_NUM_IMAGE            8
/*�û����ַ���*/
#define MAX_SIZE_LEN8            8

#define MAX_SIZE_LEN16           16

#define MAX_SIZE_LEN32           32

#define MAX_SIZE_LEN64           64

#define MAX_SIZE_LEN512          512

#define MAX_SIZE_PATH_LEN        256

#define MAX_NUM_AUX_CAMERA       3

#define MAX_NUM_SERVER           4

#define MAX_NUM_DEVICE           8

#define MAX_NUM_PER_PAGE         50

#define MAX_CLIENT_LINK_NUM      4

#define MAX_PLAT_LINK_NUM        4
/*ͼƬ�ϳ��������*/
#define MAX_MERGE_PIC_NUM        8
/*ͼƬ�ϳɲ�����󲼾���*/
#define MAX_MERGE_LAYOUT_NUM     4
/*���ͼƬ�ϳɲ�����*/
#define MAX_PIC_MERGE_NUM        5
/*���osd������*/
#define MAX_OSD_TYPE_COUNT       22
/*���OSD������(����)*/
#define MAX_OSD_OVERLAY_COUNT    10

/*���֧��8·�������*/
#define MAX_CAMERA_LINK_NUM      8
/*���͸����Ϣ����*/
#define MAX_TRAN_DATA_NUM        1024
/*ע��ƽ̨��puid*/
#define  MAX_SIZE_PUID           64
/*���ڿ���Э����󳤶�*/
#define MAX_CON_PROT_DATA        256
/*���֧�ֵ�Υ����Ƶ����*/
#define MAX_NUM_VIDEOR_INFO      1
/*Υ����Ƶʱ��*/
#define MAX_LEN_VIDEOR_TIME      24
/*Υ����Ƶȫ·��*/
#define MAX_LEN_VIDEOR_URL       1024
/*�ֵ����*/
#define MAX_ILLEGAL_NUM          36
/*��������*/
#define MAX_SCENE_NUM            4

/************************IPC V7����***********************/
/*����߼�������*/
#define LOGIC_ROAD_NUM_MAX                  32
/*�����߼���������������������������*/
#define MAX_DECT_LABEL_NUM                  4
/*������*/
#define ROAD_NUM_MAX                        4
/*����*/
#define SCENE_NUM_SUPPORT_MAX               4
/*�������: ָ��̬�����µ�Υͣ���*/
#define VEH_DET_ROI_NUM_MAX                 4
/*��������������󶨵����*/
#define ROI_AREA_POINT_MAX                  8
#define VEH_DET_NUM_MAX                     32

/*��Ȧ�������ʼ��š�������*/
#define COIL_LOOP_START_LABEL               1
#define COIL_LOOP_CHANNEL_MAX               16
/*�״�������ʼ��š�������*/
#define RADAR_LOOP_START_LABEL              (COIL_LOOP_START_LABEL+COIL_LOOP_CHANNEL_MAX)
#define RADAR_NUM_MAX                       4
/*��Ƶ�������ʼ��š�������*/
#define VIDEO_LOOP_START_LABEL              32
#define VIDEO_LOOP_NUM_MAX                  24
/*����Ƽ����ͨ������*/
#define MAX_REDLAMP_DET_NUM                 8

/*��󴮿���*/
#define MAX_SERIAL_NUM                      3
/*������*/
#define MAX_SERIAL_NAME_LEN                 32

/**/
#define MAX_NUM_SNAPTIMING			        7
/**/
#define MAX_NUM_DECT_TIME					4
/*��������������������*/
#define RETENTION_NUM_MAX                   2
/**/
#define MAX_NUM_SCENEPOLL					8


/*�̶����������*/
#define FIX_RULE_LINE_START_LABEL           64
#define FIX_RULE_LINE_NUM_MAX               16
/*��������߱��*/
#define ROAD_LINE_LEFT_LABEL                (FIX_RULE_LINE_START_LABEL+0)
/*�����ұ��߱��*/
#define ROAD_LINE_RIGHT_LABEL               (FIX_RULE_LINE_START_LABEL+1)
/*����12�ָ��߱��*/
#define ROAD_LINE_12_LABEL                  (FIX_RULE_LINE_START_LABEL+2)
/*����23�ָ��߱��*/
#define ROAD_LINE_23_LABEL                  (FIX_RULE_LINE_START_LABEL+3)
/*����34�ָ��߱��*/
#define ROAD_LINE_34_LABEL                  (FIX_RULE_LINE_START_LABEL+4)
/*����߱��*/
#define SCAN_LINE_LABEL                     (FIX_RULE_LINE_START_LABEL+5)
/*��ת�ж��߱��*/
#define TURN_LEFT_LINE_LABEL                (FIX_RULE_LINE_START_LABEL+6)
/*ֱ���ж��߱��*/
#define STRAIGHT_LINE_LABEL                 (FIX_RULE_LINE_START_LABEL+7)
/*��ת�ж��߱��*/
#define TURN_RIGHT_LINE_LABEL               (FIX_RULE_LINE_START_LABEL+8)
/*����1ͣ���߱��*/
#define STOP_LINE_1_LABEL                   (FIX_RULE_LINE_START_LABEL+9)
/*����2ͣ���߱��*/
#define STOP_LINE_2_LABEL                   (FIX_RULE_LINE_START_LABEL+10)
/*����3ͣ���߱��*/
#define STOP_LINE_3_LABEL                   (FIX_RULE_LINE_START_LABEL+11)
/*����4ͣ���߱��*/
#define STOP_LINE_4_LABEL                   (FIX_RULE_LINE_START_LABEL+12)

/*�Զ�������߱�š�������*/
#define USER_RULE_LINE_START_LABEL          (FIX_RULE_LINE_START_LABEL+FIX_RULE_LINE_NUM_MAX)
#define USER_RULE_LINE_NUM_MAX               16

/*��Ƶ��⡢��Ȧ��⡢�״��⡢��Ƶ���+�״����*/
#define DETECT_MODE_VIDEO                    (0x0001<<1)
#define DETECT_MODE_COIL                     (0x0001<<2)
#define DETECT_MODE_RADAR                    (0x0001<<3)
#define DETECT_MODE_VIDEO_RADAR              ((0x0001<<4)|(0x0001<<1))

////////////////////////////�����ⷽ��/////////////////////////////////////
/*�˶����*/
#define DETECT_METHOD_GRAY                   0
/*���Ƽ��*/
#define DETECT_METHOD_PLATE                  1
/*β�Ƽ��*/
#define DETECT_METHOD_TAILLAMP               2
/*ͷ�Ƽ��*/
#define DETECT_METHOD_HEADLAMP               3
/*���˶����*/
#define DETECT_METHOD_GRAY_SIMPLE            4
/*��Ƽ��*/
#define DETECT_METHOD_REDLAMP                5
/*���������*/
#define DETECT_METHOD_COIL                   6
/*�״�����*/
#define DETECT_METHOD_RADAR                  7
/*�ⲿ����*/
#define DETECT_METHOD_EXTERNAL               8
/*IO�źż��*/
#define DETECT_METHOD_IO                     9
/*�������*/
#define DETECT_METHOD_RETENTION              10
/*��Ч���*/
#define DETECT_METHOD_INVALID                255
/*����: 1--��ͷ��2--��β��4--��ת��8--ֱ�С�16--��ת*/
#define DETECT_HEAD_VIEW                     (0x1<<0)
#define DETECT_TAIL_VIEW                     (0x1<<1)
/*�����λ: ��ת*/
#define REDLAMP_PHASE_TURNRIGHT               (0x1<<2)
/*�����λ: ֱ��*/
#define REDLAMP_PHASE_STRA_AHEAD              (0x1<<3)
/*�����λ: ��ת*/
#define REDLAMP_PHASE_TURNLEFT               (0x1<<4)

/*��ʻ����: 1--������ʻ��2--ȥ����ʻ��3--˫�����*/
#define MOVE_DIR_LX                          0x1
#define MOVE_DIR_QX                          0x2
#define MOVE_DIR_SX                          0x3

/*�������Զ���: */
/*������ר�ó���*/
#define BUS_LANE                             (1<<4)
/*���ת����*/
#define TURN_LEFT_WAIT                       (1<<3)
/*������ת*/
#define TURN_LEFT                            (1<<2)
/*����ֱ��*/
#define GO_STRAGIHT                          (1<<1)
/*������ת*/
#define TURN_RIGHT                           (1<<0)

/*���ƽǶ�(1: ���ż�(C��); 2: A�ˣ�������������; 3: A�ˣ�������������; 4: �Ƕȷ��򲻶�)*/
#define PLATE_ANGLE_C                        0x01
#define PLATE_ANGLE_A_R                      0x02
#define PLATE_ANGLE_A_L                      0X03
#define PLATE_ANGLE_UN                       0x04
/*5: A�ˣ����������������ػ���*/
#define PLATE_ANGLE_A_R_R                    0x05
#define PLATE_ANGLE_A_L_L                    0x06
#define PLATE_ANGLE_A_UN_UN                  0x07

////////////////�߼��������� &&  ץ������////////////////////////////////////////////
/*����*/
#define LOGIC_ROAD_TYPE_KK                  (0x0001<<0)
/*����*/
#define LOGIC_ROAD_TYPE_CS                  (0x0001<<1)
/*����: ��ʱץ���߼�(��ͷ���ڳ���)*/
#define LOGIC_ROAD_TYPE_NX                  (0x0001<<2)
/*��ռ��*/
#define LOGIC_ROAD_TYPE_ZD                  (0x0001<<3)
/*��ռ��&ռ��Ӧ������*/
#define LOGIC_ROAD_TYPE_YJ                  (0x0001<<4)
/*ѹ��: ��ʱץ���߼�(��ͷ���ڳ���)*/
#define LOGIC_ROAD_TYPE_YX                  (0x0001<<5)
/*ʵ�߱��*/
#define LOGIC_ROAD_TYPE_BD                  (0x0001<<6)
/*ռ�ù�������*/
#define LOGIC_ROAD_TYPE_GJ                  (0x0001<<7)
/*�����*/
#define LOGIC_ROAD_TYPE_HD                  (0x0001<<8)
/*��������*/
#define LOGIC_ROAD_TYPE_DX                  (0x0001<<9)
/*��ֹ��ת*/
#define LOGIC_ROAD_TYPE_JZ                  (0x0001<<10)
/*Υ��ͣ��*/
#define LOGIC_ROAD_TYPE_WT                  (0x0001<<11)
/*����: ��Ƶ�����߼�(��β�羯����)*/
#define LOGIC_ROAD_TYPE_NX_2                (0x0001<<12)
/*ѹ��: ��Ƶ�����߼�(��β�羯����)*/
#define LOGIC_ROAD_TYPE_YX_2                (0x0001<<13)

////////////////////////���ⷽʽ////////////////////////////////////////
/*����Ʋ���ģʽ*/
#define FLASH_LIGHT_MODE                    (0x0001<<0)
/*LED�Ʋ���ģʽ*/
#define LED_LIGHT_MODE                      (0x0001<<1)
/*�޲��⣬��Ƶ����ͼģʽ*/
#define NONE_LIGHT_MODE                     (0x0000)
/*������*/
#define FLASH_LIGHT_NIGHT_MODE_1            (0x0000)
/*������*/
#define FLASH_LIGHT_NIGHT_MODE_2            (0x0001)

/*��Դͬ�� ��λ��������*/
#define MAX_PHASE_NUM                       8

////////////////////////ͼƬ����////////////////////////////////////////
/*�ֶ��ع�*/
#define KISP_2A_AE_MANU                     (0x1<<0)
/*�Զ��ع�*/
#define KISP_2A_AE_AUTO_1                   (0x1<<1)
/*ISP����AE*/
#define KISP_2A_AE_AUTO_2                   (0x1<<2)
/*����*/
#define KISP_2A_AE_HOLD                     (0x1<<3)
/*Invalid*/
#define KISP_2A_AE_INVALID                  (0x1<<4)

/*�ֶ�*/
#define KISP_2A_AWB_MANU                    (0x1<<0)
/*�Զ���ƽ��*/
#define KISP_2A_AWB_AUTO_1                  (0x1<<1)
/*ISP����AWB*/
#define KISP_2A_AWB_AUTO_2                  (0x1<<2)
/*����: */
#define KISP_2A_AWB_HOLD                    (0x1<<3)
/*Invalid*/
#define KISP_2A_AWB_INVALID                 (0x1<<4)

/*LED���Զ�����: �Զ�*/
#define KISP_LED_AUTO                       (0x1<<0)
/*LED�ƿ���*/
#define KISP_LED_ON                         (0x1<<1)
/*LED�ƹر�*/
#define KISP_LED_OFF                        (0x1<<2)
/*UnKnown*/
#define KISP_LED_UNKNOWN                    (0x1<<3)

/*PLƫ�⾵����: �Զ�*/
#define KISP_PL_AUTO                        (0x1<<0)
/*PL����*/
#define KISP_PL_ON                          (0x1<<1)
/*PL�ر�*/
#define KISP_PL_OFF                         (0x1<<2)
/*Unknown*/
#define KISP_PL_UNKNOWN                     (0x1<<3)

/*Υ�������*/
#define MAX_NUM_ILLEGAL_TYPE				32


////////////////////////////������ͼ��/////////////////////////////////////
/*�ַ�����ĳ���*/
#define STRING_MAX_LENGTH_128  				129
/*�ַ�����ĳ���*/
#define STRING_MAX_LENGTH_256  				257
/*�ַ�����ĳ���*/
#define STRING_MAX_LENGTH_100  				101
/*�ַ�����ĳ���*/
#define STRING_MAX_LENGTH_1024  			1024
/*�豸ID�ı��볤��*/
#define STRING_LENGTH_DEVID  				20

////////////////////////////����ƽ̨/////////////////////////////////////
/*���ڱ����ĳ���*/
#define YJ_MAX_LEN_BAYNOTID					12
/*���ڱ����ĳ���*/
#define YJ_MAX_LEN_DIRECTION				2

/*---------------------------------------------------------
 *ö��      (ͨ��ö��   +   Э��ö��   +  ҵ��ö��)
 *---------------------------------------------------------*/
/**************************ͨ��ö��************************/

/*�������ͱ���*/
typedef enum
{
    /*δʶ��*/
    VEHICLE_TYPE_UNKNOWN    = 50000,
    /*С�ͳ�*/
    VEHICLE_TYPE_SMALL_SIZE = 50001,
    /*���ͳ�*/
    VEHICLE_TYPE_BIG_SIZE   = 50002,
    /*���ͳ�*/
    VEHICLE_TYPE_MID_SIZE   = 50003,
    /*Ħ�г�*/
    VEHICLE_TYPE_MOTOR      = 50004,
    /*����*/
    VEHICLE_TYPE_PEOPLE     = 50005,
    /*�ǻ�����*/
    VEHICLE_TYPE_NON_MOTOR  = 50006,
    /*�γ�*/
    VEHICLE_TYPE_JC         = 50007,
    /*�����*/
    VEHICLE_TYPE_MBC        = 50008,
    /*�ͳ�*/
    VEHICLE_TYPE_KC         = 50009,
    /*С����*/
    VEHICLE_TYPE_XHC        = 50010,
    /*�����*/
    VEHICLE_TYPE_DHC        = 50011,
}EVehicleType;

/*������ɫ*/
typedef enum
{
    /*δʶ��*/
    PLATE_COLOR_UNKNOWN = 40000,
    /*��*/
    PLATE_COLOR_BLACK   = 40001,
    /*��*/
    PLATE_COLOR_BLUE    = 40002,
    /*��*/
    PLATE_COLOR_WHITE   = 40003,
    /*��*/
    PLATE_COLOR_YELLOW  = 40004,
    /*��*/
    PLATE_COLOR_GREEN   = 40005,
	/*����*/
    PLATE_COLOR_YELLOW_GREEN   = 40006
}EPlateColor;

/*������ɫ����*/
typedef enum
{
    /*A��*/
    VEHICLE_COLOR_WHITE     = 0x41,
    /*��*/
    VEHICLE_COLOR_GRAY      = 0x42,
    /*C��*/
    VEHICLE_COLOR_YELLOW    = 0x43,
    /*D��*/
    VEHICLE_COLOR_PINK      = 0x44,
    /*E��*/
    VEHICLE_COLOR_RED       = 0x45,
    /*F��*/
    VEHICLE_COLOR_purple    = 0x46,
    /*G��*/
    VEHICLE_COLOR_GREEN     = 0x47,
    /*H��*/
    VEHICLE_COLOR_BLUE      = 0x48,
    /*I��*/
    VEHICLE_COLOR_BROWN     = 0x49,
    /*J��*/
    VEHICLE_COLOR_BLACK     = 0x4A,
	/*K��*/
	VEHICLE_COLOR_ORANGE         = 0x4B,
	/*L��*/
	VEHICLE_COLOR_INDIGO         = 0x4C,
	/*M��*/
	VEHICLE_COLOR_SILVERY        = 0x4D,
	/*N����*/
	VEHICLE_COLOR_SILVERY_WHITE  = 0x4E,
    /*Z����*/
    VEHICLE_COLOR_OTHER     = 0x5A
}EVehicleColor;

/*Υ�����ͱ��붨�����£�*/
typedef enum
{
    /*����*/
    ILLEGAL_TYPE_OVER_SPEED         = 10001,
    /*����*/
    ILLEGAL_TYPE_RETROGRADE         = 10002,
    /*�����*/
    ILLEGAL_TYPE_THROUGHT_RED_RIGHT = 10003,
    /*ѹ����*/
    ILLEGAL_TYPE_OVER_YELLOW_LINE   = 10004,
    /*����������ʻ*/
    ILLEGAL_TYPE_NOT_CORRECT_LANE   = 10005,
    /*���䳬��*/
    ILLEGAL_TYPE_OVER_LINE          = 10006,
    /*ѹʵ�� */
    ILLEGAL_TYPE_SOLIDLINE          = 10007,
    /*Υ��ͣ��*/
    ILLEGAL_TYPE_STOP               = 10008,
    /*�޳��ƣ����ڸ��ٿ�����Ŀ*/
    ILLEGAL_TYPE_NOPLATE            = 10009,
    /*������ */
    ILLEGAL_TYPE_BAN_VIOLATION      = 10010,
	/* Υ����ͨ�����־*/
    ILLEGAL_TYPE_TRAFFIC_SIGNS      = 10011,
	/* Խ��ͣ��*/
    ILLEGAL_TYPE_LINE_STOP          = 10012,
	/* ռ��ר�ó���*/
    ILLEGAL_TYPE_OCCU_LANE          = 10013,
	/*Υ����ͷ */
    ILLEGAL_TYPE_ILLEGA_TURN        = 10014,
	/* ������ռ��*/
    ILLEGAL_TYPE_MOTOR_LANE         = 10015,
	/*ʵ�߱�� */
    ILLEGAL_TYPE_SOLID_LINE         = 10016,
	/*ѹ����ʻ */
    ILLEGAL_TYPE_LINE_DRIVE         = 10017,
	/*����δϵ��ȫ�� */
    ILLEGAL_TYPE_SAFETY_BELT        = 10018,
	/*����δϵ��ȫ�� */
    ILLEGAL_TYPE_SEC_SAFETY_BELT    = 10019,
	/*���ݿ�����绰 */
    ILLEGAL_TYPE_MAKE_PHONE         = 10020,
	/*�����������涨��ʻ */
    ILLEGAL_TYPE_MUCK_CARS          = 10021,
	/*Υ��ͣ������֪ͨ */
    ILLEGAL_TYPE_STOP_MESSAGE       = 10022,

}EIllegalType;

/*��������*/
typedef enum
{
	/*������������*/      
	PLATE_TYPE_BIG_CAR				=1,
	/*С����������*/      
	PLATE_TYPE_SMALL_CAR			=2,
	/*ʹ����������*/      
	PLATE_TYPE_EMBASSY_CAR			=3,
	/*�����������*/      
	PLATE_TYPE_CONSULATE_CAR		=4,
	/*������������*/      
	PLATE_TYPE_ABOARD				=5,
	/*�⼮��������*/      
	PLATE_TYPE_FOREIGN				=6,
	/*��������Ħ�г�����*/    
	PLATE_TYPE_MOTORCYCLE			=7,
	/*���Ħ�г�����*/    
	PLATE_TYPE_SMALL_MOTORCYCLE		=8,
	/*ʹ��Ħ�г�����*/    
	PLATE_TYPE_EMBASSY_MOTOR		=9,
	/*���Ħ�г�����*/    
	PLATE_TYPE_CONSULATE_MOTOR		=10,
	/*����Ħ�г�����*/    
	PLATE_TYPE_ABOARD_MOTOR			=11,
	/*�⼮Ħ�г�����*/    
	PLATE_TYPE_FOREIGN_MOTOR		=12,
	/*ũ�����䳵����*/    
	PLATE_TYPE_FARMING				=13,
	/*����������*/        
	PLATE_TYPE_TRACTOR				=14,
	/*�ҳ�����*/          
	PLATE_TYPE_TRAILER				=15,
	/*������������*/      
	PLATE_TYPE_COACH				=16,
	/*����Ħ�г�����*/    
	PLATE_TYPE_COACH_MOTOR			=17,
	/*ʵ����������*/      
	PLATE_TYPE_EXPER				=18,
	/*ʵ��Ħ�г�����*/    
	PLATE_TYPE_EXPER_MOTOR			=19,
	/*��ʱ�뾳��������*/  
	PLATE_TYPE_ENTRY				=20,
	/*��ʱ�뾳Ħ�г�����*/
	PLATE_TYPE_ENTRY_MOTOR			=21,
	/*��ʱ��ʻ������*/    
	PLATE_TYPE_ENTRY_DRIVING		=22,
	/*������������*/      
	PLATE_TYPE_POLICE				=23,
	/*����Ħ�г�����*/    
	PLATE_TYPE_POLICE_MOTOR			=24,
	/*��������*/          
	PLATE_TYPE_OTHER				=99,

}EPlateType;

typedef enum
{
	/*ǰ���豸*/
    DEVICE_TYPE_FRONT_DEV   = 0,
	/*���������*/
    DEVICE_TYPE_CLIENT      = 1,
	/*�ͻ��˽���*/
	DEVICE_TYPE_UI			= 2,
	/*����*/
    DEVICE_TYPE_NUKOWN
}EDeviceType;

typedef enum
{
	ENUM_LINK_TYPE_SERVER         = 1,
	ENUM_LINK_TYPE_CLIENT         = 2,
}EIVHSLINKTYPE;

/*ͼƬ����*/
typedef enum
{
    /*��ͷ����ȫ��ͼ*/
    VEH_IMAGE_TYPE_FRONT_PANORAMA = 2,
    /*��ͷ���ƺ���СͼƬ*/
    VEH_IMAGE_TYPE_FRONT_PLANTE   = 3,
    /*��β����ȫ��ͼ*/
    VEH_IMAGE_TYPE_BACK_PANORAMA  = 5,
    /*��β���ƺ���СͼƬ*/
    VEH_IMAGE_TYPE_BACK_PLANTE    = 6,
    /*����СͼƬ*/
    VEH_IMAGE_TYPE_FACE           = 7,
    /*Υ��ͼƬ*/
    VEH_IMAGE_TYPE_ILLEGAL        = 11,
    /*�¼�ͼƬ*/
    VEH_IMAGE_TYPE_EVENT          = 12,
    /*������дͼƬ*/
    VEH_IMAGE_TYPE_VEHICLE        = 13,
    /*�ϳ�ͼƬ*/
    VEH_IMAGE_TYPE_MONTAGE        = 128,
    /*����ͼƬ*/
    VEH_IMAGE_TYPE_MJPEG_DEBUG    = 255
}EImageType;

/*�ϴ���������(ƽ̨�ϴ�)*/
typedef enum
{
    EM_DATA_TYPE_KAKOU_ORIGINAL_PIC     = 0x0001,   //����ԭͼ
    EM_DATA_TYPE_KAKOU_MERGE_PIC        = 0x0002,   //���ںϳ�ͼƬ
    EM_DATA_TYPE_ILLEGAL_ORIGINAL_PIC   = 0x0004,   //Υ��ԭͼ
    EM_DATA_TYPE_ILLEGAL_MERGE_PIC      = 0x0008,   //Υ���ϳ�ͼƬ
    EM_DATA_TYPE_FACE_FEATURE           = 0x0010,   //������д
    EM_DATA_TYPE_VEHICLE_FEATURE        = 0x0020,   //������д
    EM_DATA_TYPE_PLATE_FEATURE          = 0x0040,   //������д
    EM_DATA_TYPE_ILLEGAL_VIDEO          = 0x0080,   //Υ��¼��
    EM_DATA_TYPE_VEHICLE_INFO           = 0x0100,   //������Ϣ
    EM_DATA_TYPE_NUKOWN
}EITS_DATA_TYPE;


/*��������*/
typedef enum
{
	/*δʶ��*/
	EM_VEHICLE_CLASS_UNKWON			= 150000,
	/*����*/
	EM_VEHICLE_CLASS_CAR			= 150001,
	/*�ҳ�*/
	EM_VEHICLE_CLASS_TRAILER		= 150002,
	/*Ħ�г�*/
	EM_VEHICLE_CLASS_MOTOR			= 150003,

}EVehicleClass;


/*���������Ͷ���*/
typedef enum
{
	/*δʶ��*/
	EM_VEHICLE_SUB_CLASS_UNKWON			    = 160000,
	/*�γ�*/
	EM_VEHICLE_SUB_CLASS_CAR		        = 160001,
	/*�ͳ�*/
	EM_VEHICLE_SUB_CLASS_BUS		        = 150002,
	/*�����*/
	EM_VEHICLE_SUB_CLASS_VAN			    = 150003,
	/*���ͻ���*/
	EM_VEHICLE_SUB_CLASS_HEAVY_TRUCK		= 160004,
	/*��΢�ͻ���*/
	EM_VEHICLE_SUB_CLASS_LIGHT_TRUCK		= 150005,
	/*���Ϳͳ�*/
	EM_VEHICLE_SUB_CLASS_MEDIUM_BUS			= 150006,
	/*SUV_MPV*/
	EM_VEHICLE_SUB_CLASS_SUV_MPV			= 160007,

}EVehicleSubClass;

/**************************Э��ö��************************/
typedef enum
{
    FUNCTION_SUPPORT_TYPE_CLIENT        = 0x0001,   //�ͻ���
    FUNCTION_SUPPORT_TYPE_WEBSERVICE    = 0x0002,   //�ͻ���webserivce
    FUNCTION_SUPPORT_TYPE_HTTP          = 0x0004,   //�ͻ���HTTP
    FUNCTION_SUPPORT_TYPE_FTP           = 0x0008,   //�ͻ���FTP
    FUNCTION_SUPPORT_TYPE_IPC_ACCESS    = 0x0010,   //ipc����
    FUNCTION_SUPPORT_TYPE_PIC           = 0x0020,   //ͼƬת��
    FUNCTION_SUPPORT_TYPE_NULL
}EFUNCTION_SUPPORT;

typedef enum
{
    /*����״̬*/
    LINK_STATE_NONE             = 0,
    /*���ڽ���״̬ */
    LINK_STATE_CONNECTING       = 1,
    /*�Ѿ�����״̬*/
    LINK_STATE_CONNECTED        = 2,
    /*����ע��״̬*/
    LINK_STATE_REGISTRERING     = 3,
    /*�Ự״̬*/
    LINK_STATE_SSN              = 4,
    /*��ͣ����*/
    LINK_STATE_SUSPEND          = 5,
    /*�ر�״̬*/
    LINK_STATE_CLOSE            = 6,
}ELinkState;

enum PROTOCOL_COMM_TYPE
{
    PROTOCOL_TYPE_KEDA      = 1,            //���ݿƴ�ģʽ
    PROTOCOL_TYPE_YUSHI     = 2,            //����ģʽ
    PROTOCOL_TYPE_FTP       = 3,            //FTP
	PROTOCOL_TYPE_HAIKANG   = 4,            //����ģʽ
	PROTOCOL_TYPE_FENGHUO   = 5,            //���ģʽ
	PROTOCOL_TYPE_VID_IMG	= 6,            //������ͼ��,��Ƶͼ����Ϣģʽ
	PROTOCOL_TYPE_YINJIANG	= 7,            //����ƽ̨
	PROTOCOL_TYPE_BENNENG	= 8,            //����ƽ̨
	PROTOCOL_TYPE_TIANWANG	= 9,            //��������ƽ̨
	PROTOCOL_TYPE_HISENSER	= 10,           //����ƽ̨
    PROTOCOL_TYPE_NONE      = 55            //����Ϊ��	
};

enum HISDATA_TRANS_MODE
{
	HISDATA_TRANS_ALWAYS = 0,
	HISDATA_TRANS_ASK	= 1,
	HISDATA_TRANS_NO = 2,
};

/**************************ҵ��ö�٣�ITSͼƬ����************************/
// osd ����
enum emOSDType
{
    EM_OSD_TYPE_ALL,        //ȫ���¼�
    EM_OSD_TYPE_PLATE,      //����
    EM_OSD_TYPE_PLATECOLOR, //������ɫ
    EM_OSD_TYPE_BODYCOLOR,  //������ɫ
    EM_OSD_TYPE_BRAND,      //����
    EM_OSD_TYPE_DATETIME,   //ʱ��
    EM_OSD_TYPE_MS,         //����
    EM_OSD_TYPE_SCENE,      //�ص�
};

enum ENUM_MERGE_TYPE
{
    enum_merge_type_none        =0,
    enum_merge_type_twoinone,
    enum_merge_type_threeinone,
    enum_merge_type_fourinone,
    enum_merge_type_fiveinone,
    enum_merge_type_sixinone,
    enum_merge_type_sixintwo,
};

enum ENUM_IMAGE_SOURCE_TYPE
{
    enum_image_source_none = 0,
    enum_image_source_panorama,    //ȫ��ͼƬ
    enum_image_source_feature,     //��дͼƬ
};

enum ENUM_FEATURE_POSITION
{
    enum_feature_pos_unkown = 0,
    enum_feature_pos_ul     = 1,
    enum_feature_pos_ur     = 2,
    enum_feature_pos_ll     = 3,
    enum_feature_pos_lr     = 4,
};

enum ENUM_IMAGE_SIZE
{
    enum_image_size_unkown   = 0,
    enum_image_size_original = 1,
    enum_image_size_half     = 2,
    enum_image_size_quarter  = 4,
};

enum ENUM_IMAGE_STORE_TYPE
{
    enum_image_store_type_rt    = 1,
    enum_image_store_type_local = 2,
};

/*************************ҵ��ö��:ITSƽ̨���������**********************/
enum PLATFORM_SERVER_TYPE
{
    enum_platform_type_kedacom = 1,
    enum_platform_type_shiyue  = 2,
    enum_platform_type_ftp     = 3,
};

enum CAMERA_TYPE
{
    enum_camera_kedacom = 1,
    enum_camera_ruishi  = 2,
};

enum CAMERA_MATCH_MODE_TYPE
{
    enum_match_mode_type_capture        = 1,    //ǰ��ץ��
    enum_match_mode_type_epolice        = 2,    //����羯
    enum_match_mode_type_illegal_uturn  = 3,    //Υ����ͷ
    enum_match_mode_type_speed_measure  = 4,    //�������
};

/*************************ҵ��ö��:ITS¼������***********************/
enum VIDEO_SECTION_TYPE
{
    enum_video_section_type_illegal     = 1,    //Υ����ȡ
    enum_video_section_type_unkown
};

/*************************ҵ��ö��:ITS��ѯ***************************/
enum VEHICLE_QUERY_TYPE
{
    VEHICLE_QUERY_TYPE_NULL         = 0x0,
    VEHICLE_QUERY_TYPE_START_TIME   = 0x0001,   //��ʼʱ��
    VEHICLE_QUERY_TYPE_STOP_TIME    = 0x0002,   //����ʱ��
    VEHICLE_QUERY_TYPE_TYPE         = 0x0004,   //��������
    VEHICLE_QUERY_TYPE_IPCNO        = 0x0008,   //������
    VEHICLE_QUERY_TYPE_PLATE        = 0x0010,   //����
    VEHICLE_QUERY_TYPE_STATE        = 0x0020,   //�ϴ�״̬
    VEHICLE_QUERY_TYPE_MIN_SPEED    = 0x0040,   //��С����
    VEHICLE_QUERY_TYPE_MAX_SPEED    = 0x0080,   //�����
    VEHICLE_QUERY_TYPE_ASC          = 0x0100,   //������
};

enum QUERY_DATA_TYPE
{
    enum_data_type_all_kakou = 1,
    enum_data_type_all_illegal,
    enum_data_type_run_red_light,
    enum_data_type_overspeed,
    enum_data_type_retrograde,
    enum_data_type_linedriving,
    enum_data_type_illegal_parking,
    enum_data_type_change_lanes,
    enum_data_type_illegal_prohibit,
    enum_data_type_occupancy_speciallane,
    enum_data_type_inconsistent_plate,
    enum_data_type_congestion,
    enum_data_type_vehicle_occupancy_lane,
    enum_data_type_run_green_light,
    enum_data_type_vehicle_uturn,
    enum_data_type_speed_detection,
};

enum QUERY_UPLOAD_STATE
{
    enum_query_upload_state_finish   = 1,
    enum_query_upload_state_unfinish = 2,
};

enum QUERY_SORT_TYPE
{
    enum_query_sort_time_asc    = 1,
    enum_query_sort_time_des    = 2,
    enum_query_sort_no_asc      = 3,
    enum_query_sort_no_des      = 4,
};
/*************************ҵ��ö��:ipc v7***********************/
/*�߼����� ץ��ģʽ*/
enum SNAP_CTRL_MODE
{
    enum_snap_ctrl_mode_by_time     = 1,
    enum_snap_ctrl_mode_by_distance = 2,
};

enum PTZ_EVENT_TYPE
{
    enum_ptz_event_type_preset      = 1,    //->p1
    enum_ptz_event_type_patrol      = 2,    //p1<-->p2
    enum_ptz_evnet_type_unkown
};

enum DRIVE_DIR_TYPE
{
    DRIVE_DIR_TYPE_LX                = 0x1,    //������ʻ
    DRIVE_DIR_TYPE_QX                = 0x2,    //ȥ����ʻ
    DRIVE_DIR_TYPE_SX                = 0x3,    //˫�����
    DRIVE_DIR_TYPE_UNKOWN
};

/*����ģʽ*/
enum E_STREAM_MODE
{
    ENUM_STREAM_MODE_JPEG   = 1,
    ENUM_STREAM_MODE_UNKOWN
};

/*����Э������*/
typedef enum
{
    /*�״�CSR-INЭ��*/
    E_RADAR_CSR_IN = 1,
    /*���̺�Ƴ���ģ��V2Э��*/
    E_HL_DET_MODULE_V2,
    /*�״�802-2DЭ��*/
    E_RADAR_802_2D,
    /*���̺�Ƴ���ģ��V1Э��*/
    E_HL_DET_MODULE_V1,
    /*���ӳ�����Э��*/
    E_UNIVIEW_DET_MODULE,
    /*��*/
    E_NONE = 255,
}ESerialProtocol;

typedef enum
{
    E_TRAFFIC_STATE_CLEAR   = 0,
    E_TRAFFIC_STATE_SLOW    = 1,
    E_TRAFFIC_STATE_BUSY    = 2,
}ETrafficState;

typedef enum
{
    /*������*/
    E_VEHFLOW_UPDATE_TYPE_NEVER     = 0,
    /*δ��ʱ���, ��λMM:HH:MM ��12:00:00*/
    E_VEHFLOW_UPDATE_TYPE_BY_POINT  = 1,
    /*ʱ������ �統ǰʱ��2:30��*/
    E_VEHFLOW_UPDATE_TYPE_BY_PERIOD = 2,
    /*�������� �ﵽ�涨����ֵ ��1000*/
    E_VEHFLOW_UPDATE_TYPE_BY_FLOWCNT= 3,
}EFlowUpdateType;

typedef enum
{
    E_UPDATE_PERIOD_TYPE_SEC   = 0,
    E_UPDATE_PERIOD_TYPE_MIN   = 1, 
    E_UPDATE_PERIOD_TYPE_HOUR  = 2,
    E_UPDATE_PERIOD_TYPE_DAY   = 3,
    E_UPDATE_PERIOD_TYPE_MONTH = 4,
    E_UPDATE_PERIOD_TYPE_YEAR  = 5,
    E_UPDATE_PERIOD_TYPE_COUNT
}EFlowPeriodType;

//UI����������
enum EMUI_CAP_TYPE
{
    EMUI_CAP_TYPE_SCENE = 0x0,      // �������� 0:��֧��, 1:ȫ��֧��; 
    EMUI_CAP_TYPE_DETECTION,        // ������� 0:��֧��, 1:ȫ��֧��; 
    EMUI_CAP_TYPE_LOGICLANE,        // �߼����� 0:��֧��, 1:ȫ��֧��; 
    EMUI_CAP_TYPE_IDENTPARAM,       // ʶ����� 0:��֧��, 1:ȫ��֧��; 
    EMUI_CAP_TYPE_VELOMETER,        // ��Ƶ���� 0:��֧��, 1:ȫ��֧��; 
    EMUI_CAP_TYPE_IMAGEQUALITY,     // ͼ��Ʒ�� 0:��֧��, 1:ȫ��֧��;2�������汾������ʾ�ع�ĺ��Ʋ�� 
    EMUI_CAP_TYPE_SYSPICMERGE,      // ͼƬ�ϳ� 0:��֧��, 1:ȫ��֧��; 
    EMUI_CAP_TYPE_OSD,              // OSD      0:��֧��, 1:ȫ��֧��; 
    EMUI_CAP_TYPE_REDLIGHT,         // ��Ʋ��� 0:��֧��, 1:ȫ��֧��; 
    EMUI_CAP_TYPE_POWERSYN,         // ��Դͬ�� 0:��֧��, 1:ȫ��֧��; 
    EMUI_CAP_TYPE_SERIAL,           // ������Ϣ 0:��֧��, 1:ȫ��֧��
    EMUI_CAP_TYPE_REGISTERPLAT,     // ע��ƽ̨ 0:��֧�֣�1:ȫ��֧��; 
	EMUI_CAP_TYPE_ILLGPARK,		    // Υͣ���� 0:��֧�֣�1:ȫ��֧��; 
	EMUI_CAP_TYPE_FLOWDET,			// ��Ƶ������� 0:��֧�֣�1:ȫ��֧��; 
    EMUI_CAP_TYPE_COUNT
};

typedef enum
{
    /*������*/
    E_LANE_DIR_TYPE_EAST2WEST           = 1,
    /*����*/
    E_LANE_DIR_TYPE_WEST2EAST           = 2,
    /*����*/
    E_LANE_DIR_TYPE_SOUTH2NORTH         = 3,
    /*������*/
    E_LANE_DIR_TYPE_NORTH2SOUTH         = 4,
    /*����������*/
    E_LANE_DIR_TYPE_SOUTHEAST2NORTHWEST = 5,
    /*��������*/
    E_LANE_DIR_TYPE_NORTHWEST2SOUTHEAST = 6,
    /*����������*/
    E_LANE_DIR_TYPE_NORTHEAST2SOUTHWEST = 7,
    /*�����򶫱�*/
    E_LANE_DIR_TYPE_SOUTHWEST2NORTHEAST = 8,
    /*����*/
    E_LANE_DIR_TYPE_OTHER,
}E_LANE_DIR_TYPE;


typedef enum
{
    /*����*/
    E_DEV_ERROR_NOTICE_NORMAL          = 1,
    /*�쳣*/
    E_DEV_ERROR_NOTICE_EXCEPT          = 2,
    /*δ֪*/
    E_DEV_ERROR_NOTICE_UNKNOW          = 3,
  
}E_DEV_ERROR_NOTICE;

typedef enum
{
    /*�����Ȧ״̬*/
    E_DEV_STATE_LOOP				= 80001,
    /*����ƹ���״̬*/
    E_DEV_STATE_LAMP				= 80002,
    /*�����¶�״̬*/
    E_DEV_STATE_TEMPERATURE         = 80003,
	/*������״̬*/
    E_DEV_STATE_CASE				= 80004,
    /*���ػ�����״̬*/
    E_DEV_STATE_ITS_WORKING         = 80005,
  
}E_DEV_STATE;

/*************************������ͼ��ö��***********************/

//ͼƬ�ɼ���ʽ
enum EInfoKind
{
	EN_INFO_KIND_OTHER		=0,  //����
	EN_INFO_KIND_AUTOMATIC	=1,  //�Զ��ɼ�
	EN_INFO_KIND_MANUAL	    =2,  //�˹��ɼ�
};

//ͼƬ�ĸ�ʽ
enum EFileFormat
{
	EN_FILE_FORMAT_BMP			=1,  //Bmp
	EN_FILE_FORMAT_GIF			=2,  //Gif
	EN_FILE_FORMAT_JPEG			=3,  //Jpeg
	EN_FILE_FORMAT_JFIF			=4,  //Jfif
	EN_FILE_FORMAT_KDC			=5,  //Kdc
	EN_FILE_FORMAT_PCD			=6,  //Pcd
	EN_FILE_FORMAT_PCX			=7,  //Pcx
	EN_FILE_FORMAT_PIC			=8,  //Pic
	EN_FILE_FORMAT_PIX			=9,  //Pix
	EN_FILE_FORMAT_PNG			=10,  //Png
	EN_FILE_FORMAT_PSD			=11,  //Psd
	EN_FILE_FORMAT_TAPGA		=12,  //Tapga
	EN_FILE_FORMAT_TIFF			=13,  //Tiff
	EN_FILE_FORMAT_WMF			=14,  //Wmf
	EN_FILE_FORMAT_JPEG_2000	=15,  //Jp2
	EN_FILE_FORMAT_OTHER		=16,  //Other
};

//ͼƬ��Ϣ��Դ
enum EDataSourceType
{
	EN_DATA_SOURCE_TYPE_GOVERNMENT		=1,		//�������ؼ��
	EN_DATA_SOURCE_TYPE_SOCIOLOGY		=2,		//������ΰ����
	EN_DATA_SOURCE_TYPE_TRAFFIC			=3,		//��ͨ��أ��������ͨ��أ�
	EN_DATA_SOURCE_TYPE_IMMIGRATION		=4,		//���뾳���
	EN_DATA_SOURCE_TYPE_PORT			=5,		//�ۿڼ��
	EN_DATA_SOURCE_TYPE_FINANCIAL		=6,		//����ϵͳ���
	EN_DATA_SOURCE_TYPE_HOTEL			=7,		//�ùݼ��
	EN_DATA_SOURCE_TYPE_WWW				=8,		//������Ӫҵ�������
	EN_DATA_SOURCE_TYPE_SERVICE			=9,		//���ַ��������
	EN_DATA_SOURCE_TYPE_OTHER_COMPANY	=10,	//������ҵ/��ҵ��λ���
	EN_DATA_SOURCE_TYPE_RESIDENT		=11,	//�����Խ����
	EN_DATA_SOURCE_TYPE_GA				=12,	//�����ڲ�
	EN_DATA_SOURCE_TYPE_PRISONS			=13,	//����
	EN_DATA_SOURCE_TYPE_INERROGATION	=14,	//Ѷ����
	EN_DATA_SOURCE_TYPE_TERMINAL		=15,	//��������ֱ�����ȣ����ն�����
	EN_DATA_SOURCE_TYPE_MOBILE			=16,	//�ƶ�ִ��
	EN_DATA_SOURCE_TYPE_PHONE			=17,	//�ֻ���ƽ���������
	EN_DATA_SOURCE_TYPE_DV				=18,	//DV����
	EN_DATA_SOURCE_TYPE_CAMERA			=19,	//�������
	EN_DATA_SOURCE_TYPE_NETWORK			=20,	//�����ȡ
	EN_DATA_SOURCE_TYPE_AUDIO_VISUAL	=21,	//��������Ƭ
	EN_DATA_SOURCE_TYPE_OTHER			=99,	//����
};

//ͼƬ��Ϣ��Դ
enum EEventSort
{
	EN_EVENT_TYPE_OTHER					= 0,	//����
	EN_EVENT_TYPE_BAYONET_CAR			= 1,   	//���ڹ���
	EN_EVENT_TYPE_BAYONET_PEOPLE		= 2,   	//���ڹ���
	EN_EVENT_TYPE_BAYONET_FIGHT			= 3,  	//���ڴ��
	EN_EVENT_TYPE_BAYONET_RUN			= 4,  	//���ڿ��ٱ���
	EN_EVENT_TYPE_MOVING_DETECT			= 5,  	//Ŀ������������ȡ�˶�Ŀ����
	EN_EVENT_TYPE_TARGET_CLASS			= 6,  	//Ŀ������������ȡ,Ŀ�����
	EN_EVENT_TYPE_COLOR_DETECT			= 7,  	//Ŀ������������ȡ,Ŀ����ɫ���
	EN_EVENT_TYPE_PEOPLE_DETECT			= 8,  	//Ŀ������������ȡ,���˼��
	EN_EVENT_TYPE_PEOPLE_INFO			= 9,  	//Ŀ������������ȡ,��Ա���Է���
	EN_EVENT_TYPE_FACE_DETECT			= 10,  	//Ŀ������������ȡ,�������
	EN_EVENT_TYPE_FACE_COMP				= 11,  	//Ŀ������������ȡ,�����ȶ�
	EN_EVENT_TYPE_VEHC_DETECT			= 12,  	//Ŀ������������ȡ,�������
	EN_EVENT_TYPE_TRAFFIC_STATISTICS	= 14,  	//Ŀ����������,����ͳ��
	EN_EVENT_TYPE_DENSISTY_DETECT		= 15,  	//Ŀ����������,�ܶȼ��
	EN_EVENT_TYPE_PLATE_INFO			= 16,  	//Ŀ��ʶ��,����ʶ��
	EN_EVENT_TYPE_VEHC_INFO				= 17,  	//Ŀ��ʶ��,������������ʶ��
	EN_EVENT_TYPE_VEHC_FEATURE			= 18,  	//Ŀ��ʶ��,������������ʶ��
	EN_EVENT_TYPE_TRIPWIRE				= 19,  	//��Ϊ����,���߼��
	EN_EVENT_TYPE_INTRUSION				= 20,  	//��Ϊ����,���ּ��
	EN_EVENT_TYPE_RETROGRADE			= 21,  	//��Ϊ����,���м��
	EN_EVENT_TYPE_LINGER				= 22,  	//��Ϊ����,�ǻ����
	EN_EVENT_TYPE_LEGACE				= 23,  	//��Ϊ����,��������
	EN_EVENT_TYPE_TARGET_REMOVAL		= 24,  	//��Ϊ����,Ŀ���Ƴ����
	EN_EVENT_TYPE_VIDEO_SUMMAR			= 25,  	//��ƵժҪ,��ƵժҪ
	EN_EVENT_TYPE_FOG					= 26,  	//��Ƶ��ǿ�븴ԭ,ȥ��
	EN_EVENT_TYPE_VAGUE					= 27,  	//��Ƶ��ǿ�븴ԭ,ȥģ��
	EN_EVENT_TYPE_CONTRAST_RATIO		= 28,  	//��Ƶ��ǿ�븴ԭ,�Աȶ���ǿ
	EN_EVENT_TYPE_LOW_ILLUMINATION		= 29,  	//��Ƶ��ǿ�븴ԭ,���ն���Ƶͼ����ǿ
	EN_EVENT_TYPE_PARTIAL_COLOR			= 30,  	//��Ƶ��ǿ�븴ԭ,ƫɫУ��
	EN_EVENT_TYPE_WIDE_DYNAMIC			= 31,  	//��Ƶ��ǿ�븴ԭ,��̬��ǿ
	EN_EVENT_TYPE_SUPER_RESOLUTION		= 32,  	//��Ƶ��ǿ�븴ԭ,���ֱ����ؽ�
	EN_EVENT_TYPE_GEOMETRY				= 33,  	//��Ƶ��ǿ�븴ԭ,���λ���У��
	EN_EVENT_TYPE_PARITY				= 34,  	//��Ƶ��ǿ�븴ԭ,��ż��У��
	EN_EVENT_TYPE_COLOR_ROOM			= 35,  	//��Ƶ��ǿ�븴ԭ,��ɫ�ռ��������
	EN_EVENT_TYPE_NOISE					= 36,  	//��Ƶ��ǿ�븴ԭ,ȥ����
};

//��Ƶͼ����Ϣ�������������
enum EBasicObjectsInfoType
{
	EN_BASIC_OBJECT_INFO_TYPE_VIDEO		=1,		//��ƵƬ��
	EN_BASIC_OBJECT_INFO_TYPE_IMAGE		=2,		//ͼ��
	EN_BASIC_OBJECT_INFO_TYPE_FILE		=3,		//�ļ�
	EN_BASIC_OBJECT_INFO_TYPE_OTHER		=99,	//����
};

//��Ƶͼ����Ϣ�������Զ��������
enum EAttributeInfoType
{
	EN_ATTRIBUTE_INFO_TYPE_PEOPLE		=1,		//��Ա
	EN_ATTRIBUTE_INFO_TYPE_CAR			=2,		//������
	EN_ATTRIBUTE_INFO_TYPE_BICYCLE		=3,		//�ǻ�����
	EN_ATTRIBUTE_INFO_TYPE_GOODS		=4,		//��Ʒ
	EN_ATTRIBUTE_INFO_TYPE_SCENE		=5,		//����
	EN_ATTRIBUTE_INFO_TYPE_FACE			=6,		//����
	EN_ATTRIBUTE_INFO_TYPE_TAG			=7,		//��Ƶͼ���ǩ
	EN_ATTRIBUTE_INFO_TYPE_OTHER		=99,	//����
};

enum EColorType
{
	EN_COLOR_TYPE_BALCK			= 1 ,//��
	EN_COLOR_TYPE_WHITE			= 2 ,//��
	EN_COLOR_TYPE_GRAY			= 3 ,//��
	EN_COLOR_TYPE_RED			= 4 ,//��
	EN_COLOR_TYPE_BLUE			= 5 ,//��
	EN_COLOR_TYPE_YELLOW		= 6 ,//��
	EN_COLOR_TYPE_ORANGE		= 7 ,//��
	EN_COLOR_TYPE_BROWN			= 8 ,//��
	EN_COLOR_TYPE_GREEN			= 9 ,//��
	EN_COLOR_TYPE_VIOLET		= 10 ,//��
	EN_COLOR_TYPE_CYAN			= 11 ,//��
	EN_COLOR_TYPE_PINK			= 12 ,//��
	EN_COLOR_TYPE_TRANSPARENT	= 13 ,//͸��
	EN_COLOR_TYPE_OTHER			= 99 ,//����
};

// #ifdef _MSC_VER
// #pragma pack(pop)
// #endif //WIN32

#pragma pack(pop)
#endif //end of _IVHS_DEFINE_H_
