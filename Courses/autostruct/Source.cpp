#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct car
{
	int ID;
	string Brand;
	string Model;
	string Version;
	double Price;
	int Year;
};

int main()
{
	int n = 0;
	cout << "How mach cars do you want to add?\n";
	cin >> n;

	car *cars = new car[n];

	for (int i = 0; i < n; i++)
	{

		cout << "Enter the ID of the car: ";
		cin >> cars[i].ID;
		cout << endl;

		cout << "Brand of the car: ";
		getline(cin, cars[i].Brand);
		cin.get();

		cin.get();
		cout << "Model of the car: ";
		getline(cin, cars[i].Model);
		cin.get();

		cout << "Version of the car: ";
		getline(cin, cars[i].Version);
		cin.get();

		cin.get();
		cout << "Price of the car: ";
		cin >> cars[i].Price;

		cout << "Year of producting: ";
		cin >> cars[i].Year;

		system("cls");
	}

	int CarID = 0;

	cout << "Input ID of the car that you want to explore " << endl << "ID:";
	cin >> CarID;

	cout << "Brand\t" << cars[CarID].Brand;
	cout << "Model\t" << cars[CarID].Model;
	cout << "Version\t" << cars[CarID].Version;
	cout << "Price\t" << cars[CarID].Price;
	cout << "Tear\t" << cars[CarID].Year;



	system("pause");
	return 0;
}