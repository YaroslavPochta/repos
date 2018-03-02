#pragma once
#include "CVector.h"
template <typename type>
class vectorex: public Vector<type>
{
private:
	type* elements;
public:
	vectorex(int size = 10, type value = 0);
	~vectorex();
	vectorex(const vectorex<type>& v);
	void pushFront(type value);
	void popFront();

};
template <typename type>
vectorex<type>::vectorex(int size, type value)// :size(size)
{
	elements = new type[size];
	for (int i = 0; i < size; i++)
		elements[i] = value;
}
template <typename type>
vectorex<type>::vectorex(const vectorex<type>& v)
{
	size = v.size;
	elements = new type[size];
	for (int i = 0; i < size; i++)
		elements[i] = v.elements[i];
}
template <typename type>
vectorex<type>::~vectorex()
{
	delete[] elements;
}
template <typename type>
void vectorex<type>::pushFront(type value)
{
	type* newElements = new type[size + 1];
	for (int i = 0; i < size; i++)
		newElements[i+1] = elements[i]; 
	//memcpy((newElements + 1), elements, size * sizeof(type));
	newElements[0] = value;
	size++;
	delete[] elements;
	elements = newElements;
	//setSize(size);
	//setElements(newElements);
}
template <typename type>
void vectorex<type>::popFront()
{
	size--;
	type* newElements = new type[size];
	//memcpy(newElements, (elements + 1), size * sizeof(type));
	for (int i = 0; i < size; i++)
		newElements[i] = elements[i + 1];

	delete[] elements;
	elements = newElements;
	//setSize(size);
	//setElements(newElements);
}
