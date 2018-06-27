#include "Headers\HeaderCollect.h"

LRESULT CALLBACK MinimizeWindowImageButtonWndProc(HWND hMinimizeWindowImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	RECT ButtonClientRect;

	switch(iMessage)
	{
	case WM_CREATE:
		GetWindowRect(hMinimizeWindowImageButtonWnd, &ButtonClientRect);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hMinimizeWindowImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MinimizeButtonNormal.bmp"));
		EndPaint(hMinimizeWindowImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		SendMessage(hMainWnd, WM_SIZE, SIZE_MINIMIZED, 0);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hMinimizeWindowImageButtonWnd, iMessage, wParam, lParam));
}