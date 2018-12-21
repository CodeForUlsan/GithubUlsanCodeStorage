#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK GlassImageButtonWndProc(HWND hGlassImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	RECT ButtonClientRect;

	switch(iMessage)
	{
	case WM_CREATE:
		GetWindowRect(hGlassImageButtonWnd, &ButtonClientRect);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hGlassImageButtonWnd, &PaintStruct);
		if(GlassOnOff == FALSE)
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIGlassOffButton.bmp"));
		else if(GlassOnOff == TRUE)
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIGlassOnButton.bmp"));
		EndPaint(hGlassImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		GlassOnOff = !GlassOnOff;
		WndLayerTransparentOnOff(GlassOnOff, hMainWnd);
		WndLayerTransparentOnOff(GlassOnOff, hPlayListWnd);
		InvalidateRect(hGlassImageButtonWnd, NULL, true);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hGlassImageButtonWnd, iMessage, wParam, lParam));
}