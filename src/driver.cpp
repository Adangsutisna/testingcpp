#include "driver.h"
#include "strlib.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Memastikan stringstream dapat digunakan

bool buyStock(StockPortfolio& inPort, const std::string& inString) {
    auto parts = strSplit(inString, '|');
    if (parts.size() != 4) return false;

    try {
        double priceDollars = std::stod(parts[2]);
        double numShares = std::stod(parts[3]);

        // Membuat Money dengan nilai dolar, mengkonversinya ke sen
        Money purchasePrice(priceDollars * 100);
        
        // Memperbaiki urutan parameter sesuai definisi Stock (symbol, name, price, shares)
        Stock stock(parts[0], parts[1], purchasePrice, numShares);
        inPort.addStock(stock);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool updateStock(StockPortfolio& inPort, const std::string& inString) {
    auto parts = strSplit(inString, '|');
    if (parts.size() != 2) return false;

    if (!inPort.containsStock(parts[0])) return false;

    try {
        double newPriceDollars = std::stod(parts[1]);
        Money newPrice(newPriceDollars * 100); // Mengkonversi ke sen
        inPort[parts[0]].setCurrentPrice(newPrice);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool processFile(StockPortfolio& inPort, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        line.erase(0, line.find_first_not_of(' ')); // Trim leading whitespace
        line.erase(line.find_last_not_of(' ') + 1); // Trim trailing whitespace
        if (line.empty()) continue;

        bool result;
        if (line[0] == '+') {
            result = updateStock(inPort, line.substr(1));
        } else {
            result = buyStock(inPort, line);
        }

        if (!result) {
            std::cerr << "Failed to process line: " << line << std::endl;
            return false;
        }
    }
    return true;
}
