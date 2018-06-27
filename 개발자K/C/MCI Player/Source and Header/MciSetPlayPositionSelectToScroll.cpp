#include "Headers\HeaderCollect.h"

void MciSetPlayPositionSelectToScroll(UINT *MciDeviceID, DWORD *PlayCurrentTimeValue)
{
	MCI_SEEK_PARMS MciSeekParms;

	MciSeekParms.dwTo = *PlayCurrentTimeValue;
	mciSendCommand(*MciDeviceID, MCI_SEEK, MCI_TO, (DWORD)(LPVOID)&MciSeekParms);	
}