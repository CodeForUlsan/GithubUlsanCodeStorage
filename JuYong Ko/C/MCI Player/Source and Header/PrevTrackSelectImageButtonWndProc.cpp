#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK PrevTrackSelectImageButtonWndProc(HWND hPrevTrackSelectImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	RECT ButtonClientRect;
	int ListBoxIndexValue = 0;
	TCHAR lpstrFile[MAX_PATH] = TEXT("");

	switch(iMessage)
	{
	case WM_CREATE:
		GetWindowRect(hPrevTrackSelectImageButtonWnd, &ButtonClientRect);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hPrevTrackSelectImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PrevButtonNormal.bmp"));
		EndPaint(hPrevTrackSelectImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		ListBoxIndexValue = SendMessage(hPlayListBoxWnd, LB_GETCURSEL, 0, 0);
		if(SendMessage(hPlayListBoxWnd, LB_GETTOPINDEX, 0, 0) >= ListBoxIndexValue)
			ListBoxIndexValue = (SendMessage(hPlayListBoxWnd, LB_GETCOUNT, 0, 0) - 1);
		else
			ListBoxIndexValue--;
		SendMessage(hPlayListBoxWnd, LB_SETCURSEL, ListBoxIndexValue, 0);
		SendMessage(hPlayListBoxWnd, LB_GETTEXT, ListBoxIndexValue, (LPARAM)lpstrFile);
		lstrcpy(Global_lpstrFile, lpstrFile);
		hPlayListWnd = FindWindow(lpszMainWndClassName, NULL);
		SendMessage(hPlayListWnd, WM_COMMAND, PLAYORPAUSECHANGEBUTTON, 0);
		hPlayListWnd = FindWindow(lpszPlayListWndClassName, NULL);		
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hPrevTrackSelectImageButtonWnd, iMessage, wParam, lParam));
}