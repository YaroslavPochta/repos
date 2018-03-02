#include <list>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
char symbol;

class isFirstSymbol
{
public:
	char symbol_;
	isFirstSymbol(char symbol) : symbol_(symbol) {};
	bool operator() (string str) { return str[0] == symbol;}

};

int main()
{
	list<string> stringList;
	ifstream fin("in.txt");
	string buf;

	int n;
	fin >> n;

	for (int i = 0; i < n; i++)
	{
		fin >> buf;
		stringList.push_back(buf);
	} 
	// 1 task
	stringList.sort();

	list<string>::iterator iter;
	ofstream fout1("out1.txt");
	for (iter = stringList.begin(); iter != stringList.end(); iter++)       
		fout1 << *iter << '\n';

	// 2 task
	ofstream fout2("out2.txt");
	cout << "Plese, input the symbol<  " << endl;
	cin >> symbol;
	for (iter = stringList.begin(); iter != stringList.end(); iter++)
		if ((*iter)[0] == symbol)
			fout2 << *iter << '\n';

	// 3 task
	ofstream fout3("out3.txt");
	
	cout << "Plese, input the symbol " << endl;
	cin >> symbol;
	list<string>::iterator p1 = find_if(stringList.begin(), stringList.end(), isFirstSymbol(symbol));
	list<string>::iterator p2 = find_if_not(p1, stringList.end(), isFirstSymbol(symbol));
	stringList.erase(p1, p2);
	/*for (iter = stringList.begin(); iter != stringList.end(); iter++)
		if ((*iter)[0] == symbol)
			stringList.erase(iter--);
			*/
	for (iter = stringList.begin(); iter != stringList.end(); iter++)
			fout3 << *iter << '\n';
	system("pause");
	return 0;
}