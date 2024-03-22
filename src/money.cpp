#include "money.h"
#include <iomanip>

// Konstruktor default yang menginisialisasi jumlah uang menjadi 0 sen.
Money::Money() : mCents(0) {}

// Konstruktor yang mengonversi dolar menjadi sen dan menginisialisasi jumlah uang.
Money::Money(double inDollars) {
    mCents = static_cast<long long>(inDollars * 100);
}

// Konstruktor yang menerima dolar dan sen, mengonversinya menjadi sen, dan menginisialisasi jumlah uang.
Money::Money(long long inDollars, long long inCents) {
    mCents = inDollars * 100 + inCents;
}

// Konstruktor yang menerima sen dan menginisialisasi jumlah uang dengan sen tersebut.
Money::Money(long long inCents) : mCents(inCents) {}

// Konstruktor yang menerima sen dalam tipe data int dan menginisialisasi jumlah uang dengan sen tersebut.
Money::Money(int inCents) : mCents(static_cast<long long>(inCents)) {}

// Fungsi untuk mendapatkan jumlah sen dari objek Money.
long long Money::getCents() const {
    return mCents;
}

// Operator overloading untuk menambahkan objek Money lain ke objek ini.
Money& Money::operator+=(const Money& right) {
    mCents += right.mCents;
    return *this;
}

// Operator overloading untuk mengurangi objek Money lain dari objek ini.
Money& Money::operator-=(const Money& right) {
    mCents -= right.mCents;
    return *this;
}

// Operator overloading untuk mengalikan objek Money ini dengan sebuah bilangan double.
Money& Money::operator*=(double right) {
    mCents = static_cast<long long>(mCents * right);
    return *this;
}

// Operator overloading untuk membagi objek Money ini dengan sebuah bilangan double.
Money& Money::operator/=(double right) {
    mCents = static_cast<long long>(mCents / right);
    return *this;
}

// Operator overloading untuk menambahkan dua objek Money.
Money operator+(const Money& left, const Money& right) {
    return Money(left.mCents + right.mCents);
}

// Operator overloading untuk mengurangi dua objek Money.
Money operator-(const Money& left, const Money& right) {
    return Money(left.mCents - right.mCents);
}

// Operator overloading untuk mengalikan objek Money dengan sebuah bilangan double.
Money operator*(const Money& left, double right) {
    return Money(static_cast<long long>(left.mCents * right));
}

// Operator overloading untuk membagi objek Money dengan sebuah bilangan double.
Money operator/(const Money& left, double right) {
    return Money(static_cast<long long>(left.mCents / right));
}

// Operator overloading untuk membandingkan kesamaan antara dua objek Money.
bool operator==(const Money& left, const Money& right) {
    return left.mCents == right.mCents;
}

// Operator overloading untuk membandingkan ketidaksamaan antara dua objek Money.
bool operator!=(const Money& left, const Money& right) {
    return !(left == right);
}

// Operator overloading untuk membandingkan apakah objek Money kiri lebih kecil dari yang kanan.
bool operator<(const Money& left, const Money& right) {
    return left.mCents < right.mCents;
}

// Operator overloading untuk membandingkan apakah objek Money kiri lebih besar dari yang kanan.
bool operator>(const Money& left, const Money& right) {
    return right < left;
}

// Operator overloading untuk membandingkan apakah objek Money kiri lebih kecil atau sama dengan yang kanan.
bool operator<=(const Money& left, const Money& right) {
    return !(left > right);
}

// Operator overloading untuk membandingkan apakah objek Money kiri lebih besar atau sama dengan yang kanan.
bool operator>=(const Money& left, const Money& right) {
    return !(left < right);
}

// Operator overloading untuk mencetak objek Money ke stream output.
std::ostream& operator<<(std::ostream& out, const Money& money) {
    double amount = money.mCents / 100.0;
    out << "$" << std::fixed << std::setprecision(2) << amount;
    return out;
}

// Operator overloading untuk membaca nilai dolar dari
std::istream& operator>>(std::istream& in, Money& money) {
    double inDollars;
    in >> std::fixed >> std::setprecision(2) >> inDollars;
    money = Money(inDollars);
    return in;
}