#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK PlayOrPauseImageButtonWndProc(HWND hPlayOrPauseImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	RECT ButtonClientRect;	

	switch(iMessage)
	{
	case WM_CREATE:
		GetWindowRect(hPlayOrPauseImageButtonWnd, &ButtonClientRect);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hPlayOrPauseImageButtonWnd, &PaintStruct);
		if(PlayorPause == FALSE)
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PlayButtonNormal.bmp"));
		else if(PlayorPause == TRUE)
			CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PauseButtonNormal.bmp"));
		EndPaint(hPlayOrPauseImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		SendMessage(hMainWnd, WM_COMMAND, PLAYORPAUSECHANGEBUTTON, 0);
		InvalidateRect(hPlayOrPauseImageButtonWnd, NULL, true);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hPlayOrPauseImageButtonWnd, iMessage, wParam, lParam));
}