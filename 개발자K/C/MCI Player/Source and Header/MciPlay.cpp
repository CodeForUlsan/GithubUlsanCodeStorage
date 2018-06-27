#include "Headers\HeaderCollect.h"

DWORD MciPlay(HWND hWnd, UINT *MciDeviceID)//MciOpen �Լ����� ��ġ�� ���������� ���µǾ��ٸ� �� �Լ��� ���� �ش������� �����Ų��.
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