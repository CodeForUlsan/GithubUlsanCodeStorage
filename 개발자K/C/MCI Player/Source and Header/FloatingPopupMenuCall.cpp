#include "Headers\HeaderCollect.h"

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