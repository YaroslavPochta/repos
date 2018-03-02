#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Power
{
public:
	int power;
	Power(const int _power = 0) : power(_power) {}
	virtual bool operator==(const Power&) = 0;
	virtual void print(ostream& = cout) = 0;
	virtual bool deltaPower(const Power&) = 0;
	virtual bool operator>(const Power&a) = 0;
	virtual bool operator< (const Power&a) = 0;
	~Power();
};

