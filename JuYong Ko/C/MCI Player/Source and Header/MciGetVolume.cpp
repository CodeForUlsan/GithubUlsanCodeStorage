#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

int MciGetVolume(UINT *MciDeviceID)
{
	MCI_STATUS_PARMS MciStatusParms;
	
	MciStatusParms.dwCallback = 0;
	MciStatusParms.dwItem = MCI_DGV_STATUS_VOLUME;
	
	mciSendCommand(*MciDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)(LPVOID)&MciStatusParms);

	return (int)(MciStatusParms.dwReturn/10);
}