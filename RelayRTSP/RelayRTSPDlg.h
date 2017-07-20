
// RelayRTSPDlg.h : 头文件
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


//文件列表
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

//RTSP服务参数
typedef struct tagRtspServer_t
{
	UserAuthenticationDatabase *auThDB;		//用户信息
	RTSPServer *server;						//服务器
	int port;								//服务器段口号
	int datasize;							//数据区长度
	unsigned char* databuf;					//数据区指针
	ServerMediaSession* sms;				//会话
}RtspServer_t;


// CRelayRTSPDlg 对话框
class CRelayRTSPDlg : public CDialogEx
{
// 构造
public:
	CRelayRTSPDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_RELAYRTSP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//afx_msg LRESULT OnPlayStateMessage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnReceiveFrame(WPARAM w, LPARAM p);
	DECLARE_MESSAGE_MAP();

private:	
	//RTSP服务相关
	TaskScheduler* scheduler;
	UsageEnvironment* env;
	int nCameraIP;

	//鼠标位置
	POINT ptFile;

	int m_iImageWidth ,m_iImageHeight;

	//登陆相关
	HANDLE hLogin;		//登陆连接句柄
	tmConnectInfo_t  tmLogin;
	
	HANDLE m_hPlay;	//播放文件句柄


	//数据流头信息
	const int STREAM_HEAD_SIZE = 1024 * 4;
	BYTE *pStreamHead;
	int nStreamHeadSize;

	//RTSP服务相关
	RTSPServer * rtspServer;		//服务器
	UserAuthenticationDatabase *auThDB;		// 用户信息
	ServerMediaSession* sms;

	Boolean reuseFirstSource;	//如果为“true”则其他接入的客户端跟第一个客户端看到一样的视频流，否则其他客户端接入的时候将重新播放
	char const* streamName = "h264ESVideoTest";
	char const* descriptionString = "Session streamed by \"RTSP Relay Server!\"";
	int datasize;//数据区长度
	unsigned char* databuf;//数据区指针
	bool dosent;//rtsp发送标志位，为true则发送，否则退出

private:
	void AddToRtspServer(UsageEnvironment* u_env, RtspServer_t serv);
	void startReplicaUDPSink(StreamReplicator* replicator, char const* outputAddressStr, portNumBits outputPortNum); // forward
	void startReplicaFileSink(StreamReplicator* replicator, char const* outputFileName); // forward

	static UINT			FileSearchProc(void* lpThis);
	UINT				FileSearchProcLoop(int iControlType);

	static int OnRemoteFileRead(HANDLE hObject, void* lpBuffer, int nRead, unsigned int* pdwCodeTag, int* pNeedBufSize, void* context);
	static int OnRemoteFileSeek(HANDLE hObject, int offset, int origin, int* pPosition, unsigned int* pTimeStamp, void* context);
protected:
	//加入列表
	FileList_t*			InsertList(tmFindFileCfg_t* pFind, BOOL bImage);

	//文件列表
	FileList_t*		m_pFileList;

	//NVR登陆相关参数
	NVRLogin_t m_tNVRLogin;

	//RTSP
	CWinThread *pRtspThread;
	static UINT ThreadRTSPEvent(void* context);
	UINT RTSPEvent();

public:
	afx_msg void OnClose();

	//数据流回调相关
	int					OnStreamData(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo);
	static int WINAPI	OnLoginCallBack(HANDLE hTmCC, BOOL bConnect, unsigned int dwResult, void *context);
	static int	 WINAPI	fnDataCallBack(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context);

	// NVR视频通道号
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
