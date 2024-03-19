#include "driver.h"
#include <iostream>

int main() {
    StockPortfolio myPortfolio;
    std::string filename = "input/purchaseList.txt";

    // Proses file untuk membangun portofolio
    if (!processFile(myPortfolio, filename)) {
        std::cerr << "Failed to process file: " << filename << std::endl;
        return 1;
    }

    // Lakukan operasi lain seperti menampilkan portofolio atau mengupdate saham

    return 0;
}
