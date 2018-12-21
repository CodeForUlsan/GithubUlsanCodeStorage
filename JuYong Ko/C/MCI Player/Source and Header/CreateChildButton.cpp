#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

HWND CreateChildButton(TCHAR *WindowCaption, RECT *WinClientRectangle, int ButtonPositionX, int ButtonPositionY,
					   int ButtonWidth, int ButtonHeight, HWND *hWnd, HMENU ButtonWindowID)//버튼 생성 함수
{
	HWND ButtonWnd;//버튼으로 생성될 차일드 윈도우의 핸들값

	ButtonWnd = CreateWindow(TEXT("BUTTON"), WindowCaption, WS_CHILD|WS_VISIBLE|WS_BORDER|BS_PUSHBUTTON,
		(WinClientRectangle->right/2)+ButtonPositionX, (WinClientRectangle->bottom/2)+ButtonPositionY,
		ButtonWidth, ButtonHeight, *hWnd, ButtonWindowID, g_hInstance, NULL);
	return ButtonWnd;//핸들값을 리턴하여 받는 핸들인수가 실제 핸들을 가지게 된다.
}