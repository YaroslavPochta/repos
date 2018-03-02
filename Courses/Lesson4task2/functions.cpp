#include <iostream>
#include <stdio.h>
#include <time.h>
//homework
//1.явл€етс€ ли массив отсортированным по возрастанию bool isItSort(int arr[], int size)
//2.ќпределить длинну максимальной подпоследовательности одинаковых подр€д идущих эементов int maxLenght(int[], int)
//3.»зучить файловых воод-вывод из .txt и аддаптировать домашний функции под считывание значений из них
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
int* searchPtr(int mas[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == value)
			return &(mas[i]);
	}
	return NULL;
}
 //resultMas = mas + mas2
int AUB(int arr[], int size1, int arr2[], int size2, int resultArr[])
{
	int i = 0, j = 0, k = 0;
	for (i = 0, k = 0; i < size1; i++, k++)
		resultArr[k] = arr[i];
	for (j = 0; j < size2; j++)
		if (searchPtr(arr, size1, arr2[j]) == NULL)
			resultArr[k++] = arr2[j];
	return k;
}
int intersection(int arr[], int size1, int arr2[], int size2, int intersectionArr[])
{
	int i = 0, k = 0;
	for (i = 0; i < size1; i++)
		if (searchPtr(arr2, size2, arr[i]) != NULL)
			intersectionArr[k++] = arr[i];
	return k;
}
int removeValue(int arr[], int size, int value)
{
	int iRead = 0, iWrite = 0;
	for (iRead = 0; iRead < size; iRead++)
		if (arr[iRead] != value)
			arr[iWrite++] = arr[iRead];
	return iWrite;
}


