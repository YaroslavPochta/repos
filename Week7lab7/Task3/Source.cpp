#include <iostream>
#include <string>
#include "Func.h"
using namespace std;

int main() 
{
	string str;
	cout << "Input your string: ";
	getline(cin, str);
	cout << str << " = " << reversePolishNotation(str) << endl;
	system("pause");
	return 0;
}