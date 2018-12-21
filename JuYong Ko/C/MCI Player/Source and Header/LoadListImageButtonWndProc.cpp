#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK LoadListImageButtonWndProc(HWND hLoadListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	TCHAR ListIni[MAX_PATH];
	TCHAR IniListLoadBuffer[MAX_PATH] = TEXT("");
	char IniCastIndexBuffer[MAX_PATH] = "";
	TCHAR IniIndexBuffer[MAX_PATH] = TEXT("");
	int IniLoadLoop = 0;

	switch(iMessage)
	{
	case WM_PAINT:
		hDC = BeginPaint(hLoadListImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PlayListLoadlist.bmp"));
		EndPaint(hLoadListImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		GetCurrentDirectory(MAX_PATH, IniPath);
		_stprintf_s(ListIni, TEXT("%s\\MCIPlayList.ini"), IniPath);
		_itoa_s(IniLoadLoop, IniCastIndexBuffer, MAX_PATH, 10);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, IniCastIndexBuffer, strlen(IniCastIndexBuffer), IniIndexBuffer, MAX_PATH);
		for(IniLoadLoop = 0; 0 != GetPrivateProfileString(TEXT("PlayList"), IniIndexBuffer, TEXT(""), IniListLoadBuffer, MAX_PATH, ListIni); IniLoadLoop++)
		{
			_itoa_s(IniLoadLoop, IniCastIndexBuffer, MAX_PATH, 10);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, IniCastIndexBuffer, strlen(IniCastIndexBuffer), IniIndexBuffer, MAX_PATH);
			GetPrivateProfileString(TEXT("PlayList"), IniIndexBuffer, TEXT(""), IniListLoadBuffer, MAX_PATH, ListIni);
			SendMessage(hPlayListBoxWnd, LB_ADDSTRING, IniLoadLoop, (LPARAM)IniListLoadBuffer);
		}
		MessageBox(hLoadListImageButtonWnd, TEXT("MCIPlayList.ini�� ���� ����Ʈ�� �ҷ��Խ��ϴ�."), TEXT("�ҷ����� �Ϸ�"), MB_OK);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hLoadListImageButtonWnd, iMessage, wParam, lParam));
}