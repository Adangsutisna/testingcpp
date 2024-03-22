#include "driver.h"
#include "strlib.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

// Fungsi untuk membeli saham berdasarkan string input.
bool buyStock(StockPortfolio& inPort, const std::string& inString) {
    // Memisahkan input string berdasarkan karakter '|'.
    auto parts = strSplit(inString, '|');
    // Jika bagian tidak sama dengan 4, format input tidak valid.
    if (parts.size() != 4) {
        std::cerr << "Error: Format input tidak valid untuk pembelian saham." << std::endl;
        return false;
    }
    try {
        // Mengkonversi string ke double untuk harga dan jumlah saham.
        double priceDollars = std::stod(parts[2]); // Ini dalam dolar
        double numShares = std::stod(parts[3]);

        Money purchasePrice(priceDollars); // Mengonversi dolar ke sen
        // Membuat objek saham baru dan menambahkannya ke portofolio.
        Stock stock(parts[1], parts[0], purchasePrice, numShares);
        inPort.addStock(stock);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << " saat pembelian saham." << std::endl;
        return false;
    }
    return true;
}

// Fungsi untuk memperbarui harga saham yang sudah ada dalam portofolio.
bool updateStock(StockPortfolio& inPort, const std::string& inString) {
    // Memisahkan input string berdasarkan karakter '|'.
    auto parts = strSplit(inString, '|');
    // Jika bagian tidak sama dengan 2, format input tidak valid.
    if (parts.size() != 2) {
        std::cerr << "Error: Format input tidak valid untuk pembaruan saham." << std::endl;
        return false;
    }
    try {
        // Memeriksa apakah simbol saham ada dalam portofolio.
        if (!inPort.containsStock(parts[0])) {
            std::cerr << "Error: Simbol saham tidak ditemukan dalam portofolio." << std::endl;
            return false;
        }

        double newPriceDollars = std::stod(parts[1]); // Ini dalam dolar
        Money newPrice(newPriceDollars); // Mengonversi dolar ke sen
        // Memperbarui harga saham yang ada dengan harga baru.
        inPort[parts[0]].setCurrentPrice(newPrice);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << " saat pembaruan saham." << std::endl;
        return false;
    }
    return true;
}

// Fungsi untuk memproses file yang berisi perintah pembelian atau pembaruan saham.
bool processFile(StockPortfolio& inPort, const std::string& inString) {
    // Membuka file berdasarkan nama yang diberikan.
    std::ifstream file(inString);
    // Jika file tidak dapat dibuka, tampilkan error.
    if (!file.is_open()) {
        std::cerr << "Error: Tidak bisa membuka file " << inString << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        // Lewati baris kosong.
        if (line.empty()) continue;
        // Jika baris dimulai dengan '+', perbarui saham.
        if (line[0] == '+') {
            if (!updateStock(inPort, line.substr(1))) {
                std::cerr << "Error: Gagal memperbarui saham dengan baris: " << line << std::endl;
                return false;
            }
        } else {
            // Jika bukan, beli saham berdasarkan baris.
            if (!buyStock(inPort, line)) {
                std::cerr << "Error: Gagal membeli saham dengan baris: " << line << std::endl;
                return false;
            }
        }
    }

    file.close(); // Menutup file setelah selesai diproses.
    return true;
}

