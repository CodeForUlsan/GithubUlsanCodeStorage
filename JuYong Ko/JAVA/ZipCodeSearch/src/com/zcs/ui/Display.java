package com.zcs.ui;

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

import java.util.ArrayList;
import java.util.Scanner;

import com.zcs.proc.ZipCodeBean;

public class Display {
	
	Scanner scan = new Scanner(System.in);
	
	public int menuDisplay(String[] korCityName, int selectCity, String countryInput,
			String villageInput, String roadInput, int searchOption,
			String buildLotnumInput, String buildRoadnumInput)
	{
		// 사용자가 값을 입력하고 난뒤에 실행될 화면
		System.out.println("찾고자 하는 범위");
		if(selectCity == 0)
		{
			System.out.println("시/도 : "); // 선택되지 않음
		}
		else
		{
			System.out.println("시/도 : " + korCityName[selectCity-1]); // 사용자 입력을 통해 변함
		}
		if(countryInput == null)
		{
			System.out.println("시/구/군 : "); // 선택되지 않음
		}
		else
		{
			System.out.println("시/구/군 : " + countryInput); // 사용자 입력을 통해서 변함
		}
		if((villageInput == null) && (roadInput == null))
		{
			System.out.println("검색옵션을 선택해주세요");
		}
		else
		{
			if(searchOption == 1)
			{
				System.out.println("읍/면/동/리 : " + villageInput); // 사용자 입력을 통해서 변함
			}
			else if(searchOption == 2)
			{
				System.out.println("도로명 : " + roadInput);
			}
			else
			{
				System.out.println("검색옵션을 선택해주세요");
			}
		}
		if((buildLotnumInput == null) && (buildRoadnumInput == null))
		{
			System.out.println("상세 검색 : ");
		}
		else
		{
			if(searchOption == 1)
			{
				System.out.println("상세 검색 : " + buildLotnumInput); // 사용자 입력을 통해서 변함
			}
			else if(searchOption == 2)
			{
				System.out.println("상세 검색 : " + buildRoadnumInput);
			}
			else
			{
				System.out.println("상세 검색 : ");
			}
		}
		System.out.println();
		System.out.println("메뉴를 선택해주세요.");
		System.out.println("1. 시/도 입력 및 변경하기");
		System.out.println("2. 시/구/군 입력 및 변경하기");
		if(searchOption == 1)
		{
			System.out.println("3. 읍/면/동/리 입력 및 변경하기");
		}
		else if(searchOption == 2)
		{
			System.out.println("3. 도로명 입력 및 변경하기");
		}
		else
		{
			System.out.println("3. 읍/면/동/리 or 도로명 입력 및 변경하기");
		}
		System.out.println("4. 상세 검색(지번이나 건물명을 입력해주세요[ex:현대해상 or 137])");
		System.out.println("5. 종료하기");
		System.out.println(" - 사용하고자 하는 메뉴의 번호를 입력해주세요 : ");
		return scan.nextInt();
	}
	
	public int citySelect(int selectCity, String[] korCityName, String[] tableCityName)
	{
		// 1-1번 메뉴 구성(우편번호 찾기 - 시/도 선택하기)
		System.out.println("찾고자하는 우편번호가 있는 시/도를 선택해주세요 : ");
		System.out.println("1. 서울특별시 2. 부산광역시 3. 대구광역시 4. 인천광역시 5. 광주광역시");
		System.out.println("6. 대전광역시 7. 울산광역시 8. 세종특별자치시 9. 강원도 10. 경기도");
		System.out.println("11. 경상남도 12. 경상북도 13. 전라남도 14. 전라북도 15. 제주특별자치도");
		System.out.println("16. 충청남도 17. 충청북도");
		selectCity = scan.nextInt();
		//System.out.println("선택한 도시는 " + korCityName[selectCity-1] + "입니다.");
		//System.out.println("you're Selected City is " + tableCityName[selectCity-1]);
		return selectCity;
	}
	
	public String countrySelect(ArrayList<String> countryList, String countryInput)
	{
		// - 1-2번 메뉴 구성(우편번호 찾기 - 시/구/군 선택하기)
		System.out.println("해당 우편번호의 시/구/군을 선택해주세요");
		for(int i = 0; i < countryList.size(); i++)
		{
			System.out.println((i+1) + ". " + countryList.get(i));
		}
		System.out.println("숫자 입력 : ");
		countryInput = countryList.get(scan.nextInt()-1);
		System.out.println("선택한 시/군/구는 " + countryInput);
		return countryInput;
	}
	
	public void selectVillageList(ArrayList<ZipCodeBean> villageList)
	{
		// - 1-3a번 메뉴 구성(우편번호 찾기 - 읍/면/동/리 입력하기)
		for(int i = 0; i < villageList.size(); i++)
		{
			System.out.print(villageList.get(i).getZipcode() + " ");
			System.out.print(villageList.get(i).getCity() + " ");
			System.out.print(villageList.get(i).getCityEng() + " ");
			System.out.print(villageList.get(i).getCountry() + " ");
			System.out.print(villageList.get(i).getCountryEng() + " ");
			System.out.print(villageList.get(i).getTown() + " ");
			System.out.print(villageList.get(i).getTownEng() + " ");
			System.out.print(villageList.get(i).getVillageName() + " ");
			System.out.print(villageList.get(i).getSubTown() + " ");
			System.out.print(villageList.get(i).getLotNumberMain() + "-");
			System.out.print(villageList.get(i).getLotNumberSub() + " ");
			System.out.print(villageList.get(i).getDeliveryName() + " ");
			System.out.println(villageList.get(i).getBuildName() + " ");
		}
	}
	
	public void selectRoadList(ArrayList<ZipCodeBean> roadList)
	{
		// - 1-3b번 메뉴 구성(우편번호 찾기 - 도로명 입력하기)
		for(int i = 0; i < roadList.size(); i++)
		{
			System.out.print(roadList.get(i).getZipcode() + " ");
			System.out.print(roadList.get(i).getCity() + " ");
			System.out.print(roadList.get(i).getCityEng() + " ");
			System.out.print(roadList.get(i).getCountry() + " ");
			System.out.print(roadList.get(i).getCountryEng() + " ");
			System.out.print(roadList.get(i).getRoadName() + " ");
			System.out.print(roadList.get(i).getRoadNameEng() + " ");
			System.out.print(roadList.get(i).getBuildNumberMain() + "-");
			System.out.print(roadList.get(i).getBuildNumberSub() + " ");
			System.out.print(roadList.get(i).getDeliveryName() + " ");
			System.out.println(roadList.get(i).getBuildName() + " ");
		}
	}
	
	public void allDisplay(ArrayList<ZipCodeBean> allList)
	{
		for(int i = 0; i < allList.size(); i++)
		{
			System.out.print(allList.get(i).getZipcode() + " ");
			System.out.print(allList.get(i).getCity() + " ");
			System.out.print(allList.get(i).getCityEng() + " ");
			System.out.print(allList.get(i).getCountry() + " ");
			System.out.print(allList.get(i).getCountryEng() + " ");
			System.out.print(allList.get(i).getTown() + " ");
			System.out.print(allList.get(i).getTownEng() + " ");
			System.out.print(allList.get(i).getRoadName() + " " );
			System.out.print(allList.get(i).getRoadNameEng() + " ");
			System.out.print(allList.get(i).getBuildNumberMain() + "-");
			System.out.print(allList.get(i).getBuildNumberSub() + " ");
			System.out.print(allList.get(i).getDeliveryName() + " ");
			System.out.print(allList.get(i).getBuildName() + " ");
			System.out.print(allList.get(i).getVillageName() + " ");
			System.out.print(allList.get(i).getSubTown() + " ");
			System.out.print(allList.get(i).getLotNumberMain() + "-");
			System.out.println(allList.get(i).getLotNumberSub());
		}
	}
}