#ifndef _H_DATA_RTSPRELAY
#define _H_DATA_RTSPRELAY

//NVR���ò���
typedef struct _t_NVR_CONFIG
{
	CString strVideoType;			//��Ƶ����,D1,1080P,4k
	int nCountVideoChannel;		//NVR����Ƶͨ��������(��Ӧ��ǰNVR�н��������ͷ����)
	int IP_Suffix[16];					//ÿ������ͷIP��ַ(���8λ),Ĭ��Ϊ192.168.1.XX,����XXΪ��ǰ�����е�ֵ
}NVR_CONFIG;

//RTSP�������ò���(��NVR���)
typedef struct _t_RTSP_NVR_CONFIG
{
	int nCountNVR;		//��ǰRTSP���������ӵ�NVR����
	NVR_CONFIG *arrayNVR;		//NVR���飨ʹ��ǰ���ʼ����
};


#endif	//_H_DATA_RTSPRELAY