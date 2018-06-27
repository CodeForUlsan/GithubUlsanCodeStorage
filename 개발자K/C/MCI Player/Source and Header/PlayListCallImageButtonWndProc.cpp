#include "Headers\HeaderCollect.h"

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