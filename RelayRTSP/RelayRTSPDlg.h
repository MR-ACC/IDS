
// RelayRTSPDlg.h : ͷ�ļ�
//

#include "GroupsockHelper.hh"
#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"
#include "UsageEnvironment.hh"
#include "Groupsock.hh"
#include "inc\tmTransDefine.h"
#include "inc\tmControlClient.h"
#include "H264LiveVideoServerMediaSubssion.hh"
#include "H264FramedLiveSource.hh"
#include "RemotePlayerCom.h"

//#include <string>
//using namespace std;

#pragma once

#define WM_PLAYSTATE			WM_USER + 210
#define WM_REFRESHSTATE			WM_USER + 211


//�ļ��б�
typedef struct tagFileList_t
{
	struct tagFileList_t*	prev;
	struct tagFileList_t*	next;
	tmFindFileCfg_t			file;
	int						item;
	BOOL					bImage;
}FileList_t;

typedef struct tagNVRLogin_t
{
	CString strIP;
	int nPort;
	CString strName;
	CString strPassword;
	int nChannelCount;
	CString strVideoType;
}NVRLogin_t;

#define HEAD_MAX_LEN		1024
typedef struct tagRemoteFile_t
{
	HANDLE	hObject;
	HANDLE	hControl;
	BYTE	pHeadInfo[HEAD_MAX_LEN];
	int		iHeadInfoLen;
	int		iFileCurrentPos;
	int		iFrameRate;
	BOOL	bFileFinish;
	BYTE*	pFrameBuffer;
	int		iFrameBufferLen;
	int		iFrameLen;
}RemoteFile_t;

//RTSP�������
typedef struct tagRtspServer_t
{
	UserAuthenticationDatabase *auThDB;		//�û���Ϣ
	RTSPServer *server;						//������
	int port;								//�������οں�
	int datasize;							//����������
	unsigned char* databuf;					//������ָ��
	ServerMediaSession* sms;				//�Ự
}RtspServer_t;


// CRelayRTSPDlg �Ի���
class CRelayRTSPDlg : public CDialogEx
{
// ����
public:
	CRelayRTSPDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RELAYRTSP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//afx_msg LRESULT OnPlayStateMessage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnReceiveFrame(WPARAM w, LPARAM p);
	DECLARE_MESSAGE_MAP();

private:	
	//RTSP�������
	TaskScheduler* scheduler;
	UsageEnvironment* env;
	int nCameraIP;

	//���λ��
	POINT ptFile;

	int m_iImageWidth ,m_iImageHeight;

	//��½���
	HANDLE hLogin;		//��½���Ӿ��
	tmConnectInfo_t  tmLogin;
	
	HANDLE m_hPlay;	//�����ļ����


	//������ͷ��Ϣ
	const int STREAM_HEAD_SIZE = 1024 * 4;
	BYTE *pStreamHead;
	int nStreamHeadSize;

	//RTSP�������
	RTSPServer * rtspServer;		//������
	UserAuthenticationDatabase *auThDB;		// �û���Ϣ
	ServerMediaSession* sms;

	Boolean reuseFirstSource;	//���Ϊ��true������������Ŀͻ��˸���һ���ͻ��˿���һ������Ƶ�������������ͻ��˽����ʱ�����²���
	char const* streamName = "h264ESVideoTest";
	char const* descriptionString = "Session streamed by \"RTSP Relay Server!\"";
	int datasize;//����������
	unsigned char* databuf;//������ָ��
	bool dosent;//rtsp���ͱ�־λ��Ϊtrue���ͣ������˳�

private:
	void AddToRtspServer(UsageEnvironment* u_env, RtspServer_t serv);
	void startReplicaUDPSink(StreamReplicator* replicator, char const* outputAddressStr, portNumBits outputPortNum); // forward
	void startReplicaFileSink(StreamReplicator* replicator, char const* outputFileName); // forward

	static UINT			FileSearchProc(void* lpThis);
	UINT				FileSearchProcLoop(int iControlType);

	static int OnRemoteFileRead(HANDLE hObject, void* lpBuffer, int nRead, unsigned int* pdwCodeTag, int* pNeedBufSize, void* context);
	static int OnRemoteFileSeek(HANDLE hObject, int offset, int origin, int* pPosition, unsigned int* pTimeStamp, void* context);
protected:
	//�����б�
	FileList_t*			InsertList(tmFindFileCfg_t* pFind, BOOL bImage);

	//�ļ��б�
	FileList_t*		m_pFileList;

	//NVR��½��ز���
	NVRLogin_t m_tNVRLogin;

	//RTSP
	CWinThread *pRtspThread;
	static UINT ThreadRTSPEvent(void* context);
	UINT RTSPEvent();

public:
	afx_msg void OnClose();

	//�������ص����
	int					OnStreamData(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo);
	static int WINAPI	OnLoginCallBack(HANDLE hTmCC, BOOL bConnect, unsigned int dwResult, void *context);
	static int	 WINAPI	fnDataCallBack(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context);

	// NVR��Ƶͨ����
	int m_nNVRChannel;
	CComboBox m_combNVRChannel;
	CDateTimeCtrl m_ctrlDateStart, m_ctrlTimeStart, m_ctrlDateEnd, m_ctrlTimeEnd;
	afx_msg void OnClickedConnectToNVR();
	afx_msg void OnClickedDisconnectFromNVR();
	CString m_strNVRIPAddress;
	CListCtrl m_listFile;
	afx_msg void OnClickedSearchFile();
	afx_msg void OnClickedStartRtsp();
	afx_msg void OnClickFileList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
};
