#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

DWORD MciPlay(HWND hWnd, UINT *MciDeviceID)//MciOpen 함수에서 장치가 정상적으로 오픈되었다면 이 함수를 통해 해당파일을 재생시킨다.
{
	DWORD MciErrorResult;
	MCI_PLAY_PARMS MciPlayParms;

	if(MciDeviceID == 0)
	{
		MciErrorResult = mciSendCommand(*MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);
		return MciErrorResult;
	}

	MciPlayParms.dwCallback = (DWORD)hWnd;
	MciErrorResult = mciSendCommand(*MciDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&MciPlayParms);
	if(MciErrorResult)
		mciSendCommand(*MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);

	return MciErrorResult;
}