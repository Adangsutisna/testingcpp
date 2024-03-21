#pragma once

#include <map>
#include <string>
#include <vector>

#include "stock.h"

class StockPortfolio
{
private:
	// Stores the collection of stocks
	// Key is the short stock symbol (like "DIS")
	// Value is the full Stock object
	std::map<std::string, Stock> mStocks;

public:
	// Constructors
	StockPortfolio();

	// Getters
	Money getTotalValue() const;
	Money getOrigValue() const;
	Money getProfit() const;

	// Name: 
	//		addStock
	// Input:
	//		1. A (constant reference) stock object to add to the map
	// Output: 
	//		None 
	// Side effects: 
	//		Adds the stock to the internal map
	// Summary:
	//		Adds a stock to the map, if the stock is already in the map
	//		update it with the new stock object
	void addStock(const Stock& inStock);

	// Name: 
	//		containsStock
	// Input:
	//		1. A (constant reference) string with the stock symbol
	// Output: 
	//		Boolean
	// Side effects: 
	//		None
	// Summary:
	//		Returns true if the stock exists in the map, otherwise false
	bool containsStock(const std::string& inSymbol) const;

	// Name: 
	//		operator[]
	// Input:
	//		1. A (constant reference) string with the stock symbol
	// Output: 
	//		A reference to a Stock object
	// Side effects: 
	//		None
	// Summary:
	//		Returns a reference to the Stock that exists at the 
	//		inputted key -- undefined if the stock doesn't exist.
	Stock& operator[](const std::string& inSymbol);

	// Name: 
	//		getAlphaList
	// Input:
	//		None
	// Output: 
	//		A vector of strings sorted in 
	//		alphabetical order by stock symbol
	// Side effects: 
	//		None
	// Summary:
	//		Returns a vector of sorted strings
	std::vector<std::string> getAlphaList();

	// Name: 
	//		getValueList
	// Input:
	//		None
	// Output: 
	//		A vector of strings sorted in 
	//		ascending order, by current stock value
	// Side effects: 
	//		None
	// Summary:
	//		Returns a vector of strings in the above order
	std::vector<std::string> getValueList();
	
	// Name: 
	//		getDiffList
	// Input:
	//		None
	// Output: 
	//		A vector of strings sorted in 
	//		ascending order, by stock difference
	// Side effects: 
	//		None
	// Summary:
	//		Returns a vector of strings in the above order	
	std::vector<std::string> getDiffList();
    Money adjustment(int) const;
};
