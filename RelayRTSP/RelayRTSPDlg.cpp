
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
: CDialogEx(CRelayRTSPDlg::IDD, pParent), env(NULL)
, m_nNVRChannel(0), hLogin(NULL),m_hPlay(NULL)
, m_strNVRIPAddress(_T("")), m_pFileList(NULL),m_iImageWidth(0),m_iImageHeight(0)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
	ON_MESSAGE(WM_PLAYSTATE, OnPlayStateMessage)
END_MESSAGE_MAP()


static void announceStream(RTSPServer* rtspServer, ServerMediaSession* sms, char const*
	streamName)//��ʾRTSP������Ϣ
{
	char* url = rtspServer->rtspURL(sms);
	UsageEnvironment& env = rtspServer->envir();
	env << streamName << "\n";
	env << "Play this stream using the URL \"" << url << "\"\n";
	delete[] url;
}

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


	//�����ʼ��
	((CButton*)GetDlgItem(IDC_DISCONNECT))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_SEARCH_FILE))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_START_RTSP))->EnableWindow(false);
	//DWORD dwStyle = m_listFile.GetStyle();
	m_listFile.SetExtendedStyle(m_listFile.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	m_listFile.InsertColumn(0, "�ļ��б�", LVCFMT_LEFT, 500, 0);

	//��ȡĬ�ϵ�ini�ļ�������NVR��RTSP����
	m_tNVRLogin.nPort = ::GetPrivateProfileInt("global", "port", 6002, "./NVR_Config.ini");
	m_tNVRLogin.nChannelCount = ::GetPrivateProfileInt("global", "camera_Channel_Count", 12, "./NVR_Config.ini");
	char ss[128];
	::GetPrivateProfileString("global", "IP", "192.168.1.122", ss, 128, "./NVR_Config.ini");
	m_tNVRLogin.strIP.Format("%s", ss);
	::GetPrivateProfileString("global", "user_name", "system", ss, 128, "./NVR_Config.ini");
	m_tNVRLogin.strName.Format("%s", ss);
	::GetPrivateProfileString("global", "user_password", "system", ss, 128, "./NVR_Config.ini");
	m_tNVRLogin.strPassword.Format("%s", ss);
	::GetPrivateProfileString("global", "TYPE", "1600*1200", ss, 128, "./NVR_Config.ini");
	m_tNVRLogin.strVideoType.Format("%s", ss);

	//���ó�ʼIP
	m_strNVRIPAddress = m_tNVRLogin.strIP;
	((CEdit*)(GetDlgItem(IDC_NVR_IPADDRESS1)))->SetWindowTextA(m_strNVRIPAddress);

	//��ʼ��ͨ����
	m_combNVRChannel.ResetContent();
	//((CComboBox*)GetDlgItem(IDC_NVRCHANNEL))->ResetContent();
	CString strTemp = "";
	for (int i = 0; i <= m_tNVRLogin.nChannelCount; i++)
	{
		strTemp.Format("%d", i);
		m_combNVRChannel.InsertString(-1, strTemp);
	}
	m_combNVRChannel.SetCurSel(0);
	m_combNVRChannel.UpdateData(TRUE);


	// ��NVR
	if (NULL == hLogin)
	{
		hLogin = TMCC_Init(TMCC_INITTYPE_CONTROL);
	}
	else
	{
		TMCC_DisConnect(hLogin);
	}

	//��ʼ��RTSP����
	reuseFirstSource = False;
	scheduler = BasicTaskScheduler::createNew();
	env = BasicUsageEnvironment::createNew(*scheduler);

	//����û����ʿ��ƣ�ÿ����һ���ͻ������ӣ�����Ҫ����һ��UserRecord��
	UserAuthenticationDatabase *auThDB = NULL;
#ifdef ACCESS_CONTROL
	authDB = new UserAuthenticationDatabase;
	authDB->addUserRecord("system", "system"); // replace these with real strings
#endif
	RTSPServer * rtspServer = RTSPServer::createNew(*env, 8002, auThDB);
	if (rtspServer == NULL) {
		*env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
		return false;
	}

	//��ʼ�����ݻ�����
	databuf = (unsigned char*)malloc(1024 * 1024);

	//�������ݲ���������
	ServerMediaSession* sms = ServerMediaSession::createNew(*env, streamName,
		streamName, descriptionString);
	sms->addSubsession(H264LiveVideoServerMediaSubssion::createNew(*env, reuseFirstSource,
		&datasize, databuf, &dosent));//�޸�Ϊ�Լ�ʵ�ֵ�H264LiveVideoServerMediaSubssion
	rtspServer->addServerMediaSession(sms);
	announceStream(rtspServer, sms, streamName);//��ʾ�û�����������Ϣ
	//	env->taskScheduler().doEventLoop(); //ѭ���ȴ�����	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//��½�ص�����
int WINAPI	CRelayRTSPDlg::OnLoginCallBack(HANDLE hTmCC, BOOL bConnect, unsigned int dwResult, void *context)
{
	return 0;
}

///************* ��Ƶ�ص�������    ***********
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
		TRACE("�յ���Ƶ����   ֡���ͣ�%d,������:%d�������ͣ�%d,��ID��%d\n", pStreamInfo->byFrameType, pStreamInfo->byStreamNo,
			pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);

		//������Ƶ֡��RTSP���������ݻ����������ȷ����ͬͨ��������Ƶ��������
	}

	//�յ���Ƶ����
	if (1 == pStreamInfo->byFrameType)
	{
		TRACE("�յ���Ƶ��������:%d����ID��%d\n", pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);
	}

	//�յ�������ͷ
	if (2 == pStreamInfo->byFrameType)
	{
		//		TRACE("�յ�������ͷ:%d֡\n", pStreamInfo->byFrameType);
		TRACE("�յ�������ͷ:֡���ͣ�%d,�����ţ�%d��������ţ�%d��������:%d����ID:%d\n", pStreamInfo->byFrameType,
			pStreamInfo->dwStreamId, pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);
		memcpy(pStreamHead, pStreamInfo->pBuffer, pStreamInfo->iBufferSize);
		//nStreamHeadSize = pStreamInfo->iBufferSize;
		//		pStreamHead = (tmAvInfo_t*)pStreamHead;
		//TRACE("�յ�������ͷ:�����ţ�%d֡��������ţ�%d��������:%d����ID:%d\n", (tmAvInfo_t)pStreamHead->dwStreamId,
		//	pStreamHead->byVideoIndex);

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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
HCURSOR CRelayRTSPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//����sink�û�����
void CRelayRTSPDlg::startReplicaFileSink(StreamReplicator* replicator, char const* outputFileName)
{
	// Begin by creating an input stream from our replicator:
	FramedSource* source = replicator->createStreamReplica();

	// Then create a 'file sink' object to receive thie replica stream:
	MediaSink* sink = FileSink::createNew(*env, outputFileName);

	// Now, start playing, feeding the sink object from the source:
	sink->startPlaying(*source, NULL, NULL);
}

//����UDP����
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

//�˳�
void CRelayRTSPDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//�ͷ�NVR��Դ
	TMCC_CloseFile(m_hPlay);
	m_hPlay = NULL;
	TMCC_Done(hLogin);
	hLogin = NULL;

	//�ͷ�RTSP������Դ
	//BasicTaskScheduler::
	if (NULL != env)
	{
		if (False == env->reclaim())
		{
			AfxMessageBox("RTSP�����ڴ���Դ�ͷŴ���");
		}
	}
	CDialogEx::OnClose();
}

//���ӵ�NVR
void CRelayRTSPDlg::OnClickedConnectToNVR()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	memset(&tmLogin, 0, sizeof(tmConnectInfo_t));
	tmLogin.dwSize = sizeof(tmConnectCfg_t);
	tmLogin.iPort = m_tNVRLogin.nPort;
	strcpy(tmLogin.pIp, m_strNVRIPAddress);
	sprintf(tmLogin.szUser, m_tNVRLogin.strName);
	sprintf(tmLogin.szPass, m_tNVRLogin.strPassword);
	//�������ӳ�ʱֵ
	TMCC_SetTimeOut(hLogin, 3000);
	//ע���¼״̬�ص�
	TMCC_RegisterConnectCallBack(hLogin, OnLoginCallBack, this);
	if (TMCC_ERR_SUCCESS != TMCC_Connect(hLogin, &tmLogin, FALSE))
	{
		//��¼ʧ��
		MessageBox("����NVR�豸ʧ��!");
		return;
	}

	((CStatic*)(GetDlgItem(IDC_STATUS)))->SetWindowTextA("���ӳɹ�\n" + m_strNVRIPAddress);
	((CButton*)GetDlgItem(IDC_DISCONNECT))->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_CONNECT))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_SEARCH_FILE))->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_START_RTSP))->EnableWindow(true);
}

//��NVR�Ͽ�
void CRelayRTSPDlg::OnClickedDisconnectFromNVR()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (NULL != hLogin)
	{
		if (TMCC_ERR_SUCCESS == TMCC_DisConnect(hLogin))
		{
			((CStatic*)(GetDlgItem(IDC_STATUS)))->SetWindowTextA("�Ͽ��ɹ�\n" + m_strNVRIPAddress);
			((CButton*)GetDlgItem(IDC_DISCONNECT))->EnableWindow(false);
			((CButton*)GetDlgItem(IDC_CONNECT))->EnableWindow(true);
			((CButton*)GetDlgItem(IDC_SEARCH_FILE))->EnableWindow(false);
			((CButton*)GetDlgItem(IDC_START_RTSP))->EnableWindow(false);
		}
	}
}

//����NVR�ļ�
void CRelayRTSPDlg::OnClickedSearchFile()
{
	//�����ļ���������
	AfxBeginThread(FileSearchProc, this);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

//����RTSP����
void CRelayRTSPDlg::OnClickedStartRtsp()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString					str;
	int						index, iRet;
	int						count;
	BOOL					bCancel = FALSE;
	tmPlayConditionCfg_t	struCond;
	FileList_t*				pFileList;
	tmTimeInfo_t*			pTime;
	SYSTEMTIME				time;
	BYTE*					buffer = new BYTE[1600 * 1200];
	if (NULL != m_hPlay)
	{
		TMCC_CloseFile(m_hPlay);
		m_hPlay = NULL;
	}

	//��ȡѡ���ļ������
	m_listFile.ScreenToClient(&ptFile);
	index = m_listFile.HitTest(ptFile);
	if (index < 0)
	{
		AfxMessageBox("δѡ���ļ�");//û��ѡ���ļ�
		return;
	}

	//��ȡ�ļ���Ϣ
	pFileList = (FileList_t*)m_listFile.GetItemData(index);
	if (pFileList == NULL)
	{
		AfxMessageBox("ϵͳ����");//ϵͳ����
		return;
	}

	memset(&struCond, 0, sizeof(tmPlayConditionCfg_t));
	struCond.dwSize = sizeof(tmPlayConditionCfg_t);
	struCond.wFactoryId = pFileList->file.wFactoryId;
	struCond.byChannel = pFileList->file.byChannel;
	struCond.byPlayImage = FALSE;
	struCond.byBufferBeforePlay = FALSE;
	struCond.dwBufferSizeBeforePlay = 1600 * 1200 * 20;
	struCond.info.time.byBackupData = pFileList->file.byBackupData;
	struCond.info.time.byDiskName = pFileList->file.byDiskName;
	struCond.info.time.byCheckStopTime = FALSE;
	struCond.info.time.struStartTime = pFileList->file.struStartTime;
	struCond.info.time.struStopTime = pFileList->file.struStopTime;
	struCond.info.time.byAlarmType = pFileList->file.byAlarmType;
	struCond.info.time.byFileFormat = pFileList->file.byFileFormat;
	struCond.info.time.dwServerPort = m_tNVRLogin.nPort;
	struCond.byEnableServer = FALSE;
	struCond.fnStreamReadCallBack = fnDataCallBack;
	struCond.fnStreamReadContext = this;
	struCond.byPlayType = REMOTEPLAY_MODE_BUFFILE;//  REMOTEPLAY_MODE_READFILE
	sprintf(struCond.info.time.sServerAddress, "%s", m_tNVRLogin.strIP);
	sprintf(struCond.info.time.sUserName, "%s", m_tNVRLogin.strName);
	sprintf(struCond.info.time.sUserPass, "%s", m_tNVRLogin.strPassword);

	m_hPlay = TMCC_OpenFile(hLogin, &struCond, ((CStatic*)(GetDlgItem(IDC_STATUS)))->GetSafeHwnd());
	if (NULL == m_hPlay)
	{
		MessageBox("�ļ���ʧ��");
		return;
	}

	//�����ļ�
	tmPlayControlCfg_t cfg;
	memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
	cfg.dwSize = sizeof(tmPlayControlCfg_t);
	cfg.dwCommand = PLAY_CONTROL_PLAY;
	TMCC_ControlFile(m_hPlay, &cfg);

	//ע����Ϣ
	TMCC_GetImageSize(m_hPlay, &m_iImageWidth, &m_iImageHeight);
//	TMCC_RegisterConnectMessage(m_hPlay, GetSafeHwnd(), WM_PLAYSTATE);
}

//����״̬�ص�����
LRESULT CRelayRTSPDlg::OnPlayStateMessage(WPARAM wParam, LPARAM lParam)
{
	TRACE("wParam = %d,lParam = %d\n", wParam, lParam);
	return 0;
}

//Զ���ļ���ȡ�ص�����
int WINAPI CRelayRTSPDlg::fnDataCallBack(HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void *context)
{
	return ((CRelayRTSPDlg*)context)->OnStreamData(hTmCC, pStreamInfo);

	//if (0 == pStreamInfo->byFrameType)
	//{
	//	TRACE("�յ���Ƶ����   ֡���ͣ�%d,������:%d�������ͣ�%d,��ID��%d\n", pStreamInfo->byFrameType, pStreamInfo->byStreamNo,
	//		pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);

	//	//������Ƶ֡��RTSP���������ݻ����������ȷ����ͬͨ��������Ƶ��������
	//}

	////�յ���Ƶ����
	//if (1 == pStreamInfo->byFrameType)
	//{
	//	TRACE("�յ���Ƶ��������:%d����ID��%d\n", pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);
	//}

	////�յ�������ͷ
	//if (2 == pStreamInfo->byFrameType)
	//{
	//	//		TRACE("�յ�������ͷ:%d֡\n", pStreamInfo->byFrameType);
	//	TRACE("�յ�������ͷ:֡���ͣ�%d,�����ţ�%d��������ţ�%d��������:%d����ID:%d\n", pStreamInfo->byFrameType,
	//		pStreamInfo->dwStreamId, pStreamInfo->dwStreamTag, pStreamInfo->dwStreamId);
	//	memcpy(pStreamHead, pStreamInfo->pBuffer, pStreamInfo->iBufferSize);
	//	//nStreamHeadSize = pStreamInfo->iBufferSize;
	//	//		pStreamHead = (tmAvInfo_t*)pStreamHead;
	//	//TRACE("�յ�������ͷ:�����ţ�%d֡��������ţ�%d��������:%d����ID:%d\n", (tmAvInfo_t)pStreamHead->dwStreamId,
	//	//	pStreamHead->byVideoIndex);

	//}
	return 0;
}

//�ļ������̺߳���
UINT CRelayRTSPDlg::FileSearchProc(void* lpThis)
{
	return ((CRelayRTSPDlg*)lpThis)->FileSearchProcLoop(0);
}

//�ļ���������
UINT CRelayRTSPDlg::FileSearchProcLoop(int iControlType)
{
	int						iRet;
	CString					str;
	tmFindConditionCfg_t	cond;
	tmFindFileCfg_t			file;
	SYSTEMTIME				time;
	HANDLE					hSearch = NULL;

	m_listFile.DeleteAllItems();

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
	cond.dwServerPort = m_tNVRLogin.nPort;
	sprintf(cond.sServerAddress, "%s", m_strNVRIPAddress);
	sprintf(cond.sUserName, "%s", m_tNVRLogin.strName);
	sprintf(cond.sUserPass, "%s", m_tNVRLogin.strPassword);
	hSearch = TMCC_FindFirstFile(hLogin, &cond, &file);
	if (hSearch == NULL)
	{
		AfxMessageBox("do not have video file");//û��¼���ļ�
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
		tmTimeInfo_t	struTail;

		while (pNext->next != NULL)
		{
			pNext = pNext->next;
		}
	}


	return TRUE;
}

//��������������б�
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

	return pNew;
}

//��굥���ļ��б���Ϣ��Ӧ����
void CRelayRTSPDlg::OnClickFileList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetCursorPos(&ptFile);
	*pResult = 0;
}
