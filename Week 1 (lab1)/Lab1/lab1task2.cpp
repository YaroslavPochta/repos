#include <iostream>
using namespace std;
int main2()
{
	double a, b, c, x1, x2, D, x;
	cout << "Enter the a ";
	cin >> a;
	cout << "Enter the b ";
	cin >> b;
	cout << "Enter the c ";
	cin >> c;
	if (a != 0 )
	{
		D = b*b - 4 * a*c;
		if (D > 0)
		{
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			cout << "x1="; cout << x1;
			cout << "     x2="; cout << x2 << endl;
		}
		else 
		{
			if (D == 0)
			{
				x = (-b) / (2 * a);
				cout << "x=";
				cout << x << endl;
			}
			else cout << "There is no any solution" << endl;
		}
	}
	else
	{
		if (b != 0) {
			x = -c / b;
			cout << "x=";
			cout << x;
		}
		else
		{
			if (c == 0)  cout << "X can be any number";
			else  cout << "There is no any solution" << endl;
		}
	}
	system("pause");
	return 0;
}
