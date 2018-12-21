#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

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