package com.zcs.db;

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
