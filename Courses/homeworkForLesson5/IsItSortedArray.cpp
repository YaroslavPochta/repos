#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main()
{
	int choice = 0;
	cout << "What task would you like to run?(1/2) " << endl;
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			int size;
			cout << "Enter number of the elements in your array ";
			cin >> size;
			int *arr = new int[size];
			InputingArray(arr, size);
			cout << endl;
			if (isItSorted(arr, size)) cout << "Yes, this array is sorted." << endl;
			else cout << "No, this array isn't sorted." << endl; 
			break;
		}
		case 2: 
		{
			/*string filename;
			cout << "Enter filename in a full form " << endl;
			getline(cin, filename);*/
			int size;
			cout << "How much elements do you want to read from file " << "ArrayIsHere.txt" << "?" << endl;
			cin >> size;
			int *arr = new int[size];
			getingArrayFromFile(arr, size, "ArrayIsHere.txt");
			cout << "Max lenght of similar elements in this file is " << maxLenght(arr, size) << endl;
		}
	}
	system("pause");
	return 0;
}