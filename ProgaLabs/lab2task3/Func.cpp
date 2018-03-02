#include "Route.h"

string driverLastname;
bool isItFindAnything = false;
set<string> differentBusModels;

bool howToSort(Route& rt1, Route& rt2)
{
	return (rt1.routeNumber < rt2.routeNumber);
}

void searchingDriver(pair<int, Route> route)
{
	if (route.second.driver == driverLastname)
	{
		isItFindAnything = true;
		cout << route.second;
	}
}

void insertingBusModels(pair<int, Route> route)
{
	differentBusModels.insert(route.second.busInfo.second);
}

void infoAboutRoute(multimap<int, Route> buses)
{
	auto iter = buses.begin();
	int route;
	Route routeInfo;
	cout << "\nInput route number and we show information about it for you: ";
	cin >> route;
	cout << setw(12) << "Route number" << setw(15) << "Driver " << setw(15) << "Number of bus" << setw(15) << "Model of bus" << endl;
	while (iter != buses.end())
	{
		if (route == (*iter).first) cout << (*iter).second;
		iter++;
	}
}

void editingInformation(multimap<int, Route> buses)
{
	int route;
	char choice;
	auto iter = buses.begin();
	cout << "\n\nDo you want to edit any information?(y/n): ";
	cin >> choice;
	if (choice == 'y')
	{
		int decision;
		bool isItThisRouteExist = false;
		cout << "What do you want to edit?(1/2)\n1.Change driver.\n2.Change bus.\n";
		cin >> decision;
		switch (decision)
		{
		case 1:
		{
			cout << "Input route number: ";
			cin >> route;
			while (iter != buses.end())
			{
				if (route == (*iter).first)
				{
					isItThisRouteExist = true;
					cout << (*iter).second;
					cout << "Is it that route and driver?(y/n) ";
					cin >> choice;
					if (choice == 'y')
					{
						cout << "Please, input new driver's lastname: ";
						string newLastname;
						cin >> newLastname;
						(*iter).second.driver = newLastname;
						break;
					}
				}
				iter++;
			}
			if (!isItThisRouteExist) cout << "There is no this route.\n";
			break;
		}
		case 2:
		{
			cout << "Input route number: ";
			cin >> route;
			while (iter != buses.end())
			{
				if (route == (*iter).first)
				{
					isItThisRouteExist = true;
					cout << (*iter).second;
					cout << "Is it that route and bus?(y/n) ";
					cin >> choice;
					if (choice == 'y')
					{
						cout << "Please, input new bus number and model: ";
						pair<int, string> newBus;
						cin >> newBus.first >> newBus.second;
						(*iter).second.busInfo = newBus;
						break;
					}
				}
				iter++;
			}
			if (!isItThisRouteExist)	cout << "There is no this route.\n";
			break;
		}
		default:
		{
			cout << "Uncorrect choice\n";
		}
		}
		cout << "New routes list: \n";
		cout << setw(12) << "Route number" << setw(15) << "Driver " << setw(15) << "Number of bus" << setw(15) << "Model of bus" << endl << endl;
		for (iter = buses.begin(); iter != buses.end(); iter++)
			cout << (*iter).second;
	}

}

void searchingInformationAboutDriver(multimap<int, Route> buses)
{
	cout << "\nPlease, input drivers lastname for the more information about him and nis routes: ";
	cin >> driverLastname;
	cout << setw(12) << "Route number" << setw(15) << "Driver " << setw(15) << "Number of bus" << setw(15) << "Model of bus" << endl << endl;
	for_each(buses.begin(), buses.end(), searchingDriver);

	if (!isItFindAnything)
		cout << "Sorry, but we didn't find this driver.\n";
}

void diffBusModels(multimap<int, Route> buses)
{
	for_each(buses.begin(), buses.end(), insertingBusModels);
	set<string> ::iterator busIterator = differentBusModels.begin();
	cout << "\nDifferent bus models there: ";
	while (busIterator != differentBusModels.end())
	{
		cout << *busIterator << ", ";
		busIterator++;
	}
}
