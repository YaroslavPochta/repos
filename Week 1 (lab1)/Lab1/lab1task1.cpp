#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
void main1()
{
	double squareOfCircle, squareOfSquare;
	float diameter, diagonal;

	cout << "Enter square of the square ";
	cin >> squareOfSquare;
	while (squareOfSquare < 0)
	{
		cout << "Error! Enter square of the square ";
		cin >> squareOfSquare;
	}

	cout << "Enter square of the circle ";
	cin >> squareOfCircle;
	while (squareOfCircle < 0)
	{
		cout << "Error! Enter square of the square ";
		cin >> squareOfCircle;
	}

	diagonal = sqrt(squareOfSquare * 2);
	diameter = sqrt(squareOfCircle * 4 / M_PI);
	if (diameter >= diagonal)
	{
		cout << "We can place the square into the circle" << endl;
	}
	else
	{
		cout << "We can place the circle into the circle" << endl;
	}
	system("pause");
}