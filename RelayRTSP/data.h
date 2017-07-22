#ifndef _H_DATA_RTSPRELAY
#define _H_DATA_RTSPRELAY

//NVR及RTSP服务配置参数
typedef struct tagNVRLogin_t
{
	int nRtspServerPort;				//rtsp服务器的端口号(1台NVR对应1个rtsp服务,同时对应1个端口号)

	CString strVideoType;			//视频类型,D1,1080P,4k
	CString strNVR_IP;				//NVR的IP地址
	int nNVRPort;						//NVR的登录端口号
	int nCountVideoChannel;		//NVR中视频通道的数量(对应当前NVR中接入的摄像头数量)
	CString strUserName;			//NVR的登录用户名
	CString strUserPassword;		//NVR的登录用户密码
	//int IP_Suffix[16];				//每个摄像头IP地址(最后8位),默认为192.168.1.XX,其中XX为当前数组中的值
}NVRLogin_t;

//RTSP服务全局配置参数(与NVR相关)
typedef struct _t_RTSP_NVR_CONFIG
{
	int nCountNVR;		//当前RTSP服务器连接的NVR数量
	NVRLogin_t *arrayNVR;		//NVR数组（使用前须初始化）
}RTSP_NVR_CONFIG;


#endif	//_H_DATA_RTSPRELAY