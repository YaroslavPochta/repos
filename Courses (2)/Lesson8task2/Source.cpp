#pragma warning (disable : 4996)
#include <fstream>
#include <iostream>
using namespace std;

struct Sstudent 
{
	int course;
	int group;
	char name[20];
	Sstudent(int c, int g, char *n) //конструктор 
	{
		course = c;
		group = g;
		strcpy(name, n);
	}
	void print()
	{
		cout << course << '\t' << group << '\t' << name << endl;
	}
	Sstudent() //конструктор 
	{
		course = 0;
		group = 0;
		strcpy(name, "Unnamed");
	}
};

int main()
{
	Sstudent studs[10];

	studs[0] = Sstudent(1, 2, "Ivanov");
	studs[1] = Sstudent(1, 4, "Pochta");
	studs[2] = Sstudent(2, 4, "DuraTupaya");
	int n = 3;

	for (int i = 0; i < n; i++)
		studs[i].print();

	ofstream out("data.bin", ios::binary);
	out.write((char*)&n, sizeof(n));
	for (int i = 0; i < n; i++)
		out.write((char*)&(studs[i]/*&(studs[i]) == (studs+1)*/), sizeof(Sstudent));



	system("pause");
	return 0;
}
