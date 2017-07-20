// PlayCom.h: interface for the CPlayCom class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYCOM_H__D00BBC87_5882_4148_91B6_D3BD03DDBD2D__INCLUDED_)
#define AFX_PLAYCOM_H__D00BBC87_5882_4148_91B6_D3BD03DDBD2D__INCLUDED_

#include "./inc/tmTransDefine.h"
#include "./inc/tmControlClient.h"
#pragma comment(lib, "./lib/tmControlClient.lib")

//�򿪲��ŵ��ļ�
HANDLE	Avdec_OpenFile( const char* lpFileName, HWND hWnd, BOOL bAutoCreateIndex, BOOL bAutoPlay );
HANDLE	Avdec_OpenFileA( HANDLE hLogin, tmPlayConditionCfg_t* pStruCond, HWND hWnd );
int		Avdec_CloseFile( HANDLE p );

//ע��״̬�ı�ص�
void	Avdec_RegisterStateChangeCallBack( HANDLE p, TMCC_CONNECT_CALLBACK pCallBack, void* context );
//ע��״̬�ı���Ϣ
void	Avdec_RegisterStateChangeMessage( HANDLE p, HWND hWnd, UINT nMess );
//ע������֡�ص�
void	Avdec_RegisterAVFrameCallBack( HANDLE p, TMCC_AVFRAME_CALLBACK pCallBack, void* context );
//ע����ʾ֡����ص�
void	Avdec_RegisterDrawCallBack( HANDLE p, TMCC_DDRAW_CALLBACK pCallBack, void* context );


int		Avdec_Play( HANDLE p );
int		Avdec_Stop( HANDLE p );
int		Avdec_Pause( HANDLE p );
int		Avdec_StepFrame( HANDLE p, BOOL bForward );
int		Avdec_Fast( HANDLE p, int iSpeed );
int		Avdec_Slow( HANDLE p, int iSpeed );
int		Avdec_GetTotalFrames( HANDLE p );
int		Avdec_GetCurrentPosition( HANDLE p );
int		Avdec_SetCurrentPosition( HANDLE p, int iPosition );	
float	Avdec_GetTotalTime( HANDLE p );
float	Avdec_GetCurrentTime( HANDLE p );		
int		Avdec_SetCurrentTime( HANDLE p, float fCurrentTime );
int		Avdec_GetCurrentState( HANDLE p );
int		Avdec_GetPlayInfo( HANDLE p, tmPlayStateCfg_t* pInfo );

//��������
int		Avdec_GetVolume( HANDLE p );
int		Avdec_SetVolume( HANDLE p, int iVolume );
BOOL	Avdec_GetMute( HANDLE p );
int		Avdec_SetMute( HANDLE p, BOOL bMute );

//��ʾ����
int		Avdec_SetDisplayVisible( HANDLE p, BOOL bShow );
int		Avdec_GetDisplayRegion( HANDLE p, int iRegionNum, RECT* pSrcRect, HWND* hDestWnd, BOOL* bEnable );
int		Avdec_SetDisplayRegion( HANDLE p, int iRegionNum, RECT* pSrcRect, HWND hDestWnd, BOOL bEnable );
int		Avdec_CapturePictureToFile( HANDLE p, const char* name, const char* fmt );
int		Avdec_CapturePictureToBuffer( HANDLE p, const char* fmt, void* buf, int* buf_len );
int		Avdec_RefreshDisplay( HANDLE p );
int		Avdec_ClearDisplay( HANDLE p );
int		Avdec_GetImageSize( HANDLE p, int* iWidth, int* iHeight );
int		Avdec_GetDisplayScale( HANDLE p, int* iScale );
int		Avdec_SetDiareekMode( HANDLE p, int iMode );

int		Avdec_SaveFileIndex( HANDLE p, const char* pFileIndexName );

#endif // !defined(AFX_PLAYCOM_H__D00BBC87_5882_4148_91B6_D3BD03DDBD2D__INCLUDED_)
