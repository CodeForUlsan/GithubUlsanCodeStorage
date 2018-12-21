#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

void FloatingPopupMenuCall(HWND hWnd, HMENU hMenu, HMENU hPopup, POINT Point)
{
	hMenu = LoadMenu(g_hInstance, MAKEINTRESOURCE(IDR_MENU1));
	hPopup = GetSubMenu(hMenu, 0);
	GetCursorPos(&Point);
	SetForegroundWindow(hWnd);
	TrackPopupMenu(hPopup, TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON, Point.x, Point.y, 0, hWnd, NULL);
	SetForegroundWindow(hWnd);
	DestroyMenu(hPopup);
	DestroyMenu(hMenu);
}