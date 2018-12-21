#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK PlayListCallImageButtonWndProc(HWND hPlayListCallImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	RECT ButtonClientRect;
	RECT userResolution;

	switch(iMessage)
	{
	case WM_CREATE:
		GetWindowRect(hPlayListCallImageButtonWnd, &ButtonClientRect);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hPlayListCallImageButtonWnd, &PaintStruct);
		if(PlayListOnOff == FALSE)
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIPlayListOffButton.bmp"));
		else
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\MCIPlayListOnButton.bmp"));
		EndPaint(hPlayListCallImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		PlayListOnOff = !PlayListOnOff;
		if(PlayListOnOff == TRUE)
		{
			GetWindowRect(GetDesktopWindow(), &userResolution);
			MoveWindow(hPlayListWnd, (userResolution.right-400), (userResolution.bottom-750), 400, 500, TRUE);
			ShowWindow(hPlayListWnd, SW_SHOW);
			WndLayerTransparentOnOff(GlassOnOff, hPlayListWnd);
		}
		else
		{
			ShowWindow(hPlayListWnd, SW_HIDE);
		}
		InvalidateRect(hPlayListCallImageButtonWnd, NULL, true);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hPlayListCallImageButtonWnd, iMessage, wParam, lParam));
}