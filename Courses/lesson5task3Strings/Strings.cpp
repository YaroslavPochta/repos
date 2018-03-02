#pragma warning(disable : 4996)
#include <string.h>
#include <iostream>
using namespace std;
/////////////////////////////////////////////
bool isDigit(char c)
{
	return ((c >= '0') && (c <= '9'));
}
////////////////////////////////////////////
int main()
{
	/*¬арианты ввида строк
	char str[100] = "Hello";
	char str[] = "Heloo ghjdv";
	char str[] = {'f','t','y','d','\0'};
	cin >> str; ввод до пробела
	cin.getline(str, 100[размер]);
	‘ункции со строками
	strlen(char*)
	strcpy() - копирование
	strcmp() - сравнение
	strcat()
	strchr()
	atoi(), atof()
	strtok()
	strpbrk()*/
	 
	//¬вести строку и определить, сколько в ней символов

	char str[100];
	cin.getline(str, 100);
/*	int counter = 0;
	for (int i = 0; str[i] != '\0'; i++)
		if (isDigit(str[i]))            //isdigit(str[i])
			counter++;
	cout << endl << counter << endl;*/
	
	int counters[256];

	for (int i = 0; i < 256; i++) //int counters[256] = {0,};
		counters[i] = 0;

	for (int i = 0; str[i] != '\0'; i++)
		++(counters[str[i]]);

	for (int i = 0; i < 256; i++)
		if (counters[i] != 0) cout << (char)i << " : " << counters[i] << endl;

	system("pause");
	return 0;
}
//idi nahyi )))))))))
//lil peep dead :(