#include "Headers\HeaderCollect.h"

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