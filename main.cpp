#include "driver.h"
#include <iostream>

int main() {
    StockPortfolio portfolio;
    
    // Proses file pembelian awalscsc
    // std::string purchaseListPath = "input/purchaseList.txt";
    // if (!processFile(portfolio, purchaseListPath)) {
    //     std::cerr << "Gagal memproses file pembelian: " << purchaseListPath << std::endl;
    //     return 1;
    // }
    
    // Anda dapat menambahkan logika tambahan di sini untuk memproses perubahan harga jika perlu
    // Misalnya, dengan memanggil `processFile` lagi untuk file yang berbeda atau logika tambahan untuk memproses bagian kedua file.

    // Menampilkan ringkasan portofolio
    std::cout << "Total Nilai Portofolio: $" << portfolio.getTotalValue().getCents() / 100.0 << std::endl;
    std::cout << "Total Nilai Pembelian: $" << portfolio.getOrigValue().getCents() / 100.0 << std::endl;
    std::cout << "Total Keuntungan/Kerugian: $" << portfolio.getProfit().getCents() / 100.0 << std::endl;

    return 0;
}
