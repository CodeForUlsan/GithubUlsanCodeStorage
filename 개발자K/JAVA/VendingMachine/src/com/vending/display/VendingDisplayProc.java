package com.vending.display;

public class VendingDisplayProc {
	// 자판기에서 판매하는 상품이 어떤종류가 있는지와 현재 자판기에 투입된 잔액이 얼마인지 화면에 표시해주는 메소드
	public void menuDisplay(String[] drink, int[] drinkStock, int[] drinkPrice, int payStock)
	{
		lineDisplay();
		for(int i = 0; i < drink.length; i++)
		{
			System.out.print(drink[i]);
			if(drink[i].length() < 5)
			{
				System.out.print("\t\t가격 : ");
			}
			else
			{
				System.out.print("\t가격 : ");
			}
			System.out.print(drinkPrice[i] + "원\t");
			if(drinkStock[i]==0)
			{
				System.out.println("품절");
			}
			else
			{
				System.out.println();
			}
		}
		System.out.println();
		System.out.println("\t\t현재의 금액 : " + payStock);
		lineDisplay();
	}
	
	// 사용자가 구매하는 음료의 종류를 앞에 각 상품별로 번호를 붙여 출력하는 메소드	
	public void purchaseMenuDisplay(String[] drink, int[] drinkPrice, int[] drinkStock, int payStock)
	{
		for(int i = 0; i < 51; i++)
		{
			System.out.print("-");
		}
		System.out.println();
		for(int i = 0; i < drink.length; i++)
		{
			System.out.print((i+1) + ". " + drink[i] + "       \t가격 : " + drinkPrice[i] + "원\t");
			if(drinkStock[i]==0)
			{
				System.out.println("품절");
			}
			else
			{
				System.out.println();
			}
		}
		System.out.println();
		System.out.println("\t\t현재의 금액 : " + payStock);				
		for(int i = 0; i < 51; i++)
		{
			System.out.print("-");
		}
		System.out.println();
	}
	
	// 화면을 깔끔하게 보이기 위한 메소드
	public void clearScreen()
	{
		for(int i = 0; i < 70; i++)
		{
			System.out.println("");
		}
	}
	
	// 화면에 점선을 표시할 메소드
	public void lineDisplay()
	{
		for(int i = 0; i < 51; i++)
		{
			System.out.print("-");
		}
		System.out.println();
	}
}