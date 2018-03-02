#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int a1;
	int a2;
	ifstream in1("1.txt");
	ifstream in2("2.txt");
	ofstream out("out.txt");
	in1 >> a1;
	in2 >> a2;
	while ((!in1.eof()) && (!in2.eof()))
	{
		if (a1 <= a2)
		{
			out << a1 << endl;
			in1 >> a1;
		}
		else
		{
			out << a2 << endl;
			in1 >> a2;
		}
	}
	while (!in1.eof())
	{
		out << a1 << endl;
		in2 >> a1;
	}
	while (!in2.eof())
	{
		out << a2 << endl;
		in2 >> a2;
	}



	system("pause");
	return 0;
}