#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK MainWndProc(HWND hMainWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	RECT WinClientRectangle;//메인윈도우의 클라이언트 영역을 저장할 변수	
	HMENU hMenu=NULL, hPopup=NULL;
	OPENFILENAME OpenFileName;//파일열기 대화상자 구조체
	static TCHAR lpstrFile[MAX_PATH]=TEXT("");//사용자가 선택한 파일명 문자를 저장할 변수(완전경로)
	TCHAR StaticWndlpstrFile[MAX_PATH]=TEXT("");
	TCHAR lpstrFileTitle[MAX_PATH]=TEXT("");//사용자가 선택한 파일명 문자를 저장할 변수
	TCHAR MciErrorString[MAX_PATH]=TEXT("");//Mci장치 사용중 발생한 에러메세지를 저장할 문자열 변수
	TCHAR MciVolumeString[10]=TEXT("");//Mci장치의 볼륨을 문자로 변환하여 저장될 변수
	TCHAR MciPlayTimeString[20]=TEXT("");//Mci장치의 현재 재생시간 / 총 재생시간을 저장할 변수
	NOTIFYICONDATA NotifyIconData;//전역으로 변경
	POINT Point;
	DWORD MciErrorResult;//Mci장치 사용중 발생할 에러메세지의 코드를 저장할 DWORD형 변수(부호없는 정수형)
	HDROP hDropFile = (HDROP)wParam;
	int ControllWindowPositionY=50;
	int PlayPositionScrollLength=350;
	int VolumePositionScrollLength=80;
	int FileNameStaticLength=350;
	char lpstrFileChar[MAX_PATH]="";
	char lpstrFileTitleChar[MAX_PATH]="";
	char lpstrFileTitleFormatChar[MAX_PATH]="";
	int GetWheelDeltaWParamZ = GET_WHEEL_DELTA_WPARAM(wParam);
	UINT nHit;
	HDC hDC;
	PAINTSTRUCT PaintStruct;

	int VolumeValueBufferSize = 10;
	int IniOnOffStateSize = 10;

	TCHAR IniInitialize[MAX_PATH] = TEXT("");

	memset(&Point, 0, sizeof(POINT));

	switch(iMessage)
	{
	case WM_CREATE://윈도우가 화면에 그려지기전에 미리 실행되어질 메세지
		//AnimateWindow(hMainWnd, 1000, AW_SLIDE);
		ShowWindow(hMainWnd, SW_SHOW);
		GetClientRect(hMainWnd, &WinClientRectangle);//부모, 메인 윈도우의 클라이언트 영역을 구한다.
		DragAcceptFiles(hMainWnd, TRUE);//부모 윈도우가 드래그된 파일을 입력받을수 있도록 활성화 시킨다.
		
		SetWindowLong(hMainWnd, GWL_EXSTYLE, GetWindowLong(hMainWnd, GWL_EXSTYLE)|WS_EX_LAYERED);

		GetCurrentDirectory(MAX_PATH, IniPath);
		_stprintf_s(IniInitialize, TEXT("%s\\MCIPInitialize.ini"), IniPath);
		VolumeValue = GetPrivateProfileInt(TEXT("Initialize Set"), TEXT("VolumeValue"), 50, IniInitialize);
		VolumeScrollValue = GetPrivateProfileInt(TEXT("Initialize Set"), TEXT("VolumeScrollValue"), 50, IniInitialize);
		
		wsprintf(MciVolumeString, TEXT("%4ld %%"), VolumeValue);//VolumeValue를 TCHAR형으로 변환하여 MciVolumeString에 문자열로 변환하여 대입한다.
		PlayTimePrintStatic(MciPlayTimeString);

		hFileNameStaticWnd = CreateWindow(TEXT("STATIC"), NULL, WS_CHILD|WS_VISIBLE|WS_BORDER,
			(WinClientRectangle.right-FileNameStaticLength)/2, WinClientRectangle.bottom-ControllWindowPositionY*3,
			FileNameStaticLength, 20, hMainWnd, (HMENU)-1, g_hInstance, NULL);

		hPlayPositionScrollWnd = CreateWindow(TEXT("SCROLLBAR"), NULL, WS_CHILD|WS_VISIBLE|SBS_HORZ|WS_DISABLED,
			(WinClientRectangle.right-PlayPositionScrollLength)/2, WinClientRectangle.bottom-ControllWindowPositionY*2+15,
			PlayPositionScrollLength, 15, hMainWnd, (HMENU)PLAYPOSITIONSCROLLBAR, g_hInstance, NULL);
		SetScrollRange(hPlayPositionScrollWnd, SB_CTL, 0, PlayTotalTimeValue/1000, TRUE);
		SetScrollPos(hPlayPositionScrollWnd, SB_CTL, PlayScrollValue, TRUE);

		hVolumePositionScrollWnd = CreateWindow(TEXT("SCROLLBAR"), NULL, WS_CHILD|WS_VISIBLE|SBS_HORZ,
			(WinClientRectangle.right/2)+100, WinClientRectangle.bottom-ControllWindowPositionY+15,
			VolumePositionScrollLength, 10, hMainWnd, (HMENU)VOLUMEPOSITIONSCROLLBAR, g_hInstance, NULL);
		SetScrollRange(hVolumePositionScrollWnd, SB_CTL, 0, 100, TRUE);
		SetScrollPos(hVolumePositionScrollWnd, SB_CTL, VolumeScrollValue, TRUE);

		hPlayPositionStaticWnd = CreateWindow(TEXT("STATIC"), MciPlayTimeString, WS_CHILD|WS_VISIBLE|WS_BORDER,
			(WinClientRectangle.right-PlayPositionScrollLength)/2, (WinClientRectangle.bottom-ControllWindowPositionY*2)-20,
			110, 20, hMainWnd, (HMENU)-1, g_hInstance, NULL);

		hVolumePositionStaticWnd = CreateWindow(TEXT("STATIC"), MciVolumeString, WS_CHILD|WS_VISIBLE|WS_BORDER,
			(WinClientRectangle.right/2)+120, WinClientRectangle.bottom-ControllWindowPositionY-10,
			50, 20, hMainWnd, (HMENU)-1, g_hInstance, NULL);
		
		hPrevTrackSelectImageButtonWnd = CreateWindow(lpszPrevTrackSelectImageButtonWndClassName, TEXT("ImageButton"),
			WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right/2)-170, (WinClientRectangle.bottom/2)+40, 50, 30,
			hMainWnd, (HMENU)NULL, g_hInstance, NULL);

		hPlayOrPauseImageButtonWnd = CreateWindow(lpszPlayOrPauseImageButtonWndClassName, TEXT("ImageButton"), WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right/2)-110, (WinClientRectangle.bottom/2)+40, 50, 30,
			hMainWnd, (HMENU)PLAYORPAUSECHANGEBUTTON, g_hInstance, NULL);

		hStopImageButtonWnd = CreateWindow(lpszStopImageButtonWndClassName, TEXT("ImageButton"), WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right/2)-50, (WinClientRectangle.bottom/2)+40, 50, 30,
			hMainWnd, (HMENU)STOPBUTTON, g_hInstance, NULL);

		hNextTrackSelectImageButtonWnd = CreateWindow(lpszNextTrackSelectImageButtonWndClassName, TEXT("ImageButton"),
			WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right/2)+10, (WinClientRectangle.bottom/2)+40, 50, 30,
			hMainWnd, (HMENU)NULL, g_hInstance, NULL);

		hCloseWindowImageButtonWnd = CreateWindow(lpszCloseWindowImageButtonWndClassName, TEXT("SystemImageButton"),
			WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right-43), (WinClientRectangle.top+7), 40, 30,
			hMainWnd, (HMENU)-1, g_hInstance, NULL);

		hMinimizeWindowImageButtonWnd = CreateWindow(lpszMinimizeWindowImageButtonWndClassName, TEXT("SystemImageButton"),
			WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right-83), (WinClientRectangle.top+7), 40, 30,
			hMainWnd, (HMENU)-1, g_hInstance, NULL);

		hPlayListCallImageButtonWnd = CreateWindow(lpszPlayListCallImageButtonClassName, TEXT("PlayList CallButton"),
			WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right-163), (WinClientRectangle.top+7), 80, 30,
			hMainWnd, (HMENU)-1, g_hInstance, NULL);

		hRepeatImageButtonWnd = CreateWindow(lpszRepeatImageButtonClassName, TEXT("Repeat Button"),
			WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right/2)-50, (WinClientRectangle.bottom-ControllWindowPositionY*2)-20,
			72, 22, hMainWnd, (HMENU)NULL, g_hInstance, NULL);

		hGlassImageButtonWnd = CreateWindow(lpszGlassImageButtonClassName, TEXT("Glass Button"),
			WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right/2)+27, (WinClientRectangle.bottom-ControllWindowPositionY*2)-20,
			72, 22, hMainWnd, (HMENU)NULL, g_hInstance, NULL);

		hVersionImageButtonWnd = CreateWindow(lpszVersionImageButtonClassName, TEXT("Version Button"),
			WS_CHILD|WS_VISIBLE,
			(WinClientRectangle.right/2)+104, (WinClientRectangle.bottom-ControllWindowPositionY*2)-20,
			72, 22, hMainWnd, (HMENU)NULL, g_hInstance, NULL);

		hCopyrightWnd = CreateWindow(lpszCopyrightWndClassName, lpszCopyrightWndClassName,
			WS_POPUP,
			CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
			hMainWnd, (HMENU)NULL, g_hInstance, NULL);

		hPlayListWnd = CreateWindow(lpszPlayListWndClassName, lpszPlayListWndClassName,
			WS_POPUP,
			CW_USEDEFAULT, CW_USEDEFAULT, 400, 500,
			hMainWnd, (HMENU)NULL, g_hInstance, NULL);

		RepeatOnOff = (BOOL)GetPrivateProfileInt(TEXT("Initialize Set"), TEXT("Repeat"), 0, IniInitialize);
		if(RepeatOnOff == TRUE)
			InvalidateRect(hRepeatImageButtonWnd, NULL, true);
		GlassOnOff = (BOOL)GetPrivateProfileInt(TEXT("Initialize Set"), TEXT("Glass"), 0, IniInitialize);
		if(GlassOnOff == TRUE)
			SetTimer(hMainWnd, INITIALIZELAYERSETTIMER, 10, NULL);
		GetPrivateProfileString(TEXT("Initialize Set"), TEXT("LastPlayMediaPath"), TEXT(""), Global_lpstrFile, MAX_PATH, IniInitialize);

		WideCharToMultiByte(CP_ACP, 0, Global_lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//유니코드로 입력받은 파일의 전체 경로를 ANCI코드로 변환한다.
		_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//전달받은 전체 경로 문자를 잘게 나눈다.
		strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//전체 경로의 나누어진 부분중, 파일 포맷과 파일명을 합쳐준다.
		SetWindowText(hFileNameStaticWnd, lpstrFileTitle);//변환된 유니코드를 해당 윈도우 핸들을 가진 스태틱 윈도우에 표시한다.
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hMainWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\Skin.bmp"));
		EndPaint(hMainWnd, &PaintStruct);
		return 0;
	case WM_DROPFILES://드래그된 파일을 받았을때 처리할 메세지
		if(MciDeviceID != 0)//장치가 초기화되어있지 않다면...
			mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//장치를 닫는다.

		DragQueryFile(hDropFile, 0, lpstrFile, MAX_PATH);//드래그된 파일의 완전경로를 받아서 핸들을 연다.

		lstrcpy(Global_lpstrFile, lpstrFile);

		PlayorPause = false;
		InvalidateRect(hPlayOrPauseImageButtonWnd, NULL, TRUE);		

		WrapperMusicFilePlayFunction(hMainWnd, Global_lpstrFile, &MciErrorResult);//Wrapper 함수 호출

		WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//유니코드로 입력받은 파일의 전체 경로를 ANCI코드로 변환한다.
		_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//전달받은 전체 경로 문자를 잘게 나눈다.
		strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//전체 경로의 나누어진 부분중, 파일 포맷과 파일명을 합쳐준다.
		if(MciErrorResult)//만약 장치 오픈시나, 연주시작전에 mci 장치의 에러가 발생했다면...
		{
			mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//오픈된 MCI장치를 강제로 닫는다.
			StateChangeToPlayOrPause(&PlayorPause);
			wsprintf(MciPlayTimeString, TEXT(" %02ld : %02ld / %02ld : %02ld"),	0, 0, 0, 0);//재생된 파일의 현재시간, 전체시간을 전부 0으로 초기화한다.
			SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);//초기화된 시간을 스태틱윈도우에 표시하게 한다.
			MessageBox(hMainWnd, TEXT("파일 열기에 실패하였습니다."), TEXT("알림"), MB_OK);			
		}
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//변환된 파일명 + 파일포맷의 문자열을 다시 유니코드로 변환
		SetWindowText(hFileNameStaticWnd, lpstrFileTitle);//변환된 유니코드를 해당 윈도우 핸들을 가진 스태틱 윈도우에 표시한다.
		SendMessage(hPlayListBoxWnd, LB_RESETCONTENT, 0, 0);
		SendMessage(hPlayListBoxWnd, LB_ADDSTRING, 0, (LPARAM)lpstrFileTitle);
		DragFinish(hDropFile);//파일 드래그 입력을 종료하고 핸들을 닫아준다.
		SetForegroundWindow(hMainWnd);//파일을 입력받은 해당윈도우를 활성화한다.
		return 0;
	case TRAY://윈도우가 숨김상태가 되고 작업표시줄에 등록된 상태일때 처리할 메세지
		switch(lParam)
		{
		case WM_LBUTTONDOWN://윈도우가 숨김상태이고 작업표시줄에 등록되어있을때 마우스 왼쪽버튼을 눌렀을때 호출될 메세지
			NotifyIconDataCall(hMainWnd, &NotifyIconData, TRAY);//해당함수 호출
			Shell_NotifyIcon(NIM_DELETE, &NotifyIconData);//윈도우를 보이게 하기전 트레이에 등록된 아이콘 소멸 
			ShowWindow(hMainWnd, SW_SHOWNORMAL);//트레이 아이콘 소멸후 윈도우를 보여지게함
			SetForegroundWindow(hMainWnd);//윈도우의 순서를 맨앞으로 옴겨 활성화
			break;
		case WM_RBUTTONDOWN://윈도우가 숨김상태이고 작업표시줄에 등록되어있을때 마우스 오른쪽버튼을 눌렀을때 호출될 메세지
			FloatingPopupMenuCall(hMainWnd, hMenu, hPopup, Point);//플로팅팝업메뉴를 호출할 함수
			break;
		}
		return 0;
	case WM_SIZE://윈도우의 크기가 변경되었을시에 호출될 메세지
		switch(wParam)
		{
		case SIZE_MINIMIZED://윈도우 상단의 최소화버튼으로 윈도우가 숨김상태가 되었을때 호출될 메세지
			NotifyIconDataCall(hMainWnd, &NotifyIconData, TRAY);
			lstrcpy(NotifyIconData.szTip, lpszMainWndClassName);
			Shell_NotifyIcon(NIM_ADD, &NotifyIconData);
			ShowWindow(hMainWnd, SW_HIDE);
			break;
		}
		return 0;
	case WM_CONTEXTMENU:
		hMenu = LoadMenu(g_hInstance, MAKEINTRESOURCE(IDR_MENU1));
		hPopup = GetSubMenu(hMenu, 0);
		TrackPopupMenu(hPopup, TPM_LEFTALIGN, (short)LOWORD(lParam), (short)HIWORD(lParam), 0, hMainWnd, NULL);
		DestroyMenu(hMenu);
		return 0;
	case WM_HSCROLL://스크롤윈도우의 메세지가 발생했을때 호출될 메세지
		switch(LOWORD(wParam))
		{
		case SB_LINELEFT:
			if((HWND)lParam == hPlayPositionScrollWnd)
			{
				SetScrollValueUseMaxFunction(true, &PlayScrollValue, -1, &PlayCurrentTimeValue);
				MciSetPlayPositionSelectToScroll(&MciDeviceID, &PlayCurrentTimeValue);
				PlayorPause = false;
			}
			if((HWND)lParam == hVolumePositionScrollWnd)
			{
				SetScrollValueUseMaxFunction(false, &VolumeScrollValue, -1, &VolumeValue);
				MciSetVolume(&VolumeValue, &MciDeviceID);
				MciGetVolume(&MciDeviceID);
			}
			break;
		case SB_LINERIGHT:
			if((HWND)lParam == hPlayPositionScrollWnd)
			{
				SetScrollValueUseMinFunction(true, &PlayScrollValue, 1, PlayTotalTimeValue, &PlayCurrentTimeValue);
				MciSetPlayPositionSelectToScroll(&MciDeviceID, &PlayCurrentTimeValue);
				PlayorPause = false;
			}
			if((HWND)lParam == hVolumePositionScrollWnd)
			{
				SetScrollValueUseMinFunction(false, &VolumeScrollValue, 1, 100, &VolumeValue);
				MciSetVolume(&VolumeValue, &MciDeviceID);
				MciGetVolume(&MciDeviceID);
			}
			break;
		case SB_PAGELEFT:
			if((HWND)lParam == hPlayPositionScrollWnd)
			{
				SetScrollValueUseMaxFunction(true, &PlayScrollValue, -10, &PlayCurrentTimeValue);
				MciSetPlayPositionSelectToScroll(&MciDeviceID, &PlayCurrentTimeValue);
				PlayorPause = false;
			}
			if((HWND)lParam == hVolumePositionScrollWnd)
			{
				SetScrollValueUseMaxFunction(false, &VolumeScrollValue, -10, &VolumeValue);
				MciSetVolume(&VolumeValue, &MciDeviceID);
				MciGetVolume(&MciDeviceID);
			}
			break;
		case SB_PAGERIGHT:
			if((HWND)lParam == hPlayPositionScrollWnd)
			{
				SetScrollValueUseMinFunction(true, &PlayScrollValue, 10, PlayTotalTimeValue, &PlayCurrentTimeValue);
				MciSetPlayPositionSelectToScroll(&MciDeviceID, &PlayCurrentTimeValue);
				PlayorPause = false;
			}
			if((HWND)lParam == hVolumePositionScrollWnd)
			{
				SetScrollValueUseMinFunction(false, &VolumeScrollValue, 10, 100, &VolumeValue);
				MciSetVolume(&VolumeValue, &MciDeviceID);
				MciGetVolume(&MciDeviceID);
			}
			break;
		case SB_THUMBTRACK:
			if((HWND)lParam == hPlayPositionScrollWnd)
			{
				PlayScrollValue = HIWORD(wParam);
				PlayCurrentTimeValue = (DWORD)(PlayScrollValue*1000);
				MciSetPlayPositionSelectToScroll(&MciDeviceID, &PlayCurrentTimeValue);
				PlayorPause = false;
			}
			if((HWND)lParam == hVolumePositionScrollWnd)
			{
				VolumeScrollValue = HIWORD(wParam);
				VolumeValue = (DWORD)VolumeScrollValue;
				MciSetVolume(&VolumeValue, &MciDeviceID);
				MciGetVolume(&MciDeviceID);
			}
			break;
		case SB_THUMBPOSITION:
			if((HWND)lParam == hPlayPositionScrollWnd)
			{
				PlayScrollValue = HIWORD(wParam);
				PlayCurrentTimeValue = (DWORD)(PlayScrollValue*1000);
				MciSetPlayPositionSelectToScroll(&MciDeviceID, &PlayCurrentTimeValue);
				PlayorPause = false;
			}
			break;
		}
		if((HWND)lParam == hPlayPositionScrollWnd)
		{
			SetScrollPos((HWND)lParam, SB_CTL, PlayScrollValue, TRUE);
			PlayCurrentTimeValue = (DWORD)(PlayScrollValue*1000);
			if(PlayorPause == false)
				SendMessage(hMainWnd, WM_COMMAND, PLAYORPAUSECHANGEBUTTON, 0);
		}
		if((HWND)lParam == hVolumePositionScrollWnd)
		{
			SetScrollPos((HWND)lParam, SB_CTL, VolumeScrollValue, TRUE);
			VolumeValue = (DWORD)VolumeScrollValue;
			wsprintf(MciVolumeString, TEXT("%4ld %%"), VolumeValue);
			SetWindowText(hVolumePositionStaticWnd, MciVolumeString);
			MciSetVolume(&VolumeValue, &MciDeviceID);
			MciGetVolume(&MciDeviceID);
		}
		return 0;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDM_OPENFILE://파일 열기(플로팅 팝업 메뉴)
			memset(&OpenFileName, 0, sizeof(OPENFILENAME));
			OpenFileNameDialogCall(hMainWnd, &OpenFileName, lpstrFile, lpstrFileTitle);
			if(GetOpenFileName(&OpenFileName) != 0)
			{
				if(MciDeviceID != 0)
					mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);

				lstrcpy(Global_lpstrFile, lpstrFile);

				WrapperMusicFilePlayFunction(hMainWnd, Global_lpstrFile, &MciErrorResult);

				SetWindowText(hFileNameStaticWnd, lpstrFileTitle);

				SendMessage(hPlayListBoxWnd, LB_RESETCONTENT, 0, 0);
				SendMessage(hPlayListBoxWnd, LB_ADDSTRING, 0, (LPARAM)lpstrFileTitle);
			}
			break;
		case IDM_INFORMATION://프로그램 정보(플로팅 팝업 메뉴)
			SendMessage(hVersionImageButtonWnd, WM_LBUTTONUP, 0, 0);
			break;
		case IDM_EXIT://종료(플로팅 팝업 메뉴)
			DestroyWindow(hMainWnd);
			break;
		case PLAYORPAUSECHANGEBUTTON://재생아이콘의 버튼윈도우를 눌렀을때 호출될 메세지
			if(PlayorPause == false)//정지, 혹은 일시정지의 상태라면...
			{
				if((MciDeviceID == 0) && (lstrcmp(Global_lpstrFile, TEXT("")) == 0))//파일 완전 경로 버퍼가 비었고 장치 디바이스가 0일시에만 해당
				{
					memset(&OpenFileName, 0, sizeof(OPENFILENAME));
					OpenFileNameDialogCall(hMainWnd, &OpenFileName, lpstrFile, lpstrFileTitle);
					if(GetOpenFileName(&OpenFileName) != 0)
					{
						if(MciDeviceID != 0)
							mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);
					
						if(lstrcmp(lpstrFile, TEXT("")) == 0)
							lstrcpy(lpstrFile, Global_lpstrFile);
						else if(lstrcmp(Global_lpstrFile, TEXT("")) == 0)
							lstrcpy(Global_lpstrFile, lpstrFile);

						WrapperMusicFilePlayFunction(hMainWnd, Global_lpstrFile, &MciErrorResult);

						WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//유니코드로 입력받은 파일의 전체 경로를 ANCI코드로 변환한다.
						_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//전달받은 전체 경로 문자를 잘게 나눈다.
						strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//전체 경로의 나누어진 부분중, 파일 포맷과 파일명을 합쳐준다.
						MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//변환된 파일명 + 파일포맷의 문자열을 다시 유니코드로 변환

						SetWindowText(hFileNameStaticWnd, lpstrFileTitle);

						SendMessage(hPlayListBoxWnd, LB_RESETCONTENT, 0, 0);
						SendMessage(hPlayListBoxWnd, LB_ADDSTRING, 0, (LPARAM)lpstrFileTitle);
					}
				}

				else if(lstrcmp(lpstrFile, TEXT("")) != 0)//스크롤바에서 구간 선택후 재생기능 호출시, MIC_PAUSE 이후 재생기능 호출시에 처리, 반복재생 기능으로 재생기능호출시 처리
				{
					MciErrorResult = MciPlay(hMainWnd, &MciDeviceID);
					SetTimer(hMainWnd, PLAYPOSITIONSTATICTIMER, 500, NULL);
					SendMessage(hMainWnd, WM_TIMER, PLAYPOSITIONSTATICTIMER, 0);
					StateChangeToPlayOrPause(&PlayorPause);
					VolumeValue = (DWORD)VolumeScrollValue;//기록되어있는 볼륨값을 현재 볼륨으로 설정시키기위해 캐스팅해준다.
					MciSetVolume(&VolumeValue, &MciDeviceID);//해당파일의 볼륨값을 기록되어진 볼륨값으로 설정시킨다.

					WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//유니코드로 입력받은 파일의 전체 경로를 ANCI코드로 변환한다.
					_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//전달받은 전체 경로 문자를 잘게 나눈다.
					strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//전체 경로의 나누어진 부분중, 파일 포맷과 파일명을 합쳐준다.
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//변환된 파일명 + 파일포맷의 문자열을 다시 유니코드로 변환

					SetWindowText(hFileNameStaticWnd, lpstrFileTitle);

					if(MciErrorResult)//파일 열기 대화상자에서 파일을 제대로 읽어오지 못했을 경우 예외처리(사용자가 취소를 눌렀을 경우 등...)
					{
						mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//오픈된 MCI장치를 강제로 닫는다.
						StateChangeToPlayOrPause(&PlayorPause);
						wsprintf(MciPlayTimeString, TEXT(" %02ld : %02ld / %02ld : %02ld"),	0, 0, 0, 0);//재생된 파일의 현재시간, 전체시간을 전부 0으로 초기화한다.
						SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);//초기화된 시간을 스태틱윈도우에 표시하게 한다.
					}
				}

				else if(lstrcmp(Global_lpstrFile, TEXT("")) != 0)//프로그램 처음 구동시 MCI 장치가 오픈되어있지 않고, 지역파일완전경로 버퍼가 비어있을때 호출(파일리스트 윈도우로부터 재생기능 호출시)
				{
					GetWindowText(hFileNameStaticWnd, StaticWndlpstrFile, MAX_PATH);
					
					lstrcpy(lpstrFile, Global_lpstrFile);

					WrapperMusicFilePlayFunction(hMainWnd, Global_lpstrFile, &MciErrorResult);

					WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//유니코드로 입력받은 파일의 전체 경로를 ANCI코드로 변환한다.
					_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//전달받은 전체 경로 문자를 잘게 나눈다.
					strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//전체 경로의 나누어진 부분중, 파일 포맷과 파일명을 합쳐준다.
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//변환된 파일명 + 파일포맷의 문자열을 다시 유니코드로 변환

					SetWindowText(hFileNameStaticWnd, lpstrFileTitle);
				}

				if(MciErrorResult)//만약 장치 오픈시나, 연주시작전에 mci 장치의 에러가 발생했다면...
				{
					mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//오픈된 MCI장치를 강제로 닫는다.
					StateChangeToPlayOrPause(&PlayorPause);
					wsprintf(MciPlayTimeString, TEXT(" %02ld : %02ld / %02ld : %02ld"),	0, 0, 0, 0);//재생된 파일의 현재시간, 전체시간을 전부 0으로 초기화한다.
					SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);//초기화된 시간을 스태틱윈도우에 표시하게 한다.
				}
			}
			
			else if((PlayorPause == TRUE) && (lstrcmp(Global_lpstrFile, lpstrFile) != 0))//재생중일때 파일리스트윈도우로부터 새로운 파일완전경로를 전역버퍼에 받았고 재생기능을 호출했을때 처리(재생중일때 파일리스트 윈도우의 재생파일을 더블클릭했을시 호출)
			{
				lstrcpy(lpstrFile, Global_lpstrFile);

				MciErrorResult = MciOpen(Global_lpstrFile, &MciDeviceID);
				MciErrorResult = MciPlay(hMainWnd, &MciDeviceID);
				SetTimer(hMainWnd, PLAYPOSITIONSTATICTIMER, 500, NULL);
				SendMessage(hMainWnd, WM_TIMER, PLAYPOSITIONSTATICTIMER, 0);
				StateChangeToPlayOrPause(&PlayorPause);
				VolumeValue = (DWORD)VolumeScrollValue;//기록되어있는 볼륨값을 현재 볼륨으로 설정시키기위해 캐스팅해준다.
				MciSetVolume(&VolumeValue, &MciDeviceID);//해당파일의 볼륨값을 기록되어진 볼륨값으로 설정시킨다.

				WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//유니코드로 입력받은 파일의 전체 경로를 ANCI코드로 변환한다.
				_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//전달받은 전체 경로 문자를 잘게 나눈다.
				strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//전체 경로의 나누어진 부분중, 파일 포맷과 파일명을 합쳐준다.
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//변환된 파일명 + 파일포맷의 문자열을 다시 유니코드로 변환

				SetWindowText(hFileNameStaticWnd, lpstrFileTitle);

				if(MciErrorResult)//파일 열기 대화상자에서 파일을 제대로 읽어오지 못했을 경우 예외처리(사용자가 취소를 눌렀을 경우 등...)
				{
					mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//오픈된 MCI장치를 강제로 닫는다.
					StateChangeToPlayOrPause(&PlayorPause);
					wsprintf(MciPlayTimeString, TEXT(" %02ld : %02ld / %02ld : %02ld"),	0, 0, 0, 0);//재생된 파일의 현재시간, 전체시간을 전부 0으로 초기화한다.
					SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);//초기화된 시간을 스태틱윈도우에 표시하게 한다.
				}
			}

			else if(PlayorPause == TRUE)//PlayorPause == true 일때, Pause 버튼의 역활 수행, 재생중일때 버튼을 누르면 발생,(추가적 처리:파일리스트 윈도우로부터 같은 파일을 선택되었을때도 호출됨.)
			{
				mciSendCommand(MciDeviceID, MCI_PAUSE, 0, (DWORD)NULL);
				StateChangeToPlayOrPause(&PlayorPause);
			}
			break;
		case STOPBUTTON://정지 아이콘의 버튼윈도우를 눌렀을때 호출될 메세지
			mciSendCommand(MciDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)NULL);//재생을 멈추고 해당파일의 첫지점으로 이동
			StateChangeToPlayOrPause(&PlayorPause);
			EnableWindow(hPlayPositionScrollWnd, false);
			InvalidateRect(hPlayOrPauseImageButtonWnd, NULL, true);
			break;
		}
		SetFocus(hMainWnd);
		return 0;
	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_UP:
			SendMessage(hMainWnd, WM_HSCROLL, SB_PAGERIGHT, (LPARAM)hVolumePositionScrollWnd);
			break;
		case VK_DOWN:
			SendMessage(hMainWnd, WM_HSCROLL, SB_PAGELEFT, (LPARAM)hVolumePositionScrollWnd);
			break;
		case VK_RIGHT:
			if(IsWindowEnabled(hPlayPositionScrollWnd) != 0)
			{
				if(PlayorPause != false)
					SendMessage(hMainWnd, WM_HSCROLL, SB_PAGERIGHT, (LPARAM)hPlayPositionScrollWnd);
			}
			break;
		case VK_LEFT:
			if(IsWindowEnabled(hPlayPositionScrollWnd) != 0)
			{
				if(PlayorPause != false)
					SendMessage(hMainWnd, WM_HSCROLL, SB_PAGELEFT, (LPARAM)hPlayPositionScrollWnd);
			}
			break;
		case VK_SPACE:
			SendMessage(hMainWnd, WM_COMMAND, PLAYORPAUSECHANGEBUTTON, 0);
			InvalidateRect(hPlayOrPauseImageButtonWnd, NULL, true);
			break;
		}
		return 0;
	case WM_MOUSEWHEEL:
		switch(GetWheelDeltaWParamZ)
		{
		case 120:
			SendMessage(hMainWnd, WM_HSCROLL, SB_PAGERIGHT, (LPARAM)hVolumePositionScrollWnd);
			break;
		case -120:
			SendMessage(hMainWnd,WM_HSCROLL, SB_PAGELEFT, (LPARAM)hVolumePositionScrollWnd);
			break;
		}
		return 0;
	case WM_TIMER://타이머가 호출되었을때 호출될 메세지
		switch(wParam)
		{
		case PLAYPOSITIONSTATICTIMER:
			PlayCurrentTimeValue = MciGetPlayPosition(&PlayTotalTimeValue, &MciDeviceID);
			PlayTimePrintStatic(MciPlayTimeString);
			SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);
			PlayScrollValue = (int)(PlayCurrentTimeValue/1000);
			SetScrollPos(hPlayPositionScrollWnd, SB_CTL, PlayScrollValue, TRUE);
			if(PlayCurrentTimeValue == PlayTotalTimeValue)
			{
				PlayCurrentTimeValue = 0;
				PlayTimePrintStatic(MciPlayTimeString);
				SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);
				KillTimer(hMainWnd, PLAYPOSITIONSTATICTIMER);
			}
			break;
		case PLAYPOSITIONSCROLLTIMER:
			if(PlayCurrentTimeValue == PlayTotalTimeValue)
			{
				KillTimer(hMainWnd, PLAYPOSITIONSCROLLTIMER);
			}
			break;
		case INITIALIZELAYERSETTIMER:
			WndLayerTransparentOnOff(GlassOnOff, hMainWnd);
			InvalidateRect(hGlassImageButtonWnd, NULL, true);			
			KillTimer(hMainWnd, INITIALIZELAYERSETTIMER);
			break;
		}
		return 0;
	case MM_MCINOTIFY://MCI장치가 메세지를 받았을때(재생성공, 재생실패, 재생중 다른 사용자 메세지) 호출될 메세지
		switch(wParam)
		{
		case MCI_NOTIFY_SUCCESSFUL:
			//SendMessage(hMainWnd, WM_COMMAND, STOPBUTTON, 0);//WM_COMMAND의 STOPBUTTON메세지를 강제로 호출
			if(RepeatOnOff == TRUE)
			{
				SendMessage(hMainWnd, WM_COMMAND, STOPBUTTON, 0);
				SendMessage(hMainWnd, WM_COMMAND, PLAYORPAUSECHANGEBUTTON, 0);
			}
			else
				SendMessage(hNextTrackSelectImageButtonWnd, WM_LBUTTONUP, 0, 0);
			break;
		case MCI_NOTIFY_FAILURE:
		case MCI_NOTIFY_SUPERSEDED:
		case MCI_NOTIFY_ABORTED:
			break;
		}
		return 0;
	case WM_NCHITTEST:
		nHit = DefWindowProc(hMainWnd, iMessage, wParam, lParam);
		if(nHit == HTCLIENT)
			nHit = HTCAPTION;
		return nHit;
	case WM_DESTROY://윈도우가 종료될때 호출될 메세지
		GetCurrentDirectory(MAX_PATH, IniPath);
		_stprintf_s(IniInitialize, TEXT("%s\\MCIPInitialize.ini"), IniPath);
		_itoa_s(VolumeScrollValue, CastVolumeValueBuffer, VolumeValueBufferSize, 10);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, CastVolumeValueBuffer, strlen(CastVolumeValueBuffer),
			VolumeValueBuffer, VolumeValueBufferSize);
		WritePrivateProfileString(TEXT("Initialize Set"), TEXT("VolumeValue"), VolumeValueBuffer, IniInitialize);
		_itoa_s(VolumeScrollValue, CastVolumeValueBuffer, VolumeValueBufferSize, 10);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, CastVolumeValueBuffer, strlen(CastVolumeValueBuffer),
			VolumeValueBuffer, VolumeValueBufferSize);
		WritePrivateProfileString(TEXT("Initialize Set"), TEXT("VolumeScrollValue"), VolumeValueBuffer, IniInitialize);

		_itoa_s(RepeatOnOff, CastIniOnOffState, IniOnOffStateSize, 10);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, CastIniOnOffState, strlen(CastIniOnOffState), IniOnOffState, IniOnOffStateSize);
		WritePrivateProfileString(TEXT("Initialize Set"), TEXT("Repeat"), IniOnOffState, IniInitialize);
		_itoa_s(GlassOnOff, CastIniOnOffState, IniOnOffStateSize, 10);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, CastIniOnOffState, strlen(CastIniOnOffState), IniOnOffState, IniOnOffStateSize);
		WritePrivateProfileString(TEXT("Initialize Set"), TEXT("Glass"), IniOnOffState, IniInitialize);

		WritePrivateProfileString(TEXT("Initialize Set"), TEXT("LastPlayMediaPath"), Global_lpstrFile, IniInitialize);

		mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//MCI장치가 열려있다면 닫아준다.
		KillTimer(hMainWnd, PLAYPOSITIONSTATICTIMER);//만약 타이머가 사용중이라면 해당 타이머를 풀어준다.
		KillTimer(hMainWnd, PLAYPOSITIONSCROLLTIMER);
		KillTimer(hMainWnd, INITIALIZELAYERSETTIMER);
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hMainWnd, iMessage, wParam, lParam));//호출되지 않은 나머지 메세지는 디폴트처리 시킨다.
}