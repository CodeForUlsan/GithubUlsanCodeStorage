#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

void MciSetPlayPositionSelectToScroll(UINT *MciDeviceID, DWORD *PlayCurrentTimeValue)
{
	MCI_SEEK_PARMS MciSeekParms;

	MciSeekParms.dwTo = *PlayCurrentTimeValue;
	mciSendCommand(*MciDeviceID, MCI_SEEK, MCI_TO, (DWORD)(LPVOID)&MciSeekParms);	
}