package com.vending.admin;

public class VendingAdminProc {
	// 관리자 화면에 들어가면 표시될 음료 상품의 재고 및 잔돈 현황을 표시할 메소드	
	public void adminVendingStateCheck(String[] drink, int[] drinkStock, int[] drinkPrice, int[] coinType, int[] coinStock)
	{
		System.out.println("<\t상\t품\t재\t고\t>");
		System.out.println();
		for(int i = 0; i < drink.length; i++)
		{
			System.out.print(drink[i] + "       \t가격 : " + drinkPrice[i] + "원\t");
			System.out.println("재고 : " + drinkStock[i]);
		}
		System.out.println();
		System.out.println("<\t거\t스\t름\t돈\t>");
		System.out.println();
		for(int i = 0; i < coinType.length; i++)
		{
			if(i == 0)
			{
				System.out.println("\t" + coinType[i] + "원\t\t\t" + coinStock[i] + "장");
			}
			else
			{
				System.out.println("\t" + coinType[i] + "원\t\t\t" + coinStock[i] + "개");
			}
		}
	}
}