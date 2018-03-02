#include <iostream>
#include "func.h"
using namespace std;

int main1()
{
	cout << "Input quantity of the elements in your array ";
	int size;
	cin >> size;
	int *arr = new int[size];
	InputingArray(arr, size);
	int* (*funPointer)(int* arr, int size, int & newSize) ;
	cout << "What do you want to do?" << endl;
	cout << "1. Find all simple numbers in ur array." << endl;
	cout << "2. Sort array." << endl;
	cout << "3. Find median in array." << endl;
	cout << "Please, chooce (1/2/3): ";
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
		case 1: 
		{
			//output(simpleNumeralsArray(arr, size), size, "Simple numerals in the array: " );
			funPointer = simpleNumeralsArray;
			break; 
		}
		case 2: 
		{
			funPointer = selectionSort;
			break;
		}
		case 3: 
		{
			funPointer = medianOfArray;
			break;
		}
		default: { funPointer = NULL; cout << "Incorrect operation"; }
	}

	int newArraySize = 0;
	int *resultArray = funPointer(arr, size, newArraySize);
	output(resultArray, newArraySize, "Result:\n");
	system("pause");
	return 0;
}