//на входе строка символов
//cоставить все слова начинающиеся на заданные на заданные буквы,и заканчивающиеся на заданные буквы

#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
using namespace std;
int main()
{//               012345             1-4   3-4  
	char str[] = "zanexo";// ответ - anex  ex
	char first[] = "aeo";
	char last[] = "xz";
	int start[10], nStart = 0;
	char *ptr = strpbrk(str, first);
	cout << (ptr - str) << endl;
	while (ptr != NULL)
	{
		start[nStart] = ptr - str;
		nStart++;
		ptr = strpbrk(ptr + 1, first);
	}
	cout << "Start: ";
	for (int i = 0; i < nStart; i++)
	{
		cout << start[i] << '\t';
	}
	cout << endl;

	int finish[10], nFinish = 0;
	ptr = strpbrk(str, last);

	while (ptr != NULL)
	{
		finish[nFinish] = ptr - str;
		nFinish++;
		ptr = strpbrk(ptr + 1, last);
	}

	cout << "Finish: ";                         //start 1 3 5          
	for (int i = 0; i < nFinish; i++)           //finish 0 4 
	{
		cout << finish[i] << '\t';
	}
	cout << endl;

	for (int i = 0; i < nStart; i++)
	{          //start[i]-finish[j] 
		int j;
		for (j = 0; j < nFinish; j++)
		{
			if (start[i] <= finish[j])
				break;
		}
		for (; j < nFinish; j++)
			cout << start[i] << "-" << finish[j] << endl;


	}

	system("pause");
	return 0;
}