<?php

// 울산광역시 문화축제
// HTML, CSS, 자바스크립트 프론트엔드 파트
// 메인화면

include_once("picdata.php");

?>

<html>
<head>
<meta http-equiv='Content-Type' content='text/html;charset=utf-8'>
<meta http-equiv='X-UA-Compatible' content='IE=edge'>
<meta name='viewport' content='user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, width=device-width, height=device-height'>
<link rel='stylesheet'  href='fonts.css'></link>
<script src='http://code.jquery.com/jquery-latest.js'></script>
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
a:link{
	color: white;
	text-decoration: none;
}
a:visited{
	color: white;
	text-decoration: none;
}
a:hover{
	color: white;
	text-decoration: none;
}
</style>
</head>
<body style='margin:0; padding:0;'>
<table width='100%' height='100%' border='1'>
<?php
	for($i = 0; $i < $totalCount; $i++)
	{
		if(($i % 2) == 0)
		{
			print "<tr>";
		}
		print "<td bgcolor='black' onClick=\"location.href='http://ulin.kr/ulsanfestival/eventpage.php?fname=".$ulsanfestivalTitle[$i]."'\" style='text-align:center; cursor:pointer;'>";
		print "<font color='white'><b>";
		print $ulsanfestivalTitle[$i];
		print "<br>";
		if(strcmp($ulsanfestivalStartDt[$i], ""))
		{
			print $ulsanfestivalStartDt[$i];
			print " ~ ";
			if(strcmp($ulsanfestivalEndDt[$i], ""))
			{
				print $ulsanfestivalEndDt[$i];
			}
			print "<br>";
		}
		print "</b></font>";
		print "</td>";
		if(($i % 2) == 1)
		{
			print "</tr>";
		}
	}
?>
<tr>
<td colspan='2' onClick="location.href='http://ulin.kr'" style='text-align:center; cursor:pointer;'>
http://ulin.kr로 이동
</td>
</tr>
</table>
</body>
</html>