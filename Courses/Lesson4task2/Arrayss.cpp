#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
	int * mas, *mas2, *resultMas, *intersectionArr;
	int size1 = 15;
	int size2 = 15;
	int size3 = size1 + size2;
	
	mas = new int[size1];
	initRandom(mas, size1, 0, 45);
	output(mas, size1, "A:");
	mas2 = new int[size2];
	initRandom(mas2, size2, 0, 20);
	output(mas2, size2, "B:");
	resultMas = new int[size3];
	size3 = AUB(mas, size1, mas2, size2, resultMas);
	output(resultMas, size3, "Union:");
	cout << endl;
	
	intersectionArr = new int[size1+size2];
	size3 = intersection(mas, size1, mas2, size2, intersectionArr);
	output(intersectionArr, size3, "iNTERSECTION:");
	cout << endl;
	
	int number;
	cout << "Input value you want to remove: ";
	cin >> number; 

	size1 = removeValue(mas, size1, number);
	output(mas, size1, "A:");
	system("pause");
}