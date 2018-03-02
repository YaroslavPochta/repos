#pragma once
void task2();
void task1();
void task3();
void task4();
void helloWorld();
int task5();
struct Date
{
	int day;
	int month;
	int year;
};
bool isLeapYear(int year);
bool isValidDate(Date date);
int howMuchDaysInMonth(int month, int year);
int howMuchDays(Date dateOfBirth, Date currentDate);
bool isCorrectInput(Date &dateOfBirth, Date &currentDate);