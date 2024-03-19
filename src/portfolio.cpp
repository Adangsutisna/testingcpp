#include "portfolio.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

StockPortfolio::StockPortfolio() {}

void StockPortfolio::addStock(const Stock& inStock) {
    mStocks[inStock.getSymbol()] = inStock;
}

Money StockPortfolio::getTotalValue() const {
    Money total(0);
    for (const auto& pair : mStocks) {
        total += pair.second.getCurrPrice() * pair.second.getNumShares();
    }
    return total;
}

Money StockPortfolio::getOrigValue() const {
    Money total(0);
    for (const auto& pair : mStocks) {
        total += pair.second.getPurPrice() * pair.second.getNumShares();
    }
    return total;
}

Money StockPortfolio::getProfit() const {
    return getTotalValue() - getOrigValue();
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
        valuePairs.emplace_back(pair.second.getCurrPrice() * pair.second.getNumShares(), pair.first);
    }
    std::sort(valuePairs.begin(), valuePairs.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    std::vector<std::string> sortedSymbols;
    for (const auto& valuePair : valuePairs) {
        sortedSymbols.push_back(valuePair.second);
    }
    return sortedSymbols;
}

std::vector<std::string> StockPortfolio::getDiffList() {
    std::vector<std::pair<Money, std::string>> diffPairs;
    for (const auto& pair : mStocks) {
        diffPairs.emplace_back(pair.second.getChange(), pair.first);
    }
    std::sort(diffPairs.begin(), diffPairs.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    std::vector<std::string> sortedSymbols;
    for (const auto& diffPair : diffPairs) {
        sortedSymbols.push_back(diffPair.second);
    }
    return sortedSymbols;
}

bool StockPortfolio::containsStock(const std::string& inSymbol) const {
    return mStocks.find(inSymbol) != mStocks.end();
}

Stock& StockPortfolio::operator[](const std::string& inSymbol) {
    if (mStocks.find(inSymbol) == mStocks.end()) {
        throw std::out_of_range("Stock not found in portfolio.");
    }
    return mStocks[inSymbol];
}
