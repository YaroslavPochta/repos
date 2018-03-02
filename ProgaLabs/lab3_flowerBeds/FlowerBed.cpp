#include "FlowerBed.h"



FlowerBed::FlowerBed()
{
	number = 0;
	form = "none";
	differentFlowers.push_back("empty");
}
FlowerBed::FlowerBed(int number_, string form_, vector<string> differentFlowers_)
{
	number = number_;
	form = form_;
	differentFlowers = differentFlowers_;
}

FlowerBed::~FlowerBed()
{
}
