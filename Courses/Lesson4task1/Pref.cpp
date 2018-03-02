/*// int * p возьми адрес, находящийся в p
// arr + i - адресс i-того элемента arr
// arr = arr[0]
// 
// */
#include <iostream>
using namespace std;

void InputingArray(int mas[], int size)
{
	cout << "Input your array :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> mas[i];
	}
}
/////////////////////////////////////////////////////
int searchingValueInArray(int mas[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == value)

			return i;
	}
	return -1;
}
/////////////////////////////////////////////////////
int* search2(int mas[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == value)
			return &(mas[i]);
	}
	return NULL;
}
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
	InputingArray(arr, n);
	output(arr, n, "A:");
	cout << endl;

	int number;
	cout << "Input number you want to change: ";
	cin >> number;

	int differentNumber;
	cout << "Input your different number: ";
	cin >> differentNumber;

	int currentFirst = 0;
	int* p = search2(arr, n, number);
	int index = searchingValueInArray(arr, n, number);
	if (p != NULL)
		cout << "Index = " << (p - arr) << endl;

	while ((index = searchingValueInArray(&(arr[currentFirst]), n - currentFirst, number)) != -1)
	{
		arr[currentFirst + index] = differentNumber;
		currentFirst = index;
	}

	p = arr;
	while ((p = search2(p, n, number)) != NULL)
	{
		(*p) = number;
	}
	////                                          NEW
	int *p0 = &(arr[0]);
	int *p1 = &(arr[1]);
	cout << "p1-p0 = " << p1 - p0 << endl;
	cout << "p0 = " << p0 << endl;
	cout << "p1 = " << p1 << endl;
	cout << endl;
	system("pause");
	return 0;
}