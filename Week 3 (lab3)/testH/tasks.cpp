#include <iostream> 
using namespace std;

void task1()
{
	cout << "Input number N" << endl;
	int N;
	cin >> N;
	if (N < 1) cout << "N should be natural namber." << endl;
	else {
		int mas[10] = {};
		int i;
		while (N > 0)
		{
			i = N % 10;
			mas[i]++;
			N = N / 10;
		}
		int k = 0;
		for (int i = 0; i < 10; i++)
		{
			if (mas[i] != 0) k = k + 1;
		}
		cout << "There is " << k << " different numerals" << endl;
	}
	system("pause");


}
void task2()
{
	cout << "Input number N" << endl;
	int N;
	cin >> N;
	int n;
	int numerals = 0;
	cout << "Number 0" << endl;
		cout << "Number 1" << endl;
	for (n = 1; n < N; n++)
	{
		//int m = n;
		// —читаю количество цифр в числе
		/*while (m > 0) 
		{
			m = m / 10;
			numerals++;
		}*/
		numerals = ceil(log10(n));
		//cout << numerals << endl;
		int p = 1;
		for (int i = 0; i < numerals; i++)
		{
			p *= 10;
		}
		if (((n*n) % p) == n)
			cout << "Number " << n << endl;
		numerals = 0;
	}
	system("pause");
}
int NOD(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	return a + b;
}

void task3()
{
	cout << "Input number N" << endl;

	int N;
	cin >> N;
	for (int d = 2; d < N; d++)
	{
		for (int n = 1; n < d; n++)
		{
			if (NOD(d, n) == 1)
				cout << n << "/" << d << endl;
		}
	}
}

bool isItPerfect(int n)
{
	int sum = 1;
	int reminder;
	int divider;
	int sq = sqrt(n) ;
	for (int d = 2; d <= sq; d++)
	{
		reminder = n % d;
		divider = n / d;
		if (reminder == 0) { sum = sum + d + divider; }
	}
		return sum==n;
}

void task4()
{
	cout << "Input number N" << endl;
	int N;
	cin >> N;
	if (N < 1) cout << "It is not a natural number!";
	for (int n = 2; n <= N; n++)
	{
		if (isItPerfect(n))
			cout << "n= " << n << endl;
	}
	system("pause");
}

struct Date
{
	int day;
	int month;
	int year;
};
bool isLeapYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	return false;
}
bool isValidDate(Date date)
{
	if ((date.day < 1) || (date.month<1) || (date.month>12) || (date.year < 0))
		return false;
	switch (date.month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		if (date.day > 31)
			return false;
		break;
	}
	case 4: case 6: case 9: case 11:
	{
		if (date.day > 30)
			return false;
		break;
	}
	case 2:
	{
		if (isLeapYear(date.year))
		{
			if (date.day > 29)
				return false;
		}
		else
		{
			if (date.day > 28)
				return false;
		}

	}

	}
	return true;
}
int howMuchDaysInMonth(int month, int year)
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		return 31;
		break;
	}
	case 4: case 6: case 9: case 11:
	{
		return 30;
		break;
	}
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	};
}
int howMuchDays(Date dateOfBirth, Date currentDate)
{
	int amountOfDays = 0;
	if ((dateOfBirth.year == currentDate.year) && (dateOfBirth.month == currentDate.month))
		return currentDate.day - dateOfBirth.day + 1;
	amountOfDays = howMuchDaysInMonth(dateOfBirth.month, dateOfBirth.year) - (dateOfBirth.day - 1);

	for (int monthIndex = dateOfBirth.month+1; monthIndex <=12; monthIndex++)
		amountOfDays += howMuchDaysInMonth(monthIndex, currentDate.year);
	int yearIndex = dateOfBirth.year+1;
	while (yearIndex < currentDate.year)
	{
		if (isLeapYear(yearIndex))
			amountOfDays += 366;
		else
			amountOfDays += 365;
		yearIndex++;
	}

	for (int monthIndex = 1; monthIndex < currentDate.month; monthIndex++)
		amountOfDays += howMuchDaysInMonth(monthIndex, currentDate.year);

	amountOfDays += currentDate.day;
	return amountOfDays;
}
bool isCorrectInput(Date &dateOfBirth, Date &currentDate)
{
	if (dateOfBirth.year > currentDate.year)
	{
		swap(dateOfBirth.year, currentDate.year);
		swap(dateOfBirth.month, currentDate.month);
		swap(dateOfBirth.day, currentDate.day);
		return false;
	}

	if (dateOfBirth.year = currentDate.year)
		if (dateOfBirth.month > currentDate.month)
		{
				swap(dateOfBirth.month, currentDate.month);
				swap(dateOfBirth.day, currentDate.day);
				return false;
		}

	if (dateOfBirth.year = currentDate.year)
		if (dateOfBirth.month = currentDate.month)
			if (dateOfBirth.month > currentDate.month)
			{
				swap(dateOfBirth.day, currentDate.day);
				return false;
			}

	return true;
}
int task5()
{
	Date dateOfBirth;
	Date currentDate;
	int numberOfLivedDays = 0;

	cout << "input the date of birth" << endl;
	cin >> dateOfBirth.day >> dateOfBirth.month >> dateOfBirth.year;
	if (!(isValidDate(dateOfBirth)))
	{
		cout << "Wrong date" << endl;
		return 0;
	}
	cout << "Current date " << endl;
	cin >> currentDate.day >> currentDate.month >> currentDate.year;
	if (!(isValidDate(currentDate)))
	{
		cout << "Wrong date" << endl;
		return 0;
	}
	if (isCorrectInput == false) cout << "You had inputed incorrect dates and we swap them" << endl;

	cout << "You had lived " << howMuchDays(dateOfBirth, currentDate) << " days" << endl;
	return 0;
}