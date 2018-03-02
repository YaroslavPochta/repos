#include<iostream>
#include "tasks.h"
using namespace std;

void main() {
	char answer;
	int taskNumber;
	do { 
		cout << "1.Different numbers in the numeral" << endl;
		cout << "2.Automorphic numbers" << endl;
		cout << "3.Irreducible rfactions" << endl;
		cout << "4.Perfect numbers" << endl;
		cout << "What task would you like to run?(1/2/3/4/5): " << endl;
		cin >> taskNumber;
		switch (taskNumber)
		{
		case 1: task1();
			break;
		case 2: task2();
			break;
		case 3: task3();
			break;
		case 4: task4();
			break;
		case 5: task5();
			break;
		default: cout << "It was incorrect number of the task " << endl;
		}
		taskNumber = 0;
		answer = NULL;
		cout << "Do you  want to run other task?(y/n): ";
		cin >> answer;
	} while (answer = 'y');
	system("pause");
	system("cls");
}