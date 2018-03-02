#pragma warning (disable : 4996)
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	const int maxN = 100;
	const int maxLen = 20;

	char buf[maxLen];

	// char * ptrWord[maxN] ;
	char **ptrWords;
	ifstream fin("in.txt");
	int size;
	fin >> size;
	ptrWords = new char *[size];

	for (int i = 0; i < size; i++)
	{
		fin >> buf;
		ptrWords[i] = new char[strlen(buf) + 1];
		strcpy(ptrWords[i], buf);
	}

	for (int i = 0; i < size; i++)
		cout << ptrWords[i] << endl;

	for (int curSize = size; curSize > 1; --curSize)
		for (int i = 0; i < curSize - 1; ++i)
			/*	if (strcmp(ptrWords[i], ptrWords[i + 1]) > 0)
					swap(ptrWords[i], ptrWords[i + 1]);*/         //    Это для алфавитного порядка( обратное > меняем на <)
			if (strlen(ptrWords[i]) > strlen(ptrWords[i + 1])); // возрастание длины
	for (int i = 0; i < size; i++)
		delete[] ptrWords[i];
	delete[] ptrWords;
	system("pause");
	return 0;
}



