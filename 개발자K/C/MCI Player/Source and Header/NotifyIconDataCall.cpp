#include "Headers\HeaderCollect.h"

void NotifyIconDataCall(HWND hWnd, NOTIFYICONDATA *NotifyIconData, int Tray)
{
	NotifyIconData->cbSize = sizeof(NOTIFYICONDATA);
	NotifyIconData->hWnd = hWnd;
	NotifyIconData->uID = 0;
	NotifyIconData->uFlags = NIF_ICON|NIF_TIP|NIF_MESSAGE;
	NotifyIconData->uCallbackMessage = Tray;
	NotifyIconData->hIcon = LoadIcon(NULL, IDI_APPLICATION);
}