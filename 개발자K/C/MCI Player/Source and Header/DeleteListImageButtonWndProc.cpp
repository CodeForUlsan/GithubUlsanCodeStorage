#include "Headers\HeaderCollect.h"

LRESULT CALLBACK DeleteListImageButtonWndProc(HWND hDeleteListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	int ListBoxIndexValue=0;

	switch(iMessage)
	{
	case WM_PAINT:
		hDC = BeginPaint(hDeleteListImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PlayListDellist.bmp"));
		EndPaint(hDeleteListImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		ListBoxIndexValue = SendMessage(hPlayListBoxWnd, LB_GETCURSEL, 0, 0);
		SendMessage(hPlayListBoxWnd, LB_DELETESTRING, ListBoxIndexValue, 0);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hDeleteListImageButtonWnd, iMessage, wParam, lParam));
}