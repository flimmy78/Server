#ifndef __NET_SDK_ERROR_H__
#define __NET_SDK_ERROR_H__ 

/*
**sdk error code
*/	
//0~39 ͨ�ô���
#define NET_ERROR_NO_ERROR                      0                   //û�д���                                                  
#define NET_ERROR_VERSION_MISMATCH              1                   //�汾��ƥ��                                                
#define NET_ERROR_CHAN_NOT_SUPPORT              2                   //ָ��ͨ����֧�ָò���                                      
#define NET_ERROR_UNKNOW_ENCRYPT                3                   //δ֪�ļ��ܷ�ʽ                                            
#define NET_ERROR_SDK_INTER_ERROR               4                   //SDK�ڲ�����                                               
#define NET_ERROR_ALLOC_RESOURCE_ERROR          5                   //��Դ�������                                              
#define NET_ERROR_NOT_SUPPORT                   6                   //SDK��֧�ָò���                                           
#define NET_ERROR_NO_INIT                       7                   //û�г�ʼ��                                                
#define NET_ERROR_PARAM_ERROR                   8                   //����Ĳ�������                                            
#define NET_ERROR_INPUT_TIME_ERROR              9                   //ʱ�����벻��ȷ                                            
#define NET_ERROR_INVALID_HANDLE                10                  //��Ч�ľ��                                                
#define NET_ERROR_ORDER_ERROR                   11                  //�ӿڵ��ô������      
#define NET_ERROR_OS_NO_SUPPORT                 12                  //��ǰϵͳ��֧�ִ˹���      
#define NET_ERROR_UNSUPPORT_CONFIG              13                  //��֧�ֵ���������
#define NET_ERROR_SERVER_DATA_ERROR             14                  //����˴������������
#define NET_ERROR_TIME_PARA_ERROR               15                  //ʱ���������
#define NET_ERROR_BUFFER_SIZE_ERROR             16                  //�����buffer��С����
#define NET_ERROR_ID_ERROR                      17                  //ID����, ������ID, Ӳ��ID
#define NET_ERROR_PLAY_END                      18                  //�ط�¼���ļ��ѽ���
#define NET_ERROR_MAX_SESSION                   19                  //session����ﵽ�����Ŀ                  

//40~59 �������
#define NET_ERROR_BIND_SOCKET_ERROR             40                  //���׽���ʧ��                                            
#define NET_ERROR_CLOSE_SOCKET_ERROR            41                  //socket�����жϣ��˴���ͨ�������������жϻ�Ŀ�ĵز��ɴ�    
#define NET_ERROR_LISTEN_ERROR                  42                  //socket����ʧ��                                            
#define NET_ERROR_CONNECT_FAIL                  43                  //���ӷ�����ʧ��                                            
#define NET_ERROR_SEND_FAIL                     44                  //�����������ʧ��                                          
#define NET_ERROR_RECV_FAIL                     45                  //�ӷ�������������ʧ��                                      
#define NET_ERROR_RECV_TIMEOUT                  46                  //�ӷ������������ݳ�ʱ                                      
#define NET_ERROR_NO_ENOUGH_SENDBUF             47                  //���ͻ�����̫С                                            
#define NET_ERROR_NO_ENOUGH_RECVBUF             48                  //���ջ�����̫С                                            
#define NET_ERROR_CREATE_SOCKET_ERROR           49                  //����SOCKET����                                            
#define NET_ERROR_SET_SOCKET_ERROR              50                  //����SOCKET��������        
#define NET_ERROR_LOCAL_PORT_IN_USE             51                  //���ض˿��ѱ�ռ��
#define NET_ERROR_FILE_END                      52                  //�ļ�����
#define NET_ERROR_RECONNECTING                  53                  //��������             

//60~79 �ļ�����
#define NET_ERROR_CREATE_FILE_FAIL              60                  //�����ļ�����                                              
#define NET_ERROR_OPEN_FILE_FAIL                61                  //���ļ�����                                              
#define NET_ERROR_WRITE_FILE_FAIL               62                  //д�ļ�ʧ��                                                
#define NET_ERROR_UNKNOW_FORMAT                 63                  //�ļ���ʽ����ȷ                                            
#define NET_ERROR_DIR_ERROR                     64                  //·������     
#define NET_ERROR_READ_FILE_FAIL                65                  //���ļ�ʧ��                                                                                           

//80~99 ϵͳ�������
#define NET_ERROR_PC_OPEN_SOUND_FAIL            80                  //��PC����ʧ��                                            
#define NET_ERROR_AUDIO_MODE_ERROR              81                  //����ģʽ����                                              
#define NET_ERROR_VOICEMONOPOLIZE               82                  //��������ռ                                                
#define NET_ERROR_LOAD_PLAYSDK_API_FAIL         83                  //���ò��ſ�ĳ���ӿ�ʧ��                                
#define NET_ERROR_LOAD_PLAYSDK_FAIL             84                  //���ز���SDKʧ��                                           
#define NET_ERROR_PLAYER_FAIL                   85                  //���ſ���ô���                                            
#define NET_ERROR_GET_LOCAL_IP_FAIL             86                  //��ÿͻ��˵�IP��ַ�������ַʧ��                          
#define NET_ERROR_GET_LOCAL_MAC_FAIL            87                  //��ÿͻ��˵�IP��ַ�������ַʧ��                          
#define NET_ERROR_IP_MISMATCH                   88                  //IP��ַ��ƥ��                                              
#define NET_ERROR_MAC_MISMATCH                  89                  //MAC��ַ��ƥ��           

//100~130 ��ģʽ��ش���
#define NET_ERROR_NO_IPC_REGISTER               101                 //û��IPC��������������

//500~999   �豸�˷����Ĵ���
#define NET_ERROR_OPERATION_ERROR               500                 //�豸���ص���ʧ��                                              
#define NET_ERROR_USER_NOT_EXIST                501                 //�û�������                                                
#define NET_ERROR_PASSWORD_ERROR                502                 //�û����������                                            
#define NET_ERROR_INVALID_SESSION_ID            503                 //��Ч�ĻỰID                                              
#define NET_ERROR_MAX_USER_NUM                  504                 //�豸���û����ﵽ���                                      
#define NET_ERROR_NOSERIALPORT                  505                 //���ںŴ���                                                
#define NET_ERROR_ALARMIN_ID_ERROR              506                 //��Ч�ı��������                                          
#define NET_ERROR_ALARMOUT_ID_ERROR             507                 //��Ч�ı��������                                          
#define NET_ERROR_CHANNEL_ID_ERROR              508                 //ͨ���Ŵ���                                                
#define NET_ERROR_NET_ERROR_DATA                509                 //�豸��Ӧ���͵���������                                    
#define NET_ERROR_VOICE_IN_USE                  510                 //�����������Խ���ռ��                                      
#define NET_ERROR_NO_DISK                       511                 //û��Ӳ��                                                  
#define NET_ERROR_DISK_ID_ERROR                 512                 //Ӳ�̺Ŵ���                                                
#define NET_ERROR_NO_RIGHT                      513                 //�豸�˷�ӦȨ�޲���  
#define NET_ERROR_DISK_IS_FORMATING             514                 //Ӳ�����ڸ�ʽ��Ӳ��
#define NET_ERROR_UNKONW_DEVICE_ERROR           515                 //�豸���ص�δ֪������

//1000~1255 RTSP����                  
#define NET_ERROR_LOAD_RTSP_SDK_ERROR           1000                //����RTSP SDK ʧ��
#define NET_ERROR_RTSP_INVALID_PARAM            1001                //��������                                                  
#define NET_ERROR_RTSP_NOT_SUPPORT              1002                //��֧�ֵķ���                                              
#define NET_ERROR_RTSP_NO_MEMORY                1003                //�ڴ治��                                                  
#define NET_ERROR_RTSP_TIMEDOUT                 1004                //���ʳ�ʱ                                                  
#define NET_ERROR_RTSP_AGAIN                    1005                //������                                                    
#define NET_ERROR_RTSP_UNIMPLEMENTED            1006                //δʵ��                                                    
#define NET_ERROR_RTSP_WRONG_STATUS             1007                //�����״̬                                                
#define NET_ERROR_RTSP_PROTOCOL                 1008                //��֧�ֵ�Э��   
#define NET_ERROR_RTSP_NOTFOUND                 1009                //record file not found
#define NET_ERROR_RTSP_AUTHFAILED               1010                //Auth Failed
#define NET_ERROR_RTSP_FAULT                    1255                //General fault

//1400~1500 ���ſ����


/*
*exception callback
*/
#define EXCP_HEARTBEAT_FAIL			        0x0001	            //�û�����ʱ�쳣
#define EXCP_HEARTBEAT_RESUME			    0x0002	            //�û������ָ�
#define EXCP_VOICE_TALK			            0x0003	            //�����Խ��쳣
#define EXCP_ALARMCHAN_FAIL					0x0004	            //�����쳣
#define EXCP_ALARMCHAN_RECONNECT		    0x0007	            //����ʱ����
#define EXCP_ALARMCHAN_RESUME			    0x0010              //����ʱ�����ɹ�
#define EXCP_REALPLAY_FAIL				    0x0005	            //Ԥ���쳣
#define EXCP_REALPLAY_RECONNECT				0x0006	            //Ԥ��ʱ����
#define EXCP_REALPLAY_RESUME		        0x0009              //Ԥ��ʱ�����ɹ�
#define EXCP_PLAYBACK_FAIL				    0x0008	            //�ط��쳣

#endif
