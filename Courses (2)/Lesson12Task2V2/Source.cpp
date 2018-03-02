#include <iostream>
using namespace std;

struct SQueue
{
	int buf[5];
	int size = 5;
	int first = -1;
	int last = -1;           // SQueue() {size = 100; first = last = -1;}
	void print()
	{
		cout << "Queue(" << first << "; " << last << ") = ";
		if (first != -1)
		{
			for (int i = first; i != last; i = (i == (size - 1)) ? 0 : ++i)
				cout << buf[i] << "; ";
			cout << buf[last];
		}
		cout << endl;
	}
	void push(int value)
	{
		if (first == -1)
			first = 0;
		last = (last == (size - 1)) ? 0 : ++last;
		buf[last] = value;
	}
	int pop()
	{
		int tmp = buf[first];
		if (first == last)
			first = last = -1;
		else first = (first == (size - 1)) ? 0 : ++first;
		return tmp;
	}

};

int main()
{
	SQueue queue;

	// empty queue
	for (int i = 0; i < 9; i++)
	{
		queue.push(i+1);
		queue.push(i+1);
		queue.print();
		cout << "Pop = " << queue.pop() << endl;
		queue.print();
	}
		
		
	/*queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);

	queue.print();

	cout << "Pop = " << queue.pop() << endl;
	queue.print();
	cout << "Pop = " << queue.pop() << endl;
	queue.print();
	cout << "Pop = " << queue.pop() << endl;
	queue.print();
	cout << "Pop = " << queue.pop() << endl;
	queue.print();
	cout << "Pop = " << queue.pop() << endl;
	queue.print();*/

	system("pause");
	return 0;
}