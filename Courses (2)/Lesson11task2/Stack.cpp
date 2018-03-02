//***********************************************                  Stack based on line list                  **********************************************//
//  push - add new items in stack                 == addToHead
//  pop  - delete item and return value           == deleteFromHead
//  top  - give top value and DON'T change it
// empty - is it empty

#include <iostream>
#include <fstream>

using namespace std;

struct elem
{
	int data;
	elem* next;
	elem(int d = 0, elem* Next = NULL) : data(d), next(Next) {}; //stack(int d = 0, stack* theNext = NULL) {data = d; next = Next;}
};
void printStruct(elem* f)
{
	cout << "List: ";
	for (elem*tmp = f; tmp != NULL; tmp = tmp->next)
		cout << tmp->data << "\t";
	cout << endl;
}
void push(elem*&stack, int value)
{
	elem* newElem = new elem(value, stack);
	stack = newElem;
}
int pop(elem*&stack)
{
	int tmp = stack->data;
	elem* delElem = stack;
	stack = stack->next;
	delete delElem;
	return tmp;
}
int top(elem*stack)
{
	return stack->data;
}
bool empty(elem*stack)
{
	return stack == NULL;
}


int main()
{
	elem* stack = new elem(7, NULL);
	
	while (!empty(stack))
		cout << "pop()=" << *(pop(stack));

	for (int i = 1; i <= 15; i++)
	{
		push(stack, i);
	}
	while (!empty(stack))
		cout << "pop()=" << pop(stack) << endl;

	printStruct(stack);
	system("pause");
	return 0;
}
