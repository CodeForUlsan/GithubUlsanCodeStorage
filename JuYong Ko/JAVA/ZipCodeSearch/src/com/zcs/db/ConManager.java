package com.zcs.db;

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

import java.sql.Connection;
import java.sql.DriverManager;

public class ConManager {

	Connection jdbcCon = null;
	
	public ConManager(Connection jdbcCon)
	{
		String driver = "org.sqlite.JDBC";
		String url = "jdbc:sqlite:D:\\Project-Sqlite3\\DB\\zipcode.db";

		try
		{
			Class.forName(driver);
			this.jdbcCon = DriverManager.getConnection(url);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public Connection getConnection()
	{
		return this.jdbcCon;
	}
	
	public void closeCon()
	{
		try
		{
			this.jdbcCon.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
