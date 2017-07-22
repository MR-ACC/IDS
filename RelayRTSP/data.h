#ifndef _H_DATA_RTSPRELAY
#define _H_DATA_RTSPRELAY

//NVR��RTSP�������ò���
typedef struct tagNVRLogin_t
{
	int nRtspServerPort;				//rtsp�������Ķ˿ں�(1̨NVR��Ӧ1��rtsp����,ͬʱ��Ӧ1���˿ں�)

	CString strVideoType;			//��Ƶ����,D1,1080P,4k
	CString strNVR_IP;				//NVR��IP��ַ
	int nNVRPort;						//NVR�ĵ�¼�˿ں�
	int nCountVideoChannel;		//NVR����Ƶͨ��������(��Ӧ��ǰNVR�н��������ͷ����)
	CString strUserName;			//NVR�ĵ�¼�û���
	CString strUserPassword;		//NVR�ĵ�¼�û�����
	//int IP_Suffix[16];				//ÿ������ͷIP��ַ(���8λ),Ĭ��Ϊ192.168.1.XX,����XXΪ��ǰ�����е�ֵ
}NVRLogin_t;

//RTSP����ȫ�����ò���(��NVR���)
typedef struct _t_RTSP_NVR_CONFIG
{
	int nCountNVR;		//��ǰRTSP���������ӵ�NVR����
	NVRLogin_t *arrayNVR;		//NVR���飨ʹ��ǰ���ʼ����
}RTSP_NVR_CONFIG;


#endif	//_H_DATA_RTSPRELAY