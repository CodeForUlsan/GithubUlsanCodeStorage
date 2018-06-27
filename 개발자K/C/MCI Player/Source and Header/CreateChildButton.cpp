#include "Headers\HeaderCollect.h"

HWND CreateChildButton(TCHAR *WindowCaption, RECT *WinClientRectangle, int ButtonPositionX, int ButtonPositionY,
					   int ButtonWidth, int ButtonHeight, HWND *hWnd, HMENU ButtonWindowID)//버튼 생성 함수
{
	HWND ButtonWnd;//버튼으로 생성될 차일드 윈도우의 핸들값

	ButtonWnd = CreateWindow(TEXT("BUTTON"), WindowCaption, WS_CHILD|WS_VISIBLE|WS_BORDER|BS_PUSHBUTTON,
		(WinClientRectangle->right/2)+ButtonPositionX, (WinClientRectangle->bottom/2)+ButtonPositionY,
		ButtonWidth, ButtonHeight, *hWnd, ButtonWindowID, g_hInstance, NULL);
	return ButtonWnd;//핸들값을 리턴하여 받는 핸들인수가 실제 핸들을 가지게 된다.
}