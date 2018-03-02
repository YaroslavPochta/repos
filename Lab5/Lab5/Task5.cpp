#include <iostream>
#include "Functions.h"
using namespace std;
int main5()
{
	cout << "Input quantity of elements in the first and the second arrays " << endl;
	int size;
	cin >> size;
	int *arr = new int[size];
	//initRandom(arr, size, 0, 100);
	InputingArray(arr, size);
	//output(arr, size, "Array:");
	int newSize = deletingSimpleNumerals(arr, size);
	output(arr, newSize, "Array without simple numerals");
	delete[] arr;
	system("pause");
	return 0;
}