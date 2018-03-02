#include <iostream>
using namespace std;

int main1()
{
	char choice = '0';
	int a;
	int b;
	while ((int)choice != 32)
	{
		cout << "What operation whould you like to start?" << endl;
		cout << "1. Amount (+)" << endl;
		cout << "2. Subtraction (-)" << endl;
		cout << "3. Multiplication (*) " << endl;
		cout << "4. Division (/)" << endl;
		cout << "5. Remainder of the division (%)" << endl;
		cout << "If you want to exit press 'q'. " << endl;
		cin >> choice;
		cout << "Input first value,  operation and the second value." << endl;
		cin >> hex >> a >> choice >> hex >> b;
		switch (choice)
		{
		case '+':case '1': cout << a << "+" << b << "=" << hex << a + b << endl;
			break;
		case '-': case '2':  cout << a << "-" << b << "=" << hex << a - b << endl;
			break;
		case '*': case '3': cout << a << "*" << b << "=" << hex << a * b << endl;
			break;
		case '/': case '4': {
			if (b != 0) { cout << a << "/" << b << "=" << hex << (double)a / b << endl; }
			else {
				while (b == 0)
				{
					cout << "Uncrrect result, please inpur your values again" << endl;
					cin >> a >> choice >> b;
					cout << a << "/" << b << "=" << hex << (double)a / b << endl;
				}
			}
		}
				  break;
		case '%': case '5': {
			if (b != 0) { cout << a << "%" << b << "=" << a % b << endl; }
			else {
				while (b == 0)
				{
					cout << "Uncrrect result, please inpur your values again" << endl;
					cin >> a >> choice >> b;
					cout << a << "%" << b << "=" << hex << a % b << endl;
				}
			}
		}
				  break;
		case 'q': case 'Q': cout << "Exit from the proram" << endl;
			break;
		default:cout << "You entered uncorrect operation " << endl;
		}
		system("pause");
		system("cls");
	}
	return 0;
}