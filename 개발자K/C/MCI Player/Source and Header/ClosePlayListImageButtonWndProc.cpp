#include "Headers\HeaderCollect.h"

LRESULT CALLBACK ClosePlayListImageButtonWndProc(HWND hClosePlayListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;

	switch(iMessage)
	{
	case WM_PAINT:
		hDC = BeginPaint(hClosePlayListImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\CloseButtonNormal.bmp"));
		EndPaint(hClosePlayListImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		ShowWindow(hPlayListWnd, SW_HIDE);
		PlayListOnOff = !PlayListOnOff;
		InvalidateRect(hPlayListCallImageButtonWnd, NULL, true);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hClosePlayListImageButtonWnd, iMessage, wParam, lParam));
}