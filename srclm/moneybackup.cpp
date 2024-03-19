#include "money.h"
#include <iomanip> 

Money::Money() : mCents(0) {}

Money::Money(double inDollars) {
    mCents = static_cast<long long>(inDollars * 100);
}

Money::Money(long long inDollars, long long inCents) {
    mCents = inDollars * 100 + inCents;
}

Money::Money(long long inCents) : mCents(inCents) {}

Money::Money(int inCents) : mCents(static_cast<long long>(inCents)) {}

long long Money::getCents() {
    return mCents;
}

Money& Money::operator+=(const Money& right) {
    mCents += right.mCents;
    return *this;
}

Money& Money::operator-=(const Money& right) {
    mCents -= right.mCents;
    return *this;
}

Money& Money::operator*=(double right) {
    mCents = static_cast<long long>(mCents * right);
    return *this;
}

Money& Money::operator/=(double right) {
    mCents = static_cast<long long>(mCents / right);
    return *this;
}

Money operator+(const Money& left, const Money& right) {
    return Money(left.mCents + right.mCents);
}

Money operator-(const Money& left, const Money& right) {
    return Money(left.mCents - right.mCents);
}

Money operator*(const Money& left, double right) {
    return Money(static_cast<long long>(left.mCents * right));
}

Money operator/(const Money& left, double right) {
    return Money(static_cast<long long>(left.mCents / right));
}

bool operator==(const Money& left, const Money& right) {
    return left.mCents == right.mCents;
}

bool operator!=(const Money& left, const Money& right) {
    return !(left == right);
}

bool operator<(const Money& left, const Money& right) {
    return left.mCents < right.mCents;
}

bool operator>(const Money& left, const Money& right) {
    return right < left;
}

bool operator<=(const Money& left, const Money& right) {
    return !(left > right);
}

bool operator>=(const Money& left, const Money& right) {
    return !(left < right);
}

std::ostream& operator<<(std::ostream& out, const Money& money) {
    double amount = money.mCents / 100.0; // Mengonversi sen ke dolar
    out << "$" << std::fixed << std::setprecision(2) << amount; // Menetapkan format output
    return out;
}

std::istream& operator>>(std::istream& in, Money& money) {
    double inDollars;
    in >> inDollars;
    money = Money(inDollars);
    return in;
}


