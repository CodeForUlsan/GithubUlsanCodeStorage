#include "Headers\HeaderCollect.h"

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

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