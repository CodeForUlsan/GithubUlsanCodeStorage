#include "Headers\HeaderCollect.h"

DWORD MciOpen(TCHAR *MusicFileName, UINT *MciDeviceID)//Mci��ġ ������ ó���ϴ� �Լ�
{
	DWORD MciErrorResult;//��ġ���¿� ������ ��� ��ȯ�Ǵ� �����޼����� ��ġ�� ���� ����
	MCI_OPEN_PARMS MciOpenParms;//��ġ ���� ������ ���� ����ü

	if(MciDeviceID)//���࿡ ����̽� �������� 0���� �ʱ�ȭ �Ǿ����� ���� ���...
		mciSendCommand(*MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//������ ��ġ�� �ݴ´�
	
	MciOpenParms.lpstrElementName = MusicFileName;//�Ѱܹ޴� ���ϸ��� ����ü�� �Ѱ��ش�.
	MciErrorResult = mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&MciOpenParms);//�Ѱܹ��� ���ϸ����� ��ġ�� �����Ͽ� ����� �غ� �Ѵ�
	if(MciErrorResult)//���࿡ ��ġ ���½ÿ� �����޼����� ��ȯ�Ǿ��ٸ�...
		mciSendCommand(*MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//������ ��ġ�� �ݴ´�

	*MciDeviceID = MciOpenParms.wDeviceID;//��ġ ������ ���� �Ұ�� �ش� ����̽����� �Ѱܹ޴´�.

	return MciErrorResult;//���� �޼������� ��ȯ�Ѵ�
}