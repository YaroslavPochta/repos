#include <iostream>
using namespace std;

int main()
{
	for (int i = 32; i < 256; i++)
	{
		cout << (((i - 1) % 10 == 0) ? '\n' : '\t');
		cout << i << "=" << (char)i;
	}

	system("pause");
	return 0;
}