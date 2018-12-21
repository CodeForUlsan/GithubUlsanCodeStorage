#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK ClosePlayListImageButtonWndProc(HWND hClosePlayListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;

	switch(iMessage)
	{
	case WM_PAINT:
		hDC = BeginPaint(hClosePlayListImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\CloseButtonNormal.bmp"));
		EndPaint(hClosePlayListImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		ShowWindow(hPlayListWnd, SW_HIDE);
		PlayListOnOff = !PlayListOnOff;
		InvalidateRect(hPlayListCallImageButtonWnd, NULL, true);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hClosePlayListImageButtonWnd, iMessage, wParam, lParam));
}