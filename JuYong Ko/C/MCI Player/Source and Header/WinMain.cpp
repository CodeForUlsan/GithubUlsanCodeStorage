#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

//�Լ� �����
//������ ���ν���
//MainWndProcs ����
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

//CopyrightWndProcs ����
LRESULT CALLBACK CopyrightWndProc(HWND hCopyrightWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK MakerLogoImageWndProc(HWND hMkaerLogoImageWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ProgramLogoImageWndProc(HWND hProgramLogoImageWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK CloseCopyrightImageButtonWndProc(HWND hCloseCopyrightImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

//PlayListWndProcs ����
LRESULT CALLBACK PlayListWndProc(HWND hPlayListWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ClosePlayListImageButtonWndProc(HWND hClosePlayListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AddListImageButtonWndProc(HWND hAddListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DeleteListImageButtonWndProc(HWND hDeleteListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AllDeleteImageButtonWndProc(HWND hDeleteAllImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SaveListImageButtonWndProc(HWND hSaveListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LoadListImageButtonWndProc(HWND hLoadListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

//�������� ����� VariableCollect.h extern ����
HINSTANCE g_hInstance;

//ClassNames
//MainWndProcs ����
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

//CopyrightWndProcs ����
LPCTSTR lpszCopyrightWndClassName = TEXT("Version Window");
LPCTSTR lpszMakerLogoImageClassName = TEXT("Maker Logo Image");
LPCTSTR lpszProgramLogoImageClassName = TEXT("Program Logo Image");
LPCTSTR lpszCloseCopyrightImageButtonClassName = TEXT("Copyright Close Button");

//PlayListWndProcs ����
LPCTSTR lpszPlayListWndClassName = TEXT("Play List Window");
LPCTSTR lpszClosePlayListImageButtonClassName = TEXT("PlayList Close Button");
LPCTSTR lpszAddListImageButtonClassName = TEXT("AddList Button");
LPCTSTR lpszDeleteListImageButtonClassName = TEXT("DeleteList Button");
LPCTSTR lpszAllDeleteImageButtonClassName = TEXT("DeleteAll Button");
LPCTSTR lpszSaveListImageButtonClassName = TEXT("SaveList Button");
LPCTSTR lpszLoadListImageButtonClassName = TEXT("LoadList Button");

//�ڵ鷯
//MainWndProcs ����
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

//CopyrightWndProcs ����
HWND hCopyrightWnd;
HWND hMakerLogoImageWnd;
HWND hProgramLogoImageWnd;
HWND hCloseCopyrightImageButtonWnd;

//PlayListWndProcs ����
HWND hPlayListWnd;
HWND hPlayListBoxWnd;
HWND hClosePlayListImageButtonWnd;
HWND hAddListImageButtonWnd;
HWND hDeleteListImageButtonWnd;
HWND hAllDeleteImageButtonWnd;
HWND hSaveListImageButtonWnd;
HWND hLoadListImageButtonWnd;

//���� ����
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

	if(FindWindow(lpszMainWndClassName, NULL)!=NULL)//������ Ŭ������ ����ϱ� ���� �ش� Ŭ�������� ���� �����츦 ã�´�. ã������ ��� NULL���� ��ȯ�ϹǷ�...
	{//�ش��ϴ� �����찡 �ִٸ�...
		hMainWnd = FindWindow(lpszMainWndClassName, NULL);//�����ڵ鿡 ã�� �������� �ڵ��� �����Ѵ�.
		if(IsIconic(hMainWnd))
			SendMessage(hMainWnd, TRAY, WM_LBUTTONDOWN, 0);//ã�� ������ �ڵ��� ���� TRAY �޼����� ȣ���Ѵ�.

		SetForegroundWindow(hMainWnd);//�ش� �ڵ鰪�� ���� �����츦 �ֻ����� ��ġ�� TOP_MOST ��Ų��.
		return 0;//���� �����Ϸ��ߴ� ������� Ŭ������ ������� �ʰ� �����Ų��.
	}

	//������ Ŭ���� ��Ϻ�
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

	//�޼��� ������
	for(;;)
	{
		if(PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))//�޼������� �����Ѵ�.
		{//����ڷκ��� �޼����� �޾Ҵٸ�...
			if(Message.message == WM_QUIT)//���� ���� �޼����� WM_QUIT���...
			{
				break;
			}
			else//���� �޼����� WM_QUIT�޼��� �̿��� �޼������...
			{
				TranslateMessage(&Message);
				DispatchMessage(&Message);				
			}
		}
		else//�޼����� ���� ���ߴٸ�...
		{
			WaitMessage();//�޼����� ���������� ����Ѵ�.
		}
	}

	return (int)Message.wParam;
}