#include "Headers\HeaderCollect.h"

LRESULT CALLBACK RepeatImageButtonWndProc(HWND hRepeatImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	RECT ButtonClientRect;

	switch(iMessage)
	{
	case WM_CREATE:
		GetWindowRect(hRepeatImageButtonWnd, &ButtonClientRect);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hRepeatImageButtonWnd, &PaintStruct);
		if(RepeatOnOff == FALSE)
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIRepeatOffButton.bmp"));
		else if(RepeatOnOff == TRUE)
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIRepeatOnButton.bmp"));
		EndPaint(hRepeatImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		RepeatOnOff = !RepeatOnOff;
		InvalidateRect(hRepeatImageButtonWnd, NULL, true);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hRepeatImageButtonWnd, iMessage, wParam, lParam));
}