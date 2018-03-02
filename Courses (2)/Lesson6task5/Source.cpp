#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int matr[100][100];
	int n, m;
	ifstream fin("in.txt");
	if (!fin)
	{
		cout << "File problem!\n";
		return 0;
	}
	fin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)//бывает
			fin >> matr[i][j];

	cout << "matr=\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout<<matr[i][j]<<'\t';
		cout << endl;
	}

	system("pause");
	return 0;
}