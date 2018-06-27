#include "Headers\HeaderCollect.h"

LRESULT CALLBACK CloseCopyrightImageButtonWndProc(HWND hCloseCopyrightImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT PaintStruct;

	switch(iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hCloseCopyrightImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hdc, TEXT("Images\\CloseButtonNormal.bmp"));
		EndPaint(hCloseCopyrightImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		ShowWindow(hCopyrightWnd, SW_HIDE);
		VersionOnOff = !VersionOnOff;
		InvalidateRect(hVersionImageButtonWnd, NULL, true);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hCloseCopyrightImageButtonWnd, iMessage, wParam, lParam));
}