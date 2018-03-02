#include <iostream>
using namespace std;

struct Selem // list
{
	int data;
	Selem* next;
	Selem(int d = 0, Selem* p = NULL) :data(d), next(p) {}
};
void printStruct(Selem* f)
{
	cout << "List: ";
	for (Selem*tmp = f; tmp != NULL; tmp = tmp->next)
		cout << tmp->data << "\t";
	cout << endl;
}
void addToTail(Selem* &f, int value)
{
	Selem* newElem = new Selem(value, NULL);
	if (f == NULL)
		f = newElem;
	else
	{
		Selem*tmp = f;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newElem;
	}
}
void addToHead(Selem* &f, int value)
{
	Selem* newElem = new Selem(value, f);
	f = newElem;
}
void deleteFromHead(Selem* &f)
{
	if (f == NULL)
	{
		cout << "Error! This list is empty!\n";
		return;
	}
	Selem* delElem = f;
	f = f->next;
	delete delElem;
}
void deleteFromTail(Selem* &f)
{
	if (f == NULL)
	{
		cout << "You are stupid! You tried to delete empty list!\n";
		return;
	}
	if (f->next == NULL)
	{
		delete f; // or deleteFromHead(f);
		f = NULL;
	}
	else
	{
		Selem* tmp = f;
		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		delete tmp->next;
		tmp->next = NULL;
	}
}
void clear(Selem* &f)
{
	while (f != NULL)
		deleteFromHead(f);
}
int main()
{
	Selem* first;
	first = new Selem;
	first->data = 7;
	first->next = new Selem;
	first->next->data = 13;
	first->next->next = NULL;

	printStruct(first);

	first = NULL;
	printStruct(first);
	addToTail(first, 1);
	addToTail(first, 2);
	addToTail(first, 3);
	addToTail(first, 4);
	addToTail(first, 5);
	printStruct(first);


	deleteFromTail(first);
	printStruct(first);
	deleteFromTail(first);
	printStruct(first);
	deleteFromTail(first);
	deleteFromTail(first);
	printStruct(first);
	deleteFromTail(first);
	printStruct(first);
	deleteFromTail(first);
	printStruct(first);

	printStruct(first);

	system("pause");
	return 0;
}