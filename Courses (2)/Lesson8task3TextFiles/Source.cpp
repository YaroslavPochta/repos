#include <fstream>
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////
void writeString(ostream& fout, char *str)
{
	fout << str << endl;
}
////////////////////////////////////////////////////////////////////////
int main()
{
	ifstream fin("Text.txt");
	long long sum = 0;
	int a;

	while (fin >> a)
		sum += a;

	fin.close();

	ofstream fout("Text.txt", ios::app);
	//fout << endl << sum;
	writeString(fout, "Ghbdtn ");
	return 0;
}