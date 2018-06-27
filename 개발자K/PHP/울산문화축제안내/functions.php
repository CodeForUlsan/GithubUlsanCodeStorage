<?php

// 울산광역시 문화축제
// 함수 기능 파트

// 축제기간 표기 함수
function dtShow($startDt, $endDt)
{
	if(strcmp($startDt, ""))
	{
		if(strcmp($endDt, ""))
		{
			print "<b>축제기간 : </b>".$startDt." 부터 ".$endDt." 까지";
		}
		else
		{
			print "<b>축제시작일 : </b>".$startDt;
		}
		print "<br>";
	}
}

// 단일 변수용 표기 함수
function scriptShow($variable, $selector)
{
	if(strcmp($variable, ""))
	{
		print "<b>";
		switch($selector)
		{
			case 1: // 개최장소
				print "개최장소 : </b>".$variable;
				break;
			case 2: // 지번주소
				print "지번주소 : </b>".$variable;
				break;
			case 3: // 도로명주소
				print "도로명주소 : </b>".$variable;
				break;
			case 4: // 홈페이지 - a 태그 추가
				print "홈페이지 : </b><a href='".$variable."'>".$variable."</a>";
				break;
			case 5: // 주관기관
				print "주관기관 : </b>".$variable;
				break;
			case 6: // 주최기관
				print "주최기관 : </b>".$variable;
				break;
			case 7: // 연락처
				print "연락처 : </b>".$variable;
				break;
			case 8: // 후원기관
				print "후원기관 : </b>".$variable;
				break;
			case 9: // 관련정보
				print "관련정보 : </b>".$variable;
				break;
			default :
				print "";
				break;
		}
		print "<br>";
	}
}

?>