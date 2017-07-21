#ifndef _H_DATA_RTSPRELAY
#define _H_DATA_RTSPRELAY

//NVR配置参数
typedef struct _t_NVR_CONFIG
{
	CString strVideoType;			//视频类型,D1,1080P,4k
	int nCountVideoChannel;		//NVR中视频通道的数量(对应当前NVR中接入的摄像头数量)
	int IP_Suffix[16];					//每个摄像头IP地址(最后8位),默认为192.168.1.XX,其中XX为当前数组中的值
}NVR_CONFIG;

//RTSP服务配置参数(与NVR相关)
typedef struct _t_RTSP_NVR_CONFIG
{
	int nCountNVR;		//当前RTSP服务器连接的NVR数量
	NVR_CONFIG *arrayNVR;		//NVR数组（使用前须初始化）
};


#endif	//_H_DATA_RTSPRELAY