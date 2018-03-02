// 1)строка=слова,разделённыая space-символами ;вывести список слов в алфавитном порядке
// принять слова в массив,отсортировать его,вывести эл.массива в отсортированном виде

#pragma warning (disable : 4996)
#include <iostream>

using namespace std;
int main()
{
	
	const int maxN = 100;
	const int maxLen = 20;
	char words[maxN][maxLen];
	char buf[maxLen];
	int nWords = 0;

	while (cin >> buf)
	{
		strcpy(words[nWords], buf);
		nWords++;
	}

	for (int curSize = nWords; curSize > 1; curSize--)
		for (int i = 0; i < curSize - 1; i++)
			if (strcmp(words[i], words[i + 1]) > 0)
			{
				strcpy(buf, words[i]);
				strcpy(words[i], words[i + 1]);
				strcpy(words[i + 1], buf);
			}

	for (int i = 0; i < nWords; i++)
		cout << words[i] << endl;

	system("pause");//нужно напечать ctrl+z  чтобы закончить вводить
	return 0;
}