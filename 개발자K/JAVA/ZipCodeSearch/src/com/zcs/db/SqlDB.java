package com.zcs.db;

import java.sql.Connection;

public class SqlDB extends SearchDB{
	public SqlDB(Connection jdbcCon)
	{
		super(jdbcCon);
	}
}
