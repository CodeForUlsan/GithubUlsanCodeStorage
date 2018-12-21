#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
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