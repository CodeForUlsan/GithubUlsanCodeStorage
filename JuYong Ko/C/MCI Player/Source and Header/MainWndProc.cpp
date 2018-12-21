#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

LRESULT CALLBACK MainWndProc(HWND hMainWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	RECT WinClientRectangle;//������������ Ŭ���̾�Ʈ ������ ������ ����	
	HMENU hMenu=NULL, hPopup=NULL;
	OPENFILENAME OpenFileName;//���Ͽ��� ��ȭ���� ����ü
	static TCHAR lpstrFile[MAX_PATH]=TEXT("");//����ڰ� ������ ���ϸ� ���ڸ� ������ ����(�������)
	TCHAR StaticWndlpstrFile[MAX_PATH]=TEXT("");
	TCHAR lpstrFileTitle[MAX_PATH]=TEXT("");//����ڰ� ������ ���ϸ� ���ڸ� ������ ����
	TCHAR MciErrorString[MAX_PATH]=TEXT("");//Mci��ġ ����� �߻��� �����޼����� ������ ���ڿ� ����
	TCHAR MciVolumeString[10]=TEXT("");//Mci��ġ�� ������ ���ڷ� ��ȯ�Ͽ� ����� ����
	TCHAR MciPlayTimeString[20]=TEXT("");//Mci��ġ�� ���� ����ð� / �� ����ð��� ������ ����
	NOTIFYICONDATA NotifyIconData;//�������� ����
	POINT Point;
	DWORD MciErrorResult;//Mci��ġ ����� �߻��� �����޼����� �ڵ带 ������ DWORD�� ����(��ȣ���� ������)
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
	case WM_CREATE://�����찡 ȭ�鿡 �׷��������� �̸� ����Ǿ��� �޼���
		//AnimateWindow(hMainWnd, 1000, AW_SLIDE);
		ShowWindow(hMainWnd, SW_SHOW);
		GetClientRect(hMainWnd, &WinClientRectangle);//�θ�, ���� �������� Ŭ���̾�Ʈ ������ ���Ѵ�.
		DragAcceptFiles(hMainWnd, TRUE);//�θ� �����찡 �巡�׵� ������ �Է¹����� �ֵ��� Ȱ��ȭ ��Ų��.
		
		SetWindowLong(hMainWnd, GWL_EXSTYLE, GetWindowLong(hMainWnd, GWL_EXSTYLE)|WS_EX_LAYERED);

		GetCurrentDirectory(MAX_PATH, IniPath);
		_stprintf_s(IniInitialize, TEXT("%s\\MCIPInitialize.ini"), IniPath);
		VolumeValue = GetPrivateProfileInt(TEXT("Initialize Set"), TEXT("VolumeValue"), 50, IniInitialize);
		VolumeScrollValue = GetPrivateProfileInt(TEXT("Initialize Set"), TEXT("VolumeScrollValue"), 50, IniInitialize);
		
		wsprintf(MciVolumeString, TEXT("%4ld %%"), VolumeValue);//VolumeValue�� TCHAR������ ��ȯ�Ͽ� MciVolumeString�� ���ڿ��� ��ȯ�Ͽ� �����Ѵ�.
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

		WideCharToMultiByte(CP_ACP, 0, Global_lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//�����ڵ�� �Է¹��� ������ ��ü ��θ� ANCI�ڵ�� ��ȯ�Ѵ�.
		_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//���޹��� ��ü ��� ���ڸ� �߰� ������.
		strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//��ü ����� �������� �κ���, ���� ���˰� ���ϸ��� �����ش�.
		SetWindowText(hFileNameStaticWnd, lpstrFileTitle);//��ȯ�� �����ڵ带 �ش� ������ �ڵ��� ���� ����ƽ �����쿡 ǥ���Ѵ�.
		return 0;
	case WM_PAINT:
		hDC = BeginPaint(hMainWnd, &PaintStruct);
		CustomButtonImageDoubleBuffering(hDC, TEXT("Images\\Skin.bmp"));
		EndPaint(hMainWnd, &PaintStruct);
		return 0;
	case WM_DROPFILES://�巡�׵� ������ �޾����� ó���� �޼���
		if(MciDeviceID != 0)//��ġ�� �ʱ�ȭ�Ǿ����� �ʴٸ�...
			mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//��ġ�� �ݴ´�.

		DragQueryFile(hDropFile, 0, lpstrFile, MAX_PATH);//�巡�׵� ������ ������θ� �޾Ƽ� �ڵ��� ����.

		lstrcpy(Global_lpstrFile, lpstrFile);

		PlayorPause = false;
		InvalidateRect(hPlayOrPauseImageButtonWnd, NULL, TRUE);		

		WrapperMusicFilePlayFunction(hMainWnd, Global_lpstrFile, &MciErrorResult);//Wrapper �Լ� ȣ��

		WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//�����ڵ�� �Է¹��� ������ ��ü ��θ� ANCI�ڵ�� ��ȯ�Ѵ�.
		_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//���޹��� ��ü ��� ���ڸ� �߰� ������.
		strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//��ü ����� �������� �κ���, ���� ���˰� ���ϸ��� �����ش�.
		if(MciErrorResult)//���� ��ġ ���½ó�, ���ֽ������� mci ��ġ�� ������ �߻��ߴٸ�...
		{
			mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//���µ� MCI��ġ�� ������ �ݴ´�.
			StateChangeToPlayOrPause(&PlayorPause);
			wsprintf(MciPlayTimeString, TEXT(" %02ld : %02ld / %02ld : %02ld"),	0, 0, 0, 0);//����� ������ ����ð�, ��ü�ð��� ���� 0���� �ʱ�ȭ�Ѵ�.
			SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);//�ʱ�ȭ�� �ð��� ����ƽ�����쿡 ǥ���ϰ� �Ѵ�.
			MessageBox(hMainWnd, TEXT("���� ���⿡ �����Ͽ����ϴ�."), TEXT("�˸�"), MB_OK);			
		}
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//��ȯ�� ���ϸ� + ���������� ���ڿ��� �ٽ� �����ڵ�� ��ȯ
		SetWindowText(hFileNameStaticWnd, lpstrFileTitle);//��ȯ�� �����ڵ带 �ش� ������ �ڵ��� ���� ����ƽ �����쿡 ǥ���Ѵ�.
		SendMessage(hPlayListBoxWnd, LB_RESETCONTENT, 0, 0);
		SendMessage(hPlayListBoxWnd, LB_ADDSTRING, 0, (LPARAM)lpstrFileTitle);
		DragFinish(hDropFile);//���� �巡�� �Է��� �����ϰ� �ڵ��� �ݾ��ش�.
		SetForegroundWindow(hMainWnd);//������ �Է¹��� �ش������츦 Ȱ��ȭ�Ѵ�.
		return 0;
	case TRAY://�����찡 ������°� �ǰ� �۾�ǥ���ٿ� ��ϵ� �����϶� ó���� �޼���
		switch(lParam)
		{
		case WM_LBUTTONDOWN://�����찡 ��������̰� �۾�ǥ���ٿ� ��ϵǾ������� ���콺 ���ʹ�ư�� �������� ȣ��� �޼���
			NotifyIconDataCall(hMainWnd, &NotifyIconData, TRAY);//�ش��Լ� ȣ��
			Shell_NotifyIcon(NIM_DELETE, &NotifyIconData);//�����츦 ���̰� �ϱ��� Ʈ���̿� ��ϵ� ������ �Ҹ� 
			ShowWindow(hMainWnd, SW_SHOWNORMAL);//Ʈ���� ������ �Ҹ��� �����츦 ����������
			SetForegroundWindow(hMainWnd);//�������� ������ �Ǿ����� �Ȱ� Ȱ��ȭ
			break;
		case WM_RBUTTONDOWN://�����찡 ��������̰� �۾�ǥ���ٿ� ��ϵǾ������� ���콺 �����ʹ�ư�� �������� ȣ��� �޼���
			FloatingPopupMenuCall(hMainWnd, hMenu, hPopup, Point);//�÷����˾��޴��� ȣ���� �Լ�
			break;
		}
		return 0;
	case WM_SIZE://�������� ũ�Ⱑ ����Ǿ����ÿ� ȣ��� �޼���
		switch(wParam)
		{
		case SIZE_MINIMIZED://������ ����� �ּ�ȭ��ư���� �����찡 ������°� �Ǿ����� ȣ��� �޼���
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
	case WM_HSCROLL://��ũ���������� �޼����� �߻������� ȣ��� �޼���
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
		case IDM_OPENFILE://���� ����(�÷��� �˾� �޴�)
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
		case IDM_INFORMATION://���α׷� ����(�÷��� �˾� �޴�)
			SendMessage(hVersionImageButtonWnd, WM_LBUTTONUP, 0, 0);
			break;
		case IDM_EXIT://����(�÷��� �˾� �޴�)
			DestroyWindow(hMainWnd);
			break;
		case PLAYORPAUSECHANGEBUTTON://����������� ��ư�����츦 �������� ȣ��� �޼���
			if(PlayorPause == false)//����, Ȥ�� �Ͻ������� ���¶��...
			{
				if((MciDeviceID == 0) && (lstrcmp(Global_lpstrFile, TEXT("")) == 0))//���� ���� ��� ���۰� ����� ��ġ ����̽��� 0�Ͻÿ��� �ش�
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

						WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//�����ڵ�� �Է¹��� ������ ��ü ��θ� ANCI�ڵ�� ��ȯ�Ѵ�.
						_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//���޹��� ��ü ��� ���ڸ� �߰� ������.
						strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//��ü ����� �������� �κ���, ���� ���˰� ���ϸ��� �����ش�.
						MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//��ȯ�� ���ϸ� + ���������� ���ڿ��� �ٽ� �����ڵ�� ��ȯ

						SetWindowText(hFileNameStaticWnd, lpstrFileTitle);

						SendMessage(hPlayListBoxWnd, LB_RESETCONTENT, 0, 0);
						SendMessage(hPlayListBoxWnd, LB_ADDSTRING, 0, (LPARAM)lpstrFileTitle);
					}
				}

				else if(lstrcmp(lpstrFile, TEXT("")) != 0)//��ũ�ѹٿ��� ���� ������ ������ ȣ���, MIC_PAUSE ���� ������ ȣ��ÿ� ó��, �ݺ���� ������� ������ȣ��� ó��
				{
					MciErrorResult = MciPlay(hMainWnd, &MciDeviceID);
					SetTimer(hMainWnd, PLAYPOSITIONSTATICTIMER, 500, NULL);
					SendMessage(hMainWnd, WM_TIMER, PLAYPOSITIONSTATICTIMER, 0);
					StateChangeToPlayOrPause(&PlayorPause);
					VolumeValue = (DWORD)VolumeScrollValue;//��ϵǾ��ִ� �������� ���� �������� ������Ű������ ĳ�������ش�.
					MciSetVolume(&VolumeValue, &MciDeviceID);//�ش������� �������� ��ϵǾ��� ���������� ������Ų��.

					WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//�����ڵ�� �Է¹��� ������ ��ü ��θ� ANCI�ڵ�� ��ȯ�Ѵ�.
					_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//���޹��� ��ü ��� ���ڸ� �߰� ������.
					strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//��ü ����� �������� �κ���, ���� ���˰� ���ϸ��� �����ش�.
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//��ȯ�� ���ϸ� + ���������� ���ڿ��� �ٽ� �����ڵ�� ��ȯ

					SetWindowText(hFileNameStaticWnd, lpstrFileTitle);

					if(MciErrorResult)//���� ���� ��ȭ���ڿ��� ������ ����� �о���� ������ ��� ����ó��(����ڰ� ��Ҹ� ������ ��� ��...)
					{
						mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//���µ� MCI��ġ�� ������ �ݴ´�.
						StateChangeToPlayOrPause(&PlayorPause);
						wsprintf(MciPlayTimeString, TEXT(" %02ld : %02ld / %02ld : %02ld"),	0, 0, 0, 0);//����� ������ ����ð�, ��ü�ð��� ���� 0���� �ʱ�ȭ�Ѵ�.
						SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);//�ʱ�ȭ�� �ð��� ����ƽ�����쿡 ǥ���ϰ� �Ѵ�.
					}
				}

				else if(lstrcmp(Global_lpstrFile, TEXT("")) != 0)//���α׷� ó�� ������ MCI ��ġ�� ���µǾ����� �ʰ�, �������Ͽ������ ���۰� ��������� ȣ��(���ϸ���Ʈ ������κ��� ������ ȣ���)
				{
					GetWindowText(hFileNameStaticWnd, StaticWndlpstrFile, MAX_PATH);
					
					lstrcpy(lpstrFile, Global_lpstrFile);

					WrapperMusicFilePlayFunction(hMainWnd, Global_lpstrFile, &MciErrorResult);

					WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//�����ڵ�� �Է¹��� ������ ��ü ��θ� ANCI�ڵ�� ��ȯ�Ѵ�.
					_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//���޹��� ��ü ��� ���ڸ� �߰� ������.
					strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//��ü ����� �������� �κ���, ���� ���˰� ���ϸ��� �����ش�.
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//��ȯ�� ���ϸ� + ���������� ���ڿ��� �ٽ� �����ڵ�� ��ȯ

					SetWindowText(hFileNameStaticWnd, lpstrFileTitle);
				}

				if(MciErrorResult)//���� ��ġ ���½ó�, ���ֽ������� mci ��ġ�� ������ �߻��ߴٸ�...
				{
					mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//���µ� MCI��ġ�� ������ �ݴ´�.
					StateChangeToPlayOrPause(&PlayorPause);
					wsprintf(MciPlayTimeString, TEXT(" %02ld : %02ld / %02ld : %02ld"),	0, 0, 0, 0);//����� ������ ����ð�, ��ü�ð��� ���� 0���� �ʱ�ȭ�Ѵ�.
					SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);//�ʱ�ȭ�� �ð��� ����ƽ�����쿡 ǥ���ϰ� �Ѵ�.
				}
			}
			
			else if((PlayorPause == TRUE) && (lstrcmp(Global_lpstrFile, lpstrFile) != 0))//������϶� ���ϸ���Ʈ������κ��� ���ο� ���Ͽ�����θ� �������ۿ� �޾Ұ� �������� ȣ�������� ó��(������϶� ���ϸ���Ʈ �������� ��������� ����Ŭ�������� ȣ��)
			{
				lstrcpy(lpstrFile, Global_lpstrFile);

				MciErrorResult = MciOpen(Global_lpstrFile, &MciDeviceID);
				MciErrorResult = MciPlay(hMainWnd, &MciDeviceID);
				SetTimer(hMainWnd, PLAYPOSITIONSTATICTIMER, 500, NULL);
				SendMessage(hMainWnd, WM_TIMER, PLAYPOSITIONSTATICTIMER, 0);
				StateChangeToPlayOrPause(&PlayorPause);
				VolumeValue = (DWORD)VolumeScrollValue;//��ϵǾ��ִ� �������� ���� �������� ������Ű������ ĳ�������ش�.
				MciSetVolume(&VolumeValue, &MciDeviceID);//�ش������� �������� ��ϵǾ��� ���������� ������Ų��.

				WideCharToMultiByte(CP_ACP, 0, lpstrFile, MAX_PATH, lpstrFileChar, MAX_PATH, NULL, NULL);//�����ڵ�� �Է¹��� ������ ��ü ��θ� ANCI�ڵ�� ��ȯ�Ѵ�.
				_splitpath_s(lpstrFileChar, NULL, NULL, NULL, NULL, lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar, MAX_PATH);//���޹��� ��ü ��� ���ڸ� �߰� ������.
				strcat_s(lpstrFileTitleChar, MAX_PATH, lpstrFileTitleFormatChar);//��ü ����� �������� �κ���, ���� ���˰� ���ϸ��� �����ش�.
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, lpstrFileTitleChar, MAX_PATH, lpstrFileTitle, MAX_PATH);//��ȯ�� ���ϸ� + ���������� ���ڿ��� �ٽ� �����ڵ�� ��ȯ

				SetWindowText(hFileNameStaticWnd, lpstrFileTitle);

				if(MciErrorResult)//���� ���� ��ȭ���ڿ��� ������ ����� �о���� ������ ��� ����ó��(����ڰ� ��Ҹ� ������ ��� ��...)
				{
					mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//���µ� MCI��ġ�� ������ �ݴ´�.
					StateChangeToPlayOrPause(&PlayorPause);
					wsprintf(MciPlayTimeString, TEXT(" %02ld : %02ld / %02ld : %02ld"),	0, 0, 0, 0);//����� ������ ����ð�, ��ü�ð��� ���� 0���� �ʱ�ȭ�Ѵ�.
					SetWindowText(hPlayPositionStaticWnd, MciPlayTimeString);//�ʱ�ȭ�� �ð��� ����ƽ�����쿡 ǥ���ϰ� �Ѵ�.
				}
			}

			else if(PlayorPause == TRUE)//PlayorPause == true �϶�, Pause ��ư�� ��Ȱ ����, ������϶� ��ư�� ������ �߻�,(�߰��� ó��:���ϸ���Ʈ ������κ��� ���� ������ ���õǾ������� ȣ���.)
			{
				mciSendCommand(MciDeviceID, MCI_PAUSE, 0, (DWORD)NULL);
				StateChangeToPlayOrPause(&PlayorPause);
			}
			break;
		case STOPBUTTON://���� �������� ��ư�����츦 �������� ȣ��� �޼���
			mciSendCommand(MciDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)NULL);//����� ���߰� �ش������� ù�������� �̵�
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
	case WM_TIMER://Ÿ�̸Ӱ� ȣ��Ǿ����� ȣ��� �޼���
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
	case MM_MCINOTIFY://MCI��ġ�� �޼����� �޾�����(�������, �������, ����� �ٸ� ����� �޼���) ȣ��� �޼���
		switch(wParam)
		{
		case MCI_NOTIFY_SUCCESSFUL:
			//SendMessage(hMainWnd, WM_COMMAND, STOPBUTTON, 0);//WM_COMMAND�� STOPBUTTON�޼����� ������ ȣ��
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
	case WM_DESTROY://�����찡 ����ɶ� ȣ��� �޼���
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

		mciSendCommand(MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//MCI��ġ�� �����ִٸ� �ݾ��ش�.
		KillTimer(hMainWnd, PLAYPOSITIONSTATICTIMER);//���� Ÿ�̸Ӱ� ������̶�� �ش� Ÿ�̸Ӹ� Ǯ���ش�.
		KillTimer(hMainWnd, PLAYPOSITIONSCROLLTIMER);
		KillTimer(hMainWnd, INITIALIZELAYERSETTIMER);
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hMainWnd, iMessage, wParam, lParam));//ȣ����� ���� ������ �޼����� ����Ʈó�� ��Ų��.
}