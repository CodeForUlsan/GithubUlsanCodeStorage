package com.vending.files;

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
2018.12.21.Revision1
*/

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.FileSystemNotFoundException;

public class VendingFileProc extends VendingFileData{
	public VendingFileProc()
	{
		super();
	}
	// ���Ǳ⳻�� ���� ������ �ܺ����Ͽ� ���� �޼ҵ�
	public void writeFileToDrink(String[] drink, File f)
	{
		FileWriter fw = null;
		PrintWriter pw = null;
		try
		{
			fw = new FileWriter(f);
			pw = new PrintWriter(fw);
			for(int i = 0; i < drink.length; i++)
			{
				pw.println(drink[i]);
			}
			pw.close();
			fw.close();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}
	}
	
	// ���Ǳ⳻�� ���� ������ �ܺ����Ͽ��� �о���� �޼ҵ�
	public void drinkTypeToFile(String[] drinkType, File f)
	{
		FileReader fr = null;
		String bufLine = null;
		try
		{
			fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			int i = 0;
			while((bufLine = br.readLine())!=null)
			{
				drinkType[i] = bufLine;
				i++;
			}
			br.close();
			fr.close();
		}
		catch(FileNotFoundException fe)
		{
			fe.printStackTrace();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();			
		}
	}
	
	// ���Ǳ⳻�� ���� ���ġ�� �ܺ����Ͽ� ���� �޼ҵ�
	public void writeFileToDrinkStock(int[] drinkStock, File f)
	{		
		FileWriter fw = null;
		PrintWriter pw = null;
		try
		{			
			fw = new FileWriter(f);
			pw = new PrintWriter(fw);
			for(int i = 0; i < drinkStock.length; i++)
			{
				pw.println(drinkStock[i]);
			}
			pw.close();
			fw.close();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}
	}

	// ���Ǳ⳻�� ����� ��� �ܺ����Ͽ��� �о���� �޼ҵ�
	public void drinkStockToFile(int[] drinkStock, File f)
	{
		FileReader fr = null;
		String bufLine = null;
		try
		{
			fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			int i = 0;
			while((bufLine = br.readLine())!=null)
			{
				drinkStock[i] = Integer.parseInt(bufLine);
				i++;
			}
			br.close();
			fr.close();
		}
		catch(FileNotFoundException fe)
		{
			fe.printStackTrace();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}
	}
	
	// ���Ǳ⳻�� ������� ������ �ܺ����Ͽ� ���� �޼ҵ�
	public void writeFileToDrinkPrice(int[] drinkPrice, File f)
	{
		FileWriter fw = null;
		PrintWriter pw = null;
		try
		{			
			fw = new FileWriter(f);
			pw = new PrintWriter(fw);
			for(int i = 0; i < drinkPrice.length; i++)
			{
				pw.println(drinkPrice[i]);
			}
			pw.close();
			fw.close();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}
	}
	
	// ���Ǳ⳻�� ������� ������ �ܺ����Ͽ��� �о���� �޼ҵ�
	public void drinkPriceToFile(int[] drinkPrice, File f)
	{
		FileReader fr = null;
		String bufLine = null;
		try
		{
			fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			int i = 0;
			while((bufLine = br.readLine())!=null)
			{
				drinkPrice[i] = Integer.parseInt(bufLine);
				i++;
			}
			br.close();
			fr.close();
		}
		catch(FileNotFoundException fe)
		{
			fe.printStackTrace();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}
	}
		
	// ���Ǳ⳻�� �Ž������� �ܷ��� �ܺ����Ͽ� ���� �޼ҵ�
	public void writeFileToCoinStock(int[] coinStock, File f)
	{
		FileWriter fw = null;
		PrintWriter pw = null;
		try
		{			
			fw = new FileWriter(f);
			pw = new PrintWriter(fw);
			for(int i = 0; i < coinStock.length; i++)
			{
				pw.println(coinStock[i]);
			}
			pw.close();
			fw.close();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}
	}

	// ���Ǳ⳻�� �Ž������� �ܷ��� �ܺ����Ͽ��� �о���� �޼ҵ�
	public void coinStockToFile(int[] coinStock, File f)
	{
		FileReader fr = null;
		String bufLine = null;
		try
		{
			fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			int i = 0;
			while((bufLine = br.readLine())!=null)
			{
				coinStock[i] = Integer.parseInt(bufLine);
				i++;
			}
			br.close();
			fr.close();
		}
		catch(FileSystemNotFoundException fe)
		{
			fe.printStackTrace();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}
	}
	
	// ������ ��й�ȣ�� �ܺ����Ͽ� ���� �޼ҵ�
	public void writeFileToAdminPassword(String adminPassword, File f)
	{
		FileWriter fw = null;
		PrintWriter pw = null;
		try
		{
			fw = new FileWriter(f);
			pw = new PrintWriter(fw);
			pw.println(adminPassword);
			pw.close();
			fw.close();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}
	}
	
	// ������ ��й�ȣ�� �ܺ����Ͽ��� �о���� �޼ҵ�
	public String adminPasswordToFile(String adminPassword, File f)
	{
		FileReader fr = null;
		String bufLine = null;
		try
		{
			fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			while((bufLine = br.readLine())!=null)
			{
				adminPassword = bufLine;
			}
			br.close();
			fr.close();
		}
		catch(FileNotFoundException fe)
		{
			fe.printStackTrace();
		}
		catch(IOException ie)
		{
			ie.printStackTrace();			
		}
		return adminPassword;
	}
	
	// ���Ǳ��� ���� ������ �ܺ����Ͽ� ���� �޼ҵ�
	public void saveVendingStates(String[] drink, File drinkFile,
			int[] drinkStock, File drinkStockFile,
			int[] drinkPrice, File drinkPriceFile,
			int[] coinStock, File coinStockFile,
			String adminPassword, File adminPasswordFile)
	{
		writeFileToDrink(drink, drinkFile);
		writeFileToDrinkStock(drinkStock, drinkStockFile);
		writeFileToDrinkPrice(drinkPrice, drinkPriceFile);
		writeFileToCoinStock(coinStock, coinStockFile);
		writeFileToAdminPassword(adminPassword, adminPasswordFile);
	}
}
