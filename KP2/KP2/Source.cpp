#include <iostream>
using namespace std;
int foo1(int x, int y = 2, int z);
int foo2(x = 0, int y);
int foo3(int x, int, int y = 5);
int foo4(int x; int);
int foo5(int x, y = x);
int foo6(5, 8);
int main() {
		int arr[]{ 1, 2, 3, 4, 5 };
		for_each(arr, arr + 5, [](int x) {cout << x; });
	system("pause");
	return 0;
}