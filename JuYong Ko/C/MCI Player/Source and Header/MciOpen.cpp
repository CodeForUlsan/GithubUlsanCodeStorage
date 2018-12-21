#include "Headers\HeaderCollect.h"

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

DWORD MciOpen(TCHAR *MusicFileName, UINT *MciDeviceID)//Mci장치 오픈을 처리하는 함수
{
	DWORD MciErrorResult;//장치오픈에 실패할 경우 반환되는 에러메세지를 수치로 담을 변수
	MCI_OPEN_PARMS MciOpenParms;//장치 오픈 정보를 받을 구조체

	if(MciDeviceID)//만약에 디바이스 정보값이 0으로 초기화 되어있지 않을 경우...
		mciSendCommand(*MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//강제로 장치를 닫는다
	
	MciOpenParms.lpstrElementName = MusicFileName;//넘겨받는 파일명만을 구조체에 넘겨준다.
	MciErrorResult = mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&MciOpenParms);//넘겨받은 파일명만으로 장치를 오픈하여 재생할 준비를 한다
	if(MciErrorResult)//만약에 장치 오픈시에 에러메세지가 반환되었다면...
		mciSendCommand(*MciDeviceID, MCI_CLOSE, 0, (DWORD)NULL);//강제로 장치를 닫는다

	*MciDeviceID = MciOpenParms.wDeviceID;//장치 오픈이 성공 할경우 해당 디바이스값을 넘겨받는다.

	return MciErrorResult;//에러 메세지만을 반환한다
}