#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

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