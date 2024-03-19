#include "driver.h"
#include "strlib.h"
#include <fstream>

bool buyStock(StockPortfolio& inPort, const std::string& inString) {
    std::vector<std::string> parts = strSplit(inString, '|');
    if (parts.size() < 4) return false; // Pastikan string memiliki semua bagian yang diperlukan
    
    std::string symbol = parts[0];
    std::string name = parts[1];
    double numShares = std::stod(parts[2]);
    Money purchasePrice(std::stod(parts[3]));

    Stock newStock(name, symbol, purchasePrice, numShares);
    inPort.addStock(newStock);
    return true;
}
