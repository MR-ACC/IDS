// PlayCom.cpp: implementation of the CPlayCom class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RelayRTSP.h"
#include "RemotePlayerCom.h"

#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
                ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))


#define INDEX_BUF_MAXSIZE	(1024*1024)

typedef struct tagFileInfo_t
{
	BOOL				bLocal;
	FILE*				pf;
	HANDLE				hPlay;
	tmAvIndexEntry_t*	pIndex;
	int					iIndexCount;
}FileInfo_t;

static HANDLE fnOpen( const char* lpFileName, const char* lpMode, void* context )
{
	FileInfo_t* pFile = new FileInfo_t;
	
	memset(pFile, 0, sizeof(FileInfo_t));
	pFile->bLocal = TRUE;
	pFile->pf = fopen(lpFileName, lpMode);
	if( pFile->pf == NULL )
	{
		delete pFile;
		pFile = NULL;
	}

_exit:
	return (HANDLE)pFile;
}

static int fnClose(HANDLE hFile)
{
	FileInfo_t* pFile = (FileInfo_t*)hFile;
	if( pFile == NULL )
	{
		return -1;
	}
	if( pFile->pf != NULL )
	{
		fclose(pFile->pf);
		pFile->pf = NULL;
	}

	delete pFile;
	pFile = NULL;

	return 0;
}

static unsigned int fnSeek( HANDLE hFile, int offset, int origin )
{
	FileInfo_t* pFile = (FileInfo_t*)hFile;
	if( pFile == NULL )
	{
		return -1;
	}
	if( pFile->pf == NULL )
	{
		return -1;
	}
	fseek(pFile->pf, offset, origin);
	return (unsigned int)ftell(pFile->pf);
}

static int fnRead( HANDLE hFile, void* lpBuffer, int nRead )
{
	FileInfo_t* pFile = (FileInfo_t*)hFile;
	if( pFile == NULL )
	{
		return -1;
	}
	if( pFile->pf == NULL )
	{
		return -1;
	}
	return fread(lpBuffer, 1, nRead, pFile->pf);
}

static int fnWrite( HANDLE hFile, void* lpBuffer, int nWrite )
{
	FileInfo_t* pFile = (FileInfo_t*)hFile;
	if( pFile == NULL )
	{
		return -1;
	}
	if( pFile->pf == NULL )
	{
		return -1;
	}
	return fwrite(lpBuffer, 1, nWrite, pFile->pf);
}

static unsigned int fnSize( HANDLE hFile )
{
	struct stat buf;
	FileInfo_t* pFile = (FileInfo_t*)hFile;
	if( pFile == NULL )
	{
		return -1;
	}
	if( pFile->pf == NULL )
	{
		return -1;
	}

	if( fstat(_fileno(pFile->pf), &buf) == 0 )
	{
		return buf.st_size;
	}

	return 0;
}


static tmFileAccessInterface_t g_FileInterface = 
{
	fnOpen,
	fnClose,
	fnSeek,
	fnRead,
	fnWrite,
	fnSize
};

static FileInfo_t gOpenFileInfo;

//读取文件帧回调
static int OnReadCallBack( HANDLE hObject, void* lpBuffer, int nRead, unsigned int* dwCodeTag, int* nNeedBufSize, void* context )
{
	FileInfo_t*		pFileInfo = &gOpenFileInfo;
	BYTE			head[8];
	FILE*			pf = pFileInfo->pf;
	int				iRet, iLen;
	unsigned int	dwCodeID;

	iRet = fread(head, 1, 8, pf);
	if( iRet != 8 )
	{
		return -1;
	}
	
	memcpy(&dwCodeID, head, 4);
	memcpy(&iLen, head+4, 4);
	
	if( nRead < iLen )
	{
		if( nNeedBufSize != NULL )
		{
			*nNeedBufSize = iLen;
		}
		return -2;
	}
	
	iRet = fread(lpBuffer, 1, iLen, pf);
	if( iRet != iLen )
	{
		return -3;
	}
	
	if( dwCodeTag != NULL )
	{
		*dwCodeTag = dwCodeID;
	}

	return iLen;
}

//设置文件位置
static int OnSeekCallBack( HANDLE hObject, int offset, int origin, void* context )
{
	FILE* pf = gOpenFileInfo.pf;
	
	if( origin == SEEK_CUR && offset == 0 )
	{
		return ftell(pf);
	}

	return fseek(pf, offset, origin);
}

//打开播放的文件
HANDLE Avdec_OpenFile( const char* lpFileName, HWND hWnd, BOOL bAutoCreateIndex, BOOL bAutoPlay )
{
	tmPlayConditionCfg_t	struCond;

	memset(&struCond, 0, sizeof(tmPlayConditionCfg_t));
	struCond.dwSize = sizeof(tmPlayConditionCfg_t);
	struCond.info.file.byAutoCreateIndex = bAutoCreateIndex;
	struCond.info.file.byAutoPlay = bAutoPlay;
	sprintf(struCond.info.file.sFileName, "%s", lpFileName);
	
//	struCond.info.file.pFileCallBack = &g_FileInterface;
//	struCond.info.file.pFileContext = this;
//	struCond.info.file.pAvIndex = (tmAvIndexEntry_t*)pIndexBuf;
//	struCond.info.file.iAvIndexCount = iIndexNum;
	

	return Avdec_OpenFileA(NULL, &struCond, hWnd);
}

HANDLE Avdec_OpenFileA( HANDLE hLogin, tmPlayConditionCfg_t* pStruCond, HWND hWnd )
{
	return ::TMCC_OpenFile(hLogin, pStruCond, hWnd);
}

int	Avdec_CloseFile( HANDLE p )
{
	FileInfo_t*	pFileInfo = &gOpenFileInfo;
	
	if( pFileInfo->pIndex != NULL )
	{
		free(pFileInfo->pIndex);
	}

	if( pFileInfo->pf != NULL )
	{
		fclose(pFileInfo->pf);
	}

	memset(pFileInfo, 0, sizeof(FileInfo_t));

	return ::TMCC_CloseFile(p);
}

//注册状态改变回调
void Avdec_RegisterStateChangeCallBack( HANDLE p, TMCC_CONNECT_CALLBACK pCallBack, void* context )
{
	::TMCC_RegisterConnectCallBack(p, pCallBack, context);
}

//注册状态改变消息
void Avdec_RegisterStateChangeMessage( HANDLE p, HWND hWnd, UINT nMess )
{
	::TMCC_RegisterConnectMessage(p, hWnd, nMess);
}

//注册解码后帧回调
void Avdec_RegisterAVFrameCallBack( HANDLE p, TMCC_AVFRAME_CALLBACK pCallBack, void* context )
{
	::TMCC_RegisterAVFrameCallBack(p, pCallBack, context);
}

//注册显示帧输出回调
void Avdec_RegisterDrawCallBack( HANDLE p, TMCC_DDRAW_CALLBACK pCallBack, void* context )
{
	::TMCC_RegisterDrawCallBack(p, pCallBack, context);
}

int	Avdec_Play( HANDLE p )
{
	tmPlayControlCfg_t cfg;

	memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
	cfg.dwSize = sizeof(tmPlayControlCfg_t);
	cfg.dwCommand = PLAY_CONTROL_PLAY;
	return ::TMCC_ControlFile(p, &cfg);
}

int	Avdec_Stop( HANDLE p )
{
	tmPlayControlCfg_t cfg;

	memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
	cfg.dwSize = sizeof(tmPlayControlCfg_t);
	cfg.dwCommand = PLAY_CONTROL_STOP;
	return ::TMCC_ControlFile(p, &cfg);
}

int	Avdec_Pause( HANDLE p )
{
	tmPlayControlCfg_t cfg;

	memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
	cfg.dwSize = sizeof(tmPlayControlCfg_t);
	cfg.dwCommand = PLAY_CONTROL_PAUSE;
	return ::TMCC_ControlFile(p, &cfg);
}

int	Avdec_StepFrame( HANDLE p, BOOL bForward )
{
	tmPlayControlCfg_t cfg;

	memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
	cfg.dwSize = sizeof(tmPlayControlCfg_t);
	cfg.dwCommand = PLAY_CONTROL_STEMP;
	cfg.control.bForward = bForward;
	return ::TMCC_ControlFile(p, &cfg);
}

int	Avdec_Fast( HANDLE p, int iSpeed )
{
	tmPlayControlCfg_t cfg;

	memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
	cfg.dwSize = sizeof(tmPlayControlCfg_t);
	cfg.dwCommand = PLAY_CONTROL_FAST;
	cfg.control.iSpeed = iSpeed;
	return ::TMCC_ControlFile(p, &cfg);
}

int	Avdec_Slow( HANDLE p, int iSpeed )
{
	tmPlayControlCfg_t cfg;

	memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
	cfg.dwSize = sizeof(tmPlayControlCfg_t);
	cfg.dwCommand = PLAY_CONTROL_SLOW;
	cfg.control.iSpeed = iSpeed;
	return ::TMCC_ControlFile(p, &cfg);
}

int	Avdec_GetTotalFrames( HANDLE p )
{
	tmPlayStateCfg_t state;

	memset(&state, 0, sizeof(tmPlayStateCfg_t));
	state.dwSize = sizeof(tmPlayStateCfg_t);
	 ::TMCC_GetFilePlayState(p, &state);
	return state.dwTotalFrames;
}

int	Avdec_GetCurrentPosition( HANDLE p )
{
	tmPlayStateCfg_t state;

	memset(&state, 0, sizeof(tmPlayStateCfg_t));
	state.dwSize = sizeof(tmPlayStateCfg_t);
	 ::TMCC_GetFilePlayState(p, &state);
	return state.dwCurrentFrame;
}

int	Avdec_SetCurrentPosition( HANDLE p, int iPosition )
{
	tmPlayControlCfg_t cfg;

	memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
	cfg.dwSize = sizeof(tmPlayControlCfg_t);
	cfg.dwCommand = PLAY_CONTROL_SEEKPOS;
	cfg.control.iCurrentPosition = iPosition;
	return ::TMCC_ControlFile(p, &cfg);
}

float Avdec_GetTotalTime( HANDLE p )
{
	tmPlayStateCfg_t state;

	memset(&state, 0, sizeof(tmPlayStateCfg_t));
	state.dwSize = sizeof(tmPlayStateCfg_t);
	 ::TMCC_GetFilePlayState(p, &state);
	return (float)state.dwTotalTimes;
}

float Avdec_GetCurrentTime( HANDLE p )
{
	tmPlayStateCfg_t state;

	memset(&state, 0, sizeof(tmPlayStateCfg_t));
	state.dwSize = sizeof(tmPlayStateCfg_t);
	 ::TMCC_GetFilePlayState(p, &state);
	return (float)state.dwCurrentTimes;
}

int	Avdec_SetCurrentTime( HANDLE p, float fCurrentTime )
{
	tmPlayControlCfg_t cfg;

	memset(&cfg, 0, sizeof(tmPlayControlCfg_t));
	cfg.dwSize = sizeof(tmPlayControlCfg_t);
	cfg.dwCommand = PLAY_CONTROL_SEEKTIME;
	cfg.control.dwCurrentTime = (int)fCurrentTime;
	return ::TMCC_ControlFile(p, &cfg);
}

int	Avdec_GetCurrentState( HANDLE p )
{
	tmPlayStateCfg_t state;

	memset(&state, 0, sizeof(tmPlayStateCfg_t));
	state.dwSize = sizeof(tmPlayStateCfg_t);
	::TMCC_GetFilePlayState(p, &state);
	return state.byCurrentState;
}

int	Avdec_GetPlayInfo( HANDLE p, tmPlayStateCfg_t* pInfo )
{
	return ::TMCC_GetFilePlayState(p, pInfo);
}

//声音控制
int	Avdec_SetVolume( HANDLE p, int iVolume )
{
	return ::TMCC_SetVolume(p, iVolume);
}

int	Avdec_SetMute( HANDLE p, BOOL bMute )
{
	return ::TMCC_SetMute(p, bMute);
}

//显示控制
int	Avdec_SetDisplayVisible( HANDLE p, BOOL bShow )
{
	return ::TMCC_SetDisplayShow(p, bShow);
}

int	Avdec_GetDisplayRegion( HANDLE p, int iRegionNum, RECT* pSrcRect, HWND* hDestWnd, BOOL* bEnable )
{
	return ::TMCC_GetDisplayRegion(p, iRegionNum, pSrcRect, hDestWnd, bEnable);
}

int	Avdec_SetDisplayRegion( HANDLE p, int iRegionNum, RECT* pSrcRect, HWND hDestWnd, BOOL bEnable )
{
	return ::TMCC_SetDisplayRegion(p, iRegionNum, pSrcRect, hDestWnd, bEnable);
}

int	Avdec_CapturePictureToFile( HANDLE p, const char* name, const char* fmt )
{
	return ::TMCC_CapturePictureToFile(p, name, fmt);
}

int	Avdec_CapturePictureToBuffer( HANDLE p, const char* fmt, void* buf, int* buf_len )
{
	return ::TMCC_CapturePictureToBuffer(p, fmt, buf, buf_len);
}

int	Avdec_RefreshDisplay( HANDLE p )
{
	return ::TMCC_RefreshDisplay(p);
}

int	Avdec_ClearDisplay( HANDLE p )
{
	return ::TMCC_ClearDisplay(p);
}

int	Avdec_GetImageSize( HANDLE p, int* iWidth, int* iHeight )
{
	return ::TMCC_GetImageSize(p, iWidth, iHeight);
}

int	Avdec_GetDisplayScale( HANDLE p, int* iScale )
{
	return ::TMCC_GetDisplayScale(p, iScale);
}

int	Avdec_SetDiareekMode( HANDLE p, int iMode )
{
	return ::TMCC_SetDiareekMode(p, iMode);
}

int	Avdec_SaveFileIndex( HANDLE p, const char* pFileIndexName )
{
	int					iRet, iNum, iSize;
	tmPlayControlCfg_t	cmd;
	BYTE*				pIndexBuf = (BYTE*)malloc(INDEX_BUF_MAXSIZE);
	FILE*				pf = NULL;

	memset(&cmd, 0, sizeof(tmPlayControlCfg_t));
	cmd.dwSize = sizeof(tmPlayControlCfg_t);
	cmd.dwCommand = PLAY_CONTROL_GETAVINDEX;
	cmd.control.index.pAvIndex = (tmAvIndexEntry_t*)pIndexBuf;
	cmd.control.index.iAvIndexCount = 0;
	cmd.control.index.iAvIndexMaxCount = INDEX_BUF_MAXSIZE / sizeof(tmAvIndexEntry_t);
	
	iRet = ::TMCC_ControlFile(p, &cmd);
	if( iRet == 0 && cmd.control.index.iAvIndexCount > 0 )
	{
		iSize = cmd.control.index.iAvIndexCount * sizeof(tmAvIndexEntry_t);
		pf = fopen(pFileIndexName, "wb");
		if( pf != NULL )
		{
			fwrite(pIndexBuf, 1, iSize, pf);
			fclose(pf);
			pf = NULL;
		}
	}

_exit:
	if( pf != NULL )
	{
		fclose(pf);
		pf = NULL;
	}
	if( pIndexBuf != NULL )
	{
		free(pIndexBuf);
	}
	return 0;
}

