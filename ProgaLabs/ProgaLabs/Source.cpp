#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	vector<char> alpha;
	for (char i = 'a'; i <= 'z'; i++)
		alpha.push_back(i);
/*	for (vector<char>::iterator iter = alpha.begin(); iter != alpha.end(); iter++){}*/
	vector<char>::iterator iter;
	for (iter = alpha.begin(); iter != alpha.end() ; iter++)
	{
		cout << *iter << ", ";
	}
	cout << endl;
	vector<char>::reverse_iterator riter;
	for (riter = alpha.rbegin(); riter != alpha.rend(); riter++)
	{
		cout << *riter << ", ";
	}
	cout << endl;
	system("pause");
	return 0;
}