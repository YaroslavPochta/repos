#include <iostream>
using namespace std;

int main1()
{
	int n = 0;
	cout << "Input the quantity of elements ";
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> arr[i];
	}

	int counter;
	for (int i = 0; i < n; i++)
	{
		counter = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i] == arr[j])
				counter++;
		}
		if (counter % 2 == 1) { cout << "Numerral that occurs odd times is" << arr[i]; break; }
	
	}
	system("pause");
	return 0;
}
