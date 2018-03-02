#include <iostream>
#define USING_MATH_DEFINES
#include "complexNumberStack.h"
#include "ComplexNumber.h"
ComplexNumber cn(0, 0);
void printStruct(elem* f)
{
	cout << "Stack: ";
	for (elem*tmp = f; tmp != NULL; tmp = tmp->next)
		cout << tmp->data << "\t";
	cout << endl;
}
void push(elem*&top, ComplexNumber value)
{
	elem* newElem = new elem(value, top);
	top = newElem;
}
ComplexNumber pop(elem*&top)
{
	if (isEmpty(top) == true) 
	{
		throw Empty();
	}
	cout << "pop = " << isEmpty(top);
	ComplexNumber tmp = top->data;
	elem* delElem = top;
	top = top->next;
	delete delElem;
	return tmp;
}
ComplexNumber top(elem*top)
{
	return top->data;
}
bool isEmpty(elem* top)
{
	return top == NULL;
}
