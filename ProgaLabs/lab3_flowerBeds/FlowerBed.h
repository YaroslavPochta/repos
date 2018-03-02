#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FlowerBed
{
public:
	int number;
	string form;
	vector<string> differentFlowers;
	FlowerBed();
	FlowerBed(int number_, string form_, vector<string> differentFlowers_);
	~FlowerBed();
};

