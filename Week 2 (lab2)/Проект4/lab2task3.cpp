#include <iostream>
using namespace std;
int main3()
{
	int n;
	int amount = 0; //������������ ���������� 
	int number = 0;
	cout << "Enter the N "; //�������� �����, ����� ���� �������� �� ����� ������
	cin >> n;
	while (n > 0) //���������� �����
	{
		number = n % 10; //������ ��������� ����� ����� ��������� ������� �� ������� �� 10
		amount += number; //������������ ���� � �����
		n = (n)/10;
	}
	cout << "The amount is " << amount << endl;
	system("pause");
	return 0;
}