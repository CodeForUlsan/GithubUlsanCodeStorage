<?php

// 공공데이터 포털 대기오염정보 조회 서비스
// HTML, CSS, 자바스크립트 프론트엔드 파트
// 메인화면

include_once("envdata.php");
include_once("functions.php");

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

<html>
<head>
<meta http-equiv='Content-Type' content='text/html;charset=utf-8'>
<meta name='viewport' content='user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, width=device-width, height=device-height'>
<link rel='stylesheet'  href='fonts.css'></link>
<script src='http://code.jquery.com/jquery-latest.js'></script>
<style>
body {
	margin: 0px;
	padding: 0px;
}
<?php
for($i = 0; $i < $totalCount; $i++)
{
	print ".ticker".$i."{";
	print "width : 100%;";
	if($check_mobile)
	{// 모바일
		print "height : 75%;";
	}
	else
	{// PC
		print "height : 71px;";
	}
	print "overflow : hidden;";
	print "border : 1px solid #DDD;";
	print "margin : 0;";
	print "padding : 0;";
	print "list-style : none;";
	print "border-radius : 5px;";
	print "box-shadow : 0px 0px 5px #DDD;";
	print "text-align : center;";
	print "}";

	print ".ticker".$i." li {";
	print "border-bottom : 1px;";
	print "padding : 7px;";
	print "margin : 0px 5px;";
	print "}";
}
?>
</style>
</head>
<body>
<body style='margin:0; padding:0;'>
<table width='100%' height='100%' border='1'>
<tr>
	<td>
	<font><b>
	<?php print $dataTime[0]." 울산대기현황"; ?>
	</b></font>
	</td>
	<td bgcolor='black' onClick="location.href='http://ulin.kr'" style='text-align:center; cursor:pointer;'>
	<font color='white'><b>http://ulin.kr로 이동</b></font>
	</td>
</tr>
<?php
	for($i = 0; $i < $totalCount; $i++)
	{
		if(($i % 2) == 0)
		{
			print "<tr>";
		}
		print "<td bgcolor='black' onClick=\"location.href='http://ulin.kr/ulsanairsb/viewdetails.php?sname=".$stationName[$i]."'\" style='text-align:center; cursor:pointer;'>";
		print "<font color='white'><b>";
		print $stationName[$i];
		print "<br>";
		print "<ul id='ticker".$i."' class='ticker".$i."'>";
		if($check_mobile)
		{// 모바일
			print "<li>";
			print "미세먼지농도:";
			print levelColor($pm10Grade1h[$i], $pm10Value[$i], 1);
			print "<br>";
			print "미세먼지등급:";
			print exchangeGrade($pm10Grade1h[$i]);
			print "</li>";
			print "<li>";
			print "초미세먼지농도:";
			print levelColor($pm25Grade1h[$i], $pm25Value[$i], 1);
			print "<br>";
			print "초미세먼지등급:";
			print exchangeGrade($pm25Grade1h[$i]);
			print "</li>";
		}
		else
		{// PC
			print "<li>";
			print "미세먼지농도:";
			print levelColor($pm10Grade1h[$i], $pm10Value[$i], 1);
			print "미세먼지등급:";
			print exchangeGrade($pm10Grade1h[$i]);
			print "</li>";
			print "<li>";
			print "초미세먼지농도:";
			print levelColor($pm25Grade1h[$i], $pm25Value[$i], 1);
			print "초미세먼지등급:";
			print exchangeGrade($pm25Grade1h[$i]);
			print "</li>";
			print "<li>";
			print "아황산가스농도:";
			print levelColor($so2Grade[$i], $so2Value[$i], 2);
			print "아황산가스지수:";
			print exchangeGrade($so2Grade[$i]);
			print "</li>";
			print "<li>";
			print "일산화탄소농도:";
			print levelColor($coGrade[$i], $coValue[$i], 2);
			print "일산화탄소지수:";
			print exchangeGrade($coGrade[$i]);
			print "</li>";
			print "<li>";
			print "오존농도:";
			print levelColor($o3Grade[$i], $o3Value[$i], 2);
			print "오존지수:";
			print exchangeGrade($o3Grade[$i]);
			print "</li>";
			print "<li>";
			print "이산화질소농도:";
			print levelColor($no2Grade[$i], $no2Value[$i], 2);
			print "이산화질소지수:";
			print exchangeGrade($no2Grade[$i]);
			print "</li>";
			print "<li>";
			print "통합대기환경수치:";
			print levelColor($khaiGrade[$i], $khaiValue[$i], 0);
			print "통합대기환경지수:";
			print exchangeGrade($khaiGrade[$i]);
			print "</li>";
		}
		print "</ul>";
		print "</b></font>";
		print "</td>";
		if(($i % 2) == 1)
		{
			print "</tr>";
		}
	}
?>
<tr>
<td colspan = '2' align='center'>
	<font><b>데이터는 실시간 관측된 자료이며 측정소 현지 사정이나 데이터의 수신상태에 따라 미수신될 수 있습니다.
	<br>제공:환경부/한국환경공단</b></font>
</td>
</tr>
</table>
<script>
<?php
if($check_mobile)
{// 모바일
}
else
{// PC
	for($i = 0; $i < $totalCount; $i++)
	{
		print "function tick".$i."()";
		print "{";
		print "$('#ticker".$i." li:first').slideUp( function () { $(this).appendTo($('#ticker".$i."')).slideDown(); });";
		print "}";
		print "setInterval(function(){ tick".$i."() }, 5000);";
	}
}
?>
</script>
</body>
</html>