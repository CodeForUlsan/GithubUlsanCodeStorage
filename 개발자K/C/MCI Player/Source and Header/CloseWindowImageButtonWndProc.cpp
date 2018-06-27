#include "Headers\HeaderCollect.h"

LRESULT CALLBACK CloseWindowImageButtonWndProc(HWND hCloseWindowImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	RECT ButtonClientRect;

	switch(iMessage)
	{
	case WM_CREATE:
		GetWindowRect(hCloseWindowImageButtonWnd, &ButtonClientRect);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hCloseWindowImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\CloseButtonNormal.bmp"));
		EndPaint(hCloseWindowImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		SendMessage(hMainWnd, WM_CLOSE, 0, 0);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hCloseWindowImageButtonWnd, iMessage, wParam, lParam));
}