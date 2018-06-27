#include "Headers\HeaderCollect.h"

void WndLayerTransparentOnOff(BOOL GlassOnOff, HWND hWnd)
{
	if(GlassOnOff == FALSE)
		SetLayeredWindowAttributes(hWnd, 0, 255, LWA_ALPHA);
	else if(GlassOnOff == TRUE)
		SetLayeredWindowAttributes(hWnd, 0, 50, LWA_ALPHA);
}