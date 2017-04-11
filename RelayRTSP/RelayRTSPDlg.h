
// RelayRTSPDlg.h : ͷ�ļ�
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
	DECLARE_MESSAGE_MAP();

private:	
	//RTSP�������
	TaskScheduler* scheduler;
	UsageEnvironment* env;
	int nCameraIP;

	//NVR���
	HANDLE hRealStream;		//���Ӿ��
	tmPlayRealStreamCfg_t realStream;
	int nNVRChannel;

	//������ͷ��Ϣ
	const int STREAM_HEAD_SIZE = 1024 * 4;
	BYTE *pStreamHead;
	int nStreamHeadSize;

private:
	void startReplicaUDPSink(StreamReplicator* replicator, char const* outputAddressStr, portNumBits outputPortNum); // forward
	void startReplicaFileSink(StreamReplicator* replicator, char const* outputFileName); // forward
public:
	afx_msg void OnClose();
	afx_msg void On_Click_LoadIniFile();

	//�������ص����
	static int WINAPI	OnStreamDataCallBack(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context);
	int 				OnStreamData(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo);

};
