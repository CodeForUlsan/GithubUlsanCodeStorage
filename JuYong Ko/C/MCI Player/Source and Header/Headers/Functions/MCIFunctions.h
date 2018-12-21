#ifndef _MCIFUNCTIONS_H_
#define _MCIFUNCTIONS_H_
void MciClose(UINT *MciDeviceID);
DWORD MciGetPlayPosition(DWORD *TotalTime, UINT *MciDeviceID);
int MciGetVolume(UINT *MciDeviceID);
DWORD MciOpen(TCHAR *MusicFileName, UINT *MciDeviceID);
DWORD MciPlay(HWND hWnd, UINT *MciDeviceID);
void SetScrollValueUseMaxFunction(bool TrueIsPlayFalseIsVolume, int *SetIntValue, int MaxScrollValue, DWORD *SetDwordValue);
void SetScrollValueUseMinFunction(bool TrueIsPlayFalseIsVolume, int *SetIntValue, int MinScrollValue, DWORD MinTotalScrollValue, DWORD *SetDwordValue);
void MciSetPlayPositionSelectToScroll(UINT *MciDeviceID, DWORD *PlayCurrentTimeValue);
void MciSetVolume(DWORD *VolumeValue, UINT *MciDeviceID);
#endif