#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

void SetScrollValueUseMinFunction(bool TrueIsPlayFalseIsVolume, int *SetIntValue, int MinScrollValue, DWORD MinTotalScrollValue, DWORD *SetDwordValue)
{//Min�Լ��� ������� ����� ��ũ�Ѱ� �����Լ�
	if(TrueIsPlayFalseIsVolume==true)//true�� ��� Play��ũ�ѹ��� ���� ����
	{
		*SetIntValue = min((int)MinTotalScrollValue/1000, *SetIntValue+MinScrollValue);
		*SetDwordValue = (DWORD)((*SetIntValue)*1000);
	}
	else//false�� ��� ������ũ�ѹ��� ���� ����
	{
		*SetIntValue = min((int)MinTotalScrollValue, *SetIntValue+MinScrollValue);
		*SetDwordValue = (DWORD)(*SetIntValue);
	}
}