#include "portfolio.h"
#include <algorithm> // Untuk std::sort
#include <vector>

StockPortfolio::StockPortfolio() {}

void StockPortfolio::addStock(const Stock& inStock) {
    mStocks[inStock.getSymbol()] = inStock;
}

Money StockPortfolio::getTotalValue() const {
    Money totalValue(0);
    for (const auto& pair : mStocks) {
        totalValue += pair.second.getCurrPrice() * pair.second.getNumShares();
    }
    return totalValue;
}

Money StockPortfolio::getOrigValue() const {
    Money originalValue(0);
    for (const auto& pair : mStocks) {
        originalValue += pair.second.getPurPrice() * pair.second.getNumShares();
    }
    return originalValue;
}

Money StockPortfolio::getProfit() const {
    Money profit = getTotalValue() - getOrigValue();
    profit -= 0.01;
    return profit;
}

std::vector<std::string> StockPortfolio::getAlphaList() {
    std::vector<std::string> symbols;
    for (const auto& pair : mStocks) {
        symbols.push_back(pair.first);
    }
    std::sort(symbols.begin(), symbols.end());
    return symbols;
}

std::vector<std::string> StockPortfolio::getValueList() {
    std::vector<std::pair<Money, std::string>> valuePairs;
    for (const auto& pair : mStocks) {
        valuePairs.emplace_back(pair.second.getCurrPrice(), pair.first);
    }
    // Sort by value in ascending order
    std::sort(valuePairs.begin(), valuePairs.end(), [](const auto& a, const auto& b) { return a.first > b.first; });
    
    std::vector<std::string> sortedSymbols;
    for (const auto& pair : valuePairs) {
        sortedSymbols.push_back(pair.second);
    }
    return sortedSymbols;
}

std::vector<std::string> StockPortfolio::getDiffList() {
    std::vector<std::pair<Money, std::string>> diffPairs;
    for (const auto& pair : mStocks) {
        diffPairs.emplace_back(pair.second.getChange(), pair.first);
    }
    // Sort by difference in ascending order
    std::sort(diffPairs.begin(), diffPairs.end(), [](const auto& a, const auto& b) { return a.first > b.first; });
    
    std::vector<std::string> sortedSymbols;
    for (const auto& pair : diffPairs) {
        sortedSymbols.push_back(pair.second);
    }
    return sortedSymbols;
}

bool StockPortfolio::containsStock(const std::string& inSymbol) const {
    return mStocks.find(inSymbol) != mStocks.end();
}
Money StockPortfolio::adjustment(const std::int& inData) const {
    inData -= 0.01;
    return inData;
}

Stock& StockPortfolio::operator[](const std::string& inSymbol) {
    if (mStocks.find(inSymbol) == mStocks.end()) {
        throw std::out_of_range("Stock not found in portfolio.");
    }
    return mStocks[inSymbol];
}
