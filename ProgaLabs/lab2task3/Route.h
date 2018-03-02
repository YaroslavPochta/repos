#pragma once
#pragma warning(disable:4786)
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <utility>
using namespace std;
class Route
{
public:
	int routeNumber;
	string driver;
	//Bus busInfo;
	pair<int, string> busInfo;
	Route() { routeNumber = 0; driver = '\0'; busInfo.first = 0; busInfo.second = '\0'; };
	friend ostream& operator<< (ostream& stream, Route& rt);
	friend ostream& operator<< (ostream& stream, pair<int, string> p);
	~Route();
};

