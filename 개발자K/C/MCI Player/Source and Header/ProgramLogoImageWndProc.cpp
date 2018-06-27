#include "Headers\HeaderCollect.h"

LRESULT CALLBACK ProgramLogoImageWndProc(HWND hProgramLogoImageWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT PaintStruct;

	switch(iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hProgramLogoImageWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hdc, TEXT("Images\\ProgramLogo.bmp"));
		EndPaint(hProgramLogoImageWnd, &PaintStruct);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hProgramLogoImageWnd, iMessage, wParam, lParam));
}