#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
void main()
{
	int max = - INT_MAX;
	cout << "Input 4 numbers: ";
	for (int i = 0; i < 4; ++i)
	{
		int number;
		cin >> number;
		if ((number % 2 == 0) && (number > max)) { max = number; }
	}

	if (max != -INT_MAX) { cout << "The largest even number is " << max << endl; }
	else { cout << "The largest even number not found" << endl; }
	system("pause");
}