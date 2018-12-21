#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

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