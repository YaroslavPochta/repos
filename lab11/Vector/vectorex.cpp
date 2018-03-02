/*#include "vectorex.h"
template <typename type>
vectorex<type>::vectorex(int size, type value) :size(size)
{
	elements = new type[size];
	for (int i = 0; i < size; i++)
		elements[i] = value;
}
template <typename type>
vectorex<type>::vectorex<type>(const vectorex<type>& v)
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
void vectorex<type>:: pushFront(type& value)
{
	type* newElements = new type[size + 1];
	memcpy((newElements+1), elements, size * sizeof(type));
	newElements[0] = value;
	size++;
	delete[] elements;
	elements = newElements;
}
template <typename type>
void vectorex<type>:: popFront()
{
	size--;
	type* newElements = new type[size];
	memcpy(newElements, (elements+1), size * sizeof(type));
	delete[] elements;
	elements = newElements;
}*/