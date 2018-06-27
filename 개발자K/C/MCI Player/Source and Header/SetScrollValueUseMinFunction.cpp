#include "Headers\HeaderCollect.h"

void SetScrollValueUseMinFunction(bool TrueIsPlayFalseIsVolume, int *SetIntValue, int MinScrollValue, DWORD MinTotalScrollValue, DWORD *SetDwordValue)
{//Min함수를 사용했을 경우의 스크롤값 설정함수
	if(TrueIsPlayFalseIsVolume==true)//true일 경우 Play스크롤바의 값을 설정
	{
		*SetIntValue = min((int)MinTotalScrollValue/1000, *SetIntValue+MinScrollValue);
		*SetDwordValue = (DWORD)((*SetIntValue)*1000);
	}
	else//false의 경우 볼륨스크롤바의 값을 설정
	{
		*SetIntValue = min((int)MinTotalScrollValue, *SetIntValue+MinScrollValue);
		*SetDwordValue = (DWORD)(*SetIntValue);
	}
}