#pragma once

#include <iostream>
#include <string>

#include "money.h"

class Stock
{
private:
	// Stores the price paid to purchase the stock
	Money mPurchasePrice;
	// Stores the current price, update this variable
	Money mCurrentPrice;
	// Stores the full name of the company
	std::string mName;
	// Stores the short stock symbol
	std::string mSymbol;
	// Number of shares owned
	double mNumShares;
	
public:
	// Constructors 
	Stock();
	Stock(const std::string &inName, const std::string& inSymbol, 
	const Money& inPurPrice, double inNumShares);

	// Getters
	Money getCurrPrice() const;
	Money getPurPrice() const;
	Money getChange() const;
	std::string getSymbol() const;
	std::string getName() const;
	double getNumShares() const;

	// Setters
	void setCurrentPrice(const Money& inCurrPrice);

	// Stream operators
	friend std::ostream& operator<<(std::ostream& out, const Stock& stock);
};