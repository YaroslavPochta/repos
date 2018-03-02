#include "Power.h"
#pragma once
class LeftHandRobot: public Power
{
public:
	LeftHandRobot(const int _power = 0) : Power(_power) {}
	bool operator==(const Power &a);
	void print(ostream &out = cout);
	bool deltaPower(const Power &a);
	bool operator>(const Power &a);
	bool operator< (const Power &a);
	~LeftHandRobot();
};

