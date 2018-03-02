#include <iostream>
using namespace std;

template <typename type
struct SQueue
{
	type buf[100];  // elements
	int last = -1; //index of the last element
	void print()
	{
		cout << "Queue: ";
		for (int i = 0; i <= last; i++)
			cout << buf[i] << ", ";
		cout << endl;
	}
	void push(type value) // add to queue
	{
		buf[(++last)] = value;
	}
	type pop()
	{
		type tmp = buf[0];
		--last;
		for (int i = 0; i <= last; i++)
			buf[i] = buf[i + 1];
		return tmp;
	}

};

int main()
{
	SQueue <int>queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);

	queue.print();

	cout << "pop = " << queue.pop() << endl;
	queue.print();

	system("pause");
	return 0;
}
