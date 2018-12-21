<?php

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

// 공공데이터 포털 대기오염정보 조회 서비스
// 미세먼지 지수 및 등급 한글로 출력해주기 위한 기능 파트

// 지수, 등급자료의 경우 1 ~ 4로 표기.(1-좋음, 2-보통, 3-나쁨, 4-매우나쁨)

// 숫자로된 등급을 한글로 변환 및 색상표현
function exchangeGrade($grade)
{
	switch($grade)
	{
		case 1:
			$gradeKor = "<font style='color:lime'>좋음</font>";
			break;
		case 2:
			$gradeKor = "<font style='color:green'>보통</font>";
			break;
		case 3:
			$gradeKor = "<font style='color:orange'>나쁨</font>";
			break;
		case 4:
			$gradeKor = "<font style='color:red'>매우나쁨</font>";
			break;
		default:
			$gradeKor = "<font>없음</font>";
			break;
	}
	return $gradeKor;
}

// 등급에 따른 글자 색상을 지정하는 함수
function levelColor($grade, $value, $airTypeN)
{
	switch($grade)
	{
		case 1:// 좋음
			$returnValue = "<font style='color:lime'>".$value;
			break;
		case 2:// 보통
			$returnValue = "<font style='color:green'>".$value;
			break;
		case 3:// 나쁨
			$returnValue = "<font style='color:orange'>".$value;
			break;
		case 4:// 아주나쁨
			$returnValue = "<font style='color:red'>".$value;
			break;
		default:
			$returnValue = "<font>없음</font>";
			break;
	}
	if($grade <= 4 && strcmp($value, "-") == 1)
	{
		switch($airTypeN)
		{
			case 1:// 미세먼지(㎍/㎥)
				$returnValue = $returnValue."㎍/㎥";
				break;
			case 2:// 가스 등 화학물질(ppm)
				$returnValue = $returnValue."ppm";
				break;
			default:// 통합대기환경지수
				$returnValue = $returnValue;
				break;
		}
		$returnValue = $returnValue."</font>";
	}
	return $returnValue;
}
?>