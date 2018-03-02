#include <iostream>
using namespace std;

int indexOfMinElementInArray(int *arr, int first, int last)
{
	int indexOfMin = first;
	for (int i = first; i < last; i++)
	{
		if (arr[i] < arr[indexOfMin])
			indexOfMin = i;
	}
	return indexOfMin;
}
int NOD(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	return a + b;
}
void selectionSortV(int*arr, int size)
{

	int indexOfMin = 0;
	for (int i = 0; i < size; i++)
	{
		indexOfMin = indexOfMinElementInArray(arr, i, size);
		swap(arr[i], arr[indexOfMin]);
	}
}

int main()
{
	cout << "Ener number of elements in ur array ";
	int n = 0;
	cin >> n;
	if (n < 2)
	{ 
		cout << "Uncorrect result" << endl; 
		system("pause");
		return 0;
	}
	int *arr = new int[n];
	cout << "Input elements of ur array" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	selectionSortV(arr, n);
	
	int d = arr[1] - arr[0];
	if (d == 0) cout << "Error" << endl;
	for (int i = 2; i < n; i++)
		d = NOD(d, arr[i] - arr[i - 1]);
	cout << "The original progression:" << endl;

	int a = arr[0];
	while (a <= arr[n - 1])
	{
		cout << a << "  ";
		a += d;
	}
	cout << endl;
	delete[] arr;
	system("pause");
	return 0;
}
//Тесты
//      Введённые  данные                                                        Прогрессия на выходе
//         3 23 39 47                                                      3 7 11 15 19 23 27 31 35 39 4 47
//     1 17 17 33 41 65 81                                                   1 9 17 25 33 41 49 57 65 73 81