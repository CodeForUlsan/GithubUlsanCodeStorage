package com.vending.calc;

public class VendingCalcProc {
	
	// ����ڰ� ���Ḧ �����ϸ� �� ������ ���� �������, ���� ���Ǳ⿡ ���Ե� �ݾ��� ���ڶ��� �ʴ��� üũ�ϰ�,
	// ��ǰ�� �����ϰ� ������ �Ž������� ����Ͽ� ǥ���ϴ� �޼ҵ�
	public int payCheck(int[] drinkStock, int drinkSelect, String[] drink, int[] drinkPrice, int payStock)
	{
		if(drinkStock[drinkSelect-1]!=0)
		{
			if((payStock - drinkPrice[drinkSelect-1]) > 0)
			{
				System.out.println(drink[drinkSelect-1] + " ������ �Ϸ�Ǿ����ϴ�.");
				payStock = payStock - drinkPrice[drinkSelect-1];
				drinkStock[drinkSelect-1]--;
				System.out.println("�Ž������� " + payStock + "�� �Դϴ�.");				
			}
			else
			{
				System.out.println("���Ե� �ݾ��� ��ǰ�� ���ݺ��� �����ϴ�. ������ �߰� �������ּ���.");
			}
		}
		else
		{
			System.out.println("������ ��ǰ�� ǰ���Դϴ�. �ٽ� ������ �ּ���");
		}
		return payStock;
	}
	
	// ��ȯ�Ǵ� �ܾ��� �� �������� ����� üũ�ϰ� �ܾ��� 0���� ���� �����ϴ� �޼ҵ�
	public int changeCalculator(int coinType, int coinStock, int payStock, int select)
	{
		if(select == 0)
		{
			if(coinStock != 0)
			{
				System.out.println(coinType + "��\t" + (payStock/coinType) + "��\t");
				coinStock = coinStock - (payStock/coinType);
			}
			else
			{
				System.out.println(coinType + "��\t0��\t");
			}
		}
		else
		{
			if(coinStock != 0)
			{
				System.out.println(coinType + "��\t" + (payStock/coinType) + "��\t");
				coinStock = coinStock - (payStock/coinType);
			}
			else
			{
				System.out.println(coinType + "��\t0��\t");
			}
		}
		return coinStock;
	}
	
	// �Ž������� ����ϴ� �޼ҵ�
	public int payCalculator(int payStock, int coinType, int coinStock)
	{
		if(coinStock != 0)
		{
			payStock = payStock - ((payStock/coinType) * coinType);
		}
		return payStock;
	}
}
