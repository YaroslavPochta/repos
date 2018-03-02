#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int n;
	cout << "Input your numeral ";
	cin >> n;
	int temp = n;
	cout << "What task do you want to start?(1/2/3/4)" << endl;

	int choice;
	cin >> choice;
	int counter = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		counter++;
	}
	switch (choice)
	{
	case 1:
		cout << "The is" << counter << " numerals" << endl;
	case 2:
	{
		int reverseN = 0;
		int digit = 0;
		while (temp != 0)
		{
			digit = temp % 10;
			reverseN = reverseN * 10 + digit;
			temp /= 10;
		}
	}

	case 3:
	{
		int maxDigit = 0;
		int minDigit = 9;
		while (temp != 0)
		{
			int digit = temp % 10;
			if (digit < minDigit)
				minDigit = digit;
			if (digit > maxDigit)
				maxDigit = digit;
		}
		cout << "Minimal digit is " << minDigit << endl;
		cout << "Maximal digit is " << maxDigit << endl;
	}
	case 4:
		int result = ((int)(pow(10, counter) + n) * 10 + 1);
		cout << result<< endl;
	}
	system("pause");
	return 0;
}