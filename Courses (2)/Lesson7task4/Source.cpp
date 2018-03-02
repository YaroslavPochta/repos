#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
using namespace std;
////////////////////////////////////////////////
struct Swords
{
	char word[20];
	int count;
};
///////////////////////////////////////////////////////
int searchingWordInText(Swords *container, int size, char *token)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(container[i].word, token) == 0)
			return i;
	}
	return -1;
}
///////////////////////////////////////////////////////
int main()
{
	int n = 0;
	Swords  words[150];
	char buf[150];

	ifstream fin("Text.txt");
	if (!fin)
	{
		cout << "Error";
		return 0;
	}
	char *token;
	char sep[] = " ,.;:\t\n(){}[]</>?!";
	while (fin.getline(buf, 150))
	{
		token = strtok(buf, sep);
		while (token != NULL)  //обработка слова
		{
			//cout << token << endl;
			int i = searchingWordInText(words, n, token);
			if (i == -1)
			{
				strcpy(words[n].word, token);
				words[n].count = 1;
				++n;
			}
			else ++(words[i].count);
			token = strtok(NULL, sep);
		}
	}

	for (int i = 0; i < n; i++)
		//	cout << words[i].word << " - " << words[i].count << " times" << endl;

		printf("%20s - %3d\n", words[i].word, words[i].count);
	system("pause");
	return 0;
}