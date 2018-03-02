#include <iostream>
#include <fstream>
using namespace std;
#include "Fraction.h"

int main()
{
	Fraction frac1(1, 1);
	Fraction frac2(3, -2);
	Fraction frac3(-1, 3);

	Fraction fracs[100];
	ifstream in("data.txt");
	int size;
	in >> size;
	for ( int i = 0; i < size; i++) 
		in >> fracs[i];
	for (int i = 0; i < size; i++)
		cout << fracs[i] << endl;
	Fraction max = fracs[0];
	for (int i = 0; i < size; i++)
		if (max <= fracs[i])
			max = fracs[i];
	cout << "max = " << max << endl;
	system("pause");
	return 0;
}