
// RelayRTSPDlg.h : ͷ�ļ�
//

#include "Groupsock.hh"
#include "UsageEnvironment.hh"
#include "BasicUsageEnvironment.hh"
#include "liveMedia.hh"

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
