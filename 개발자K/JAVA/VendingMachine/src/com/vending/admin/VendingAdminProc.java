package com.vending.admin;

public class VendingAdminProc {
	// ������ ȭ�鿡 ���� ǥ�õ� ���� ��ǰ�� ��� �� �ܵ� ��Ȳ�� ǥ���� �޼ҵ�	
	public void adminVendingStateCheck(String[] drink, int[] drinkStock, int[] drinkPrice, int[] coinType, int[] coinStock)
	{
		System.out.println("<\t��\tǰ\t��\t��\t>");
		System.out.println();
		for(int i = 0; i < drink.length; i++)
		{
			System.out.print(drink[i] + "       \t���� : " + drinkPrice[i] + "��\t");
			System.out.println("��� : " + drinkStock[i]);
		}
		System.out.println();
		System.out.println("<\t��\t��\t��\t��\t>");
		System.out.println();
		for(int i = 0; i < coinType.length; i++)
		{
			if(i == 0)
			{
				System.out.println("\t" + coinType[i] + "��\t\t\t" + coinStock[i] + "��");
			}
			else
			{
				System.out.println("\t" + coinType[i] + "��\t\t\t" + coinStock[i] + "��");
			}
		}
	}
}