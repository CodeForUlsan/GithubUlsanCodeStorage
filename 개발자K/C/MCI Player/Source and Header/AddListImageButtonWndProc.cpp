#include "Headers\HeaderCollect.h"

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