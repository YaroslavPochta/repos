#include <iostream>
using namespace std;

int main2()
{
	int n = 0;
	cout << "Input the quantity of elements " << endl;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> arr[i];
	}
	//Сортировка пузырьком
	int t = 0;
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	system("cls");

	cout << "Shorted array: " << endl;
	for (int i = 0; i< n; i++)
		cout << "A[" << i << "] = " << arr[i] << endl;
	system("pause");
	system("cls");

	system("pause");
	cout << "The maximal products of three elements: " << endl;
	int power1 = arr[0] * arr[1] * arr[n-1]; //два минимальных и максимальное
	int power2 = arr[n-3] * arr[n-2] * arr[n-1]; //три максимальных
	cout << power1 << endl << power2 << endl;
	if (power1 >= power2) cout << "The maximal product of three elements is " << power1 << endl;
	else cout << "The maximal product of three elements is " << power2 << endl;
	delete[] arr;
	system("pause");
	return 0;
}