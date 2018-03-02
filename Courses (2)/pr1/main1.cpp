#include <iostream>
#include <cstring>
#include <fstream>
#pragma warning (disable : 4996)
using namespace std;
struct Data
{
	int day;
	int month;
	int year;
	Data(char * source)
	{
		char str[20];
		strcpy(str, source);
		char * ptr = strtok(str, "/");
		day = atoi(ptr);
		ptr = strtok(NULL, "/");
		month = atoi(ptr);
		ptr = strtok(NULL, "/");
		year = atoi(ptr);
	}
	Data() :day(1), month(1), year(2017) {}
	void print()
	{
		printf("%2d/%2d/%4d", day, month, year);
	}
};
struct Product
{
	int key;
	char name[20];
	double price;
	Data date;
	void print()
	{
		cout << key << " " << name << " " << price << " ";
		date.print();
		cout << endl;
	}
};
int main()
{
	Product *products;
	int n;
	// чтение из текстового файла
	fstream fs;
	fs.open("input.txt", ios::in);
	fs >> n;
	products = new Product[n];
	for (int i = 0; i < n; i++)
	{
		char buf[50];
		fs >> products[i].key >> products[i].name >> products[i].price >> buf;
		products[i].date = Data(buf);
	}
	fs.close();
	// вывести на экран
	for (int i = 0; i < n; i++)
	{
		products[i].print();
		cout << endl;
	}
	cout << endl;
	// сохранить в бинарный файл
	fs.open("data.bin", ios::out | ios::binary);
	for (int i = 0; i < n; i++)
	{
		fs.write((char*)&products[i], sizeof(Product));
	}
	fs.close();
	// чтение из бинарного и вывод в консоль
	fs.open("data.bin", ios::in | ios::binary);
	if (!fs.is_open())
	{
		cout << " Error " << endl;
		return 0;
	}
	Product tmp;
	while (fs.read((char*)&tmp, sizeof(tmp)))
	{
		tmp.print();
	}
	cout << endl;
	fs.close();
	// добавить в бинарный файл 
	tmp.key = 5;
	strcpy(tmp.name, "butter");
	tmp.price = 2.80;
	tmp.date = Data("29/11/2017");
	fs.open("data.bin", ios::app | ios::binary);
	fs.write((char*)&tmp, sizeof(Product));
	fs.close();
	fs.open("data.bin", ios::in | ios::binary);
	while (fs.read((char*)&tmp, sizeof(tmp)))
	{
		tmp.print();
	}
	fs.close();
	// изменить запись в бинарном файле (bread увеличить цену на 10%)
	/*fs.open("data.bin", ios::in | ios::out | ios::binary);
	if (!fs.is_open())
	{
		cout << " Error " << endl;
		return 0;
	}
	while (fs.read((char*)&tmp, sizeof(tmp)))
	{
		if (strcmp(tmp.name, "milk") == 0)
		{
			tmp.price = tmp.price * 1.1;
			int pos = sizeof(tmp);
			fs.seekp(-pos);
			fs.write((char*)&tmp, sizeof(tmp));
		}

	}
	fs.close();
	fs.open("data.bin", ios::in | ios::binary);
	while (fs.read((char*)&tmp, sizeof(tmp)))
	{
		tmp.print();
	}
	fs.close();*/
	fs.open("data.bin", ios::in | ios::binary);
	if (!fs)
	{
		cout << "Error" << endl;
		return 0;
	}

	while (fs.peek() != EOF)
	{
		fs.read((char*)&tmp, sizeof(tmp));
		tmp.print();
	}
	fs.close();

	//7 - modification (+10% for the bread price)
	
	fs.open("data.bin", ios::in | ios::out | ios::binary);
	if (!fs)
	{
		cout << "Error" << endl;
		return 0;
	}

	int count = 0;
	int size = sizeof(Product);

	while (fs.peek() != EOF)
	{
		fs.read((char*)&tmp, size);
		if (strcmp(tmp.name, "butter") == 0)
		{
			tmp.price *= 1.1;
			fs.seekp(count*size);
			fs.write((char*)&tmp, size);
			fs.seekg((count + 1)*size);
		}
		count++;
	}

	fs.seekg(0);
	cout << "Modify prices:\n";
	while (fs.peek() != EOF)
	{
		fs.read((char*)&tmp, size);
		tmp.print();
	}

	//////////////////////////////////////////////////////                              swap(first, last)               ////////////////////////////////////////////////////////////////
	Product first, last;
	fs.seekg(0);
	fs.read((char*)&first, size);
	fs.seekg((count-1)*size);
	fs.seekp(0);
	fs.read((char*)&last, size);
	first.print();
	cout << "\nLast\n";
	cout << count << "\n\n";
	last.print();
	fs.close();

	system("pause");
	return 0;
}












