#include "Student.h"
Student::Student()
{
	lastname = "\0";
	groupNumber = 0;
}
Student::Student(string str, int group, vector<int> arr)
{
	lastname = str;
	groupNumber = group;
	marks = arr;

}

Student::~Student() {}
ostream& operator<< (ostream& stream, const Student stud)
{
	cout << setw(15) << stud.lastname << setw(15) <<  stud.groupNumber << setw(10);
	for (int j = 0; j < stud.marks.size(); j++)
		cout << stud.marks[j] << " ";
	cout << endl;
	return stream;
}
bool operator< (const Student& st1, const Student& st2)
{
	for (int i = 0; (i < st1.lastname.length()) && (i < st2.lastname.length()); i++)
		if ((int)st1.lastname[i] < (int)st2.lastname[i])
			return true;
	return false;
}
/*
istream& operator>> (istream& stream, const Student stud)
{
	fin >> stud.lastname >> stud.groupNumber;
	for (int j = 0; j < 5; j++)
	{
		fin >> val;
		stud.marks.push_back(val);
	}
	return stream;
}*/