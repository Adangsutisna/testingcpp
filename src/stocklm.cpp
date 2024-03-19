#include "stock.h"

Stock::Stock()
{
	// TODO: Complete function
}

Stock::Stock(const std::string& inName, const std::string& inSymbol, 
	const Money& inPurPrice, double inNumShares)
{
	// TODO: Complete function
}

Money Stock::getCurrPrice() const
{
	// TODO: Fix return value
	return Money();
}

Money Stock::getPurPrice() const
{
	// TODO: Fix return value
	return Money();
}

Money Stock::getChange() const
{
	// TODO: Fix return value
	return Money();
}

std::string Stock::getSymbol() const
{
	// TODO: Fix return value
	return "";
}

std::string Stock::getName() const
{
	// TODO: Fix return value
	return "";
}

double Stock::getNumShares() const
{
	// TODO: Fix return value
	return 0.0;
}

void Stock::setCurrentPrice(const Money& inCurrPrice)
{
	// TODO: Complete function
}

// Stream operators
std::ostream& operator<<(std::ostream& out, const Stock& stock)
{
	// TODO: Fix return value
	return out;
}
