package com.zcs.db;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

import com.zcs.proc.ZipCodeBean;

public class SearchDB extends SetDB{
	public SearchDB(Connection jdbcCon)
	{
		super(jdbcCon);
	}
	
	public int recordCount(String zipcodeTable)
	{
		String sql = "select count(*) from " + zipcodeTable;
		Statement stmt = null;
		ResultSet rs = null;
		int recordCount = 0;
		try
		{
			stmt = jdbcCon.createStatement();
			rs = stmt.executeQuery(sql);
			while(rs.next())
			{
				recordCount = rs.getInt(1);
			}
			rs.close();
			stmt.close();			
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		return recordCount;
	}
	
	public ArrayList<String> getCountry(String cityInput)
	{
		String sql = "select distinct(country) from '" + cityInput + "'";
		Statement stmt = null;
		ResultSet rs = null;
		ArrayList<String> countryList = new ArrayList<String>();
		try
		{
			stmt = jdbcCon.createStatement();
			rs = stmt.executeQuery(sql);
			while(rs.next())
			{
				countryList.add(rs.getString(1));
			}
			rs.close();
			stmt.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}		
		return countryList;
	}
	
	public ArrayList<ZipCodeBean> getVillageList(String cityInput, String country, String villageKeyword)
	{
		String sql = "select * from " + cityInput + 
				" where country = '" + country + 
				"' and villageName like '%" + villageKeyword + "%'";
		Statement stmt = null;
		ResultSet rs = null;
		ArrayList<ZipCodeBean> resultList = new ArrayList<ZipCodeBean>();
		try
		{
			stmt = jdbcCon.createStatement();
			rs = stmt.executeQuery(sql);
			while(rs.next())
			{
				ZipCodeBean resultBean = new ZipCodeBean();
				resultBean.setZipcode(rs.getString(1));
				resultBean.setCity(rs.getString(2));
				resultBean.setCityEng(rs.getString(3));
				resultBean.setCountry(rs.getString(4));
				resultBean.setCountryEng(rs.getString(5));
				resultBean.setTown(rs.getString(6));
				resultBean.setTownEng(rs.getString(7));
				resultBean.setRoadName(rs.getString(8));
				resultBean.setRoadNameEng(rs.getString(9));
				resultBean.setBuildNumberMain(rs.getString(10));
				resultBean.setBuildNumberSub(rs.getString(11));
				resultBean.setDeliveryName(rs.getString(12));
				resultBean.setBuildName(rs.getString(13));
				resultBean.setVillageName(rs.getString(14));
				resultBean.setSubTown(rs.getString(15));
				resultBean.setLotNumberMain(rs.getString(16));
				resultBean.setLotNumberSub(rs.getString(17));
				resultList.add(resultBean);
			}
			rs.close();
			stmt.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}		
		return resultList;
	}
	
	public ArrayList<ZipCodeBean> getRoadList(String cityInput, String country, String roadKeyword)
	{
		String sql = "select * from " + cityInput + 
				" where country = '" + country + 
				"' and roadName like '%" + roadKeyword + "%'";
		Statement stmt = null;
		ResultSet rs = null;
		ArrayList<ZipCodeBean> resultList = new ArrayList<ZipCodeBean>();
		try
		{
			stmt = jdbcCon.createStatement();
			rs = stmt.executeQuery(sql);
			while(rs.next())
			{
				ZipCodeBean resultBean = new ZipCodeBean();
				resultBean.setZipcode(rs.getString(1));
				resultBean.setCity(rs.getString(2));
				resultBean.setCityEng(rs.getString(3));
				resultBean.setCountry(rs.getString(4));
				resultBean.setCountryEng(rs.getString(5));
				resultBean.setTown(rs.getString(6));
				resultBean.setTownEng(rs.getString(7));
				resultBean.setRoadName(rs.getString(8));
				resultBean.setRoadNameEng(rs.getString(9));
				resultBean.setBuildNumberMain(rs.getString(10));
				resultBean.setBuildNumberSub(rs.getString(11));
				resultBean.setDeliveryName(rs.getString(12));
				resultBean.setBuildName(rs.getString(13));
				resultBean.setVillageName(rs.getString(14));
				resultBean.setSubTown(rs.getString(15));
				resultBean.setLotNumberMain(rs.getString(16));
				resultBean.setLotNumberSub(rs.getString(17));
				resultList.add(resultBean);
			}
			rs.close();
			stmt.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}		
		return resultList;
	}
	
	public ArrayList<ZipCodeBean> getBuildOrLotnumSearch(String tableName,
			String countryName, String villageName, String keyword)
	{
		String sql = "select * from (select * from " + tableName + " where country = '" + countryName + 
				"' and villageName like '%" + villageName + "%')" + 
				"where buildName like '%" + keyword +
				"%' or lotNumberMain like '%" + keyword + 
				"%' or lotNumberSub like '%" + keyword +
				"%' or deliveryName like '%" + keyword + "%'";
		Statement stmt = null;
		ResultSet rs = null;
		ArrayList<ZipCodeBean> ziplist = new ArrayList<ZipCodeBean>();
		try
		{
			stmt = jdbcCon.createStatement();
			rs = stmt.executeQuery(sql);
			while(rs.next())
			{
				ZipCodeBean zipbean = new ZipCodeBean();
				zipbean.setZipcode(rs.getString(1));
				zipbean.setCity(rs.getString(2));
				zipbean.setCityEng(rs.getString(3));
				zipbean.setCountry(rs.getString(4));
				zipbean.setCountryEng(rs.getString(5));
				zipbean.setTown(rs.getString(6));
				zipbean.setTownEng(rs.getString(7));
				zipbean.setRoadName(rs.getString(8));
				zipbean.setRoadNameEng(rs.getString(9));
				zipbean.setBuildNumberMain(rs.getString(10));
				zipbean.setBuildNumberSub(rs.getString(11));
				zipbean.setDeliveryName(rs.getString(12));
				zipbean.setBuildName(rs.getString(13));
				zipbean.setVillageName(rs.getString(14));
				zipbean.setSubTown(rs.getString(15));
				zipbean.setLotNumberMain(rs.getString(16));
				zipbean.setLotNumberSub(rs.getString(17));
				ziplist.add(zipbean);
			}
			rs.close();
			stmt.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
		return ziplist;
	}
	
	public ArrayList<ZipCodeBean> getBuildOrBuildnumSearch(String tableName,
			String countryName, String roadName, String keyword)
	{
		String sql = "select * from (select * from " + tableName + " where country = '" + countryName + 
				"' and roadName like '%" + roadName + "%')" + 
				"where buildName like '%" + keyword +
				"%' or buildNumberMain like '%" + keyword + 
				"%' or buildNumberSub like '%" + keyword +
				"%' or deliveryName like '%" + keyword + "%'";
		Statement stmt = null;
		ResultSet rs = null;
		ArrayList<ZipCodeBean> ziplist = new ArrayList<ZipCodeBean>();
		try
		{
			stmt = jdbcCon.createStatement();
			rs = stmt.executeQuery(sql);
			while(rs.next())
			{
				ZipCodeBean zipbean = new ZipCodeBean();
				zipbean.setZipcode(rs.getString(1));
				zipbean.setCity(rs.getString(2));
				zipbean.setCityEng(rs.getString(3));
				zipbean.setCountry(rs.getString(4));
				zipbean.setCountryEng(rs.getString(5));
				zipbean.setTown(rs.getString(6));
				zipbean.setTownEng(rs.getString(7));
				zipbean.setRoadName(rs.getString(8));
				zipbean.setRoadNameEng(rs.getString(9));
				zipbean.setBuildNumberMain(rs.getString(10));
				zipbean.setBuildNumberSub(rs.getString(11));
				zipbean.setDeliveryName(rs.getString(12));
				zipbean.setBuildName(rs.getString(13));
				zipbean.setVillageName(rs.getString(14));
				zipbean.setSubTown(rs.getString(15));
				zipbean.setLotNumberMain(rs.getString(16));
				zipbean.setLotNumberSub(rs.getString(17));
				ziplist.add(zipbean);
			}
			rs.close();
			stmt.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
		return ziplist;
	}
}