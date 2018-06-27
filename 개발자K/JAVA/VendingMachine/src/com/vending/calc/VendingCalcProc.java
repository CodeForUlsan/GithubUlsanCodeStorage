package com.vending.calc;

public class VendingCalcProc {
	
	// 사용자가 음료를 선택하면 그 음료의 재고는 충분한지, 현재 자판기에 투입된 금액이 모자라진 않는지 체크하고,
	// 상품을 구입하고 난뒤의 거스름돈을 계산하여 표시하는 메소드
	public int payCheck(int[] drinkStock, int drinkSelect, String[] drink, int[] drinkPrice, int payStock)
	{
		if(drinkStock[drinkSelect-1]!=0)
		{
			if((payStock - drinkPrice[drinkSelect-1]) > 0)
			{
				System.out.println(drink[drinkSelect-1] + " 구입이 완료되었습니다.");
				payStock = payStock - drinkPrice[drinkSelect-1];
				drinkStock[drinkSelect-1]--;
				System.out.println("거스름돈은 " + payStock + "원 입니다.");				
			}
			else
			{
				System.out.println("투입된 금액이 상품의 가격보다 적습니다. 현금을 추가 투입해주세요.");
			}
		}
		else
		{
			System.out.println("선택한 상품은 품절입니다. 다시 선택해 주세요");
		}
		return payStock;
	}
	
	// 반환되는 잔액이 각 종류별로 몇개인지 체크하고 잔액을 0으로 만들어서 리턴하는 메소드
	public int changeCalculator(int coinType, int coinStock, int payStock, int select)
	{
		if(select == 0)
		{
			if(coinStock != 0)
			{
				System.out.println(coinType + "원\t" + (payStock/coinType) + "장\t");
				coinStock = coinStock - (payStock/coinType);
			}
			else
			{
				System.out.println(coinType + "원\t0장\t");
			}
		}
		else
		{
			if(coinStock != 0)
			{
				System.out.println(coinType + "원\t" + (payStock/coinType) + "개\t");
				coinStock = coinStock - (payStock/coinType);
			}
			else
			{
				System.out.println(coinType + "원\t0개\t");
			}
		}
		return coinStock;
	}
	
	// 거스름돈을 계산하는 메소드
	public int payCalculator(int payStock, int coinType, int coinStock)
	{
		if(coinStock != 0)
		{
			payStock = payStock - ((payStock/coinType) * coinType);
		}
		return payStock;
	}
}
