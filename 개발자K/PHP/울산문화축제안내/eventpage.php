<?php

// 울산광역시 문화축제
// HTML, CSS, 자바스크립트 프론트엔드 파트
// 이벤트 상세 페이지 파트

include_once("picdata.php");
include_once("functions.php");
include_once("nmapservicekey.php"); // 네이버지도 API 서비스 키 $nmapservicekey

?>

<html>
<head>
<meta http-equiv='Content-Type' content='text/html;charset=utf-8'>
<meta http-equiv='X-UA-Compatible' content='IE=edge'>
<meta name='viewport' content='user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, width=device-width, height=device-height'>
<link rel='stylesheet'  href='fonts.css'></link>
<script src='http://code.jquery.com/jquery-latest.js'></script>
<script type="text/javascript" src="https://openapi.map.naver.com/openapi/v3/maps.js?clientId=<?php print $nmapservicekey; ?>&submodules=geocoder"></script>
<script>
$(document).ready(function(){
	if(navigator.userAgent.toLowerCase().indexOf('mobile') != -1)
	{
	}
	else
	{
		if(navigator.userAgent.toLowerCase().indexOf('windows') != -1 ||
		navigator.userAgent.toLowerCase().indexOf('mac') != -1 ||
		navigator.userAgent.toLowerCase().indexOf('linux') != -1)
		{
			location.href='http://ulin.kr/ulsanfestival/pc/index.php';
		}
	}
});
</script>
<style>
.bottom{
	position: fixed;
	width: 100%;
	height: 5%;
	bottom: 0;
	background-color: black;
	margin: 0;
	padding: 0px 0px;
	z-index: 1000;
}
</style>
</head>
<body>

<?php
$fname = $_GET['fname'];
$nmapXpos;
$nmapYpos;
$nmapTitle;

for($i = 0; $i < $totalCount; $i++)
{
	if(strcmp($fname, $ulsanfestivalTitle[$i]) == 0)
	{
		print "<font style='font-size:157%'><b>";
		print $ulsanfestivalTitle[$i];
		$nmapTitle = $ulsanfestivalTitle[$i];
		print "</b></font>";
		print "<br><br>";
		print "<b>축제사진들</b>";
		print "<br>";
		print "</font>";
		print "<p align='center'>";
		print "<div>";
		for($a = 0; $a < $picTotalCount[$i]; $a++)
		{
			print "<img style='width:100%; height:auto;' src='";
			print $picFileUrl[$i][$a];
			print "'>";
			print "<br><br><br>";
		}
		print "</div>";
		print "<font>";
		dtShow($ulsanfestivalStartDt[$i], $ulsanfestivalEndDt[$i]); 	// 축제기간 표기
		scriptShow($ulsanfestivalPlace[$i], 1);							// 개최장소 표기
		scriptShow($ulsanfestivalAddr[$i], 2);							// 지번주소 표기
		scriptShow($ulsanfestivalNewAddr[$i], 3);						// 도로명주소 표기
		$nmapXpos = $ulsanfestivalXpos[$i];								// 네이버맵 경도값
		$nmapYpos = $ulsanfestivalYpos[$i];								// 네이버맵 위도값
		print "<br>";
		print "<div id='map' style='width:100%; height:50%;'></div>";	// 네이버맵 표기
		print "<br>";
		scriptShow($ulsanfestivalHP[$i], 4);							// 홈페이지 표기
		scriptShow($ulsanfestivalSupervise[$i], 5);						// 주관기관 표기
		scriptShow($ulsanfestivalHost[$i], 6);							// 주최기관 표기
		scriptShow($ulsanfestivalTel[$i], 7);							// 연락처 표기
		scriptShow($ulsanfestivalSupport[$i], 8);						// 후원기관 표기
		scriptShow($ulsanfestivalInfo[$i], 9);							// 관련정보 표기
		print "<br>";
		print $ulsanfestivalContents[$i];								// 축제내용 표기
		print "<br><br>";
	}
}
?>

<br>
<br>
<br>
<div class='bottom'>
<table width='100%' height='100%' border='0'>
	<tr>
		<td onClick="location.href='http://ulin.kr/ulsanfestival/index.php'" style='text-align:center; cursor:pointer;'>
		<font style='color:white'>메뉴화면으로</font>
		</td>
		<td onClick="location.href='http://ulin.kr'" style='text-align:center; cursor:pointer;'>
		<font style='color:white'>http://ulin.kr로 이동</font>
		</td>
	</tr>
</table>
</div>
<script>
var map = new naver.maps.Map('map', {center: new naver.maps.LatLng(<?php print $nmapYpos.", ".$nmapXpos; ?>)});
// 마커 표시
var marker = new naver.maps.Marker({
	position: new naver.maps.LatLng(<?php print $nmapYpos.", ".$nmapXpos; ?>),
	map: map,
	animation: naver.maps.Animation.BOUNCE
});
// 마커 클릭 이벤트 처리
naver.maps.Event.addListener(marker, "click", function(e) {
	if (infowindow.getMap())
	{
		infowindow.close();
	}
	else
	{
		infowindow.open(map, marker);
	}
});
// 마크 클릭시 인포윈도우 오픈
var infowindow = new naver.maps.InfoWindow({
	content: '<h3><?php print $nmapTitle; ?></h3>'
});
</script>
</body>
</html>