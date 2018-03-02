#pragma once
#include "ComplexNumber.h"
struct elem
{
	ComplexNumber data;
	elem* next;
	elem(ComplexNumber d, elem* Next = NULL) : data(d), next(Next) {};
};
void printStruct(elem* f);
void push(elem*&stack, ComplexNumber value);
ComplexNumber pop(elem*&stack);
ComplexNumber top(elem*stack);
bool isEmpty(elem*stack);

 class Empty
{
public:
	Empty::Empty() {};
};