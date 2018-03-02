#include <iostream>
using namespace std;
int main4()
{
	int n;
	int i = 1;
	double sum = 1;
	double factorial = 1; //блок формирования переменных
	cout << "Enter the N ";
	cin >> n; //ввод числа n
	while (n < 0)
	{	cout << "Error! Enter correct number";
		cin >> n;}
	while (i <= n) // вычисляем i-тое слагаемое 
	{
		factorial *= i; //вычисление факториала числа i
		sum += (1 / factorial); //прибавляем значение 1/i! в случае успешного выполнения цикла
		i++; //увеличиваем i на 1 для того, чтобы оно приближалось к n
	}
	cout << "The answer is " << sum << endl; //вывод ответа
	system("pause");
	return 0;
}