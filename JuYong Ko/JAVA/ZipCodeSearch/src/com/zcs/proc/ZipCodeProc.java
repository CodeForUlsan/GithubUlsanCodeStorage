package com.zcs.proc;

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.sql.Connection;
import java.util.ArrayList;

import com.zcs.db.SearchDB;

public class ZipCodeProc {

	ArrayList<ZipCodeBean> zipdata = new ArrayList<ZipCodeBean>();
	
	public ArrayList<ZipCodeBean> readToFile(String txtFilePath,int startCount, int endCount)
	{
		Connection jdbcCon = null;
		SearchDB sdb = new SearchDB(jdbcCon);
		
		File zipcodeFile = new File(txtFilePath);
		FileReader fr = null;
		BufferedReader br = null;
		
		boolean flag = false;
		int loopStart = 1;
		try
		{
			fr = new FileReader(zipcodeFile);
			br = new BufferedReader(fr);
			String line = null;
			while((line = br.readLine())!=null)
			{
				if(loopStart >= startCount)
				{
					ZipCodeBean zipbean = new ZipCodeBean();
					ZipCodeBean compareZipbean = new ZipCodeBean();
					String[] lines = line.split("\\|");
					zipbean.setZipcode(lines[0]);				
					zipbean.setCity(lines[2]);
					zipbean.setCityEng(lines[3]);
					zipbean.setCountry(lines[4]);
					zipbean.setCountryEng(lines[5]);
					zipbean.setTown(lines[6]);
					zipbean.setTownEng(lines[7]);
					zipbean.setRoadName(lines[9]);
					zipbean.setRoadNameEng(lines[10]);
					zipbean.setBuildNumberMain(lines[12]);
					zipbean.setBuildNumberSub(lines[13]);
					zipbean.setDeliveryName(lines[15]);
					zipbean.setBuildName(lines[16]);
					zipbean.setVillageName(lines[18]);
					zipbean.setSubTown(lines[19]);
					zipbean.setLotNumberMain(lines[21]);
					zipbean.setLotNumberSub(lines[23]);
					//this.zipdata.add(i, zipbean);
					
					flag = this.zipdata.add(zipbean);
				//	if(flag == true)
				//	{
				//		System.out.println("List add Success");
				//	}						
				}
				loopStart++;
				if(loopStart >= endCount)
				{
					break;
				}
			}
			//this.zipdata.remove(0);
			firstLineTxtCutting();
			br.close();
			fr.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			try{br.close();}catch(Exception e){}
			try{fr.close();}catch(Exception e){}
		}		
		return this.zipdata;
	}
	
	public int fileLineCount(String txtFilePath)
	{
		File zipcodeFile = new File(txtFilePath);
		FileReader fr = null;
		BufferedReader br = null;

		int lineCount = 0;
		try
		{
			fr = new FileReader(zipcodeFile);
			br = new BufferedReader(fr);
			String line = null;
			while((line = br.readLine())!=null)
			{
				lineCount++;
			}
			br.close();
			fr.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			try{br.close();}catch(Exception e){}
			try{fr.close();}catch(Exception e){}
		}
		return lineCount-1; // 첫라인은 데이터베이스에 insert시에 잘라내므로 실제 파일에서 읽어오는 라인에서 -1을 해야 한다. 
	}
	
	public void firstLineTxtCutting()
	{
		if(this.zipdata.get(0).getZipcode().equals("우편번호"))
		{
			this.zipdata.remove(0);
		}
	}
}