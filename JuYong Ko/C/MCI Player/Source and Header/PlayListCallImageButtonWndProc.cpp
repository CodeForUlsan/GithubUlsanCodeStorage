#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK PlayListCallImageButtonWndProc(HWND hPlayListCallImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	RECT ButtonClientRect;
	RECT userResolution;

	switch(iMessage)
	{
	case WM_CREATE:
		GetWindowRect(hPlayListCallImageButtonWnd, &ButtonClientRect);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hPlayListCallImageButtonWnd, &PaintStruct);
		if(PlayListOnOff == FALSE)
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIPlayListOffButton.bmp"));
		else
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIPlayListOnButton.bmp"));
		EndPaint(hPlayListCallImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		PlayListOnOff = !PlayListOnOff;
		if(PlayListOnOff == TRUE)
		{
			GetWindowRect(GetDesktopWindow(), &userResolution);
			MoveWindow(hPlayListWnd, (userResolution.right-400), (userResolution.bottom-750), 400, 500, TRUE);
			ShowWindow(hPlayListWnd, SW_SHOW);
			WndLayerTransparentOnOff(GlassOnOff, hPlayListWnd);
		}
		else
		{
			ShowWindow(hPlayListWnd, SW_HIDE);
		}
		InvalidateRect(hPlayListCallImageButtonWnd, NULL, true);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hPlayListCallImageButtonWnd, iMessage, wParam, lParam));
}