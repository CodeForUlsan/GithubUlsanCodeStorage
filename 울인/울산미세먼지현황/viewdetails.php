<?php

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

// 공공데이터 포털 대기오염정보 조회 서비스
// HTML, CSS, 자바스크립트 프론트엔드 파트
// 상세보기 화면

include_once("envdata.php");
include_once("functions.php");

// 사용자가 선택한 스테이션(측정소 = 동명) 이름값. 포스트로 넘어옴
$sname = $_GET['sname'];

$nowUrl = 'http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI']; // 페이스북 공유하기에 쓸 현재 페이지 URL
$titleLabel = "울인 - ".$sname."미세먼지현황";	// 페이지 타이틀 라벨
$contentLabel = "오늘 울산의 미세먼지 현황은... 1시간 단위로 확인할수있는 ".$sname."의 미세먼지 현황";	// 페이지 콘텐츠 설명

// 모바일 PC 체크 코드
$mobile_agent = array("iPhone", "iPad", "Android", "Blackberry", "SymbianOS|SCH-M\d+", "Opera Mini", "Windows ce", "Nokia", "Sony", "iPod" );
$check_mobile = false;
for($i=0; $i<sizeof($mobile_agent); $i++)
{
	if(stripos( $_SERVER['HTTP_USER_AGENT'], $mobile_agent[$i] ))
	{
		$check_mobile = true;
		break;
	}
}
?>

<!DOCTYPE html>
<html>
<head>
<meta http-equiv='Content-Type' content='text/html;charset=utf-8'>
<meta name='viewport' content='user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, width=device-width, height=device-height'>
<meta name='description' content='<?php print $contentLabel; ?>'>
<title><?php print $titleLabel; ?></title>
<!-- 페이스북 공유하기 메타 태그 -->
<meta property='og:url'			content='<?php print $nowUrl; ?>'/>
<meta property='og:type'		content='website'/>
<meta property='og:title'		content='<?php print $titleLabel; ?>'/>
<meta property='og:description'	content='<?php print $contentLabel; ?>'/>
<meta property='og:image'		content='http://ulin.kr/theme/Ulin/img/logo.png'/>
<!-- 페이스북 공유하기 메타 태그 끝 -->

<!-- Javascript CDN List -->
<!-- jQuery CDN -->
<script src='http://code.jquery.com/jquery-latest.js'></script>
<!-- 카카오 API -->
<script src="https://developers.kakao.com/sdk/js/kakao.min.js"></script>

<!-- local Javascript -->
<!-- 페이스북 공유하기 -->
<script src='./js/facebookshare.js'></script>
<!-- JQuery 구버젼 -->
<script src='./js/jquery-1.4.4.min.js'></script>
<!-- 배경움직이기 -->
<script src='./js/move-bg.js'></script>
<script>
// 배경화면 움직이기 애니매이션
$(document).ready(function() {
	moveBgAround();
});

function moveBgAround() {
	var x = Math.floor(Math.random()*401);
	var y = Math.floor(Math.random()*401);
	var time = Math.floor(Math.random()*1001) + 2000;
	$('.scrollBg').animate({
		backgroundPosition: '(' + (x * -1) + 'px ' + (y * -1) + 'px)'
	}, time, "swing", function() {
		moveBgAround();
	});
}
</script>

<!-- Local CSS -->
<link rel='stylesheet'  href='./css/fonts.css'></link>
<style>
body{
	background-attachment: fixed;
}
/* 하단 고정 메뉴 스타일 설정 */
.bottom{
	position: fixed;
	width: 100%;
	height: 9%;
	bottom: 0;
	background-color: black;
	margin: 0;
	padding: 0px 0px;
	z-index: 1000;
}
</style>
</head>
<?php
	if($check_mobile)
	{
		$bodyClassName = "mobile";
		$bodyBgImg = "bgcloudm".rand(1,10).".jpg";
	}
	else
	{
		$bodyClassName = "scrollBg";
		$bodyBgImg = "bgcloud".rand(1,10).".jpg";
	}
?>
<body class='<?php print $bodyClassName; ?>' style='margin:0 auto; padding:0; background-image:url("bgimg/<?php print $bodyBgImg; ?>");'>
<table width='99%' height='100%' border='0' style='margin: auto;'>
<?php
for($i = 0; $i < $totalCount; $i++)
{
	if(strcmp($sname, $stationName[$i]) == 0)
	{
		print "<tr>";
		print "<td colspan='2'>";
		print "<font><b>측정소 이름 : </b>";
		print $stationName[$i];
		print "</font><br>";
		print "<b><font>측정망 : </b>";
		print $mangName[$i];
		print "</font><br>";
		print "<b><font>오염도 측정 시각 : </b>";
		print $dataTime[$i];
		print "</font><br>";
		print "<b><font>아황산가스 농도(so2 단위 ppm) : </font></b>";
		print levelColor($so2Grade[$i], $so2Value[$i], 2);
		print "<br>";
		print "<b><font>일산화탄소 농도(co 단위 ppm) : </font></b>";
		print levelColor($coGrade[$i], $coValue[$i], 2);
		print "<br>";
		print "<b><font>오존 농도(o3 단위 ppm) : </font></b>";
		print levelColor($o3Grade[$i], $o3Value[$i], 2);
		print "<br>";
		print "<b><font>이산화질소 농도(no2 단위 ppm) : </font></b>";
		print levelColor($no2Grade[$i], $no2Value[$i], 2);
		print "<br>";
		print "<b><font>미세먼지 농도(PM10 단위 ㎍/㎥) : </font></b>";
		print levelColor($pm10Grade1h[$i], $pm10Value[$i], 1);
		print "<br>";
		print "<b><font>미세먼지 24시간 예측 농도(PM10 단위 ㎍/㎥) : </font></b>";
		print levelColor($pm10Grade[$i], $pm10Value24[$i], 1);
		print "<br>";
		print "<b><font>초미세먼지 농도(PM2.5 단위 ㎍/㎥) : </font></b>";
		print levelColor($pm25Grade1h[$i], $pm25Value[$i], 1);
		print "<br>";
		print "<b><font>초미세먼지 24시간 예측 농도(PM2.5 단위 ㎍/㎥) : </font></b>";
		print levelColor($pm25Grade[$i], $pm25Value24[$i], 1);
		print "<br>";
		print "<b><font>통합대기환경수치 : </font></b>";
		print levelColor($khaiGrade[$i], $khaiValue[$i], 0);
		print "<br>";
		print "<b><font>통합대기환경지수 : </font></b>";
		print exchangeGrade($khaiGrade[$i]);
		print "<br>";
		print "<b><font>아황산가스 지수 : </font></b>";
		print exchangeGrade($so2Grade[$i]);
		print "<br>";
		print "<b><font>일산화탄소 지수 : </font></b>";
		print exchangeGrade($coGrade[$i]);
		print "<br>";
		print "<b><font>오존 지수 : </font></b>";
		print exchangeGrade($o3Grade[$i]);
		print "<br>";
		print "<b><font>이산화질소 지수 : </font></b>";
		print exchangeGrade($no2Grade[$i]);
		print "<br>";
		print "<b><font>미세먼지 24시간 등급 : </font></b>";
		print exchangeGrade($pm10Grade[$i]);
		print "<br>";
		print "<b><font>초미세먼지 24시간 등급 : </font></b>";
		print exchangeGrade($pm25Grade[$i]);
		print "<br>";
		print "<b><font>미세먼지 1시간 등급 : </font></b>";
		print exchangeGrade($pm10Grade1h[$i]);
		print "<br>";
		print "<b><font>초미세먼지 1시간 등급 : </font></b>";
		print exchangeGrade($pm25Grade1h[$i]);
		print "</td>";
		print "</tr>";
	}
}
?>
</font>
<tr>
<td colspan = '2' align='center'>
	<font><b>데이터는 실시간 관측된 자료이며 측정소 현지 사정이나 데이터의 수신상태에 따라 미수신될 수 있습니다.
	<br>제공:환경부/한국환경공단</b></font></td>
</tr>
</table>
<table width='99%' border='0' style='margin:auto;'>
<!-- 공유하기 링크 -->
<tr>
<td colspan=3 style='text-align:center;'>
<h3 style='color:white;'>이 페이지를 공유하기</h3>
</td>
</tr>
<tr>
<!-- 페이스북 -->
<td style='text-align:center;'>
	<div class='fb-share-button' data-href='<?php print $nowUrl; ?>' data-layout='button' data-mobile_iframe='true' data-size='large'>
	</div>
</td>
<!-- 트위터 -->
<td style='text-align:center;'>
	<a href="https://twitter.com/share?ref_src=twsrc%5Etfw" class="twitter-share-button" data-size="large" data-show-count="false">Tweet</a>
	<script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>
</td>
<!-- 카카오톡 -->
<td style='text-align:center;'>
	<a id='kakao-link-btn' href='javascript:;'>
	<img src='//developers.kakao.com/assets/img/about/logos/kakaolink/kakaolink_btn_medium.png'/>
	</a>
</td>
</tr>
<!-- 공유하기 링크 끝 -->
</table>
<br>
<br>
<br>
<br>
<br>
<div class='bottom'>
<table width='100%' height='100%' border='0'>
	<tr>
		<td onClick="location.href='./index.php'" style='text-align:center; cursor:pointer;'>
		<font style='color:white'>메뉴화면으로</font>
		</td>
		<td onClick="location.href='http://ulin.kr'" style='text-align:center; cursor:pointer;'>
		<font style='color:white'>http://ulin.kr로 이동</font>
		</td>
	</tr>
</table>
</div>
<!-- 카카오링크 공유하기 -->
<script src='./js/phpforkakaoshare.js'></script>
<script>
// 카카오링크
var linkTitle = document.title;
var linkUrl = "<?php print $nowUrl; ?>";
var linkDescription = "<?php print $contentLabel; ?>";
var imgFileUrl = "http://ulin.kr/울산미세먼지현황/kakaolinkimg/scs.png";
phpforKakaoshare(linkTitle, linkUrl, linkDescription, imgFileUrl);
</script>
</body>
</html>