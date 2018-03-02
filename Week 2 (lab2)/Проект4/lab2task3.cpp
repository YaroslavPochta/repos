#include <iostream>
using namespace std;
int main3()
{
	int n;
	int amount = 0; //формирование переменных 
	int number = 0;
	cout << "Enter the N "; //введение числа, сумму цифр которого мы будем искать
	cin >> n;
	while (n > 0) //построение цикла
	{
		number = n % 10; //чтение последней цифры путем получения остатка от деления на 10
		amount += number; //суммирование цифр в числе
		n = (n)/10;
	}
	cout << "The amount is " << amount << endl;
	system("pause");
	return 0;
}