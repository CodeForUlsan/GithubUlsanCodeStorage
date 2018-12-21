#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK AddListImageButtonWndProc(HWND hAddListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PaintStruct;
	OPENFILENAME OpenListFileNameDialog;
	TCHAR lpstrFile[MAX_PATH] = TEXT("");
	TCHAR lpstrFileTitle[MAX_PATH] = TEXT("");

	switch(iMessage)
	{
	case WM_PAINT:
		hDC = BeginPaint(hAddListImageButtonWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\PlayListAddlist.bmp"));
		EndPaint(hAddListImageButtonWnd, &PaintStruct);
		return 0;
	case WM_LBUTTONUP:
		memset(&OpenListFileNameDialog, 0, sizeof(OPENFILENAME));
		OpenFileNameDialogCall(hPlayListWnd, &OpenListFileNameDialog, lpstrFile, lpstrFileTitle);
		if(GetOpenFileName(&OpenListFileNameDialog) != 0)
			SendMessage(hPlayListBoxWnd, LB_ADDSTRING, 0, (LPARAM)lpstrFileTitle);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hAddListImageButtonWnd, iMessage, wParam, lParam));
}