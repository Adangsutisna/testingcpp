#include "portfolio.h"

StockPortfolio::StockPortfolio()
{
	// TODO: Complete function
}

void StockPortfolio::addStock(const Stock& inStock)
{
	// TODO: Complete function
}

Money StockPortfolio::getTotalValue() const
{
	// TODO: Fix return value
	return Money(0);
}

Money StockPortfolio::getOrigValue() const
{
	// TODO: Fix return value
	return Money(0);
}

Money StockPortfolio::getProfit() const
{
	// TODO: Fix return value
	return Money(0);
}

std::vector<std::string> StockPortfolio::getAlphaList()
{
	// TODO: Fix return value
	std::vector<std::string> retval;
	return retval;
}

std::vector<std::string> StockPortfolio::getValueList()
{
	// TODO: Fix return value
	std::vector<std::string> retval;
	return retval;
}

std::vector<std::string> StockPortfolio::getDiffList()
{
	// TODO: Fix return value
	std::vector<std::string> retval;
	return retval;
}

bool StockPortfolio::containsStock(const std::string& inSymbol) const
{
	// TODO: Fix return value
	return false;
}


Stock& StockPortfolio::operator[](const std::string& inSymbol)
{
	// TODO: Fix return value
	// You don't need to handle this error if the
	// symbol doesn't exist
	return *(new Stock());
}

