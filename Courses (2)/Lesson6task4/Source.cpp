#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
using namespace std;
void deleteChar(char *str, char c)
{
	int iWrite = 0;
	for (int iRead = 0; str[iRead] != '\0'; iRead++)
	{
		if (str[iRead] != c)
		{
			str[iWrite++] = str[iRead];
		}
		str[iWrite] = '\0';
	}
}
int main()
{
	char buf[100];
	cin.getline(buf, 100);
	deleteChar(buf, 'a');
	cout << "buf=" << buf << endl;
	strcpy(buf, "Hello");
	char * ptr = strchr(buf, 'e');
	*ptr = '\0';
	cout << "buf=" << buf << endl;
	strcat(buf, ptr + 1);

	system("pause");
	return 0;
}