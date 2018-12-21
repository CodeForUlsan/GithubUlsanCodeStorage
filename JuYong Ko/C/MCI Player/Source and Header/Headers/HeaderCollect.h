#ifndef _HEADERCOLLECT_H_
#define _HEADERCOLLECT_H_
#include <Windows.h>
#include <Mmsystem.h>
#include <Digitalv.h>
#include <tchar.h>
#pragma comment(lib, "Winmm.lib")//추가적인 설정없이 winmm.lib 파일을 읽어옴.

//필터 없음
#include "resource.h"
#include "VariableCollect.h"

//Functions 필터
#include "Functions\FileHandlingFunctions.h"
#include "Functions\GraphicFunctions.h"
#include "Functions\MCIFunctions.h"
#include "Functions\MCIPlayRelatedFunctions.h"
#include "Functions\MenuRelatedFunctions.h"
#include "Functions\ShellRelatedFunctions.h"
#include "Functions\TemporaryFunctions.h"
#include "Functions\WrapperFunctions.h"

//WndProcs 필터
#include "WndProcs\CopyrightWndProcs.h"
#include "WndProcs\MainWndProcs.h"
#include "WndProcs\PlayListWndProcs.h"
#endif