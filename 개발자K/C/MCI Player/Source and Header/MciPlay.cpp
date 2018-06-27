#include "Headers\HeaderCollect.h"

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