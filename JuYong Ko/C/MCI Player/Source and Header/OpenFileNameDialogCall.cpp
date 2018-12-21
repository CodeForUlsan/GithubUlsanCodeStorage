#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

void OpenFileNameDialogCall(HWND hWnd, OPENFILENAME *OpenFileName, TCHAR *lpstrFile, TCHAR *lpstrFileTitle)
{
	OpenFileName->lStructSize = sizeof(OPENFILENAME);
	OpenFileName->hwndOwner = hWnd;
	OpenFileName->lpstrFilter = TEXT("MP3 파일\0*.mp3\0")
		TEXT("WAV 파일\0*.wav\0")
		TEXT("MIDI 파일\0*.mid\0")
		TEXT("모든 파일\0*.*\0");
	OpenFileName->nMaxFile = MAX_PATH;
	OpenFileName->lpstrFile = lpstrFile;
	OpenFileName->nMaxFileTitle = MAX_PATH;
	OpenFileName->lpstrFileTitle = lpstrFileTitle;
}