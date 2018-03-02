#include <iostream> 
#include "Functions.h"
using namespace std;
int main4()
{
	cout << "Input quantity of elements in the first and the second arrays " << endl;
	int size1;
	int size2;
	cin >> size1 >> size2;
	int *arr1 = new int[size1];
	int *arr2 = new int[size2];
	InputingArray(arr1, size1);
	InputingArray(arr2, size2);

	int isSubstrng = isSubstring(arr1, arr2, size1, size2);
	if (isSubstrng == -1) cout << "It is not a substring";
	else cout << isSubstrng << endl;
	/*
	if (isSubset(arr1, arr2, size1, size2) == true)
	{
	cout << "The second array is a subset of the first" << endl;
	if (isSubstrng == -1)
	{
	cout << "The second array isn't a substring of the first" << endl;
	}
	else
	{
	cout << "The second array is a substring of the first array" << endl;
	cout << "Position of the first element of the subset in the first array is  " << isSubstrng << endl;
	}
	}
	else
	{
	cout << "The second array isn't a subset of the first array" << endl;
	cout << "The second array isn't a substring of the first" << endl;
	}
	*/

	delete[] arr1, arr2;
	system("pause");
	return 0;
}