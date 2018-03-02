#include <iostream>
#include <ostream>
using namespace std;
#include "Fraction.h"


Fraction::Fraction(int a, int b) : numerator(a), denominator(b)
{
	modify();
}

Fraction::~Fraction() {}

void Fraction::printToConsole() const
{
	cout << "Fraction = " << numerator << "/" << denominator << endl;
}
Fraction operator+(Fraction frac1, Fraction frac2)
{
	return Fraction(frac1.getNumerator()*frac2.getDenominator() + frac1.getDenominator()*frac2.getNumerator(), frac1.getDenominator()*frac2.getDenominator());
}
void Fraction::modify()
{
	if (numerator != 0)
	{
		int a = abs(numerator);
		int b = abs(denominator);
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		numerator = numerator / a;
		denominator = denominator / b;
		if ((denominator*numerator) > 0)
		{
			numerator = abs(numerator);
			denominator = abs(denominator);
		}
		else
		{
			numerator = -abs(numerator);
			denominator = abs(denominator);
		}
	}
	else denominator = 1;
}
Fraction Fraction :: operator* (Fraction frac2)
{
	return Fraction(numerator*frac2.numerator, denominator*frac2.denominator);
}
bool Fraction :: operator==(Fraction frac2)
{
	return ((numerator == frac2.numerator) && (denominator == frac2.denominator));
}
bool operator!=(Fraction frac1, Fraction frac2)
{
	return !(frac1 == frac2);
}
Fraction Fraction ::operator-()
{
	return Fraction(-numerator, denominator);
}
bool Fraction :: operator<=(Fraction frac2)
{
	Fraction difference = (*this) + -frac2;
	return difference.numerator <= 0;
}
bool Fraction :: operator>=(Fraction frac2)
{
	Fraction difference = (*this) + -frac2;
	return difference.numerator >= 0;
}
ostream& operator<<(ostream& out, Fraction frac)
{
	int a = frac.getNumerator();
	if (a == 0)
	{
		out << "0";
		return out;
	}
	int b = frac.getDenominator();
	if (a < 0)
	{
		cout << "";
		a = -a;
	}
	if (a >= b)
		out << a / b << " ";
	if (b != 1)
		out << a % b << "/" << b;
	return out;
}
istream& operator >> (istream&in, Fraction&frac)
{ // [-] a / b
	int a;
	int b;
	in >> a;
	in.ignore(1);
	in >> b;
	frac = Fraction(a, b);
	frac.setFraction(a, b);

	return in;
}
void Fraction::operator+= (Fraction frac2)
{
	*this = *this + frac2;
}