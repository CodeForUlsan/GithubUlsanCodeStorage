package com.vending.main;

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
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
		
		String[] drink = {"칠성사이다", "코카콜라", "스프라이트", "밀키스", "암바사"}; // 음료 상품 문자열 배열[default]
		String adminPassword = "admin";
		int[] drinkStock = {100, 100, 100, 100, 100}; // 음료 상품 재고 정수형 배열
		int[] drinkPrice = {700, 800, 900, 600, 500}; // 음료 판매 가격 정수형 배열
		int[] coinType = {1000, 500, 100, 50, 10}; // 현금 결제시 사용가능한 금액 단위 정수형 배열
		int[] coinStock = {0, 100, 100, 100, 100}; // 자판기에서 거슬러 줄수있는 각 금액별 잔돈 갯수 정수형 배열
		int payStock = 0; // 사용자가 상품을 선택시에 현금결제로 할경우 자판기에서 받거나 거슬러줘야할 금액을 임시로 저장할 변수
		int addingPay = 0; // 사용자가 추가로 금액을 투입했을때 임시로 저장할 정수형 변수
		int payCheck = 0; // 거슬러줄 총 금액을 임시로 저장하고 거스름돈을 걸러줄수있는 체크하는데 활용될 정수형 변수
		
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
			int menuSelect = 0; // 사용자가 메뉴를 선택한 것을 임시로 저장할 변수
			System.out.println("<\t자\t판\t기\t>");
			vdp.menuDisplay(drink, drinkStock, drinkPrice, payStock);
			System.out.println("1. 현금 투입");
			System.out.println("2. 현금 반환");
			System.out.println("3. 상품 선택");
			System.out.println("4. 자판기 관리");
			System.out.println("5. 프로그램 종료");
			System.out.print("메뉴를 선택해주세요 : ");
			menuSelect = scan.nextInt();
			System.out.println();
			vdp.clearScreen();
			if(menuSelect==1)
			{
				vdp.menuDisplay(drink, drinkStock, drinkPrice, payStock);
				System.out.println("<\t현\t금\t투\t입\t>");
				System.out.print("투입할 금액을 입력해주세요 : ");
				addingPay = scan.nextInt();
				payStock = payStock + addingPay;
				System.out.println();
				vdp.clearScreen();
			}
			else if(menuSelect==2)
			{
				System.out.println("<\t현\t금\t반\t환\t>");
				System.out.println(payStock + "원이 반환되었습니다.");
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
					System.out.print("상품을 선택해 주세요 : ");
					int drinkSelect = scan.nextInt();
					vdp.clearScreen();
					payCheck = payStock;
					for(int i = 0; i < coinType.length; i++)
					{
						payCheck = payCheck - (coinType[i] * coinStock[i]);
					}					
					if(payCheck > 0)
					{
						System.out.println("거스름돈이 부족합니다. 관리자에게 문의 하세요.");
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
					System.out.println("<\t상\t품\t추\t가\t구\t매\t>");
					System.out.println("1. 상품 추가 구매");
					System.out.println("2. 잔액 반환");
					System.out.print("메뉴를 선택해 주세요 : ");
					menuSelect = scan.nextInt();
					System.out.println();
					if(menuSelect == 1)
					{
						
					}
					else if(menuSelect == 2)
					{
						vdp.lineDisplay();
						System.out.println("<\t현\t금\t반\t환\t>");
						System.out.println(payStock + "원이 반환되었습니다.");
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
				System.out.print("관리자 비밀번호를 입력해주세요 : ");
				String adminCheck = scan.next();
				if(adminPassword.equals(adminCheck) == true)
				{
					System.out.println("관리모드로 전환합니다.");
					while(true)
					{
						vdp.lineDisplay();
						System.out.println();
						System.out.println("<\t관\t리\t화\t면\t>");
						vap.adminVendingStateCheck(drink, drinkStock, drinkPrice, coinType, coinStock);
						vdp.lineDisplay();
						System.out.println("1. 상품 재고 채우기");
						System.out.println("2. 거스름돈 채우기");
						System.out.println("3. 상품 종류 변경하기");
						System.out.println("4. 상품 가격 변경하기");
						System.out.println("5. 관리자 비밀번호 변경하기");
						System.out.println("6. 관리화면 나가기");
						System.out.print("메뉴를 선택해주세요 : ");
						int adminMenuSelect = scan.nextInt();
						System.out.println();
						if(adminMenuSelect == 1)
						{
							while(true)
							{
								vdp.lineDisplay();
								for(int i = 0; i < drink.length; i++)
								{
									System.out.println((i + 1) + ". " + drink[i] + "\t\t재고 : " + drinkStock[i]);
								}
								vdp.lineDisplay();
								System.out.print("재고를 채울 상품을 선택하세요 : ");
								int selectPutDrink = scan.nextInt();
								System.out.print(drink[selectPutDrink-1] + " 상품을 몇개 채워넣으시겠습니까? : ");
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
								System.out.println("상품의 재고를 추가하시겠습니까?");
								System.out.println("1. 재고를 추가 한다.");
								System.out.println("2. 재고 추가를 종료한다.");
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
										System.out.println((i+1) + ". " + coinType[i] + "원\t" + coinStock[i] + "장");
									}
									else
									{
										System.out.println((i+1) + ". " + coinType[i] + "원\t\t" + coinStock[i] + "개");
									}
								}
								vdp.lineDisplay();
								System.out.print("추가할 거스름돈의 종류를 선택하세요 : ");
								int changeSelect = scan.nextInt();
								System.out.print(coinType[changeSelect-1] + "원 을 얼마나 추가 하시겠습니까? : ");
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
								System.out.println("거스름돈을 추가 하시겠습니까?");
								System.out.println("1. 거스름돈을 추가 한다.");
								System.out.println("2. 거스름돈 추가를 종료한다.");
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
									System.out.println((i + 1) + ". " + drink[i] + "   \t\t재고 : " + drinkStock[i]);
								}
								vdp.lineDisplay();
								System.out.print("종류를 변경할 상품을 선택하세요 : ");
								int selectChangeDrink = scan.nextInt();
								System.out.print(drink[selectChangeDrink-1] + "을 어떤 상품으로 변경하시겠습니까? 상품 명을 입력해주세요 : ");
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
								System.out.println("추가로 상품 종류를 변경하시겠습니까?");
								System.out.println("1. 상품 종류를 추가로 변경한다.");
								System.out.println("2. 상품 종류 변경을 종료한다.");
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
									System.out.println((i + 1) + ". " + drink[i] + "   \t\t가격 : " + drinkPrice[i]);
								}
								vdp.lineDisplay();
								System.out.print("가격을 변경할 상품을 선택하세요 : ");
								int selectChangePrice = scan.nextInt();
								System.out.print(drink[selectChangePrice-1] + "의 가격을 얼마로 변경하시겠습니까? 변경될 가격을 적어주세요 : ");
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
								System.out.println("추가로 상품 가격을 변경하시겠습니까?");
								System.out.println("1. 상품 가격을 추가로 변경한다.");
								System.out.println("2. 상품 가격 변경을 종료한다.");
								if(scan.nextInt() != 1)
								{
									break;
								}
							}
						}
						else if(adminMenuSelect == 5)
						{
							System.out.println("관리자 비밀번호를 변경합니다.");
							System.out.println("변경할 비밀번호를 입력해주세요 : ");
							adminPassword = scan.next();
							System.out.println("비밀번호가 변경되었습니다.");
						}
						else if(adminMenuSelect == 6)
						{
							vfp.saveVendingStates(drink, vfp.getDrinkFile(), drinkStock, vfp.getDrinkStockFile(),
									drinkPrice, vfp.getDrinkPriceFile(), coinStock, vfp.getCoinStockFile(), adminPassword, vfp.getAdminPasswordFile());
							System.out.println("관리화면을 종료합니다.");
							break;
						}
					}
				}
				else
				{
					System.out.println("비밀번호 오류 : 일치하지 않습니다.");
				}
			}
			else if(menuSelect==5)
			{
				vfp.saveVendingStates(drink, vfp.getDrinkFile(), drinkStock, vfp.getDrinkStockFile(),
						drinkPrice, vfp.getDrinkPriceFile(), coinStock, vfp.getCoinStockFile(), adminPassword, vfp.getAdminPasswordFile());
				System.out.println("감사합니다.");
				break;
			}
		}
		scan.close();
	}
}