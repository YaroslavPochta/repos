#include<iostream> 
#include <time.h>
#define USE_MATH_DEFINES
using namespace std;
int indexOfMinElementInArray(int *arr, int first, int last)
{
	int indexOfMin = first;
	for (int i = first; i < last; i++)
	{
		if (arr[i] < arr[indexOfMin])
			indexOfMin = i;
	}
	return indexOfMin;
}
void initRandom(int mas[], int size, int a, int b)
{
	srand((unsigned)time(0));
	for (int i = 0; i < size; i++)
		mas[i] = a + rand() % (b - a);
}
void output(int *mas, int size, char title[])
{
	cout << title;
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0) { cout << endl; }
		cout << mas[i] << '\t';
	}
	cout << endl << endl;
}
int minInTheArray(int mas[], int first, int last)
{
	int size = last - first;
	int min = mas[first];
	for (int j = first; j < last; j++)
	{
		if (mas[j] < min)
		{
			min = mas[j];
		}
	}
	return min;
}
void InputingArray(int mas[], int size)
{
	cout << "Input your array :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> mas[i];
	}
}
int searchingValueInArray(int mas[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == value)

			return i;
	}
	return -1;
}
int* selectionSort(int*arr, int size, int& newArraySize)
{
	int indexOfMin = 0;
	for (int i = 0; i < size; i++)
	{
		indexOfMin = indexOfMinElementInArray(arr, i, size);
		swap(arr[i], arr[indexOfMin]);
	}
	newArraySize = size;
	return arr;
}
bool isItSimple(int n)
{
	if (n > 2)
	{
		int k = sqrt(n);
		for (int i = 2; i <= k; i++)
			if (n % i == 0)
				return false;

	}
	else if (n == 2) return true;
	else return false;
	return true;
}
int deletingSimpleNumerals(int *mas, int size)
{
	for (int i = 0; i < size; i++)
		if (isItSimple(mas[i]))
		{
			for (int j = i; j < size; j++)
				mas[j] = mas[j + 1];
			i--;
			size--;
		}
	return size; //new size
}
int* simpleNumeralsArray(int *mas, int size, int& newArraySize)
{
	newArraySize = 0;
	for (int i = 0; i < size; ++i)
		if (isItSimple(mas[i]))
		{
			newArraySize = newArraySize + 1;
		}

	int* arrayOfSimpleNumerals = new int[newArraySize];
	int j = 0;
	for (int i = 0; i < size; i++)
		if (isItSimple(mas[i]))
		{
			arrayOfSimpleNumerals[j] = mas[i];
			j++;
		}

	return arrayOfSimpleNumerals;
}
void selectionSortV(int*arr, int size)
{

	int indexOfMin = 0;
	int counter = 0;
	for (int i = 0; i < size; i++, counter++)
	{
		indexOfMin = indexOfMinElementInArray(arr, i, size);
		swap(arr[i], arr[indexOfMin]);
		if (counter == (size / 2))
			break;
	}
}
int*  medianOfArray(int *arr, int size, int& newArraySize)
{
	int *median = new int;
	int *bufArray = new int[size];
	for (int i = 0; i < size; i++)
		bufArray[i] = arr[i];

	selectionSortV(bufArray, size);
	*median = bufArray[(size-1)/ 2];
	newArraySize = 1;
	return median;
}