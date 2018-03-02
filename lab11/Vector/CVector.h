﻿#pragma once
#include <ostream>
using namespace std;

template <typename type>
class Vector
{
private:

public:
	type *elements;
	int size;
	Vector(int size = 10, int value = 0);
	~Vector();
	Vector(const Vector<type>&);
	int getSize() { return size; }
	int* getElements() { return elements; }
	void setSize(int value) { size = value; }
	void setElements(int* newElem) { elements = newElem; }
	//type getValue(int index);
	type operator* (const Vector<type>&);
	Vector& operator=(const Vector<type>&);
	Vector<type> operator+(Vector<type> v2);
	type& operator[](int index);
	void pushBack(type value);
};
template <typename type>
ostream& operator<<(ostream&, Vector<type>);
#include <ostream>
#include "CVector.h"
using namespace std;

template <typename type>
Vector<type>::Vector(const Vector& v)
{
	size = v.size;
	elements = new type[size];
	for (int i = 0; i < size; i++)
		elements[i] = v.elements[i];
}
template <typename type>
Vector<type>::Vector(int size, int value) :size(size)
{
	elements = new type[size];
	for (int i = 0; i < size; i++)
		elements[i] = value;
}
template <typename type>
Vector<type>::~Vector()
{
	delete[] elements;
}
template <typename type>
ostream& operator<<(ostream& out, Vector<type> v)
{// v - copy v1
	for (int i = 0; i < v.getSize(); i++)
		out << v[i] << " ";
	return out;
}
template <typename type>
Vector<type> Vector<type>::operator+(Vector<type> v2)
{
	int size1 = (size <= v2.size) ? size : v2.size;
	Vector<type> tmp(size1);
	for (int i = 0; i < size1; i++)
		tmp.elements[i] = elements[i] + v2.elements[i];
	return tmp;
}
template <typename type>
type Vector<type>::operator*(const Vector<type>& v2)
{
	int size1 = (size <= v2.size) ? size : v2.size;
	type tmp = 0;
	for (int i = 0; i < size1; i++)
		tmp += (elements[i] * v2.elements[i]);
	return tmp;
}
template <typename type>
Vector<type>& Vector<type>::operator=(const Vector& v2)
{
	if (this != &v2)  // защита от самоприсваивания
	{
		delete[] elements;
		size = v2.size;
		elements = new type[size];
		for (int i = 0; i < size; i++)
			elements[i] = v2.elements[i];
	}
	return *this;
}
template <typename type>
type& Vector<type> ::operator[](int index)
{
	return elements[index];
}
template <typename type>
void Vector<type>::pushBack(type value)
{
	type* newElements = new type[size + 1];
	memcpy(newElements, elements, size * sizeof(type));
	newElements[size] = value;
	size++;
	delete[] elements;
	elements = newElements;
}