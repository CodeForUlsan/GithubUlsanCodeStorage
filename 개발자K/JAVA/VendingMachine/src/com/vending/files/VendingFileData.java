package com.vending.files;

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
