#include "Headers\HeaderCollect.h"

void WrapperMusicFilePlayFunction(HWND hWnd, TCHAR *Global_lpstrFile, DWORD *MciErrorResult)
{
	EnableWindow(hPlayPositionScrollWnd, true);
	*MciErrorResult = MciOpen(Global_lpstrFile, &MciDeviceID);//완전경로를 받은 파일을통해 장치를 mci장치를 오픈하여 연주 준비를 한다.
	*MciErrorResult = MciPlay(hWnd, &MciDeviceID);//위에 오픈된 장치를 통하여 연주를 시작한다.
	SetTimer(hWnd, PLAYPOSITIONSTATICTIMER, 500, NULL);//연주되는 파일의 현재 시간/총 시간을 스태틱 윈도우에 뿌려줄 타이머를 셋트한다.
	SendMessage(hWnd, WM_TIMER, PLAYPOSITIONSTATICTIMER, 0);//셋트된 타이머를 호출한다
	SetScrollRange(hPlayPositionScrollWnd, SB_CTL, 0, PlayTotalTimeValue/1000, TRUE);//타이머가 호출된뒤에 연주파일의 총시간을 다시 PlayPositionScrollBar에 최대 범위로 지정시킨다.
	VolumeValue = (DWORD)VolumeScrollValue;//기록되어있는 볼륨값을 현재 볼륨으로 설정시키기위해 캐스팅해준다.
	MciSetVolume(&VolumeValue, &MciDeviceID);//해당파일의 볼륨값을 기록되어진 볼륨값으로 설정시킨다.
	StateChangeToPlayOrPause(&PlayorPause);
}