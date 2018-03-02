#include <iostream>
using namespace std;
#include "Vector.h"
#define USING_MATH_DEFINES

int main()
{
	Vector v1(3, 5);
	Vector v2(7,2);
	Vector v3(1);
	cout << "v1 = " << v1 << endl;
	cout << "v2 = " << v2 << endl;
	cout << "v3 = " << v3 << endl;
	Vector v4(v1);
	Vector v5;
	cout << "v1 + v2 = "<< v1 + v1 << endl;
	cout << "v1 * v2 = " << v1 * v2 << endl;
	v3 = v1 + v1;
	cout << "v3 = " << v3 << endl;
	v5 = v5;
	cout << "v5 = " << v5 << endl;
	v1[0] = 2345;
	v1.pushBack(123456);
	v1.pushBack(456);
	v1.pushBack(1236);
	v1.pushBack(60936456);
	cout << "v1 = " << v1 << endl;
	system("pause");
	return 0;
}