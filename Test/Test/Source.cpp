#include <iostream>
#include <string>
using namespace std;

int main1()
{
	char vowels[] = { 'a','e','y','u','o','i','E','Y','U','O','A','I','у','е','ы','а','о','э','я','и','ю','ё','Ё','У','Е','Ы','А','О','Э','Я','И','Ю' };
	int lenghtOfWord = 0;
	string str;
	cout << "Input your text:" << endl;
	getline(cin, str);
	str + '\0';
	cout << "lenght" << endl;
	cin >> lenghtOfWord;

	for (int i = 0; i < sizeof(str); i++) //Если i-тый элемент строки, следующий за пробелом, табуляцией либо переходом на новую строку,
	{                                     //НЕ гласная буква, то мы входим в основной цикл
		if ((str[i] == (char)32) || (str[i] == '\t') || (str[i] == '\n'))
		{
			for (int j = 0; j < 32; j++) //гласных всего 32 штуки (английский и русский алфавит с обоими регистрами)
			{
				int counter = 0;
				if (str[i+1] != vowels[j]) { counter++; } //Если наша буква не равна никакой из гласных, то увеличиваем счетчик
				else break;
				if (counter == 32) //мы попали на согласную букву
					do {
						if ((str[i + lenghtOfWord] == (char)32) || (str[i + lenghtOfWord] == '\t') || (str[i + lenghtOfWord] == '\n')) //если какое-либо из этих условий верно, то длина слова подходит нам 
							str.erase(i, i + lenghtOfWord);
					} while (str[1 + lenghtOfWord] != '\0');
			}
		}
	};


	cout << str;

	system("pause");
	return 0;
}