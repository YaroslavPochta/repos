#include <iostream>
#include <stdio.h>
using namespace std;
void DecToHex(int dec, char str[])
{
	char hex[] = { "0123456789abcdef" };
	int istr = 0;
	while (dec != 0)
	{
		int reminder = dec % 16;
		str[istr] = hex[reminder];
		istr++;
		dec /= 16;
	}
	str[istr] = '\0'; // istr по факту является длинной строки
	for (int i = 0; i < istr / 2; i++)
		swap(str[i], str[istr - 1 - i]);
}
/////////////////////////////////////////////
int main()
{
	int dec;
	char buf[100];

	cout << "Input your value " << endl;
	cin >> dec;
	DecToHex(dec, buf);
	cout << buf << endl;

	system("pause");
	system("cls");
	return 0;
}