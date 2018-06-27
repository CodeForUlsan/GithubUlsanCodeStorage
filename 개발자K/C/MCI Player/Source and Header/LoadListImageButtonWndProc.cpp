#include "Headers\HeaderCollect.h"

LRESULT CALLBACK LoadListImageButtonWndProc(HWND hLoadListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	TCHAR ListIni[MAX_PATH];
	TCHAR IniListLoadBuffer[MAX_PATH] = TEXT("");
	char IniCastIndexBuffer[MAX_PATH] = "";
	TCHAR IniIndexBuffer[MAX_PATH] = TEXT("");
	int IniLoadLoop = 0;

	switch(iMessage)
	{
	case WM_PAINT:
		hDC = BeginPaint(hLoadListImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PlayListLoadlist.bmp"));
		EndPaint(hLoadListImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		GetCurrentDirectory(MAX_PATH, IniPath);
		_stprintf_s(ListIni, TEXT("%s\\MCIPlayList.ini"), IniPath);
		_itoa_s(IniLoadLoop, IniCastIndexBuffer, MAX_PATH, 10);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, IniCastIndexBuffer, strlen(IniCastIndexBuffer), IniIndexBuffer, MAX_PATH);
		for(IniLoadLoop = 0; 0 != GetPrivateProfileString(TEXT("PlayList"), IniIndexBuffer, TEXT(""), IniListLoadBuffer, MAX_PATH, ListIni); IniLoadLoop++)
		{
			_itoa_s(IniLoadLoop, IniCastIndexBuffer, MAX_PATH, 10);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, IniCastIndexBuffer, strlen(IniCastIndexBuffer), IniIndexBuffer, MAX_PATH);
			GetPrivateProfileString(TEXT("PlayList"), IniIndexBuffer, TEXT(""), IniListLoadBuffer, MAX_PATH, ListIni);
			SendMessage(hPlayListBoxWnd, LB_ADDSTRING, IniLoadLoop, (LPARAM)IniListLoadBuffer);
		}
		MessageBox(hLoadListImageButtonWnd, TEXT("MCIPlayList.ini로 부터 리스트를 불러왔습니다."), TEXT("불러오기 완료"), MB_OK);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hLoadListImageButtonWnd, iMessage, wParam, lParam));
}