<?php

// 울산광역시 문화축제
// HTML, CSS, 자바스크립트 프론트엔드 파트

include_once($_SERVER['DOCUMENT_ROOT']."/ulsanfestival/picdata.php");
include_once($_SERVER['DOCUMENT_ROOT']."/ulsanfestival/functions.php");
include_once($_SERVER['DOCUMENT_ROOT']."/ulsanfestival/nmapservicekey.php"); // 네이버지도 API 서비스 키 $nmapservicekey

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
$(document).ready(function(){	// 상하 스크르롤 링크 애니매이션
	if(navigator.userAgent.toLowerCase().indexOf('edge') != -1 || 
	navigator.userAgent.toLowerCase().indexOf('chrome/33') != -1 ||
	navigator.userAgent.toLowerCase().indexOf('net') != -1)
	{
		$(".scroll").click(function(event){
			event.preventDefault();
			$('html,body').animate({scrollTop:$('[name="'+this.hash.substring(1)+'"]').offset().top}, 500);
		});
	}
});

$(document).ready(function(){	// 모바일일 경우 모바일용 화면으로 이동
	if(navigator.userAgent.toLowerCase().indexOf('android') != -1 ||
	navigator.userAgent.toLowerCase().indexOf('ios') != -1 ||
	navigator.userAgent.toLowerCase().indexOf('mobile') != -1)
	{
		location.href='http://ulin.kr/ulsanfestival/index.php';
	}
});
</script>
<style>
body {
	margin: 0px;
	padding: 0px;
}
.jbMenu {
	position: fixed;
	text-align: center;
	background-color: black;
	padding: 0px 0px;
	width: 100%;
	height: 10%;
	z-index:1000;
}

.menu {
	float: left;
	text-align: center;
}
.menu li {
	display: inline-block;
	text-align: center;
}
</style>
</head>
<body>
<div class='jbMenu'>
	<ul class='menu'>
	<?php
		for($i = 0; $i < $totalCount; $i++)
		{
			print "<li><font><b>";
			print "<a href='#".$ulsanfestivalTitle[$i]."' class='scroll' style='color:white; text-decoration:none;'>";
			print $ulsanfestivalTitle[$i];
			print "</b></font></a></li>&nbsp&nbsp&nbsp&nbsp&nbsp";
		}
	?>
	<li><font><b>
	<a href='http://ulin.kr' style='color:white; text-decoration:none;'>
		http://ulin.kr로 이동
	</a>
	</b></font></li>
	</ul>
</div>
<br>
<br>
<br>
<br>
<br>
<br>

<div>
	<?php
	$nmapXpos = array();
	$nmapYpos = array();
	$nmapTitle = array();
	
		for($i = 0; $i < $totalCount; $i++)
		{
			print "<a name='".$ulsanfestivalTitle[$i]."'></a>";
			print "<br><br><br><br><br><br>";
			print "<div><font style='font-size:175%;'><b>";
			print $ulsanfestivalTitle[$i];
			$nmapTitle[$i] = $ulsanfestivalTitle[$i];
			print "</b></font>";
			print "<br><br>";
			print "<font>";
			dtShow($ulsanfestivalStartDt[$i], $ulsanfestivalEndDt[$i]);
			scriptShow($ulsanfestivalPlace[$i], 1);							// 개최장소 표기
			scriptShow($ulsanfestivalAddr[$i], 2);							// 지번주소 표기
			scriptShow($ulsanfestivalNewAddr[$i], 3);						// 도로명주소 표기
			$nmapXpos[$i] = $ulsanfestivalXpos[$i];								// 네이버맵 경도값
			$nmapYpos[$i] = $ulsanfestivalYpos[$i];								// 네이버맵 위도값
			print "<br>";
			print "<div id='map".$i."' style='width:50%; height:50%;'></div>";	// 네이버맵 표기
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
		}
	?>
</div>
<script>
<?php
for($i = 0; $i < $totalCount; $i++)
{
	print "var map".$i." = new naver.maps.Map('map".$i."', {center: new naver.maps.LatLng(".$nmapYpos[$i].", ".$nmapXpos[$i].")});";
// 마커 표시
	print "var marker".$i."	= new naver.maps.Marker({";
	print "position: new naver.maps.LatLng(".$nmapYpos[$i].", ".$nmapXpos[$i]."),";
	print "map: map".$i.",";
	print "animation: naver.maps.Animation.BOUNCE";
	print "});";
// 마커 클릭 이벤트 처리
	print "naver.maps.Event.addListener(marker".$i.", 'click', function(e) {";
	print "if (infowindow".$i.".getMap())";
	print "{";
	print "infowindow".$i.".close();";
	print "}";
	print "else";
	print "{";
	print "infowindow".$i.".open(map, marker);";
	print "}";
	print "});";
// 마크 클릭시 인포윈도우 오픈
	print "var infowindow".$i." = new naver.maps.InfoWindow({";
	print "content: '<h3>".$nmapTitle[$i]."</h3>'";
	print "});";
}
?>
</script>
</body>
</html>