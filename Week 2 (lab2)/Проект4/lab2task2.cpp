#include <iostream>
using namespace std;
int main2()
{
	float x;
	float y; //формирование переменных
	int i = 1;
	cout << "Enter X and Y " << endl;
	cin >> x >> y; //ввод количества километров, которые пробежал бегун в первый день
	while ((x < 0) || (y < 0))
	{cout << "Error! Enter correct numerals";
		cin >> x >> y;}
	while ( x < y) //цикл увеличивает количство км в первый день на 10%, пока оно не превысит в последний день
	{
		x = 1.1*x; 
		i++; // увеличение числа дней при удачном выполнении цикла
	}
	cout << "The answer is " << i << " days" << endl;
	system("pause");
	return 0;
}