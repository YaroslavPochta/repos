#include <iostream>
using namespace std;

int sumInRow(int **magicSquare, int size, int column)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += magicSquare[column][i];
	return sum;
}
int sumInColumn(int **magicSquare, int size, int row)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += magicSquare[i][row];
	return sum;
}


int main1()
{
	int n ;
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

	for (int i = 1; (isItMagic == true) && ( i < n); i++)
			if (sum != sumInRow(magicSquare, n, i))
				isItMagic = false;

	for (int i = 0; (isItMagic == true) && (i < n); i++)
		if (sum != sumInColumn(magicSquare, n, i))
			isItMagic = false;
	

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