#include "Headers\HeaderCollect.h"

void PlayTimePrintStatic(LPWSTR MciPlayTimeString)
{
	wsprintf(MciPlayTimeString, TEXT(" %02ld : %02ld / %02ld : %02ld"),
		(PlayCurrentTimeValue/60000), (PlayCurrentTimeValue%60000)/1000,
		(PlayTotalTimeValue/60000), (PlayTotalTimeValue%60000)/1000);
}