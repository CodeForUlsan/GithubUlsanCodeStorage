#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

void NotifyIconDataCall(HWND hWnd, NOTIFYICONDATA *NotifyIconData, int Tray)
{
	NotifyIconData->cbSize = sizeof(NOTIFYICONDATA);
	NotifyIconData->hWnd = hWnd;
	NotifyIconData->uID = 0;
	NotifyIconData->uFlags = NIF_ICON|NIF_TIP|NIF_MESSAGE;
	NotifyIconData->uCallbackMessage = Tray;
	NotifyIconData->hIcon = LoadIcon(NULL, IDI_APPLICATION);
}