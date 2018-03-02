#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
using namespace std;
void initRandom(int mas[], int size, int a, int b)
{
	srand(time(000));
	for (int i = 0; i < size; i++)
		mas[i] = a + rand() % (b - a);
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
void output(int mas[], int size, char title[])
{
	cout << title;
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0) { cout << endl; }
		cout << mas[i] << '\t';
	}
	cout << endl << endl;
}
void getingArrayFromFile(int mas[], int size, char filename[])
{
	ifstream fin(filename);
	for (int i = 0; i < size; i++)
		fin >> mas[i];
}
void outputArrayInFile(int mas[],int size, char filename[])
{
	ofstream fout;
	fout.open("ArrayIsHere.txt"); 
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0) { cout << endl; }
		fout << mas[i] << '\t';
	}
}
int maxInTheIntArray(int mas[], int size)
{
	int max = mas[0];
	for (int i = 0; i < size; i++)
	{
		if (mas[i] > max) max = mas[i];
	}

	return max;
}
bool isItSorted(int mas[], int size)
{
	for (int i = 1; i < size; i++)
		if (mas[i - 1] > mas[i])
			return false;
	return true;
}
int maxLenghtSubsetOfSimilarValues(int mas[], int size)
{
	int j = 0;
	int *lenghtOfSubset = new int[size];
	int counter = 1;
	for (int i = 0; i < size; i++)
		if (mas[i] == mas[i + 1])
			counter++;
		else 
		{
			lenghtOfSubset[j] = counter;
			j++;
			counter = 1; 
		}
	return maxInTheIntArray(lenghtOfSubset, j);
}
int maxLenght(int mas[], int size)
{
	int maxLen = 0;
	int curLen = 0;
	if ((i == size - 1) || (mas[i] != mas[i + 1]))
	{
		if (maxLen < curLen)
			maxLen = curLen;

		curLen = 1;
	}
	else curLen++;
	return maxLen;
}