#include "driver.h"
#include "strlib.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

bool buyStock(StockPortfolio& inPort, const std::string& inString) {
    auto parts = strSplit(inString, '|');
    if (parts.size() != 4) {
        std::cerr << "Error: Invalid input format for buying stock." << std::endl;
        return false;
    }
    try {
        // Perhatikan bahwa std::stod akan mengkonversi string ke double dengan benar
        double priceDollars = std::stod(parts[2]); // Ini dalam dolar
        double numShares = std::stod(parts[3]);

        Money purchasePrice(priceDollars * 100); // Mengonversi dolar ke sen
        Stock stock(parts[0], parts[1], purchasePrice, numShares);
        inPort.addStock(stock);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << " during stock purchase." << std::endl;
        return false;
    }
    return true;
}

bool updateStock(StockPortfolio& inPort, const std::string& inString) {
    auto parts = strSplit(inString, '|');
    if (parts.size() != 2) {
        std::cerr << "Error: Invalid input format for updating stock." << std::endl;
        return false;
    }
    try {
        if (!inPort.containsStock(parts[0])) {
            std::cerr << "Error: Stock symbol not found in portfolio." << std::endl;
            return false;
        }

        double newPriceDollars = std::stod(parts[1]); // Ini dalam dolar
        Money newPrice(newPriceDollars * 100); // Mengonversi dolar ke sen
        inPort[parts[0]].setCurrentPrice(newPrice);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << " during stock update." << std::endl;
        return false;
    }
    return true;
}

bool processFile(StockPortfolio& inPort, const std::string& inString) {
    std::ifstream file(inString);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << inString << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines
        if (line[0] == '+') {
            if (!updateStock(inPort, line.substr(1))) {
                std::cerr << "Error: Failed to update stock with line: " << line << std::endl;
                return false;
            }
        } else {
            if (!buyStock(inPort, line)) {
                std::cerr << "Error: Failed to buy stock with line: " << line << std::endl;
                return false;
            }
        }
    }
    return true;
}
