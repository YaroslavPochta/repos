#include<iostream>
#include "Functions.h"
#define USE_MATH_DEFINES
using namespace std;
int main2()
{
	cout << "Input number of elements " << endl;
	int size;
	cin >> size;
	int *arr = new int[size];

	initRandom(arr, size, 0, 100);
	output(arr, size, "Array:");
	cout << endl << endl;
	//selectionSort(arr, size);
	output(arr, size, "Array:");
	cout << endl << endl;
	system("pause");
	delete[] arr;
	return 0;
}