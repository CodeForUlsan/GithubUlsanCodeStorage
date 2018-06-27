<?php

// 공공데이터 포털 대기오염정보 조회 서비스
// URL 연결 및 XML 파싱 백엔드파트
// http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getCtprvnRltmMesureDnsty?numOfRows=100&pageNo=1&sidoName=울산&ver=1.3&ServiceKey=데이터포털 인증키

include_once("pdatakey.php"); // $pdatakey 변수에 저장된 키값이 넘어옴

$ch = curl_init();
// URL
$url = 'http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getCtprvnRltmMesureDnsty';
// 서비스 키
$queryParams = '?' . urlencode('ServiceKey') . '=' . $pdatakey;
// 한 페이지 결과 수
$queryParams .= '&' . urlencode('numOfRows') . '=' . urlencode('100');
// 페이지 번호
$queryParams .= '&' . urlencode('pageNo') . '=' . urlencode('1');
// 시도 이름 (서울, 부산, 대구, 인천, 광주, 대전, 울산, 경기, 강원, 충북, 충남, 전북, 전남, 경북, 경남, 제주, 세종)
$queryParams .= '&' . urlencode('sidoName') . '=' . urlencode('울산');
// 데이터 버젼 (1.0, 1.1, 1.2, 1.3)
$queryParams .= '&' . urlencode('ver') . '=' . urlencode('1.3');

curl_setopt($ch, CURLOPT_URL, $url . $queryParams);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
curl_setopt($ch, CURLOPT_HEADER, FALSE);
curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'GET');
$response = curl_exec($ch);
curl_close($ch);

$object = simplexml_load_string($response);

$totalCount = $object->body->totalCount;

$stationName	= array();
$mangName		= array();
$dataTime		= array();
$so2Value		= array();
$coValue		= array();
$o3Value		= array();
$no2Value		= array();
$pm10Value		= array();
$pm10Value24	= array();
$pm25Value		= array();
$pm25Value24	= array();
$khaiValue		= array();
$khaiGrade		= array();
$so2Grade		= array();
$coGrade		= array();
$o3Grade		= array();
$no2Grade		= array();
$pm10Grade		= array();
$pm25Grade		= array();
$pm10Grade1h	= array();
$pm25Grade1h	= array();

for($i = 0; $i < $totalCount; $i++)
{
	$stationName[$i]	= $object->body->items->item[$i]->stationName;	// 측정소 이름
	$mangName[$i]		= $object->body->items->item[$i]->mangName;		// 측정망 정보 (국가배경, 교외대기, 도시대기, 도로변대기)
	$dataTime[$i]		= $object->body->items->item[$i]->dataTime;		// 오염도 측정 연-월-일 시간 : 분
	$so2Value[$i]		= $object->body->items->item[$i]->so2Value;		// 아황산가스 농도(단위 : ppm)
	$coValue[$i]		= $object->body->items->item[$i]->coValue;		// 일산화탄소 농도(단위 : ppm)
	$o3Value[$i]		= $object->body->items->item[$i]->o3Value;		// 오존 농도(단위 : ppm)
	$no2Value[$i]		= $object->body->items->item[$i]->no2Value;		// 이산화질소 농도(단위 : ppm)
	$pm10Value[$i]		= $object->body->items->item[$i]->pm10Value;	// 미세먼지(PM10) 농도(단위 : ㎍/㎥)
	$pm10Value24[$i]	= $object->body->items->item[$i]->pm10Value24;	// 미세먼지(PM10) 24시간예측 이동농도(단위 : ㎍/㎥)
	$pm25Value[$i]		= $object->body->items->item[$i]->pm25Value;	// 미세먼지(PM2.5) 농도(단위 : ㎍/㎥)
	$pm25Value24[$i]	= $object->body->items->item[$i]->pm25Value24;	// 미세먼지(PM2.5) 24시간예측 이동농도(단위 : ㎍/㎥)
	$khaiValue[$i]		= $object->body->items->item[$i]->khaiValue;	// 통합대기환경수치
	$khaiGrade[$i]		= $object->body->items->item[$i]->khaiGrade;	// 통합대기환경지수
	$so2Grade[$i]		= $object->body->items->item[$i]->so2Grade;		// 아황산가스 지수
	$coGrade[$i]		= $object->body->items->item[$i]->coGrade;		// 일산화탄소 지수
	$o3Grade[$i]		= $object->body->items->item[$i]->o3Grade;		// 오존 지수
	$no2Grade[$i]		= $object->body->items->item[$i]->no2Grade;		// 이산화질소 지수
	$pm10Grade[$i]		= $object->body->items->item[$i]->pm10Grade;	// 미세먼지(PM10) 24시간 등급자료
	$pm25Grade[$i]		= $object->body->items->item[$i]->pm25Grade;	// 미세먼지(PM2.5) 24시간 등급자료
	$pm10Grade1h[$i]	= $object->body->items->item[$i]->pm10Grade1h;	// 미세먼지(PM10) 1시간 등급자료
	$pm25Grade1h[$i]	= $object->body->items->item[$i]->pm25Grade1h;	// 미세먼지(PM2.5) 1시간 등급자료
}

?>