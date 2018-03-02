#include <iostream>
using namespace std;
int checkDay(int);
int checkMonths(int);
int checkYear(int);
int main()
{
	int day;
	int month;
	int year;

	cout << "Enter the day "; //просьба ввести дату 
	cin >> day;
	day = checkDay( day);

	cout << "Enter the month ";
	cin >> month;
	month = checkMonths(month);

	cout << "Enter the year ";
	cin >> year;
	year = checkYear(year);

	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10:
		//maxMonthDay = 31;
		switch (day)
		{
		case 31:
			day = 1;  month++;
			break;
		default:
			day++;
		}
		break;
	case 12:
		switch (day)
		{
		case 31:
			day = 1;  month = 1; year++;
			break;
		default:
			day++;
		}
		break;
	case 2:
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		{
			if (day > 29)
			{
				do {
					cout << "Input the correct date! ";
					cin >> day;
				} while ((day < 1) || (day > 29));
			}

			if (day == 29)
			{
				day = 1; month++;
			}
			else
				day++;

		}
		else 
		{
			if (day > 28)
			{
				do {
					cout << "Input the correct day! ";
					cin >> day;
				} while ((day < 1) || (day > 28));
			}
			if (day == 28)
			{
				day = 1; month++;
			}
			else
				day++;
		}
		break;
	default:
		switch (day)
		{
		case 30:
			day = 1;  month++;
			break;
		default:
			day++;
		}
	}
	
	cout << day << "." << month << "." << year;
	system("pause");
	return 0;
}
int checkDay(int days)
{
	while ((days > 31) || (days < 1))
	{
		cout << "Input the correct day ";
		cin >> days;
	}
	return days;
}

int checkMonths(int months)
{
	while ((months > 12) || (months < 1))
	{
		cout << "Input the correct mounth ";
		cin >> months;
	}
	return months;
}

int checkYear(int year)
{
	while (year < 1)
	{
		cout << "Input the correct year ";
		cin >> year;
	}
	return year;
}
