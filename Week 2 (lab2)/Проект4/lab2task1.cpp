#include <iostream>
using namespace std;
int main1()
{
	int n;
	cout << "Enter your numeral ";
	bool isEvenNumber = true;
	cin >> n;//���� �����, ������� ��������� ���������
	while (n <= 0)
	{
		cout << "Error! Enter correct numeral ";
		cin >> n;
	}
	int k = 1; // 2^0
	while (n > k) //�������� �����
	{
		k = k << 1; // k *=2
	}
	if (n==k)
		cout << "Yes, N is the degree of two" << endl;
	else
		cout << "No, N isn't the degree of two " << endl;

	/*while ((n > 2) && (isEvenNumber)) //�������� �����
	{
		if (n % 2 == 0) //�������� �������� �����
			n = n / 2; //������� ����� �� 2
		else
			isEvenNumber = false; //���������� ���������� ������� �������� ���� ����� �� ������� �� 2
	}
	if (((n % 2 == 0) && isEvenNumber) || (n == 1)) //�������,���� ����� �������� �������� ������
		cout << "Yes, N is the degree of two" << endl;
	else
		cout << "No, N isn't the degree of two " << endl;
	
	*/
	system("pause");
	return 0;

}