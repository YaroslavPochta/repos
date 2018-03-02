#include <iostream>
#include <stdio.h>

using namespace std;
int decomposition (int n, int Div[])
{
	int indexDiv = 0;
	for (int div = 2; n!=1; div++)
	{
		while (n%div == 0)
		{
			Div[indexDiv++] = div;
			n = n / div;
		}
	}
	return indexDiv;
}
int main()
{
	int n = 0;
	cout << "Input your value " << endl;
	cin >> n;

	int A[100];
	int countDiv = decomposition(n, A);

	int len = 1;

	cout << n << '=';
	for (int i = 0; i < countDiv; i++)
	{
		if ((i != countDiv-1)&&(A[i] == A[i + 1]))
			len++;
		else
		{
			cout << A[i];
			if (len > 1)
				cout << "^" << len;
			cout << '*';
			len = 1;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
