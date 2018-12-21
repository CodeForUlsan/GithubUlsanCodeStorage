#ifndef _MAINWNDPROCS_H_
#define _MAINWNDPROCS_H_
LRESULT CALLBACK MainWndProc(HWND hMainWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK CloseWindowImageButtonWndProc(HWND hCloseWindowImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK GlassImageButtonWndProc(HWND hGlassImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK MinimizeWindowImageButtonWndProc(HWND hMinimizeWindowImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK NextTrackSelectImageButtonWndProc(HWND hNextTrackSelectImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PlayOrPauseImageButtonWndProc(HWND hPlayOrPauseImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PrevTrackSelectImageButtonWndProc(HWND hPrevTrackSelectImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK RepeatImageButtonWndProc(HWND hRepeatImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK StopImageButtonWndProc(HWND hStopImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK VersionImageButtonWndProc(HWND hVersionImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PlayListCallImageButtonWndProc(HWND hPlayListCallImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
#endif