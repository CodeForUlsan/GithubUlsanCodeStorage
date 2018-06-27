#ifndef _HEADERCOLLECT_H_
#define _HEADERCOLLECT_H_
#include <Windows.h>
#include <Mmsystem.h>
#include <Digitalv.h>
#include <tchar.h>
#pragma comment(lib, "Winmm.lib")//�߰����� �������� winmm.lib ������ �о��.

//���� ����
#include "resource.h"
#include "VariableCollect.h"

//Functions ����
#include "Functions\FileHandlingFunctions.h"
#include "Functions\GraphicFunctions.h"
#include "Functions\MCIFunctions.h"
#include "Functions\MCIPlayRelatedFunctions.h"
#include "Functions\MenuRelatedFunctions.h"
#include "Functions\ShellRelatedFunctions.h"
#include "Functions\TemporaryFunctions.h"
#include "Functions\WrapperFunctions.h"

//WndProcs ����
#include "WndProcs\CopyrightWndProcs.h"
#include "WndProcs\MainWndProcs.h"
#include "WndProcs\PlayListWndProcs.h"
#endif