#include "LeftHandRobot.h"
#include "RightHandRobot.h"

LeftHandRobot::~LeftHandRobot() {}
void LeftHandRobot:: print(ostream &out) 
{
	out << "Left hand robot's power is " << power << endl;
}
bool LeftHandRobot:: operator==(const Power &a) 
{
	return (power == a.power);
}
bool LeftHandRobot:: deltaPower(const Power &a) 
{
	int power1 = this->power;
	int power2 = a.power;
	if ((abs(power1 - power2) <= 1) && (dynamic_cast<const RightHandRobot*>(&a)))
		return 1;
	return 0;
}
bool LeftHandRobot :: operator>(const Power &a)
{
	if (this->power > a.power)
		return true;
	else return false;
}
bool LeftHandRobot:: operator< (const Power &a)
{
	if (this->power < a.power)
		return true;
	else return false;
}