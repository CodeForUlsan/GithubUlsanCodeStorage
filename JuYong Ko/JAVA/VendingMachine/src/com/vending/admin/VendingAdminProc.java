package com.vending.admin;

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

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