//*******************************************        Queue based on cycle (cycloid) array        ******************************************//

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
			for (int i = first; i != last; ++i)
				cout << buf[i] << "; ";
			cout << buf[last];
		}
		cout << endl;
	}
	void push(int value)
	{
		if (first == -1)
			first = 0;
		buf[++last] = value;
	}
	int pop()
	{
		int tmp = buf[first];
		if (first == last)
			first = last = -1;
		else ++first;
		return tmp;
	}

};

int main()
{
	SQueue queue;
	queue.print();

	queue.push(1);
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
	queue.print();

	system("pause");
	return 0;
}