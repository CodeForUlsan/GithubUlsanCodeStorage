package com.zcs.ui;

import java.sql.Connection;
import java.util.ArrayList;
import java.util.Scanner;

import com.zcs.db.SqlDB;
import com.zcs.proc.ZipCodeBean;
import com.zcs.proc.ZipCodeProc;

public class Console {

	// �о�� �ؽ�Ʈ������ ��� ���ڿ�(�̸� �����ټ� ����)
	String txtFilePathGangwon = "D:\\ZipCodeDB\\20150508_������.txt";
	String txtfilePathGyeonggi = "D:\\ZipCodeDB\\20150508_��⵵.txt";
	String txtFilePathGyeongsangnam = "D:\\ZipCodeDB\\20150508_��󳲵�.txt";
	String txtFilePathGyeongsangbuk = "D:\\ZipCodeDB\\20150508_���ϵ�.txt";
	String txtFilePathGwangju = "D:\\ZipCodeDB\\20150508_���ֱ�����.txt";
	String txtFilePathDaegu = "D:\\ZipCodeDB\\20150508_�뱸������.txt";
	String txtFilePathDaejeon = "D:\\ZipCodeDB\\20150508_����������.txt";
	String txtFilePathBusan = "D:\\ZipCodeDB\\20150508_�λ걤����.txt";
	String txtFilePathSeoul = "D:\\ZipCodeDB\\20150508_����Ư����.txt";
	String txtFilePathSejong = "D:\\ZipCodeDB\\20150508_����Ư����ġ��.txt";
	String txtFilePathUlsan = "D:\\ZipCodeDB\\20150508_��걤����.txt";
	String txtFilePathIncheon = "D:\\ZipCodeDB\\20150508_��õ������.txt";
	String txtFilePathJeollanam = "D:\\ZipCodeDB\\20150508_���󳲵�.txt";
	String txtFilePathJeollabuk = "D:\\ZipCodeDB\\20150508_����ϵ�.txt";	
	String txtFilePathJeju = "D:\\ZipCodeDB\\20150508_����Ư����ġ��.txt";
	String txtFilePathChungcheongnam = "D:\\ZipCodeDB\\20150508_��û����.txt";
	String txtFilePathChungcheongbuk = "D:\\ZipCodeDB\\20150508_��û�ϵ�.txt";	

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
		
		String[] korCityName = {"����Ư����", "�λ걤����", "�뱸������", "��õ������", "���ֱ�����",
				"����������", "��걤����", "����Ư����ġ��", "������", "��⵵",
				"��󳲵�", "���ϵ�", "���󳲵�", "����ϵ�", "����Ư����ġ��",
				"��û����", "��û�ϵ�"};
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
		
		// ������ insert Ƚ�� ����
		int startCount = 0;
		int endCount = 1024;

		System.out.println("�����ȣ ������ üũ");
		rcount = sldb.recordCount("Ulsan");
		System.out.println("��� " + rcount);
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
		System.out.println("1. �����ȣ ã��");
		System.out.println("2. ���α׷� ����");
		System.out.print("- ����ϰ��� �ϴ� �޴��� ��ȣ�� �Է����ּ��� : ");
		if(scan.nextInt() == 2)
		{
			System.out.println("���α׷��� ����Ǿ����ϴ�.");
			System.exit(0);
		}

		while(true)
		{
			// �����ȣ ã�� �޴�ȭ��
			mainMenuNum = dp.menuDisplay(korCityName, selectCity, countryInput,
					villageInput, roadInput, searchOption,
					buildLotnumInput, buildRoadnumInput);
			switch(mainMenuNum)
			{
			case 1:
				// 1-1�� �޴� ����(�����ȣ ã�� - ��/�� �����ϱ�)
				selectCity = dp.citySelect(selectCity, korCityName, tableCityName);
				break;
			case 2:
				if(selectCity == 0)
				{
					System.out.println("�˻��� ��/���� ���� �������ּ���");
					break;
				}
				// - 1-2�� �޴� ����(�����ȣ ã�� - ��/��/�� �����ϱ�)
				countryList = sldb.getCountry(tableCityName[selectCity-1]);
				countryInput = dp.countrySelect(countryList, countryInput);
				break;
			case 3:
				if(countryInput == null)
				{
					System.out.println("�˻��� ��/��/���� ���� �������ּ���");
					break;
				}
				// - 1-3�� �޴� ����(�����ȣ ã�� - ��/��/��/�� �Է��ϱ�)
				System.out.println("�˻��� ����� �������ּ���");
				System.out.println("1. ��/��/��/���� �˻�");
				System.out.println("2. ���θ����� �˻�");
				searchOption = scan.nextInt();
				if(searchOption == 1)
				{
					System.out.print("�ش� �����ȣ�� ��/��/��/���� �Է����ּ��� : ");
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
					System.out.println("�ش� �����ȣ�� ���θ��� �Է����ּ��� : ");
					roadInput = scan.next();
					roadList = sldb.getRoadList(tableCityName[selectCity-1], countryInput, roadInput);
					dp.selectRoadList(roadList);
				}
				System.out.println();
				break;
			case 4:
				if((villageInput == null) && (roadInput == null))
				{
					System.out.println("�˻��� ��/��/��/���� ���� �Է����ּ���");
					break;
				}
				// - 1-4�� �޴� ����(�����ȣ ã�� - �󼼰˻� �Է��ϱ�)
				if(searchOption == 1)
				{
					System.out.print(korCityName[selectCity-1] + " " + 
							countryInput + " " + villageInput + "���� �˻��� �ǹ��̳� ������ �Է��ϼ��� : ");
					buildLotnumInput = scan.next();
					finResult = sldb.getBuildOrLotnumSearch("Ulsan", countryInput, villageInput, buildLotnumInput);
					dp.selectVillageList(finResult);
				}
				else if(searchOption == 2)
				{
					System.out.println(korCityName[selectCity-1] + " " +
							countryInput + " " + roadInput + "���� �˻��� �ǹ��̳� �ǹ���ȣ�� �Է��ϼ��� : ");
					buildRoadnumInput = scan.next();
					finResult = sldb.getBuildOrBuildnumSearch("Ulsan", countryInput, roadInput, buildRoadnumInput);
					dp.selectRoadList(finResult);
				}				

				System.out.println();
				if(searchOption == 1)
				{
					System.out.println("�����ּҸ� ���θ��ּҷ� �����Ͻðڽ��ϱ�?");
					System.out.println("1. ��");
					System.out.println("2. �ƴϿ�");
					System.out.println("3. ���θ�� �����ּҸ� ���� ǥ���Ѵ�.");
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
					System.out.println("���θ��ּҸ� �����ּҷ� �����Ͻðڽ��ϱ�?");
					System.out.println("1. ��");
					System.out.println("2. �ƴϿ�");
					System.out.println("3. ���θ�� �����ּҸ� ���� ǥ���Ѵ�.");
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
					System.out.println("�߸��� �����Դϴ�.");
				}
				System.out.println();
				break;
			case 5:
				// 262�� �������� �̵��Ͽ� ���α׷��� �����.
				break;
			default:
				System.out.println("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���.");
				System.out.println();
				break;
			}
			if(mainMenuNum == 5) // ���� �ڵ�
			{
				System.out.println("���α׷��� ����Ǿ����ϴ�.");
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
			System.out.println("���ῡ �����Ͽ����ϴ�.");
		}
		else
		{
			System.out.println("False");
		}
		sldb.closeCon();
	}
}
