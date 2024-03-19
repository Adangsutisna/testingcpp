#pragma once

#include "portfolio.h"

// Name: 
//		buyStock
// Input:
//		1. A (reference) StockPortfolio
//      2. A (const reference) string containing a string like 
//          "APPL|Apple Inc.|0.11|10000.50"
// Output: 
//		Boolean, true if the stock was added correctly 
// Side effects: 
//		Adds the stock created from the inputted string to the portfolio
// Summary:
//		Creates a stock from a string: "APPL|Apple Inc.|0.11|10000.50"
//          1. Stock symbol
//          2. Stock name
//          3. Number of shares
//          4. Purchase / current stock price
bool buyStock(StockPortfolio& inPort, const std::string& inString);

// Name: 
//		updateStock
// Input:
//		1. A (reference) StockPortfolio
//      2. A (const reference) string containing a string like 
//          "APPL|135.43"
// Output: 
//		Boolean, true if the stock was modified correctly 
// Side effects: 
//		Updates the stock based on the inputted string
// Summary:
//		Creates a stock from a string: "APPL|135.43"
//          1. Stock symbol
//          2. The new stock price (or current value)
bool updateStock(StockPortfolio& inPort, const std::string& inString);

// Name: 
//		processFile
// Input:
//		1. A (reference) StockPortfolio
//      2. A (const reference) containing the file name to process
// Output: 
//		Boolean, true if the file was processed correctly 
// Side effects: 
//		Updates the portfolio to add / update stocks based on the file
// Summary:
//		Creates a stock from a strings in the input file
bool processFile(StockPortfolio& inPort, const std::string& inString);

