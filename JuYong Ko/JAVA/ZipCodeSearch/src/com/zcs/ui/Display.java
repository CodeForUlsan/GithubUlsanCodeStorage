package com.zcs.ui;

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
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
		// ����ڰ� ���� �Է��ϰ� ���ڿ� ����� ȭ��
		System.out.println("ã���� �ϴ� ����");
		if(selectCity == 0)
		{
			System.out.println("��/�� : "); // ���õ��� ����
		}
		else
		{
			System.out.println("��/�� : " + korCityName[selectCity-1]); // ����� �Է��� ���� ����
		}
		if(countryInput == null)
		{
			System.out.println("��/��/�� : "); // ���õ��� ����
		}
		else
		{
			System.out.println("��/��/�� : " + countryInput); // ����� �Է��� ���ؼ� ����
		}
		if((villageInput == null) && (roadInput == null))
		{
			System.out.println("�˻��ɼ��� �������ּ���");
		}
		else
		{
			if(searchOption == 1)
			{
				System.out.println("��/��/��/�� : " + villageInput); // ����� �Է��� ���ؼ� ����
			}
			else if(searchOption == 2)
			{
				System.out.println("���θ� : " + roadInput);
			}
			else
			{
				System.out.println("�˻��ɼ��� �������ּ���");
			}
		}
		if((buildLotnumInput == null) && (buildRoadnumInput == null))
		{
			System.out.println("�� �˻� : ");
		}
		else
		{
			if(searchOption == 1)
			{
				System.out.println("�� �˻� : " + buildLotnumInput); // ����� �Է��� ���ؼ� ����
			}
			else if(searchOption == 2)
			{
				System.out.println("�� �˻� : " + buildRoadnumInput);
			}
			else
			{
				System.out.println("�� �˻� : ");
			}
		}
		System.out.println();
		System.out.println("�޴��� �������ּ���.");
		System.out.println("1. ��/�� �Է� �� �����ϱ�");
		System.out.println("2. ��/��/�� �Է� �� �����ϱ�");
		if(searchOption == 1)
		{
			System.out.println("3. ��/��/��/�� �Է� �� �����ϱ�");
		}
		else if(searchOption == 2)
		{
			System.out.println("3. ���θ� �Է� �� �����ϱ�");
		}
		else
		{
			System.out.println("3. ��/��/��/�� or ���θ� �Է� �� �����ϱ�");
		}
		System.out.println("4. �� �˻�(�����̳� �ǹ����� �Է����ּ���[ex:�����ػ� or 137])");
		System.out.println("5. �����ϱ�");
		System.out.println(" - ����ϰ��� �ϴ� �޴��� ��ȣ�� �Է����ּ��� : ");
		return scan.nextInt();
	}
	
	public int citySelect(int selectCity, String[] korCityName, String[] tableCityName)
	{
		// 1-1�� �޴� ����(�����ȣ ã�� - ��/�� �����ϱ�)
		System.out.println("ã�����ϴ� �����ȣ�� �ִ� ��/���� �������ּ��� : ");
		System.out.println("1. ����Ư���� 2. �λ걤���� 3. �뱸������ 4. ��õ������ 5. ���ֱ�����");
		System.out.println("6. ���������� 7. ��걤���� 8. ����Ư����ġ�� 9. ������ 10. ��⵵");
		System.out.println("11. ��󳲵� 12. ���ϵ� 13. ���󳲵� 14. ����ϵ� 15. ����Ư����ġ��");
		System.out.println("16. ��û���� 17. ��û�ϵ�");
		selectCity = scan.nextInt();
		//System.out.println("������ ���ô� " + korCityName[selectCity-1] + "�Դϴ�.");
		//System.out.println("you're Selected City is " + tableCityName[selectCity-1]);
		return selectCity;
	}
	
	public String countrySelect(ArrayList<String> countryList, String countryInput)
	{
		// - 1-2�� �޴� ����(�����ȣ ã�� - ��/��/�� �����ϱ�)
		System.out.println("�ش� �����ȣ�� ��/��/���� �������ּ���");
		for(int i = 0; i < countryList.size(); i++)
		{
			System.out.println((i+1) + ". " + countryList.get(i));
		}
		System.out.println("���� �Է� : ");
		countryInput = countryList.get(scan.nextInt()-1);
		System.out.println("������ ��/��/���� " + countryInput);
		return countryInput;
	}
	
	public void selectVillageList(ArrayList<ZipCodeBean> villageList)
	{
		// - 1-3a�� �޴� ����(�����ȣ ã�� - ��/��/��/�� �Է��ϱ�)
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
		// - 1-3b�� �޴� ����(�����ȣ ã�� - ���θ� �Է��ϱ�)
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