#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

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