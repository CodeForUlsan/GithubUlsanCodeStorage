#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK PlayListWndProc(HWND hPlayListWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	RECT PlayListWndClientRect;
	TCHAR lpstrFile[MAX_PATH] = TEXT("");
	TCHAR lpstrFileTitle[MAX_PATH] = TEXT("");
	int ListBoxIndexValue=0;
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	UINT nHit;

	switch(iMessage)
	{
	case WM_CREATE:
		GetClientRect(hPlayListWnd, &PlayListWndClientRect);
		
		SetWindowLong(hPlayListWnd, GWL_EXSTYLE, GetWindowLong(hMainWnd, GWL_EXSTYLE)|WS_EX_LAYERED);

		hClosePlayListImageButtonWnd = CreateWindow(lpszClosePlayListImageButtonClassName, lpszClosePlayListImageButtonClassName,
			WS_CHILD|WS_VISIBLE,
			PlayListWndClientRect.right-43, PlayListWndClientRect.top+8,
			40, 30,
			hPlayListWnd, (HMENU)NULL, g_hInstance, NULL);
		
		hAddListImageButtonWnd = CreateWindow(lpszAddListImageButtonClassName, lpszAddListImageButtonClassName,
			WS_CHILD|WS_VISIBLE,
			PlayListWndClientRect.left+20, PlayListWndClientRect.bottom-100,
			100, 30,
			hPlayListWnd, (HMENU)NULL, g_hInstance, NULL);

		hDeleteListImageButtonWnd = CreateWindow(lpszDeleteListImageButtonClassName, lpszDeleteListImageButtonClassName,
			WS_CHILD|WS_VISIBLE,
			PlayListWndClientRect.left+150, PlayListWndClientRect.bottom-100,
			100, 30,
			hPlayListWnd, (HMENU)NULL, g_hInstance, NULL);

		hAllDeleteImageButtonWnd = CreateWindow(lpszAllDeleteImageButtonClassName, lpszAllDeleteImageButtonClassName,
			WS_CHILD|WS_VISIBLE,
			PlayListWndClientRect.right-120, PlayListWndClientRect.bottom-100,
			100, 30,
			hPlayListWnd, (HMENU)NULL, g_hInstance, NULL);

		hSaveListImageButtonWnd = CreateWindow(lpszSaveListImageButtonClassName, lpszSaveListImageButtonClassName,
			WS_CHILD|WS_VISIBLE,
			PlayListWndClientRect.left+75, PlayListWndClientRect.bottom-60,
			100, 30,
			hPlayListWnd, (HMENU)NULL, g_hInstance, NULL);

		hLoadListImageButtonWnd = CreateWindow(lpszLoadListImageButtonClassName, lpszLoadListImageButtonClassName,
			WS_CHILD|WS_VISIBLE,
			PlayListWndClientRect.right-175, PlayListWndClientRect.bottom-60,
			100, 30,
			hPlayListWnd, (HMENU)NULL, g_hInstance, NULL);

		hPlayListBoxWnd = CreateWindow(TEXT("LISTBOX"), NULL,
			WS_CHILD|WS_VISIBLE|WS_BORDER|LBS_NOTIFY|LBS_HASSTRINGS,
			PlayListWndClientRect.left+20, PlayListWndClientRect.top+51,
			PlayListWndClientRect.right-40, PlayListWndClientRect.bottom-150,
			hPlayListWnd, (HMENU)PLAYLISTBOX, g_hInstance, NULL);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hPlayListWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PlayListSkin.bmp"));
		EndPaint(hPlayListWnd, &PaintStruct);
		return 0;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case PLAYLISTBOX:
			switch(HIWORD(wParam))
			{
			case LBN_DBLCLK:
				ListBoxIndexValue = SendMessage(hPlayListBoxWnd, LB_GETCURSEL, 0, 0);
				SendMessage(hPlayListBoxWnd, LB_GETTEXT, ListBoxIndexValue, (LPARAM)lpstrFile);
				lstrcpy(Global_lpstrFile, lpstrFile);
				hPlayListWnd = FindWindow(lpszMainWndClassName, NULL);
				SendMessage(hPlayListWnd, WM_COMMAND, PLAYORPAUSECHANGEBUTTON, 0);
				hPlayListWnd = FindWindow(lpszPlayListWndClassName, NULL);
				break;
			}
			break;
		}
		return 0;
	case WM_NCHITTEST:
		nHit = DefWindowProc(hPlayListWnd, iMessage, wParam, lParam);
		if(nHit == HTCLIENT)
			nHit = HTCAPTION;
		return nHit;
	case WM_CLOSE:
		ShowWindow(hPlayListWnd, SW_HIDE);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hPlayListWnd, iMessage, wParam, lParam));
}