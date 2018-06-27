#include "Headers\HeaderCollect.h"

void MciClose(UINT *MciDeviceID)
{
	mciSendCommand(*MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);
}