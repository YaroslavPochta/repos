//������ 

#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	const int maxLen = 20;
	char buf[maxLen];
	int nWords = 0;
	char **ptrWords;//������ ����������   ��� �� ������� ����� char *
	ifstream fin("in.txt");//������� �������� ������� ����� � ��������� � ��������� �����
	int size;
	fin >> size;
	ptrWords = new char *[size];

	for (int i = 0; i < size; i++)
	{
		fin >> buf;
		ptrWords[i] = new char[strlen(buf) + 1];
		strcpy(ptrWords[i], buf);
	}

	for (int curSize = size; curSize > 1; curSize--)
	{
		for (int i = 0; i < curSize - 1; i++)
		{
			//if (strcmp(ptrWords[i], ptrWords[i + 1]) > 0) //����������� ����� � ���������� �������

			//{
			//	swap(ptrWords[i], ptrWords[i + 1]);
			//}
			if (strlen(ptrWords[i]) > strlen(ptrWords[i + 1]))//����������� ���� ����
			{
				swap(ptrWords[i], ptrWords[i + 1]);
			}
		}
	}

	for (int i = 0; i < size; i++)
		cout << ptrWords[i] << endl;

	for (int i = 0; i < size; i++)
		delete[] ptrWords[i];

	delete[] ptrWords;

	system("pause");
	return 0;
}