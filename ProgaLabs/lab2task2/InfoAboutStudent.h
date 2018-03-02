#pragma once
#include "Student.h"
class InfoAboutStudent
{
public:
	int groupNumber;
	vector<int> marks;
	InfoAboutStudent(int groupNumber_, vector<int> marks) { groupNumber_ = 0; marks = { 0,0,0,0,0 }; }
	InfoAboutStudent(Student& stud) { groupNumber = stud.groupNumber; marks = stud.marks; };
	~InfoAboutStudent() {};
};

