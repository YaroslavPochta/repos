#include <iostream>
#include <string>
using namespace std;

int main1()
{
	char vowels[] = { 'a','e','y','u','o','i','E','Y','U','O','A','I','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�' };
	int lenghtOfWord = 0;
	string str;
	cout << "Input your text:" << endl;
	getline(cin, str);
	str + '\0';
	cout << "lenght" << endl;
	cin >> lenghtOfWord;

	for (int i = 0; i < sizeof(str); i++) //���� i-��� ������� ������, ��������� �� ��������, ���������� ���� ��������� �� ����� ������,
	{                                     //�� ������� �����, �� �� ������ � �������� ����
		if ((str[i] == (char)32) || (str[i] == '\t') || (str[i] == '\n'))
		{
			for (int j = 0; j < 32; j++) //������� ����� 32 ����� (���������� � ������� ������� � ������ ����������)
			{
				int counter = 0;
				if (str[i+1] != vowels[j]) { counter++; } //���� ���� ����� �� ����� ������� �� �������, �� ����������� �������
				else break;
				if (counter == 32) //�� ������ �� ��������� �����
					do {
						if ((str[i + lenghtOfWord] == (char)32) || (str[i + lenghtOfWord] == '\t') || (str[i + lenghtOfWord] == '\n')) //���� �����-���� �� ���� ������� �����, �� ����� ����� �������� ��� 
							str.erase(i, i + lenghtOfWord);
					} while (str[1 + lenghtOfWord] != '\0');
			}
		}
	};


	cout << str;

	system("pause");
	return 0;
}