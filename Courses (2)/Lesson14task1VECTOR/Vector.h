#pragma once
#include <ostream>
using namespace std;

class Vector
{
private:
	int *elements;
	int size;
public:
	Vector(int size = 10, int value = 0);
	~Vector();
	Vector(const Vector&);
	int getSize() const { return size; }
	int getValue(int index) const { return elements[index]; }
	Vector operator+ (Vector);
	int operator* (const Vector&);
	Vector& operator=(const Vector&);
	int& operator[](int index);
	void pushBack(int value);
};
ostream& operator<<(ostream&, Vector);
