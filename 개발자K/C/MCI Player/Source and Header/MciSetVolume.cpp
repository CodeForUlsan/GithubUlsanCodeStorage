#include "Headers\HeaderCollect.h"

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