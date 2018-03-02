#pragma warning (disable : 4996)
#include <iostream>
#include <string>
using namespace std;
#define USING_MATH_DEFINES

class Stud
{
private:
	char name[20];
	double mark;
public:
	Stud(const char* name_, double mark_) :mark(mark_) { strcpy(name, name_); };
	~Stud() {};
	double getMark() const { return mark; };
	const char* getName() const { return name; };
	void setAvaregeMark(double value) { mark = value; };
	string getString() const { char buf[100]; sprintf(buf, "name = %20s; mark = %5.2f", name, mark); return string(buf); }
};
class Undergraduate : public Stud
{
private:
	int year;
public:
	Undergraduate(const char* name_, double mark_, int year_) : Stud(name_, mark_), year(year_) {}
	~Undergraduate() {};
	int getYear(/) const { return year; }
	string getString() const { char buf[100]; sprintf(buf, "%s; year = %2d", (Stud::getString()).c_str(), year); return buf; }
};
class PostGraduated : public Undergraduate
{
	char adviser[20];

};

int main()
{
	Stud st1("Ivan ", 3.5);
	cout << "st1 = " << st1.getString() << endl;
	Undergraduate ug1("Petr Moifas", 4.3, 2);
	cout << ug1.getString() << endl;
	system("pause");
	return 0;
}