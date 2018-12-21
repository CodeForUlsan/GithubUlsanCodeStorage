package com.zcs.proc;

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

public class ZipCodeBean {

	// 1. 우편번호 - zipcode
	private String zipcode;
	// 2. 시도 - city
	private String city;
	// 3. 시도영문 - cityEng
	private String cityEng;
	// 4. 시군구 - country
	private String country;
	// 5. 시군구영문 - countryEng
	private String countryEng;
	// 6. 읍면 - town
	private String town;
	// 7. 읍면영문 - townEng
	private String townEng;
	// 8. 도로명 - roadName
	private String roadName;
	// 9. 도로명영문 - roadNameEng
	private String roadNameEng;
	// 10. 건물번호본번 - buildNumberMain
	private String buildNumberMain;
	// 11. 건물번호부번 - buildNumberSub
	private String buildNumberSub;	
	// 12. 대량배달처명 - deliveryName
	private String deliveryName;
	// 13. 시군구용건물명 - buildName
	private String buildName;
	// 14. 법정동명 - villageName
	private String villageName;
	// 15. 리 - subTown
	private String subTown;
	// 16. 지번본번 - lotNumberMain
	private String lotNumberMain;
	// 17. 지번부번 - lotNumberSub
	private String lotNumberSub;

	public String getZipcode() {
		return zipcode;
	}
	public void setZipcode(String zipcode) {
		this.zipcode = zipcode;
	}
	public String getCity() {
		return city;
	}
	public void setCity(String city) {
		this.city = city;
	}
	public String getCityEng() {
		return cityEng;
	}
	public void setCityEng(String cityEng) {
		this.cityEng = cityEng;
	}
	public String getCountry() {
		return country;
	}
	public void setCountry(String country) {
		this.country = country;
	}
	public String getCountryEng() {
		return countryEng;
	}
	public void setCountryEng(String countryEng) {
		this.countryEng = countryEng;
	}
	public String getTown() {
		return town;
	}
	public void setTown(String town) {
		this.town = town;
	}
	public String getTownEng() {
		return townEng;
	}
	public void setTownEng(String townEng) {
		this.townEng = townEng;
	}
	public String getRoadName() {
		return roadName;
	}
	public void setRoadName(String roadName) {
		this.roadName = roadName;
	}
	public String getRoadNameEng() {
		return roadNameEng;
	}
	public void setRoadNameEng(String roadNameEng) {
		this.roadNameEng = roadNameEng;
	}
	public String getBuildNumberMain() {
		return buildNumberMain;
	}
	public void setBuildNumberMain(String buildNumberMain) {
		this.buildNumberMain = buildNumberMain;
	}
	public String getBuildNumberSub() {
		return buildNumberSub;
	}
	public void setBuildNumberSub(String buildNumberSub) {
		this.buildNumberSub = buildNumberSub;
	}
	public String getDeliveryName() {
		return deliveryName;
	}
	public void setDeliveryName(String deliveryName) {
		this.deliveryName = deliveryName;
	}
	public String getBuildName() {
		return buildName;
	}
	public void setBuildName(String buildName) {
		this.buildName = buildName;
	}
	public String getVillageName() {
		return villageName;
	}
	public void setVillageName(String villageName) {
		this.villageName = villageName;
	}
	public String getSubTown() {
		return subTown;
	}
	public void setSubTown(String subTown) {
		this.subTown = subTown;
	}
	public String getLotNumberMain() {
		return lotNumberMain;
	}
	public void setLotNumberMain(String lotNumberMain) {
		this.lotNumberMain = lotNumberMain;
	}
	public String getLotNumberSub() {
		return lotNumberSub;
	}
	public void setLotNumberSub(String lotNumberSub) {
		this.lotNumberSub = lotNumberSub;
	}
}