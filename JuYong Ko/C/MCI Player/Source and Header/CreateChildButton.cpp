#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

HWND CreateChildButton(TCHAR *WindowCaption, RECT *WinClientRectangle, int ButtonPositionX, int ButtonPositionY,
					   int ButtonWidth, int ButtonHeight, HWND *hWnd, HMENU ButtonWindowID)//��ư ���� �Լ�
{
	HWND ButtonWnd;//��ư���� ������ ���ϵ� �������� �ڵ鰪

	ButtonWnd = CreateWindow(TEXT("BUTTON"), WindowCaption, WS_CHILD|WS_VISIBLE|WS_BORDER|BS_PUSHBUTTON,
		(WinClientRectangle->right/2)+ButtonPositionX, (WinClientRectangle->bottom/2)+ButtonPositionY,
		ButtonWidth, ButtonHeight, *hWnd, ButtonWindowID, g_hInstance, NULL);
	return ButtonWnd;//�ڵ鰪�� �����Ͽ� �޴� �ڵ��μ��� ���� �ڵ��� ������ �ȴ�.
}