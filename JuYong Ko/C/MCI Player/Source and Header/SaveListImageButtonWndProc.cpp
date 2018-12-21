#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK SaveListImageButtonWndProc(HWND hSaveListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	TCHAR ListIni[MAX_PATH];
	TCHAR IniListSaveBuffer[MAX_PATH] = TEXT("");
	char IniCastIndexBuffer[MAX_PATH] = "";
	TCHAR IniIndexBuffer[MAX_PATH] = TEXT("");
	int IniSaveLoop = 0;

	switch(iMessage)
	{
	case WM_PAINT:
		hDC = BeginPaint(hSaveListImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PlayListSavelist.bmp"));
		EndPaint(hSaveListImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		GetCurrentDirectory(MAX_PATH, IniPath);
		_stprintf_s(ListIni, TEXT("%s\\MCIPlayList.ini"), IniPath);
		for(IniSaveLoop = 0; IniSaveLoop <= (SendMessage(hPlayListBoxWnd, LB_GETCOUNT, 0, 0) - 1); IniSaveLoop++)
		{
			SendMessage(hPlayListBoxWnd, LB_GETTEXT, IniSaveLoop, (LPARAM)IniListSaveBuffer);
			_itoa_s(IniSaveLoop, IniCastIndexBuffer, MAX_PATH, 10);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, IniCastIndexBuffer, strlen(IniCastIndexBuffer), IniIndexBuffer, MAX_PATH);
			WritePrivateProfileString(TEXT("PlayList"), IniIndexBuffer, IniListSaveBuffer, ListIni);
		}
		MessageBox(hSaveListImageButtonWnd, TEXT("리스트의 저장이 완료되었습니다."), TEXT("저장 완료"), MB_OK);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hSaveListImageButtonWnd, iMessage, wParam, lParam));
}