#include "stock.h"
#include <iostream>
#include <iomanip>

// Konstruktor default: Inisialisasi nama, simbol, dan jumlah saham dengan nilai default.
Stock::Stock() : mName(""), mSymbol(""), mNumShares(0) {}

// Konstruktor dengan parameter: Menginisialisasi saham dengan nama, simbol, harga pembelian, dan jumlah saham.
Stock::Stock(const std::string& inName, const std::string& inSymbol, 
             const Money& inPurPrice, double inNumShares)
    : mName(inName), mSymbol(inSymbol), mPurchasePrice(inPurPrice), mCurrentPrice(inPurPrice), mNumShares(inNumShares) {}

// Mengembalikan harga saham saat ini.
Money Stock::getCurrPrice() const {
    return mCurrentPrice;
}

// Mengembalikan harga pembelian saham.
Money Stock::getPurPrice() const {
    return mPurchasePrice;
}

// Menghitung dan mengembalikan perubahan harga saham dari harga pembelian.
Money Stock::getChange() const {
 return (mCurrentPrice - mPurchasePrice) * mNumShares;
}

// Mengembalikan simbol saham.
std::string Stock::getSymbol() const {
    return mSymbol;
}

// Mengembalikan nama saham.
std::string Stock::getName() const {
    return mName;
}

// Mengembalikan jumlah saham.
double Stock::getNumShares() const {
    return mNumShares;
}

// Mengatur harga saham saat ini.
void Stock::setCurrentPrice(const Money& inCurrPrice) {
    mCurrentPrice = inCurrPrice;
}

// Operator overloading untuk mencetak objek saham.
// Menampilkan simbol, jumlah saham, dan harga saham saat ini dengan format tertentu.
std::ostream& operator<<(std::ostream& out, const Stock& stock) {
    // Menggunakan std::fixed dan std::setprecision untuk menampilkan harga dengan dua digit di belakang koma.
    out << stock.getSymbol() << " : " << stock.getNumShares()
        << " @ $" << std::fixed << std::setprecision(2) << stock.getCurrPrice().getCents() / 100.0;
    return out;
}