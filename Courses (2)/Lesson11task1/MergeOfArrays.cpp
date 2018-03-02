#pragma warning (disable : 4996)
#include <iostream>

#include <fstream>

using namespace std;

template <typename type>
void readFromFileToArray(type* arr, int size, char* filename)
{
	ifstream fin(filename);
	for (int i = 0; i < size; i++)
		fin >> arr[i];
}
template <typename type>
void writeToConsole(type* arr, int size, char* title)
{
	cout << title << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "A[" << i << "] = " << arr[i] << '\t';
		if (i % 3 == 2) cout << endl;
	}
	cout << endl << endl;
}
template <typename type>
void mergeArrays(type* arr1, type* arr2, type* resultArray, int size1, int size2)
{
	for (int i = 0, j = 0, k = 0; k < size1 + size2; k++)
	{
		if (i == size1)
		{
			resultArray[k] = arr2[j++];
			continue;
		}
		if (j == size2)
		{
			resultArray[k] = arr1[i++];
			continue;
		}
		resultArray[k] = (arr1[i] <= arr2[j]) ? arr1[i++] : arr2[j++];
	}
}
template <typename type>
void mySwap(type left, type right)
{
	type tmp = left;
	left = right;
	right = tmp;
	
}
void mySwap(char* str1, char* str2)
{
	char buf[100];
	strcpy(buf, str1);
	strcpy(str1, str2);
	strcpy(str2, buf);
}
int main()
{
	int size1;
	int size2;
	cout << "Input size1 and size 2" << endl;
	cin >> size1 >> size2;

	double* arr1 = new double[size1];
	double* arr2 = new double[size2];
	double* resultArray = new double[size1+size2];

	readFromFileToArray(arr1, size1, "1.txt");
	readFromFileToArray(arr2, size2, "2.txt");

	writeToConsole(arr1, size1, "First array:");
	writeToConsole(arr2, size2, "Second array:");

	mergeArrays(arr1, arr2, resultArray, size1, size2);
	writeToConsole(resultArray, size1 + size2, "Result array:");

	delete[] arr1;
	delete[] arr2;
	delete[] resultArray;

	char str1[10] = "Hello!";
	char str2[10] = "The end.";
	mySwap(str1, str2);
	cout << str1 << endl;
	system("pause");
	return 0;
}
