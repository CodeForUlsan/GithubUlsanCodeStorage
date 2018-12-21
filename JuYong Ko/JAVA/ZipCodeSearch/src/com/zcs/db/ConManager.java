package com.zcs.db;

/*
�������� �α�
!!!�����Ŀ��� �ݵ�� �α׸� �������ֽʽÿ�!!!
�α� ��Ģ - �տ��� ������ ���ڰ� ���ϴ�. ���ڵڿ� �ٴ� Revision�� �ش��� ù��° �ǿø��� ��� ���� 1�� �ι�°�� ��쿣 ���� 2�� �ٿ��ֽø� �˴ϴ�.
ex)2018�� 12�� 21�� ù��° ������ - 2018.12.21.Revision1, 2018�� 12�� 21�� �ι�° ������ - 2018.12.21.Revision2
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
