#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set st1;
	Set st2;
	cout << "Input first set" << endl;
	cin >> st1;
	cout << "Input second set" << endl;
	cin >> st2;
	
	
	cout << "st1 + st2 =" << st1 + st2 << endl;
	cout << "st1 * st2 =" << st1 * st2 << endl;
	cout << "st1 - st2 =" << st1 - st2 << endl;
	cout << "st1 < st2 =";
	(st1 < st2) ? cout << "True" <<endl : cout << "False" << endl;

	if (!(st1 == st2)) cout << "Set's aren't similar " << endl;
	
	system("pause");
	return 0;
}