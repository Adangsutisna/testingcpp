#include "portfolio.h"
#include <algorithm> // Untuk std::sort
#include <vector>

// Konstruktor default untuk StockPortfolio yang menginisialisasi portofolio kosong.
StockPortfolio::StockPortfolio() {}

// Fungsi untuk menambahkan saham ke dalam portofolio.
void StockPortfolio::addStock(const Stock& inStock) {
    // Menambahkan saham berdasarkan simbol saham sebagai kunci.
    mStocks[inStock.getSymbol()] = inStock;
}

// Fungsi untuk mendapatkan total nilai saat ini dari semua saham dalam portofolio.
Money StockPortfolio::getTotalValue() const {
    Money totalValue(0);
    // Menghitung total nilai dengan menjumlahkan harga saat ini dikali jumlah saham.
    for (const auto& pair : mStocks) {
        totalValue += pair.second.getCurrPrice() * pair.second.getNumShares();
    }
    return totalValue;
}

// Fungsi untuk mendapatkan total nilai pembelian awal dari semua saham dalam portofolio.
Money StockPortfolio::getOrigValue() const {
    Money originalValue(0);
    // Menghitung total nilai pembelian dengan menjumlahkan harga pembelian dikali jumlah saham.
    for (const auto& pair : mStocks) {
        originalValue += pair.second.getPurPrice() * pair.second.getNumShares();
    }
    return originalValue;
}

// Fungsi untuk menghitung profit (keuntungan atau kerugian) dari portofolio.
Money StockPortfolio::getProfit() const {
    // Menghitung total nilai saat ini dan nilai pembelian awal dari semua saham.
    double totalValue = 0;
    for (const auto& pair : mStocks) {
        totalValue += pair.second.getCurrPrice().getCents() * pair.second.getNumShares();
    }

    double originalValue = 0;
    for (const auto& pair : mStocks) {
        originalValue += pair.second.getPurPrice().getCents() * pair.second.getNumShares();
    }

    // Menghitung profit dengan mengurangi total nilai pembelian dari total nilai saat ini.
    return Money((totalValue - originalValue) / 100.0);
}

// Fungsi untuk mendapatkan daftar simbol saham dalam portofolio, diurutkan secara alfabetis.
std::vector<std::string> StockPortfolio::getAlphaList() {
    std::vector<std::string> symbols;
    // Menambahkan semua simbol saham ke dalam vector.
    for (const auto& pair : mStocks) {
        symbols.push_back(pair.first);
    }
    // Mengurutkan simbol saham secara alfabetis.
    std::sort(symbols.begin(), symbols.end());
    return symbols;
}

// Fungsi untuk mendapatkan daftar simbol saham berdasarkan nilai saat ini, diurutkan dari nilai terbesar.
std::vector<std::string> StockPortfolio::getValueList() {
    std::vector<std::pair<Money, std::string>> valuePairs;
    // Membuat pasangan nilai dan simbol saham.
    for (const auto& pair : mStocks) {
        valuePairs.emplace_back(pair.second.getCurrPrice(), pair.first);
    }
    // Mengurutkan pasangan berdasarkan nilai saham dari yang terbesar.
    std::sort(valuePairs.begin(), valuePairs.end(), [](const auto& a, const auto& b) { return a.first > b.first; });
    
    // Mengumpulkan simbol saham yang sudah diurutkan berdasarkan nilai.
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


Stock& StockPortfolio::operator[](const std::string& inSymbol) {
    if (mStocks.find(inSymbol) == mStocks.end()) {
        throw std::out_of_range("Stock not found in portfolio.");
    }
    return mStocks[inSymbol];
}
