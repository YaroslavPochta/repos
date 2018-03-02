#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class Student
{
public:
	string lastname;
	int groupNumber;
	vector<int> marks;
public:
	Student();
	Student(string str, int group, vector<int> arr);
	friend ostream& operator<< (ostream& stream, const Student stud);
	friend bool operator< (const Student& st1, const Student& st2);
	friend bool operator== (Student & st1, string str) { return (st1.lastname == str); }

	//friend istream& operator>> (istream& stream, const Student stud);
	~Student();
};