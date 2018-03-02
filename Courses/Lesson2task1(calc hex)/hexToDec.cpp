//Calculator with hex values
//d - 10, x - 16, c - char
#include <iostream>
#include <stdio.h>
using namespace std;
int hexToDec(char *str)
{
	char hex[] = { "0123456789abcdef" };
	int dec = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		char c;
		c = (((str[i] >= 'A') && (str[i] <= 'F')) ? ('a' + (str[i] - 'A')) : (str[i]));
		for (int j = 0; j < 16; j++)
		{
			if (c == hex[j])
				dec = dec * 16 + j;
		}
	}
	return dec;
}
//////////////////////////////////////////////////////
int mainhtd()
{
	/*int a;
	int b;
	scanf_s("%x", &a);
	printf_s("a=%x\n", a);*/

	/*char buf[100];
	sprintf_s(buf, "a10=%d\ta16=%x\n", a, a);
	cout << buf;

	sprintf_s(buf, "a*a=%x\n", a*a);
	cout << buf;*/

	char buf[100] = { "f1" };
	cout << "hex value in dec =  " << hexToDec(buf) << endl;
	system("pause");
	system("cls");
	return 0;
}