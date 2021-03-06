/***************************************************************************
								tmTransDefine.h
                             -------------------
    begin                :  2005.12.21
    copyright            : (C) 2005 by aipstar
 ***************************************************************************/

/***************************************************************************
 *  该文件为AS视频服务器，视频解码器客户端配置服务器结构定义文件		   *
 ***************************************************************************/

/*修改日志
 *2007-12-18
 *2009-05-19 添加设备的心跳包，这个心跳包支持我们的设备和所有模块
 *2010-04-44 在视频参数配置结构<tmPicPreviewCfg_t/tmPicModeScheduleInfo_t>中锐度变量
 *2011-11-11 支持超D1 960x576
*/

#ifndef __TMTRANSEDEFINE_H__
#define __TMTRANSEDEFINE_H__

/* 以下宏定义不能随便修改 */
#define IP_LEN					24
#define NAME_LEN 				32
#define SERIALNO_LEN 			48
#define MACADDR_LEN 			6
#define MAX_ETHERNET 			2
#define PATHNAME_LEN 			128
#define PASSWD_LEN 				32
#define MAX_CHANNUM 			64
#define MAX_ALARMOUT 			64
#define MAX_TIMESEGMENT			4
#define MAX_PRESET				256
#define MAX_DAYS 				7
#define MAX_WEEKNAME			20
#define PHONENUMBER_LEN			32
#define MAX_DISKNUM 			16
#define MAX_WINDOW 				16
#define MAX_VGA 				1
#define MAX_USERNUM 			16
#define MAX_EXCEPTIONNUM		16
#define MAX_LINK 				6
#define MAX_ALARMIN 			64
#define MAX_IRALARMIN 			8
#define MAX_VIDEOOUT 			4
#define MAX_NAMELEN				16		/*DVS本地登陆名*/
#define MAX_RIGHT				64		/*权限*/
#define CARDNUM_LEN 			20
#define DECODER_NAME_LEN		20
#define MAX_MOTIONAREANUM		5		/*移动区域个数*/
#define MAX_SERIALTRANS_LEN		128
#define MAX_CIRCLE_NUM			32
#define MAX_NTP_SERVERS			3		/*NTP服务器的最大个数*/
#define MAX_RS232NUM			6
#define CRUISE_MAX_LINE_NUMS	8
#define MAX_ALARMDEVICE			6		/*最大的报警设备*/
#define MAX_CIRCLECONNECTNUM	32		/*最大的循切数*/
#define MAX_WINDOWNUM 			16		/*最大解码通道数*/
#define MAX_SCHEDVIDEOINMODE	5		/*最大支持配置模式*/
#define MAX_FRAMERATE_NUM		25		/*最大支持帧率模式*/
#define COLOR_MODE_NUM			16
#define MAX_FLIRAREANUM			16		/*热像区域个数*/

/* 网络接口定义 */
#define NET_IF_AUTO				0
#define NET_IF_10M_HALF			1		/* 10M ethernet*/
#define NET_IF_10M_FULL			2
#define NET_IF_100M_HALF		3		/* 100M ethernet */
#define NET_IF_100M_FULL		4
#define NET_IF_1000M_HALF		5		/* 1000M ethernet */
#define NET_IF_1000M_FULL		6

/*设备型号(DVS类型)*/
#define DVS								3	/*视频服务器*/
#define DEC								4	/*标清解码器*/
#define HD_DEC							5	/*高清解码器*/
#define HD_NVR							6	/*高清NVR*/
#define HD_STORAGE						7	/*存储服务器*/
#define HD_TURN							8	/*转发器*/
#define HD_TVWALL						9	/*电视墙解码器*/
#define DVS_IPCAMERA					12	/*15/17编码模块*/
#define HD_IPCAMERA 					13	/*1080p10(摄像机)*/
#define HD_IPCAMERA1 					14	/*720p(摄像机)*/
#define HD_IPCAMERA2 					15	/*D1(摄像机)*/
#define HD_IPCAMERA3 					16	/*1080p30(摄像机)*/
#define HD_IPCAMERA4 					17	/*保留*/
#define HD_NVS							21	/*D1编码模块(BNC输入)*/
#define HD_NVS1							22	/*高清编码模块(YPbPr输入)*/
#define	HD_SC110_CAM					23	/*SC110编码模块*/

#define HD_DIGITALCAMERA_2M18			25	/*2M数字一体机*/

#define ANALOG_CAM						31	/*模拟CAM*/
#define HD_IPCAMERA_1M 					32	/*1M网络摄像机*/
#define HD_IPCAMERA_2M 					33	/*2M网络摄像机*/
#define HD_IPCAMERA_3M 					34	/*3M网络摄像机*/
#define HD_IPCAMERA_5M 					35	/*5M网络摄像机*/
#define HD_IPCAMERA_2M18				36	/*2M18倍网络一体机*/
#define HD_IPCAMERA_2M16				37	/*2M16倍网络一体机*/
#define HD_IPCAMERA_2M22				38	/*2M22倍网络一体机*/
#define HD_IPCAMERA_D1					39	/*D1摄像机*/
#define HD_IP38x38_2M					40	/*2M38x38模块*/
#define HD_IP38x38_1M					41	/*1M38x38模块*/
#define HD_IP38x38_D1					42	/*D138x38模块*/
#define HD_IPCAMERA_2M1M				43	/*2M1M网络摄像机*/
#define HD_IPCAMERA_2M1M16				44	/*2M118倍网络一体机*/
#define HD_IPCAMERA_2M1M18				45	/*2M1M16倍网络一体机*/
#define HD_IPCAMERA_2M1M22				46	/*2M1M22倍网络一体机*/
#define HD_IPCAMERA_SAFE				47	/*安全卫士系统*/
#define HD_IPCAMERA_2MINTELLIGENT		48	/*2M智能枪机*/
#define HD_IPCAMERA_2M20				49	/*2M20倍网络一体机*/
#define HD_IPCAMERA_2M36				50	/*2M30倍网络一体机*/
#define HD_IPCAMERA_1D3M18				51	/*1.3M18倍网络一体机*/
#define HD_IPCAMERA_1D3M16				52	/*1.3M16倍网络一体机*/
#define HD_IPCAMERA_1M18				53	/*1M18倍网络一体机*/
#define HD_IPCAMERA_1M16				54	/*1M16倍网络一体机*/
#define HD_IPCAMERA_1M22				55	/*1M22倍网络一体机*/
#define HD_IPCAMERA_1D3M22				56	/*1.3M22倍网络一体机*/
#define	HD_IPCAMERA_1M3					57	/*1M3倍网络一体机*/
#define	HD_IPCAMERA_1D3M3				58	/*1.3M3倍网络一体机*/
#define	HD_IPCAMERA_2M3					59	/*2M3倍网络一体机*/
#define HD_IPCAMERA_1D3M 				60	/*1.3M网络摄像机*/
#define HD_IP38x38_1D3M					61	/*1.3M38x38模块*/
#define HD_IP2BALL_1M					62	/*1M二代半球*/
#define HD_IP2BALL_1D3M					63	/*1.3M二代半球*/
#define HD_IP2BALL_2M					64	/*2M二代半球*/
#define HD_IPCAMERA_1M30 				65	/*1M一体机*/
#define HD_IPCAMERA_1D3M30				66	/*1.3M一体机*/
#define HD_IPCAMERA_2M30				67	/*2M一体机*/
#define HD_IPCAMERA_2M4CH				68	/*2M4码流枪机*/
#define HD_IP38x38_2M4CH				69	/*2M4码流M38模组*/
#define HD_IPCAMERA_4M 					70	/*4M网络摄像机*/
#define HD_IPCAMERA_2M60FRAME			71	/*2M60帧网络摄像机*/
#define HD_IPCAMERA_3M60FRAME 			72	/*3M60帧网络摄像机*/
#define HD_IPCAMERA_6M 					73	/*6M网络摄像机*/
#define HD_IPCAMERA_8M 					74	/*8M网络摄像机*/
#define HD_IPCAMERA_12M 				75	/*12M网络摄像机*/
#define HD_IP38x38_3M					76	/*3M双板M38模组*/
#define HD_IPCAMERA_PANORAMA			77	/*全景摄像机*/
#define HD_IP38x38_4M					78	/*1M双板M42模组*/

#define HD_IP38x42_1M					79	/*1M双板M38x42模组*/
#define HD_IP38x42_1D3M					80	/*1.3M双板M38x42模组*/
#define HD_IP38x42_2M					81	/*2M双板M38x42模组*/
#define HD_IP38x42_3M					82	/*3M双板M38x42模组*/
#define HD_IP38x42_4M					83	/*4M双板M38x42模组*/

#define HD_IP42x42_1M					84	/*1M双板M42模组*/
#define HD_IP42x42_1D3M					85	/*1.3M双板M42模组*/
#define HD_IP42x42_2M					86	/*2M双板M42模组*/
#define HD_IP42x42_3M					87	/*3M双板M42模组*/
#define HD_IP42x42_4M					88	/*4M双板M42模组*/
#define HD_IP42x42_5M					89	/*5M双板M42模组*/

#define	HD_IPCAMERA_YTJ_1M				90	/*1M倍网络一体机*/
#define	HD_IPCAMERA_YTJ_1D3M			91	/*1.3M倍网络一体机*/
#define	HD_IPCAMERA_YTJ_2M				92	/*2M倍网络一体机*/
#define	HD_IPCAMERA_YTJ_3M				93	/*3M倍网络一体机*/
#define	HD_IPCAMERA_YTJ_4M				94	/*4M倍网络一体机*/
#define	HD_IPCAMERA_YTJ_5M				95	/*5M倍网络一体机*/

#define HD_IP2BALL_3M					100	/*3M二代半球*/
#define HD_IP2BALL_5M					101	/*5M二代半球*/
#define HD_IP2BALL_6M					102	/*6M二代半球*/

#define HD_IPATM_1D3M					105	/*ATM1.3M设备*/
#define HD_IPATM_2M						106	/*ATM2M设备*/
#define HD_IPATM_3M						107	/*ATM3M设备*/
#define HD_IPATM_4M						108	/*ATM4M设备*/

#define HD_IPELEVATOR_2M				108	/*电梯设备*/

/* 用户信息定义，单个用户信息 */
typedef struct tmUserInfo_t
{
	unsigned int	dwSize;						/* 该结构大小，可能由于版本不同而变化*/
	char			szUserName[32];				/* 用户名 */
	char			szPassword[32];				/* 密码 */
	char			szMotifyPassword[32];		/* 密码 */
	unsigned short	wRemoteLevel;				/* 级别 */
	unsigned short	wRemoteLoginNum;			/* 允许同时登录数，0-为限制登录 */
	unsigned int	dwRemoteRightHi;			/* 权限 */
	unsigned int	dwRemoteRightLo;			/* 权限 */									
	unsigned int	dwUserIP;					/* 允许访问的远程IP地址(为0时表示允许任何地址) */
	unsigned char	byMACAddr[6];				/* 允许访问的远程物理地址(为0时表示允许任何地址)*/
}tmUserInfo_t;

/* 用户列表，列举用户时使用 */
typedef struct tmUser_t
{
	unsigned int	dwSize;						/*该结构大小*/
	int				iUserCount;					/*可用用户个数，必须小于MAX_USERNUM*/
	tmUserInfo_t	struUserInfo[16];			/*用户信息数组*/
}tmUser_t;

/* 用户加密数据TMCC_MINOR_CMD_GETENCRYPTDATA */
typedef struct tmUserEncryptMD5Cfg_t
{
	unsigned int	dwSize;
	unsigned char	byUserData[128];			/*需要加密的源数据*/
	unsigned int	dwUserDataLen;				/*需要加密的数据长度*/
	unsigned char	byMD5Data[16];				/*加密后的数据16个字节*/
}tmUserEncryptMD5Cfg_t;

/*DVS设备参数*/
typedef struct tmDeviceCfg_t
{
	unsigned int	dwSize;
	char			sDVSName[32];				/*DVS名称*/
	unsigned int	dwDVSID;					/*DVS ID,用于遥控器*/
	unsigned int	dwRecycleRecord;			/*是否循环录像,0:不是; 1:是*/
	unsigned int	dwVideoStandard;			/*视频制式0:PAL 1:NTSC*/
	unsigned int	dwMicrophone;				/*是否启用语音对讲, 0不启用,其它启用*/

/*以下不能更改*/
	char			szSerialNumber[48];			/*序列号*/
	unsigned int	dwSoftwareVersion;			/*软件版本号,高16位是主版本,低16位是次版本*/
	unsigned int	dwSoftwareBuildDate;		/*软件生成日期,0xYYYYMMDD*/
	unsigned int	dwDSPSoftwareVersion;		/*DSP软件版本,高16位是主版本,低16位是次版本*/
	unsigned int	dwDSPSoftwareBuildDate;		/*DSP软件生成日期,0xYYYYMMDD*/
	unsigned int	dwPanelVersion;				/*前面板版本,高16位是主版本,低16位是次版本*/
	unsigned int	dwHardwareVersion;			/*硬件版本,高16位是主版本,低16位是次版本*/
	unsigned char	byAlarmInPortNum;			/*DVS报警输入个数, MAX_ALARMIN-byAlarmInPortNum为网络报警个数*/
	unsigned char	byAlarmOutPortNum;			/*DVS报警输出个数*/
	unsigned char	byRS232Num;					/*DVS 232串口个数*/
	unsigned char	byRS485Num;					/*DVS 485串口个数*/
	unsigned char	byNetworkPortNum;			/*网络口个数*/
	unsigned char	byDiskCtrlNum;				/*DVS 硬盘控制器个数*/
	unsigned char	byDiskNum;					/*DVS 硬盘个数*/
	unsigned char	byDVSType;					/*DVS类型, */
	unsigned char	byChanNum;					/*DVS 通道个数*/
	unsigned char	byStartChan;				/*起始通道号,例如DVS-1,DVS - 1*/
	unsigned char	byDecordChans;				/*DVS 解码路数*/
	unsigned char	byVGANum;					/*VGA口的个数*/
	unsigned char	byUSBNum;					/*USB口的个数*/
	unsigned char	byFactory;					/*厂商代码，视频服务器的厂商ID,AIP公司定义*/
	unsigned short  wDeviceExternType;			/*设备扩展类型：第一位表示是否支持红外，第二位表示是否支持双路报警输入(0x0001 -- 支持红外; 0x0002 -- 支持双路报警)*/
	char			sDVSType[16];				/*设备类型名称*/
	unsigned int	dwModeType;					/*设备类型,比如A5DDR2 A5DDR3 S2 等,参见MODAL_ONLY_FLAG_A5*/
}tmDeviceCfg_t;

/*DVS设备扩展参数*/
typedef struct tmDeviceExCfg_t
{
	unsigned int	dwSize;						/*本结构大小*/
	unsigned char	byAlarmOutTurnIn;			/*报警输出修改成报警输入(M38模组支持此功能)*/
	unsigned char	byTransProtocol;			/*选用的协议0-默认内置协议,1-ONVIF协议,2-国标协议,3-互信互通协议*/
	unsigned char	byTemp[2];	
}tmDeviceExCfg_t;

/* 网络接口参数 */
typedef struct tmEthernet_t
{
	unsigned int	dwSize;
	char			sDVSIP[25];					/*服务器IP地址*/
	char			sDVSIPMask[25];				/*服务器IP地址掩码*/
	unsigned short	wDHCP;						/*1启用动态IP获取,0指定IP*/
	unsigned int	dwNetInterface;				/*网络接口 1-10MBase-T 2-10MBase-T全双工 3-100MBase-TX 4-100M全双工 5-10M/100M自适应*/
	unsigned short	wDVSPort;					/*端口号*/
	unsigned short	wHttpPort;					/*Http服务器端口号*/
	unsigned char	byMACAddr[6];				/*服务器的物理地址*/
	unsigned char	byInitNetInterface;			/*当前网络类型*/
	unsigned char	byClientConnectType;		/*要求客户端的连接模式*/
}tmEthernet_t;

/* DDNS服务器信息参数 */
typedef struct tmDDNS_t
{
	unsigned int		dwSize;
	char				sDDNSServerName[32];	/*DDNS服务器名称*/
	char				sDDNSServerName2[32];	/*备用DDNS服务器名称*/
	char				sDDNSName[32];			/*DDNS名称*/
	char				sDDNSUser[32];			/*DDNS用户名*/
	char				sDDNSPassword[32];		/*DDNS密码*/
}tmDDNS_t;

/* 网络配置结构 */
typedef struct tmNetCfg_t
{
	unsigned int		dwSize;
	tmEthernet_t		struEtherNet[2];				/* 以太网口 */
	char				sManageHostIP[26];				/*远程管理主机地址*/
	unsigned short		wManageHostPort;				/*远程管理主机端口号*/
	unsigned int		dwManageHost;					/*远程管理主0-不启用,1-启用*/
	unsigned int		dwSyncTimeFromManageHost;		/*从管理中心同步时间*/

	char				sDNSIP[25];						/*DNS服务器地址  */
	char				sDNSIP2[25];					/*备用DNS服务器地址  */

	char				sMultiCastIP[18];				/*多播组地址*/
	unsigned int		dwMultiCastPort;				/*多播组端口，第2码流+1,第3码流+2,第4码流+3*/
	unsigned char		byMultiCastIPMode;				/*多播地址组成模式:0-使用设置的地址, 1-地址xxx.aaa.aaa.aaa(其中aaa与本机地址一致,xxx使用设定的)*/
	unsigned char		byMultiCastPortMode;			/*多播端口组成模式:0-各码流端口相同,1-各码流端口递增，多个通道也根据通道数递增*/
	unsigned char		byMultiCastTemp;				/**/

	char				sGatewayIP[25];       			/*网关地址 */

	char				sNFSIP[25];						/*NAS主机IP地址	*/
	char				sNFSDirectory[130];				/*NAS目录*/
	unsigned char		byEnableNFS;					/*是否启用NFS，启用后摄像机将向指定目录写文件*/

	unsigned int		dwPPPOE;						/*0-不启用,1-启用*/
	char				sPPPoEUser[32];					/*PPPoE用户名*/
	char				sPPPoEPassword[32];				/*PPPoE密码*/
	char				sPPPoEIP[16];					/*PPPoE IP地址(只读)*/

	unsigned char		byTemp[12];						/*保留*/

	unsigned int		dwDDNS;							/*0-不启用,1-启用，如果是局域网登录，登录DDNS的地址为网关地址*/
	tmDDNS_t			struDDNS;						/*DDNS*/

	char				sManaeHostUser[32];				/*登陆管理中心用户名*/
	char				sManaeHostPassword[32];			/*登陆管理中心密码*/
	
	/*RTP是否启用0-不启用，1-启用*/
	unsigned int		dwEnableRtsp;
	/*RTP/RTSP监听端口*/
	unsigned short		wRtspPort;
	/*RTP/RTSP传输模式0-VLC兼容模式,1-QT兼容模式*/
	unsigned short		wRtspMode;
	/*RTSP主码流的访问标识，默认为bs0*/
	char				sMajorStream[32];
	/*RTSP从码流的访问标识，默认为bs1*/
	char				sMinorStream[32];
	/*RTSP主码流的访问标识，默认为bs2*/
	char				sThirdStream[32];
	/*RTSP从码流的访问标识，默认为bs3*/
	char				sFourthStream[32];
}tmNetCfg_t;

typedef struct tmRtspMutiCastStreamCfg_t
{
	unsigned int		dwSize;
	unsigned char		byEnableVideo;						/*使能视频组播发送*/
	unsigned char		byEnableAudio;						/*使能音频组播发送*/
	unsigned char		byReserve[2];
	char				sMultiCastIpVideo[20];				/*视频多播组地址*/
	char				sMultiCastIpAduio[20];				/*音频多播组地址*/
	unsigned short		wMultiCastPortVideo;				/*视频组播端口*/
	unsigned short		wMultiCastPortAudio;				/*音频组播端口*/
	unsigned char		byReserve2[8];
}tmRtspMutiCastStreamCfg_t;

/*RTSP组播发送配置参数*/
typedef struct tmRtspMutiCastCfg_t					/*TMCC_MINOR_CMD_RTSPMUTICASTCFG*/
{
	unsigned int					dwSize;

	unsigned char					byCurStreamNum;
	unsigned char					byReserve[3];
	
	tmRtspMutiCastStreamCfg_t		tRtspMuticast[8];
}tmRtspMutiCastCfg_t;

/* 无线网络配置结构 */
typedef struct tmWifiCfg_t
{
	unsigned int		dwSize;						/*本结构大小*/	
	unsigned char		byEnable;					/*无线是否启用	*/
	unsigned char		byDhcp;						/*无线地址方式,1启用动态IP获取,0指定IP*/
	
	char				sIpAddr[16];				/*Wifi地址  */
	char				sIpMaskAddr[16];			/*Wifi地址掩码  */
	char				sGatewayIP[16];       		/*Wifi网关地址 */
	char				sDNSIP1[16];				/*WifiDNS1地址*/
	char				sDNSIP2[16];				/*WifiDNS2地址*/
	
	char				sSsid[48];					/*服务器的SSID限制32*/
	char				sKey[48];					/*密钥限制32*/
	unsigned char		byKeyMgmt;					/*网络身份验证0-开放,1-共享,2-WPA,3-WPA-PSK,4-WPA2,5-WPA2-PSK*/
	unsigned char		byKeyType;					/*数据加密0-禁用，1-WEP，2-TKIP,3-AES*/
	unsigned char		byKeyIndex;					/*密码索引*/
	unsigned char		byScanSsid;					/*即使没有广播也连接*/
	unsigned int		dwWpaPtkRekey;				/*更换密钥时间*/

	BYTE				byMACAddr[6];				/*WifiMac地址*/

	unsigned char		byKeyFormat;				/*密码格式0-字符串,1-16数*/
	unsigned char		byTemp[3];
}tmWifiCfg_t;

/*2010-09-39 add by stone*/
typedef struct tmDDNSCfg_t
{
	unsigned int		dwSize;
	unsigned char		byDDNSEnable;
	unsigned char		byTemp[3];
	char				sDDNSServerName[32];		/*DDNS服务器名称*/
	char				sDDNSServerName2[32];		/*备用DDNS服务器名称*/
	char				sDDNSName[32];				/*DDNS名称*/
	char				sDDNSUser[32];				/*DDNS用户名*/
	char				sDDNSPassword[32];			/*DDNS密码*/
}tmDDNSCfg_t;

/*2007/11/29 frankxia add for Simpe Network Time Protocol Server*/
typedef struct tmNTPCfg_t
{
	unsigned int	dwSize;
	/*实际的NTP服务器个数 1<=dwCount<= NTPSERVER_MAX*/
	unsigned int	dwCount;
	/*正在使用的服务器索引,0<=dwIdx<MAX_NTP_SERVERS*/
	unsigned int	dwIdx;		
	/*最大允许的NTP服务器的个数*/
	char			strNTPServer[MAX_NTP_SERVERS][PATHNAME_LEN];	
}tmNTPCfg_t;

typedef struct tmNTPCfgEx_t
{
	unsigned int	dwSize;
	/*是否启用*/
	unsigned int	dwEnableNtp;
	/*同步时间间隔(单位:分钟)*/
	unsigned int	dwNtpTime;		
	/*最大允许的NTP服务器的个数*/
	char			strNTPServer[128];	
}tmNTPCfgEx_t;

/*2007/12/26 frankxia add for ftp file recorder*/
/*FTP服务器设置，定义了*/
typedef struct tmFTPCfg_t
{
	/*本结构大小*/
	unsigned int	dwSize;	

	/*是否启用FTP服务器*/
	unsigned char	byUseFTP;

	/*允许最大128字节*/
	char			strFTPServerIpAddr[128];

	/*FTP录像码流ID号*/
	unsigned char	byRecordStreamId;

	/*录像格式，暂时未用*/
	unsigned char	byRecordFormat;

	/*是否启用指定目录存放*/
	unsigned char	byEnableDirectory;

	/*服务器的端口，ftp默认21*/
	unsigned int	dwServerPort;

	/*FTP服务器用户名*/
	char			strFTPCliUserName[16];

	/*FTP服务器用户密码*/
	char			strFTPCliUserPass[16];

	/*记录文件的时间*/
	unsigned int	dwFTPRecordFileSize;

	/*指定的存放目录*/
	char			strDirectoryName[128];
}tmFTPCfg_t;


/*2007/12/26 frankxia add for sendmail*/
typedef struct tmSMTPCfg_t
{
	unsigned int	dwSize;	
	/*是否启用邮件服务器*/
	unsigned char	byUseSMTP;
	/*邮件服务器地址*/
	char			strSMTPServerIpAddr[128];/*允许最大128字节*/
	/*字节对其保留*/
	unsigned char	byReserves[3];
	/*邮件服务器用户名*/
	char			strSMTPCliUserName[16];
	/*邮件服务器用户口令*/
	char			strSMTPCliUserPass[16];
}tmSMTPCfg_t;

/*设备心跳配置定义*/
typedef struct tmLiveHeartCfg_t
{
	unsigned int		dwSize;							/*该结构的大小，必须填写*/
	unsigned char		byEnableLiveHeart;				/*是否启用心跳*/
	unsigned char		byLiveHeartMode;				/*心跳包发送模式0-UDP,1-TCP/IP*/
	unsigned short		wLiveTime;						/*发送心跳间隔时间(单位:秒)*/
	char				sServerAddress[32];				/*远程管理主机地址*/
	unsigned int		dwServerPort;					/*远程管理主机端口号*/
	unsigned char		byEnableRecord;					/*是否启用断网自动录像*/
	unsigned char		byTem[3];
}tmLiveHeartCfg_t;

/*设备数据流主动上传服务器信息*/
typedef struct tmStreamUpToServerCfg_t
{
	unsigned short		dwSize;							/*该结构的大小，必须填写*/
	unsigned char		byEnable;						/*是否启用自动上传*/
	unsigned char		byTemp;							/*保留*/
	char				sServerAddress[64];				/*远程管理主机地址*/
	unsigned short		wControlPort;					/*远程管理主机端口号*/
	unsigned short		wStreamPort;					/*远程管理主机端口号*/
	unsigned short		wTalkPort;						/*远程管理主机端口号*/
	unsigned short		wTemp;							/*保留*/
	char				sDeviceNumber[32];				/*设备序列号*/
}tmStreamUpToServerCfg_t;

/* 时间配置，从视服中得到时间，设置时给系统时间 */
typedef struct tmTimeCfg_t
{
	unsigned int	dwSize;
	unsigned short	wYear;			/*年*/
	unsigned short	wMonth;			/*月*/
	unsigned short	wDay;			/*日*/
	unsigned short	wDayOfWeek;		/*日*/
	unsigned short	wHour;			/*时*/
	unsigned short	wMinute;		/*分*/
	unsigned short	wSecond;		/*秒*/
	short			wTimeZone;		/*时区*/	
	int				iDayLightTime;	/*夏令时时间偏差，秒	*/
	unsigned short	wZoneIndex;		/*时区名称索引,先由wTimeZone确定时区，再由wZoneIndex确定是哪个地区，解决相同时区不同地区的问题*/
	unsigned char	byTemp[2];
}tmTimeCfg_t;

/*时间定义*/
typedef struct tmTimeInfo_t
{
	unsigned short	wYear;			/*年*/
	unsigned char	byMonth;		/*月*/
	unsigned char	byDay;			/*日*/
	unsigned char	byHour;			/*时*/
	unsigned char	byMinute;		/*分*/
	unsigned char	bySecond;		/*秒*/
	unsigned char	byTemp;			/*保留*/
	unsigned int	dwMicroSecond;	/*豪秒*/
}tmTimeInfo_t;

/* 时间范围 */
typedef struct tmSchedTime_t
{
	unsigned int	dwSize;
	/*开始时间*/
    unsigned char	byStartHour;
	unsigned char	byStartMin;
	/*结束时间*/
	unsigned char	byStopHour;
	unsigned char	byStopMin;
}tmSchedTime_t;

/* 报警处理方式*/
#define NOACTION			0x00				/*无响应*/
#define WARNONMONITOR		0x01				/*监视器上警告*/
#define WARNONAUDIOOUT		0x02				/*声音警告*/
#define UPTOCENTER			0x04				/*上传中心*/
#define TRIGGERALARMOUT		0x08				/*触发报警输出*/
#define UPTOCTRLCLIENT		0x10				/*上传控制客户端*/
#define UPTOAVCLIENT		0x20				/*上传音视频客户端*/
typedef struct tmHandleException_t
{
	unsigned char		byRelAlarmOutEnable[4];	/* 标明报警输出有效byRelAlarmOutEnable[0]为12则报警输出0-3 */
	unsigned int		dwHandleType;			/*处理方式,处理方式的"或"结果*/
	unsigned char		byRelAlarmOut[4];		/*报警触发的输出通道,报警触发的输出,为1表示触发该输出*/
}tmHandleException_t;


/* 报警处理动作 */
typedef struct tmTransFer_t
{
	/*取消结构大小定义*/
	unsigned char	byTransFerType;			/* 处理联动类型12为tmTransFer_t为通道数组0-16, 13为通道由byChannel决定*/
	unsigned char	byChannel;				/* 通道号0-MAX_CHANNUM */
	unsigned char	byTemp[2];				/* 保留 */
	unsigned char	byEnableRelRecordChan;	/* 报警触发的录象通道,为1表示触发该通道 */
	unsigned char	byEnablePreset;			/* 是否调用预置点 */
	unsigned char	byPresetNo;				/* 调用的云台预置点序号,一个报警输入可以调用多个通道的云台预置点*/
	unsigned char	byEnableCruise;			/* 是否调用巡航 */
	unsigned char	byCruiseNo;				/* 巡航 */
	unsigned char	byEnablePtzTrack;		/* 是否调用轨迹 */
	unsigned char	byPTZTrack;				/* 调用的云台的轨迹序号 */
	unsigned char	byEnableCaptureChan;	/* 报警触发的抓图通道，为1表示触发该通道 */
}tmTransFer_t;

/* 通道图象结构, 区域定义，该区域704*576 */
typedef struct tmAreaScope_t
{
	unsigned short	wAreaTopLeftX;		/* 区域的x坐标 */
	unsigned short	wAreaTopLeftY;		/* 区域的y坐标 */
	unsigned short	wAreaWidth;			/* 区域的宽 */
	unsigned short	wAreaHeight;		/* 区域的高 */
}tmAreaScope_t;
/* 移动侦测 */
typedef struct tmMotion_t
{
	unsigned int			dwSize;	
	unsigned char			byMotionScopeNum;							/*侦测区域个数，必须小于或等于5*/
	tmAreaScope_t			struMotionScope[5];							/*侦测区域704*576*/
	unsigned char			byMotionSensitive;							/*移动侦测灵敏度, 0 - 5,越高越灵敏*/
	unsigned char			byMotionThreshold;							/*移动检测阀值，为设置移动区域的宏块总数百分比，0-100，当为0时只要有一个宏块移动就算移动*/
																		/*置越小越灵敏*/
	unsigned char			byEnableHandleMotion;						/*是否处理移动侦测*/ 
	tmHandleException_t		strMotionHandleType;						/*处理方式*/
	tmSchedTime_t			struAlarmTime[7][4];						/*布防时间*/
	tmTransFer_t			struAlarmTransFer[16];						/*触发通道*/
}tmMotion_t;

/* 移动侦测 */
typedef struct tmVideoMotionCfg_t
{
	unsigned int			dwSize;	
	tmAreaScope_t			struMotionScope[5];							/*侦测区域704*576*/
	unsigned char			byMotionScopeNum;							/*侦测区域个数，必须小于或等于5*/	
	unsigned char			byMotionSensitive;							/*移动侦测灵敏度, 0 - 5,越高越灵敏*/
	unsigned char			byMotionThreshold;							/*移动检测阀值，为设置移动区域的宏块总数百分比，0-100，当为0时只要有一个宏块移动就算移动*/																		/*置越小越灵敏*/
	unsigned char			byEnableHandleMotion;						/*是否处理移动侦测*/ 
	tmHandleException_t		strMotionHandleType;						/*处理方式*/
	tmSchedTime_t			struAlarmTime[7][4];						/*布防时间*/
	tmTransFer_t			struAlarmTransFer[16];						/*触发通道*/
	unsigned int			dwHandleMinTime;							/*处理报警的最小时间，单位毫秒(在此时间内有对此报警只处理一次)*/
}tmVideoMotionCfg_t;

//测温区域定义
typedef struct tmFlirAreaScope_t
{
	unsigned short	wAreaTopLeftX;		/* 区域的x坐标 */
	unsigned short	wAreaTopLeftY;		/* 区域的y坐标 */
	unsigned short	wAreaWidth;			/* 区域的宽 */
	unsigned short	wAreaHeight;		/* 区域的高 */
	short			wMinTemperature;		/*当前点的最低摄氏温度*10，只读*/
	short			wMaxTemperature;		/*当前点的最高摄氏温度*10，只读*/
	short			wAverageTemperature;	/*当前点的平均摄氏温度*10，只读*/
	unsigned char	byAlarm;
	unsigned char	byTemp;
}tmFlirAreaScope_t;
//测温全屏定义
typedef struct tmFlirFullScope_t
{
	unsigned short	wMinTempX;			/* 最低温度的x坐标 */
	unsigned short	wMinTempY;			/* 最低温度的y坐标 */
	unsigned short	wMaxTempX;			/* 最高温度的x坐标 */
	unsigned short	wMaxTempY;			/* 最高温度的y坐标 */
	short			wMinTemperature;		/*全屏幕最低摄氏温度*10，只读*/
	short			wMaxTemperature;		/*全屏幕最高摄氏温度*10，只读*/
	short			wAverageTemperature;	/*全屏幕平均摄氏温度*10，只读*/
	unsigned char	byAlarm;
	unsigned char	byTemp;
}tmFlirFullScope_t;
//测温点定义
typedef struct tmFlirSpoltScope_t
{
	unsigned int	dwSize;	
	unsigned short	wSpoltX;		/*单点测温X坐标*/
	unsigned short	wSpoltY;		/*单点测温Y坐标*/
	short			wTemperature;	/*当前点的摄氏温度*10，只读*/	
	unsigned char	byAlarm;
	unsigned char	byTemp;
}tmFlirSpoltScope_t;


/* 热成像视频区域测温 */
typedef struct tmVideoFlirAreaCfg_t
{
	unsigned int			dwSize;	
	tmFlirAreaScope_t		struScope[MAX_FLIRAREANUM];					/*区域信息*/
	tmFlirFullScope_t		struFullScope;								/*全屏信息*/
	tmFlirSpoltScope_t		struSpoltScope;								/*单点信息*/
	unsigned char			byScopeNum;									/*侦测区域个数，必须小于或等于MAX_FLIRAREANUM*/	
	unsigned char			byCheckMode;								/*测温类型0-区域测温，1-全屏测温，2-单点测温*/
	unsigned char			byEnablePreset;								/*是否关联到预置点*/
	unsigned char			byPresetNo;									/*预置点ID,0-MAX_PRESET-1*/
}tmVideoFlirAreaCfg_t;

/* 热成像视频点测温 */
typedef struct tmVideoFlirSpoltCfg_t
{
	unsigned int			dwSize;	
	unsigned char			byEnableSpolt;
	unsigned char			byTemp;
	unsigned short			wSpoltX;									/*单点测温X坐标*/
	unsigned short			wSpoltY;									/*单点测温Y坐标*/
	short					wTemperature;								/*当前点的摄氏温度*10，只读*/
}tmVideoFlirSpoltCfg_t;

/* 热成像视频区域测温 */
typedef struct tmVideoFlirCfg_t
{
	unsigned int			dwSize;	
	unsigned char			byViewFlirInfo;								/*显示测温信息*/	
	unsigned char			byEnableHandleFlir;							/*是否处理热像测温*/ 
	unsigned char			byEnablePresetFlir;							/*是否启用预置点热像测温配置参数*/ 
	unsigned char			byCheckTempMode;							/*检查温度模式，0-检查平均温度，1-检查最低温度，2-检查最高温度*/ 
	tmHandleException_t		strHandleType;								/*处理方式*/
	unsigned int			dwHandleMinTime;							/*处理报警的最小时间，单位毫秒(在此时间内有对此报警只处理一次)*/
	tmSchedTime_t			struAlarmTime[7][4];						/*布防时间*/
	tmTransFer_t			struAlarmTransFer[16];						/*触发通道*/
	short					wMinTemperature;							/*低温(摄氏温度*10)报警值*/
	short					wMaxTemperature;							/*高温(摄氏温度*10)报警值*/	
	unsigned int			dwCheckDelayTime;							/*设置后延时检查时间，主要体现在预置点到位的时间(单位秒)*/
	int						iTempOffset;								/*温度偏差(摄氏温度*10)*/
	unsigned int			dwAutoFocusTempOffset;						/*自动聚焦的温度偏差(摄氏温度*10)*/
}tmVideoFlirCfg_t;


/* 遮挡报警区域为704*576 */
typedef struct tmHideAlarm_t
{
	unsigned int			dwSize;
	unsigned char			byHideSensitive;			/* 遮挡灵敏度 ,0 - 5,越高越灵敏 */
	tmAreaScope_t			struHideAlarmArea;			/* 遮挡区域 */
	unsigned char			byEnableHandleHideAlarm;	/* 是否处理信号丢失报警 */ 
	tmHandleException_t		strHideAlarmHandleType;		/* 处理方式 */	
	tmSchedTime_t			struAlarmTime[7][4];		/* 布防时间 */	
}tmHideAlarm_t;
/* 遮挡报警区域扩展为704*576 */
typedef struct tmVideoHideCfg_t
{
	unsigned int			dwSize;
	tmAreaScope_t			struHideAlarmArea;			/* 遮挡区域 */
	unsigned char			byHideSensitive;			/* 遮挡灵敏度 ,0 - 5,越高越灵敏 */
	unsigned char			byEnableHandleHideAlarm;	/* 是否处理信号丢失报警 */ 
	unsigned char			byHideScopeNum;				/*遮挡区域个数，必须小于或等于5*/
	unsigned char			byTemp[1];
	tmHandleException_t		strHideAlarmHandleType;		/* 处理方式 */	
	tmSchedTime_t			struAlarmTime[7][4];		/* 布防时间 */
	unsigned int			dwHandleMinTime;			/* 处理报警的最小时间，单位毫秒(在此时间内有对此报警只处理一次) */
	tmAreaScope_t			struHideAlarmAreaEx[4];		/* 报警区域扩展，为了程序兼容只能新增加4个到最后,总共5个*/
}tmVideoHideCfg_t;

/* 信号丢失报警 */
typedef struct tmViLost_t
{
	unsigned int			dwSize;
	unsigned char			byEnableHandleVILost;		/* 是否处理信号丢失报警 */ 
	tmHandleException_t		strVILostHandleType;		/* 处理方式 */	
	tmSchedTime_t			struAlarmTime[7][4];		/* 布防时间 */
}tmViLost_t;

/* 信号丢失报警扩展 */
typedef struct tmVideoLostCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnableHandle;				/* 是否处理信号丢失报警 */ 
	unsigned char			byTemp[3];
	tmHandleException_t		strHandleType;				/* 处理方式 */	
	tmSchedTime_t			struAlarmTime[7][4];		/* 布防时间 */
}tmVideoLostCfg_t;

/* 视频遮挡配置 */
typedef struct tmVideoMaskCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnableMask;				/* 是否启动遮挡 ,0-否,1-是 区域为704*576*/
	unsigned char			byTemp[3];
	tmAreaScope_t			struHideArea[4];			/*遮挡区域*/
}tmVideoMaskCfg_t;

/* 人脸检测配置 */
typedef struct tmFaceDetectCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnable;				/* 是否启动遮挡 ,0-否,1-是*/
	unsigned char			byTemp[3];
}tmFaceDetectCfg_t;

/* 智能跟踪，需要一体机机芯才生效 */
typedef struct tmAptitudeScoutCfg_t
{
	unsigned int			dwSize;	
	unsigned char			byEnable;					/*是否启用*/	
	unsigned char			byTimeOut;					/*跟踪超时时间 60s-200s*/
	unsigned char			byTemp[2];					/*保留*/
}tmAptitudeScoutCfg_t;

/* 图像预览参数 */
typedef struct tmPicPreviewCfg_t
{
	unsigned int			dwSize;
	unsigned char			dwVideoFormat;				/*只读：视频制式 0-PAL 1-NTSC*/
	unsigned char			byGamma;					/*伽玛,0-255*/
	unsigned char			byEnableAcutanceA;			/*是否启用0-不单独使用，根据byAcutance设置，1-单独使用*/
	unsigned char			byAcutanceA;				/*锐度A,0-255*/   
	short					byBrightness;  				/*亮度,0-255*/
	short					byContrast;    				/*对比度,0-255*/	
	short					bySaturation;  				/*饱和度,0-255 */
	short					byHue;    					/*色调,0-255*/
	short					byAcutance;					/*锐度,0-255*/   
}tmPicPreviewCfg_t;

/* 图像预览参数 */
typedef struct tmPicPreviewInfo_t
{
	/*亮度,0-255*/
	unsigned char	byBrightness;
	/*对比度,0-255*/
	unsigned char	byContrast;
	/*饱和度,0-255 */
	unsigned char	bySaturation;
  	/*色调,0-255*/
	unsigned char	byHue;
}tmPicPreviewInfo_t;

/*图像模式预设计划*/
typedef struct tagPicModeScheduleInfo_t
{
	/*时间段信息，开始时*/
	unsigned char		byStartHour;      
	unsigned char		byStartMin;
	unsigned char		byStopHour;
	unsigned char		byStopMin;
	
	/*是否启用标志: 0-不启用; 1-启用*/
	unsigned char		byEnable;         
	/*视频模式索引: 0-白天模式; 1-强光模式; 2-傍晚模式; 3-夜间模式*/
	unsigned char		byMode;  
	/*扩展的锐度(0-255)*/
	unsigned char		byAcutance;
	/*保留*/
	unsigned char		byGamma;     
}tmPicModeScheduleInfo_t;

typedef struct tagPicModeScheduleCfg_t
{
	unsigned int					dwSize ;
	/*图像模式:0-白天模式; 1-强光模式; 2-傍晚模式; 3-夜间模式*/
	tmPicPreviewInfo_t				struMode[4];                  
	/*索引0，1，2.3分别代表四个时间段*/
	tmPicModeScheduleInfo_t			struModeSched[4];   
}tmPicModeScheduleCfg_t;

/*　图像采集偏移微调定义 */
typedef struct tmVideoOffsetCfg_t
{
	unsigned int	dwSize;	
	short			offset_left;
	short			offset_top;
	short			offset_right;
	short			offset_bottom;
}tmVideoOffsetCfg_t;

/* 图像OSD参数配置 */
typedef struct tmVideoOsdCfg_t
{
	unsigned int			dwSize;

	char					sChanName[64];				/* 通道名 */
	unsigned short			wShowNameTopLeftX;			/* 通道名称显示位置的x坐标 */
	unsigned short			wShowNameTopLeftY;			/* 通道名称显示位置的y坐标 */
	unsigned char			byShowChanName;				/* 预览的图象上是否显示通道名称,0-不显示,1-显示 区域为704*576 */
	unsigned char			byNameCoordinateMode;		/* 坐标模式通道模式*/
														/* 0-相对左上角，1-相对右上角，2-相对左下角，3-相对右下角*/

	unsigned short			wShowTimeTopLeftX;			/* OSD的x坐标 */
	unsigned short			wShowTimeTopLeftY;			/* OSD的y坐标 */
	unsigned char			byShowTime;					/* 预览的图象上是否显示OSD,0-不显示,1-显示*/
	unsigned char			byTimeType;					/* OSD类型(主要是年月日格式) */
														/* 0: xxxx/xx/xx xx:xx:xx 年/月/日 时分秒*/
														/* 1: xx/xx/xxxx xx:xx:xx 月/日/年 时分秒*/
														/* 2: xx:xx:xx 时分秒*/
														/* 3: xxxx-xx-xx xx:xx:xx 年-月-日 时分秒*/
														/* 4: xx-xx-xxxx xx:xx:xx 月-日-年 时分秒*/
														/* 5: xx-xx-xxxx xx:xx:xx 日-月-年 时分秒 wangjun*/
														/* 6: xx/xx/xxxx xx:xx:xx 日/月/年 时分秒 wangjun*/
														/* 7: xxxx年xx月xx日 xx时xx分xx秒 wangjun*/
														/* 8: xxxx年xx月xx日 xx:xx:xx */
	unsigned char			byShowWeek;					/* 是否显示星期 */	
	unsigned char			byWeekType;					/* 星期类型0-中文，1-英文 */
	unsigned char			byTimeCoordinateMode;		/* 坐标模式时间模式*/

	unsigned char			byOsdAttrib;				/* OSD属性: */
														/* 0: 半透明 */	
														/* 1: 不透明 */	
														/* 当最高位为1时，低7位为透明度0~127*/
	unsigned char			byFontMode;					/* OSD的字体模式通道名大小 */	
	unsigned char			byAlignMode;				/* 字符串中如果带\n将隔行显示，头顶对齐方式,0-右对齐，1-中间，2-左对齐，0xFF-自动*/
	unsigned char			byFontMode1;				/* OSD的字体模式时间 */	
	unsigned char			byFontMode2;				/* OSD的字体模式扩展字符 */	

	/*扩展显示的标题*/
	char					sShowText[256];				/* 扩展的标题 */
	unsigned short			wShowTextTopLeftX;			/* 扩展的标题显示位置的x坐标 */
	unsigned short			wShowTextTopLeftY;			/* 扩展的标题显示位置的y坐标 */
	unsigned char			byShowText;					/* 预览的图象上是否显示扩展的标题,0-不显示,1-显示 区域为704*576 */
	unsigned char			byTextCoordinateMode;		/* 坐标模式*/
														/* 0-相对左上角，1-相对右上角，2-相对左下角，3-相对右下角*/
	unsigned char			byTextExpandMode;			/* 是否启用扩展标题的菜单模式*/
	unsigned char			byTextBackGroundMode;		/* 扩展OSD背景大小模式 0-以高为准，1-以宽为准，2-自动按图像比例处理, 3-指定大小, 4-全屏*/

	unsigned char			byTextBackGroundColor;		/* 背景透明度 */
	unsigned char			byNameColorMode;			/* 童道名字体颜色方案0~15 */
	unsigned char			byTimeColorMode;			/* 时间字体颜色方案0~15 */
	unsigned char			byTextColorMode;			/* 扩展字符字体颜色方案0~15 */

	unsigned short			wTextBackGroundWidth;		/* 扩展背景宽度，相对于704*576 */
	unsigned short			wTextBackGroundHeight;		/* 扩展背景高度，相对于704*576 */
	/*第4个OSD区域*/
	char					sText4[256];				/* 第4个OSD */
	unsigned short			wText4TopLeftX;				/* 第4个OSD显示位置的x坐标 */
	unsigned short			wText4TopLeftY;				/* 第4个OSD显示位置的y坐标 */
	unsigned char			byShowText4;				/* 预览的图象上是否显示第4个OSD,0-不显示,1-显示 区域为704*576 */
	unsigned char			byText4CoordinateMode;		/* 坐标模式*/
														/* 0-相对左上角，1-相对右上角，2-相对左下角，3-相对右下角*/	
	unsigned char			byFontMode4;				/* OSD的字体模式第4个OSD区域 */	
	unsigned char			byText4ColorMode;			/* 扩展字符字体颜色方案0~15 */
}tmVideoOsdCfg_t;

/*OSD颜色方案配置*/
typedef struct tmVideoOsdColorInfo_t
{
	/*字体主题颜色RGB*/
	unsigned char			byEnable;
	unsigned char			byFontR;
	unsigned char			byFontG;
	unsigned char			byFontB;
	/*字体边缘颜色RGB*/
	unsigned char			byEnableEdge;
	unsigned char			byEdgeR;
	unsigned char			byEdgeG;
	unsigned char			byEdgeB;
	/*字体背景颜色RGB*/
	unsigned char			byEnableBack;
	unsigned char			byBackR;
	unsigned char			byBackG;
	unsigned char			byBackB;
	unsigned char			byBackAlpha;
	unsigned char			byTemp[3];
}tmVideoOsdColorInfo_t;
typedef struct tmVideoOsdColorCfg_t
{
	unsigned int			dwSize;
	tmVideoOsdColorInfo_t	struColorMode[COLOR_MODE_NUM];
}tmVideoOsdColorCfg_t;

typedef struct tmVideoExpandOsdInfo_t
{
	/*位置和大小信息，相对于704*576*/
	tmAreaScope_t			pos;
	/*字体大小*/
	unsigned char			size;
	/*模式0-字符串，1-画框, 2-点, 3-画十字， 21-字符串和框，22字符串和点, 23字符串和十字*/
	unsigned char			mode;
	/*0-相对左上角，1-相对右上角，2-相对左下角，3-相对右下角*/
	unsigned char			coordinate_mode;
	unsigned char			save;
	/*字体颜色RGB24{r,g,b}*/
	union
	{
		struct
		{
			unsigned char	r;
			unsigned char	g;
			unsigned char	b;
			unsigned char	t;
		}rgb;
		unsigned int		c;
	}color;
	union
	{
		struct
		{
			unsigned char	r;
			unsigned char	g;
			unsigned char	b;
			unsigned char	t;
		}rgb;
		unsigned int		c;
	}border_color;
	/*字符信息*/
	char					szInfo[256];
}tmVideoExpandOsdInfo_t;

typedef struct tmVideoExpandOsdCfg_t
{
	unsigned int			dwSize;
	unsigned short			iCount;
	unsigned char			byType;
	unsigned char			byTemp;
	tmVideoExpandOsdInfo_t	struOsdInfo[1];
}tmVideoExpandOsdCfg_t;

/* 图像参数 */
typedef struct tmPicCfg_t
{
	unsigned int			dwSize;
	char					sChanName[32];
	unsigned int			dwVideoFormat;				/* 只读：视频制式 0-PAL 1-NTSC*/

	/*显示通道名*/
	unsigned int			dwShowChanName;				/* 预览的图象上是否显示通道名称,0-不显示,1-显示 区域为704*576 */
	unsigned short			wShowNameTopLeftX;			/* 通道名称显示位置的x坐标 */
	unsigned short			wShowNameTopLeftY;			/* 通道名称显示位置的y坐标 */
	unsigned char			byShowNamAttrib;			/* 名称属性:透明 */

	/*信号丢失报警*/
	tmViLost_t				struVILost;
	/*移动侦测*/
	tmMotion_t				struMotion;	
	/*遮挡报警*/
	tmHideAlarm_t			struHideAlarm;
	/*遮挡*/
	unsigned char			dwEnableHide;				/* 是否启动遮挡 ,0-否,1-是 区域为704*576*/
	tmAreaScope_t			struHideArea;				/*遮挡区域*/

	unsigned int			dwShowOsd;					/* 预览的图象上是否显示OSD,0-不显示,1-显示*/
	unsigned short			wOSDTopLeftX;				/* OSD的x坐标 */
	unsigned short			wOSDTopLeftY;				/* OSD的y坐标 */
	unsigned char			byOSDType;					/* OSD类型(主要是年月日格式) */
														/* 0: xxxx/xx/xx xx:xx:xx 年月日 时分秒*/
														/* 1: xx/xx/xxxx xx:xx:xx 月日年 时分秒*/
														/* 2: xx:xx:xx 时分秒*/
	unsigned char			byDispWeek;					/* 是否显示星期 */	
	unsigned char			byOSDAttrib;				/* OSD属性:透明 */
														/* 0: 不透明 */	
														/* 1: 半透明 */	
	char					sWeekName[7][20];			/*星期名称，0为星期一，6为星期日*/

	unsigned char			byEnableStreamNum;			/*是否支持双码流，0-单码流，1-双码流，此参数还必须根据NVS硬件决定*/
}tmPicCfg_t;

/*压缩参数*/
typedef struct tmCompression_t
{
	/*此结构值修改为编码格式，为了保持一致此值不能为16*/
	/*unsigned int	dwSize;*/
	/*视频编码格式，0-BKMPEG4,1-H264,2-MJPEG,3-H265,10-YPbPr,11-cvbs,12-hdmi,13-Digital*/
	unsigned char		byCompressFormat;

	/*关键帧间隔 : 0x00 表示使用默认；0xFF 表示全关键帧;其他值表示关键帧帧间隔*/
	unsigned char		byKeyFrameInterval;

	/*设置当全帧时显示的帧率*/
	unsigned char		byDisplayFrame;
	/*是否启用图像质量控制*/
	unsigned char		byEnableQuality;

	/*码流类型0-视频流,1-复合流*/
	unsigned char		byStreamType;

	/*分辨率
	 0-CIF(352x288) 1-QCIF(176x144), 2-2CIF(704x288), 3-4CIF(704x576), 
	 4-QQCIF(88x72), 5-DCIF(512x384), 6-VGA(640x480), 7-QDICF(256x192), 8-QVGA(320x240),
	 9-800x600, 10-1024x768 11-1280x720, 12-D1(720x576),
	 13-1600x1200, 14-1440x1080, 15-1920x1080, 16-1280x1024, 17-1280x960
	 18-1920x1200, 19-2048x1152, 20-2048x1536, 21-2560x1440, 22-2592x1944
	 23-960x576, 24-2304x1296, 25-3072x2048, 26-3840x2160, 27-4096x2160, 28-4000x3000
	 29-1280x1280, 30-2880x720
	*/
	unsigned char		byResolution;

	/*码率类型0:定码率, 1:变码率, 2:限码流*/
	unsigned char		byBitrateType;

	/*图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差 6-最差*/	
	unsigned char		byPicQuality;

	/*视频码率 0-保留 1-保留 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	  13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	  最高位(32位)置成1表示是自定义码流, 0-31位表示码流值(MIN-16K MAX-8192K)。
	*/
	unsigned int		dwVideoBitrate; 

	/*帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20;
	  扩展 14-1/15; 15-1/14: 16-1/13; 17-1/12; 18-1/11; 19-1/10; 20-1/9; 21-1/7; 22-1/6; 23-1/5; 24-1/3;
	  25-使用byVideoFrameRate的实际帧率
	*/
	unsigned char		dwVideoFrameRate;
	unsigned char		byVideoFrameRate;
	
	/*H26x编码级别<10-默认, 10-Baseline, 11-MainProfile, 12-HighProfile*/
	unsigned char		byProfileLevel;
	unsigned char		byTemp1;
}tmCompression_t;

typedef struct tmCompressionCfg_t
{
	unsigned int			dwSize;
	/*录像主流参数*/
	tmCompression_t			struRecordPara;		
	/*网络传输子码流参数*/
	tmCompression_t			struNetPara;
	/*第3子码流参数*/
	tmCompression_t			struThirdPara;
	/*组合编码格式，如果不是用新的编码方式，请设置为0*/
	unsigned char			byFormatId;
	/*0位标示D1使用的分辨率(0-720x576,1-704x576)*/
	unsigned char			byResolutionCfg;
	/*网络数据流是加密模式0-不加密，1-加密*/
	unsigned char			byStreamEncryptMode;
	/*保留*/
	unsigned char			byTemp;
	/*第4子码流参数*/
	tmCompression_t			struFourthPara;
	/*第5678子码流参数*/
	tmCompression_t			struOtherPara[4];
}tmCompressionCfg_t;

/* 区域编码参数，针对码流的信息 */
typedef struct tmVideoEnjoyInfo_t
{
	unsigned char			byEnable;							/*是否启用5*/	
	unsigned char			byScopeNum;							/*区域数*/
	unsigned char			byTemp[2];							/*保留*/
	struct
	{
		tmAreaScope_t		struScope;						/*侦测区域704*576*/
		unsigned char		byQuality;						/*区域的质量*/
		unsigned char		byLevel;						/*区域的编码级别*/
		unsigned char		byTemp[6];
	}scope[4];
	unsigned char			byResTemp[12];
}tmVideoEnjoyInfo_t;
/* 区域编码参数配置 */
typedef struct tmVideoEnjoyCfg_t
{
	unsigned int			dwSize;	
	tmVideoEnjoyInfo_t		struEnjoy[8];
}tmVideoEnjoyCfg_t;

/*码流信息*/
typedef struct tmStreamDescription_t
{
	unsigned char			byResolution;			/*图像大小格式索引*/
	unsigned char			byFormat;				/*编码格式*/
	unsigned char			byFrameRateNum;			/*帧率列表数*/
	unsigned char			byType;					/*码流类型0-压缩编码，1-数字或模拟输出，2-抓图码流*/
	unsigned char			byFramesRateList[MAX_FRAMERATE_NUM];	/*帧率列表*/
	unsigned char			byMaxFrameRate;			/*最大帧率限制*/
	unsigned short			nWidth;					/*图像宽*/
	unsigned short			nHeight;				/*图像高*/
	unsigned char			byTemp[2];				/*保留*/
	unsigned int			dwMaxBitRate;			/*码流上限*/
	unsigned int			dwDisplayRatio;			/*显示的正确比例*1000*/
}tmStreamDescription_t;

/*编码能力查询*/
typedef struct tmCompressCapability_t
{
	char					sName[64];			/*编码格式名称,如1080P(H264) + D1(H264)*/
	unsigned char			byFormatId;			/*编码格式*/
	unsigned char			byStreamCount;		/*码流数*/
	unsigned char			byTemp[2];
	tmStreamDescription_t	struStreamFormat[4];/*码流的编码格式*/
}tmCompressCapability_t;

typedef struct tmCompressCapabilityCfg_t
{
	unsigned int			dwSize;				/*本结构大小*/
	unsigned int			dwCount;			/*支持的压缩格式数*/
	tmCompressCapability_t	struCapability[1];	/*组合编码列表，这里象征性定义一个*/
}tmCompressCapabilityCfg_t;

/*扩展编码能力查询*/
typedef struct tmCompressCapabilityEx_t
{
	char					sName[128];			/*编码格式名称,如1080P(H264) + D1(H264)*/
	unsigned char			byFormatId;			/*编码格式*/
	unsigned char			byStreamCount;		/*码流数*/
	unsigned char			byTemp[2];
	tmStreamDescription_t	struStreamFormat[8];/*码流的编码格式*/
}tmCompressCapabilityEx_t;

typedef struct tmCompressCapabilityExCfg_t
{
	unsigned int				dwSize;				/*本结构大小*/
	unsigned int				dwCount;			/*支持的压缩格式数*/
	tmCompressCapabilityEx_t	struCapability[1];	/*组合编码列表，这里象征性定义一个*/
}tmCompressCapabilityExCfg_t;

/*音频压缩的配置结构，这个结果的设置是针对系统的所有通道*/
typedef struct tmAudioCfg_t
{
	/*本结构大小*/
	unsigned int		dwSize;
	/*音频编码格式，参考音频编码格式列表*/
	unsigned char		byCompressFormat;
	/*要所音频声道数0-左声道，1-右声道，2-立体声*/
	unsigned char		byChannelMode;
	/*音频压缩码流默认0-默认,1-16K,2-24K,3-32K,4-40K,5-48K,6-56K,7-64K,8-128K,9-256K*/
	unsigned char		byBitRate;
	/*音频采样率0-默认, 1-8000Hz, 2-16000Hz, 3-22050Hz, 4-44100Hz, 5-48000Hz*/
	unsigned char		bySamplesRate;
	/*音频放大倍数*100,如1表示0.01,100表示1*/
	unsigned int		dwLampFactor;
	/*输入选择0-选择音频输入，1-选择MIC输入*/
	unsigned char		byAudioInMode;
	/*音频输入模式，0-拾音器，1-线性输入*/
	unsigned char		byLineInMode;
}tmAudioCfg_t;
/*音频编码格式列表*/
#define TMCC_AUDIO_ENCTYPE_MP2		0x00
#define TMCC_AUDIO_ENCTYPE_AAC		0x01
#define TMCC_AUDIO_ENCTYPE_MULAW	0x02
#define TMCC_AUDIO_ENCTYPE_ALAW		0x03
#define TMCC_AUDIO_ENCTYPE_G721		0x04
#define TMCC_AUDIO_ENCTYPE_G722		0x05
#define TMCC_AUDIO_ENCTYPE_G723_24	0x06
#define TMCC_AUDIO_ENCTYPE_G723_40	0x07
#define TMCC_AUDIO_ENCTYPE_G726		0x08
#define TMCC_AUDIO_ENCTYPE_G729		0x09
#define TMCC_AUDIO_ENCTYPE_S16LE	0x0A


/*摄像机抓拍定义*/
typedef struct tmCaptureImageCfg_t
{
	/*本结构大小*/
	unsigned int		dwSize;
	/*图像格式，0-BMP, 1-JPEG, 2-H264, 3-YUV, 4-H265目前保留只能是1*/
	unsigned char		byFormat;
	/*抓图存放位置0-保存到本地硬盘，1-上传到FTP服务器,2-通过报警通道上传*/
	/*3-本地保存同时上传FTP,4-本地保存同时上传报警通道*/
	unsigned char		bySaveMode;
	/*每次报警抓图数目1~5*/
	unsigned char		byCaptureNum;
	/*是否启用指定目录存放*/
	unsigned char		byEnableDirectory;
	/*抓图的间隔时间毫秒*/
	unsigned int		dwCaptureInterval;

	/*抓图FTP服务器设置*/
	/*允许最大128字节*/
	char				sFTPServerIpAddr[128];

	/*服务器的端口，ftp默认21*/
	unsigned int		dwFTPServerPort;

	/*FTP服务器用户名*/
	char				sFTPCliUserName[16];

	/*FTP服务器用户密码*/
	char				sFTPCliUserPass[16];
	
	/*抓图的存放目录*/
	char				sDirectoryName[128];

	/*抓图码流为从码流0-主码流，1-从码流，2-第3码流，3-第4码流，0xFF使用默认码流根据默认配置选项处理*/
	unsigned char		byCaptureStream;
	
	/*抓图通道是否叠加和主码流一样的OSD信息，这里只针对有单独的抓图通道，如果是其它码流按设置处理*/
	unsigned char		byRenderOsdInfo;

	/*报警抓图时，如果一直有报警，那么每次开始抓图的时间间隔，单位秒，默认1秒,0为开始报警才抓图*/
	/*注意当报警停掉，间隔10秒后再报警为另外一次报警，否则还是前一次报警*/
	unsigned char		byAlarmIntervalCapture;
	/*默认抓图设置0-自动选择最佳抓图(首先选择最大的MJPEG，后选择主码流)，1-主码流抓图，2-2码流抓图，3-3码流抓图，4-4码流抓图*/
	unsigned char		byDefaultCaptureMode;
	/*图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差 6-最差*/
	unsigned char		byPicQuality;
	/*抓图抓最大码流(如果vin大于最大码流)*/
	unsigned char		byMaxVinImage;
	/*保留*/
	unsigned char		byTemp[2];
}tmCaptureImageCfg_t;
#define CAPTUREIMAGE_MODE_SAVE			0x00
#define CAPTUREIMAGE_MODE_FTP			0x01
#define CAPTUREIMAGE_MODE_SERVER		0x02
#define CAPTUREIMAGE_MODE_SAVEANDFTP	0x03
#define CAPTUREIMAGE_MODE_SAVEANDSERVER	0x04

/*自动抓图的布防时间*/
typedef struct tmCaptureSchedCfg_t
{
	/*本结构大小*/
	unsigned int				dwSize;
	/*抓图时间段*/
	tmSchedTime_t				struCaptureSched[MAX_DAYS][MAX_TIMESEGMENT];
	/*每组抓图动作间隔时间，单位秒*/
	unsigned int				dwCaptureTime;					
	/*保留*/
	unsigned char				byReserves;
	/*是否启用布防抓图*/
	unsigned char				byEnableCapture;	
	/*保留*/
	unsigned char				byTemp[2];
}tmCaptureSchedCfg_t;

/*----------------------------------------------------------------------*/

#define PTZ_REALTRANS			0	/* 透明云台数据传输 */
#define PTZ_LIGHT_PWRON			2	/* 接通灯光电源 1*/
#define PTZ_WIPER_PWRON			3	/* 接通雨刷开关 2*/
#define PTZ_FAN_PWRON			4	/* 接通风扇开关 3*/
#define PTZ_HEATER_PWRON		5	/* 接通加热器开关 4*/
#define PTZ_AUX_PWRON			6	/* 接通辅助设备开关 5 5*/

#define PTZ_FOCUS_AUTO			7	/* 自动聚焦 */

#define PTZ_ZOOM_IN				11	/* 焦距以速度SS变大(倍率变大) */
#define PTZ_ZOOM_OUT			12	/* 焦距以速度SS变小(倍率变小) */
#define PTZ_FOCUS_NEAR			13	/* 焦点以速度SS前调 */
#define PTZ_FOCUS_FAR			14	/* 焦点以速度SS后调 */
#define PTZ_IRIS_ENLARGE		15	/* 光圈以速度SS扩大 */
#define PTZ_IRIS_SHRINK			16	/* 光圈以速度SS缩小 */
#define PTZ_ZOOM_STEPIN			17	/* 焦距以速度SS单步变大(倍率变大) */
#define PTZ_ZOOM_STEPOUT		18	/* 焦距以速度SS单步变小(倍率变小) */
#define PTZ_UP					21	/* 云台以SS的速度上仰 */
#define PTZ_DOWN				22	/* 云台以SS的速度下俯 */
#define PTZ_LEFT				23	/* 云台以SS的速度左转 */
#define PTZ_RIGHT				24	/* 云台以SS的速度右转 */
#define PTZ_RIGHTUP				25	/* 云台以SS的速度右上仰 */
#define PTZ_RIGHTDOWN			26	/* 云台以SS的速度右下仰 */
#define PTZ_LEFTUP				27	/* 云台以SS的速度左上仰 */
#define PTZ_LEFTDOWN			28	/* 云台以SS的速度左下仰 */
#define PTZ_AUTO				29	/* 云台以SS的速度左右自动扫描 */

#define PTZ_485INPUT			31	/* 485接收数据输入 */
#define PTZ_485OUTPUT			32	/* 485发送数据输出 */
#define PTZ_SET_KEEPWATCH		33	/*保存守望点*/
#define PTZ_GOTO_KEEPWATCH		34	/*调用守望点*/
#define PTZ_LOCK_KEEPWATCH		35	/*关闭看守卫*/
#define PTZ_CLOSE_KEEPWATCH		35	/*关闭看守卫*/
#define PTZ_UNLOCK_KEEPWATCH	36	/*打开看守卫*/
#define PTZ_OPEN_KEEPWATCH		36	/*打开看守卫*/

#define PTZ_GOTO_ZOOMBS			37	/* 转到指定倍数,默认基数10开始为一倍，小于10为特殊位置*/

#define PTZ_SET_PRESET			100	/* 设置预置点 */
#define PTZ_CLE_PRESET			101	/* 清除预置点 */
#define PTZ_GOTO_PRESET			102	/* 转到预置点*/

#define PTZ_STARTREC_TRACK		110	/* 开始录制轨迹 */
#define PTZ_STOPREC_TRACK		111	/* 停止录制轨迹 */
#define PTZ_STARTRUN_TRACK		112	/* 运行轨迹*/
#define PTZ_STOPRUN_TRACK		113	/* 停止轨迹*/

#define PTZ_STARTREC_CRUISE		120	/* 开始录制巡航 */
#define PTZ_STOPREC_CRUISE		121	/* 停止录制巡航 */
#define PTZ_STARTRUN_CRUISE		122	/* 运行巡航*/
#define PTZ_STOPRUN_CRUISE		123	/* 停止巡航*/

#define PTZ_INTEGRATE_CONTROL	124	/* 云台综合控制，同时控制旋转和变倍等*/
#define PTZ_SET_ORIGINALITYPT	125	/* 设置当前位置为坐标原始点*/

#define PTZ_STARTREC_LINE		130	/* 开始录制线扫 */
#define PTZ_STOPREC_LINE		131	/* 停止录制线扫 */
#define PTZ_SETLINE_POINT		132	/* 设置线扫点*/
#define PTZ_STARTRUN_LINE		133	/* 运行巡航*/
#define PTZ_STOPRUN_LINE		134	/* 停止巡航*/

#define PTZ_SELFCHECK			255	/*云台自检*/

/*解码器*/
typedef struct tmDecoderCfg_t
{
	unsigned int			dwSize;
	unsigned int			dwBaudRate;				/*波特率(bps)直接表示*/
	unsigned char			byDataBit;				/* 数据有几位 0－5位，1－6位，2－7位，3－8位;*/
	unsigned char			byStopBit;				/* 停止位 0－1位，1－1.5位，2-2;*/
	unsigned char			byParity;				/* 校验 0－无校验，1－奇校验，2－偶校验;*/
	unsigned char			byFlowcontrol;			/* 0－无，1－软流控,2-硬流控	*/
	unsigned char			byTransBaudRate;		/* 透明传输的第三方波特率0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;	*/
	unsigned char			byTemp;					/*无用*/
	unsigned short			wDecoderAddress;		/*解码器地址:0 - 255*/
	char					szDecoderName[20];		/*解码器名称	*/
	unsigned short			wTrackStopTime;			/*轨迹运行后延时时间，单位为秒*/
	unsigned char			bySetCruise[16];		/* 巡航是否设置: 0-没有设置,其它值为预置点号 */
	unsigned char			bySetPreset[16];		/* 预置点是否设置0-没有设置,其它值为预置点号 */
	unsigned char			bySetTrack[16];			/* 轨迹是否设置,0-没有设置,其它值为预置点号*/
}tmDecoderCfg_t;

typedef struct tmDecoderInfo_t
{
	unsigned int			dwSize;
	char					szDecoderName[20];				/*解码器名称*/
}tmDecoderInfo_t;

/*
 *预置点新结构定义
 */
typedef struct tmPresetInfo_t
{
	char			szPresetName[128];		/* 预置点名称 */
	unsigned char	byEnable;				/* 预置点是否设置 */
	unsigned char	byTemp[3];				/* 保留 */
}tmPresetInfo_t;

typedef struct tmPresetCfg_t
{
	unsigned int	dwSize;					/*本结构大小*/
	tmPresetInfo_t	pPresetList[MAX_PRESET];/*预置点列表*/
}tmPresetCfg_t;

/*
 巡航的点信息
 */
typedef struct tmCruisePoint_t
{
	unsigned char	byEnable;				/*是否启用0,1*/
	unsigned char	byPresetNo;				/*预置点号0-MAX_PRESET-1*/
	unsigned char	byCruiseSpeed;			/*巡航速度*/
	unsigned char	byTemp;					/*保留*/
	unsigned int	dwStopTime;				/*停留时间，单位秒*/
}tmCruisePoint_t;

typedef struct tmCruiseInfo_t
{
	unsigned char	byEnableThisCruise;		/*是否启用本巡航轨迹*/
	unsigned char	byCruiseLineMerge;		/*N条线合并为一条线*/
	unsigned char	byTemp[2];
	tmCruisePoint_t	struCruise[16];			/*预置点信息*/
}tmCruiseInfo_t;

/*巡航定义*/
typedef struct tmCruiseCfg_t
{
	unsigned int	dwSize;					/*本结构大小*/
	tmCruiseInfo_t	struCruiseLine[CRUISE_MAX_LINE_NUMS];
}tmCruiseCfg_t;

typedef struct tmPtzSchedTime_t
{
	tmSchedTime_t	struSchedTime;
	unsigned char	byRunType;				/*运行类型0-巡航,1-轨迹,2-线扫*/
	unsigned char	byRunLine;				/*运行的线,0xFF为所有线	*/
	unsigned char	byTemp[2];
}tmPtzSchedTime_t;
/*云台配置信息*/
typedef struct tmPtzSchedCfg_t
{
	unsigned int		dwSize;										/*本结构大小*/
	unsigned char		byEnableKeepWatch;							/*是否启用看守位0,1*/
	unsigned char		byEnableSchedTime;							/*是否启用时间布防*/
	unsigned short		dwKeepWatchCheckTime;						/*(秒)停止云台控制一定时间后开始启用调用看守位或者在系统启动后调用看守位*/
	tmPtzSchedTime_t	struSchedTime[MAX_DAYS][MAX_TIMESEGMENT];	/*布防的时间*/
	unsigned char		byLimitMinSpeed;							/*Zoom的最小限速*/
	unsigned char		byLimitMaxSpeed;							/*Zoom的最大限速*/
	unsigned char		byManualControlPtzTime;						/*手动控制PTZ多少秒后，自动PTZ才能生效，默认30秒*/
	unsigned char		byPtzZoomMode;								/*云台动作和机芯动作先后模式，0-同时动作，1-先云台后机芯，2-先机芯后云台*/
	unsigned char		byPresetCruiseTime;							/*预置点停留时间默认值(默认为10秒)，可设置5~100秒*/
	unsigned char		byPtzTransPresetMin;						/*球机需要的特殊预置点开始号(包含)，1标示第一个,0表示不启用*/
	unsigned char		byPtzTransPresetMax;						/*球机需要的特殊预置点结束号(包含)，1标示第一个,0表示不启用*/
	unsigned char		byPtzLimitPresetMin;						/*不能使用的预置点开始号(包含)，1标示第一个,0表示不启用*/
	unsigned char		byPtzLimitPresetMax;						/*不能使用的预置点结束号(包含)，1标示第一个,0表示不启用*/
	unsigned char		byPtzUsePresetMin;							/*球机的预置点号可以使用开始号，共需要9个,0表示不启用*/
	unsigned char		bySendZoomBsMode;							/*发送变倍倍数到球机的模式0-不发送，1-发送所有倍数，2-发送整数倍数，3-变倍结束后发送倍数*/
	unsigned char		bySendSpecialtiesZoomBs;					/*发送特别倍速0-不发送，其它为特定倍数，默认3*/
	unsigned char		byViewZoomBsMode;							/*显示倍数模式0-安光学倍数显示，1-安线性倍数显示*/
    unsigned char		byAuxLinkAlarmOut;						/*zzt add  辅助开关联动报警输出*/							/*显示倍数模式0-安光学倍数显示，1-安线性倍数显示*/
	unsigned char		byLimitTemp[50];							/*保留*/
	unsigned char		byDisplayPtzInfo;							/*当操作云台是是否显示信息(zoom倍数，角度)*/
	unsigned char		byDisplayX;									/*信息显示X坐标*/
	unsigned char		byDisplayY;									/*信息显示Y坐标*/
	unsigned char		byDisplayMode;								/*信息显示参考位置，参考OSD设置*/
	unsigned char		byCruiseCaptureImage;						/*预置点巡航是否抓图，具体抓图信息依据tmCaptureImageCfg_t的配置信息*/
	unsigned char		by3DProtocal;								/*云台3D协议，0-不启用,1-hb1,2-hb2,3-sx*/
	unsigned short		byVerticallyMaxAngle;						/*云台垂直最大限制度*10*/
	unsigned char		byFocusTrace;								/*调用预置点是否跟焦*/
	unsigned char		by3DZoomMaxBS;								/*每次调用3DZoom的最大倍数*/
	unsigned char		byAlarmOutByAux;							/*报警输出通过辅助开关命令输出*/
	unsigned char		byPtzSpeedCtl;								/*wangjun add 球机变倍后速度控制参数，因为球机的速度不是线行的，所以这里只是一个大概值*/
	unsigned char		byPtzMaxSpeedCtl;							/*设置球机速度缩放比例 0 无效 1-200 最大速度的百分比*/
	unsigned char		byTmp[1];
}tmPtzSchedCfg_t;

/*云台辅助开关布防设置，可以通过此设置定时打开辅助功能*/
/*从低到高第1表示PTZ_LIGHT_PWRON*/
/*从低到高第2表示PTZ_WIPER_PWRON*/
/*从低到高第3表示PTZ_FAN_PWRON*/
/*从低到高第4表示PTZ_HEATER_PWRON*/
/*从低到高第5表示PTZ_AUX_PWRON*/
typedef struct tmPtzAuxTime_t
{
	tmSchedTime_t	struSchedTime;			/*布防时间*/
	unsigned char	byAuxEnable;			/*辅助开关使能*/
	unsigned char	byAuxState;				/*辅助开关状态*/
	unsigned char	byTemp[2];
}tmPtzAuxTime_t;

typedef struct tmPtzAuxCfg_t
{
	unsigned int	dwSize;
	unsigned char	byEnable;				/*辅助开关布防是否生效*/
	unsigned char	byTemp[3];
	tmPtzAuxTime_t	struSchedTime[MAX_DAYS][MAX_TIMESEGMENT];	/*布防的时间*/
}tmPtzAuxCfg_t;

/*----------------------------------------------------------------------*/
/*RS232串口*/
typedef struct tmPPPCfg_t
{
	unsigned int	dwSize;
	char			sRemoteIP[24];						/*远端IP地址*/
	unsigned char	byTemp1;
	char			sLocalIP[24];						/*本地IP地址*/
	unsigned char	byTemp2;
	char			sLocalIPMask[24];					/*本地IP地址掩码*/
	unsigned char	byTemp3;
	char			szUserName[32];						/* 用户名 */
	char			szPassword[32];						/* 密码 */
	unsigned char	byPPPMode;							/*PPP模式, 0－主动，1－被动	*/
	unsigned char	byRedial;							/*是否回拨:0-否,1-是*/
	unsigned char	byRedialMode;						/*回拨模式,0-由拨入者指定,1-预置回拨号码*/
	unsigned char	byDataEncrypt;						/*数据加密,0-否,1-是*/
	unsigned char	byTemp4;							
	unsigned int	dwMTU;								/*MTU*/
	char			sTelephoneNumber[32];				/*电话号码*/
}tmPPPCfg_t;

typedef struct tmRS2322Cfg_t
{
	unsigned int		dwSize;
	unsigned int		dwBaudRate;			/* 波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k; */
	unsigned char		byDataBit;				/* 数据有几位 0－5位，1－6位，2－7位，3－8位;*/
	unsigned char		byStopBit;				/* 停止位 0－1位,1－2位;*/
	unsigned char		byParity;				/* 校验 0－无校验,1－奇校验，2－偶校验;*/
	unsigned char		byFlowcontrol;			/* 0－无,1－软流控,2-硬流控*/
	unsigned int		dwWorkMode;			/* 工作模式，0－窄带传输(232串口用于PPP拨号)，1－控制台(232串口用于参数控制)，2－透明通道*/
	tmPPPCfg_t			struPPPConfig;
}tmRS2322Cfg_t;
/*----------------------------------------------------------------------*/

/*IR报警输入*/
typedef struct tmIRAlarmInCfg_t
{
	unsigned int			dwSize;
	unsigned char			byAlarmType;								/*报警器类型,0：常开,1：常闭*/
	unsigned char			byTemp;
	unsigned short			wAdcHigh;									/*读取报警有效的高值(0~1000)*/
	unsigned short			wAdcLow;									/*读取报警有效的低值(0~1000)*/
	unsigned short			wAdcCurrent;								/*读取报警有效的当前值(0~1000)，只读*/
}tmIRAlarmInCfg_t;


/*报警输入*/
typedef struct tmAlarmInCfg_t
{
	unsigned int			dwSize;
	char					sAlarmInName[32];							/* 名称 */
	unsigned char			byAlarmType;								/*报警器类型,0：常开,1：常闭*/
	unsigned char			byAlarmInHandle;							/* 是否处理 */
	tmHandleException_t		struAlarmHandleType;						/* 处理方式 */
	tmSchedTime_t			struAlarmTime[7][4];						/*布防时间*/
	tmTransFer_t			struAlarmTransFer[16];						/*触发的16个通道，在tmTransFer_t中定义通道号*/
	unsigned int			dwHandleMinTime;							/* 处理报警的最小时间，单位毫秒(在此时间内有对此报警只处理一次)*/
	unsigned short			wAdcHigh;									/*读取报警有效的高值(0~1000)*/
	unsigned short			wAdcLow;									/*读取报警有效的低值(0~1000)*/
	unsigned short			wAdcCurrent;								/*读取报警有效的当前值(0~1000)，只读*/
	unsigned short			wTemp;
}tmAlarmInCfg_t;

/*DVR报警输出320*/
typedef struct tmAlarmOutCfg_t
{
	unsigned int			dwSize;
	unsigned char			sAlarmOutName[32];							/* 名称 */
	unsigned int			dwAlarmOutDelay;							/* 输出保持时间(-1为无限，手动关闭), 毫秒 */
	tmSchedTime_t			struAlarmTime[7][4];						/* 报警输出激活时间段 */
	unsigned char			byAlarmType;								/* 报警器类型,0：常开,1：常闭 */
	unsigned char			byManualAlarmOutModle;						/* 0:由dwAlarmOutDelay决定关闭; 1:必须手动关闭*/
	unsigned char			byTemp[1];									/* 保留 */
	unsigned char			dwSchedTimType;								/* 输出布防类型,0-用时间布防，1-默认开始所有布防，2-撤防 */
}tmAlarmOutCfg_t;

/*DVR报警处理*/
typedef struct tmAlarmCfg_t
{
	/*本结构大小*/
	unsigned int	dwSize;			
				
	/*报警上传时间间隔(单位秒), 为0表示只要有连续报警，就连续输出*/
	/*仅对报警上传有效*/
	unsigned int	dwUpToTime;						

	/*报警声音延时时间	*/									
	unsigned int	dwAlarmAudioTimeout;			
	/*云台控制超时，必须大于5秒*/
	unsigned int	dwPtzControlTimeout;			
	/*控制连接超时，必须大于5秒*/
	unsigned int	dwConfigTimeout;				
	/*控制台串口连接超时，必须大于5秒*/
	unsigned int	dwSerialTimeout;				

	/*允许系统软复位,目前硬件不支持*/
	unsigned char	byAllowSoftReset;				
	/*允许配置连接超时检测*/
	unsigned char	byAllowConfigTinmeout;			
	/*是否允许服务器自动定时复位重启*/
	unsigned char	byAllowAutoReset;				
	/*允许设置参数时蜂鸣器响和指示灯亮*/
	unsigned char	byAllowConfigBeep;				

	/*循环方式，0为按指定时间循环，此模式为系统启动开始计时参考时间；*/
	/*其它为指定天数中的指定时间复位(1-31)*/
	unsigned char	byAutoResetMode;				
	/*报警上传中心类型，0客户端需要登录，1客户端不需要登录*/
	unsigned char	byAlarmToManagerType;			
	/*录像文件大小，以分钟计算0表示不录像*/
	unsigned char	byRecoderFileSize;				
	/*是否启动自动录像，为0关闭(报警触发录像)，为1一般录像，如果此时有其他报警录像则启动其他录像*/
	unsigned char	byNormalRecoder;				
	
	/*向DDNS服务器注册的时间间隔，单位秒，必须大于60秒*/
	unsigned int	dwDDNSLoginTimeOut;				
	
	/*byAutoResetMode==0时为循环时间，以秒为单位，必须大于等于60，以系统启动开始计数*/
	/*byAutoResetMode!=0为指定时刻自动复位重启的始参考时间，以秒为单位，即一天中的秒数(0-86400)*/
	unsigned int	dwAutoResetCircleTime;			
	/*自动复位标志，从低位开始，一位代表一个功能*/
	/*0位为1表示允许网络复位*/
	/*1位为1表示允许视频采集复位*/
	/*31位为1表示允许系统复位*/
	unsigned int	dwAutoResetFlags;			
	/*网络传输强制流方式,0为客户端制定，>0为指定大小传输，256-8192*/
	unsigned short	wTranstStreamSize;
	/*是否启用写文件状态灯提示*/
	unsigned char	byEnableWriteFileState;	
	/*是否上传文件操作状态到服务器，服务器需要监听UDP端口*/
	unsigned char	byUpFileStateToManager;
	/*日志保留天数1-255,依据设备而定*/
	unsigned char	byLogRemainDays;
	/*是否允许SD卡录像*/
	unsigned char	byEnableSDCardRecord;
	/*RTSP网络传输大小,0为默认*/
	unsigned short	wRtpPacketSize;	
	/*是否启用UPNP服务*/
	unsigned char	byEnableUPnp;	
}tmAlarmCfg_t;

/*----------------------------------------------------------------------*/

#define ALARMTYPE_ALARMIN				0x00
#define ALARMTYPE_DISKFULL				0x01
#define ALARMTYPE_VIDEOLOST				0x02
#define ALARMTYPE_MOTION				0x03
#define ALARMTYPE_DISKNOTFORMAT			0x04
#define ALARMTYPE_DISKACCESS			0x05
#define ALARMTYPE_CAMREAHIDE			0x06
#define ALARMTYPE_VIDEOSTANDARD			0x07
#define ALARMTYPE_UNLAWFULACCESS		0x08

#define ALARMTYPE_WuCunChuJiHua			9	//无存储计划报警	
#define ALARMTYPE_DISKWARRING			10	//磁盘异常(不健康)
#define ALARMTYPE_TongDaoWeiLuXiang		11	//通道未录像
#define ALARMTYPE_QianDuanXinHaoBaoJin	12	//前端信号量报警
#define ALARMTYPE_ACROSS_LINE			13	//跨线报警
#define ALARMTYPE_INTO					14	//区域闯入报警
#define ALARMTYPE_ABANDON				15	//遗留物体报警

/*上传报警信息156*/
typedef struct tmAlaramInfo_t
{
	unsigned int	dwSize;
	unsigned short  wAlarmType;					/*	0-信号量报警,	1-硬盘满,	2-信号丢失，3－移动侦测，
													4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配,
													8-非法访问 9-无存储计划 10-磁盘异常 11-通道未录像
													12-前端信号量报警 13-跨线报警 14-非法闯入 15-物品遗留/丢失*/

	unsigned short  wAlarmState;				/*报警状态0-结束报警，1-开始报警*/
	unsigned int	dwAlarmChannel;				/*报警输入端口*/
	unsigned int	dwAlarmOutputNumber[4];		/*报警输入端口对应的输出端口，哪一位不为-1表示对应哪一个输出*/
	unsigned int	dwAlarmRelateChannel[16];	/*报警输入端口对应的录像通道，哪一位不为-1表示对应哪一路录像*/
	unsigned int	dwDiskNumber[16];			/*dwAlarmType为4时,哪一位不为-1表示哪个硬盘*/
}tmAlaramInfo_t;

/*图像输出回调*/
typedef struct tmCaptureImageInfo_t
{
	/*本结构大小必须填写为sizeof(struct tmCaptureImageInfo_t)*/
	unsigned int	dwSize;
	
	/*抓图的用户ID,只有手动才有用*/
	unsigned int	nUserID;

	/*通道号0表示第一通道*/
	unsigned char	byChannelId;

	/*抓图方法0-自动抓拍，1-报警抓拍，2-手动抓拍*/
	unsigned char	byCaptureFunc;

	/*报警通道*/
	unsigned char	byAlarmChannel;
	
	/*缓冲指针*/
	unsigned char*	pBuffer;
	/*缓冲大小*/
	int				iBufferSize;
	/*缓冲指针*/
	unsigned char*	pBuffer2;
	/*缓冲大小*/
	int				iBuffer2Size;
	 
	/*总共抓张数*/
	int				iTotalCaptureNum;
	/*当前的序号*/
	int				iCurrentIndex;

	/*图片大小宽*/
	short			nWidth;
	/*图片大小高*/
	short			nHeight;

	/*图像格式，0-BMP, 1-JPEG, 2-H264, 3-YUV, 4-H265目前保留只能是1*/
	unsigned char	byImageFormat;
	
	/*时间戳*/
	tmTimeInfo_t	struTimeStamp;
}tmCaptureImageInfo_t;

/*上传管理中心报警信息*/
typedef struct tmToManagerAlarmInfo_t
{
	unsigned int		dwSize;
	tmAlaramInfo_t		struAlarmInfo;
	char				szDVSName[32];					/*DVS名称*/
	unsigned char		szSerialNumber[48];				/*服务器序列号*/
	unsigned char		szServerGUID[16];				/*服务器唯一GUID*/
	unsigned char		byMACAddr[6];					/*远程物理地址*/
	char				szServerIP[16];					/*服务器地址*/
	char				szServerMask[24];				/*服务器地址*/
	unsigned char		byTemp[4];
}tmToManagerAlarmInfo_t;
/*上传管理中心的图片信息定义*/
typedef struct tmToManagerImageInfo_t
{
	unsigned int		dwSize;							/*本结构大小*/
	struct
	{
		short			nWidth;							/*图片大小宽*/
		short			nHeight;						/*图片大小高*/
		unsigned char	byBitCount;						/*图像位数*/
		unsigned char	byRevolving;					/*图像是否旋转*/
		short			nPitch;							/*图片pitch*/
	}image;
	BYTE				byTemp1[8];
	unsigned char		byMACAddr[6];					/*远程物理地址*/
	unsigned char		byTemp2[2];						/*保留*/
	char				szServerIP[16];					/*服务器地址*/
	unsigned char		byImageFmt;						/*图片格式,0-JPEG,1-BMP,2-RGB555,3-RGB565,4-RGB24,*/
														/*5-RGB32,6-YUV444,7-YUV422,8-YUV420,9-BKMPEG4,10-H264,11-H265*/
	unsigned char		byCount;						/*本次抓图共要抓取张数*/
	unsigned char		byIndex;						/*当前图片的序号*/
	unsigned char		byImageMode;					/*抓图的模式0-报警联动抓图, 1-移动联动抓图, 2-手动抓图, 3-刷卡抓图, 4-预置点巡航,0FF-自动抓图*/
	unsigned char		byAlarmId;						/*报警通道*/
	unsigned char		byChannelId;					/*摄像机通道*/
	unsigned char		byOtherInfo[2];					/*保留，如果是报警，那么0，1表示其它报警器状态*/
	struct
	{
		short			nYear;
		unsigned char	nMonth;
		unsigned char	nDay;
		unsigned char	nDayOfWeek;
		unsigned char	nHour;
		unsigned char	nMinute;
		unsigned char	nSecond;
	}time;
	unsigned int		dwImageSize;					/*图像大小，也就是本结构后面数据大小*/
}tmToManagerImageInfo_t;
/*上传中心的心跳包*/
/*设备心跳包定义*/
typedef struct tmToManagerLiveHeartInfo_t
{
	/*本结构定义*/
	unsigned int		dwSize;							
	/*设备类型*/
	unsigned short		nDeviceType;					
	/*设备的厂家ID*/
	unsigned short		nFactoryId;						
	/*设备端口*/
	unsigned short		nDevicePort;					
	/*设备地址*/
	unsigned int		nDeviceAddress;					
	/*服务器唯一GUID*/
	unsigned char		nDeviceGUID[16];				
	/*设备的通道数*/
	unsigned char		nChannelCount;		
	/*报警输入数*/
	unsigned char		nAlarmInCount;
	/*报警输出个数*/
	unsigned char		nAlarmOutCount;
	/*硬盘数(分区数)*/
	unsigned char		nDiskCount;
	/*设备具体类型如(D1,HDCMA)*/
	unsigned char		nDeviceSubType;
	/*设备的网卡MARK地址，第一个主网卡*/
	unsigned char		nMarkAddress[6];	
	/*设备名称*/
	char				nDeviceName[32];
}tmToManagerLiveHeartInfo_t;

/*安全卫士设备报警信息定义*/
typedef struct tmToManagerSafeGuardInfo_t
{
	/*本结构定义*/
	unsigned int		dwSize;				
	/*设备地址*/
	unsigned int		nDeviceAddress;	
	/*设备端口*/
	unsigned short		nDevicePort;					
	/*设备的网卡MARK地址，第一个主网卡*/
	unsigned char		nMarkAddress[6];	
	
	/*设备的通行灯状态0-禁止，1-通行*/
	unsigned char		byLightState;
	/*设备的对讲按钮按下1-对讲*/
	unsigned char		byTalkState;
	/*设备的布防按钮按下0-没有按下，1-按下*/
	unsigned char		byBuFangState;
	/*设备的撤防按状态0-没有按下，1-按下*/
	unsigned char		byCheFangState;
	/*设备的报警按钮按下0-没有按下，1-按下*/
	unsigned char		byAlarmState;	
	/*设备的红外状态0-没有打开，1-打开*/
	unsigned char		byInfraredState;
	/*设备有人刷卡*/
	unsigned char		byCardEnable;
	/*卡号*/
	unsigned int		dwCardNo;
}tmToManagerSafeGuardInfo_t;

/*设备调用云台信息定义TMCC_MAJOR_CMD_SERVERMESSAGE/TMCC_MINOR_CMD_SERVERCALLPTZ*/
typedef struct tmToManagerPtzInfo_t
{
	/*本结构定义*/
	unsigned int		dwSize;				
	/*设备地址*/
	unsigned int		nDeviceAddress;	
	/*设备端口*/
	unsigned short		nDevicePort;					
	/*设备的网卡MARK地址，第一个主网卡*/
	unsigned char		nMarkAddress[6];	
	
	/*设备调用云台的类型0-调用预置点*/
	unsigned char		byCallType;
	/*预置点号*/
	unsigned char		byCallData;
	/**/
	unsigned char		byTemp[2];
	/*名称*/
	char				szCallName[32];
}tmToManagerPtzInfo_t;

/* 服务器设备信息 256*/
typedef struct tmServerInfo_t
{
	unsigned int		dwSize;							/*该结构的大小，必须填写*/
	unsigned char		bServerConnect;					/*服务器连接或是断开连接*/
	char				szDVSName[32];					/*DVS名称*/
	unsigned char		szSerialNumber[48];				/*服务器序列号*/
	unsigned char		szServerGUID[16];				/*服务器唯一GUID*/	
	unsigned char		byMACAddr[6];					/*远程物理地址*/
	char				szServerIP[25];					/*服务器地址*/
	char				szServerMask[25];				/*服务器地址*/
	char				szCenterManagerIP[25];			/*管理中心地址*/
	unsigned char		byCenterManager;				/*是否启动管理中心*/

	unsigned char		byAlarmInNum;					/*服务器输入报警个数*/
	unsigned char		byAlarmOutNum;					/*服务器输出报警个数*/
	unsigned short		wChannelNum;					/*服务器通道数*/

	unsigned int		dwServerType;					/*服务器类型*/
	unsigned short		wDVSPort;						/*端口号*/
	unsigned short		wHttpPort;						/*HTTP服务器*/
	unsigned int		dwGroupID;						/*服务器组号端口号*/
	unsigned int		dwSoftwareVersion;				/*软件版本号,高16位是主版本,低16位是次版本*/
	unsigned int		dwPanelVersion;					/*前面板版本,高16位是主版本,低16位是次版本*/
	unsigned int		dwHardwareVersion;				/*硬件版本,高16位是主版本,低16位是次版本*/
	unsigned int		dwFactoryNo;					/*服务器组厂商编号*/
}tmServerInfo_t;

typedef struct tmServerInfoEx_t
{
	unsigned int		dwSize;							/*该结构的大小，必须填写*/
	unsigned char		bServerConnect;					/*服务器连接或是断开连接*/
	char				szDVSName[32];					/*DVS名称*/
	unsigned char		szSerialNumber[48];				/*服务器序列号*/
	unsigned char		szServerGUID[16];				/*服务器唯一GUID*/	
	unsigned char		byMACAddr[6];					/*远程物理地址*/
	char				szServerIP[25];					/*服务器地址*/
	char				szServerMask[25];				/*服务器地址*/
	char				szCenterManagerIP[25];			/*管理中心地址*/
	unsigned char		byCenterManager;				/*是否启动管理中心*/

	unsigned char		byAlarmInNum;					/*服务器输入报警个数*/
	unsigned char		byAlarmOutNum;					/*服务器输出报警个数*/
	unsigned short		wChannelNum;					/*服务器通道数*/

	unsigned int		dwServerType;					/*服务器类型*/
	unsigned short		wDVSPort;						/*端口号*/
	unsigned short		wHttpPort;						/*HTTP服务器*/
	unsigned int		dwGroupID;						/*服务器组号端口号*/
	unsigned int		dwSoftwareVersion;				/*软件版本号,高16位是主版本,低16位是次版本*/
	unsigned int		dwPanelVersion;					/*前面板版本,高16位是主版本,低16位是次版本*/
	unsigned int		dwHardwareVersion;				/*硬件版本,高16位是主版本,低16位是次版本*/
	unsigned int		dwFactoryNo;					/*服务器组厂商编号*/
	unsigned int		dwRunTime;						/*服务器已运行时间*/

	unsigned short		wCurrentDVSPort;				/*当前工作端口号*/
	unsigned short		wCurrentHttpPort;				/*当前工作HTTP服务器*/
	unsigned int		dwCurrentServerIP;				/*当前工作IP*/
	unsigned int		dwCurrentServerMask;			/*当前工作IP掩码*/

	/*高清新加20090306*/
	unsigned int		dwServerGateWay;				/*服务器网关*/
	unsigned char		byEnableDhcp;					/*DHCP启用*/
	unsigned char		byEtherNet;						/*网络ID0-第一个网络，1-第二个网络*/
	unsigned char		byWifi;							/*是否是WIFI地址1为WIFI地址*/
	unsigned char		byTemp;							/*保留*/
	unsigned int		dwLastUpgradeTime;				/*设备最后一次升级时间*/
}tmServerInfoEx_t;

/*配置服务器地址结构定义*/
typedef struct tmServerCfg_t
{
	unsigned int		dwSize;							/*该结构的大小，必须填写*/
	tmServerInfo_t		pInfo[1];						/*服务器信息*/
	unsigned int		dwMajorCommand;					/*服务器配置命令*/
	unsigned int		dwMinorCommand;					/*服务器配置命令*/
	char				szUserName[32];					/*配置用户名*/
	char				szPassword[32];					/*配置的口令*/
	int					iConfigMode;					/*配置后动作，0表示无动作，1表示从新启动*/
	unsigned int		dwResverse;						/*保留*/
	unsigned int		dwResverse1;					/*保留*/
}tmServerCfg_t;

/*配置服务器地址结构定义*/
typedef struct tmServerExCfg_t
{
	unsigned int		dwSize;							/*该结构的大小，必须填写*/
	tmServerInfo_t		pInfo[1];						/*服务器信息*/
	unsigned int		dwMajorCommand;					/*服务器配置命令*/
	unsigned int		dwMinorCommand;					/*服务器配置命令*/
	char				szUserName[32];					/*配置用户名*/
	char				szPassword[32];					/*配置的口令*/
	unsigned char		iConfigMode;					/*配置后动作，0表示无动作，1表示从新启动*/
	unsigned char		bControlAll;					/*配置时是否配置所有设备*/
	unsigned char		bTemp[2];						/*保留*/
	unsigned int		dwResverse;						/*指示是否是tmServerCfg_t的扩展结构*/
														/*0表示使用tmServerInfo_t配置数据，1表示tmServerInfoEx_t配置数据*/
														/*其它值表示其它结构*/
	unsigned int		dwResverse1;					/*保留*/
	tmServerInfoEx_t	pInfoEx[1];						/*UPnp的配置信息，扩展修改只能修改tmServerInfoEx_t结构了*/
}tmServerExCfg_t;

/*多播配置结构定义*/
typedef struct tmMultiServerCfg_t
{
	unsigned int		dwSize;							/*该结构的大小，必须填写*/
	unsigned int		dwMajorCommand;					/*服务器配置命令*/
	unsigned int		dwMinorCommand;					/*服务器配置命令*/
	char				szUserName[32];					/*配置用户名*/
	char				szPassword[32];					/*配置的口令*/
	unsigned int		dwCompareSerialNumber;			/*是否需要匹配序列号，0-不匹配，设置所有，1-匹配GUID设置*/
	char				szSerialNumber[48];				/*服务器唯一序列号*/
}tmMultiServerCfg_t;

/*设备状态*/
typedef struct tmChannelState_t
{
	unsigned int		dwSize;
	unsigned char		byRecordStatic;				/*通道是否在录像,0-不录像,1-录像*/
	unsigned char		bySignalStatic;				/*连接的信号状态,0-正常,1-信号丢失*/
	unsigned char		byHardwareStatic;			/*通道硬件状态,0-正常,1-异常,例如DSP死掉*/
	unsigned char		reservedData;
	unsigned int		dwBitRate;					/*实际码率*/
	unsigned int		dwLinkNum;					/*客户端连接的个数*/
	unsigned int		dwClientIP[6];				/*客户端的IP地址*/
}tmChannelState_t;

typedef struct tmDiskState_t
{
	unsigned int		dwSize;
	unsigned int		dwVolume;							/*硬盘的容量*/
	unsigned int		dwFreeSpace;						/*硬盘的剩余空间*/
	unsigned int		dwHardDiskStatic;					/*硬盘的状态,休眠,活动,不正常等*/
}tmDiskState_t;

typedef struct tmUserState_t
{
	unsigned int		dwSize;
	char				szUserName[32];				/*登录用户名*/
	unsigned int		dwLoginNum;					/*登录数, 如果为0表示无用户登录*/
	unsigned int		dwLoginAddress[16];			/*登录地址*/
}tmUserState_t;

typedef struct tmWorkState_t
{
	unsigned int		dwSize;
	unsigned int		dwDeviceRunTime;				/*设备自上次启动来运行时间，单位秒*/
	unsigned int		dwDeviceStatic; 				/*设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误,例如串口死掉*/
	tmDiskState_t		struHardDiskStatic[16];			/*硬盘当前状态 */
	tmChannelState_t	struChanStatic[16];				/*通道的状态*/
	tmUserState_t		struUserStatic[16];				/*登录用户的状态*/
	unsigned char		byAlarmInStatic[16];			/*报警端口的状态,0-没有报警,1-有报警*/
	unsigned char		byAlarmOutStatic[4];			/*报警输出端口的状态,0-没有输出,1-有报警输出*/

	/*add by stone 20090508*/
	unsigned int		dwCpuClockFrequency;			/*CPU的频率*/
	unsigned int		dwTotalMemorySize;				/*总共内存大小*/
	unsigned int		dwFreeMemorySize;				/*剩余内存大小*/
}tmWorkState_t;

/*云台控制参数如控制多长时间，旋转角度等,大小必须小于128字节*/
/*当byControlMode==1时使用8192方法且都是相对位置，当byControlMode为其它值时使用几个方向的模式*/
typedef struct tmPtzParameter_t
{	
	unsigned int		dwAutoStopTime;					/*自动断开时间，如光圈控制*/
	int					dwZoomValue;					/*变倍*/
	int					dwVerticallyAngle;				/*垂直*/
	int					dwHorizontallyAngle;			/*水平*/
	unsigned char		byZoomMode;						/*0-拉近,1-拉远,2-绝对*/
	unsigned char		byVerticallyMode;				/*0-垂直向上,1-垂直向下,2-绝对*/
	unsigned char		byHorizontallyMode;				/*0-水平向左(仅控制位置增减),1-水平向右,2-绝对*/
	unsigned char		byControlMode;					/*控制模式: 0-使用角度*1000,1-使用坐标计算方法*8192,3-使用步数,4-使用鱼眼模式(角度，倍数x1000)*no*/
	unsigned char		byHorSpeed;						/*控制水平速度1~128*/
	unsigned char		byVerSpeed;						/*控制垂直速度1~128*/
	unsigned char		byGoPathMode;					/*控制水平方向走的路线0-最短路线走，1-水平向左，2-水平向右，3-直接到点位置(鱼眼)*/
	unsigned char		byRectRatio;			/*为了让变倍更准确，算法:A=(框宽/图像宽*100)和B=(框高/图像高*100)，byRectRatio=(A>B)?A:(B|0x80)*/
}tmPtzParameter_t;

/*
坐标计算方法：
1、以图像中心为参考原点，将图像划分成四个部分，相对于参考原点，分别为右上、左上、左下、右下，其中右、下为正，左、上为负。
2、得到当前坐标相对于原点的值，再除以单位长度，得到相对的比例值，此比例值已经与具体的分辨率无关
3、因为得到的相对比例值一定小于等于1，为了避免为小数，统一将得到的比例值乘以8192,将乘积后的值取整，作为参数填入到协议对应字节。
举例如下：
当前分辨率为1024＊768，则图像中心点坐标为(512,384)，如果目标位置坐标为(768,576),则可知目标位置处于右上，其比例值为：
水平：
（768-512）/512 = 0.5，再乘以8192，即为4096，因为是右边，所以为4096，填入对应字节即可。
垂直：
（576-384）/384 = 0.5，再乘以8192，即为4096，因为是上边，所以为-4096,填入对应字节即可。
*/

/*云台控制结构160字节*/
typedef struct tmPtzCommandCfg_t
{
	unsigned int			dwSize;						/*该结构大小，此结构实际大小可能更大*/
	unsigned int			dwPTZCommand;				/*云台控制命令*/
	unsigned int			dwPTZControl;				/*控制操作，如果是预置点命令，为预置点号*/
	unsigned int			dwAddress;
	unsigned int			dwSpeed;
	int						iPTZCodeLen;				/*PTZ命令码长度*/
	union
	{
		unsigned char		pPTZCodeBuf[256];			/*具体命令码值，当码值大于1时，从第2个码值开始*/
														/*的缓冲应紧跟此结构后*/
		tmPtzParameter_t	struParameter;				/*云台参数*/
	}data;
}tmPtzCommandCfg_t;

/*云台当前信息对应命令TMCC_MAJOR_CMD_PTZCONTROL/TMCC_MINOR_CMD_GETPTZINFO*/
/*角度需要*1000,中心点计算方法需要*8192,角度根据设备不同而不同水平360度，垂直90度*/
typedef struct tmPtzIntegrateCfg_t
{
	unsigned int				dwSize;								/*该结构大小，此结构实际大小*/
	int							dwVerticallyStation;				/*最大垂直位置*/
	int							dwHorizontallyStation;				/*最大水平位置*/
	int							dwVerticallyVisualAngle;			/*当前可视垂直位置*/
	int							dwHorizontallyVisualAngle;			/*当前可视水平位置*/
	int							dwZoomValue;						/*当前的倍数*/
	unsigned char				byControlMode;						/*控制模式0-角度(*1000)，1-步进(不*8192), 4-鱼眼模式(角度)*/
	unsigned char				byCurrentPreset;					/*当前运行在哪个预置点上，0标示没有在预置点上,1-标示1号预置点*/
	unsigned char				byPtzMode;							/*云台信息0-没有云台信息，1-一般机械球机，2-鱼眼，3-全景，4-鱼眼云台信息*/
	unsigned char				byFixMode;							/*摄像机安装模式 0-壁挂, 1-吸顶, 2-桌面*/
	int							dwMaxZoomValue;						/*最大倍数*/
	int							dwImageHorVisualAngle;				/*当前倍数的图像视角水平大小*/
	int							dwImageVerVisualAngle;				/*当前倍数的图像视角垂直大小*/
	int							dwVerticallyMinStation;				/*最小垂直位置*/
	int							dwHorizontallyMinStation;			/*最小水平位置*/
}tmPtzIntegrateCfg_t;

typedef struct tmPtzIntegrateListCfg_t
{
	unsigned int				dwSize;								/*该结构大小，此结构实际大小*/
	unsigned char				byCount;							/*列表数*/	
	unsigned char				byTemp[3];							/*保留*/
	tmPtzIntegrateCfg_t			struList[8];						/*列表*/
}tmPtzIntegrateListCfg_t;

/*物理硬盘信息结构*/
typedef struct tmDriveInfo_t
{
	unsigned char				byInit;								/*硬盘是否初始化*/
	unsigned char				byReset;							/*是否再初始化硬盘*/
	unsigned char				byFDisk;							/*硬盘是否按系统模式分区*/
	unsigned char				byTemp[1];							/*保留*/
	unsigned int				dwDriveType;						/*硬盘类型*/
	unsigned int				dwTotalSpace;						/*硬盘总空间*/
	unsigned int				dwUsefullSpace;						/*可用空间大小*/
}tmDriveInfo_t;

/*物理硬盘结构*/
typedef struct tmDriveCfg_t
{
	unsigned int				dwSize;								/*该结构大小*/
	unsigned int				dwDriveCount;						/*硬盘个数*/
	tmDriveInfo_t				struDisk[16];						/*硬盘信息*/
}tmDriveCfg_t;
#define TMCC_DRIVE_UNKNOWN			0x00
#define TMCC_DRIVE_NO_ROOT_DIR		0x01
#define TMCC_DRIVE_REMOVABLE		0x02
#define TMCC_DRIVE_FIXED			0x03
#define TMCC_DRIVE_REMOTE			0x04
#define TMCC_DRIVE_CDROM			0x05
#define TMCC_DRIVE_RAMDISK			0x06
#define TMCC_DRIVE_SDRAM			0x07

typedef struct tmDriveAlarmCfg_t
{
	unsigned int				dwSize;								/*该结构大小*/
	unsigned char				byEnableFullSpaceAlarm;				/*开启磁盘满报警*/
	unsigned char				byEnableExceptionAlarm;				/*开启磁盘异常报警*/
	unsigned char				byTemp[2];
}tmDriveAlarmCfg_t;

/*视频输入配置使用命令TMCC_MAJOR_CMD_VIDEOINCFG/TMCC_MINOR_CMD_VIDEOIN*/
typedef struct tmVideoInCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;
	
	/*50/60Hz,0-auto, 1:50Hz,2-60Hz*/
	unsigned char				byAntiFlickerMode;
	/*0:VIDEO_COLOR_STYLE_FOR_PC 1:VIDEO_COLOR_STYLE_FOR_TV;*/
	unsigned char				byVideoColorStyle;	
	/*视频输入旋转0-normal,1-180,2-90,3-270,4-vflip,5-hflip*/
	unsigned char				byRotaeAngle180;
	/*彩转黑模式0-自动，1-彩色，2-黑白*/
	unsigned char				byColorTransMode;

	/*快门模式取值范围0=1/25,1=1/30,2=1/50,3=1/60,4=1/100,5=1/120,6=1/240,7=1/480,8=1/960,9=1/1024*/
	/*10=自动,11-1/4,12-1/8,13-1/15,14-1/180,15-1/2000,16-1/4000,17-1/10000*/
	unsigned char				byShutterSpeed;
	/*AGC增益0=42dB,32=36dB,64=30dB,96=24dB,128=18dB,160=12dB,192=6dB,224-自动,225-48dB,226-54dB,227-60dB*/
	unsigned char               byAgc;	
	/*红外切换模式: 0表示自动切换模式,1表示定时切换，切换时间见下面定义*/
	/*2表示使用报警输入切换,0xFF为手动控制模式*/
	unsigned char               byIRShutMode;
	/*光圈曝光0-最大光圈;100-最小光圈, 0xFF-手动;设置光圈值时最大光圈值*/
	unsigned char				byExposure;

	/*红外打开时间和关闭时间*/
	unsigned char               byIRStartHour;
	unsigned char               byIRStartMin;
	unsigned char               byIRStopHour;
	unsigned char               byIRStopMin;

	/*0-自动, 1-快门优先, 2-自动增益优先, 3-自动光圈优先, 4-手动模式*/
	unsigned char				byModeSwitch;	
	/*白平衡控制0-关闭,1-自动,2-白炽灯,3-D4000,4-D5000,5-日光,6-阴天,7-闪光灯,8-荧光的,9-荧光的H,10-水下,0xFF-手动*/
	unsigned char				byWhiteBalance;
	/*宽动态模式0-关,1-自动,2-内部模式1X,3-内部模式2X,4-内部模式3X,5-内部模式4X, 0xFF-默认*/
	unsigned char				byWdr;
	/*背光补偿0-关，1-开*/
	unsigned char				byBlc;

	/*白平衡手动值，RB(0~16383)*/
	unsigned short				nWhiteBalanceR;
	unsigned short				nWhiteBalanceB;
	/*3D降噪0~255*/
	unsigned char				byMctfStrength;
	/*滤光片类型0-瞬间正向, 1-瞬间反向, 2-持续正向, 3-持续反向*/
	unsigned char				byIRType;
	/*切换滤光片是否控制报警输出控制红外灯(报警输出连接红外灯), 0-不联动，1-联动报警输出1，2-联动报警输出2*/
	unsigned char				byIRCutTriggerAlarmOut;
	/*滤光片切换时间默认500毫秒,0-500, 1-100, 2-200, 3-300*/
	unsigned char				byIRCutTime;

	/*曝光水平( 10 ~ 200 )*/
	unsigned char				byExposureLevel;
	/*黑白模式自动切换的亮度阀值，只有在自动模式有效*/
	unsigned char				byColorTransMin;
	unsigned char				byColorTransMax;
	/*降照级别0xFF为自动降照,0,1,2,3,4,5,6,7,8  (二级降噪)*/
	unsigned char				byNoiseFilter;

	/*是否强制降照,0/1,当为0是byNoiseFilter只是一个下限值，1-为一个固定值*/
	unsigned char				byForceNoiseFilter;
	/*曝光模式0-spot, 1-center,2-average,3-custom*/
	unsigned char				byAeMeteringMode;
	/*宽动态模式8bit，每bit标示一种模式, 全为0表示一般模式, 0位表示启用硬件宽动态, 1位表示启用HISO模式, 2位表示启用低帧率模式*/
	unsigned char				byWdrMode;
	/*报警输入联动红外的报警号(当报警输入>1时生效)，默认0，内部决定的报警输入,1-第一个报警输入，2-第二个报警输入*/
	unsigned char               byIRShutAlarmIn;
	/*使用自动对比度, 0关闭， 1-自动， <256为具体强度*/
	unsigned char               byAutoContrast;
	/*强光抑制功能0-关闭，1-6级别*/
	unsigned char				byLightInhibitionEn;

	/*强制设置帧率
	0-自动, 1-1, 2-2, 3-3, 4-4, 5-5, 6-6, 7-10, 8-12, 9-13, 10-14, 11-15, 12-20, 13-24, 14-25, 15-30, 16-50, 17-60, 18-120
	19-29.75, 20-59.94, 21-23.976, 22-12.5, 23-6.25, 24-3.125, 25-7.5, 26-3.75
	*/
	unsigned char				byVinFrameRate;

	/*曝光区域的大小*/
	unsigned char				byAeMeteringRow;
	unsigned char				byAeMeteringColumn;

	/*滤光片类型0-红波，1-蓝波, 2-x, 3-x*/
	unsigned char				byIRFilterType;

	//YUV输出类型，0-关闭YUV，1-默认， 2-主码流， 3-从码流, 从10开始参考tmCompression_t中byResolution定义-10
	unsigned char				byCaptureYuvResolution;
	//自动检测曝光补偿
	unsigned char				byAutoCheckExposureLevel;
	//明区0~255，0自动，默认128
	unsigned char				byWhiteLevel;
	//暗区0~255，0自动，默认128
	unsigned char				byBlackLevel;

	/*黑白模式自动切换的增益阀值，只有在自动模式有效*/
	unsigned char				byAgcTransMin;
	unsigned char				byAgcTransMax;

	/*快门取值最大值0-默认,其它单位为1/x*/
	unsigned short				nMaxShutterSpeed;
	/*AGC增益在byAgc基础上的增量，总的AGC=byAgc+nMaxAgc*/
	unsigned short              nMaxAgc;

	/*
	 * 此处特别注意，在有些机型上byAeMeteringData的96个字节不过，但HDR的曝光参数由没用，
	 * 所可以使用是扩展byAeMeteringData到496个
	 */
	/*曝光区域*/
	unsigned char				byAeMeteringData[96];
	
	/*HDR曝光水平( 10 ~ 200 )*/
	unsigned char				byExposureLevelHdr[4];
	/*HDR快门低限*/
	unsigned short				nMinShutterSpeedHdr[4];
	/*HDR快门高限*/
	unsigned short				nMaxShutterSpeedHdr[4];
	/*HDR最大增益*/
	unsigned char				byMaxAgcHdr[4];

	/*曝光区域*/
	unsigned char				byAeMeteringDataHdr[4][96];

}tmVideoInCfg_t;

#define WDR_MODE_HDR			0x01
#define WDR_MODE_HISO			0x02
#define WDR_MODE_LOWFRAMERATE	0x04

/*视频输入配置使用命令TMCC_MAJOR_CMD_VIDEOINCFG/TMCC_MINOR_CMD_VIDEOINEX*/
typedef struct tmVideoInExCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;
	
	/*图像模式0-一般模式,1-HDR硬件宽动态, 2-HISO模式*/
	unsigned char				byImageMode;
	/*视频输入旋转0-normal,1-180,2-90,3-270,4-vflip,5-hflip*/
	unsigned char				byRotaeAngle180;
	/*50/60Hz,0-auto, 1:50Hz,2-60Hz*/
	unsigned char				byAntiFlickerMode;
	/*0:VIDEO_COLOR_STYLE_FOR_PC 1:VIDEO_COLOR_STYLE_FOR_TV;*/
	unsigned char				byVideoColorStyle;	

	/*白平衡控制0-关闭,1-自动,2-白炽灯,3-D4000,4-D5000,5-日光,6-阴天,7-闪光灯,8-荧光的,9-荧光的H,10-水下,0xFF-手动*/
	unsigned char				byWhiteBalance;
	/*宽动态模式0-关,1-自动,2-内部模式1X,3-内部模式2X,4-内部模式3X,5-内部模式4X, 0xFF-默认*/
	unsigned char				byWdr;
	/*背光补偿0-关，1-开*/
	unsigned char				byBlc;
	/*光圈曝光0-最大光圈;100-最小光圈, 0xFF-手动;设置光圈值时最大光圈值*/
	unsigned char				byExposure;
	/*3D降噪0~255*/
	unsigned char				byMctfStrength;
	/*3a模式 0-自动, 1-快门优先, 2-增益优先, 3-光圈优先*/
	unsigned char				by3AModeSwitch;	
	/*降照级别0xFF为自动降照,0,1,2,3,4,5,6,7,8  (二级降噪)*/
	unsigned char				byNoiseFilter;
	/*是否强制降照,0/1,当为0是byNoiseFilter只是一个下限值，1-为一个固定值*/
	unsigned char				byForceNoiseFilter;

	/*使用自动对比度*/
	unsigned char               byAutoContrast;
	/*强光抑制功能*/
	unsigned char				byLightInhibitionEn;
	/*曝光模式0-spot, 1-center,2-average,3-custom*/
	unsigned char				byAeMeteringMode;
	/*保留*/
	unsigned char				byTemp[13];

	/*一些HDR模式的参数，当byImageMode==0是，只取数组0*/
	struct
	{
		/*快门速度最大值0-默认, 其它单位为1/x秒*/
		unsigned short			nMaxShutterSpeed;
		/*快门取值最小值0-默认, 其它单位为1/x秒*/
		unsigned short			nMinShutterSpeed;
		/*AGC增益dB 0~255dB*/
		unsigned char           byMaxAgc;
		/*曝光水平( 10 ~ 200 )*/
		unsigned char			byExposureLevel;
		unsigned char			byTemp[10];
		/*曝光区域*/
		unsigned char			byAeMeteringData[96];
	}table[4];

}tmVideoInExCfg_t;


typedef struct tmVideoAwbCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;

	/*是否启用*/
	BYTE						byEnableRepairAwb;
	/*原始色温是参考色温还是WB数据*/
	BYTE						byRefColorTemp;
	BYTE						byTemp[2];

	/*自动白平衡的修正值，当tmVideoInCfg_t中byWhiteBalance=0/1时有效*/
	union
	{
		struct
		{
	unsigned short				wOrgLowRGainVal;		/*低色温*/
	unsigned short				wOrgLowBGainVal;	
		}low;
		unsigned int			dwRefLowColorTemp;
	};
	
	union
	{
		struct
		{
	unsigned short				wOrgHighRGainVal;		/*高色温*/
	unsigned short				wOrgHighBGainVal;
		}high;		
		unsigned int			dwRefHighColorTemp;
	};

	unsigned short				wTargetLowRGainVal;		/*低色温*/
	unsigned short				wTargetLowBGainVal;
	unsigned short				wTargetHighRGainVal;	/*高色温*/
	unsigned short				wTargetHighBGainVal;
}tmVideoAwbCfg_t;

/*视频输入配置使用命令TMCC_MAJOR_CMD_VIDEOINCFG/TMCC_MINOR_CMD_IRCUTVIDEOIN*/
/*IRCUT切换后使用该配置*/
typedef struct tmIRCutVideoInCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;	
	/*是否启用视频参数*/
	unsigned char				byEnablePicPreview;
	/*是否启用*/
	unsigned char				byEnableVideoIn;
	/*是否启用*/
	unsigned char				byEnable;
	/*预览 标记*/
	unsigned char				byPreviewMode;
	/*视频参数*/
	tmPicPreviewCfg_t			struPicPreview;
	/*视频输入参数*/
	tmVideoInCfg_t				struVideoIn;
}tmIRCutVideoInCfg_t;

/*红外切换时间*/
typedef struct tmIRCutCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;

	/*红外打开时间和关闭时间*/
	unsigned char               byIRStartHour;
	unsigned char               byIRStartMin;
	unsigned char               byIRStopHour;
	unsigned char               byIRStopMin;

	/*红外切换模式: 0表示自动切换模式,1表示定时切换，切换时间见上面定义*/
	/*2表示使用报警输入切换,0xFF为手动控制模式*/
	unsigned char               byIRShutMode;	
	/*滤光片类型0-持续正向，1-持续反向，2-瞬间正向，3-瞬间反向*/
	unsigned char				byIRType;
	/*切换滤光片是否控制报警输出控制红外灯(报警输出连接红外灯)*/
	unsigned char				byIRCutTriggerAlarmOut;
	/*滤光片切换时间默认500毫秒,0-500, 1-100, 2-200, 3-300*/
	unsigned char				byIRCutTime;

	/*报警输入联动红外的报警号(当报警输入>1时生效)，默认0，内部决定的报警输入,1-第一个报警输入，2-第二个报警输入*/
	unsigned char               byIRShutAlarmIn;

	/*红外类型0-850NM, 1-950NM*/
	unsigned char				byCurveType;

	/*彩转黑模式0-自动，1-彩色，2-黑白*/
	unsigned char				byColorTransMode;

	/*黑白模式自动切换的亮度阀值，只有在自动模式有效*/
	unsigned char				byColorTransMin;
	unsigned char				byColorTransMax;

	/*黑白模式自动切换的增益阀值，只有在自动模式有效*/
	unsigned char				byAgcTransMin;
	unsigned char				byAgcTransMax;

}tmIRCutCfg_t;

/*视频输入配置使用命令TMCC_MAJOR_CMD_VIDEOINCFG/TMCC_MINOR_CMD_SCHEDVIDEOIN*/
typedef struct tmSchedVideoInMode_t
{
	/*该结构大小*/
	unsigned int				dwSize;
	/*是否启用*/
	unsigned char				byEnable;
	/*预览 标记*/
	unsigned char				byPreviewMode;	
	/*是否启用视频参数*/
	unsigned char				byEnablePicPreview;
	/*是否启用*/
	unsigned char				byEnableVideoIn;
	/*模式的名称*/
	char						szModeName[32];
	/*布防时间*/
	tmSchedTime_t				struSchedTime;
	/*视频输入参数*/
	tmVideoInCfg_t				struVideoIn;
	/*视频参数*/
	tmPicPreviewCfg_t			struPicPreview;
}tmSchedVideoInMode_t;

typedef struct tmSchedVideoInCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;
	/*视频输入参数*/
	tmSchedVideoInMode_t		struVideoInMode[MAX_SCHEDVIDEOINMODE];
}tmSchedVideoInCfg_t;

/*曝光模式*/
#define EXPOSURE_MODE_AUTOR				0x00
#define EXPOSURE_MODE_AUTOREX			0x01
#define EXPOSURE_MODE_MANUALBYSHUTTER	0x07
#define EXPOSURE_MODE_MANUALBYAPERTURE	0x08
#define EXPOSURE_MODE_MANUALBYAGC		0x09
#define EXPOSURE_MODE_AUTOR1			0x10
#define EXPOSURE_MODE_AUTOR2			0x20
#define EXPOSURE_MODE_AUTOR1EX			0x11
#define EXPOSURE_MODE_AUTOR2EX			0x21
#define EXPOSURE_MODE_AUTOR3EX			0x31
/*红外切换模式*/
#define IRSHUT_MODE_AUTO				0x00
#define IRSHUT_MODE_SCHEDTIME			0x01
#define IRSHUT_MODE_ALARMIN				0x02
#define IRSHUT_MODE_MANUAL				0xFF


/*镜头光圈参数配置*/
typedef struct tmApertureCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;

	/*光圈类型0-手动光圈, 1-自动光圈, 2-限制最大光圈*/
	unsigned char				byApertureType;
	/*保留*/
	unsigned char				byTemp[2];
	/*光圈的可用范围(不同镜头不一样的)*/
	unsigned char				byDutyDelta;
	/*光圈的平衡值(不同镜头不一样的)*/
	unsigned int				dwDutyBalance;
}tmApertureCfg_t;

/*一体机工作模式配置*/
typedef struct tmZoomCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;

	/*当前聚焦模式0-auto,1-zoom then focus,2-manual*/
	unsigned char				byFocusMode;
	/*切换IRCUT后是否自动转到手动聚焦模式*/
	unsigned char				byAutoManualFocus;
	/*切换IRCUT后是否自动转到手动聚焦模式的时间，秒*/
	unsigned char				byAutoManualFocusTime;
	/*红外类型0-850NM, 1-950NM*/
	unsigned char				byCurveType;
	/*最小聚焦距离: 0-默认;1-10m;2-6m;3-3m;4-2m;5-1.5m;6-1m;7-MAX*/
	unsigned char               byFocusLimt;
	/*是否启用数字变倍*/
	unsigned char               byEnableDigitalZoom;
	/*是否启用如果没有聚焦上，回到1x;0:不启用；1:启用，默认1*/
	unsigned char				byGoto1XEnable;
	/*检测参数5-200*/
	unsigned char				byGoto1XVal;
}tmZoomCfg_t;
/*聚焦模式*/
#define ZOOM_AUTO_FOCUS			0x00
#define ZOOM_THEN_FOCUS			0x01
#define ZOOM_MANUAL_FOCUS		0x02
/*红外灯类型*/
#define ZOOM_CURVE_TYPE_NORMAL	0x00
#define ZOOM_CURVE_TYPE_850NM	0x01
#define ZOOM_CURVE_TYPE_950NM	0x02

/*镜头畸变校正*/
typedef struct tmLensDeWarpCfg_t
{
	/*该结构大小*/
	unsigned int		dwSize;
	/*是否启用*/
	unsigned char		byEnable;
	/*区域选择模式*/
	unsigned char		byLensWarpMode;
	/*子区域点表示模式,0-水平/垂直角度,1-中心点坐标*/
	unsigned char		bySubregionMode;
	unsigned char		byTemp;
	/*视角大小度*1000*/
	unsigned int		dwMaxFov;
	/*鱼眼半径*/
	unsigned int		dwMaxRadius;
	/*缩放倍数*1000*/
	unsigned int		dwMaxZoom;
	
	/*区域水平/垂直角度 x1000*/
	struct
	{
		int				pan;
		int				tilt;	
	}struPantilt;
	/*区域中心点坐标 x1000*/
	struct
	{
		int				x;
		int				y;	
	}struRoi;
	/*区域选择*/
	struct
	{
		short			x;
		short			y;	
		short			cx;
		short			cy;
	}struNotrans;
	/*全景视角度数<=180, x1000 */
	unsigned int		dwHorPanorRange;
}tmLensDeWarpCfg_t;


/*视频输出配置结构使用命令TMCC_MAJOR_CMD_VIDEOOUTCFG/TMCC_MINOR_CMD_VIDEOOUT*/
typedef struct tmVideoOutCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;
	/*是否启用视频输出*/
	unsigned char				byEnableVideoOut;
	/*视频输出模式现支持YPbPr,*/
	/*0xFF:默认双码流，无模拟输出*/
	/*0-YPbPr(720p output,only模拟输出,当做模拟摄像机输出), */
	/*1-YPbPr(480p/576p out,单码流), */
	/*2-YPbPr(480i/576i out单码流),*/
	/*3-CVBS(480i/576i out单码流),暂时不支持*/
	unsigned char				byVideoOutMode;
	/*输出刷新率*/
	unsigned char				byRenovator;
	/*保留*/
	unsigned char				byResverse;

	/*视频输出分辨率*/
	unsigned short				wWidth;
	unsigned short				wHeight;	
	
}tmVideoOutCfg_t;

/*视频输出偏移配置结构使用命令TMCC_MAJOR_CMD_VIDEOOUTCFG/TMCC_MINOR_CMD_VIDEOOUTOFFSET*/
typedef struct tmVideoOutOffsetCfg_t
{
	/*该结构大小*/
	unsigned int				dwSize;

	/*视频输出偏移*/
	unsigned short				wOffsetLeft;
	unsigned short				wOffsetTop;
	unsigned short				wOffsetRight;
	unsigned short				wOffsetBottom;

	/*视频输出是否全屏显示*/
	unsigned char				byFullScreen;
	/*保留*/
	unsigned char				byResverse[3];
	
}tmVideoOutOffsetCfg_t;


/*　图像采集偏移微调定义 */
typedef struct tmVideoEptzCfg_t
{
	unsigned int	dwSize;	

	unsigned char	byClearLeft;
	unsigned char	byClearTop;
	unsigned char	byClearRight;
	unsigned char	byClearBottom;

	short			offset_x;
	short			offset_y;
	short			offset_cx;
	short			offset_cy;
}tmVideoEptzCfg_t;

/*全天录像参数配置(子结构)*/
typedef struct tmRecordDay_t
{
	/*是否全天录像 0-否 1-是*/
	unsigned char	byAllDayRecord;	
	/*0:定时录像，1:移动侦测，2:报警录像，3:动测|报警，4:动测&报警, 5:命令触发, 6: 智能录像, 7:手动录像*/
	unsigned char	byRecordType;
	/*保留*/
	unsigned char	byTemp[2];
}tmRecordDay_t;

/*时间段录像参数配置(子结构)*/
typedef struct tmRecordSched_t
{
	/*录像时间*/
	tmSchedTime_t	struRecordTime;
	/*0:定时录像，1:移动侦测，2:报警录像，3:动测|报警，4:动测&报警, 5:命令触发, 6: 智能录像, 7:手动录像*/
	unsigned char	byRecordType;
	/*保留*/
	char			byTemp[3];
}tmRecordSched_t;

/*通道本地录像参数配置*/
typedef struct tmRecordCfg_t
{
	/*本结构大小*/
	unsigned int				dwSize;
	/*全天录像*/
	tmRecordDay_t				struRecordAllDay[MAX_DAYS];
	/*录像时间段*/
	tmRecordSched_t				struRecordSched[MAX_DAYS][MAX_TIMESEGMENT];
	/*报警延时(单位:秒，>=10秒)，录像文件大小在tmAlarmCfg.byRecoderFileSize*/
	unsigned int				dwRecordTime;					
	/*预录时间(单位:秒)*/
	unsigned int				dwPreRecordTime;				
	/*录像保存的最长时间(单位:天)*/
	unsigned int				dwRecorderDuration;				
	/*是否冗余录像,重要数据双备份：0/1*/
	unsigned char				byRedundancyRec;
	/*录像时复合流编码时是否记录音频数据*/
	unsigned char				byAudioRec;
	/*录像码流为从码流0-主码流，1-从码流，2-第3码流，3-第4码流*/
	unsigned char				byRecordStream;
	/*是否启用录像*/
	unsigned char				byEnableRecord;	
	/*启用多码流录像，全景摄像机有效，第1位为第一码流等*/
	unsigned char				byMultiStreamRecord;	
	/*保留*/
	unsigned char				byTemp[3];
}tmRecordCfg_t;

/*通道FTP录像参数配置，FTP设置参考tmFTPCfg_t结构定义*/
typedef struct tmFtpRecordCfg_t
{
	/*本结构大小*/
	unsigned int				dwSize;
	/*全天录像*/
	tmRecordDay_t				struRecordAllDay[MAX_DAYS];
	/*录像时间段*/
	tmRecordSched_t				struRecordSched[MAX_DAYS][MAX_TIMESEGMENT];
	/*报警延时(单位:秒，>=10秒)，录像文件大小在tmAlarmCfg.byRecoderFileSize*/
	unsigned int				dwRecordTime;	
	/*预录时间(单位:秒)*/
	unsigned int				dwPreRecordTime;			
	/*录像时复合流编码时是否记录音频数据*/
	unsigned char				byAudioRec;
	/*录像码流为从码流*/
	unsigned char				byRecordStream;
	/*是否启用录像*/
	unsigned char				byEnableRecord;
	/*启用多码流录像，全景摄像机有效，第1位为第一码流等*/
	unsigned char				byMultiStreamRecord;
}tmFtpRecordCfg_t;


/*
 *解码器配置结构定义
 */
/*解码器的连接信息，控制通道在Command中给出*/
typedef struct tmConnectCfg_t
{
	unsigned int				dwSize;								/*该结构大小*/
	char						sRemoteIP[24];						/*远端IP地址*/
	unsigned char				byConnectMode;						/*连接的模式0-默认连接指定信息,1-指定现有的通道号(需要根据设备是否支持)*/
	char						sTurnServerIP[24];					/*转发器IP地址*/	
	unsigned char				byTemp2;
	char						szUserName[32];						/* 用户名 */
	char						szPassword[32];						/* 密码 */
	unsigned short				wConnectPort;						/* 连接端口 */
	unsigned short				wChannelID;							/* 连接的通道号 */
	unsigned short				wStreamID;							/* 连接的码流号 */	
	unsigned short				wDelayTime;							/* 循环时间(秒)，必须大于等于10秒*/
	unsigned char				byEnableTurnServer;					/* 是否启用转发器连接0-关闭，1-启用 */
	unsigned char				byStreamType;						/* 连接码流类型 */
	unsigned char				byTransType;						/* 网络传输方式 */
	unsigned char				byDisplay;							/* 是否立即处理该连接，当为循环连接时有效，其它则为立即处理 */
	unsigned char				byTemp4[2];
}tmConnectCfg_t;

/*解码通道列表信息*/
typedef struct tmConnectListCfg_t
{
	unsigned int				dwSize;								/*结构大小，需要反映实际大小sizeof(tmAlarmDeviceCfg_t)*dwCount+8*/
	unsigned int				dwCount;							/*报警设备数量*/
	tmConnectCfg_t				pConnectList[1];					/*报警设备信息列表，象征性定义一个，需要根据dwCount判断*/
}tmConnectListCfg_t;

/*解码通道配置*/
typedef struct tmWindowsCfg_t
{
	unsigned int				dwSize;								/* 该结构大小*/
	unsigned char				byImageQuant;						/* 解码质量 */
	unsigned char				byEnableState;						/* 是否显示状态 */
	unsigned char				byEnableAudio;						/* 是否播放声音 */
	unsigned char				byResverse;							/* 保留 */
}tmWindowsCfg_t;
/*显示窗口配置*/
typedef struct tmDisplayCfg_t
{
	unsigned int				dwSize;								/*该结构大小*/
	unsigned char				bySingleView;						/* 是否单画面显示 */
	unsigned char				byWindowID;							/* 需要放大显示的窗口 */
	unsigned char				byResverse[2];
}tmDisplayCfg_t;
/*连接锁定信息*/
typedef struct tmLockCfg_t
{
	unsigned int				dwSize;
	unsigned char				byLocked;
	unsigned char				byResverse[3];
}tmLockCfg_t;

/*解码器性能*/
typedef struct tmWindowCapabilityCfg_t
{
	/*本结构大小*/
	unsigned int				dwSize;

	/*系统支持窗口切换数*/
	int							iSwitchWindowNum;
	/*窗口列表*/
	unsigned char				bySwitchWindowList[32];

	/*每窗口支持寻切的摄像机数*/
	unsigned char				byCircleCount;
}tmWindowCapabilityCfg_t;

/*NVR的通道设置结构定义*/
/*add by zzt 2010-6-25*/
/*定义NVR中使用的通道信息*/

/*报警输入输出设备信息*/
typedef struct tmAlarmDeviceCfg_t
{
	unsigned int				dwSize;								/*该结构大小*/
	unsigned int				dwFactoryId;						/*设备的ID*/
	char						sName[32];							/*通道名*/
	char						sUserName[32];						/*用户名*/
	char						sPassword[32];						/*密码*/
	char						sAddress[32];						/*远端IP地址可以是域名*/
	unsigned short				wPort;								/*连接端口*/
	unsigned short				wAlarmInBase;						/*报警输入通道起始通道号*/
	unsigned short				wAlarmInNum;						/*报警输入通道数*/
	unsigned short				wAlarmOutBase;						/*报警输出通道起始号*/
	unsigned short				wAlarmOutNum;						/*报警输出通道数*/
	unsigned char				byEnable;							/*是否启用*/
	unsigned char				bySourceType;						/*只读,通道模式0-本地，1-网络*/
}tmAlarmDeviceCfg_t;

/*通道列表信息*/
typedef struct tmAlarmDeviceListCfg_t
{
	unsigned int				dwSize;								/*结构大小，需要反映实际大小sizeof(tmAlarmDeviceCfg_t)*dwCount+8*/
	unsigned int				dwCount;							/*报警设备数量*/
	tmAlarmDeviceCfg_t			pAlarmList[1];						/*报警设备信息列表，象征性定义一个，需要根据dwCount判断*/
}tmAlarmDeviceListCfg_t;

/*单个通道信息*/
typedef struct tmChannelCfg_t
{
	unsigned int				dwSize;								/*该结构大小*/
	unsigned int				dwFactoryId;						/*设备的ID*/
	char						sName[32];							/*通道名*/
	char						sUserName[32];						/*用户名*/
	char						sPassword[32];						/*密码*/
	char						sAddress[32];						/*远端IP地址可以是域名*/
	char						sTurnAddress[32];					/*转发器地址*/
	unsigned short				wPort;								/*连接端口*/
	unsigned short				wTurnPort;							/*转发器端口*/
	unsigned char				byChannelID;						/*连接的通道号*/
	unsigned char				bySubStream;						/*是否带从码流*/
	unsigned char				byTurnServer;						/*是否启用转发器连接0-关闭，1-启用*/
	unsigned char				byStreamType;						/*连接码流类型0-只处理视频流，1-处理音视频流*/
	unsigned char				byTransType;						/*网络传输方式0-内部默认协议，1-RTSP协议*/
	unsigned char				byEnable;							/*该通道是否启用*/
	unsigned char				bySourceType;						/*只读,通道模式0-本地，1-网络*/
	unsigned char				byTemp;								/*保留*/
}tmChannelCfg_t;

/*通道列表信息*/
typedef struct tmChannelListCfg_t
{
	unsigned int				dwSize;								/*结构大小，需要反映实际大小sizeof(tmChannelCfg_t)*dwCount+8*/
	unsigned int				dwCount;							/*通道数量*/
	tmChannelCfg_t				pChannelList[1];					/*通道信息列表，象征性定义一个，需要根据dwCount判断*/
}tmChannelListCfg_t;

/*RTSP配置通道信息*/
typedef struct tmRtspChannelNameInfo_t
{
	BYTE						byEnable;						/*是否启用*/
	BYTE						byTemp[3];						/*保留*/
	char						sName1[32];						/*第一码流连接名*/
	char						sName2[32];						/*第二码流连接名*/
	char						sName3[32];						/*第三码流连接名*/
	char						sName4[32];						/*第四码流连接名*/
}tmRtspChannelNameInfo_t;
typedef struct tmRtspChannelNameCfg_t
{
	unsigned int				dwSize;							/*本结构大小*/
	unsigned int				dwCount;						/*通道数*/
	tmRtspChannelNameInfo_t		struRtspName[1];				/*RTSP名称列表*/
}tmRtspChannelNameCfg_t;


/*日志信息*/
typedef struct tmLogInfo_t
{
	unsigned int			dwSize;									/*本结构大小*/
	struct
	{
		unsigned short		wYear;									/*年*/
		unsigned char		byMonth;								/*月*/
		unsigned char		byDay;									/*日*/
		unsigned char		byHour;									/*时*/
		unsigned char		byMinute;								/*分*/
		unsigned char		bySecond;								/*秒*/
		unsigned char		byTemp;									/*保留*/
	}struLogTime;													/*日志记录时间*/
	char					sUserName[32];							/*操作的用户名*/
	char					sAddress[16];							/*远程主机地址*/
	unsigned char			byUserLoginType;						/*用户登录方式0-本地，1-网络*/
	unsigned char			byMajorType;							/*主类型 0-系统, 1-报警; 2-异常; 3-操作; 0xff-全部*/
	unsigned char			byMinorType;							/*次类型 0-全部;*/
	unsigned char			byTemp;									/*保留*/
    char					sInfo[4];								/*日志类容，象征性定义4个字节*/
}tmLogInfo_t;

typedef struct tmLogInfoListCfg_t
{
	unsigned int			dwSize;									/*本结构大小*/
	unsigned int			dwCount;								/*日志条数*/
	tmLogInfo_t				struLogInfo;							/*日志列表可变大小*/
}tmLogInfoListCfg_t;

/*日志操作*/
typedef struct tmLogCfg_t
{
	unsigned int			dwSize;									/*本结构大小*/
	tmTimeInfo_t			struStartTime;							/*日志开始时间*/
	tmTimeInfo_t			struStopTime;							/*日志结束时间*/
}tmLogCfg_t;

/*摄像机经纬度配置结构配置命令TMCC_MAJOR_CMD_THEODOLITECFG*/
typedef struct tmTheodoliteCfg_t
{
	unsigned int			dwSize;									/*本结构大小*/
	int						dwLongitude;							/*经度*10000, 东经正数，西经为负数(-1800000~1800000)*/
	int						dwLatitude;								/*纬度*10000, 北纬为正数，南纬为负数(-900000~900000)*/
}tmTheodoliteCfg_t;


/*摄像机设置的点信息*/
typedef struct tmPointInfo_t
{
	unsigned short			nxPos;									/*x水平方向坐标(PAL参考704*576, NTSC参考704*480)*/
	unsigned short			nyPos;									/*y水平方向坐标(PAL参考704*576, NTSC参考704*480)*/
}tmPointInfo_t;
/*摄像机跨线检测配置*/
typedef struct tmSpanAlarmCfg_t
{
	unsigned int			dwSize;									/*本结构大小*/
}tmSpanAlarmCfg_t;

typedef struct tmFaceDetectInfo_t
{
	unsigned int		dwSize;				/*本结构大小*/
	int					iImageWidth;
	int					iImageHeight;
	int					iFaceNum;
	struct
	{
		unsigned short	x;
		unsigned short	y;
		unsigned short	cx;
		unsigned short	cy;
	}list[32];
}tmFaceDetectInfo_t;

/*数据流信息*/
typedef struct tmRealStreamInfo_t
{
	unsigned int		dwSize;				/*本结构大小*/

	unsigned char		byFrameType;		/*帧类型0-视频，1-音频，2-数据流头*/
	unsigned char		byNeedReset;		/*是否需要复位解码器*/
	unsigned char		byKeyFrame;			/*是否关键帧*/
	unsigned char		byStreamNo;			/*码流号*/

	unsigned int		dwFactoryId;		/*厂家ID	*/
	unsigned int		dwStreamTag;		/*流类型Tag*/
	unsigned int		dwStreamId;			/*流ID*/
	union
	{
		int				iWidth;				/*视频宽*/
		int				iSamplesPerSec;		/*音频采样率*/
	};
	union
	{
		int				iHeight;			/*视频高*/
		int				iBitsPerSample;		/*音频采样位数*/
	};
	union
	{
		struct
		{
			short		iFrameRate;			/*帧率*1000，如果<1000就是实际的帧率不用*1000*/
			short		iDisplayFrameRate;	/*帧率*1000，如果<1000就是实际的帧率不用*1000*/
		}framerate;
		int				iChannels;			/*音频的声道数*/
	};
	
	/*add by 2009-0429*/
	union
	{
		unsigned int	nDisplayScale;	/*显示比例*1000*/
	};
	
	unsigned int		dwTimeStamp;	/*时间戳(单位毫秒)*/
	unsigned int		dwPlayTime;		/*此帧播放时间(单位毫秒)*/
	unsigned int		dwBitRate;		/*此数据流的码流大小*/	

	BYTE*				pBuffer;		/*数据缓冲*/
	int					iBufferSize;	/*数据大小*/
	
	BYTE*				pBuffer2;		/*数据2缓冲*/
	int					iBuffer2Size;	/*数据2大小*/

	BYTE				bInterlacer;
	BYTE				byTemp[3];

	BYTE*				pBuffer3;		/*数据3缓冲*/
	int					iBuffer3Size;	/*数据3大小*/

	BYTE*				pBuffer4;		/*数据4缓冲*/
	int					iBuffer4Size;	/*数据4大小*/

	tmFaceDetectInfo_t*	pFaceDetect;	/*人脸检测结果*/

	BYTE*				pMotionRectList;/*移动侦测信息*/
	int					iMotionRectSize;	

	BYTE*				pBuffer5;		/*数据5缓冲*/
	int					iBuffer5Size;	/*数据5大小*/

	BYTE*				pBuffer6;		/*数据6缓冲*/
	int					iBuffer6Size;	/*数据6大小*/	

	BYTE*				pBuffer7;		/*数据7缓冲*/
	int					iBuffer7Size;	/*数据7大小*/

	BYTE*				pBuffer8;		/*数据8缓冲*/
	int					iBuffer8Size;	/*数据8大小*/
}tmRealStreamInfo_t;

/*数据流头信息*/
typedef struct tmAvInfo_t
{
	/*视频*/
	unsigned char		byVideo;			/*是否带视频*/
	unsigned char		byInterlacer;		/*视频是Interlacer*/
	unsigned char		byStreamId;			/*码流号*/
	unsigned char		byVideoIndex;		/*码流序号*/
	unsigned int		dwVideoTag;			/*流类型Tag*/
	unsigned int		dwVideoId;			/*流ID*/
	unsigned short		nWidth;				/*视频宽*/
	unsigned short		nHeight;			/*视频高*/
	unsigned short		nDisplayScale;		/*显示比例*1000*/
	unsigned short		nTempV;				
	unsigned int		dwFrameRate;		/*帧率*1000*/
	unsigned int		dwVideoBitRate;		/*此数据流的码流大小*/

	/*音频*/
	unsigned char		byAudio;			/*是否采集音频	*/
	unsigned char		byBitsPerSample;	/*音频采样位数*/
	unsigned char		byChannels;			/*音频的声道数*/
	unsigned char		byAudioIndex;		/*码流序号*/
	unsigned int		dwAudioTag;			/*音频流类型Tag*/
	unsigned int		dwAudioId;			/*音频流ID	*/
	unsigned int		dwSamplesPerSec;	/*音频采样率*/
	unsigned int		dwAudioBitRate;		/*此音频流的码流大小*/
	unsigned int		dwSampleSize;		/*一个音频包包含多少帧*/
	unsigned int		dwTempA;
}tmAvInfo_t;
typedef struct tmRealStreamHeadCfg_t
{
	unsigned int			dwSize;				/*本就够大小*/
	unsigned int			nFileTotalTime;		/*文件总时间*/
	unsigned short			nFactoryId;			/*厂家ID	*/
	unsigned short			nStreamNum;			/*码流数	*/
	tmAvInfo_t				struStream[8];		/*数据流音视频信息	*/	
}tmRealStreamHeadCfg_t;

/*
 *多码流数据结构定义
 */
typedef struct tmMultiStreamInfo_t
{
	unsigned int		dwSize;						/*本结构大小*/
	unsigned char		byEnableMultiView;			/*启用多码流同时显示*/
	unsigned char		byCurrentStream;			/*解码显示码流，默认是0*/
	unsigned char		byStreamNum;				/*码流中的码流数*/
	unsigned char		byTemp;						/*保留*/
	tmAvInfo_t			stream[8];					/*码流信息列表*/
	struct
	{
		HWND			hWnd;						/*显示窗口句柄*/
		RECT			rcView;						/*显示相对于窗口的位置*/
		unsigned char	byAutoFitWindow;			/*显示的模式0-使用rcView显示，1-当窗口自适应模式，2-2窗口自适应模式*/
													/*3-4窗口自适应模式, 4*9窗口自适应模式*/
		unsigned char	byWindowIndex;				/*多窗口自适应模式的窗口id*/
		unsigned char	byLockDisplayScale;			/*是否锁定显示比例*/
	}view[8];
}tmMultiStreamInfo_t;

/*
 *文件播放
 */
/*文件搜索条件定义*/
typedef struct tmFindConditionCfg_t
{
	unsigned int			dwSize;				/*本结构大小*/
	unsigned char			byChannel;			/*搜索的通道*/
	unsigned char			byFileType;			/*搜索类型 0xFF-全部，'N'-定时，'M'-移动，'A'-报警，'H'-手动，'O'-其它*/
	unsigned char			bySearchAllTime;	/*搜索所有时间文件*/
	unsigned char			bySearchImage;		/*是否搜索图片*/
	tmTimeInfo_t			struStartTime;		/*搜索的开始时间*/
	tmTimeInfo_t			struStopTime;		/*搜索的结束时间*/
	unsigned char			byEnableServer;		/*是否启用网络参数*/
	unsigned char			byOldServer;		/*是否是老设备*/
	unsigned char			byBackupData;		/*是否搜索备份文件*/
	unsigned char			byTemp;
	char					sServerAddress[32];	/*服务器地址*/
	unsigned int			dwServerPort;		/*服务器端口*/	
	char					sUserName[32];		/*用户名*/
	char					sUserPass[32];		/*用户密码*/
}tmFindConditionCfg_t;

/*搜索到的录像文件信息*/
typedef struct tmFindFileCfg_t
{
	unsigned int			dwSize;	
	char					sFileName[64];		/*文件名*/
	unsigned char			byChannel;			/*搜索的通道*/
	union
	{
		unsigned char		byAlarmType;		/*搜索类型 0xFF-全部，'N'-定时，'M'-移动，'A'-报警，'H'-手动，'O'-其它*/
		unsigned char		byFileType;			/*搜索类型 0xFF-全部，'N'-定时，'M'-移动，'A'-报警，'H'-手动，'C'-命令(断网), 'Z'-智能，'B'动测&报警,'O'-其它*/
	};
	unsigned short			wFactoryId;			/*厂商ID*/
	tmTimeInfo_t			struStartTime;		/*文件的开始时间*/
	tmTimeInfo_t			struStopTime;		/*文件的结束时间*/
	unsigned int			dwFileTime;			/*文件时间，毫秒*/
	unsigned int			dwFileSize;			/*文件的大小(字节表示，所以录像文件不能太大)*/
	unsigned char			byImage;			/*文件是否为图片*/
	unsigned char			byFileFormat;		/*文件格式*/
	unsigned char			byBackupData;		/*是否是备份文件*/
	unsigned char			byDiskName;			/*所在磁盘*/
}tmFindFileCfg_t;

/*文件播放回调接口定义*/
/*文件访问接口回调结构定义*/
typedef struct tmFileAccessInterface_t
{
	HANDLE			(*Open)( const char* lpFileName, const char* lpMode, void* context );
	int				(*Close)(HANDLE hFile);
	unsigned int	(*Seek)( HANDLE hFile, int offset, int origin );
	int				(*Read)( HANDLE hFile, void* lpBuffer, int nRead );
	int				(*Write)( HANDLE hFile, void* lpBuffer, int nWrite );
	unsigned int	(*Size)( HANDLE hFile );
}tmFileAccessInterface_t;

/*文件索引结构定义*/
typedef struct tmAvIndexEntry_t
{
    unsigned int	ckid;
    unsigned int	dwFlags;
    unsigned int	dwChunkOffset;
    unsigned int	dwChunkLength;
}tmAvIndexEntry_t;
/*索引中dwFlags值*/
#define AVIIF_LIST							0x00000001L /* chunk is a 'LIST'*/
#define AVIIF_KEYFRAME						0x00000010L /* this frame is a key frame.*/
#define AVIIF_NOTIME						0x00000100L /* this frame doesn't take any time*/
#define AVIIF_COMPUSE						0x0FFF0000L /* these bits are for compressor use*/

/*远程文件访问接口回调结构定义*/
typedef struct tmRemoteFileInfo_t
{
	/*本结构大小*/
	unsigned int		dwSize;
	
	/*打开的文件头*/
	unsigned char*		pHeadBuf;
	int					iHeadSize;
	
	/*索引*/
	tmAvIndexEntry_t*	pIndexBuf;
	int					iIndexCount;
	
	int					iTotalFrames;	// 总帧率
	int					iTotalTime;		// 总时间
	
	/*回调关联指针*/
	void*				pContext;
	/*读取文件帧回调*/
	int					(*Read)( HANDLE hObject, void* lpBuffer, int nRead, unsigned int* dwCodeTag, int* nNeedBufSize, void* context );
	/*设置文件位置*/
	int					(*Seek)( HANDLE hObject, int offset, int origin, int* iPosition, unsigned int* iTimeStamp, void* context );
	
	/*解码方式*/
	unsigned char		byDecoderType;
}tmRemoteFileInfo_t;

/*文件播放条件定义*/
typedef struct tmPlayConditionCfg_t
{
	unsigned int						dwSize;	
	unsigned short						wFactoryId;				/*厂商ID*/
	unsigned char						byChannel;				/*通道	*/
	unsigned char						byPlayImage;			/*是否操作图片*/
	union
	{
		/*服务器文件全是用此结构148*/
		struct
		{
			tmTimeInfo_t				struStartTime;			/*文件的开始时间*/
			tmTimeInfo_t				struStopTime;			/*文件的结束时间*/
			unsigned char				byCheckStopTime;		/*是否检测结束时间*/
			unsigned char				byAlarmType;			/*报警类型*/
			unsigned char				byFileFormat;			/*0-JPEG,1-JPEG2000,2-RGB555,3-RGB565,4-RGB24,*/
																/*5-RGB32,6-YUV444,7-YUV422,8-YUV420,9-BKMPEG4,10-H264文件格式20-AVI,21-MKV*/
			unsigned char				byBackupData;			/*是否是备份文件*/
			unsigned char				byDiskName;				/*所在磁盘*/
			unsigned char				byConvertToJpeg;		/*非JPEG强制转换成JPEG*/
			char						byReserves[18];
			char						sServerAddress[32];		/*服务器地址*/
			unsigned int				dwServerPort;			/*服务器端口*/	
			char						sUserName[32];			/*用户名*/
			char						sUserPass[32];			/*用户密码*/
		}time;
		/*本地文件是用此结构148*/
		struct
		{
			unsigned char				byAutoCreateIndex;		/*是否自动生成索引*/
			unsigned char				byAutoPlay;				/*打开后是否自动播放*/
			unsigned char				byTemp[2];
			char						sFileName[128];			/*文件名*/
			tmFileAccessInterface_t*	pFileCallBack;			/*文件访问回调函数*/
			void*						pFileContext;			/*文件访问相关句柄*/
			tmAvIndexEntry_t*			pAvIndex;				/*索引缓冲*/
			int							iAvIndexCount;			/*缓冲中的索引数*/
		}file;
	}info;

	unsigned char						byBufferBeforePlay;		/*开始播放是否需要缓冲数据*/
	unsigned char						byEnableServer;			/*是否启用网络参数*/
	unsigned char						byPlayType;				/*播放方式*/
	unsigned char						byDecoderType;			/*解码方式*/
	unsigned int						dwBufferSizeBeforePlay;	/*缓冲大小*/

	/*数据回调函数回调函数*/
	int									(CALLBACK *fnStreamReadCallBack)( HANDLE hTmCC, tmRealStreamInfo_t* pStreamInfo, void* context );
	void*								fnStreamReadContext;

	/*多码流显示回调*/
//	int									(CALLBACK *fnMultiStreamCallBack)( HANDLE hTmCC, tmMultiStreamInfo_t* pMultiStream, void* context );
//	void*								fnMultiStreamContext;
}tmPlayConditionCfg_t;

/*远程文件播放方式*/
#define REMOTEPLAY_MODE_BUFFILE			0x00	/*解码显示播放，需要本地缓冲，此方式占用网络带快大*/
#define REMOTEPLAY_MODE_NOBUFFILE		0x01	/*解码显示，不带本地缓冲，此方式占用网络带宽与码流大小一致*/
#define REMOTEPLAY_MODE_OLDFILE			0x02	/*老方式播放文件，主要是a2的摄像机*/
#define REMOTEPLAY_MODE_LOCALFILE		0x03	/*本地文件*/
#define REMOTEPLAY_MODE_READFILE		0x04	/*不解码显示，为TMCC_ReadFile提供支持*/
#define REMOTEPLAY_MODE_CONTROLFILE		0x05	/*服务器控制视频的速率*/


/*文件下载条件定义*/
typedef struct tmDownloadFileCfg_t
{
	unsigned int			dwSize;				/*本结构大小*/
	tmPlayConditionCfg_t	struCondition;		/*文件条件*/

	char					sFileName[128];		/*本地文件名*/
}tmDownloadFileCfg_t;


/*远程文件打开控制结构定义*/
#define PLAY_CONTROL_PLAY				0		/*播放,以iPlayData作为播放参数(0-保留当前设置,1-回复默认)*/
#define PLAY_CONTROL_STOP				1		/*停止*/
#define PLAY_CONTROL_PAUSE				2		/*暂停,注意停止直接调用相关关闭函数即可*/
#define PLAY_CONTROL_FAST				3		/*快放,以iSpeed作为速度*/
#define PLAY_CONTROL_SLOW				4		/*慢放,以iSpeed作为速度*/
#define PLAY_CONTROL_SEEKPOS			5		/*seek,以iCurrentPosition*/
#define PLAY_CONTROL_SEEKTIME			6		/*seek,以dwCurrentTime作为时间*/
#define PLAY_CONTROL_STEMP				7		/*stemp,单帧播放*/
#define PLAY_CONTROL_SWITCH				8		/*切换文件,以szFileName作为文件名/或struTime时间*/
#define PLAY_CONTROL_MUTE				9		/*音频开关,以iEnableAudio作为开关*/
#define PLAY_CONTROL_UPEND				10		/*倒放*/
#define PLAY_CONTROL_GETAVINDEX			11		/*得到本地文件的索引*/
#define PLAY_CONTROL_SETAVINDEX			12		/*设置播放文件的索引*/
#define PLAY_CONTROL_AUTORESETBUFTIME	13		/*设置是否自动调节缓冲时间*/
#define PLAY_CONTROL_SEEKTIME_NEW		14		/*seek,以struTime作为时间  绝对时间   jukin add for gb*/
#define PLAY_CONTROL_REPAIRFILE			15		/*修复文件索引*/

typedef struct tmPlayControlCfg_t
{
	unsigned int				dwSize;				/*本结构大小*/
	unsigned int				dwCommand;			/*控制命令	*/										
	union
	{
		tmTimeInfo_t			struTime;			/*文件的开始时间*/
		int						iPlayData;			/*播放参数*/
		int						iSpeed;				/*播放的速度*/
		int						iEnableAudio;		/*音频开关*/
		int						iCurrentPosition;	/*新的播放位置(帧)*/
		unsigned int			dwCurrentTime;		/*新的播放位置(毫秒)*/
		BOOL					bForward;			/*前进单帧*/
		BOOL					bClearDisplay;		/*清空显示*/
		BOOL					bAutoResetBufTime;	/*是否自动调节缓冲*/
		struct
		{
			unsigned char		byAutoCreateIndex;	/*是否自动生成索引*/
			unsigned char		byAutoPlay;			/*打开后是否自动播放*/
			unsigned char		byTemp[2];
			char				sFileName[128];		/*切换到文件名*/
		}file;
		struct
		{
			tmAvIndexEntry_t*	pAvIndex;			/*索引缓冲*/
			int					iAvIndexCount;		/*缓冲中的索引数*/
			int					iAvIndexMaxCount;	/*缓冲的总索引数*/
		}index;
	}control;
}tmPlayControlCfg_t;

/*播放文件的当前信息*/
typedef struct tmPlayStateCfg_t
{
	unsigned int			dwSize;				/*本结构大小*/
	unsigned char			byCurrentState;		/*当前播放状态*/
	unsigned char			byResetTime;		/*需要复位时间戳*/
	unsigned char			byResetFile;		/*需要复位时间戳*/
	unsigned char			byIndex;			/*当前文件下载数*/

	unsigned int			dwTotalFrames;		/*总共帧数*/
	unsigned int			dwCurrentFrame;		/*当前帧数*/

	unsigned int			dwTotalTimes;		/*总时间(毫秒)*/
	unsigned int			dwCurrentTimes;		/*当前时间(毫秒)*/
	
	tmTimeInfo_t			struStartTime;		/*当前播放文件的开始时间*/

	unsigned int			dwTotalSize;		/*总文件大小*/
	unsigned int			dwCurrentSize;		/*当前文件大小*/
}tmPlayStateCfg_t;

/*数据流播放参数结构定义*/
/*文件播放条件定义*/
typedef struct tmPlayRealStreamCfg_t
{
	unsigned int			dwSize;	
	char					szAddress[32];		/*连接服务器的IP地址*/
	char					szTurnAddress[32];	/*转发器地址*/
	int						iPort;				/*服务器连接的端口*/
	char					szUser[32];			/*登录用户名*/
	char					szPass[32];			/*登录用户口令*/
	unsigned char			byChannel;			/*通道*/
	unsigned char			byStream;			/*码流号*/
	unsigned char			byTranstType;		/*传输类型*/
	unsigned char			byReConnectNum;		/*从连次数	*/
	int						iTranstPackSize;	/*传输包大小*/
	int						iReConnectTime;		/*重连的时间间隔*/
	unsigned char			byTransProtocol;	/*传输协议0-内部自定,1-SONY,2-RTSP	*/
	unsigned char			byForceDecode;		/*当现实窗口为空时是否需要强制解码输出*/
	unsigned char			byDecoderType;		/*解码方式*/
	unsigned char			byConnectType;		/*连接类型0-TcpIp,1-Udp,2-Dialing,3-TcpMulti,4-UdpMulti*/
	char					szParameter[128];	/*连接参数*/
	unsigned char			byMultiStream;		/*多码流列表，第一位标示第1码流，第二位标示第2码流...*/
	unsigned char			byTemp[3];
}tmPlayRealStreamCfg_t;

/*音视频原始帧信息*/
typedef struct tmAvImageInfo_t
{
	BYTE			video;				/*是否是视频*/
	BYTE			face;				/*是否有人脸检测结果，有那么yuv[3]是tmFaceDetectInfo_t指针*/
	BYTE			temp[2];
	union
	{
		BYTE*		yuv[4];				/* 当输出格式为YUV420时，yuv[0] Y数据；yuv[1] U数据 yuv[2] V数据，当face==1时yuv[3]为人脸检测结果指针*/
		BYTE*		buffer;				/*RGB格式使用这个指针，一行的字节数对应bufsize*/
	}data;

	union
	{
		int			linesize[4];		/*分别对应YUV一行数据的字节数，可能比图像宽度大，比如格式为YUV420，那么 linesize[0] Y的宽度；linesize[1] U的宽度 ；linesize[2] V的宽度*/
		int			bufsize;			/*一行数据的字节数，比如格式为RGB24，那么这个值一般为width乘以3*/
	}size;

	union
	{
		struct
		{
			short	width;
			short	height;
			int		framerate;
			BYTE	format;
			BYTE	temp[3];
		}video;
		struct
		{
			int		samplespersec;
			BYTE	channels;
			BYTE	bitspersample;
		}audio;
		BYTE		temp[16];
	}format;

	int				key_frame;	
	unsigned int	timestamp;
}tmAvImageInfo_t;


typedef enum
{
	RECORD_STATUS_STOP = 0x00,
	RECORD_STATUS_PAUSE,
	RECORD_STATUS_WORKING,
	RECORD_STATUS_ABNORMAL
}enumRecordStatus;

typedef struct tmReportRecordStatus_t		/*TMCC_MINOR_CMD_STORAGESTATUS*/
{
	unsigned int		dwSize;				/*本结构大小*/
	
	enumRecordStatus	enRecordStatus;		
	BYTE				byRecordType;
}tmReportRecordStatus_t;


typedef struct tmPtzSoftVersion_t		/*TMCC_MINOR_CMD_PTZ_VERSION*/
{
	unsigned int		dwSize;				/*本结构大小*/
	
	WORD				wptzSoftVersion;
	BYTE				byUnuse[2];
	DWORD				dwUnuse[2];
}tmPtzSoftVersion_t;

typedef struct tmPtzExtendedFunctionCfg_t				/*TMCC_MINOR_CMD_PTZ_CFG_EX*/
{
	unsigned int		dwSize;							/*本结构大小*/
	
	BYTE				byUartAlarmDisEn;				/*串口模式报警使能       0:开启串口报警输入输出  1:关闭*/
	BYTE				byQueryAlarmDisEn;				/*取消报警主动查询功能 0:主动查询 1:不主动查询*/
	BYTE				bySendIrCutStatusDisEn;			/*IRCUT上报使能 0:上报  1:不上报*/
	BYTE				byIrisCmdCtrlLaserDisEn;		/*关闭原有的光圈控制功能 0:正常IRIS控制 1:关闭正常控制 发送球机 */
		
	BYTE				byPM2_5En;						/*当3D选择5时，pm2.5使能才有效*/
	BYTE				byVDMProtocolEn;				/*VDM协议使能*/
	BYTE				byYtjCmdSendToPanDisEn;			/*控制机芯命令发送到，0,发送，1不发送*/
	BYTE				byPtzAutoAddSpeed;				/*上下左右命令自动加速 0:不加速,其它加速等级*/
	BYTE				byOsdDisplayPresetEn;			/*0:不显示,1:在OSD上显示当前调用的预置点*/
	BYTE				byUnuse[3];
	DWORD				dwUnuse[2];
}tmPtzExtendedFunctionCfg_t;


/*add by 2014-05-27*/
/*#define TMCC_MINOR_CMD_SCREENINFO					0x0A		解码器屏幕描述*/
typedef struct tmScreenInfo_t
{
	unsigned char	byScreenId;		/*屏幕ID*/
	unsigned char	byScreenType;	/*0(4:3) 1(16:9)*/
	unsigned char	byChanCount;	/*通道数*/
	unsigned char	byStartNumber;	/*通道起始编号*/
}tmScreenInfo_t;

typedef struct tmScreenInfoCfg_t
{
	unsigned int	dwSize;			/*结构大小*/
	unsigned int	dwCount;		/*屏幕数*/
	tmScreenInfo_t	struScreen[1];
}tmScreenInfoCfg_t;

/*
* 命令：TMCC_MAJOR_CMD_VIDEOPARAMCFG //add by tzh
* 用TMCC_SetConfig设置显示图像参数，句柄是正在播放视频的句柄，无需先TMCC_Connect 
**/
typedef struct tagVideoParamCfg_t
{
	unsigned int		dwSize;			/* 本结构大小*/
	BYTE				bUsed[4];		/* bUsed[0]开关亮度、对比度、Gama调整；bUsed[1]开关饱和度、色度调整；bUsed[2]bUsed[3]保留	*/
	int					iBrightness;	/* 亮度			0-255*/
	int					iContrast;		/* 对比度		0-255	*/
	int					iThreshold;		/* 对比度阈值	0-255*/
	float				fGama;			/* gama调整		0.1-3.0*/
	int					iSaturation;	/* 饱和度		0-255*/
	int					iHue;			/* 色度			0-255*/
}tmVideoParamCfg_t;

#define MAXPOINTNUMINPOLYGON						20		/*每个闯入区域的最大顶点个数*/
#define MAX_CHECK_NUM								5		/*跨线最大数*/
/*跨线检测的方式*/
#define  MOTIONLINE_METHOD_LEFTTORIGHT				0x01	/*左边跨到右边*/
#define	 MOTIONLINE_METHOD_RIGHTTOLEFT				0x02	/*右边跨到左边*/
#define  MOTIONLINE_METHOD_TOPTOBOTTOM				0x04	/*上边跨到下边*/
#define  MOTIONLINE_METHOD_BOTTOMTOTOP				0x08	/*下边跨到上边*/

/*顶点坐标信息*/
typedef	struct  tmPoint_t
{
	int		x;
	int		y;
}tmPoint_t;

/*线基本信息*/
typedef struct tmLineInfo_t
{
	int						iMethod;				/*侦测方法*/
	unsigned char			byMotionSensitive;		/*跨线检测灵敏度, 0 - 100,越高越灵敏 灵敏度越高越小的物体跨线越容易被检测到*/
	unsigned char			bytmp[3];
	tmPoint_t				pStarPostion;			/*线的开始位置*/
	tmPoint_t				pStopPostion;			/*线的结束位置*/
}tmLineInfo_t;

/*跨线检测的配置信息*/
typedef struct  tmMotionLineCfg_t
{
	unsigned int			dwSize;
	BOOL					bEnable;									/*是否启动侦测*/
	unsigned char			LineNum;				
	unsigned char			byTmp[3];
	tmLineInfo_t			pLineList[MAX_CHECK_NUM];
	tmHandleException_t		strMotionHandleType;						/*处理方式*/
	tmSchedTime_t			struAlarmTime[7][4];						/*布防时间*/
	tmTransFer_t			struAlarmTransFer[16];						/*触发通道*/
}tmMotionLineCfg_t;

/*每个区域信息*/
typedef	struct tmPolygonScope_t
{
	int						byPointNum;								/*用到顶点个数*/
	unsigned char			byPolygonSensitive;						/*区域检测的灵敏度， 0-100值越大，越小的物体闯入区域就越能被检测到*/
	unsigned char			byPolygonTime;							/*时间阈值: 时间阀值：表示目标进入警戒区域持续停留多久后产生报警,0-10s 如果为0表示闯入就会报警*/
	unsigned char			byTmp[2];
	tmPoint_t				pPointList[MAXPOINTNUMINPOLYGON];		/*坐标的范围为704*576；*/
}tmPolygonScope_t;

/*区域检测的配置参数*/
typedef struct tmPolygonCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnableAbandon;						/*是否处理区域侦测*/
	unsigned char			byPolygonScopeNum;						/*多边形区域个数，必须小于或等于5*/
	unsigned char			byTmp[2];
	tmPolygonScope_t		pPolygonScope[MAX_CHECK_NUM];
	tmHandleException_t		strMotionHandleType;					/*处理方式*/
	tmSchedTime_t			struAlarmTime[7][4];					/*布防时间*/
	tmTransFer_t			struAlarmTransFer[16];					/*触发通道*/
}tmPolygonCfg_t;


/*****************流量统计的方向*************************/

//重新定义方向，与客户端保持一致
#define FLOWLINE_ACTION_RIGHT						0x04		/*右边为进*/
#define	FLOWLINE_ACTION_LEFT						0x03		/*左边为进*/
#define FLOWLINE_ACTION_BOTTOM						0x02		/*下边为进*/
#define FLOWLINE_ACTION_TOP							0x01		/*上边为进*/



typedef struct  tmFlowLine_t
{
	int						iMethod;				/*统计方向*/
	tmPoint_t				pStarPostion;			/*线的开始位置*/
	tmPoint_t				pStopPostion;			/*线的结束位置*/
	unsigned char			byMotionSensitive;		/*流量检测灵敏度, 0 - 100,越高越灵敏 灵敏度越高越小的物体越容易被检测到*/
	unsigned char			byTmp[3];
	int						iEnterCount;			/*进量*/
	int						iExitCount;				/*出量*/
}tmFlowLine_t;

/*流量统计配置参数*/
typedef struct  tmFlowCountCfg_t
{
	unsigned int			dwSize;
	unsigned char			byEnable;									/*是否流量统计*/
	unsigned char			LineNum;		
	unsigned char			byTmp[2];
	tmFlowLine_t			pFlowList[MAX_CHECK_NUM];
	tmHandleException_t		strMotionHandleType;						/*处理方式*/
	tmSchedTime_t			struAlarmTime[7][4];						/*布防时间*/
	tmTransFer_t			struAlarmTransFer[16];						/*触发通道*/
}tmFlowCountCfg_t;


typedef	 struct tmAbandonInfo_t
{
	unsigned char			byAbandonSensitive;							/*遗留检测灵敏度, 0 - 100,越高越灵敏 灵敏度越高越小的物体越容易被检测到*/
	unsigned char			byCheckTime;								/*物体持续10-120s在区域内遗留报警*/
	unsigned char			byTmp[2];
	tmAreaScope_t			struAbandonScope;							/*遗留区域704*576*/
}tmAbandonInfo_t;

/*遗留侦测*/
typedef	struct tmAbandonCfg_t
{
	unsigned int			dwSize;
	unsigned char			byAbandonScopeNum;							/*遗留区域个数，必须小于或等于5*/
	unsigned char			byEnableAbandon;							/*是否处理遗留侦测*/
	unsigned char			byTmp[2];
	tmAbandonInfo_t			strAbandonList[MAX_CHECK_NUM];		
	tmHandleException_t		strMotionHandleType;						/*处理方式*/
	tmSchedTime_t			struAlarmTime[7][4];						/*布防时间*/
	tmTransFer_t			struAlarmTransFer[16];		
}tmAbandonCfg_t;

/*移动物体坐标信息*/
typedef struct tagtmPostionResult_t    /*移动物体的坐标和大小*/
{
	unsigned short		wX;
	unsigned short		wY;
	unsigned short		wWidth;
	unsigned short		wHeight;
}tmPostionResult_t;

typedef struct tagtmMotionRectList_t
{
	unsigned int		dwSize;			/*加上所有pPointList的长度，方便以后好兼容*/
	unsigned short		wImage_width;
	unsigned short		wImage_height;
	unsigned short		wImotion_num;
	unsigned short		wTemp;
	tmPostionResult_t 	pPointList[1]; /*有几个物体就有几个这种结构体,暂时只定义一个，这里的个数由 wImotion_num决定*/
}tmMotionRectList_t;

/*透雾参数配置  Add by TZH 2014-02-21*/
typedef struct tagDefogParams_t
{
	int			beRestoration;	 /*启用默认值；0-可配置状态，1-恢复默认值，后面的参数无效；*/
	int			iMRadius;		 /*最小值滤波半径*/
	int			iRadius;		 /*滤波半径；10-200；默认40、90；*/
	double		dEps;			 /*图像中轮廓边缘处理程度0.001-1；默认0.005*/
	int			iLevel;			 /*透雾处理程度1-100；默认82、90*/
	double		dThreshold;      /*主要用于远处或天空区域处理程度，值越大处理程度越小0.1-1.0；默认0.2*/
	double		dGama;           /*亮度调整，0.01-5.0，=1亮度不变，<1图像变暗，>1图像变亮，默认值1.3  */
	double		dSubSample;		 /*下采样率*/
}tmDefogParams_t;

typedef struct tagROI_t
{
	int x;                  
	int y;
	int width;
	int height;
}tmROI_t;

typedef struct tagDefogROIS_t
{
	int			iROICounts;     /*区域数量,0停止区域处理,整体透雾*/
	tmROI_t     stuROIS[8];     /*透雾的区域 暂定支持8个子区域*/
}tmDefogROI_t;

/*智能模块产生报警信息*/
typedef struct tmIntelligentAlarm_t
{
	unsigned int			dwSize;
	int						iAlarmType;			/*报警类型 1-跨线报警 2-区域闯入报警 3-遗留物报警*/
	int						iAlarmState;        /*报警状态*/
	int						iAlarmPostion;      /*报警发生的位置 */
}tmIntelligentAlarm_t;


/*TMCC_MINOR_CMD_STREAMSENDSTATUS*/
typedef struct tmCheckStreamSendStatusCfg_t
{
	DWORD		dwSize;
	BYTE		byEnable;					/*是否启用，当有视频传输时，立即上报正常，当出现没有发送流时，每2秒上报一次*/
	BYTE		byModuleId;					/*0:主程序 1:CGI 2:tmcc 3:RTSP STREAM_STAUTS_MODULE_SDK*/
	BYTE		byCheckTime;				/*单位秒最小为5秒 最大4分钟，应该是够了*/
	BYTE		byHandleWith;				/*0:不处理;1:重启;2: 存储*/
	BYTE		byTemp[4];					/*保留	*/
}tmCheckStreamSendStatusCfg_t;

/*枪球联动中球机的配置信息*/
typedef struct tmCameraItemInfo_t
{
	unsigned char		byEnable;//是否启用此球机条目
	unsigned char		byASsociateAlarm;//关联报警 1-跨线报警 2-区域闯入报警 3-遗留物报警
	unsigned char		byAlarmArea;//关联报警的具体区域 
	unsigned char		byTmp;
	int					iHorBase; //球机水平位置
	int					iVerBase;//球机垂直位置
	int					iZoomBase;//球机倍数
	char				szIP[32]; //球机ip地址
	int					iPort;//端口
	char				szUser[32];//用户
	char				szPass[32];//密码
}CameraItemInfo_t;

/*枪球联动配置信息 TMCC_MINOR_CMD_CAMTRACK*/
typedef struct tmCameraTrackCfg_t
{
	unsigned int		dwSize;
	int					HorViewAngle; //水平可视角
	int					VerViewAngle; //垂直可视角
	CameraItemInfo_t	pCamItemList[5]; //关联球机的信息
	unsigned char		byTmp[4];
}CameraTrackCfg_t;

/*调式3D功能 TMCC_MINOR_CMD_3D_ZOOMANGLE*/
typedef struct tag3DCtrlZoomAngle_t
{
	DWORD 				dwSize;
	BYTE				byEnable;
	BYTE				byTemp[3];
	DWORD				dwZoom;			/*倍数*1000,当为非0时,3D控制强制用该倍数*/
	DWORD				dwHorVal;		/*当前倍数水平可视频角*1000*/
	DWORD				dwVerVal;		/*当前倍数垂直可视频角*1000*/
}T3DCtrlZoomAngle_t;

/*3D功能修正 TMCC_MINOR_CMD_3D_AMENDMENT*/
typedef struct tag3DAmendment_t
{
	DWORD 				dwSize;
	BYTE				byEnable;
	BYTE				byTemp[3];
	int					iZoomOffsetX;		/*小倍数到大倍数中心点偏移x,*1000倍*/
	int					iZoomOffsetY;		/*小倍数到大倍数中心点偏移y,*1000倍*/
	int					iRotateAngle;		/*图像旋转角度,1000倍，如5.123度为5123*/
	int					iTemp;			
}T3DAmendment_t;


#define			THIRDANALYSE_BUF_SIZE     65536
//第三方智能参数
typedef struct tagThirdAnalyseCfg_t
{
	//本结构大小
	unsigned int			dwSize;
	unsigned char			AnalyseCfgbuf[THIRDANALYSE_BUF_SIZE];
}ThirdAnalyseCfg_t;


/*导入导出预置点位置 TMCC_MINOR_CMD_PTZPRESETINFO*/
typedef struct tagPtzPresetPosInfo_t
{
	//本结构大小
	unsigned int			dwSize;
	unsigned char			szPresetName[128];
	unsigned char			byEn;
	unsigned char			byType;		//0:3D方式预置点 其它为云台预置点，并指定tmPtzPreset->byValue的长度
	unsigned char			byNo;		//
	unsigned char			byTmp[1];

	
	struct
	{
		int				iZoom;						/*当前放大倍数*100*/
		int				iDigitalZoom;				/*当前数字放大倍数*100*/
		int				iFocus;						/*当前后焦*100*/
		int				iIrType;					/*新的对焦库,要求预置位同时保存IR状态*/
	}tmZoomPos;

	union{		
		struct
		{
			int				iPanPos;
			int				iTiltPos;
		}tm3DPreset;
		struct
		{	
			BYTE	byValue[8];
		}tmPtzPreset;
	}tmPtzPos;	
}PtzPresetPosInfo_t;




/*命令代码定义*/
/*用户操作*/
#define TMCC_MAJOR_CMD_USERCFG						0x101		/*用户操作相关命令信息*/
#define TMCC_MINOR_CMD_USER_MOTIFYDEFAULTUSER		0x00		/*修改系统默认用户信息*/
#define TMCC_MINOR_CMD_USER_INFO					0x01		/*所有用户信息*/
#define TMCC_MINOR_CMD_USER_SINGLEINFO				0x02		/*单个用户信息*/
#define TMCC_MINOR_CMD_USER_ADD						0x03		/*添加用户*/
#define TMCC_MINOR_CMD_USER_DELETE					0x04		/*删除用户*/
#define TMCC_MINOR_CMD_USER_MOTIFYPASSWORD			0x05		/*修改用户密码*/
#define TMCC_MINOR_CMD_USER_MOTIFYRIGHT				0x06		/*修改用户权限*/
#define TMCC_MINOR_CMD_USER_VERIFY					0x07		/*验证用户*/
#define TMCC_MINOR_CMD_USER_DATA					0x08		/*摄像机扩展数据，可以有用户保留，摄像机只保留数据*/
#define TMCC_MINOR_CMD_ENCRYPTKEY					0x09		/*设备加密密钥设置*/
#define TMCC_MINOR_CMD_GETENCRYPTDATA				0x0A		/*得到加密数据*/

/*服务器参数配置*/
#define TMCC_MAJOR_CMD_DEVICECFG					0x102		/*设备参数*/
#define TMCC_MINOR_CMD_DEVICE						0x00		/*设备参数*/
#define TMCC_MINOR_CMD_DEVICEEX						0x01		/*扩展设备参数*/

#define TMCC_MAJOR_CMD_NETCFG						0x103		/*网络参数*/
#define TMCC_MINOR_CMD_LANNETCFG					0x00		/*本地有线网络参数*/
#define TMCC_MINOR_CMD_WIFINETCFG					0x01		/*本地无线网络参数*/
#define TMCC_MINOR_CMD_RTSPMUTICASTCFG				0x02		/*RTSP组播发送配置参数*/
#define TMCC_MINOR_CMD_P2PCFG						0x03		/*p2p代理模块配置信息*/

#define TMCC_MAJOR_CMD_PICCFG						0x104		/*取图象参数*/
#define TMCC_MINOR_CMD_PIC							0x00		/*取图象参数(合成结构)*/
#define TMCC_MINOR_CMD_OSD							0x01		/*取图象OSD参数*/
#define TMCC_MINOR_CMD_MASK							0x02		/*取图象遮盖参数*/
#define TMCC_MINOR_CMD_LOST							0x03		/*取图象视频丢失参数*/
#define TMCC_MINOR_CMD_MOTION						0x04		/*取图象移动检测参数*/
#define TMCC_MINOR_CMD_HIDEALARM					0x05		/*取图象遮挡报警参数*/
#define TMCC_MINOR_CMD_ADDEXPANDOSD					0x06		/*添加特殊OSD*/
#define TMCC_MINOR_CMD_CLEAREXPANDOSD				0x07		/*清除特殊OSD*/
#define TMCC_MINOR_CMD_OSDCOLOR						0x08		/*OSD颜色方案配置*/
#define TMCC_MINOR_CMD_APTITUDESCOUT				0x09		/*设置智能分析方案*/
#define TMCC_MINOR_CMD_FACEDETECT					0x0A		/*设置人脸检测*/
#define TMCC_MINOR_CMD_LINEDETECT					0x0B		/*设置越界检测*/
#define TMCC_MINOR_CMD_POLYGONDETECT				0x0C		/*设置区域闯入检测*/
#define TMCC_MINOR_CMD_FLOWDETECT					0x0D		/*设置车流量检测*/
#define TMCC_MINOR_CMD_ABANDONDETECT				0x0E		/*设置遗留物体检测*/
#define TMCC_MINOR_CMD_MOTIONRECT					0x0F	    /*获取智能分析模块移动区域*/
#define	TMCC_MINOR_CMD_CAMTRACK						0x10		/*设置枪球联动信息*/
#define TMCC_MINOR_CMD_THIRDANALYSE					0x11		/*第三方智能参数*/
#define TMCC_MINOR_CMD_SAVEEXPANDOSD				0x12		/*保存当前的特殊OSD*/

#define TMCC_MAJOR_CMD_COMPRESSCFG					0x105		/*压缩参数*/
#define TMCC_MINOR_CMD_COMPRESSCFG					0x00		/*设置编码参数*/
#define TMCC_MINOR_CMD_QUERYCOMPRESSCAPABILITY		0x01		/*查询编码能力*/
#define TMCC_MINOR_CMD_QUERYCOMPRESSCAPABILITYEX	0x02		/*扩展查询编码能力*/
#define TMCC_MINOR_CMD_QPROICFG						0x03		/*设置区域编码质量参数*/

#define TMCC_MAJOR_CMD_RECORDCFG					0x106		/*录像时间参数*/
#define TMCC_MINOR_CMD_LOCALRECORDCFG				0x00		/*本地录像设置*/
#define TMCC_MINOR_CMD_FTPRECORDCFG 				0x01		/*FTP录像设置*/

/*云台解码器参数*/
#define TMCC_MAJOR_CMD_DECODERCFG					0x107		
#define TMCC_MINOR_CMD_485CFG 						0x00		/*485参数设置*/
#define TMCC_MINOR_CMD_CRUISECFG 					0x01		/*巡航参数设置*/
#define TMCC_MINOR_CMD_PTZCFG						0x02		/*云台参数配置*/
#define TMCC_MINOR_CMD_PRESETCFG					0x03		/*预置点参数配置*/
#define TMCC_MINOR_CMD_ZOOMCFG						0x04		/*一体机配置参数*/
#define TMCC_MINOR_CMD_TRACKCFG						0x05		/*轨迹参数配置*/
#define TMCC_MINOR_CMD_LINECFG						0x06		/*线扫参数配置*/
#define TMCC_MINOR_CMD_AUXCFG						0x07		/*辅助开关参数配置*/
#define TMCC_MINOR_CMD_APERTURECFG					0x08		/*光圈参数配置*/
#define TMCC_MINOR_CMD_PTZ_CFG_EX					0x09		/*PTZ模块扩展功能使能配置*/
#define TMCC_MINOR_CMD_3D_AMENDMENT					0x0A		/*3D修正配置*/
#define TMCC_MINOR_CMD_PTZ_INFO						0x0B		/*云台或球机信息配置*/

#define TMCC_MAJOR_CMD_RS232CFG 					0x108		/*232串口参数*/
#define TMCC_MAJOR_CMD_ALARMINCFG 					0x109		/*报警输入参数*/
#define TMCC_MINOR_CMD_ALARMINCFG 					0x00		/*报警输入参数*/
#define TMCC_MINOR_CMD_IRALARMINCFG 				0x01		/*IR报警输入参数*/
#define TMCC_MAJOR_CMD_ALARMOUTCFG 					0x10A		/*报警输出参数*/

#define TMCC_MAJOR_CMD_TIMECFG 						0x10B		/*DVR时间*/
#define TMCC_MINOR_CMD_TIMECFG 						0x00		/*时间配置*/
#define TMCC_MINOR_CMD_ZONECFG 						0x01		/*时区配置*/
#define TMCC_MINOR_CMD_DAYLIGHTCFG 					0x02		/*夏令时配置*/

#define TMCC_MAJOR_CMD_PREVIEWCFG 					0x10C		/*预览参数*/
#define TMCC_MINOR_CMD_PREVIEWCOLORCFG 				0x00		/*颜色设置*/
#define TMCC_MINOR_CMD_COMPRESSOFFSETCFG 			0x01		/*压缩偏移参数*/
#define TMCC_MINOR_CMD_PREVIEWOFFSETCFG 			0x02		/*预览偏移参数*/
#define TMCC_MINOR_CMD_PICMODE						0x03        /*设置图像模式(add by zzt 2009-09-17)*/
#define TMCC_MINOR_CMD_TEMPPREVIEWCOLORCFG 			0x04		/*临时预览色彩参数*/

/*解码器命令*/
#define TMCC_MAJOR_CMD_VIDEOOUTCFG 					0x10D		/*视频输出参数*/
#define TMCC_MINOR_CMD_VIDEOOUT						0x00		/*视频输出参数*/
#define TMCC_MINOR_CMD_CONNECTINFO					0x01		/*配置连接信息*/
#define TMCC_MINOR_CMD_ENUMCONNECTINFO				0x02		/*列举连接信息*/
#define TMCC_MINOR_CMD_WINDOWSINFO					0x03		/*窗口信息*/
#define TMCC_MINOR_CMD_DISPLAYINFO					0x04		/*解码器显示信息*/
#define TMCC_MINOR_CMD_LOCK							0x05		/*锁定当前连接，标示非循环连接*/
#define TMCC_MINOR_CMD_CLEAR						0x06		/*清除循环列表，保留当前连接*/
#define TMCC_MINOR_CMD_CONNECT						0x07		/*开始连接*/
#define TMCC_MINOR_CMD_DISCONNECT					0x08		/*断开连接*/
#define TMCC_MINOR_CMD_WINDOWCAPABILITY				0x09		/*解码窗口描述*/
#define TMCC_MINOR_CMD_VIDEOOUTOFFSET				0x0A		/*视频输出偏移*/
#define TMCC_MINOR_CMD_SCREENINFO					0x0A		/*解码器屏幕描述*/

#define TMCC_MAJOR_CMD_EXCEPTIONCFG 				0x10E		/*异常参数*/
/*服务器的消息*/
#define TMCC_MAJOR_CMD_SERVERMESSAGE				0x10F		/*服务器消息*/
#define TMCC_MINOR_CMD_DEBUGINFO					0x01		/*服务器调试信息，调试版本有效*/
#define TMCC_MINOR_CMD_SERVERSTART 					0x02		/*服务器启动*/
#define TMCC_MINOR_CMD_SERVERSTOP 					0x03		/*服务器退出*/
#define TMCC_MINOR_CMD_SERVERALARM 					0x04		/*报警上传管理中心具体信息看tmToManagerAlarmInfo_t*/
#define TMCC_MINOR_CMD_SERVERWANTSYNCTIME			0x05		/*服务器希望被同步时间*/
#define TMCC_MINOR_CMD_SERVERIMAGE					0x06		/*服务器报警图片上传,具体信息看tmToManagerImageInfo_t*/
#define TMCC_MINOR_CMD_PTZCLOSEBYOTHERUSER			0x07		/*云台控制被其它用户关闭*/
#define TMCC_MINOR_CMD_PTZCLOSEBYTIMEOUT			0x08		/*云台控制时间超时关闭*/
#define TMCC_MINOR_CMD_SERIALMESSAGE				0x09		/*服务器返回的串口数据*/
#define TMCC_MINOR_CMD_SERVERLIVEHEART				0x0A		/*设备的心跳包*/
#define TMCC_MINOR_CMD_APERTUREREPAIRCOMPLETE		0x0B		/*光圈校正完毕*/
#define TMCC_MINOR_CMD_BADPIXREPAIRCOMPLETE			0x0C		/*服务器坏点修复完毕*/
#define TMCC_MINOR_CMD_SAFEGUARDINFO				0x0D		/*安全卫士报警上传管理中心具体信息看tmToManagerSafeGuardInfo_t*/
#define TMCC_MINOR_CMD_ZOOMREPAIRCOMPLETE			0x0E		/*设备倍焦效验完毕*/
#define TMCC_MINOR_CMD_AWBREPAIRREQUEST				0x0F		/*设备白平衡效验需求操作*/
#define TMCC_MINOR_CMD_SERVERCALLPTZ				0x10		/*设备调用云台*/
#define TMCC_MINOR_CMD_LENSREPAIRREQUEST			0x11		/*设备镜头暗角修正需求操作*/
#define TMCC_MINOR_CMD_ARRIVEPTZPOINT				0x12		/*云台设置的位置到位了*/
#define TMCC_MINOR_CMD_ARRIVEZOOMPOINT				0x13		/*机芯设置的位置到位了*/
#define TMCC_MINOR_CMD_FPNREPAIRREQUEST				0x14		/*设备FPN修正需求操作*/

/*云台控制命令*/
#define TMCC_MAJOR_CMD_PTZCONTROL 					0x110		/*服务器云台控制与串口控制*/
#define TMCC_MINOR_CMD_PTZGETDECODERLIST			0x00		/*得到云台控制解码器协议*/
#define TMCC_MINOR_CMD_PTZOPEN 						0x01		/*打开云台控制*/
#define TMCC_MINOR_CMD_PTZOPENANDLOCK				0x02		/*打开云台控制和锁定云台*/
#define TMCC_MINOR_CMD_PTZCLOSE 					0x03		/*关闭云台控制*/
#define TMCC_MINOR_CMD_PTZSENDCMD					0x04		/*发送云台控制命令*/
#define TMCC_MINOR_CMD_PTZTRANS						0x05		/*发送透明传输数据*/
#define TMCC_MINOR_CMD_SERIALOPEN					0x06		/*打开串口通明通道*/
#define TMCC_MINOR_CMD_SERIALCLOSE					0x07		/*关闭通明通道*/
#define TMCC_MINOR_CMD_SERIALSEND					0x08		/*发送通明通道数据*/
#define TMCC_MINOR_CMD_GETPTZINFO					0x09		/*读取当前云台信息*/
#define TMCC_MINOR_CMD_SERIALRECV					0x0A		/*接收通明通道数据*/
#define TMCC_MINOR_CMD_UPGRADE_PTZ					0x0B		/*升级球机程序*/
#define TMCC_MINOR_CMD_GET_PTZVERSION				0x0C		/*获取云台版本信息*/
#define TMCC_MINOR_CMD_GETALLPTZINFO				0x0D		/*读取当前所有云台信息*/
#define TMCC_MINOR_CMD_GETALLVIEWSIZE				0x0E		/*获取zoom所有可视角*/
#define TMCC_MINOR_CMD_GOTOZOOMTOP					0x0F		/*调用直接到顶点*/
#define TMCC_MINOR_CMD_CFG_PTZPRSETPOSNO			0x10		/*设置导出预置点的启始预置点号*/
#define TMCC_MINOR_CMD_PTZPRESETINFO				0x11		/*导入导出云台预置点位置,当是GET时,预置点号自动增加*/

/*服务器的基本控制*/
#define TMCC_MAJOR_CMD_SERVERCONTROL				0x111		/*远程服务器控制*/
#define TMCC_MINOR_CMD_REMONTALARMIN				0x01		/*报警信号上传服务器*/
#define TMCC_MINOR_CMD_OPENLIGHT					0x02		/*服务器状态灯开启*/
#define TMCC_MINOR_CMD_CLOSELIGHT					0x03		/*服务器状态灯关闭*/
#define TMCC_MINOR_CMD_OPENBUZZER					0x04		/*服务器蜂鸣器开启*/
#define TMCC_MINOR_CMD_CLOSEBUZZER					0x05		/*服务器蜂鸣器关闭*/
#define TMCC_MINOR_CMD_GETWORKSTATE					0x06		/*得到服务器工作状态*/
#define TMCC_MINOR_CMD_REMONTCLOSEALARMOUT			0x07		/*手动关闭报警输出*/
#define TMCC_MINOR_CMD_REMONTOPENALARMOUT			0x08		/*主动打开报警输出*/
#define TMCC_MINOR_CMD_RESET						0x09		/*系统复位*/
#define TMCC_MINOR_CMD_REMONTVIDEOMOTION			0x0A		/*视频移动报警信号*/
#define TMCC_MINOR_CMD_REMONTVIDEOLOST				0x0B		/*视频丢失报警信号*/
#define TMCC_MINOR_CMD_REMONTVIDEOHIDE				0x0C		/*视频遮挡报警信号*/
#define TMCC_MINOR_CMD_REQUESTUPGRADE				0x0D		/*远请求升级*/
#define TMCC_MINOR_CMD_OPENIRCUT					0x0E		/*打开滤光片*/
#define TMCC_MINOR_CMD_CLOSEIRCUT					0x0F		/*关闭滤光片*/
#define TMCC_MINOR_CMD_MANUALCAPTURE				0x10		/*远程手动抓图传到本地*/
#define TMCC_MINOR_CMD_AUTOAPERTUREREPAIR			0x11		/*自动查找Focus的值*/
#define TMCC_MINOR_CMD_UPGRADEKEEPIP				0x12		/*升级后保留IP地址信息*/
#define TMCC_MINOR_CMD_SYNCNTPSERVER				0x13		/*系统立即同步NTP服务器*/
#define TMCC_MINOR_CMD_STARTMANUALRECORD			0x14		/*打开手动录像*/
#define TMCC_MINOR_CMD_STOPMANUALRECORD				0x15		/*关闭手动录像*/
#define TMCC_MINOR_CMD_HANDLE						0x16		/*命令*/
#define TMCC_MINOR_CMD_SAVECONFIGINFO				0x17		/*保存配置信息*/
#define TMCC_MINOR_CMD_CONTROLSAFEDOOR				0x18		/*控制安全卫士的状态灯*/
#define TMCC_MINOR_CMD_SAVEIRCUTFOCUS				0x19		/*保存当前zoom位置的Focus值以备切换IRCUT使用*/
#define TMCC_MINOR_CMD_TESTCAMEATINGLE				0x1A		/*效验防抖传感器*/
#define TMCC_MINOR_CMD_CLOSEOSDVIEW					0x1B		/*强制临时关闭OSD*/
#define TMCC_MINOR_CMD_OPENOSDVIEW					0x1C		/*强制临时打开OSD(是否显示看OSD的设置)*/
#define TMCC_MINOR_CMD_PAUSEMANUALRECORD			0x1D		/*暂停手动录像wangjun add*/
#define TMCC_MINOR_CMD_INTELLIGENT					0x1E		/*智能模块报警*/
#define TMCC_MINOR_CMD_MANUALCAPTUREEX				0x20		/*远程扩展手动抓图传到本地*/
#define TMCC_MINOR_CMD_STARTFLIRTRANS				0x21		/*开始FLIR透传*/
#define TMCC_MINOR_CMD_STOPFLIRTRANS				0x22		/*关闭FLIR透传*/
#define TMCC_MINOR_CMD_FLIRTRANS					0x23		/*FLIR透传数据*/
#define TMCC_MINOR_CMD_REMONTVIDEOFLIR				0x24		/*热源报警信号*/

#define TMCC_MAJOR_CMD_ALARMCFG 					0x112		/*报警处理参数*/

#define TMCC_MAJOR_CMD_DISKCONTROL					0x113		/*磁盘处理命令*/
#define TMCC_MINOR_CMD_DRIVEINFO					0x01		/*得到物理硬盘信息*/
#define TMCC_MINOR_CMD_DRIVEINIT					0x02		/*初始化物理硬盘*/
#define TMCC_MINOR_CMD_DRIVEALARMCFG				0x03		/*磁盘报警配置*/
#define TMCC_MINOR_CMD_DRIVEREMOVE					0x04		/*磁盘卸载*/
#define TMCC_MINOR_CMD_DRIVELOAD					0x05		/*磁盘加载*/

/*网络控制扩展命令*/
#define TMCC_MAJOR_CMD_NETCFGEX						0x114		/*net1=SNTP+..参数*/
#define TMCC_MINOR_CMD_NTPCFG						0x00
#define TMCC_MINOR_CMD_FTPCFG						0x01
#define TMCC_MINOR_CMD_SMTPCFG						0x02
#define TMCC_MINOR_CMD_LIVEHEARTCFG					0x03		/*心跳包*/
#define TMCC_MINOR_CMD_DDNSCFG						0x04		/*DDNS*/
#define TMCC_MINOR_CMD_UPCFG						0x05		/*设备主动上传配置*/
#define TMCC_MINOR_CMD_STREAMSENDSTATUS				0x06		/*检测视频流发送状态*/

/*压缩参数扩展命令*/
#define TMCC_MAJOR_CMD_COMPRESSCFGA					0x115		/*扩展压缩参数*/
#define TMCC_MINOR_CMD_COMPRESSCFGA					0x00		/*图像压缩参数*/

#define TMCC_MAJOR_CMD_VIDEOINCFG					0x116		/*视频输入配置*/
#define TMCC_MINOR_CMD_VIDEOIN						0x00		/*输入配置*/
#define TMCC_MINOR_CMD_IRCUTVIDEOIN					0x01		/*IRCUT切换对应输入配置*/
#define TMCC_MINOR_CMD_SCHEDVIDEOIN					0x02		/*按时间布防的输入配置*/
#define TMCC_MINOR_CMD_VIDEOINPREVIEW				0x03		/*临时预览VideoIn参数*/
#define TMCC_MINOR_CMD_AWBCFG						0x04		/*白平衡参数设置*/
#define TMCC_MINOR_CMD_LIGHTINHIBITION				0x05		/*强光抑制*/
#define TMCC_MINOR_CMD_IRCUTVIDEOINPREVIEW			0x06		/*临时预览IRCutVin参数*/
#define TMCC_MINOR_CMD_SCHEDVIDEOINPREVIEW			0x07		/*临时预览SchedVideoIn参数*/
#define TMCC_MINOR_CMD_LENSDEWARP					0x08		/*镜头畸变校正参数参数*/
#define TMCC_MINOR_CMD_VIDEOFLIR					0x09		/*镜头热像布防参数*/
#define TMCC_MINOR_CMD_VIDEOFLIRAREA				0x0A		/*镜头热像区域测温参数(配置是iStream=0为默认配置，1-MAX_PRESET为对应预置点配置)*/
#define TMCC_MINOR_CMD_VIDEOFLIRSPOLT				0x0B		/*镜头热像点测温参数*/

#define TMCC_MAJOR_CMD_SHUTTERCFG					0x117

/*抓图的命令*/
#define TMCC_MAJOR_CMD_CAPTUREIMAGECFG				0x118
#define TMCC_MINOR_CMD_CAPTUREIMAGECFG				0x00		/*抓图的配置*/
#define TMCC_MINOR_CMD_CAPTURESCHEDCFG				0x01		/*时间布防的配置*/

/*音频参数设置命令*/
#define TMCC_MAJOR_CMD_AUDIOCFG                     0x119

/*NVR通道信息信息设置相关命令*/
#define TMCC_MAJOR_CMD_CHANNELCFG                   0x11A       /*通道配置主命令*/
#define TMCC_MINOR_CMD_SINGLECHANNEL                0x00        /*配置单个通道信息(设置/获取)*/
#define TMCC_MINOR_CMD_ALLCHANNEL                   0x01        /*配置所有通道信息(设置/获取)*/
#define TMCC_MINOR_CMD_SINGLERTSPNAME               0x02        /*配置单个通道RTSP名称(设置/获取)*/
#define TMCC_MINOR_CMD_ALLRTSPNAME                  0x03        /*配置所有通道RTSP名称(设置/获取)*/

/*NVR的虚拟报警设备*/
#define TMCC_MAJOR_CMD_ALARMDEVICECFG               0x11B       /*报警设备配置主命令*/
#define TMCC_MINOR_CMD_SINGLEALARMDEVICE            0x00        /*配置单个报警设备信息(设置/获取)*/
#define TMCC_MINOR_CMD_ALLALARMDEVICE               0x01        /*配置所有报警设备信息(设置/获取)*/

/*设备日志命令*/
#define TMCC_MAJOR_CMD_LOGCFG						0x11C
#define TMCC_MINOR_CMD_ENUMLOG						0x00		/*枚举所有日志*/
#define TMCC_MINOR_CMD_CLEARLOG						0x01		/*清除日志*/

/*解码器配置命令*/
#define TMCC_MAJOR_CMD_CONNECTCFG					0x11D
#define TMCC_MINOR_CMD_CONNECTLISTCFG				0x00		/*所有连接*/
#define TMCC_MINOR_CMD_CLEARCONNECT					0x01		/*清除解码连接*/

/*摄像机经纬度配置命令对应tmTheodoliteCfg_t结构*/
#define TMCC_MAJOR_CMD_THEODOLITECFG				0x11E


/*IRCUT的配置命令*/
#define TMCC_MAJOR_CMD_IRCUTCFG						0x11F
#define TMCC_MINOR_CMD_IRCUTCFG						0x00		/*配置IRCUT*/

/*摄像机通过串口上报状态信息*/
#define TMCC_MAJOR_CMD_UART_REPORT					0x120
#define TMCC_MINOR_CMD_STORAGESTATUS				0x00		/*存储状态上报*/
#define TMCC_MINOR_CMD_FACE_CEHCK					0x01		/*人脸检测上报*/

/*CIG消息*/
#define TMCC_MAJOR_CMD_CGIMSG						0x123		/*CIG消息*/
#define TMCC_MINOR_CMD_CGIMSG						0x00	

#define TMCC_MAJOR_CMD_LOCALSPECIALCFG				0x124	/*设置调式或配置命令*/
#define TMCC_MINOR_CMD_PTZHONGWAILIANGDU			0x00	/*设置不同位数下红外灯的亮度*/
#define TMCC_MINOR_CMD_PTZGUANGMINFAZHI				0x01	/*设置球机光敏阀值*/
#define TMCC_MINOR_CMD_3D_ZOOMANGLE					0x02	/*3D协议可以解决调式命令*/
#define TMCC_MINOR_CMD_GET_PTZGUANGMINZHI			0x03	/*获取球当前光敏值*/

/* 视频显示参数配置 add by tzh*/ 
#define TMCC_MAJOR_CMD_VIDEOPARAMCFG				0x125		/*显示亮度、对比度、伽马、饱和度、色度等*/
#define TMCC_MINOR_CMD_VIDEOPARAMCFG				0x00

/* 用户权限定义 */
#define	TMCC_USERRIGHT_CONTROLPTZ					0x00000001	/*位0: 远程控制云台*/
#define	TMCC_USERRIGHT_MANUALREC					0x00000002	/*位1: 远程手动录象*/
#define	TMCC_USERRIGHT_PLAYBACK						0x00000004	/*位2: 远程回放*/
#define	TMCC_USERRIGHT_SETUP						0x00000008	/*位3: 远程设置参数，参数保存*/
#define	TMCC_USERRIGHT_LOOKSTAUS					0x00000010	/*位4: 远程查看状态、日志*/
#define	TMCC_USERRIGHT_ADVANCE						0x00000020	/*位5: 远程高级操作(升级，格式化，重启，关机)*/
#define	TMCC_USERRIGHT_TALK							0x00000040	/*位6: 远程发起语音对讲*/
#define	TMCC_USERRIGHT_PREVIEW						0x00000080	/*位7: 远程预览*/
#define	TMCC_USERRIGHT_ALARM						0x00000100	/*位8: 远程请求报警上传、报警输出*/
#define	TMCC_USERRIGHT_CONTROLLOCAL					0x00000200	/*位9: 远程控制，本地输出*/
#define	TMCC_USERRIGHT_SERIALPORT					0x00000400	/*位10: 远程控制串口*/
#define	TMCC_USERRIGHT_MOTIFYUSER					0x00000800	/*位11: 远程修改用户*/
#define	TMCC_USERRIGHT_MOTIFYSELFPASSWORD			0x00001000	/*位12: 远程修改用户自己的密码*/
#define	TMCC_USERRIGHT_RTSPCONNECT					0x00002000	/*位13: 远程RTSP链接*/

/*播放文件的状态*/
#define	TMCC_PLAY_STATE_STOP						0			/*停止播放*/
#define	TMCC_PLAY_STATE_PAUSE						1			/*暂停播放*/
#define	TMCC_PLAY_STATE_PLAY						2			/*播放*/
#define	TMCC_PLAY_STATE_FAST						3			/*快放*/
#define	TMCC_PLAY_STATE_SLOW						4			/*慢放*/
#define	TMCC_PLAY_STATE_OPEN						5			/*打开文件成功*/
#define	TMCC_PLAY_STATE_SWITCH						6			/*已经切换文件*/
#define	TMCC_PLAY_STATE_FILEEND						7			/*文件全部播放完毕*/
#define TMCC_PLAY_STATE_STREAMBUFFERRING			8			/*正在缓冲数据*/
#define TMCC_PLAY_STATE_ENCFMTCHANGE				9			/*编码格式改变*/

/*解码视频输出格式*/
#define TMCC_IMAGEOUT_FMT_420P						0
#define TMCC_IMAGEOUT_FMT_RGB15						1
#define TMCC_IMAGEOUT_FMT_RGB16						2
#define TMCC_IMAGEOUT_FMT_RGB24						3
#define TMCC_IMAGEOUT_FMT_RGB32						4
#define TMCC_IMAGEOUT_FMT_YUY2						5
#define TMCC_IMAGEOUT_FMT_YVYU						6
#define TMCC_IMAGEOUT_FMT_UYVY						7
#define TMCC_IMAGEOUT_FMT_420P2						8
#define TMCC_IMAGEOUT_FMT_422P						9
#define TMCC_IMAGEOUT_FMT_422P2						10
#define TMCC_IMAGEOUT_FMT_H264						11
#define TMCC_IMAGEOUT_FMT_MJPEG						12
#define TMCC_IMAGEOUT_FMT_H265						13

#define TMCC_CAPTURE_IMAGETYPE_BMP					0x00
#define TMCC_CAPTURE_IMAGETYPE_JPEG					0x01
#define TMCC_CAPTURE_IMAGETYPE_H264					0x02
#define TMCC_CAPTURE_IMAGETYPE_YUV					0x03
#define TMCC_CAPTURE_IMAGETYPE_H265					0x04
#define TMCC_CAPTURE_IMAGETYPE_RAW					0x05
#define TMCC_CAPTURE_IMAGETYPE_DEF					0xFF

#define TMCC_CAPTURE_IMAGEFMT_JPEG					0x00
#define TMCC_CAPTURE_IMAGEFMT_BMP					0x01
#define TMCC_CAPTURE_IMAGEFMT_RGB555				0x02
#define TMCC_CAPTURE_IMAGEFMT_RGB565				0x03
#define TMCC_CAPTURE_IMAGEFMT_RGB24					0x04
#define TMCC_CAPTURE_IMAGEFMT_RGB32					0x05
#define TMCC_CAPTURE_IMAGEFMT_YUV444				0x06
#define TMCC_CAPTURE_IMAGEFMT_YUV422				0x07
#define TMCC_CAPTURE_IMAGEFMT_YUV420				0x08
#define TMCC_CAPTURE_IMAGEFMT_BKMPEG4				0x09
#define TMCC_CAPTURE_IMAGEFMT_H264					0x0A
#define TMCC_CAPTURE_IMAGEFMT_H265					0x0B
#define TMCC_CAPTURE_IMAGEFMT_Y_UV420				0x0C
#define TMCC_CAPTURE_IMAGEFMT_Y_VU420				0x0D
#define TMCC_CAPTURE_IMAGEFMT_RAW					0x0E

/*操作错误代码*/
#define TMCC_ERR_SUCCESS						    0x00000000	/*没有错误发生*/
#define TMCC_ERR_HANDLE_INVALID						0xC0000001	/*非法句柄*/
#define TMCC_ERR_PARAMETER_INVALID					0xC0000002	/*参数错误*/
#define TMCC_ERR_MEMORY_OUT							0xC0000003	/*内存益出错误*/
#define TMCC_ERR_THREAD_CREATE						0xC0000004	/*线程生成错误*/
#define TMCC_ERR_THREAD_START						0xC0000005	/*启动线程错误*/
#define TMCC_ERR_THREAD_STOP						0xC0000006	/*停止线程错误*/
#define TMCC_ERR_SOCKET_CREATE						0xC0000007	/*套接字生成错误*/
#define TMCC_ERR_SERVERNOCONFIG 					0xC0000008  /*服务器没有初始化配置接口*/
#define TMCC_ERR_SERVEREXCEPTION 					0xC0000009  /*服务器函数调用发生异常*/
#define TMCC_ERR_USERNOTLOGIN 						0xC000000A  /*该用户没有登录*/
#define TMCC_ERR_NOTSETUP 						    0xC000000B  /*不能设置*/
#define TMCC_ERR_NOTDISCONNECT					    0xC000000C  /*没有断开连接*/
#define TMCC_ERR_NETWORK_FAIL_CONNECT			    0xC000000D	/*连接服务器失败*/
#define TMCC_ERR_NETWORK_SEND_ERROR				    0xC000000E	/*向服务器发送失败*/
#define TMCC_ERR_NETWORK_RECV_ERROR				    0xC000000F	/*从服务器接收数据失败*/
#define TMCC_ERR_NETWORK_RECV_TIMEOUT			    0xC0000010	/*从服务器接收数据超时*/
#define TMCC_ERR_NETWORK_ERRORDATA				    0xC0000011	/*传送的数据有误*/
#define TMCC_ERR_NETWORK_SERVERNOSTART			    0xC0000012	/*服务器没有启动*/
#define	TMCC_ERR_OPERNOTFINISH					    0xC0000013  /*上次的操作还没有完成*/
#define TMCC_ERR_NOENOUGH_BUF					    0xC0000014	/*缓冲区太小*/
#define TMCC_ERR_COMMAND_INVALID				    0xC0000015	/*非法命令*/
#define TMCC_ERR_UPGRADEFILENOTOPEN				    0xC0000016	/*升级文件不能打开*/
#define TMCC_ERR_UPGRADESIZELARG				    0xC0000017	/*升级文件大小错误不能升级*/
#define TMCC_ERR_UPGRADEPARITY					    0xC0000018	/*升级文件效验错误不能升级*/
#define TMCC_ERR_UPGRADEFILENOTREAD				    0xC0000019	/*升级文件不能读取*/
#define TMCC_ERR_STRUCTSIZE						    0xC000001A	/*结构中的大小错误*/
#define TMCC_ERR_DATACRC						    0xC000001B	/*数据CRC效验错误*/
#define	TMCC_ERR_USEREXIST						    0xC000001D  /*用户已经存在*/
#define	TMCC_ERR_USERMAXNUM						    0xC000001E  /*用户达到最大在*/
#define TMCC_ERR_NOINIT 						    0xC000001F /*没有初始化*/
#define TMCC_ERR_CHANNEL_ERROR 					    0xC0000020 /*通道号错误*/
#define TMCC_ERR_OVER_MAXLINK 					    0xC0000021 /*连接到DVR的客户端个数超过最大*/
#define TMCC_ERR_VERSIONNOMATCH					    0xC0000022 /*版本不匹配*/
#define TMCC_ERR_ORDER_ERROR					    0xC0000023 /*调用次序错误*/
#define TMCC_ERR_OPERNOPERMIT					    0xC0000024 /*无此权限*/
#define TMCC_ERR_COMMANDTIMEOUT					    0xC0000025 /*DVR命令执行超时*/
#define TMCC_ERR_ERRORSERIALPORT				    0xC0000026 /*串口号错误*/
#define TMCC_ERR_ERRORALARMPORT					    0xC0000027 /*报警端口错误*/
#define TMCC_ERR_PARAMETER_ERROR 				    0xC0000028  /*参数错误*/
#define TMCC_ERR_CHAN_EXCEPTION					    0xC0000029	/*服务器通道处于错误状态*/
#define TMCC_ERR_NODISK							    0xC000002A	/*没有硬盘*/
#define TMCC_ERR_ERRORDISKNUM					    0xC000002B	/*硬盘号错误*/
#define TMCC_ERR_DISK_FULL						    0xC000002C	/*服务器硬盘满*/
#define TMCC_ERR_DISK_ERROR						    0xC000002D	/*服务器硬盘出错*/
#define TMCC_ERR_NOSUPPORT						    0xC000002E	/*服务器不支持*/
#define TMCC_ERR_BUSY							    0xC000002F	/*服务器忙*/
#define TMCC_ERR_MODIFY_FAIL					    0xC0000030	/*服务器修改不成功*/
#define TMCC_ERR_PASSWORD_FORMAT_ERROR			    0xC0000031	/*密码输入格式不正确*/
#define TMCC_ERR_DISK_FORMATING					    0xC0000032	/*硬盘正在格式化，不能启动操作*/
#define TMCC_ERR_DVRNORESOURCE					    0xC0000033	/*DVR资源不足*/
#define	TMCC_ERR_DVROPRATEFAILED				    0xC0000034  /*DVR操作失败*/
#define TMCC_ERR_OPENHOSTSOUND_FAIL 			    0xC0000035  /*打开PC声音失败*/
#define TMCC_ERR_DVRVOICEOPENED 				    0xC0000036  /*服务器语音对讲被占用*/
#define	TMCC_ERR_TIMEINPUTERROR					    0xC0000037  /*时间输入不正确*/
#define	TMCC_ERR_NOSPECFILE						    0xC0000038  /*回放时服务器没有指定的文件*/
#define TMCC_ERR_CREATEFILE_ERROR				    0xC0000039	/*创建文件出错*/
#define	TMCC_ERR_FILEOPENFAIL					    0xC000003A  /*打开文件出错*/
#define	TMCC_ERR_GETPLAYTIMEFAIL				    0xC000003B  /*获取当前播放的时间出错*/
#define	TMCC_ERR_PLAYFAIL						    0xC000003C  /*播放出错*/
#define TMCC_ERR_FILEFORMAT_ERROR				    0xC000003D  /*文件格式不正确*/
#define TMCC_ERR_DIR_ERROR						    0xC000003E	/*路径错误*/
#define TMCC_ERR_ALLOC_RESOUCE_ERROR			    0xC000003F  /*资源分配错误*/
#define TMCC_ERR_AUDIO_MODE_ERROR				    0xC0000040	/*声卡模式错误*/
#define TMCC_ERR_CREATESOCKET_ERROR				    0xC0000042	/*创建SOCKET出错*/
#define TMCC_ERR_SETSOCKET_ERROR				    0xC0000043	/*设置SOCKET出错*/
#define TMCC_ERR_MAX_NUM						    0xC0000044	/*个数达到最大*/
#define TMCC_ERR_USERNOTEXIST					    0xC0000045	/*用户不存在*/
#define TMCC_ERR_WRITEFLASHERROR				    0xC0000046  /*写FLASH出错*/
#define TMCC_ERR_UPGRADEFAIL					    0xC0000047  /*DVR升级失败*/
#define TMCC_ERR_CARDHAVEINIT					    0xC0000048  /*解码卡已经初始化过*/
#define TMCC_ERR_PLAYERFAILED					    0xC0000049	/*播放器中错误*/
#define TMCC_ERR_MAX_USERNUM					    0xC000004A  /*用户数达到最大*/
#define TMCC_ERR_GETLOCALIPANDMACFAIL			    0xC000004B  /*获得客户端的IP地址或物理地址失败*/
#define TMCC_ERR_NOENCODEING					    0xC000004C	/*该通道没有编码*/
#define TMCC_ERR_IPMISMATCH						    0xC000004D	/*IP地址不匹配*/
#define TMCC_ERR_MACMISMATCH					    0xC000004E	/*MAC地址不匹配*/
#define TMCC_ERR_UPGRADELANGMISMATCH			    0xC000004F	/*升级文件语言不匹配*/
#define TMCC_ERR_PASSWORDVERIFY					    0xC0000050	/*用户密码错误*/
#define TMCC_ERR_USERLOGIN						    0xC0000051	/*用户已经登录*/
#define TMCC_ERR_CANNOTDELETEUSER				    0xC0000052	/*用户不能删除*/
#define TMCC_ERR_MODALNOTEXIST					    0xC0000053	/*该版本的此模块不存在*/
#define TMCC_ERR_SERVERSTARTTING				    0xC0000054	/*服务器正在启动中*/
#define TMCC_ERR_CHANNELPTZOPEN					    0xC0000055	/*打开控制云台的通道错误*/
#define TMCC_ERR_PTZCONTROLNOTOPEN				    0xC0000056	/*云台控制没有打开*/
#define TMCC_ERR_GETPTZCONTROL					    0xC0000057	/*不能得到云台控制信息*/
#define TMCC_ERR_SERIALDATASIZE						0xC0000058	/*透明传输数据大小错误*/
#define TMCC_ERR_PTZOPENED						    0xC0000059	/*云台已经被其它用户打开*/
#define TMCC_ERR_PTZLOCKED						    0xC000005A	/*云台已经被其它用户锁定*/
#define TMCC_ERR_NOVOICEFUNCTION				    0xC000005B	/*无语音对讲功能*/
#define TMCC_ERR_VOICEHAVECONNECT				    0xC000005C	/*语音对讲已经被占用*/
#define TMCC_ERR_VOICENOTOPEN					    0xC000005D	/*语音对讲打开失败*/
#define TMCC_ERR_INUPGRADE						    0xC000005E	/*处于升级模式不能打开*/
#define TMCC_ERR_ALARMINCHANNEL					    0xC000005F	/*网络报警通道错误*/
#define TMCC_ERR_SERIALHAVEOPEN					    0xC0000060	/*通明通道已经打开*/
#define TMCC_ERR_SERIALNOTOPEN					    0xC0000061	/*通明通道没有打开*/
#define TMCC_ERR_NOTOPENUPGRADEMODAL				0xC0000062	/*没有打开升级模式*/
#define TMCC_ERR_UPGRADEMODALNOSUPPORR				0xC0000063	/*系统不支持的升级模块*/
#define TMCC_ERR_OPENUPGRADEMODALWRITE				0xC0000064	/*打开写模块错误*/
#define TMCC_ERR_UPGRADEMODALNOTREAD				0xC0000065	/*模块不能读错误*/
#define TMCC_ERR_HTTPPORTIS6000						0xC0000066	/*HTTP监听端口不能为6000*/
#define TMCC_ERR_VIDEOSTANDARD						0xC0000067	/*设置的视频制式不支持*/
#define TMCC_ERR_DELETETODAYLOG						0xC0000068	/*当天日志不能删除*/
#define TMCC_ERR_NOENOUGH_DATA						0xC0000069	/*服务器中没有搜索的数据了*/
#define TMCC_ERR_WRITEFILE							0xC000006A	/*写文件错误*/
#define TMCC_ERR_READFILE							0xC000006B	/*读文件错误*/
#define TMCC_ERR_FILEEND							0xC000006C	/*读文件完毕*/
#define TMCC_ERR_FILEINDEX							0xC000006D	/*读文件索引错误*/
#define TMCC_ERR_CAPTUREIMAGE						0xC000006E	/*手动抓图失败*/
#define TMCC_ERR_BUFFERFULL							0xC0000070	/*内部缓冲满 请再次送入*/

/*错误代码*/
#define ERROR_CODE_BEGINCONNECT						0xC0001000
#define ERROR_CODE_CONNECTSUCCESS					0xC0001001
#define ERROR_CODE_NETWORK							0xC0001002
#define ERROR_CODE_CONNECTERROR						0xC0001003
#define ERROR_CODE_CONNECTERROR_1000				0xC0001004
#define ERROR_CODE_SERVERSTOP						0xC0001005
#define ERROR_CODE_SERVERSTOP_1000					0xC0001006
#define ERROR_CODE_TIMEOUT							0xC0001007
#define ERROR_CODE_TIMEOUT_1000						0xC0001008
#define ERROR_CODE_SENDDATA							0xC0001009
#define ERROR_CODE_SENDDATA_1000					0xC000100A
#define ERROR_CODE_RECVDATA							0xC000100B
#define ERROR_CODE_RECVDATA_1000					0xC000100C

#define ERROR_CODE_CLOSECONNECT						0xC0010000
#define ERROR_CODE_SERVERNOSTART					0xC0010001
#define ERROR_CODE_SERVERERROR						0xC0010002
#define ERROR_CODE_CHANNELLIMIT 					0xC0010003
#define ERROR_CODE_SERVERLIMIT						0xC0010004
#define ERROR_CODE_SERVERREFUSE						0xC0010005
#define ERROR_CODE_IPLIMIT							0xC0010006
#define ERROR_CODE_PORTLIMIT						0xC0010007
#define ERROR_CODE_TYPEERROR						0xC0010008
#define ERROR_CODE_USERERROR						0xC0010009
#define ERROR_CODE_PASSWORDERROR					0xC001000A
#define ERROR_CODE_DONTTURN							0xC001000B
#define ERROR_CODE_VERSION							0xC0100000
#define ERROR_CODE_FACTORY							0xC0100001
#define ERROR_CODE_TRANSPACKETSIZE					0xC0100002
#define ERROR_CODE_DECODEVIDEOERROR					0xC0100003

#endif	/*__TMTRANSEDEFINE_H__*/
