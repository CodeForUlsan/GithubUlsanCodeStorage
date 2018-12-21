#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK MakerLogoImageWndProc(HWND hMakerLogoImageWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT PaintStruct;

	switch(iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hMakerLogoImageWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hdc, TEXT("Images\\BlueLemonLogo.bmp"));
		EndPaint(hMakerLogoImageWnd, &PaintStruct);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hMakerLogoImageWnd, iMessage, wParam, lParam));
}