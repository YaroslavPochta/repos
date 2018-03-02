#include <iostream>
using namespace std;

/*void mySwap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}*/
void mySwap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a;
	int b;
	cout << "Input ur values " << endl;
	cin >> a >> b;
	mySwap(a, b);
	cout << "Changed values: " << a << '\t' << b << endl;
	system("pause");
	return 0;
}