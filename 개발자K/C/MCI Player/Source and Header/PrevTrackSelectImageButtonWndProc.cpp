#include "Headers\HeaderCollect.h"

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