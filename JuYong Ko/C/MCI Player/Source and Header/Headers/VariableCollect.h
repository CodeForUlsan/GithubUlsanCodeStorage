#ifndef _VARIABLECOLLECT_H_
#define _VARIABLECOLLECT_H_

//���� ������ ��Ʈ�� ID
#define PLAYORPAUSECHANGEBUTTON 100
#define STOPBUTTON 101
#define PLAYPOSITIONSCROLLBAR 200
#define VOLUMEPOSITIONSCROLLBAR 201
#define PLAYPOSITIONSTATICTIMER 301
#define PLAYPOSITIONSCROLLTIMER 302
#define INITIALIZELAYERSETTIMER 303
#define TRAY (WM_APP + 100)

//PlayListWindow ��Ʈ�� ID
#define PLAYLISTBOX 601

extern HINSTANCE g_hInstance;//���� �ν��Ͻ� ��

//MainWndProcs ����
extern LPCTSTR lpszMainWndClassName;//�θ������� Ŭ������, �θ������� ĸ�ǹ� �ؽ�Ʈ
extern LPCTSTR lpszPlayOrPauseImageButtonWndClassName;
extern LPCTSTR lpszStopImageButtonWndClassName;
extern LPCTSTR lpszPrevTrackSelectImageButtonWndClassName;
extern LPCTSTR lpszNextTrackSelectImageButtonWndClassName;
extern LPCTSTR lpszCloseWindowImageButtonWndClassName;
extern LPCTSTR lpszMinimizeWindowImageButtonWndClassName;
extern LPCTSTR lpszRepeatImageButtonClassName;
extern LPCTSTR lpszGlassImageButtonClassName;
extern LPCTSTR lpszVersionImageButtonClassName;
extern LPCTSTR lpszPlayListCallImageButtonClassName;

//CopyrightWndProcs ����
extern LPCTSTR lpszCopyrightWndClassName;
extern LPCTSTR lpszMakerLogoImageClassName;
extern LPCTSTR lpszProgramLogoImageClassName;
extern LPCTSTR lpszCloseCopyrightImageButtonClassName;

//PlayListWndProcs ����
extern LPCTSTR lpszPlayListWndClassName;
extern LPCTSTR lpszClosePlayListImageButtonClassName;
extern LPCTSTR lpszAddListImageButtonClassName;
extern LPCTSTR lpszDeleteListImageButtonClassName;
extern LPCTSTR lpszAllDeleteImageButtonClassName;
extern LPCTSTR lpszSaveListImageButtonClassName;
extern LPCTSTR lpszLoadListImageButtonClassName;

//�� ��Ʈ�� ��������� �ڵ��� ������ ����
//���� ������ �ڵ鷯
//MainWndProcs ����
extern HWND hMainWnd;
extern HWND hPlayOrPauseImageButtonWnd;
extern HWND hStopImageButtonWnd;
extern HWND hPrevTrackSelectImageButtonWnd;
extern HWND hNextTrackSelectImageButtonWnd;
extern HWND hCloseWindowImageButtonWnd;
extern HWND hMinimizeWindowImageButtonWnd;
extern HWND hPlayPositionScrollWnd;
extern HWND hVolumePositionScrollWnd;
extern HWND hFileNameStaticWnd;
extern HWND hPlayPositionStaticWnd;
extern HWND hVolumePositionStaticWnd;
extern HWND hRepeatImageButtonWnd;
extern HWND hGlassImageButtonWnd;
extern HWND hVersionImageButtonWnd;
extern HWND hPlayListCallImageButtonWnd;

//CopyrightWndProcs ����
extern HWND hCopyrightWnd;
extern HWND hMakerLogoImageWnd;
extern HWND hProgramLogoImageWnd;
extern HWND hCloseCopyrightImageButtonWnd;

//PlayListWndProcs ����
extern HWND hPlayListWnd;
extern HWND hPlayListBoxWnd;
extern HWND hClosePlayListImageButtonWnd;
extern HWND hAddListImageButtonWnd;
extern HWND hDeleteListImageButtonWnd;
extern HWND hAllDeleteImageButtonWnd;
extern HWND hSaveListImageButtonWnd;
extern HWND hLoadListImageButtonWnd;

//��Ÿ ���� ����
//WinMain.cpp
extern UINT MciDeviceID;//MCI����̽� ���̵��� �����ϱ� ���� ���� ����

extern TCHAR Global_lpstrFile[MAX_PATH];

extern int VolumeScrollValue;
extern DWORD VolumeValue;
extern int PlayScrollValue;
extern DWORD PlayTotalTimeValue;
extern DWORD PlayCurrentTimeValue;
extern BOOL PlayorPause;
extern BOOL RepeatOnOff;
extern BOOL GlassOnOff;
extern BOOL VersionOnOff;
extern BOOL PlayListOnOff;

extern TCHAR IniPath[MAX_PATH];
extern TCHAR VolumeValueBuffer[10];
extern char CastVolumeValueBuffer[10];
extern TCHAR IniOnOffState[10];
extern char CastIniOnOffState[10];

#endif