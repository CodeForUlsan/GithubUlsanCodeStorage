#include "Headers\HeaderCollect.h"

void MciSetVolume(DWORD *VolumeValue, UINT *MciDeviceID)
{
	MCI_DGV_SETAUDIO_PARMS MciDgvSetaudioParms;

	if(*VolumeValue > 100)//넘겨받은 볼륨값이 100보다 클경우...
		*VolumeValue = 100;//100을 넘지 않게 100으로 맞추어준다.
	if(*VolumeValue < 0)//넘겨받은 볼륨값이 0보다 작을 경우...
		*VolumeValue = 0;//-1이하가 되지 않도록 0으로 맞추어준다.

	*VolumeValue *= 10; //넘겨받는 수치는 0 ~ 100사이의 값이 넘어오지만, 볼륨의 크기가 0 ~ 1000 까지이므로 10을 곱하여준다. ex)VolumeValue = 50; 50 * 10 = 500;

	MciDgvSetaudioParms.dwCallback = 0;
	MciDgvSetaudioParms.dwItem = MCI_DGV_SETAUDIO_VOLUME;
	MciDgvSetaudioParms.dwValue = *VolumeValue;
	MciDgvSetaudioParms.dwOver = 0;
	MciDgvSetaudioParms.lpstrAlgorithm = NULL;
	MciDgvSetaudioParms.lpstrQuality = NULL;

	mciSendCommand(*MciDeviceID, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE|MCI_DGV_SETAUDIO_ITEM, (DWORD)(LPVOID)&MciDgvSetaudioParms);
}