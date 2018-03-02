#include "Route.h"

Route::~Route() {}

ostream& operator<< (ostream& stream, Route& rt)
{
	stream << setw(6)<< rt.routeNumber << setw(20) << rt.driver << setw(11) << rt.busInfo << endl;
	return stream;
}
ostream& operator<< (ostream& stream, pair<int, string> p)
{
	stream << p.first << setw(20) << p.second;
	return stream;
}