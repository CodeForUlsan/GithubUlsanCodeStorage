#include "Headers\HeaderCollect.h"

LRESULT CALLBACK AllDeleteImageButtonWndProc(HWND hAllDeleteImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;

	switch(iMessage)
	{
	case WM_PAINT:
		hDC = BeginPaint(hAllDeleteImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PlayListAlldel.bmp"));
		EndPaint(hAllDeleteImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		SendMessage(hPlayListBoxWnd, LB_RESETCONTENT, 0, 0);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hAllDeleteImageButtonWnd, iMessage, wParam, lParam));
}