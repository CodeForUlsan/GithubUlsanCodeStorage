#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

void CustomButtonImageDoubleBuffering(HDC MainDC, LPCTSTR BitmapFileName)
{
	HDC MemoryDC;
	HBITMAP MainBitmap;
	HBITMAP OldBitmap;
	BITMAP BitmapSize;
	int BitmapSizeWidth;
	int BitmapSizeHeight;

	MemoryDC = CreateCompatibleDC(MainDC);
	MainBitmap = (HBITMAP)LoadImage(NULL, BitmapFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	OldBitmap = (HBITMAP)SelectObject(MemoryDC, MainBitmap);

	GetObject(MainBitmap, sizeof(BITMAP), &BitmapSize);
	BitmapSizeWidth = BitmapSize.bmWidth;
	BitmapSizeHeight = BitmapSize.bmHeight;

	BitBlt(MainDC, 0, 0, BitmapSizeWidth, BitmapSizeHeight, MemoryDC, 0, 0, SRCCOPY);
	SelectObject(MemoryDC, OldBitmap);
	DeleteDC(MemoryDC);
	DeleteObject(MainBitmap);
}