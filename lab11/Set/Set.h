#pragma once
#include <iostream>

using namespace std;
class Set 
{
private:
	char mas[256];
	int size;
public:
	Set();
	Set(const Set &obj);
	~Set();

	void addNewElement(char element);
	bool IsItHasSuchElement(char element);
	bool isEmpty() { return (size == 0); };
	int getSize() { return size; };
	friend ostream& operator<< (ostream& os, const Set& set);
	friend istream& operator>> (istream& is, Set& set);
	void operator= (Set set2);
	Set operator* (Set set2); 
	Set operator+ (Set set2); 
	Set operator- (Set set2); 
	bool operator< (Set set2);
	bool operator== (Set set2);
};