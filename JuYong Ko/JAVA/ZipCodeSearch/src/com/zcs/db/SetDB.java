package com.zcs.db;

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.util.ArrayList;

import com.zcs.proc.ZipCodeBean;
import com.zcs.proc.ZipCodeProc;

public class SetDB extends ConManager{
	
	public SetDB(Connection jdbcCon)
	{
		super(jdbcCon);
	}
	
	public void dataInsert(String tableName, ArrayList<ZipCodeBean> zipdata)
	{
		ZipCodeProc zcp = new ZipCodeProc();
		PreparedStatement pstmt = null;
		String sql = "insert into " + tableName + " values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
		
		//zipdata = zcp.readToFile(txtFilePath, startCount, endCount);
					
		try
		{
			jdbcCon.setAutoCommit(false);
			pstmt = jdbcCon.prepareStatement(sql);
			for(int i = 0; i < zipdata.size(); i++)
			{
				pstmt.setString(1, zipdata.get(i).getZipcode());
				pstmt.setString(2, zipdata.get(i).getCity());
				pstmt.setString(3, zipdata.get(i).getCityEng());
				pstmt.setString(4, zipdata.get(i).getCountry());
				pstmt.setString(5, zipdata.get(i).getCountryEng());
				pstmt.setString(6, zipdata.get(i).getTown());
				pstmt.setString(7, zipdata.get(i).getTownEng());
				pstmt.setString(8, zipdata.get(i).getRoadName());
				pstmt.setString(9, zipdata.get(i).getRoadNameEng());
				pstmt.setString(10, zipdata.get(i).getBuildNumberMain());
				pstmt.setString(11, zipdata.get(i).getBuildNumberSub());
				pstmt.setString(12, zipdata.get(i).getDeliveryName());
				pstmt.setString(13, zipdata.get(i).getBuildName());
				pstmt.setString(14, zipdata.get(i).getVillageName());
				pstmt.setString(15, zipdata.get(i).getSubTown());
				pstmt.setString(16, zipdata.get(i).getLotNumberMain());
				pstmt.setString(17, zipdata.get(i).getLotNumberSub());
				pstmt.executeUpdate();
			}
			System.out.print("*");
			jdbcCon.commit();
			jdbcCon.setAutoCommit(true);			
			pstmt.close();
			//super.closeCon();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			try
			{
				jdbcCon.rollback();
				jdbcCon.setAutoCommit(true);
			}
			catch(Exception cone)
			{
				cone.printStackTrace();
			}
		}
	}
}