#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

void SetScrollValueUseMaxFunction(bool TrueIsPlayFalseIsVolume, int *SetIntValue, int MaxScrollValue, DWORD *SetDwordValue)
{//Max�Լ��� ������� ����� ��ũ�Ѱ� �����Լ�
	if(TrueIsPlayFalseIsVolume==true)//true�� ��� Play��ũ�ѹ��� ���� ����
	{
		*SetIntValue = max(0, *SetIntValue+MaxScrollValue);
		*SetDwordValue = (DWORD)((*SetIntValue)*1000);
	}
	else//false�� ��� ������ũ�ѹ��� ���� ����
	{
		*SetIntValue = max(0, *SetIntValue+MaxScrollValue);
		*SetDwordValue = (DWORD)(*SetIntValue);
	}
}