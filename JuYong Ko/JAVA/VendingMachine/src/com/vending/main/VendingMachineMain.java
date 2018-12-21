package com.vending.main;

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

import java.util.Scanner;

import com.vending.admin.VendingAdminProc;
import com.vending.calc.VendingCalcProc;
import com.vending.display.VendingDisplayProc;
import com.vending.files.VendingFileProc;

public class VendingMachineMain {
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		String[] drink = {"ĥ�����̴�", "��ī�ݶ�", "��������Ʈ", "��Ű��", "�Ϲٻ�"}; // ���� ��ǰ ���ڿ� �迭[default]
		String adminPassword = "admin";
		int[] drinkStock = {100, 100, 100, 100, 100}; // ���� ��ǰ ��� ������ �迭
		int[] drinkPrice = {700, 800, 900, 600, 500}; // ���� �Ǹ� ���� ������ �迭
		int[] coinType = {1000, 500, 100, 50, 10}; // ���� ������ ��밡���� �ݾ� ���� ������ �迭
		int[] coinStock = {0, 100, 100, 100, 100}; // ���Ǳ⿡�� �Ž��� �ټ��ִ� �� �ݾ׺� �ܵ� ���� ������ �迭
		int payStock = 0; // ����ڰ� ��ǰ�� ���ýÿ� ���ݰ����� �Ұ�� ���Ǳ⿡�� �ްų� �Ž�������� �ݾ��� �ӽ÷� ������ ����
		int addingPay = 0; // ����ڰ� �߰��� �ݾ��� ���������� �ӽ÷� ������ ������ ����
		int payCheck = 0; // �Ž����� �� �ݾ��� �ӽ÷� �����ϰ� �Ž������� �ɷ��ټ��ִ� üũ�ϴµ� Ȱ��� ������ ����
		
		VendingAdminProc vap = new VendingAdminProc();
		VendingCalcProc vcp = new VendingCalcProc();
		VendingDisplayProc vdp = new VendingDisplayProc();
		VendingFileProc vfp = new VendingFileProc();
		

		
		if(vfp.getDrinkFile().exists() == false)
		{
			vfp.writeFileToDrink(drink, vfp.getDrinkFile());
		}
		else
		{
			vfp.drinkTypeToFile(drink, vfp.getDrinkFile());
		}
		
		if(vfp.getDrinkStockFile().exists() == false)
		{
			vfp.writeFileToDrinkStock(drinkStock, vfp.getDrinkStockFile());
		}
		else
		{
			vfp.drinkStockToFile(drinkStock, vfp.getDrinkStockFile());
		}
		
		if(vfp.getDrinkPriceFile().exists() == false)
		{
			vfp.writeFileToDrinkPrice(drinkPrice, vfp.getDrinkPriceFile());
		}
		else
		{
			vfp.drinkPriceToFile(drinkPrice, vfp.getDrinkPriceFile());
		}
		
		if(vfp.getCoinStockFile().exists() == false)
		{
			vfp.writeFileToCoinStock(coinStock, vfp.getCoinStockFile());
		}
		else
		{
			vfp.coinStockToFile(coinStock, vfp.getCoinStockFile());
		}
		
		if(vfp.getAdminPasswordFile().exists() == false)
		{
			vfp.writeFileToAdminPassword(adminPassword, vfp.getAdminPasswordFile());			
		}
		else
		{
			adminPassword = vfp.adminPasswordToFile(adminPassword, vfp.getAdminPasswordFile());
		}

		while(true)
		{
			int menuSelect = 0; // ����ڰ� �޴��� ������ ���� �ӽ÷� ������ ����
			System.out.println("<\t��\t��\t��\t>");
			vdp.menuDisplay(drink, drinkStock, drinkPrice, payStock);
			System.out.println("1. ���� ����");
			System.out.println("2. ���� ��ȯ");
			System.out.println("3. ��ǰ ����");
			System.out.println("4. ���Ǳ� ����");
			System.out.println("5. ���α׷� ����");
			System.out.print("�޴��� �������ּ��� : ");
			menuSelect = scan.nextInt();
			System.out.println();
			vdp.clearScreen();
			if(menuSelect==1)
			{
				vdp.menuDisplay(drink, drinkStock, drinkPrice, payStock);
				System.out.println("<\t��\t��\t��\t��\t>");
				System.out.print("������ �ݾ��� �Է����ּ��� : ");
				addingPay = scan.nextInt();
				payStock = payStock + addingPay;
				System.out.println();
				vdp.clearScreen();
			}
			else if(menuSelect==2)
			{
				System.out.println("<\t��\t��\t��\tȯ\t>");
				System.out.println(payStock + "���� ��ȯ�Ǿ����ϴ�.");
				System.out.println();				
				for(int i = 0; i < coinType.length; i++)
				{
					coinStock[i] = vcp.changeCalculator(coinType[i], coinStock[i], payStock, i);
					payStock = vcp.payCalculator(payStock, coinType[i], coinStock[i]);
				}				
			}
			else if(menuSelect==3)
			{
				while(true)
				{						
					vdp.purchaseMenuDisplay(drink, drinkPrice, drinkStock, payStock);
					System.out.print("��ǰ�� ������ �ּ��� : ");
					int drinkSelect = scan.nextInt();
					vdp.clearScreen();
					payCheck = payStock;
					for(int i = 0; i < coinType.length; i++)
					{
						payCheck = payCheck - (coinType[i] * coinStock[i]);
					}					
					if(payCheck > 0)
					{
						System.out.println("�Ž������� �����մϴ�. �����ڿ��� ���� �ϼ���.");
						vdp.lineDisplay();
						break;
					}
					if(drinkSelect==1)
					{
						payStock = vcp.payCheck(drinkStock, drinkSelect, drink, drinkPrice, payStock);
					}
					else if(drinkSelect==2)
					{
						payStock = vcp.payCheck(drinkStock, drinkSelect, drink, drinkPrice, payStock);
					}
					else if(drinkSelect==3)
					{
						payStock = vcp.payCheck(drinkStock, drinkSelect, drink, drinkPrice, payStock);
					}
					else if(drinkSelect==4)
					{
						payStock = vcp.payCheck(drinkStock, drinkSelect, drink, drinkPrice, payStock);
					}
					else if(drinkSelect==5)
					{
						payStock = vcp.payCheck(drinkStock, drinkSelect, drink, drinkPrice, payStock);
					}
					vdp.lineDisplay();
					System.out.println("<\t��\tǰ\t��\t��\t��\t��\t>");
					System.out.println("1. ��ǰ �߰� ����");
					System.out.println("2. �ܾ� ��ȯ");
					System.out.print("�޴��� ������ �ּ��� : ");
					menuSelect = scan.nextInt();
					System.out.println();
					if(menuSelect == 1)
					{
						
					}
					else if(menuSelect == 2)
					{
						vdp.lineDisplay();
						System.out.println("<\t��\t��\t��\tȯ\t>");
						System.out.println(payStock + "���� ��ȯ�Ǿ����ϴ�.");
						System.out.println();
						for(int i = 0; i < coinType.length; i++)
						{
							coinStock[i] = vcp.changeCalculator(coinType[i], coinStock[i], payStock, i);
							payStock = vcp.payCalculator(payStock, coinType[i], coinStock[i]);
						}
						vdp.lineDisplay();
						break;
					}
				}
			}
			else if(menuSelect==4)
			{
				System.out.print("������ ��й�ȣ�� �Է����ּ��� : ");
				String adminCheck = scan.next();
				if(adminPassword.equals(adminCheck) == true)
				{
					System.out.println("�������� ��ȯ�մϴ�.");
					while(true)
					{
						vdp.lineDisplay();
						System.out.println();
						System.out.println("<\t��\t��\tȭ\t��\t>");
						vap.adminVendingStateCheck(drink, drinkStock, drinkPrice, coinType, coinStock);
						vdp.lineDisplay();
						System.out.println("1. ��ǰ ��� ä���");
						System.out.println("2. �Ž����� ä���");
						System.out.println("3. ��ǰ ���� �����ϱ�");
						System.out.println("4. ��ǰ ���� �����ϱ�");
						System.out.println("5. ������ ��й�ȣ �����ϱ�");
						System.out.println("6. ����ȭ�� ������");
						System.out.print("�޴��� �������ּ��� : ");
						int adminMenuSelect = scan.nextInt();
						System.out.println();
						if(adminMenuSelect == 1)
						{
							while(true)
							{
								vdp.lineDisplay();
								for(int i = 0; i < drink.length; i++)
								{
									System.out.println((i + 1) + ". " + drink[i] + "\t\t��� : " + drinkStock[i]);
								}
								vdp.lineDisplay();
								System.out.print("��� ä�� ��ǰ�� �����ϼ��� : ");
								int selectPutDrink = scan.nextInt();
								System.out.print(drink[selectPutDrink-1] + " ��ǰ�� � ä�������ðڽ��ϱ�? : ");
								if(selectPutDrink == 1)
								{
									drinkStock[selectPutDrink-1] = drinkStock[selectPutDrink-1] + scan.nextInt();
								}
								else if(selectPutDrink == 2)
								{
									drinkStock[selectPutDrink-1] = drinkStock[selectPutDrink-1] + scan.nextInt();
								}
								else if(selectPutDrink == 3)
								{
									drinkStock[selectPutDrink-1] = drinkStock[selectPutDrink-1] + scan.nextInt();
								}
								else if(selectPutDrink == 4)
								{
									drinkStock[selectPutDrink-1] = drinkStock[selectPutDrink-1] + scan.nextInt();
								}
								else if(selectPutDrink == 5)
								{
									drinkStock[selectPutDrink-1] = drinkStock[selectPutDrink-1] + scan.nextInt();
								}
								System.out.println("��ǰ�� ��� �߰��Ͻðڽ��ϱ�?");
								System.out.println("1. ��� �߰� �Ѵ�.");
								System.out.println("2. ��� �߰��� �����Ѵ�.");
								if(scan.nextInt() != 1)
								{
									break;
								}
							}
						}
						else if(adminMenuSelect == 2)
						{
							while(true)
							{
								vdp.lineDisplay();
								for(int i = 0; i < coinType.length; i++)
								{
									if(i == 0)
									{
										System.out.println((i+1) + ". " + coinType[i] + "��\t" + coinStock[i] + "��");
									}
									else
									{
										System.out.println((i+1) + ". " + coinType[i] + "��\t\t" + coinStock[i] + "��");
									}
								}
								vdp.lineDisplay();
								System.out.print("�߰��� �Ž������� ������ �����ϼ��� : ");
								int changeSelect = scan.nextInt();
								System.out.print(coinType[changeSelect-1] + "�� �� �󸶳� �߰� �Ͻðڽ��ϱ�? : ");
								if(changeSelect == 1)
								{
									coinStock[changeSelect-1] = coinStock[changeSelect-1] + scan.nextInt();
								}
								else if(changeSelect == 2)
								{
									coinStock[changeSelect-1] = coinStock[changeSelect-1] + scan.nextInt();
								}
								else if(changeSelect == 3)
								{
									coinStock[changeSelect-1] = coinStock[changeSelect-1] + scan.nextInt();
								}
								else if(changeSelect == 4)
								{
									coinStock[changeSelect-1] = coinStock[changeSelect-1] + scan.nextInt();
								}
								else if(changeSelect == 5)
								{
									coinStock[changeSelect-1] = coinStock[changeSelect-1] + scan.nextInt();
								}
								System.out.println("�Ž������� �߰� �Ͻðڽ��ϱ�?");
								System.out.println("1. �Ž������� �߰� �Ѵ�.");
								System.out.println("2. �Ž����� �߰��� �����Ѵ�.");
								if(scan.nextInt() != 1)
								{
									break;
								}
							}
						}
						else if(adminMenuSelect == 3)
						{
							while(true)
							{
								vdp.lineDisplay();
								for(int i = 0; i < drink.length; i++)
								{
									System.out.println((i + 1) + ". " + drink[i] + "   \t\t��� : " + drinkStock[i]);
								}
								vdp.lineDisplay();
								System.out.print("������ ������ ��ǰ�� �����ϼ��� : ");
								int selectChangeDrink = scan.nextInt();
								System.out.print(drink[selectChangeDrink-1] + "�� � ��ǰ���� �����Ͻðڽ��ϱ�? ��ǰ ���� �Է����ּ��� : ");
								if(selectChangeDrink == 1)
								{
									drink[selectChangeDrink-1] = scan.next();
									drinkStock[selectChangeDrink-1] = 0;
								}
								else if(selectChangeDrink == 2)
								{
									
									drink[selectChangeDrink-1] = scan.next();
									drinkStock[selectChangeDrink-1] = 0;
								}
								else if(selectChangeDrink == 3)
								{
									drink[selectChangeDrink-1] = scan.next();
									drinkStock[selectChangeDrink-1] = 0;
								}
								else if(selectChangeDrink == 4)
								{
									drink[selectChangeDrink-1] = scan.next();
									drinkStock[selectChangeDrink-1] = 0;
								}
								else if(selectChangeDrink == 5)
								{
									drink[selectChangeDrink-1] = scan.next();
									drinkStock[selectChangeDrink-1] = 0;
								}
								System.out.println("�߰��� ��ǰ ������ �����Ͻðڽ��ϱ�?");
								System.out.println("1. ��ǰ ������ �߰��� �����Ѵ�.");
								System.out.println("2. ��ǰ ���� ������ �����Ѵ�.");
								if(scan.nextInt() != 1)
								{
									break;
								}
							}
						}
						else if(adminMenuSelect == 4)
						{
							while(true)
							{
								vdp.lineDisplay();
								for(int i = 0; i < drink.length; i++)
								{
									System.out.println((i + 1) + ". " + drink[i] + "   \t\t���� : " + drinkPrice[i]);
								}
								vdp.lineDisplay();
								System.out.print("������ ������ ��ǰ�� �����ϼ��� : ");
								int selectChangePrice = scan.nextInt();
								System.out.print(drink[selectChangePrice-1] + "�� ������ �󸶷� �����Ͻðڽ��ϱ�? ����� ������ �����ּ��� : ");
								if(selectChangePrice == 1)
								{
									drinkPrice[selectChangePrice-1] = scan.nextInt();
								}
								else if(selectChangePrice == 2)
								{
									drinkPrice[selectChangePrice-1] = scan.nextInt();
								}
								else if(selectChangePrice == 3)
								{
									drinkPrice[selectChangePrice-1] = scan.nextInt();
								}
								else if(selectChangePrice == 4)
								{
									drinkPrice[selectChangePrice-1] = scan.nextInt();
								}
								else if(selectChangePrice == 5)
								{
									drinkPrice[selectChangePrice-1] = scan.nextInt();
								}
								System.out.println("�߰��� ��ǰ ������ �����Ͻðڽ��ϱ�?");
								System.out.println("1. ��ǰ ������ �߰��� �����Ѵ�.");
								System.out.println("2. ��ǰ ���� ������ �����Ѵ�.");
								if(scan.nextInt() != 1)
								{
									break;
								}
							}
						}
						else if(adminMenuSelect == 5)
						{
							System.out.println("������ ��й�ȣ�� �����մϴ�.");
							System.out.println("������ ��й�ȣ�� �Է����ּ��� : ");
							adminPassword = scan.next();
							System.out.println("��й�ȣ�� ����Ǿ����ϴ�.");
						}
						else if(adminMenuSelect == 6)
						{
							vfp.saveVendingStates(drink, vfp.getDrinkFile(), drinkStock, vfp.getDrinkStockFile(),
									drinkPrice, vfp.getDrinkPriceFile(), coinStock, vfp.getCoinStockFile(), adminPassword, vfp.getAdminPasswordFile());
							System.out.println("����ȭ���� �����մϴ�.");
							break;
						}
					}
				}
				else
				{
					System.out.println("��й�ȣ ���� : ��ġ���� �ʽ��ϴ�.");
				}
			}
			else if(menuSelect==5)
			{
				vfp.saveVendingStates(drink, vfp.getDrinkFile(), drinkStock, vfp.getDrinkStockFile(),
						drinkPrice, vfp.getDrinkPriceFile(), coinStock, vfp.getCoinStockFile(), adminPassword, vfp.getAdminPasswordFile());
				System.out.println("�����մϴ�.");
				break;
			}
		}
		scan.close();
	}
}