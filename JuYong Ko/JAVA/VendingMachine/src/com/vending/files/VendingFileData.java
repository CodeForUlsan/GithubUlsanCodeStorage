package com.vending.files;

/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

import java.io.File;

public class VendingFileData {
	private File drinkFile = null;
	private File drinkStockFile = null;
	private File drinkPriceFile = null;
	private File coinStockFile = null;
	private File adminPasswordFile = null;
	
	public VendingFileData()
	{
		drinkFile = new File("drink.dat");
		drinkStockFile = new File("drinkStock.dat");
		drinkPriceFile = new File("drinkPrice.dat");
		coinStockFile = new File("coinStock.dat");
		adminPasswordFile = new File("adminPassword.dat");
	}

	public File getDrinkFile() {
		return drinkFile;
	}

	public void setDrinkFile(File drinkFile) {
		this.drinkFile = drinkFile;
	}

	public File getDrinkStockFile() {
		return drinkStockFile;
	}

	public void setDrinkStockFile(File drinkStockFile) {
		this.drinkStockFile = drinkStockFile;
	}

	public File getDrinkPriceFile() {
		return drinkPriceFile;
	}

	public void setDrinkPriceFile(File drinkPriceFile) {
		this.drinkPriceFile = drinkPriceFile;
	}

	public File getCoinStockFile() {
		return coinStockFile;
	}

	public void setCoinStockFile(File coinStockFile) {
		this.coinStockFile = coinStockFile;
	}

	public File getAdminPasswordFile() {
		return adminPasswordFile;
	}

	public void setAdminPasswordFile(File adminPasswordFile) {
		this.adminPasswordFile = adminPasswordFile;
	}
}
