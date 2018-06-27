#include "Headers\HeaderCollect.h"

void SetScrollValueUseMaxFunction(bool TrueIsPlayFalseIsVolume, int *SetIntValue, int MaxScrollValue, DWORD *SetDwordValue)
{//Max함수를 사용했을 경우의 스크롤값 설정함수
	if(TrueIsPlayFalseIsVolume==true)//true일 경우 Play스크롤바의 값을 설정
	{
		*SetIntValue = max(0, *SetIntValue+MaxScrollValue);
		*SetDwordValue = (DWORD)((*SetIntValue)*1000);
	}
	else//false의 경우 볼륨스크롤바의 값을 설정
	{
		*SetIntValue = max(0, *SetIntValue+MaxScrollValue);
		*SetDwordValue = (DWORD)(*SetIntValue);
	}
}