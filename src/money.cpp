#include "money.h"
#include <iomanip>
#include <cmath> // Untuk std::round

Money::Money() : mCents(0) {}

Money::Money(double inDollars) {
    mCents = static_cast<long long>(std::round(inDollars * 100));
}

Money::Money(long long inDollars, long long inCents) {
    mCents = inDollars * 100 + inCents;
}

Money::Money(long long inCents) : mCents(inCents) {}

Money::Money(int inCents) : mCents(static_cast<long long>(inCents)) {}

long long Money::getCents() const {
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
    double tempResult = mCents * right;
    mCents = static_cast<long long>(std::round(tempResult));
    return *this;
}

Money& Money::operator/=(double right) {
    double tempResult = static_cast<double>(mCents) / right;
    mCents = static_cast<long long>(std::round(tempResult));
    return *this;
}

Money operator+(const Money& left, const Money& right) {
    return Money(left.mCents + right.mCents);
}

Money operator-(const Money& left, const Money& right) {
    return Money(left.mCents - right.mCents);
}

Money operator*(const Money& left, double right) {
    double tempResult = left.mCents * right;
    return Money(static_cast<long long>(std::round(tempResult)));
}

Money operator/(const Money& left, double right) {
    double tempResult = static_cast<double>(left.mCents) / right;
    return Money(static_cast<long long>(std::round(tempResult)));
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
    double amount = money.mCents / 100.0;
    out << "$" << std::fixed << std::setprecision(2) << amount;
    return out;
}

std::istream& operator>>(std::istream& in, Money& money) {
    double inDollars;
    in >> inDollars;
    money = Money(inDollars);
    return in;
}
