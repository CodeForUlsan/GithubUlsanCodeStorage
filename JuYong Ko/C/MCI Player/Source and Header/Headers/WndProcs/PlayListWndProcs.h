#ifndef _PLAYLISTWNDPROCS_H_
#define _PLAYLISTWNDPROCS_H_
LRESULT CALLBACK PlayListWndProc(HWND hPlayListWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ClosePlayListImageButtonWndProc(HWND hClosePlayListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AddListImageButtonWndProc(HWND hAddListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DeleteListImageButtonWndProc(HWND hDeleteListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AllDeleteImageButtonWndProc(HWND hAllDeleteImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SaveListImageButtonWndProc(HWND hSaveListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LoadListImageButtonWndProc(HWND hLoadListImageButtonWnd, UINT iMessage, WPARAM wParam, LPARAM lPAram);
#endif