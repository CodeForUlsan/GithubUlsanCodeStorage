#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

DWORD MciGetPlayPosition(DWORD *TotalTime, UINT *MciDeviceID)
{
	MCI_SET_PARMS MciSetParms;
	MCI_STATUS_PARMS MciStatusParms;
//	DWORD *TotalTime;
	DWORD CurrentTime;

	MciSetParms.dwTimeFormat = MCI_FORMAT_MILLISECONDS;
	mciSendCommand(*MciDeviceID, MCI_SET, MCI_SET_TIME_FORMAT, (DWORD)&MciSetParms);

	MciStatusParms.dwItem = MCI_STATUS_LENGTH;
	mciSendCommand(*MciDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)(LPVOID)&MciStatusParms);
	*TotalTime = MciStatusParms.dwReturn;

	MciStatusParms.dwItem = MCI_STATUS_POSITION;
	mciSendCommand(*MciDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)(LPVOID)&MciStatusParms);
	CurrentTime = MciStatusParms.dwReturn;

	return CurrentTime;
}