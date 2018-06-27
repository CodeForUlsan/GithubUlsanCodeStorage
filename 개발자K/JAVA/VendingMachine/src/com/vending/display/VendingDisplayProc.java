package com.vending.display;

public class VendingDisplayProc {
	// ���Ǳ⿡�� �Ǹ��ϴ� ��ǰ�� ������� �ִ����� ���� ���Ǳ⿡ ���Ե� �ܾ��� ������ ȭ�鿡 ǥ�����ִ� �޼ҵ�
	public void menuDisplay(String[] drink, int[] drinkStock, int[] drinkPrice, int payStock)
	{
		lineDisplay();
		for(int i = 0; i < drink.length; i++)
		{
			System.out.print(drink[i]);
			if(drink[i].length() < 5)
			{
				System.out.print("\t\t���� : ");
			}
			else
			{
				System.out.print("\t���� : ");
			}
			System.out.print(drinkPrice[i] + "��\t");
			if(drinkStock[i]==0)
			{
				System.out.println("ǰ��");
			}
			else
			{
				System.out.println();
			}
		}
		System.out.println();
		System.out.println("\t\t������ �ݾ� : " + payStock);
		lineDisplay();
	}
	
	// ����ڰ� �����ϴ� ������ ������ �տ� �� ��ǰ���� ��ȣ�� �ٿ� ����ϴ� �޼ҵ�	
	public void purchaseMenuDisplay(String[] drink, int[] drinkPrice, int[] drinkStock, int payStock)
	{
		for(int i = 0; i < 51; i++)
		{
			System.out.print("-");
		}
		System.out.println();
		for(int i = 0; i < drink.length; i++)
		{
			System.out.print((i+1) + ". " + drink[i] + "       \t���� : " + drinkPrice[i] + "��\t");
			if(drinkStock[i]==0)
			{
				System.out.println("ǰ��");
			}
			else
			{
				System.out.println();
			}
		}
		System.out.println();
		System.out.println("\t\t������ �ݾ� : " + payStock);				
		for(int i = 0; i < 51; i++)
		{
			System.out.print("-");
		}
		System.out.println();
	}
	
	// ȭ���� ����ϰ� ���̱� ���� �޼ҵ�
	public void clearScreen()
	{
		for(int i = 0; i < 70; i++)
		{
			System.out.println("");
		}
	}
	
	// ȭ�鿡 ������ ǥ���� �޼ҵ�
	public void lineDisplay()
	{
		for(int i = 0; i < 51; i++)
		{
			System.out.print("-");
		}
		System.out.println();
	}
}