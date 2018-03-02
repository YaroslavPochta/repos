/*#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class Bus
{
public:
	int numberOfBus;
	string modelOfBus;
	Bus() { numberOfBus = 0, modelOfBus = '\0'; };
	Bus(int number, string model) { numberOfBus = number; modelOfBus = model; }
	friend ostream& operator<< (ostream& stream, Bus& bus);
	~Bus();
};

*/