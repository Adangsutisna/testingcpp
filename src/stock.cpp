#include "stock.h"
#include <iostream>
#include <iomanip>


Stock::Stock() : mName(""), mSymbol(""), mNumShares(0) {}

Stock::Stock(const std::string& inName, const std::string& inSymbol, 
             const Money& inPurPrice, double inNumShares)
    : mName(inName), mSymbol(inSymbol), mPurchasePrice(inPurPrice), mCurrentPrice(inPurPrice), mNumShares(inNumShares) {}

Money Stock::getCurrPrice() const {
    return mCurrentPrice;
}

Money Stock::getPurPrice() const {
    return mPurchasePrice;
}

Money Stock::getChange() const {
 return (mCurrentPrice - mPurchasePrice) * mNumShares;
}

std::string Stock::getSymbol() const {
    return mSymbol;
}

std::string Stock::getName() const {
    return mName;
}

double Stock::getNumShares() const {
    return mNumShares;
}

void Stock::setCurrentPrice(const Money& inCurrPrice) {
    mCurrentPrice = inCurrPrice;
}

std::ostream& operator<<(std::ostream& out, const Stock& stock) {
    // Menggunakan std::fixed dan std::setprecision untuk harga, tapi tidak untuk jumlah saham
    out << stock.getSymbol() << " : " << stock.getNumShares()
        << " @ $" << std::fixed << std::setprecision(2) << stock.getCurrPrice().getCents() / 100.0;
    return out;
}
