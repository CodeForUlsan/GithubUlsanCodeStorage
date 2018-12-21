#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

//함수 선언부
//윈도우 프로시저
//MainWndProcs 필터
LRESULT CALLBACK MainWndProc(HWND hMainWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PlayOrPauseImageButtonWndProc(HWND hPlayOrPauseImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK StopImageButtonWndProc(HWND hStopImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PrevTrackSelectImageButtonWndProc(HWND hPrevTrackSelectImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK NextTrackSelectImageButtonWndProc(HWND hNextTrackSelectImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK CloseWindowImageButtonWndProc(HWND hCloseWindowImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK MinimizeWindowImageButtonWndProc(HWND hMinimizeWindowImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK RepeatImageButtonWndProc(HWND hRepeatImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK GlassImageButtonWndProc(HWND hGlassImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK VersionImageButtonWndProc(HWND hVersionImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PlayListCallImageButtonWndProc(HWND hPlayListCallImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

//CopyrightWndProcs 필터
LRESULT CALLBACK CopyrightWndProc(HWND hCopyrightWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK MakerLogoImageWndProc(HWND hMkaerLogoImageWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ProgramLogoImageWndProc(HWND hProgramLogoImageWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK CloseCopyrightImageButtonWndProc(HWND hCloseCopyrightImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

//PlayListWndProcs 필터
LRESULT CALLBACK PlayListWndProc(HWND hPlayListWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ClosePlayListImageButtonWndProc(HWND hClosePlayListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AddListImageButtonWndProc(HWND hAddListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DeleteListImageButtonWndProc(HWND hDeleteListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AllDeleteImageButtonWndProc(HWND hDeleteAllImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SaveListImageButtonWndProc(HWND hSaveListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LoadListImageButtonWndProc(HWND hLoadListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

//전역변수 선언부 VariableCollect.h extern 선언
HINSTANCE g_hInstance;

//ClassNames
//MainWndProcs 필터
TCHAR VerNumber[MAX_PATH] = TEXT("MCI Player Beta Ver C for x86");
LPCTSTR lpszMainWndClassName = VerNumber;
LPCTSTR lpszPlayOrPauseImageButtonWndClassName = TEXT("PlayOrPause Button");
LPCTSTR lpszStopImageButtonWndClassName = TEXT("Stop Button");
LPCTSTR lpszPrevTrackSelectImageButtonWndClassName = TEXT("PrevTrackSelect Button");
LPCTSTR lpszNextTrackSelectImageButtonWndClassName = TEXT("NextTrackSelect Button");
LPCTSTR lpszCloseWindowImageButtonWndClassName = TEXT("Close Window Button");
LPCTSTR lpszMinimizeWindowImageButtonWndClassName = TEXT("Minimize Window Button");
LPCTSTR lpszRepeatImageButtonClassName = TEXT("Repeat Button");
LPCTSTR lpszGlassImageButtonClassName = TEXT("Glass Button");
LPCTSTR lpszVersionImageButtonClassName = TEXT("Version Button");
LPCTSTR lpszPlayListCallImageButtonClassName = TEXT("PlayList Button");

//CopyrightWndProcs 필터
LPCTSTR lpszCopyrightWndClassName = TEXT("Version Window");
LPCTSTR lpszMakerLogoImageClassName = TEXT("Maker Logo Image");
LPCTSTR lpszProgramLogoImageClassName = TEXT("Program Logo Image");
LPCTSTR lpszCloseCopyrightImageButtonClassName = TEXT("Copyright Close Button");

//PlayListWndProcs 필터
LPCTSTR lpszPlayListWndClassName = TEXT("Play List Window");
LPCTSTR lpszClosePlayListImageButtonClassName = TEXT("PlayList Close Button");
LPCTSTR lpszAddListImageButtonClassName = TEXT("AddList Button");
LPCTSTR lpszDeleteListImageButtonClassName = TEXT("DeleteList Button");
LPCTSTR lpszAllDeleteImageButtonClassName = TEXT("DeleteAll Button");
LPCTSTR lpszSaveListImageButtonClassName = TEXT("SaveList Button");
LPCTSTR lpszLoadListImageButtonClassName = TEXT("LoadList Button");

//핸들러
//MainWndProcs 필터
HWND hMainWnd;
HWND hPlayOrPauseImageButtonWnd;
HWND hStopImageButtonWnd;
HWND hPrevTrackSelectImageButtonWnd;
HWND hNextTrackSelectImageButtonWnd;
HWND hCloseWindowImageButtonWnd;
HWND hMinimizeWindowImageButtonWnd;
HWND hPlayPositionScrollWnd;
HWND hVolumePositionScrollWnd;
HWND hFileNameStaticWnd;
HWND hPlayPositionStaticWnd;
HWND hVolumePositionStaticWnd;
HWND hRepeatImageButtonWnd;
HWND hGlassImageButtonWnd;
HWND hVersionImageButtonWnd;
HWND hPlayListCallImageButtonWnd;

//CopyrightWndProcs 필터
HWND hCopyrightWnd;
HWND hMakerLogoImageWnd;
HWND hProgramLogoImageWnd;
HWND hCloseCopyrightImageButtonWnd;

//PlayListWndProcs 필터
HWND hPlayListWnd;
HWND hPlayListBoxWnd;
HWND hClosePlayListImageButtonWnd;
HWND hAddListImageButtonWnd;
HWND hDeleteListImageButtonWnd;
HWND hAllDeleteImageButtonWnd;
HWND hSaveListImageButtonWnd;
HWND hLoadListImageButtonWnd;

//전역 변수
UINT MciDeviceID = 0;

TCHAR Global_lpstrFile[MAX_PATH] = TEXT("");

int VolumeScrollValue;
DWORD VolumeValue;
int PlayScrollValue = 0;
DWORD PlayTotalTimeValue = 0;
DWORD PlayCurrentTimeValue = 0;
BOOL PlayorPause = false;
BOOL RepeatOnOff = false; //false == Off, true == On
BOOL GlassOnOff = false; //false == Off, true == On
BOOL VersionOnOff = false; //false == hide, true == show;
BOOL PlayListOnOff = false; //false == hide, true == show;

TCHAR IniPath[MAX_PATH];
TCHAR VolumeValueBuffer[10];
char CastVolumeValueBuffer[10];
TCHAR IniOnOffState[10];
char CastIniOnOffState[10];

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszParam, int nCmdShow)
{
	MSG Message;
	WNDCLASSEX WndClassEx;
	RECT userResolution;

	g_hInstance = hInstance;

	lstrcpy((LPWSTR)lpszMainWndClassName, VerNumber);

	if(FindWindow(lpszMainWndClassName, NULL)!=NULL)//윈도우 클래스를 등록하기 전에 해당 클래스명을 가진 윈도우를 찾는다. 찾지못한 경우 NULL값을 반환하므로...
	{//해당하는 윈도우가 있다면...
		hMainWnd = FindWindow(lpszMainWndClassName, NULL);//메인핸들에 찾은 윈도우의 핸들을 대입한다.
		if(IsIconic(hMainWnd))
			SendMessage(hMainWnd, TRAY, WM_LBUTTONDOWN, 0);//찾은 윈도우 핸들이 가진 TRAY 메세지를 호출한다.

		SetForegroundWindow(hMainWnd);//해당 핸들값을 가진 윈도우를 최상위의 위치로 TOP_MOST 시킨다.
		return 0;//현재 생성하려했던 윈도우는 클래스를 등록하지 않고 종료시킨다.
	}

	//윈도우 클래스 등록부
	WndClassEx.cbSize = sizeof(WndClassEx);
	WndClassEx.cbClsExtra = 0;
	WndClassEx.cbWndExtra = 0;
	WndClassEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClassEx.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	WndClassEx.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	WndClassEx.hInstance = hInstance;
	WndClassEx.lpfnWndProc = MainWndProc;
	WndClassEx.lpszClassName = lpszMainWndClassName;
	WndClassEx.lpszMenuName = NULL;
	WndClassEx.style = CS_HREDRAW|CS_VREDRAW;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = PlayOrPauseImageButtonWndProc;
	WndClassEx.lpszClassName = lpszPlayOrPauseImageButtonWndClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = StopImageButtonWndProc;
	WndClassEx.lpszClassName = lpszStopImageButtonWndClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = PrevTrackSelectImageButtonWndProc;
	WndClassEx.lpszClassName = lpszPrevTrackSelectImageButtonWndClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = NextTrackSelectImageButtonWndProc;
	WndClassEx.lpszClassName = lpszNextTrackSelectImageButtonWndClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = CloseWindowImageButtonWndProc;
	WndClassEx.lpszClassName = lpszCloseWindowImageButtonWndClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = MinimizeWindowImageButtonWndProc;
	WndClassEx.lpszClassName = lpszMinimizeWindowImageButtonWndClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = RepeatImageButtonWndProc;
	WndClassEx.lpszClassName = lpszRepeatImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = GlassImageButtonWndProc;
	WndClassEx.lpszClassName = lpszGlassImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = VersionImageButtonWndProc;
	WndClassEx.lpszClassName = lpszVersionImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = PlayListCallImageButtonWndProc;
	WndClassEx.lpszClassName = lpszPlayListCallImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	//CopyrightWndProcs
	WndClassEx.lpfnWndProc = CopyrightWndProc;
	WndClassEx.lpszClassName = lpszCopyrightWndClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = MakerLogoImageWndProc;
	WndClassEx.lpszClassName = lpszMakerLogoImageClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = ProgramLogoImageWndProc;
	WndClassEx.lpszClassName = lpszProgramLogoImageClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = CloseCopyrightImageButtonWndProc;
	WndClassEx.lpszClassName = lpszCloseCopyrightImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	//PlayListWndProcs
	WndClassEx.lpfnWndProc = PlayListWndProc;
	WndClassEx.lpszClassName = lpszPlayListWndClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = ClosePlayListImageButtonWndProc;
	WndClassEx.lpszClassName = lpszClosePlayListImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = AddListImageButtonWndProc;
	WndClassEx.lpszClassName = lpszAddListImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = DeleteListImageButtonWndProc;
	WndClassEx.lpszClassName = lpszDeleteListImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = AllDeleteImageButtonWndProc;
	WndClassEx.lpszClassName = lpszAllDeleteImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = SaveListImageButtonWndProc;
	WndClassEx.lpszClassName = lpszSaveListImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	WndClassEx.lpfnWndProc = LoadListImageButtonWndProc;
	WndClassEx.lpszClassName = lpszLoadListImageButtonClassName;
	RegisterClassEx(&WndClassEx);

	GetClientRect(GetDesktopWindow(), &userResolution);

	hMainWnd = CreateWindowEx(WS_EX_TOPMOST, lpszMainWndClassName, lpszMainWndClassName, WS_POPUP,
		(userResolution.right-400), (userResolution.bottom-250), 400, 200,
		NULL, (HMENU)NULL, hInstance, NULL);

	//메세지 구동부
	for(;;)
	{
		if(PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))//메세지값을 조사한다.
		{//사용자로부터 메세지를 받았다면...
			if(Message.message == WM_QUIT)//만일 받은 메세지가 WM_QUIT라면...
			{
				break;
			}
			else//받은 메세지가 WM_QUIT메세지 이외의 메세지라면...
			{
				TranslateMessage(&Message);
				DispatchMessage(&Message);				
			}
		}
		else//메세지를 받지 못했다면...
		{
			WaitMessage();//메세지를 받을때까지 대기한다.
		}
	}

	return (int)Message.wParam;
}