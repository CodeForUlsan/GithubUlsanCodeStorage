#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

void MciSetVolume(DWORD *VolumeValue, UINT *MciDeviceID)
{
	MCI_DGV_SETAUDIO_PARMS MciDgvSetaudioParms;

	if(*VolumeValue > 100)//�Ѱܹ��� �������� 100���� Ŭ���...
		*VolumeValue = 100;//100�� ���� �ʰ� 100���� ���߾��ش�.
	if(*VolumeValue < 0)//�Ѱܹ��� �������� 0���� ���� ���...
		*VolumeValue = 0;//-1���ϰ� ���� �ʵ��� 0���� ���߾��ش�.

	*VolumeValue *= 10; //�Ѱܹ޴� ��ġ�� 0 ~ 100������ ���� �Ѿ������, ������ ũ�Ⱑ 0 ~ 1000 �����̹Ƿ� 10�� ���Ͽ��ش�. ex)VolumeValue = 50; 50 * 10 = 500;

	MciDgvSetaudioParms.dwCallback = 0;
	MciDgvSetaudioParms.dwItem = MCI_DGV_SETAUDIO_VOLUME;
	MciDgvSetaudioParms.dwValue = *VolumeValue;
	MciDgvSetaudioParms.dwOver = 0;
	MciDgvSetaudioParms.lpstrAlgorithm = NULL;
	MciDgvSetaudioParms.lpstrQuality = NULL;

	mciSendCommand(*MciDeviceID, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE|MCI_DGV_SETAUDIO_ITEM, (DWORD)(LPVOID)&MciDgvSetaudioParms);
}