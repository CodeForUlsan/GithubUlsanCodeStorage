package com.vending.admin;

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

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