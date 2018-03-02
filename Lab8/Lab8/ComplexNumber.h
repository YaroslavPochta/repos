#pragma once
#include <ostream>
using namespace std;

class ComplexNumber 
{
private:
	double re;
	double im;
public:
	ComplexNumber();
	ComplexNumber(double, double);
	ComplexNumber(const ComplexNumber&);
	~ComplexNumber();
	void setValue(double, double);
	ComplexNumber operator+(ComplexNumber);
	ComplexNumber operator-(ComplexNumber);
	ComplexNumber operator/(ComplexNumber cn);
	ComplexNumber operator*(ComplexNumber cn);
	void operator=(ComplexNumber);
	bool operator>(ComplexNumber) const;
	friend ostream& operator<< (ostream&, const ComplexNumber&);
};

