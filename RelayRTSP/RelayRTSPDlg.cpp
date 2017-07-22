
// RelayRTSPDlg.cpp : 实现文件
//
//#include<vector>
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
: CDialogEx(CRelayRTSPDlg::IDD, pParent), env(NULL), auThDB(NULL), rtspServer(NULL), sms(NULL)
, m_nNVRChannel(0), hLogin(NULL), m_hPlay(NULL)
, m_strNVRIPAddress(_T("")), m_pFileList(NULL), m_iImageWidth(0), m_iImageHeight(0)
, pStreamHead(NULL), pRtspThread(NULL)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_TRAY);
}

void CRelayRTSPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_NVRCHANNEL, m_nNVRChannel);
	DDV_MinMaxInt(pDX, m_nNVRChannel, 0, 31);
	DDX_Control(pDX, IDC_NVRCHANNEL, m_combNVRChannel);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_ctrlDateStart);
	DDX_Control(pDX, IDC_DATETIMEPICKER3, m_ctrlTimeStart);
	DDX_Control(pDX, IDC_DATETIMEPICKER4, m_ctrlDateEnd);
	DDX_Control(pDX, IDC_DATETIMEPICKER5, m_ctrlTimeEnd);
	DDX_Control(pDX, IDC_FILELIST, m_listFile);
	DDX_Text(pDX, IDC_NVR_IPADDRESS1, m_strNVRIPAddress);
}

BEGIN_MESSAGE_MAP(CRelayRTSPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CONNECT, &CRelayRTSPDlg::OnClickedConnectToNVR)
	ON_BN_CLICKED(IDC_DISCONNECT, &CRelayRTSPDlg::OnClickedDisconnectFromNVR)
	ON_BN_CLICKED(IDC_SEARCH_FILE, &CRelayRTSPDlg::OnClickedSearchFile)
	ON_BN_CLICKED(IDC_START_RTSP, &CRelayRTSPDlg::OnClickedStartRtsp)
	ON_NOTIFY(NM_CLICK, IDC_FILELIST, &CRelayRTSPDlg::OnClickFileList)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

static void announceStream(RTSPServer* rtspServer, ServerMediaSession* sms, char const*
	streamName)//显示RTSP连接信息
{
	char* url = rtspServer->rtspURL(sms);
	UsageEnvironment& env = rtspServer->envir();
	env << streamName << "\n";
	env << "Play this stream using the URL \"" << url << "\"\n";
	delete[] url;
}

// CRelayRTSPDlg 消息处理程序

LRESULT CRelayRTSPDlg::OnReceiveFrame(WPARAM w, LPARAM p)
{
	return 0;
}


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

	//设置搜索的起止时间
	m_ctrlDateStart.SetTime(new CTime(2017, 4, 12, 14, 00, 00));
	m_ctrlTimeStart.SetTime(new CTime(2017, 4, 12, 14, 00, 00));
	m_ctrlDateEnd.SetTime(new CTime(2017, 4, 12, 20, 00, 00));
	m_ctrlTimeEnd.SetTime(new CTime(2017, 4, 12, 20, 00, 00));

	//界面初始化
	((CButton*)GetDlgItem(IDC_DISCONNECT))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_SEARCH_FILE))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_START_RTSP))->EnableWindow(false);
	//DWORD dwStyle = m_listFile.GetStyle();
	m_listFile.SetExtendedStyle(m_listFile.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	m_listFile.InsertColumn(0, "文件列表", LVCFMT_LEFT, 500, 0); 

	//读取默认的ini文件，配置NVR和RTSP服务
	char ss[128];
	m_tNVRLogin.nRtspServerPort = ::GetPrivateProfileInt("RTSP", "server_port", 8554, "./RTSP.ini");

	::GetPrivateProfileString("NVR", "TYPE", "D1", ss, 128, "./RTSP.ini");
	m_tNVRLogin.strVideoType.Format("%s", ss);
	::GetPrivateProfileString("NVR", "nvr_IP", "192.168.1.125", ss, 128, "./RTSP.ini");
	m_tNVRLogin.strNVR_IP.Format("%s", ss);
	m_tNVRLogin.nCountVideoChannel = ::GetPrivateProfileInt("NVR", "camera_Count", -1, "./RTSP.ini");
	m_tNVRLogin.nNVRPort = ::GetPrivateProfileInt("NVR", "nvr_port", 6002, "./RTSP.ini");
	::GetPrivateProfileString("NVR", "user_name", "system", ss, 128, "./RTSP.ini");
	m_tNVRLogin.strUserName.Format("%s", ss);
	::GetPrivateProfileString("NVR", "user_password", "system", ss, 128, "./RTSP.ini");
	m_tNVRLogin.strUserPassword.Format("%s", ss);
	//设置初始IP
	m_strNVRIPAddress = m_tNVRLogin.strNVR_IP;
	((CEdit*)(GetDlgItem(IDC_NVR_IPADDRESS1)))->SetWindowTextA(m_strNVRIPAddress);
	sprintf_s(ss,"本rtsp服务端口号:%d", m_tNVRLogin.nRtspServerPort);
	((CStatic*)GetDlgItem(IDC_STATUS))->SetWindowTextA(ss);

	//初始化通道号
	m_combNVRChannel.ResetContent();
	//((CComboBox*)GetDlgItem(IDC_NVRCHANNEL))->ResetContent();
	CString strTemp = "";
	for (int i = 0; i <= m_tNVRLogin.nCountVideoChannel; i++)
	{
		strTemp.Format("%d", i);
		m_combNVRChannel.InsertString(-1, strTemp);
	}
	m_combNVRChannel.SetCurSel(0);
	m_combNVRChannel.UpdateData(TRUE);


	// 打开NVR
	if (NULL == hLogin)
	{
		hLogin = TMCC_Init(TMCC_INITTYPE_CONTROL);
	}
	else
	{
		TMCC_DisConnect(hLogin);
	}

	//初始化RTSP服务
	//	pStreamHead = new BYTE[STREAM_HEAD_SIZE];
	reuseFirstSource = False;
	scheduler = BasicTaskScheduler::createNew();
	//	scheduler = GuiTaskScheduler::createNew();
	env = BasicUsageEnvironment::createNew(*scheduler);

	auThDB = new UserAuthenticationDatabase;
	auThDB->addUserRecord("system", "system"); // replace these with real strings

#ifdef ACCESS_CONTROL
	authDB = new UserAuthenticationDatabase;
	authDB->addUserRecord("system", "system"); // replace these with real strings
#endif
	rtspServer = RTSPServer::createNew(*env, 8002, auThDB);
	if (rtspServer == NULL) {
		*env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
		return false;
	}

	//初始化数据缓冲区
	databuf = (unsigned char*)malloc(1024 * 1024);

	//加入数据并启动服务
	//ServerMediaSession* sms = ServerMediaSession::createNew(*env, streamName,
	//	streamName, descriptionString);
	//sms->addSubsession(H264LiveVideoServerMediaSubssion::createNew(*env, reuseFirstSource,
	//	&datasize, databuf, &dosent));//修改为自己实现的H264LiveVideoServerMediaSubssion
	//rtspServer->addServerMediaSession(sms);
	//announceStream(rtspServer, sms, streamName);//提示用户输入连接信息
	//env->taskScheduler().doEventLoop(); //循环等待连接	(放入到线程中去)
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

UINT CRelayRTSPDlg::ThreadRTSPEvent(void* context)
{
	return ((CRelayRTSPDlg*)context)->RTSPEvent();
}

UINT CRelayRTSPDlg::RTSPEvent()
{
	env->taskScheduler().doEventLoop();
	return TRUE;
}

void CRelayRTSPDlg::AddToRtspServer(UsageEnvironment* u_env, RtspServer_t serv)
{
	//添加用户访问控制（每增加一个客户端连接，就需要增加一条UserRecord）
	UserAuthenticationDatabase *auThDB = NULL;
#ifdef ACCESS_CONTROL
	authDB = new UserAuthenticationDatabase;
	authDB->addUserRecord("system", "system"); // replace these with real strings
#endif
	rtspServer = RTSPServer::createNew(*env, 8002, auThDB);
	if (rtspServer == NULL) {
		*env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
		return;
	}

	//初始化数据缓冲区
	databuf = (unsigned char*)malloc(1024 * 1024);

	//加入数据并启动服务
	ServerMediaSession* sms = ServerMediaSession::createNew(*env, streamName,
		streamName, descriptionString);
	sms->addSubsession(H264LiveVideoServerMediaSubssion::createNew(*env, reuseFirstSource,
		&datasize, databuf, &dosent));//修改为自己实现的H264LiveVideoServerMediaSubssion
	rtspServer->addServerMediaSession(sms);
	announceStream(rtspServer, sms, streamName);//提示用户输入连接信息
	//	env->taskScheduler().doEventLoop(); //循环等待连接	

}


//登陆回调函数
int WINAPI	CRelayRTSPDlg::OnLoginCallBack(HANDLE hTmCC, BOOL bConnect, unsigned int dwResult, void *context)
{
	return 0;
}

///************* 视频回调处理函数    ***********
//在回调函数中处理H.264数据帧
//每到达1个数据帧，则将此数据帧直接打包到RTSP服务器中
//注意H.264数据帧在SDK与RTSP中打包/解包的区别
// ********************/
int CRelayRTSPDlg::OnStreamData(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo)
{
	//headRealStream = (tmAvInfo_t)pStreamHead;
	//TRACE(headRealStream.byStreamId);
	unsigned int nStreamType = 0, nFrameLength = 0;
	//收到视频数据
	if (0 == pStreamInfo->byFrameType)
	{
		//TRACE("收到视频数据   帧类型：%d,buffer1:%d，buffer2：%d,buffer3：%d,buffer4:%d\n", pStreamInfo->byFrameType, pStreamInfo->iBufferSize,
		//	pStreamInfo->iBuffer2Size, pStreamInfo->iBuffer3Size, pStreamInfo->iBuffer4Size);

		//加入视频帧到RTSP服务器数据缓冲区（如何确定不同通道来的视频流？？）
		memcpy(&nStreamType, pStreamInfo->pBuffer, 4);
		memcpy(&nFrameLength, pStreamInfo->pBuffer + 4, 4);
		TRACE("流类型：0x%x-%d,帧长度:%d\n", nStreamType, nStreamType, nFrameLength);

		//拷贝数据到RTSP服务的缓冲区
		memcpy(&datasize, pStreamInfo->pBuffer + 4, 4);
		memcpy(databuf, pStreamInfo->pBuffer + 8, datasize);
	}

	////收到音频数据
	//if (1 == pStreamInfo->byFrameType)
	//{
	//	TRACE("收到音频数据类型:%d，流ID：%d\n", pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);
	//}

	////收到数据流头
	//if (2 == pStreamInfo->byFrameType)
	//{
	//	//		TRACE("收到数据流头:%d帧\n", pStreamInfo->byFrameType);
	//	TRACE("收到数据流头:帧类型：%d,码流号：%d，码流序号：%d，流类型:%d，流ID:%d\n", pStreamInfo->byFrameType,
	//		pStreamInfo->dwStreamId, pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);
	//	memcpy(pStreamHead, pStreamInfo->pBuffer, pStreamInfo->iBufferSize);
	//	//nStreamHeadSize = pStreamInfo->iBufferSize;
	//	//		pStreamHead = (tmAvInfo_t*)pStreamHead;
	//	//TRACE("收到数据流头:码流号：%d帧，码流序号：%d，流类型:%d，流ID:%d\n", (tmAvInfo_t)pStreamHead->dwStreamId,
	//	//	pStreamHead->byVideoIndex);

	//}

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

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CRelayRTSPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//启动sink用户服务
void CRelayRTSPDlg::startReplicaFileSink(StreamReplicator* replicator, char const* outputFileName)
{
	// Begin by creating an input stream from our replicator:
	FramedSource* source = replicator->createStreamReplica();

	// Then create a 'file sink' object to receive thie replica stream:
	MediaSink* sink = FileSink::createNew(*env, outputFileName);

	// Now, start playing, feeding the sink object from the source:
	sink->startPlaying(*source, NULL, NULL);
}

//启动UDP服务
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

//退出
void CRelayRTSPDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	////释放NVR资源
	//if (NULL != m_hPlay)
	//{
	//	TMCC_CloseFile(m_hPlay);
	//	m_hPlay = NULL;
	//}
	//if (NULL != hLogin)
	//{
	//	TMCC_Done(hLogin);
	//	hLogin = NULL;
	//}

	////释放RTSP服务资源
	////BasicTaskScheduler::
	//if (NULL != env)
	//{
	//	if (False == env->reclaim())
	//	{
	//		AfxMessageBox("RTSP服务内存资源释放错误");
	//	}
	//}

	//if (NULL != pStreamHead)
	//{
	//	delete pStreamHead;
	//	pStreamHead = NULL;
	//}
	CDialogEx::OnClose();
}

//连接到NVR
void CRelayRTSPDlg::OnClickedConnectToNVR()
{
	// TODO:  在此添加控件通知处理程序代码
	memset(&tmLogin, 0, sizeof(tmConnectInfo_t));
	tmLogin.dwSize = sizeof(tmConnectCfg_t);
	tmLogin.iPort = m_tNVRLogin.nRtspServerPort;
	strcpy(tmLogin.pIp, m_strNVRIPAddress);
	sprintf(tmLogin.szUser, m_tNVRLogin.strUserName);
	sprintf(tmLogin.szPass, m_tNVRLogin.strUserPassword);
	//设置连接超时值
	TMCC_SetTimeOut(hLogin, 3000);
	//注册登录状态回调
	TMCC_RegisterConnectCallBack(hLogin, OnLoginCallBack, this);
	if (TMCC_ERR_SUCCESS != TMCC_Connect(hLogin, &tmLogin, FALSE))
	{
		//登录失败
		MessageBox("连接NVR设备失败!");
		return;
	}

	((CStatic*)(GetDlgItem(IDC_STATUS)))->SetWindowTextA("连接成功\n" + m_strNVRIPAddress);
	((CButton*)GetDlgItem(IDC_DISCONNECT))->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_CONNECT))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_SEARCH_FILE))->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_START_RTSP))->EnableWindow(true);
}

//从NVR断开
void CRelayRTSPDlg::OnClickedDisconnectFromNVR()
{
	// TODO:  在此添加控件通知处理程序代码
	if (NULL != hLogin)
	{
		if (TMCC_ERR_SUCCESS == TMCC_DisConnect(hLogin))
		{
			((CStatic*)(GetDlgItem(IDC_STATUS)))->SetWindowTextA("断开成功\n" + m_strNVRIPAddress);
			((CButton*)GetDlgItem(IDC_DISCONNECT))->EnableWindow(false);
			((CButton*)GetDlgItem(IDC_CONNECT))->EnableWindow(true);
			((CButton*)GetDlgItem(IDC_SEARCH_FILE))->EnableWindow(false);
			((CButton*)GetDlgItem(IDC_START_RTSP))->EnableWindow(false);
		}
	}
}

//搜索NVR文件
void CRelayRTSPDlg::OnClickedSearchFile()
{
	//启动文件搜索服务
	AfxBeginThread(FileSearchProc, this);
	// TODO:  在此添加控件通知处理程序代码
}

//启动RTSP服务
void CRelayRTSPDlg::OnClickedStartRtsp()
{
	// TODO:  在此添加控件通知处理程序代码

	/*  参考RemoteTurnPlayer的代码
	//CString					str;
	//int						index;
	//BOOL					bCancel = FALSE;
	//tmPlayConditionCfg_t	struCond;
	//FileList_t*				pFileList;

	////防止重复打开
	//if (m_hPlay != NULL)
	//{
	//	::Avdec_CloseFile(m_hPlay);
	//	m_hPlay = NULL;
	//}

	////获取当前选中的文件
	//m_listFile.ScreenToClient(&ptFile);
	//index = m_listFile.HitTest(ptFile);
	//if (index < 0)
	//{
	//	AfxMessageBox("not select file");//没有选择文件
	//	return;
	//}
	//pFileList = (FileList_t*)m_listFile.GetItemData(index);
	//if (pFileList == NULL)
	//{
	//	AfxMessageBox("未选中任何文件");//系统错误
	//	return;
	//}

	//memset(&struCond, 0, sizeof(tmPlayConditionCfg_t));
	//struCond.dwSize = sizeof(tmPlayConditionCfg_t);
	//struCond.wFactoryId = pFileList->file.wFactoryId;
	//struCond.byChannel = pFileList->file.byChannel;
	//struCond.byPlayImage = FALSE;
	//struCond.byBufferBeforePlay = FALSE;
	//struCond.dwBufferSizeBeforePlay = 1024 * 1024 * 20;
	//struCond.info.time.byBackupData = pFileList->file.byBackupData;
	//struCond.info.time.byDiskName = pFileList->file.byDiskName;
	//struCond.info.time.byCheckStopTime = FALSE;
	//struCond.info.time.struStartTime = pFileList->file.struStartTime;// testTimeStart;//
	//struCond.info.time.struStopTime = pFileList->file.struStopTime;//testTimeEnd;//
	//struCond.info.time.byAlarmType = pFileList->file.byAlarmType;
	//struCond.info.time.byFileFormat = pFileList->file.byFileFormat;
	//struCond.info.time.dwServerPort = m_tNVRLogin.nPort;
	//struCond.byEnableServer = TRUE;
	//struCond.byPlayType = REMOTEPLAY_MODE_READFILE;//add by tzh
	//sprintf(struCond.info.time.sServerAddress, "%s", m_tNVRLogin.strIP);
	//sprintf(struCond.info.time.sUserName, "%s", m_tNVRLogin.strName);
	//sprintf(struCond.info.time.sUserPass, "%s", m_tNVRLogin.strPassword);

	//m_hPlay = ::Avdec_OpenFileA(hLogin, &struCond, NULL);
	//if (m_hPlay == NULL)
	//{
	//	AfxMessageBox("文件打开错误！");//打开文件错误
	//	return;
	//}

	////注销消息
	//::Avdec_GetImageSize(m_hPlay, &m_iImageWidth, &m_iImageHeight);
	//::Avdec_RegisterStateChangeMessage(m_hPlay, GetSafeHwnd(), WM_PLAYSTATE);
	//::Avdec_SetMute(m_hPlay, FALSE);
	//::Avdec_SetVolume(m_hPlay, 10000);
	//::Avdec_SetDisplayVisible(m_hPlay, TRUE);
	*/

	// 参考RemotePlayer的代码
	CString strRTSP = "";
	GetDlgItemText(IDC_START_RTSP, strRTSP);
	if ("启动RTSP服务" == strRTSP)
	{
		//启动服务
		CString					str;
		int						index;
		BOOL					bCancel = FALSE;
		tmPlayConditionCfg_t	struCond;
		FileList_t*				pFileList;

		//防止重复打开
		if (m_hPlay != NULL)
		{
			::Avdec_CloseFile(m_hPlay);
			m_hPlay = NULL;
		}

		//获取当前选中的文件
		m_listFile.ScreenToClient(&ptFile);
		index = m_listFile.HitTest(ptFile);
		if (index < 0)
		{
			AfxMessageBox("not select file");//没有选择文件
			return;
		}
		pFileList = (FileList_t*)m_listFile.GetItemData(index);
		if (pFileList == NULL)
		{
			AfxMessageBox("未选中任何文件");//系统错误
			return;
		}

		//配置参数
		memset(&struCond, 0, sizeof(tmPlayConditionCfg_t));
		struCond.dwSize = sizeof(tmPlayConditionCfg_t);
		struCond.wFactoryId = pFileList->file.wFactoryId;
		struCond.byChannel = pFileList->file.byChannel;
		struCond.byPlayImage = FALSE;
		struCond.byBufferBeforePlay = FALSE;
		struCond.dwBufferSizeBeforePlay = 1024 * 1024 * 20;
		struCond.info.time.byBackupData = pFileList->file.byBackupData;
		struCond.info.time.byDiskName = pFileList->file.byDiskName;
		struCond.info.time.byCheckStopTime = FALSE;
		struCond.info.time.struStartTime = pFileList->file.struStartTime;// testTimeStart;//
		struCond.info.time.struStopTime = pFileList->file.struStopTime;//testTimeEnd;//
		struCond.info.time.byAlarmType = pFileList->file.byAlarmType;
		struCond.info.time.byFileFormat = pFileList->file.byFileFormat;
		struCond.info.time.dwServerPort = m_tNVRLogin.nRtspServerPort;
		struCond.byEnableServer = TRUE;	//默认为FALSE
		struCond.fnStreamReadCallBack = fnDataCallBack;
		struCond.fnStreamReadContext = this;
		struCond.byPlayType = REMOTEPLAY_MODE_BUFFILE;//adjusted by tzh  REMOTEPLAY_MODE_READFILE
		sprintf(struCond.info.time.sServerAddress, "%s", m_tNVRLogin.strNVR_IP);
		sprintf(struCond.info.time.sUserName, "%s", m_tNVRLogin.strUserName);
		sprintf(struCond.info.time.sUserPass, "%s", m_tNVRLogin.strUserPassword);

		m_hPlay = TMCC_OpenFile(hLogin, &struCond, NULL);
		//m_hPlay = TMCC_OpenFile(hLogin, &struCond, ((CWnd*)GetDlgItem(IDC_STATUS))->GetSafeHwnd());	//测试用，HWnd为NULL时函数是否可用
		if (m_hPlay == NULL)
		{
			AfxMessageBox("文件打开错误！");//打开文件错误
			return;
		}

		//播放
		tmPlayControlCfg_t cfg;
		memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
		cfg.dwSize = sizeof(tmPlayControlCfg_t);
		cfg.dwCommand = PLAY_CONTROL_PLAY;
		::TMCC_ControlFile(m_hPlay, &cfg);

		//测试用
		//sms = ServerMediaSession::createNew(*env, streamName,
		//	streamName, descriptionString);
		//sms->addSubsession(H264LiveVideoServerMediaSubssion::createNew(*env, reuseFirstSource,
		//	&datasize, databuf, &dosent));//修改为自己实现的H264LiveVideoServerMediaSubssion
		//rtspServer->addServerMediaSession(sms);
		//str.Format("请用如下地址访问：%s\n", rtspServer->rtspURL(sms));

		//TRACE0(str);
		//((CStatic*)(GetDlgItem(IDC_STATUS)))->SetWindowTextA(str); rtsp://192.168.1.199:8002/h264ESVideoTest

		//
		int nCountNVR =  ::GetPrivateProfileInt("global", "port", 6002, "./NVR.ini");
		char ss[128];
		::GetPrivateProfileString("global", "IP", "192.168.1.122", ss, 128, "./NVR_Config.ini");
		

		//加入数据并启动服务(不同NVR服务器采用不同rtsp的码流号)
		for (int i = 0; i < m_listFile.GetItemCount(); i++)
		{
			sprintf(ss, "Stream-%d", i);	//码流号
			//sms = ServerMediaSession::createNew(*env, streamName,
			//	streamName, descriptionString);
			//sms->addSubsession(H264LiveVideoServerMediaSubssion::createNew(*env, reuseFirstSource,
			//	&datasize, databuf, &dosent));//修改为自己实现的H264LiveVideoServerMediaSubssion
			//rtspServer->addServerMediaSession(sms);
			str.Format("服务器:%s的通道%d请用如下地址访问：\n%s\\Stream%d", m_tNVRLogin.strNVR_IP, i, rtspServer->rtspURL(sms), i);

			((CStatic*)(GetDlgItem(IDC_STATUS)))->SetWindowTextA(str);
		}

		pRtspThread = AfxBeginThread(ThreadRTSPEvent, this);		//启动RTSP服务线程(循环响应消息)

		((CButton*)GetDlgItem(IDC_START_RTSP))->SetWindowTextA("停止RTSP服务");
	}
	else
	{
		sms = NULL;
		if (NULL != pRtspThread)
		{
			TerminateThread(pRtspThread->m_hThread, 0);	//结束消息响应线程
			pRtspThread = NULL;
		}
		((CButton*)GetDlgItem(IDC_START_RTSP))->SetWindowTextA("启动RTSP服务");
	}
	


	//TMCC_RegisterStreamCallBack(m_hPlay, fnDataCallBack, this);
}

//读取文件帧回调，任何返回<0标示文件播放完毕，0标示暂时没有读到文件，继续读取文件
//>0为读取的帧大小
int CRelayRTSPDlg::OnRemoteFileRead(HANDLE hObject, void* lpBuffer, int nRead, unsigned int* pdwCodeTag, int* pNeedBufSize, void* context)
{
	int				iResult, iFrameSize;
	RemoteFile_t*	pFile = (RemoteFile_t*)context;

	if (pFile == NULL)
	{
		iResult = -1;
		goto _exit;
	}

	if (pFile->hControl == NULL)
	{
		iResult = -2;
		goto _exit;
	}

	if (pFile->bFileFinish)
	{
		iResult = -3;
		goto _exit;
	}

	if (pFile->iFrameLen <= 0)
	{
		iResult = ::TMCC_ReadFile(pFile->hControl, pFile->pFrameBuffer, pFile->iFrameBufferLen);
		if (iResult < 0)
		{
			if (iResult == TMCC_ERR_MEMORY_OUT)
			{
				if (pFile->pFrameBuffer != NULL)
				{
					delete[] pFile->pFrameBuffer;
					pFile->pFrameBuffer = NULL;
				}
				pFile->iFrameBufferLen = 1024 * 1024;
				pFile->pFrameBuffer = new BYTE[pFile->iFrameBufferLen];
				iResult = ::TMCC_ReadFile(pFile->hControl, pFile->pFrameBuffer, pFile->iFrameBufferLen);
			}
		}
		if (iResult <= 0)
		{
			pFile->bFileFinish = TRUE;
			iResult = -4;
			goto _exit;
		}

		pFile->iFileCurrentPos++;//	+= iResult;//
		pFile->iFrameLen = iResult;
	}

	iFrameSize = pFile->iFrameLen - 8;
	if (nRead < iFrameSize)
	{
		if (pNeedBufSize != NULL)
		{
			*pNeedBufSize = iFrameSize;
		}
		iResult = 0;
		goto _exit;
	}

	//分析帧ID
	if (pdwCodeTag != NULL)
	{
		memcpy(pdwCodeTag, pFile->pFrameBuffer, 4);
	}

	//读取的缓冲需要去掉前8个字节
	if (iFrameSize > 0)
	{
		memcpy(lpBuffer, pFile->pFrameBuffer + 8, iFrameSize);
	}
	pFile->iFrameLen = 0;
	iResult = iFrameSize;

_exit:
	//	MESSAGE((0, 0, "OnRemoteFileRead  : %d, %.4s, iFrameSize=%d", iResult, (char*)pdwCodeTag, iFrameSize);)
	return iResult;
}

//设置文件位置
int CRelayRTSPDlg::OnRemoteFileSeek(HANDLE hObject, int offset, int origin, int* pPosition, unsigned int* pTimeStamp, void* context)
{
	int					iResult = 0, iPosition = 0;
	float				fTimeStamp = 0.0;
	unsigned int		dwTimeStamp = 0;
	tmPlayControlCfg_t	cfg;
	RemoteFile_t*		pFile = (RemoteFile_t*)context;

	if (pFile == NULL)
	{
		iResult = -1;
		goto _exit;
	}

	//检查是否读取当前位置
	if (origin == SEEK_CUR && offset == 0)
	{
		iResult = pFile->iFileCurrentPos;
		goto _exit;
	}

	//需要设置位置，单位帧位置
	if (pPosition != NULL)
	{
		iPosition = *pPosition;
	}
	else
	{
		iPosition = 0;
	}

	if (iPosition != 0)
	{
		iResult = iPosition;
		memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
		cfg.dwSize = sizeof(tmPlayControlCfg_t);
		//按时间SEEK
		cfg.dwCommand = PLAY_CONTROL_SEEKTIME;
		cfg.control.dwCurrentTime = *pTimeStamp;

		/* 按帧位置SEEK
		cfg.dwCommand = PLAY_CONTROL_SEEKPOS;
		cfg.control.iCurrentPosition = (int)iPosition;
		*/
		// pFile->iFileCurrentPos = 0;
		::TMCC_ControlFile(pFile->hControl, &cfg);
		//MESSAGE((0, 0, "OnRemoteFileSeek : ret=%d, iPosition=%d, TimeStamp=%d", iResult, iPosition, *pTimeStamp);)
	}

	//pFile->iFileCurrentPos = iPosition;
	iResult = 0;//iPosition;
_exit:

	return iResult;
}

//远程文件读取回调函数
int WINAPI CRelayRTSPDlg::fnDataCallBack(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context)
{
	return ((CRelayRTSPDlg*)context)->OnStreamData(hTmCC, pStreamInfo);
}

//文件搜索线程函数
UINT CRelayRTSPDlg::FileSearchProc(void* lpThis)
{
	return ((CRelayRTSPDlg*)lpThis)->FileSearchProcLoop(0);
}

//文件搜索函数
UINT CRelayRTSPDlg::FileSearchProcLoop(int iControlType)
{
	int						iRet;
	CString					str;
	tmFindConditionCfg_t	cond;
	tmFindFileCfg_t			file;
	SYSTEMTIME				time;
	HANDLE					hSearch = NULL;

	m_listFile.DeleteAllItems();	//清空原内容

	memset(&file, 0, sizeof(tmFindFileCfg_t));
	file.dwSize = sizeof(tmFindFileCfg_t);
	file.byFileFormat = 10;

	memset(&cond, 0, sizeof(tmFindConditionCfg_t));
	cond.dwSize = sizeof(tmFindConditionCfg_t);
	cond.byChannel = m_combNVRChannel.GetCurSel();
	cond.byFileType = 0xFF;
	cond.bySearchImage = 0;
	cond.bySearchAllTime = 0;
	m_ctrlDateStart.GetTime(&time);
	cond.struStartTime.wYear = time.wYear;
	cond.struStartTime.byMonth = time.wMonth;
	cond.struStartTime.byDay = time.wDay;
	m_ctrlTimeStart.GetTime(&time);
	cond.struStartTime.byHour = time.wHour;
	cond.struStartTime.byMinute = time.wMinute;
	cond.struStartTime.bySecond = time.wSecond;
	cond.struStartTime.dwMicroSecond = time.wMilliseconds;
	m_ctrlDateEnd.GetTime(&time);
	cond.struStopTime.wYear = time.wYear;
	cond.struStopTime.byMonth = time.wMonth;
	cond.struStopTime.byDay = time.wDay;
	m_ctrlTimeEnd.GetTime(&time);
	cond.struStopTime.byHour = time.wHour;
	cond.struStopTime.byMinute = time.wMinute;
	cond.struStopTime.bySecond = time.wSecond;
	cond.struStopTime.dwMicroSecond = time.wMilliseconds;
	cond.byEnableServer = 1;
	cond.byOldServer = TRUE;
	cond.byBackupData = FALSE;
	cond.dwServerPort = m_tNVRLogin.nRtspServerPort;
	sprintf(cond.sServerAddress, "%s", m_strNVRIPAddress);
	sprintf(cond.sUserName, "%s", m_tNVRLogin.strUserName);
	sprintf(cond.sUserPass, "%s", m_tNVRLogin.strUserPassword);
	hSearch = TMCC_FindFirstFile(hLogin, &cond, &file);
	if (hSearch == NULL)
	{
		AfxMessageBox("do not have video file");//没有录像文件
		return FALSE;
	}

	do
	{
		InsertList(&file, 0);
		iRet = ::TMCC_FindNextFile(hSearch, &file);
		if (iRet != TMCC_ERR_SUCCESS)
		{
			break;
		}
	} while (TRUE);

	::TMCC_FindCloseFile(hSearch);

	if (m_pFileList != NULL)
	{
		FileList_t*		pFirst = m_pFileList;
		FileList_t*		pNext = m_pFileList;

		while (pNext->next != NULL)
		{
			pNext = pNext->next;
		}
	}


	return TRUE;
}

//插入搜索结果到列表
FileList_t* CRelayRTSPDlg::InsertList(tmFindFileCfg_t* pFind, BOOL bImage)
{
	int			iCount = m_listFile.GetItemCount();
	FileList_t* pNew = new FileList_t;
	FileList_t*	pFirst = NULL;

	memset(pNew, 0, sizeof(FileList_t));
	pNew->file = *pFind;
	pNew->item = m_listFile.InsertItem(iCount, pFind->sFileName);
	//MessageBox(pFind->sFileName);
	pNew->bImage = bImage;
	m_listFile.SetItemData(pNew->item, (DWORD)pNew);

	if (m_pFileList == NULL)
	{
		m_pFileList = pNew;
	}
	else
	{
		pFirst = m_pFileList;
		while (pFirst)
		{
			if (pFirst->next == NULL)
			{
				pFirst->next = pNew;
				pNew->prev = pFirst;
				break;
			}
			pFirst = pFirst->next;
		}
	}

	//释放内存
	//if (NULL != pNew)
	//	delete pNew;
	//if (NULL != pFirst)
	//	delete pFirst;

	return pNew;
}

//鼠标单击文件列表消息响应函数
void CRelayRTSPDlg::OnClickFileList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	GetCursorPos(&ptFile);
	*pResult = 0;
}

void CRelayRTSPDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
	if (NULL != m_hPlay)
	{
		TMCC_CloseFile(m_hPlay);
		m_hPlay = NULL;
	}
	if (NULL != hLogin)
	{
		TMCC_Done(hLogin);
		hLogin = NULL;
	}

	//释放RTSP服务资源
	//BasicTaskScheduler::
	if (NULL != env)
	{
		if (False == env->reclaim())
		{
			TRACE0("RTSP服务内存资源释放错误");
			//AfxMessageBox();
			//OutputDebugStringA("RTSP服务内存资源释放错误");
		}
	}

	if (NULL != pStreamHead)
	{
		delete pStreamHead;
		pStreamHead = NULL;
	}

	//结束线程
	if (NULL != pRtspThread)
	{
		TerminateThread(pRtspThread->m_hThread, 0);	//结束消息响应线程
	}

}
