package com.zcs.db;

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