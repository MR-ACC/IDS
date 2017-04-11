
// RelayRTSPDlg.h : 头文件
//

#include <GroupsockHelper.hh>
#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"
#include "UsageEnvironment.hh"
#include "Groupsock.hh"
#include "inc\tmTransDefine.h"
#include "inc\tmControlClient.h"
#include "H264LiveVideoServerMediaSubssion.hh"
#include "H264FramedLiveSource.hh"

#pragma once


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
	DECLARE_MESSAGE_MAP();

private:	
	//RTSP服务相关
	TaskScheduler* scheduler;
	UsageEnvironment* env;
	int nCameraIP;

	//NVR相关
	HANDLE hRealStream;		//连接句柄
	tmPlayRealStreamCfg_t realStream;
	int nNVRChannel;

	//数据流头信息
	const int STREAM_HEAD_SIZE = 1024 * 4;
	BYTE *pStreamHead;
	int nStreamHeadSize;

private:
	void startReplicaUDPSink(StreamReplicator* replicator, char const* outputAddressStr, portNumBits outputPortNum); // forward
	void startReplicaFileSink(StreamReplicator* replicator, char const* outputFileName); // forward
public:
	afx_msg void OnClose();
	afx_msg void On_Click_LoadIniFile();

	//数据流回调相关
	static int WINAPI	OnStreamDataCallBack(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context);
	int 				OnStreamData(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo);

};
