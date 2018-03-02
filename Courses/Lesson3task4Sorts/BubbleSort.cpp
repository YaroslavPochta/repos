#include <iostream>
using namespace std;
void initRandom(int mas[], int size, int a, int b)
{
	for (int i = 0; i < size; i++)
		mas[i] = a + rand() % (b - a);
}
/////////////////////////////////////////////////////
void bubbleSort(int mas[], int size)
{
	for (int currentSize = size; currentSize > 1; currentSize--)
	{
		for (int i = 0; i < currentSize - 1; i++)
		{
			if (mas[i] > mas[i + 1])
			{
				swap(mas[i], mas[i + 1]);
			}
		}
	}
} //////////////////////////////////////////////////////
void output(int mas[], int size, char title[])
{
	cout << title;
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0) { cout << endl; }
		cout << mas[i] << '\t';
	}
}
/////////////////////////////////////////////////////////
int main()
{
	int n;
	cout << "Enter number of the elements in your array ";
	cin >> n;
	int *arr = new int[n];
	initRandom(arr, n, 0, 100);
	output(arr, n, "A:");
	cout << endl;
	bubbleSort(arr, n);
	output(arr, n, " ");

	system("pause");
	return 0;
}
