
// RelayRTSPDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RelayRTSP.h"
#include "RelayRTSPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRelayRTSPDlg �Ի���



CRelayRTSPDlg::CRelayRTSPDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CRelayRTSPDlg::IDD, pParent), nNVRChannel(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRelayRTSPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRelayRTSPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_LOAD_INIFILE, &CRelayRTSPDlg::On_Click_LoadIniFile)
END_MESSAGE_MAP()


// CRelayRTSPDlg ��Ϣ�������

BOOL CRelayRTSPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ����

	//��ȡĬ�ϵ�ini�ļ�������NVR��RTSP����
	//int n =  ::GetPrivateProfileInt("RTSP", "Port1", 234, "./default.ini");
	//char ss[128];
	//::GetPrivateProfileString("NVR1", "IP","default",ss,128,"./NVR-test.ini");
	//��ʼ��NVR�ɼ���ز���

	//NVR���
	pStreamHead = new BYTE[STREAM_HEAD_SIZE];
	// �����
	hRealStream = TMCC_Init(TMCC_INITTYPE_REALSTREAM);
	::TMCC_RegisterStreamCallBack(hRealStream, OnStreamDataCallBack, this);
	TMCC_SetStreamBufferTime(hRealStream, 500);
	memset(&realStream, 0, sizeof(tmPlayRealStreamCfg_t));
	realStream.dwSize = sizeof(tmPlayRealStreamCfg_t);
	sprintf_s(realStream.szAddress, "192.168.1.4");
	sprintf_s(realStream.szUser, "system");
	sprintf_s(realStream.szPass, "system");
	realStream.iPort = 6002;
	realStream.byChannel = 0;		// NVR���豸���ж�ͨ����ͨ����Ŵ�0��ʼ
	realStream.byStream = 0;		// �����ţ�0Ϊ��������1Ϊ��������2Ϊ������������������		
	realStream.byForceDecode = 0;	// byForceDecode=1��ʾǿ�ƽ���m_ctrlImage.GetSafeHwnd()
	realStream.byConnectType = 0;	// �������ͣ��豸��������������ö�Ӧ�Ĵ���Э��		
	realStream.byMultiStream = 0;	// ��ֵ��Ч����byStream��ͬʱȡ�ö��������ݣ�������������ȫ���豸

	if (TMCC_ERR_SUCCESS != TMCC_ConnectStream(hRealStream, &realStream, NULL))
	{
		MessageBox("������Ƶʧ��....");
	}

	//��ʼ��RTSP����
	//scheduler = BasicTaskScheduler::createNew();
	//env = BasicUsageEnvironment::createNew(*scheduler);
	//RTSPServer * rtspServer = RTSPServer::createNew(*env, 6002, auThDB);

	//����û����ʿ��ƣ�ÿ����һ���ͻ������ӣ�����Ҫ����һ��UserRecord��
	UserAuthenticationDatabase *auThDB = NULL;
#ifdef ACCESS_CONTROL
	authDB = new UserAuthenticationDatabase;
	authDB->addUserRecord("system", "system"); // replace these with real strings
#endif

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

int WINAPI CRelayRTSPDlg::OnStreamDataCallBack(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context)
{
	return ((CRelayRTSPDlg*)context)->OnStreamData(hTmCC, pStreamInfo);
}

///************* ��Ƶ�ص�����    ***********
//�ڻص������д���H.264����֡
//ÿ����1������֡���򽫴�����ֱ֡�Ӵ����RTSP��������
//ע��H.264����֡��SDK��RTSP�д��/���������
// ********************
int CRelayRTSPDlg::OnStreamData(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo)
{
	//headRealStream = (tmAvInfo_t)pStreamHead;
	//TRACE(headRealStream.byStreamId);
	//�յ���Ƶ����
	if (0 == pStreamInfo->byFrameType)
	{
		TRACE("�յ���Ƶ����   ����:%d����ID��%d\n", pStreamInfo->byStreamNo, pStreamInfo->dwStreamId);

		//������Ƶ֡��RTSP���������ݻ����������ȷ����ͬͨ��������Ƶ��������
		switch (nNVRChannel)
		{
		default:
			break;
		}
	}

	//�յ���Ƶ����
	if (1 == pStreamInfo->byFrameType)
	{
		TRACE("�յ���Ƶ��������:%d����ID��%d\n", pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);
	}

	//�յ�������ͷ
	if (2 == pStreamInfo->byFrameType)
	{
		TRACE("�յ�������ͷ:%d֡\n", pStreamInfo->byFrameType);
		memcpy(pStreamHead, pStreamInfo->pBuffer, pStreamInfo->iBufferSize);
		nStreamHeadSize = pStreamInfo->iBufferSize;
	}

	return -1;
}

void CRelayRTSPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRelayRTSPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRelayRTSPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRelayRTSPDlg::startReplicaFileSink(StreamReplicator* replicator, char const* outputFileName)
{
	// Begin by creating an input stream from our replicator:
	FramedSource* source = replicator->createStreamReplica();

	// Then create a 'file sink' object to receive thie replica stream:
	MediaSink* sink = FileSink::createNew(*env, outputFileName);

	// Now, start playing, feeding the sink object from the source:
	sink->startPlaying(*source, NULL, NULL);
}

void CRelayRTSPDlg::startReplicaUDPSink(StreamReplicator* replicator, char const* outputAddressStr, portNumBits outputPortNum)
{
	// Begin by creating an input stream from our replicator:
	FramedSource* source = replicator->createStreamReplica();

	// Create a 'groupsock' for the destination address and port:
	struct in_addr outputAddress;
	outputAddress.s_addr = our_inet_addr(outputAddressStr);

	Port const outputPort(outputPortNum);
	unsigned char const outputTTL = 255;

	Groupsock* outputGroupsock = new Groupsock(*env, outputAddress, outputPort, outputTTL);

	// Then create a liveMedia 'sink' object, encapsulating this groupsock:
	unsigned const maxPacketSize = 65536; // allow for large UDP packets
	MediaSink* sink = BasicUDPSink::createNew(*env, outputGroupsock, maxPacketSize);

	// Now, start playing, feeding the sink object from the source:
	sink->startPlaying(*source, NULL, NULL);
}

void CRelayRTSPDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//�ͷ�NVR��Դ
	TMCC_Done(hRealStream);
	hRealStream = NULL;

	//�ͷ�RTSP������Դ
	//BasicTaskScheduler::

	if (False == env->reclaim())
	{
		AfxMessageBox("RTSP�����ڴ���Դ�ͷŴ���");
	}
	CDialogEx::OnClose();
}

void CRelayRTSPDlg::On_Click_LoadIniFile()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlgFile(true);
	dlgFile.DoModal();
}
