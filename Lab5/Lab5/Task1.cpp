#include <iostream>
using namespace std;

int main1()
{
	int n = 0;
	cout << "Enter number of columns and rows ";
	cin >> n;

	int **magicSquare = new int*[n];
	for (int i = 0; i < n; i++)
		magicSquare[i] = new int[n];

	for (int j = 0; j < n; j++)
	{
		cout << "Enter the column number " << j << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "A[" << i << "] = ";
			cin >> magicSquare[j][i];
		}
	}
	bool isItMagic = true;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += magicSquare[i][0];

	int sumCheck;

	for (int i = 0; (isItMagic == true) && (i < n); i++)
	{
		sumCheck = 0;
		for (int j = 0; j < n; j++)
			sumCheck += magicSquare[i][j]; // sum in the row

		if (sum != sumCheck)
			isItMagic = false;
	}

	for (int i = 0; (isItMagic == true) && (i < n); i++)
	{
		sumCheck = 0;
		for (int j = 0; j < n; j++)
			sumCheck += magicSquare[j][i]; // sum in the columN

		if (sum != sumCheck)
			isItMagic = false;
	}

	if (isItMagic == true)
		cout << "\nIt is a magic square!" << endl;
	else
		cout << "\nIt is not a magic square :(" << endl;
	system("pause");

	for (int i = 0; i < n; i++)
		delete[] magicSquare[i];
	delete[] magicSquare;
	return 0;
}