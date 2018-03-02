#include "FlowerBed.h"
#include <algorithm>
#include <fstream>

int main()
{
	ifstream fin("FlowerBedsInfo.txt");
	vector<FlowerBed> vecBeds;
	FlowerBed flbed;
	vector<string> flowers;
	int n;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> flbed.number >> flbed.form;
		flowers.push_back(fin);

	}
	fin.close();
	system("pause");
	return 0;
}