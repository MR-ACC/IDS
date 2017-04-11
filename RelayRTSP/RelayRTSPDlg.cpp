
// RelayRTSPDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RelayRTSP.h"
#include "RelayRTSPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
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


// CRelayRTSPDlg 对话框



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


// CRelayRTSPDlg 消息处理程序

BOOL CRelayRTSPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代

	//读取默认的ini文件，配置NVR和RTSP服务
	//int n =  ::GetPrivateProfileInt("RTSP", "Port1", 234, "./default.ini");
	//char ss[128];
	//::GetPrivateProfileString("NVR1", "IP","default",ss,128,"./NVR-test.ini");
	//初始化NVR采集相关参数

	//NVR相关
	pStreamHead = new BYTE[STREAM_HEAD_SIZE];
	// 打开相机
	hRealStream = TMCC_Init(TMCC_INITTYPE_REALSTREAM);
	::TMCC_RegisterStreamCallBack(hRealStream, OnStreamDataCallBack, this);
	TMCC_SetStreamBufferTime(hRealStream, 500);
	memset(&realStream, 0, sizeof(tmPlayRealStreamCfg_t));
	realStream.dwSize = sizeof(tmPlayRealStreamCfg_t);
	sprintf_s(realStream.szAddress, "192.168.1.4");
	sprintf_s(realStream.szUser, "system");
	sprintf_s(realStream.szPass, "system");
	realStream.iPort = 6002;
	realStream.byChannel = 0;		// NVR等设备会有多通道，通道编号从0开始
	realStream.byStream = 0;		// 码流号，0为主码流，1为从码流，2为第三码流，依次类推		
	realStream.byForceDecode = 0;	// byForceDecode=1表示强制解码m_ctrlImage.GetSafeHwnd()
	realStream.byConnectType = 0;	// 连接类型，设备会根据这个标记启用对应的传输协议		
	realStream.byMultiStream = 0;	// 此值有效忽略byStream，同时取得多码流数据，用于连接鱼眼全景设备

	if (TMCC_ERR_SUCCESS != TMCC_ConnectStream(hRealStream, &realStream, NULL))
	{
		MessageBox("连接视频失败....");
	}

	//初始化RTSP服务
	//scheduler = BasicTaskScheduler::createNew();
	//env = BasicUsageEnvironment::createNew(*scheduler);
	//RTSPServer * rtspServer = RTSPServer::createNew(*env, 6002, auThDB);

	//添加用户访问控制（每增加一个客户端连接，就需要增加一条UserRecord）
	UserAuthenticationDatabase *auThDB = NULL;
#ifdef ACCESS_CONTROL
	authDB = new UserAuthenticationDatabase;
	authDB->addUserRecord("system", "system"); // replace these with real strings
#endif

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

int WINAPI CRelayRTSPDlg::OnStreamDataCallBack(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context)
{
	return ((CRelayRTSPDlg*)context)->OnStreamData(hTmCC, pStreamInfo);
}

///************* 视频回调函数    ***********
//在回调函数中处理H.264数据帧
//每到达1个数据帧，则将此数据帧直接打包到RTSP服务器中
//注意H.264数据帧在SDK与RTSP中打包/解包的区别
// ********************
int CRelayRTSPDlg::OnStreamData(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo)
{
	//headRealStream = (tmAvInfo_t)pStreamHead;
	//TRACE(headRealStream.byStreamId);
	//收到视频数据
	if (0 == pStreamInfo->byFrameType)
	{
		TRACE("收到视频数据   类型:%d，流ID：%d\n", pStreamInfo->byStreamNo, pStreamInfo->dwStreamId);

		//加入视频帧到RTSP服务器数据缓冲区（如何确定不同通道来的视频流？？）
		switch (nNVRChannel)
		{
		default:
			break;
		}
	}

	//收到音频数据
	if (1 == pStreamInfo->byFrameType)
	{
		TRACE("收到音频数据类型:%d，流ID：%d\n", pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);
	}

	//收到数据流头
	if (2 == pStreamInfo->byFrameType)
	{
		TRACE("收到数据流头:%d帧\n", pStreamInfo->byFrameType);
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRelayRTSPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//释放NVR资源
	TMCC_Done(hRealStream);
	hRealStream = NULL;

	//释放RTSP服务资源
	//BasicTaskScheduler::

	if (False == env->reclaim())
	{
		AfxMessageBox("RTSP服务内存资源释放错误");
	}
	CDialogEx::OnClose();
}

void CRelayRTSPDlg::On_Click_LoadIniFile()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlgFile(true);
	dlgFile.DoModal();
}
