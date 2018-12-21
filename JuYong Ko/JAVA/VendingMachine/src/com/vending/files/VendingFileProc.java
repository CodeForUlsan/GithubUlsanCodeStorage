package com.vending.files;

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
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
	// 자판기내의 음료 종류를 외부파일에 쓰는 메소드
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
	
	// 자판기내의 음료 종류를 외부파일에서 읽어오는 메소드
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
	
	// 자판기내의 음료 재고치를 외부파일에 쓰는 메소드
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

	// 자판기내의 음료수 재고를 외부파일에서 읽어오는 메소드
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
	
	// 자판기내의 음료들의 가격을 외부파일에 쓰는 메소드
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
	
	// 자판기내의 음료들의 가격을 외부파일에서 읽어오는 메소드
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
		
	// 자판기내의 거스름돈의 잔량을 외부파일에 쓰는 메소드
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

	// 자판기내의 거스름돈의 잔량을 외부파일에서 읽어오는 메소드
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
	
	// 관리자 비밀번호를 외부파일에 쓰는 메소드
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
	
	// 관리자 비밀번호를 외부파일에서 읽어오는 메소드
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
	
	// 자판기의 현재 정보를 외부파일에 쓰는 메소드
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
