#include "money.h"

Money::Money()
{
	// TODO: Complete function
}

Money::Money(double inDollars)
{
	// TODO: Complete function
}

Money::Money(long long inDollars, long long inCents)
{
	// TODO: Complete function
}

Money::Money(long long inCents)
{
	// TODO: Complete function
}

Money::Money(int inCents)
{
	// TODO: Complete function
}

long long Money::getCents()
{
	// TODO: Fix return value
	return 0;
}

Money& Money::operator+=(const Money& right)
{
	// TODO: Fix return value
	return *(new Money());
}

Money& Money::operator-=(const Money& right)
{
	// TODO: Fix return value
	return *(new Money());
}

Money& Money::operator*=(double right)
{
	// TODO: Fix return value
	return *(new Money());
}

Money& Money::operator/=(double right)
{
	// TODO: Fix return value
	return *(new Money());
}

Money operator+(const Money& left, const Money& right)
{
	// TODO: Fix return value
	return Money();
}

Money operator-(const Money& left, const Money& right)
{
	// TODO: Fix return value
	return Money();
}

Money operator*(const Money& left, double right)
{
	// TODO: Fix return value
	return Money();
}

Money operator/(const Money& left, double right)
{
	// TODO: Fix return value
	return Money();
}

bool operator==(const Money& left, const Money& right)
{
	// TODO: Fix return value
	return false;
}

bool operator!=(const Money& left, const Money& right)
{
	// TODO: Fix return value
	return false;
}

bool operator<(const Money& left, const Money& right)
{
	// TODO: Fix return value
	return false;
}

bool operator>(const Money& left, const Money& right)
{
	// TODO: Fix return value
	return false;
}
bool operator<=(const Money& left, const Money& right)
{
	// TODO: Fix return value
	return false;
}

bool operator>=(const Money& left, const Money& right)
{
	// TODO: Fix return value
	return false;
}

std::ostream& operator<<(std::ostream& out, const Money& money)
{
	// TODO: Fix return value
	return out;
}

std::istream& operator>>(std::istream& in, Money& money)
{
	// TODO: Fix return value
	return in;
}

