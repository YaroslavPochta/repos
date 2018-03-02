#include <iostream>
using namespace std;
void initRandom(int mas[], int size, int a, int b)
{
	for (int i = 0; i < size; i++)
		mas[i] = a + rand() % (b - a);
}
/////////////////////////////////////////////////////
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
void ReverseArray(int mas[], int size)
{
	for (int i = 0; i < size / 2; i++)
		swap(mas[i], mas[size - 1 - i]);
}
///////////////////////////////////////////////////////////
int deleteFirstElement(int mas[], int size)
{
	for (int i = 0; i < size - 1; i++)
		mas[i] = mas[i + 1];
	return size - 1;
}
///////////////////////////////////////////////////////////
int main()
{
	int arr[100];
	int n;
	cout << "Enter number of the elements in your array ";
	cin >> n;
	initRandom(arr, n, 0, 100);
	output(arr, n, "A:");
	cout << endl;

	ReverseArray(arr, n);

	output(arr, n, "A:");
	cout << endl;

	while (n != 1)
	{
		n = deleteFirstElement(arr, n);
		output(arr, n, "");
		cout << endl;
	}

	system("pause");
	return 0;
}
