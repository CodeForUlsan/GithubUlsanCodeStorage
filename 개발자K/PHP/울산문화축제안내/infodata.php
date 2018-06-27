<?php

// 울산광역시 문화축제 API
// URL 연결 및 XML 파싱 백엔드파트\
// http://data.ulsan.go.kr/rest/ulsanfestival/getUlsanfestivalList?PageNo=1&numOfRows=100&ServiceKey=데이터포털 인증키

include_once("pdatakey.php"); // $pdatakey 변수에 저장된 키값이 넘어옴

$ch = curl_init();
// URL
$url = 'http://data.ulsan.go.kr/rest/ulsanfestival/getUlsanfestivalList';
// 서비스 키
$queryParams = '?' . urlencode('ServiceKey') . '=' . $pdatakey;
// 페이지 번호
$queryParams .= '&' . urlencode('pageNo') . '=' . urlencode('1');
// 한 페이지 결과 수
$queryParams .= '&' . urlencode('numOfRows') . '=' . urlencode('100');

curl_setopt($ch, CURLOPT_URL, $url . $queryParams);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
curl_setopt($ch, CURLOPT_HEADER, FALSE);
curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'GET');
$response = curl_exec($ch);
curl_close($ch);

$object = simplexml_load_string($response);

$totalCount = $object->body->totalCount;

$ulsanfestivalAddr		= array();
$ulsanfestivalContents	= array();
$ulsanfestivalEndDt		= array();
$ulsanfestivalEntId		= array();
$ulsanfestivalHP		= array();
$ulsanfestivalHost		= array();
$ulsanfestivalInfo		= array();
$ulsanfestivalNewAddr	= array();
$ulsanfestivalPlace		= array();
$ulsanfestivalRegDt		= array();
$ulsanfestivalStartDt	= array();
$ulsanfestivalSupervise	= array();
$ulsanfestivalTel		= array();
$ulsanfestivalTitle		= array();
$ulsanfestivalXpos		= array();
$ulsanfestivalYpos		= array();
$ulsanfestivalSupport	= array();

for($i = 0; $i < $totalCount; $i++)
{
	$ulsanfestivalAddr[$i]		= $object->body->data->list[$i]->ulsanfestivalAddr;		// 소재지지번주소
	$ulsanfestivalContents[$i]	= $object->body->data->list[$i]->ulsanfestivalContents;	// 축제내용
	$ulsanfestivalEndDt[$i]		= $object->body->data->list[$i]->ulsanfestivalEndDt;	// 축제종료일자
	$ulsanfestivalEntId[$i]		= $object->body->data->list[$i]->ulsanfestivalEntId;	// 고유번호
	$ulsanfestivalHP[$i]		= $object->body->data->list[$i]->ulsanfestivalHP;		// 홈페이지주소
	$ulsanfestivalHost[$i]		= $object->body->data->list[$i]->ulsanfestivalHost;		// 주최기관
	$ulsanfestivalInfo[$i]		= $object->body->data->list[$i]->ulsanfestivalInfo;		// 관련정보
	$ulsanfestivalNewAddr[$i]	= $object->body->data->list[$i]->ulsanfestivalNewAddr;	// 소재지도로명주소
	$ulsanfestivalPlace[$i]		= $object->body->data->list[$i]->ulsanfestivalPlace;	// 개최장소
	$ulsanfestivalRegDt[$i]		= $object->body->data->list[$i]->ulsanfestivalRegDt;	// 데이터기준일자
	$ulsanfestivalStartDt[$i]	= $object->body->data->list[$i]->ulsanfestivalStartDt;	// 축제시작일자
	$ulsanfestivalSupervise[$i]	= $object->body->data->list[$i]->ulsanfestivalSupervise;// 주관기관
	$ulsanfestivalTel[$i]		= $object->body->data->list[$i]->ulsanfestivalTel;		// 연락처
	$ulsanfestivalTitle[$i]		= $object->body->data->list[$i]->ulsanfestivalTitle;	// 축제명
	$ulsanfestivalXpos[$i]		= $object->body->data->list[$i]->ulsanfestivalXpos;		// 경도
	$ulsanfestivalYpos[$i]		= $object->body->data->list[$i]->ulsanfestivalYpos;		// 위도
	$ulsanfestivalSupport[$i]	= $object->body->data->list[$i]->ulsanfestivalSupport;	// 후원기관
}

?>

