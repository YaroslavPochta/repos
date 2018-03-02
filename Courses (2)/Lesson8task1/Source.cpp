#pragma warning (disable : 4996)
#include <iostream>
#include <fstream>
using namespace std;

struct Student 
{
	char name[20];
	int marks[3];
	void print(Student * ptr, int n,  int i)
	{
	//	for (int i = 0; i < n; i++)
			cout << "Avarage mark of " << ptr[i].name << " is " << (double)(ptr[i].marks[1] + ptr[i].marks[2] + ptr[i].marks[0]) / 3 << endl;
	}
};
/////////////////////////////////////////////////
bool readFromFile(Student *&ptr, int &n, char *filename)
{
	ifstream fin(filename);
	if (!fin)
	{
		cout << "Error";
		return false;
	}
	fin >> n;
	ptr = new Student[n];
	for (int i = 0; i < n; i++)
		fin >> ptr[i].name >> ptr[i].marks[0] >> ptr[i].marks[1] >> ptr[i].marks[2];
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void toUpper(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = toupper(str[i]);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int findStudent(Student * ptr, int numberOfStudents, char * name)
{
	/*Student *buf = ptr;
	for (int j = 0; buf[j].name != '\0'; j++)
		toUpper(buf[j].name);

	toUpper(name);
	for (int i = 0; i < numberOfStudents; i++)
		if (strcmp(buf[i].name, name) == 0)
			return i;
	return -1;*/
	char buf1[20];
	strcpy(buf1, name);
	toUpper(buf1);
	for (int i = 0; i < numberOfStudents; i++)
	{
		char buf2[20];
		strcpy(buf2, buf1);
		toUpper(buf2);
		if (strcmp(buf1, buf2) == 0)
			return i;
	}
	return -1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	// Student stud = {"Ivanov", {8 , 9 10}};
	// syud = stud1;
	// Student *pSt;
	// pSt = &stud;
	// pSt.name == pSt->name && (*pSt).name == pSt->name

	Student *students = NULL;
	int numberOfStudents = 0;
	readFromFile(students, numberOfStudents, "Text.txt");

	char name[20];
	cout << "Enter name of the student: ";
	cin.getline(name, 20);
	int index = findStudent(students, numberOfStudents, name);
	if (index == -1)
		cout << "There is no student with such name" << endl;
	else
	{ 
		cout << "Number of the student is " << index + 1 << endl;
		students[index].print(students, numberOfStudents, index);
	}

	delete[] students;
	system("pause");
	return 0;
}