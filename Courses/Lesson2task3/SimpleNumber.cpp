//Простое или нет? Если нет, то представить в виде простых делителей
#include <iostream>
#include <stdio.h>
using namespace std;
bool isItSimple(int n)
{
	for (int i = 2; i < sqrt(n) + 1; i++)
	{
		if (n % i == 0)
			return false;
	}
}
//////////////////////////////////////////////////
void decomposition(int n, char d[])
{
	d[0] = '\0';
	int div = 2;
	while (n != 2)
	{
		while (n%div == 0)
		{
		}
		div++;
	}

}
//////////////////////////////////////////////////
int main()
{
	int n;
	cout << "Input your numeral ";
	cin >> n;
	if (isItSimple(n))
		cout << "Yes, you entered simple number" << endl;
	else
	{
		cout << "No, it isn't a simple number" << endl;
		cout << n << "=";
		for (int i = 2; i < n; i++)
		{
			while (n % i != 0)
			{
				if (n % i == 0)
				{
					cout << i << '*';
					n = n / i;
				}
			}
		}
	}

	system("pause");
	return 0;
}