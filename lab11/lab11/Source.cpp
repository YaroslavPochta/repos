#include <iostream>
using namespace std;
#include "Fraction.h"

int main()
{
	Fraction frac1(1, 1);
	Fraction frac2(3, -2);
	Fraction frac3(-1, 3);

	Fraction fracs[3];
	int size = 3;
	Fraction sum(0,1);
	cout << "Input fractions " << endl;
	for (int i = 0; i < size; i++)
		cin >> fracs[i];
	for (int i = 0; i < size; i++)
		sum = sum + fracs[i];
	Fraction mult(1, 1);
	for (int i = 0; i < size; i++)
		mult = mult * fracs[i];
	Fraction sub(0, 1);
	for (int i = 1; i < size; i++)
		sub = sub + fracs[0] + -fracs[i];
	
	cout << "sum = " <<sum << endl;
	cout << "mult = " << mult << endl;
	cout << "sub = " << sub << endl;
	system("pause");
	return 0;
}