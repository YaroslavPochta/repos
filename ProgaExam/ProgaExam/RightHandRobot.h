#include "LeftHandRobot.h"
#pragma once
class RightHandRobot : public Power
{
public:
	RightHandRobot (const int _power = 0) : Power(_power) {}
	bool operator==(const Power &a);
	bool deltaPower(const Power &a);
	void print(ostream &out = cout);
	bool operator> (const Power &a);
	bool operator< (const Power &a);
	~RightHandRobot();
};

