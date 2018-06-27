#include "Headers\HeaderCollect.h"

LRESULT CALLBACK MakerLogoImageWndProc(HWND hMakerLogoImageWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT PaintStruct;

	switch(iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hMakerLogoImageWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hdc, TEXT("Images\\BlueLemonLogo.bmp"));
		EndPaint(hMakerLogoImageWnd, &PaintStruct);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hMakerLogoImageWnd, iMessage, wParam, lParam));
}