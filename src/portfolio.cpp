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
    Money totalProfit(0);
    // Hitung total nilai saat ini dan total nilai pembelian
    Money totalValueNow = getTotalValue();
    Money totalValuePurchased = getOrigValue();
    
    // Hitung profit dengan mengurangkan total nilai pembelian dari total nilai saat ini
    // Pastikan bahwa operasi pengurangan ini akurat hingga ke sen terakhir
    totalProfit = totalValueNow - totalValuePurchased;

    return totalProfit;
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
     // Create a vector of just the stock symbols
    std::vector<std::string> symbols;
    for (const auto& pair : mStocks) {
        symbols.push_back(pair.first);
    }

    // Sort the symbols vector based on the total value of each corresponding stock
    std::sort(symbols.begin(), symbols.end(), [this](const std::string& sym1, const std::string& sym2) {
        const auto& stock1 = mStocks.at(sym1);
        const auto& stock2 = mStocks.at(sym2);
        Money value1 = stock1.getCurrPrice() * stock1.getNumShares();
        Money value2 = stock2.getCurrPrice() * stock2.getNumShares();
        return value1 < value2;  // Use '>' if you want descending order
    });

    return symbols;
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