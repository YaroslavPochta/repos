#include <iostream>
using namespace std;
void initRandom(int mas[], int size, int a, int b)
{
	for (int i = 0; i < size; i++)
		mas[i] = a + rand() % (b - a);
}
////////////////////////////////////////////////////////
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
	//initRandom(arr, n, 0, 100);
	output(arr, n, "A:");
	cout << endl;

	int number;
	cout << "Input number you want to change: ";
	cin >> number;

	/*int differentNumber;
	cout << "Input your different number: ";
	cin >> differentNumber;*/

	/*int currentFirst = 0;
	int index = searchingValueInArray(arr, n, number*/
	int *p = search2(arr, n, number);
	if (p != NULL)
		cout << "Index = " << (p - arr) << endl;
	/////////////////////sECOND VARIATION//////////////
	/*while ((index = searchingValueInArray(&(arr[currentFirst]), n - currentFirst, number)) != -1)
	{
		arr[currentFirst + index] = differentNumber;
		currentFirst = index;
	}*/

	/*while (index != -1)
	{
		arr[currentFirst] = differentNumber;
		currentFirst = index;
		index = searchingValueInArray(&(arr[currentFirst]), n - index, number);   //&(a[index]) = a + index
	}*/
	output(arr, n, "A:");
	cout << endl;
	system("pause");
	return 0;
}