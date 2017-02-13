
// RelayRTSPDlg.h : 头文件
//

#include "Groupsock.hh"
#include "UsageEnvironment.hh"
#include "BasicUsageEnvironment.hh"
#include "liveMedia.hh"

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
	DECLARE_MESSAGE_MAP()

;private:
	TaskScheduler* scheduler;
	UsageEnvironment* env;


private:
	void startReplicaUDPSink(StreamReplicator* replicator, char const* outputAddressStr, portNumBits outputPortNum); // forward
	void startReplicaFileSink(StreamReplicator* replicator, char const* outputFileName); // forward
public:
	afx_msg void OnClose();
};
