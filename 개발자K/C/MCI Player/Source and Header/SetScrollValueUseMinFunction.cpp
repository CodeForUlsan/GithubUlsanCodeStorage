#include "Headers\HeaderCollect.h"

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