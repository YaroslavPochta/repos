#include <iostream>
using namespace std;
int main1()
{
	int n;
	cout << "Enter your numeral ";
	bool isEvenNumber = true;
	cin >> n;//Ввод числа, которое требуется проверить
	while (n <= 0)
	{
		cout << "Error! Enter correct numeral ";
		cin >> n;
	}
	int k = 1; // 2^0
	while (n > k) //Проверка числа
	{
		k = k << 1; // k *=2
	}
	if (n==k)
		cout << "Yes, N is the degree of two" << endl;
	else
		cout << "No, N isn't the degree of two " << endl;

	/*while ((n > 2) && (isEvenNumber)) //Проверка числа
	{
		if (n % 2 == 0) //Проверка четности числа
			n = n / 2; //Деление числа на 2
		else
			isEvenNumber = false; //присвоение переменной ложного значения если числа не делится на 2
	}
	if (((n % 2 == 0) && isEvenNumber) || (n == 1)) //Условие,если число является степенью двойки
		cout << "Yes, N is the degree of two" << endl;
	else
		cout << "No, N isn't the degree of two " << endl;
	
	*/
	system("pause");
	return 0;

}