#pragma once

#include <iostream>


class Money
{
private:
	long long mCents;

public:
	// Constructors
	Money();
	Money(long long inDollars, long long inCents);
	Money(double inDollars);
	Money(long long inCents);
	Money(int inCents);

    long long getCents() const;

    // Getter for testing
	long long getCents();

	// Arithmetic assignment operators
	Money& operator+=(const Money& right);
	Money& operator-=(const Money& right);
	Money& operator*=(double right);
	Money& operator/=(double right);

	// Comparison operators
	friend bool operator<(const Money& left, const Money& right);
	friend bool operator>(const Money& left, const Money& right);
	friend bool operator<=(const Money& left, const Money& right);
	friend bool operator>=(const Money& left, const Money& right);
	friend bool operator==(const Money& left, const Money& right);
	friend bool operator!=(const Money& left, const Money& right);

	// Binary arithmetic operators
	friend Money operator+(const Money& left, const Money& right);
	friend Money operator-(const Money& left, const Money& right);
	friend Money operator*(const Money& left, double right);
	friend Money operator/(const Money& left, double right);

	// Stream operators
	friend std::ostream& operator<<(std::ostream& out, const Money& money);
	friend std::istream& operator>>(std::istream& in, Money& money);
};

