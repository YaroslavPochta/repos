#pragma once
class Fraction
{
private:
	int numerator;
	int denominator;    //  numerator/denominator
	void modify(); // isSimle and plus/minus with numerator
public: 
	Fraction(int = 1, int = 1);
	~Fraction();
	void printToConsole() const;
	int getNumerator() const { return numerator; }
	int getDenominator() const { return denominator; }
	//void setNumerator(int value) { numerator = value; modify();}
	//void setDenominator(int value) { denominator = value; modify(); }
	void setFraction(int value1, int value2)
	{
		numerator = value1;
		denominator = value2;
		modify();
	}
	Fraction operator*(Fraction frac2);
	bool operator==(Fraction frac2);
	Fraction operator-();
	bool operator<=(Fraction frac2);
	bool operator>=(Fraction frac2);
	void operator+=(Fraction frac2);
};
Fraction operator+(Fraction frac1, Fraction frac2);   // binary operator realised like external function
bool operator!=(Fraction frac1,Fraction frac2);
ostream& operator<< (ostream& out, Fraction frac1);
istream& operator >> (istream&in, Fraction&frac);
