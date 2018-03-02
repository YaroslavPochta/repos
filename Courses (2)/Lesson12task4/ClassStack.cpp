#include <iostream>

using namespace std;
template <typename type>
struct elem
{
	type data;
	elem* next;
	elem(type data_ = 0, elem* next_ = NULL) : data(data_), next(next_) {}; //stack(int d = 0, stack* theNext = NULL) {data = d; next = Next;}
};
template <typename type>
class Stack
{
private:
	elem <type>* head = NULL;
public:
	void print()
	{
		cout << "Stack: ";
		for (elem <type>*tmp = head; tmp != NULL; tmp = tmp->next)
			cout << tmp->data << "; ";
		cout << endl;
	}
	void push(type value)
	{
		elem<type>* newElem = new elem<type>(value, head);
		head = newElem;
	}
};

int main()
{
	Stack<char> stack;

	stack.push('f');
	stack.push('j');
	stack.push('%');
	stack.push(')');

	stack.print();

	system("pause");
	return 0;
}