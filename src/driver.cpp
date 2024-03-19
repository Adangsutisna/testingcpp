#include "driver.h"
#include "strlib.h"
#include <fstream>

bool buyStock(StockPortfolio& inPort, const std::string& inString) {
    auto parts = strSplit(inString, '|');
    if (parts.size() != 4) return false;
    Money purchasePrice(std::stod(parts[2]), 0);
    Stock stock(parts[1], parts[0], purchasePrice, std::stod(parts[3]));
    inPort.addStock(stock);
    return true;
}

bool updateStock(StockPortfolio& inPort, const std::string& inString) {
    auto parts = strSplit(inString, '|');
    if (parts.size() != 2) return false;
    if (!inPort.containsStock(parts[0])) return false;

    Money newPrice(std::stod(parts[1]), 0);
    inPort[parts[0]].setCurrentPrice(newPrice);
    return true;
}

bool processFile(StockPortfolio& inPort, const std::string& inString) {
    std::ifstream file(inString);
    if (!file.is_open()) return false; // Check if the file is open
    std::string line;
    while (getline(file, line)) {
        if (line[0] == '+') {
            if (!updateStock(inPort, line.substr(1))) return false;
        } else {
            if (!buyStock(inPort, line)) return false;
        }
    }
    file.close(); // Close the file after processing
    return true;
}
