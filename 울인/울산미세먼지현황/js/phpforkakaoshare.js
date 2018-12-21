/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

/* 함수 사용법
kakaoshare(가게이름, 가게웹사이트 주소에 들어가는 폴더명, 가게설명, 톡메세지에 쓰일 확장자를 포함한 이미지 파일 이름);
ex)kakaoshare("행복막창", "행복막창", "막창의 명가 행복막창", "logoimage.png");
*/
// 카카오톡 공유하기 기능
function phpforKakaoshare(linkTitle, linkUrl, linkDescription, imgFileUrl)
{
	Kakao.init('카카오API 인증키');
	Kakao.Link.createDefaultButton({
		container: '#kakao-link-btn',
		objectType: 'feed',
		content: {
			title: linkTitle,
			description: linkDescription,
			imageUrl: imgFileUrl,
			link: {
				mobileWebUrl: linkUrl,
				webUrl: linkUrl
			}
		},
		buttons: [
			{
				title: '웹으로 보기',
				link: {
					mobileWebUrl: linkUrl,
					webUrl: linkUrl
				}
			},
		]
	});
}