
#include <iostream>
using namespace std;
int main3()
{
	int n1, n2;
	cout << "Enter the quantity of elements of the ur arrays ";
	cin >> n1 >> n2;

	int *arr1 = new int[n1];
	int *arr2 = new int[n2]; 

	cout << "Enter elements of the first array :" << endl;
	for (int i = 0; i < n1; i++) { cout << "Arr1[" << i << "] = "; cin >> arr1[i]; }
//	system("cls");

	cout << "Enter elements of the second array :" << endl;
	for (int i = 0; i < n2; i++) { cout << "Arr2[" << i << "] = "; cin >> arr2[i]; }
	//system("cls");

	int min, max;
	if (n1 > n2) { min = n2; max = n1; }
	else { min = n1; max = n2; }

	int *arr = new int[max];
	for (int i = 0; i < max; i++) arr[i] = 0;


	for (int i = 0; i < min; i++) arr[i] = arr1[i] + arr2[i];

	if (n1 > n2) { for (int i = min ; i < max; i++) arr[i] = arr1[i]; }
	else { for (int i = min; i < max; i++) arr[i] = arr2[i]; }

	for (int i = 0; i < max; i++) cout << "Sum[" << i << "] = " << arr[i] << endl;
	system("pause");
	//system("cls");//Complete

	int n3 = n1 + n2 - 1;
	int *mult = new int[n3];

	for (int i = 0; i < n3; i++) mult[i] = 0;
	
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++) 
			mult[i + j] += arr1[i] * arr2[j];

	for (int i = 0; i < n3; i++) cout << "Mult[" << i << "] = " << mult[i] << endl;
	delete[] arr1;
	delete[] arr2;
	delete[] arr;
	delete[] mult;
	system("pause");
	return 0;
}
//Тесты:
//           Введённые данные                                                    Произведение
//Массив из 7 элементов (все 7) и 5 элементов (все 5)             35 + 70 + 135 + 140 + 175 + 175 + 175 + 140 + 135 + 70 + 35
// Из 10 элементов (все 1)                                        1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1
// 4 5 6 и 1 2 3                                                  4 + 13 + 28 + 27 + 18
//
