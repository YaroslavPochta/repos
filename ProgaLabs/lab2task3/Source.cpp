#include "Route.h"

bool howToSort(Route& rt1, Route& rt2);
void searchingDriver(pair<int, Route> route);
void insertingBusModels(pair<int, Route> route);
void infoAboutRoute(multimap<int, Route> buses);
void editingInformation(multimap<int, Route> buses);
void searchingInformationAboutDriver(multimap<int, Route> buses);
void diffBusModels(multimap<int, Route> buses);

int main()
{
	Route rt;
	fstream fin;
	fin.open("data.txt", ios::in);
	vector<Route> routes;
	int n;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> rt.routeNumber >> rt.driver >> rt.busInfo.first >> rt.busInfo.second;
		routes.push_back(rt);
	}

	sort(routes.begin(), routes.end(), howToSort);

	cout << setw(12) << "Route number" << setw(15) << "Driver " << setw(15) << "Number of bus" << setw(15) << "Model of bus" << endl << endl;
	for (int i = 0; i < routes.size(); i++)
		cout << routes[i];

	multimap<int, Route, less<int>> buses;
	for (int i = 0; i < routes.size(); i++)
		buses.insert(make_pair(routes[i].routeNumber, routes[i]));


	infoAboutRoute(buses);

	editingInformation(buses);

	searchingInformationAboutDriver(buses);

	diffBusModels(buses);

	cout << endl << endl;
	system("pause");
	return 0;
}