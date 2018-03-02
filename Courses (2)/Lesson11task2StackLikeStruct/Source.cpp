#include <iostream>
#include <fstream>
using namespace std;

struct elem
{
	char data;
	elem* next;
	elem(char d = 0, elem* Next = NULL) : data(d), next(Next) {}; //stack(int d = 0, stack* theNext = NULL) {data = d; next = Next;}
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
	char tmp = stack->data;
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

int main45()
{
	char str[] = "fghjk[ghjkl]dfghj";
	char open[] = "([{<";
	char close[] = ")]}>";
	elem* stack = NULL;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (strchr(open, str[i]) != NULL)
		{
			push(stack, str[i]);
		}
		else 
		{
			if (strchr(close, str[i]) != NULL)
			{
				if (!empty(stack))
				{
					char c = pop(stack);
					int indexOpen = strchr(open, c) - open;
					int indexClose = strchr(close, str[i]) - close;
					if (indexOpen != indexOpen)
					{
						cout << "Error 3" << endl;
						system("pause");
						return 0;
					}
				}
				else
				{
					cout << "Error 1" << endl;
					system("pause");
					return 0;
				}
			}
			else 
			{
				cout << "Error 2" << endl;
				system("pause");
				return 0;
			}
		}
	}
	if (!empty(stack))
	{
		cout << "Error 4";
		system("pause");
		return 0;
	}
	cout << "Ok" << endl;
	system("pause");
	return 0;
}
