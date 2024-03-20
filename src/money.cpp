#include "money.h"
#include <cmath> // Jika perlu untuk operasi matematika
#include <iomanip>

Money::Money() : mCents(0) {}

Money::Money(double inDollars) {
    mCents = static_cast<long long>(std::round(inDollars * 100));
}

Money::Money(long long inDollars, long long inCents) {
    mCents = (inDollars * 100) + inCents;
}

Money::Money(long long inCents) : mCents(inCents) {}

Money::Money(int inCents) : mCents(static_cast<long long>(inCents)) {}

long long Money::getCents() const {
    return mCents;
}

Money& Money::operator+=(const Money& other) {
    this->mCents += other.mCents;
    return *this;
}

Money& Money::operator-=(const Money& other) {
    this->mCents -= other.mCents;
    return *this;
}

Money& Money::operator*=(double multiplier) {
    this->mCents = static_cast<long long>(this->mCents * multiplier);
    return *this;
}

Money& Money::operator/=(double divisor) {
    if (divisor != 0) {
        this->mCents = static_cast<long long>(this->mCents / divisor);
    }
    return *this;
}

Money operator+(const Money& lhs, const Money& rhs) {
    return Money(lhs.mCents + rhs.mCents);
}

Money operator-(const Money& lhs, const Money& rhs) {
    return Money(lhs.mCents - rhs.mCents);
}

Money operator*(const Money& money, double multiplier) {
    return Money(static_cast<long long>(money.mCents * multiplier));
}

Money operator/(const Money& money, double divisor) {
    if (divisor != 0) {
        return Money(static_cast<long long>(money.mCents / divisor));
    }
    return Money();
}

bool operator==(const Money& lhs, const Money& rhs) {
    return lhs.mCents == rhs.mCents;
}

bool operator!=(const Money& lhs, const Money& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Money& lhs, const Money& rhs) {
    return lhs.mCents < rhs.mCents;
}

bool operator>(const Money& lhs, const Money& rhs) {
    return rhs < lhs;
}

bool operator<=(const Money& lhs, const Money& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const Money& lhs, const Money& rhs) {
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    double amount = money.mCents / 100.0;
    os << "$" << std::fixed << std::setprecision(2) << amount;
    return os;
}

std::istream& operator>>(std::istream& is, Money& money) {
    double amount;
    is >> amount;
    money = Money(amount);
    return is;
}
