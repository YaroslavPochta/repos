#include <iostream>
#include "Functions.h"
using namespace std;
int main3()
{
	cout << "Input number of elements " << endl;
	int size;
	cin >> size;
	int *arr = new int[size];
	initRandom(arr, size, 0, 100);
	output(arr, size, "Array:");
	//insertionSortUsingBinarySearch(arr, size);
	output(arr, size, "Sorted array:");

	delete[] arr;
	system("pause");
	return 0;
}
