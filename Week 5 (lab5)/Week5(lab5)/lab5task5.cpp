#include <iostream> 
#include "Functions.h"
using namespace std;
int main()
{   
	cout << "Input quantity of elements" << endl;
	int size;
	cin >> size;
	int *arr = new int[size];
	//initRandom(arr, size, 0, 100);
	InputingArray(arr, size);
	//output(arr, size, "Array:");
	int newSize = deletingSimpleNumerals(arr ,size);
	output(arr, newSize, "Array without simple numerals");
	delete[] arr;
	system("pause");
	return 0;
}