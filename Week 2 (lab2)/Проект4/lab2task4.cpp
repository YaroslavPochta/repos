#include <iostream>
using namespace std;
int main4()
{
	int n;
	int i = 1;
	double sum = 1;
	double factorial = 1; //���� ������������ ����������
	cout << "Enter the N ";
	cin >> n; //���� ����� n
	while (n < 0)
	{	cout << "Error! Enter correct number";
		cin >> n;}
	while (i <= n) // ��������� i-��� ��������� 
	{
		factorial *= i; //���������� ���������� ����� i
		sum += (1 / factorial); //���������� �������� 1/i! � ������ ��������� ���������� �����
		i++; //����������� i �� 1 ��� ����, ����� ��� ������������ � n
	}
	cout << "The answer is " << sum << endl; //����� ������
	system("pause");
	return 0;
}