#include <iostream>
using namespace std;
int main2()
{
	float x;
	float y; //������������ ����������
	int i = 1;
	cout << "Enter X and Y " << endl;
	cin >> x >> y; //���� ���������� ����������, ������� �������� ����� � ������ ����
	while ((x < 0) || (y < 0))
	{cout << "Error! Enter correct numerals";
		cin >> x >> y;}
	while ( x < y) //���� ����������� ��������� �� � ������ ���� �� 10%, ���� ��� �� �������� � ��������� ����
	{
		x = 1.1*x; 
		i++; // ���������� ����� ���� ��� ������� ���������� �����
	}
	cout << "The answer is " << i << " days" << endl;
	system("pause");
	return 0;
}