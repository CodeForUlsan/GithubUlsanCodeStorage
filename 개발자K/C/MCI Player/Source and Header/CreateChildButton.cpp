#include "Headers\HeaderCollect.h"

HWND CreateChildButton(TCHAR *WindowCaption, RECT *WinClientRectangle, int ButtonPositionX, int ButtonPositionY,
					   int ButtonWidth, int ButtonHeight, HWND *hWnd, HMENU ButtonWindowID)//��ư ���� �Լ�
{
	HWND ButtonWnd;//��ư���� ������ ���ϵ� �������� �ڵ鰪

	ButtonWnd = CreateWindow(TEXT("BUTTON"), WindowCaption, WS_CHILD|WS_VISIBLE|WS_BORDER|BS_PUSHBUTTON,
		(WinClientRectangle->right/2)+ButtonPositionX, (WinClientRectangle->bottom/2)+ButtonPositionY,
		ButtonWidth, ButtonHeight, *hWnd, ButtonWindowID, g_hInstance, NULL);
	return ButtonWnd;//�ڵ鰪�� �����Ͽ� �޴� �ڵ��μ��� ���� �ڵ��� ������ �ȴ�.
}