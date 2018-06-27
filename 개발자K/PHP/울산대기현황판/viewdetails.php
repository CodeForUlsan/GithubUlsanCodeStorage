<?php

// 공공데이터 포털 대기오염정보 조회 서비스
// HTML, CSS, 자바스크립트 프론트엔드 파트
// 상세보기 화면

include_once("envdata.php");
include_once("functions.php");

?>

<html>
<head>
<meta http-equiv='Content-Type' content='text/html;charset=utf-8'>
<meta name='viewport' content='user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, width=device-width, height=device-height'>
<link rel='stylesheet'  href='fonts.css'></link>
<script src='http://code.jquery.com/jquery-latest.js'></script>
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
<table width='100%' height='100%' border='0'>
<font>
<?php
$sname = $_GET['sname'];

for($i = 0; $i < $totalCount; $i++)
{
	if(strcmp($sname, $stationName[$i]) == 0)
	{
		print "<tr>";
		print "<td colspan='2'>";
		print "<b>측정소 이름 : </b>";
		print $stationName[$i];
		print "<br>";
		print "<b>측정망 : </b>";
		print $mangName[$i];
		print "<br>";
		print "<b>오염도 측정 시각 : </b>";
		print $dataTime[$i];
		print "<br>";
		print "<b>아황산가스 농도(so2 단위 ppm) : </b>";
		print levelColor($so2Grade[$i], $so2Value[$i], 2);
		print "<br>";
		print "<b>일산화탄소 농도(co 단위 ppm) : </b>";
		print levelColor($coGrade[$i], $coValue[$i], 2);
		print "<br>";
		print "<b>오존 농도(o3 단위 ppm) : </b>";
		print levelColor($o3Grade[$i], $o3Value[$i], 2);
		print "<br>";
		print "<b>이산화질소 농도(no2 단위 ppm) : </b>";
		print levelColor($no2Grade[$i], $no2Value[$i], 2);
		print "<br>";
		print "<b>미세먼지 농도(PM10 단위 ㎍/㎥) : </b>";
		print levelColor($pm10Grade1h[$i], $pm10Value[$i], 1);
		print "<br>";
		print "<b>미세먼지 24시간 예측 농도(PM10 단위 ㎍/㎥) : </b>";
		print levelColor($pm10Grade[$i], $pm10Value24[$i], 1);
		print "<br>";
		print "<b>초미세먼지 농도(PM2.5 단위 ㎍/㎥) : </b>";
		print levelColor($pm25Grade1h[$i], $pm25Value[$i], 1);
		print "<br>";
		print "<b>초미세먼지 24시간 예측 농도(PM2.5 단위 ㎍/㎥) : </b>";
		print levelColor($pm25Grade[$i], $pm25Value24[$i], 1);
		print "<br>";
		print "<b>통합대기환경수치 : </b>";
		print levelColor($khaiGrade[$i], $khaiValue[$i], 0);
		print "<br>";
		print "<b>통합대기환경지수 : </b>";
		print exchangeGrade($khaiGrade[$i]);
		print "<br>";
		print "<b>아황산가스 지수 : </b>";
		print exchangeGrade($so2Grade[$i]);
		print "<br>";
		print "<b>일산화탄소 지수 : </b>";
		print exchangeGrade($coGrade[$i]);
		print "<br>";
		print "<b>오존 지수 : </b>";
		print exchangeGrade($o3Grade[$i]);
		print "<br>";
		print "<b>이산화질소 지수 : </b>";
		print exchangeGrade($no2Grade[$i]);
		print "<br>";
		print "<b>미세먼지 24시간 등급 : </b>";
		print exchangeGrade($pm10Grade[$i]);
		print "<br>";
		print "<b>초미세먼지 24시간 등급 : </b>";
		print exchangeGrade($pm25Grade[$i]);
		print "<br>";
		print "<b>미세먼지 1시간 등급 : </b>";
		print exchangeGrade($pm10Grade1h[$i]);
		print "<br>";
		print "<b>초미세먼지 1시간 등급 : </b>";
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
<br>
<br>
<br>
<div class='bottom'>
<table width='100%' height='100%' border='0'>
	<tr>
		<td onClick="location.href='http://ulin.kr/ulsanairsb/index.php'" style='text-align:center; cursor:pointer;'>
		<font style='color:white'>메뉴화면으로</font>
		</td>
		<td onClick="location.href='http://ulin.kr'" style='text-align:center; cursor:pointer;'>
		<font style='color:white'>http://ulin.kr로 이동</font>
		</td>
	</tr>
</table>
</div>
</body>
</html>