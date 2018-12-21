#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK CopyrightWndProc(HWND hCopyrightWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	RECT CopyrightWndClientRect;
	LPCTSTR VerNameUrl = TEXT("Banana.20140607\nhttp://blog.naver.com/kojy258\n");
	HWND hCopyrightStaticWnd;
	HDC hDC;
	PAINTSTRUCT PaintStruct;

	switch(iMessage)
	{
	case WM_CREATE:
		GetClientRect(hCopyrightWnd, &CopyrightWndClientRect);
		hMakerLogoImageWnd = CreateWindow(lpszMakerLogoImageClassName, TEXT("Maker Logo Image"),
			WS_CHILD|WS_VISIBLE,
			30, 50, 400, 240,
			hCopyrightWnd, (HMENU)-1, g_hInstance, NULL);
		hProgramLogoImageWnd = CreateWindow(lpszProgramLogoImageClassName, TEXT("Program Logo Image"),
			WS_CHILD|WS_VISIBLE,
			30, 290, 128, 128,
			hCopyrightWnd, (HMENU)-1, g_hInstance, NULL);
		hCloseCopyrightImageButtonWnd = CreateWindow(lpszCloseCopyrightImageButtonClassName, TEXT("Copyright Close Button"),
			WS_CHILD|WS_VISIBLE,
			CopyrightWndClientRect.right-50, 15, 40, 30,
			hCopyrightWnd, (HMENU)NULL, g_hInstance, NULL);
		hCopyrightStaticWnd = CreateWindow(TEXT("Static"), VerNameUrl,
			WS_CHILD|WS_VISIBLE,
			30, 430, 190, 40,
			hCopyrightWnd, (HMENU)-1, g_hInstance, NULL);
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hCopyrightWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\CopyrightSkin.bmp"));
		EndPaint(hCopyrightWnd, &PaintStruct);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hCopyrightWnd, iMessage, wParam, lParam));
}