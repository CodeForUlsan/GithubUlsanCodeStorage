#include "Headers\HeaderCollect.h"

LRESULT CALLBACK VersionImageButtonWndProc(HWND hVersionImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	RECT ButtonClientRect;
	RECT userResolution;

	switch(iMessage)
	{
	case WM_CREATE:
		GetWindowRect(hVersionImageButtonWnd, &ButtonClientRect);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hVersionImageButtonWnd, &PaintStruct);
		if(VersionOnOff == FALSE)
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIVersionOffButton.bmp"));
		else
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIVersionOnButton.bmp"));
		EndPaint(hVersionImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		VersionOnOff = !VersionOnOff;
		if(VersionOnOff == TRUE)
		{
			GetWindowRect(GetDesktopWindow(), &userResolution);
			MoveWindow(hCopyrightWnd, (userResolution.right-500)/2, (userResolution.bottom-500)/2, 500, 500, TRUE);
			ShowWindow(hCopyrightWnd, SW_SHOWNORMAL);
		}
		else
		{
			ShowWindow(hCopyrightWnd, SW_HIDE);
		}
		InvalidateRect(hVersionImageButtonWnd, NULL, true);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hVersionImageButtonWnd, iMessage, wParam, lParam));
}