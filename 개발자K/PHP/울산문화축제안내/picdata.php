<?php

// 울산광역시 문화축제 사진 API
// URL 연결 및 XML 파싱 백엔드파트
// http://data.ulsan.go.kr/rest/ulsanfestival/getUlsanfestivalFile?PageNo=1&numOfRows=100&ulsanfestivalEntId=축제정보의 축제 고유번호&ServiceKey=데이터포털 인증키

include_once("infodata.php");

$picResponse = array();

for($i = 0; $i < $totalCount; $i++)
{
	$picCh = curl_init();
	// URL
	$picUrl = 'http://data.ulsan.go.kr/rest/ulsanfestival/getUlsanfestivalFile';
	// 서비스 키
	$picQueryParams = '?' . urlencode('ServiceKey') . '=' . $pdatakey;
	// 페이지 번호
	$picQueryParams .= '&' . urlencode('pageNo') . '=' . urlencode('1');
	// 한 페이지 결과 수
	$picQueryParams .= '&' . urlencode('numOfRows') . '=' . urlencode('100');
	// 축제 고유번호
	$picQueryParams .= '&' . urlencode('ulsanfestivalEntId') . '=' . urlencode($ulsanfestivalEntId[$i]);

	curl_setopt($picCh, CURLOPT_URL, $picUrl . $picQueryParams);
	curl_setopt($picCh, CURLOPT_RETURNTRANSFER, TRUE);
	curl_setopt($picCh, CURLOPT_HEADER, FALSE);
	curl_setopt($picCh, CURLOPT_CUSTOMREQUEST, 'GET');
	$picResponse[$i] = curl_exec($picCh);
	curl_close($picCh);
}

$picObject = array();
$picTotalCount = array();

$picFileOrgNm			= array();
$picFileRelNm			= array();
$picFileUrl				= array();
$picUlsanfestivalEntId	= array();
$picUlsanfestivalFileId	= array();

for($i = 0; $i < count($picResponse); $i++)
{
	$picObject[$i] = simplexml_load_string($picResponse[$i]);
	$picTotalCount[$i] = $picObject[$i]->body->totalCount;
	
	$picFileOrgNm[$i]			= array();	// 사진원본명
	$picFileRelNm[$i]			= array();	// 사진저장명
	$picFileUrl[$i]				= array();	// 사진URL
	$picUlsanfestivalEntId[$i]	= array();	// 축제 고유번호(축제 정보의 고유번호와 동일)
	$picUlsanfestivalFileId[$i]	= array();	// 사진번호
}

for($i = 0; $i < count($picResponse); $i++)
{
	for($a = 0; $a < $picTotalCount[$i]; $a++)
	{
		$picFileOrgNm[$i][$a]				= $picObject[$i]->body->data->list[$a]->fileOrgNm;
		$picFileRelNm[$i][$a]				= $picObject[$i]->body->data->list[$a]->fileRelNm;
		$picFileUrl[$i][$a]					= $picObject[$i]->body->data->list[$a]->fileUrl;
		$picUlsanfestivalEntId[$i][$a]		= $picObject[$i]->body->data->list[$a]->ulsanfestivalEntId;
		$picUlsanfestivalFileId[$i][$a]		= $picObject[$i]->body->data->list[$a]->ulsanfestivalFileId;
	}
}

?>