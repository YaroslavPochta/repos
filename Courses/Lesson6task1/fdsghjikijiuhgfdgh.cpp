//	Способы вводы с консоли
// cin >>
// cin.getline
// strtoken
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
//////////////////////////////////
void wordsBubbleSort(char *words[], int nWords)
{
	char buf;
	for (int curSize = nWords; curSize > 1; --curSize)
		for (int i = 0; i < curSize; ++i)
		{
			if (strcmp(words[i], words[i + 1]) > 0)
			{
			//	strcpy(buf[], words[i]);
				strcpy(words[i], words[i + 1]);
			//	strcpy(words[i + 1], buf);
			}

		}
}

//////////////////////////
int main1()
{
	const int maxN = 100; //Максимальное количество слов (строки массива)
	const int maxLen = 20; //Максимальная длинна слова

	char words[maxN][maxLen];
	char buf[maxLen];

	int nWords = 0;


	while (cin >> buf)
	{
		strcpy(words[nWords], buf);
		nWords++;
	}

	for (int i = 0; i < nWords; i++)
		cout << words[i];


	system("pause");
	return 0;
}