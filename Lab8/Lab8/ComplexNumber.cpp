#include <iostream>
#include "ComplexNumber.h"
using namespace std;


ComplexNumber::ComplexNumber() 
{
	this->re = 0;
	this->im = 0;
}
ComplexNumber::ComplexNumber(double real, double imaginary) : re(real), im(imaginary) {}

ComplexNumber::~ComplexNumber() {} 

ComplexNumber::ComplexNumber(const ComplexNumber &obj) 
{
	this->re = obj.re;
	this->im = obj.im;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber cn) 
{
	ComplexNumber result;
	result.re = this->re + cn.re;
	result.im = this->im + cn.im;
	return result;
}
ComplexNumber ComplexNumber:: operator-(ComplexNumber cn)
{
	ComplexNumber result;
	result.re = this->re - cn.re;
	result.im = this->im - cn.im;
	return result;
}
ComplexNumber ComplexNumber:: operator/(ComplexNumber cn)
{
	ComplexNumber result;
	if ((this->im == 0) && (this->re == 0))
	{
		this->re = 0;
		this->im = 0;
		return result;
	}
	if ((cn.re == 0) && (cn.im == 0))
	{
		cout << "Uncorrect operatoin" << endl;
		system("pause");
		return result;
	}
	result.re = ((this->re)*(cn.re) + ((this->im)*(cn.im)) / ((cn.re)*(cn.re) + (cn.im)*(cn.im)));
	result.im = ((this->im)*(cn.re) - ((this->re)*(cn.im)) / ((cn.re)*(cn.re) + (cn.im)*(cn.im)));
	return result;
}
ComplexNumber ComplexNumber::operator*(ComplexNumber cn)
{
	ComplexNumber result;
	if (((this->im == 0) && (this->re == 0)) || ((cn.re == 0) && (cn.im == 0)))
	{
		this->re = 0;
		this->im = 0;
		return result;
	}
	result.re = ((this->re)*(cn.re) - ((this->im)*(cn.im)));
	result.im = ((this->im)*(cn.re) + ((this->re)*(cn.im)));
	return result;
}

void ComplexNumber::setValue(double real, double imaginary) 
{
	this->re = real;
	this->im = imaginary;
}

void ComplexNumber::operator=(ComplexNumber cn) 
{
	this->re = cn.re;
	this->im = cn.im;
}

bool ComplexNumber::operator>(ComplexNumber cn) const 
{
	if (sqrt(pow(this->re, 2) + pow(this->im, 2)) > sqrt(pow(cn.re, 2) + pow(cn.im, 2)))
		return true;
	else
		return false;
}

ostream& operator<< (ostream& out, const ComplexNumber& cn) {
	cout << cn.re;

	if (cn.im >= 0)
		cout << " + ";
	
	cout << cn.im << "i ";
	return out;
}