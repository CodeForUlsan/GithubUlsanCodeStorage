#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

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