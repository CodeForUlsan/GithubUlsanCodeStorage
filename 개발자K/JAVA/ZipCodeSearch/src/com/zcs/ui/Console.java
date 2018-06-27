package com.zcs.ui;

import java.sql.Connection;
import java.util.ArrayList;
import java.util.Scanner;

import com.zcs.db.SqlDB;
import com.zcs.proc.ZipCodeBean;
import com.zcs.proc.ZipCodeProc;

public class Console {

	// 읽어올 텍스트문서의 경로 문자열(이름 가나다순 정렬)
	String txtFilePathGangwon = "D:\\ZipCodeDB\\20150508_강원도.txt";
	String txtfilePathGyeonggi = "D:\\ZipCodeDB\\20150508_경기도.txt";
	String txtFilePathGyeongsangnam = "D:\\ZipCodeDB\\20150508_경상남도.txt";
	String txtFilePathGyeongsangbuk = "D:\\ZipCodeDB\\20150508_경상북도.txt";
	String txtFilePathGwangju = "D:\\ZipCodeDB\\20150508_광주광역시.txt";
	String txtFilePathDaegu = "D:\\ZipCodeDB\\20150508_대구광역시.txt";
	String txtFilePathDaejeon = "D:\\ZipCodeDB\\20150508_대전광역시.txt";
	String txtFilePathBusan = "D:\\ZipCodeDB\\20150508_부산광역시.txt";
	String txtFilePathSeoul = "D:\\ZipCodeDB\\20150508_서울특별시.txt";
	String txtFilePathSejong = "D:\\ZipCodeDB\\20150508_세종특별자치시.txt";
	String txtFilePathUlsan = "D:\\ZipCodeDB\\20150508_울산광역시.txt";
	String txtFilePathIncheon = "D:\\ZipCodeDB\\20150508_인천광역시.txt";
	String txtFilePathJeollanam = "D:\\ZipCodeDB\\20150508_전라남도.txt";
	String txtFilePathJeollabuk = "D:\\ZipCodeDB\\20150508_전라북도.txt";	
	String txtFilePathJeju = "D:\\ZipCodeDB\\20150508_제주특별자치도.txt";
	String txtFilePathChungcheongnam = "D:\\ZipCodeDB\\20150508_충청남도.txt";
	String txtFilePathChungcheongbuk = "D:\\ZipCodeDB\\20150508_충청북도.txt";	

	public static void main(String[] args)
	{
		Console cs = new Console();
		Connection jdbcCon = null;
		SqlDB sldb = new SqlDB(jdbcCon);
		ZipCodeProc zcp = new ZipCodeProc();
		Display dp = new Display();
		ArrayList<ZipCodeBean> zipdata = new ArrayList<ZipCodeBean>();
		ArrayList<String> countryList = new ArrayList<String>();
		ArrayList<ZipCodeBean> villageTownList = new ArrayList<ZipCodeBean>();
		ArrayList<ZipCodeBean> roadList = new ArrayList<ZipCodeBean>();
		ArrayList<ZipCodeBean> finResult = new ArrayList<ZipCodeBean>();
		int rcount = 0;
		Scanner scan = new Scanner(System.in);
		
		String[] korCityName = {"서울특별시", "부산광역시", "대구광역시", "인천광역시", "광주광역시",
				"대전광역시", "울산광역시", "세종특별자치시", "강원도", "경기도",
				"경상남도", "경상북도", "전라남도", "전라북도", "제주특별자치도",
				"충청남도", "충청북도"};
		String[] tableCityName = {"Seoul", "Busan", "Deagu", "Incheon", "Gwangju",
				"Deajeon", "Ulsan", "Sejong", "Gangwon", "Gyeonggi",
				"Gyeonsangnam", "Gyeongsangbuk", "Jeollanam", "Jeollabuk", "Jeju",
				"Chungcheongnam", "Chungcheonbuk"};
		int selectCity = 0;
		String countryInput = null;
		String villageInput = null;
		String roadInput = null;
		String buildLotnumInput = null;
		String buildRoadnumInput = null;
		
		int mainMenuNum = 0;
		int searchOption = 0;
		int finListSelect = 0;
		
		// 데이터 insert 횟수 관련
		int startCount = 0;
		int endCount = 1024;

		System.out.println("우편번호 데이터 체크");
		rcount = sldb.recordCount("Ulsan");
		System.out.println("울산 " + rcount);
		//sldb.dataInsert(cs.txtFilePathGangwon, "Gangwon", zipdata);
		//sldb.dataInsert(cs.txtfilePathGyeonggi, "Gyeonggi", zipdata);
		//sldb.dataInsert(cs.txtFilePathGyeongsangnam, "Gyeongsangbuk", zipdata);
		//sldb.dataInsert(cs.txtFilePathGyeongsangbuk, "Gyeongsangbuk", zipdata);
	//	sldb.dataInsert(cs.txtFilePathGwangju, "Gwangju", zipdata);
	//	sldb.dataInsert(cs.txtFilePathDaegu, "Daegu", zipdata);
	//	sldb.dataInsert(cs.txtFilePathDaejeon, "Daejeon", zipdata);
		//sldb.dataInsert(cs.txtFilePathBusan, "Busan", zipdata);
		//sldb.dataInsert(cs.txtFilePathSeoul, "Seoul", zipdata);
	//	sldb.dataInsert(cs.txtFilePathSejong, "Sejong", zipdata);
		for(int i = 0; i < 97; i++)
		{
			if(rcount == zcp.fileLineCount(cs.txtFilePathUlsan))
			{
				break;
			}
			zipdata = zcp.readToFile(cs.txtFilePathUlsan, startCount, endCount);
			sldb.dataInsert("Ulsan", zipdata);
			zipdata.removeAll(zipdata);
			startCount = startCount + 1024;
			endCount = endCount + 1024;			
		}
	//	sldb.dataInsert(cs.txtFilePathIncheon, "Incheon", zipdata);
		//sldb.dataInsert(cs.txtFilePathJeollanam, "Jeollanam", zipdata);
		//sldb.dataInsert(cs.txtFilePathJeollabuk, "Jeollabuk", zipdata);
	//	sldb.dataInsert(cs.txtFilePathJeju, "Jeju", zipdata);
		//sldb.dataInsert(cs.txtFilePathChungcheongnam, "Chungcheongnam", zipdata);
		//sldb.dataInsert(cs.txtFilePathChungcheongbuk, "Chungcheongbuk", zipdata);


		System.out.println("ZipCode Ver C-20150519b");
		System.out.println("1. 우편번호 찾기");
		System.out.println("2. 프로그램 종료");
		System.out.print("- 사용하고자 하는 메뉴의 번호를 입력해주세요 : ");
		if(scan.nextInt() == 2)
		{
			System.out.println("프로그램이 종료되었습니다.");
			System.exit(0);
		}

		while(true)
		{
			// 우편번호 찾기 메뉴화면
			mainMenuNum = dp.menuDisplay(korCityName, selectCity, countryInput,
					villageInput, roadInput, searchOption,
					buildLotnumInput, buildRoadnumInput);
			switch(mainMenuNum)
			{
			case 1:
				// 1-1번 메뉴 구성(우편번호 찾기 - 시/도 선택하기)
				selectCity = dp.citySelect(selectCity, korCityName, tableCityName);
				break;
			case 2:
				if(selectCity == 0)
				{
					System.out.println("검색할 시/도를 먼저 선택해주세요");
					break;
				}
				// - 1-2번 메뉴 구성(우편번호 찾기 - 시/구/군 선택하기)
				countryList = sldb.getCountry(tableCityName[selectCity-1]);
				countryInput = dp.countrySelect(countryList, countryInput);
				break;
			case 3:
				if(countryInput == null)
				{
					System.out.println("검색할 시/군/구를 먼저 선택해주세요");
					break;
				}
				// - 1-3번 메뉴 구성(우편번호 찾기 - 읍/면/동/리 입력하기)
				System.out.println("검색할 방법을 선택해주세요");
				System.out.println("1. 읍/면/동/리로 검색");
				System.out.println("2. 도로명으로 검색");
				searchOption = scan.nextInt();
				if(searchOption == 1)
				{
					System.out.print("해당 우편번호의 읍/면/동/리를 입력해주세요 : ");
					villageInput = scan.next();
					villageTownList = sldb.getVillageList(tableCityName[selectCity-1], countryInput, villageInput);
					dp.selectVillageList(villageTownList);
					/*for(int i = 0; i < townList.size(); i++)
					{
						System.out.print(townList.get(i).getZipcode() + " ");
						System.out.print(townList.get(i).getCity() + " ");
						System.out.print(townList.get(i).getCityEng() + " ");
						System.out.print(townList.get(i).getCountry() + " ");
						System.out.print(townList.get(i).getCountryEng() + " ");
						System.out.print(townList.get(i).getTown() + " ");
						System.out.print(townList.get(i).getTownEng() + " ");
						System.out.print(townList.get(i).getRoadName() + " ");
						System.out.print(townList.get(i).getRoadNameEng() + " ");
						System.out.print(townList.get(i).getDeliveryName() + " ");
						System.out.print(townList.get(i).getBuildName() + " ");
						System.out.print(townList.get(i).getVillageName() + " ");
						System.out.print(townList.get(i).getSubTown() + " ");
						System.out.print(townList.get(i).getLotNumberMain() + " ");
						System.out.println(townList.get(i).getLotNumberSub());
					}*/	
				}
				else if(searchOption == 2)
				{
					System.out.println("해당 우편번호의 도로명을 입력해주세요 : ");
					roadInput = scan.next();
					roadList = sldb.getRoadList(tableCityName[selectCity-1], countryInput, roadInput);
					dp.selectRoadList(roadList);
				}
				System.out.println();
				break;
			case 4:
				if((villageInput == null) && (roadInput == null))
				{
					System.out.println("검색할 읍/면/동/리를 먼저 입력해주세요");
					break;
				}
				// - 1-4번 메뉴 구성(우편번호 찾기 - 상세검색 입력하기)
				if(searchOption == 1)
				{
					System.out.print(korCityName[selectCity-1] + " " + 
							countryInput + " " + villageInput + "에서 검색할 건물이나 지번을 입력하세요 : ");
					buildLotnumInput = scan.next();
					finResult = sldb.getBuildOrLotnumSearch("Ulsan", countryInput, villageInput, buildLotnumInput);
					dp.selectVillageList(finResult);
				}
				else if(searchOption == 2)
				{
					System.out.println(korCityName[selectCity-1] + " " +
							countryInput + " " + roadInput + "에서 검색할 건물이나 건물번호을 입력하세요 : ");
					buildRoadnumInput = scan.next();
					finResult = sldb.getBuildOrBuildnumSearch("Ulsan", countryInput, roadInput, buildRoadnumInput);
					dp.selectRoadList(finResult);
				}				

				System.out.println();
				if(searchOption == 1)
				{
					System.out.println("지번주소를 도로명주소로 변경하시겠습니까?");
					System.out.println("1. 예");
					System.out.println("2. 아니오");
					System.out.println("3. 도로명과 지번주소를 같이 표시한다.");
					finListSelect = scan.nextInt();
					if(finListSelect == 1)
					{
						dp.selectRoadList(finResult);
					}
					else if(finListSelect == 3)
					{
						dp.allDisplay(finResult);
					}
				}
				else if(searchOption == 2)
				{
					System.out.println("도로명주소를 지번주소로 변경하시겠습니까?");
					System.out.println("1. 예");
					System.out.println("2. 아니오");
					System.out.println("3. 도로명과 지번주소를 같이 표시한다.");
					finListSelect = scan.nextInt();
					if(finListSelect == 1)
					{
						dp.selectVillageList(finResult);
					}
					else if(finListSelect == 3)
					{
						dp.allDisplay(finResult);
					}
				}
				else
				{
					System.out.println("잘못된 접근입니다.");
				}
				System.out.println();
				break;
			case 5:
				// 262번 라인으로 이동하여 프로그램이 종료됨.
				break;
			default:
				System.out.println("잘못 입력하였습니다. 다시 입력해주세요.");
				System.out.println();
				break;
			}
			if(mainMenuNum == 5) // 종료 코드
			{
				System.out.println("프로그램이 종료되었습니다.");
				break;
			}
		}
		scan.close();
		sldb.closeCon();
	}
	
	public void dbConnectTest()
	{
		Connection con = null;
		SqlDB sldb = new SqlDB(con);
		con = sldb.getConnection();

		if(con != null)
		{
			System.out.println("연결에 성공하였습니다.");
		}
		else
		{
			System.out.println("False");
		}
		sldb.closeCon();
	}
}
