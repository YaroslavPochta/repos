#include "InfoAboutStudent.h"
#include <algorithm>
#include <numeric>
#include <map>
bool isStudentPassSessionUnsuccessfully(Student& stud)
{
	for (int i = 0; i < 5; i++)
		if (stud.marks[i] < 4)
			return true;
	return false;
}
struct sortStudentStruct
{
	inline bool operator() (const Student st1, const Student st2)
	{
		for (int i = 0; (i < st1.lastname.length()) && (i < st2.lastname.length()); i++)
			if ((int)st1.lastname[0] < (int)st2.lastname[0])
				return true;
		return false;
	}
};
void checkingMarks(Student& stud)
{
	if (isStudentPassSessionUnsuccessfully(stud))
		cout << stud;
}

int main()
{
	fstream fin;
	fin.open("Students.txt", ios::in);
	vector<Student> studVec;
	Student stud;
	int n;
	fin >> n;
	if ((!fin.eof()))
	{
		string lastname_;
		int groupNumber_;
		int val;
		for (int i = 0; i < n; i++)
		{
			fin >> lastname_ >> groupNumber_;
			stud.lastname = lastname_;
			stud.groupNumber = groupNumber_;
			for (int j = 0; j < 5; j++)
			{
				fin >> val;
				stud.marks.push_back(val);
			}
			studVec.push_back(stud);
			for (int j = 0; j < 5; j++)
				stud.marks.pop_back();
		}
		fin.close();

		vector<Student>::iterator iter;
		/*cout << "Lastname" << setw(25) << "Group number" << setw(10) << "Marks" << setw(10) << endl;
		for (int i = 0; i < studVec.size(); i++)
			cout << studVec[i] << endl;*/

		sort(studVec.begin(), studVec.end(), sortStudentStruct());
		cout << "Sorted  list of all students: " << endl;
		cout << "Lastname" << setw(25) << "Group number" << setw(10) << "Marks" << setw(10) << endl;
		for (int i = 0; i < studVec.size(); i++)
			cout << studVec[i];

		cout << endl << endl << "Input lastname of the student you want to delete: ";
		string deleteLastname;
		cin >> deleteLastname;

		auto delStudIter = find(iter = studVec.begin(), iter = studVec.end(), deleteLastname);
		if (delStudIter == studVec.end())
			cout << "Student not found" << endl;
		else
		{
			studVec.erase(delStudIter);
			cout << "Deletion was successful. New list: " << endl;
			cout << "Lastname" << setw(25) << "Group number" << setw(10) << "Marks" << setw(10) << endl;
			for (int i = 0; i < studVec.size(); i++)
				cout << studVec[i];
		}
		cout << endl << endl;

		map<string, InfoAboutStudent, less<string>> someMap;
		map<string, InfoAboutStudent, less<string>>::iterator mapIter;
		InfoAboutStudent info(studVec[0]);
		for (int i = 0; i < studVec.size(); i++)
		{
			info.groupNumber = studVec[i].groupNumber;
			info.marks = studVec[i].marks;
			someMap.insert(make_pair(studVec[i].lastname, info));
		}
		/*
			auto studIter = find_if(iter = studVec.begin(), iter = studVec.end(), isStudentPassSessionUnsuccessfully);
			cout << "Lastname" << setw(25) << "Group number" << setw(10) << "Marks" << setw(10) << endl;
			while (studIter != studVec.end())
			{
				cout << *studIter << endl;
				studIter++;
			}

			cout << "Lastname" << setw(25) << "Group number" << setw(10) << "Marks" << setw(10) << endl;
			auto studIter = studVec.begin();
			auto it = studVec.begin();
			while (studIter != studVec.end())
			{
				studIter = find_if(studIter, studVec.end(), isStudentPassSessionUnsuccessfully);
				cout << *studIter << endl;
			}
		*/
		cout << "Students that didn't pass the session successfully:" << endl;
		for_each(studVec.begin(), studVec.end(), checkingMarks);
		cout << "Please, enter the group numbet and we will find the best student there" << endl;
		int numberOfTheGroup;
		cin >> numberOfTheGroup;
		int maxSum = 0;
		int StudIndex = -1;
		for (int i = 0; i < studVec.size(); i++)
			if (studVec[i].groupNumber == numberOfTheGroup)
				if (maxSum < accumulate(studVec[i].marks.begin(), studVec[i].marks.end(), 0))
				{
					maxSum = accumulate(studVec[i].marks.begin(), studVec[i].marks.end(), 0);
					StudIndex = i;
				}
		if (StudIndex == -1)
			cout << "We couldn't find any student in this group. " << endl;
		else cout << studVec[StudIndex] << endl << endl;
	}
	else cout << "File is empty" << endl;
	system("pause");
	return 0;
}