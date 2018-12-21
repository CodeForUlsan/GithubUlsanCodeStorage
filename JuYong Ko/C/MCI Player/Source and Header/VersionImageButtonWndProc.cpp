#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

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