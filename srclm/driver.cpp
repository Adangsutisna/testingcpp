#include "driver.h"
#include "strlib.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

bool buyStock(StockPortfolio& inPort, const std::string& inString) {
    auto parts = strSplit(inString, '|');
    if (parts.size() != 4) return false;

    try {
        // Penggunaan std::stod disini adalah benar, tetapi kita perlu pastikan bahwa konversi ke Money sesuai
        // Mengingat std::stod(parts[2]) sudah merupakan nilai dolar, kita harus mengalikannya dengan 100 saat membuat objek Money
        Money purchasePrice(std::stod(parts[2]) * 100);  // Mengubah dolar ke sen
        double numShares = std::stod(parts[3]);  // Jumlah saham bisa berupa desimal

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
        Money newPrice(std::stod(parts[1]) * 100);  // Sama seperti di atas, konversi ke sen
        inPort[parts[0]].setCurrentPrice(newPrice);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool processFile(StockPortfolio& inPort, const std::string& inString) {
    std::ifstream file(inString);
    if (!file) {
        std::cerr << "Failed to open file: " << inString << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        // Menghilangkan whitespace di awal dan akhir
        line.erase(0, line.find_first_not_of(' '));  // Trim leading space
        line.erase(line.find_last_not_of(' ') + 1);  // Trim trailing space

        if (line.empty()) continue; // Skip empty lines

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
