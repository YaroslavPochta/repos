#pragma warning(disable : 4996)
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	char str[100];
	char buf[100];
	cin.getline(str, 100);
	strcpy(buf, str);
	int maxLenght = 0;
	char sep[] = " \t";
	char *maxToken;
	char *token;
	maxToken = token  = strtok(buf, " \t");
	int len = 0;
	while (token != NULL)
	{
		cout << token << endl;
		int maxLen = strlen(maxToken);
		len = strlen(token);
		if (len > maxLenght)
			maxLenght = len;
		token = strtok(NULL, sep);
	}
	cout << maxToken << endl;
	system("pause");
	return 0;
}
