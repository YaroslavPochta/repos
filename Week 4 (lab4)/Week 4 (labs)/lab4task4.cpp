#include <iostream>
using namespace std;

void bubbleSort(int* arr, int leftPosition, int rightPosition, int flag)
{
	// flag == 1 => from min to max, flag == 0 => from max to min
	int temp;
	for (int i = leftPosition; i < rightPosition; i++)
	{
		for (int j = rightPosition; j > leftPosition; j--)
		{
			if (flag == 1)
			{
				if (arr[i] >= arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			else
			{
				if (arr[i] <= arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}
int Min(int *arr, int n)
{
	int min = arr[0];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			k = i;
		}

	}
	return k;
}

int main4()
{
	cout << "Ener number of elements in ur array ";
	int n = 0;
	cin >> n;

	int *arr = new int[n];
	cout << "Input elements of ur array" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}

	int k = Min(arr, n);
	cout << "Index of minimal element in array: " << k << endl;
	system("pause");

	bubbleSort(arr, 0, k, 0);
	bubbleSort(arr, k, n - 1, 1);
	cout << "Sorted array: " << endl;
	for (int i = 0; i< n; i++)
		cout << "A[" << i << "] = " << arr[i] << endl;
	delete[] arr;
	system("pause");
	return 0;
}
