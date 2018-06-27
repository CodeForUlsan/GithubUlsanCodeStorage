#include "Headers\HeaderCollect.h"

void WrapperMusicFilePlayFunction(HWND hWnd, TCHAR *Global_lpstrFile, DWORD *MciErrorResult)
{
	EnableWindow(hPlayPositionScrollWnd, true);
	*MciErrorResult = MciOpen(Global_lpstrFile, &MciDeviceID);//������θ� ���� ���������� ��ġ�� mci��ġ�� �����Ͽ� ���� �غ� �Ѵ�.
	*MciErrorResult = MciPlay(hWnd, &MciDeviceID);//���� ���µ� ��ġ�� ���Ͽ� ���ָ� �����Ѵ�.
	SetTimer(hWnd, PLAYPOSITIONSTATICTIMER, 500, NULL);//���ֵǴ� ������ ���� �ð�/�� �ð��� ����ƽ �����쿡 �ѷ��� Ÿ�̸Ӹ� ��Ʈ�Ѵ�.
	SendMessage(hWnd, WM_TIMER, PLAYPOSITIONSTATICTIMER, 0);//��Ʈ�� Ÿ�̸Ӹ� ȣ���Ѵ�
	SetScrollRange(hPlayPositionScrollWnd, SB_CTL, 0, PlayTotalTimeValue/1000, TRUE);//Ÿ�̸Ӱ� ȣ��ȵڿ� ���������� �ѽð��� �ٽ� PlayPositionScrollBar�� �ִ� ������ ������Ų��.
	VolumeValue = (DWORD)VolumeScrollValue;//��ϵǾ��ִ� �������� ���� �������� ������Ű������ ĳ�������ش�.
	MciSetVolume(&VolumeValue, &MciDeviceID);//�ش������� �������� ��ϵǾ��� ���������� ������Ų��.
	StateChangeToPlayOrPause(&PlayorPause);
}