#include "Headers\HeaderCollect.h"

int MciGetVolume(UINT *MciDeviceID)
{
	MCI_STATUS_PARMS MciStatusParms;
	
	MciStatusParms.dwCallback = 0;
	MciStatusParms.dwItem = MCI_DGV_STATUS_VOLUME;
	
	mciSendCommand(*MciDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)(LPVOID)&MciStatusParms);

	return (int)(MciStatusParms.dwReturn/10);
}