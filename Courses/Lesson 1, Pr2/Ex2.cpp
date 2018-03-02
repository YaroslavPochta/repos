//Кодовая таблица

#include <iostream>
#include <iomanip>
using namespace std;

int main2()
{
	for (int i = 32; i < 256; i++)
	{
		if ((i - 1) % 10 == 0)
		{
			cout << endl;
		}
		else
		{
			cout << i << "=" << (char)i << '\t';
		}
	}
	cout << endl;
	system("pause");
	return 0;
}