#include "RightHandRobot.h"
RightHandRobot::~RightHandRobot() {}
bool RightHandRobot:: operator==(const Power &a) 
{
	return power == a.power;
}
bool RightHandRobot:: deltaPower(const Power &a)
{
	int power1 = this->power; 
	int power2 = a.power;
	if ((abs(power1 - power2) <= 1) && (dynamic_cast<const LeftHandRobot*>(&a)))
		return 1;
	return 0;
}
void RightHandRobot:: print(ostream &out)
{
	out << "Right hand robot's power is " << power << endl;
} 
bool RightHandRobot :: operator>(const Power &a)
{
	if (this->power > a.power)
		return true;
	else return false;
}
bool RightHandRobot:: operator< (const Power &a)
{
	if (this->power < a.power)
		return true;
	else return false;
}