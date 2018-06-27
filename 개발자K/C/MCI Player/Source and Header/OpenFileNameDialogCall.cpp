#include "Headers\HeaderCollect.h"

void OpenFileNameDialogCall(HWND hWnd, OPENFILENAME *OpenFileName, TCHAR *lpstrFile, TCHAR *lpstrFileTitle)
{
	OpenFileName->lStructSize = sizeof(OPENFILENAME);
	OpenFileName->hwndOwner = hWnd;
	OpenFileName->lpstrFilter = TEXT("MP3 ����\0*.mp3\0")
		TEXT("WAV ����\0*.wav\0")
		TEXT("MIDI ����\0*.mid\0")
		TEXT("��� ����\0*.*\0");
	OpenFileName->nMaxFile = MAX_PATH;
	OpenFileName->lpstrFile = lpstrFile;
	OpenFileName->nMaxFileTitle = MAX_PATH;
	OpenFileName->lpstrFileTitle = lpstrFileTitle;
}