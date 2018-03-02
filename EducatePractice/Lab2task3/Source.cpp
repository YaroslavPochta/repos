#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
struct stud 
{ 
	string name; 
	int group; 
	double ball; 
};
void display(stud st)
{
	cout << "Name: " << st.name << "\t\tGroup namber: " << st.group << "\t\tAverege ball: " << st.ball << endl;
}
void searchigBall(vector<stud> studVec, double searchingBall)
{
	for_each(studVec.begin(), studVec.end(), [&searchingBall](stud st) {if (st.ball == searchingBall) display(st); });
}
void searchingGroup(vector<stud> studVec, int groupNumber)
{
	for_each(studVec.begin(), studVec.end(), [&groupNumber](stud st) {if (st.group == groupNumber) display(st); });
}
bool sortByName(stud st1, stud st2)
{
	if (st1.name.compare(st2.name)< 0) return true;
	return false;
}
bool operator < (stud st1, stud st2)
{
	return sortByName(st2, st2);
}
bool sortByAvaregeBall(stud st1, stud st2)
{
	if (st1.ball < st2.ball) return true;
	return false;
}
bool sortByNameAndGroupNumber(stud st1, stud st2)
{
	if (st1.group < st2.group) return true;
	else if ((st1.group == st2.group) && (st1.name.compare(st2.name)< 0)) return true; // result < 0 if str1 precedes str2 in the sort order
	else return false;
}
int main()
{
	fstream fin;
	fin.open("studInfo.txt");
	if (!fin.eof())
	{
		int n;
		fin >> n;
		vector<stud> studVec;
		stud st;
		for (int i = 0; i < n; i++)
		{
			fin >> st.name >> st.group >> st.ball;
			studVec.push_back(st);
		}

		for_each(studVec.begin(), studVec.end(), display);

		double searchingBall;
		cout << "\n\nPlease, input ball and we will display all students with this ball: ";
		cin >> searchingBall;
		searchigBall(studVec, searchingBall);

		int groupNumber;
		cout << "\n\nPlease, input group namber and we will display all students from this group: ";
		cin >> groupNumber;
		searchingGroup(studVec, groupNumber);
		system("pause");

		vector<stud> reverse_studVec;
		for_each(studVec.rbegin(), studVec.rend(), [&reverse_studVec](stud st) {reverse_studVec.push_back(st); });
		cout << "\n\nReverse list of students:\n";
		for_each(reverse_studVec.begin(), reverse_studVec.end(), display);
		system("pause");

		cout << "We combined two vectors using merge() and it's the result:\n";
		vector<stud> mergeVec(studVec.size() + reverse_studVec.size());
		sort(studVec.begin(), studVec.end(), sortByName);
		sort(reverse_studVec.begin(), reverse_studVec.end(), sortByName);
		merge(studVec.begin(), studVec.end(), reverse_studVec.begin(), reverse_studVec.end(), mergeVec.begin());
		for_each(mergeVec.begin(), mergeVec.end(), display);
		system("pause");

		cout << "\n\n\nSorted by name:\n";
		sort(studVec.begin(), studVec.end(), sortByName);
		for_each(studVec.begin(), studVec.end(), display);

		cout << "\n\n\nSorted by avarege ball:\n";
		sort(studVec.begin(), studVec.end(), sortByAvaregeBall);
		for_each(studVec.begin(), studVec.end(), display);

		cout << "\n\n\nSorted by group number and name:\n";
		sort(studVec.begin(), studVec.end(), sortByNameAndGroupNumber);
		for_each(studVec.begin(), studVec.end(), display);
	}
	else cout << "File is empty!\n";
	system("pause");
	return 0;
}