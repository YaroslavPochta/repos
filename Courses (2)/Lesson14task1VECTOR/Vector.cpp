#include <ostream>
#include "Vector.h"
using namespace std;

template <typename type>
Vector::Vector(const Vector& v)
{
	size = v.size;
	elements = new type[size];
	for (int i = 0; i < size; i++)
		elements[i] = v.elements[i];
}

template <typename type>
Vector::Vector(int size, int value):size(size)
{
	elements = new type[size];
	for (int i = 0; i < size; i++)
		elements[i] = value;
}


Vector::~Vector()
{
	delete[] elements;
}
ostream& operator<< (ostream& out, Vector v)
{// v - copy v1
	for (int i = 0; i < v.getSize(); i++)
		out << v.getValue(i) << " ";
	return out;
} 
Vector Vector ::operator+ (Vector v2)
{
	int size1 = (size <= v2.size) ? size : v2.size;
	Vector tmp(size1);
	for (int i = 0; i < size1; i++)
		tmp.elements[i] = elements[i] + v2.elements[i];
	return tmp;
}
int Vector ::operator* (const Vector& v2)
{
	int size1 = (size <= v2.size) ? size : v2.size;
	int tmp = 0;
	for (int i = 0; i < size1; i++)
		tmp += (elements[i] * v2.elements[i]);
	return tmp;
}
Vector& Vector::operator=(const Vector& v2)
{
	if (this != &v2)  // защита от самоприсваивания
	{
		delete[] elements;
		size = v2.size;
		elements = new int[size];
		for (int i = 0; i < size; i++)
			elements[i] = v2.elements[i];
	}
	return *this;
}
int &Vector ::operator[](int index)
{
	return elements[index];
}
void Vector::pushBack(int value)
{
	int* newElements = new int[size+1];
	memcpy(newElements, elements, size * sizeof(int));
	newElements[size] = value;
	size++;
	delete[] elements;
	elements = newElements;
}