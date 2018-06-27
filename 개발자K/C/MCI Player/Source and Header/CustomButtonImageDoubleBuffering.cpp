#include "Headers\HeaderCollect.h"

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