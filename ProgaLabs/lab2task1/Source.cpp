//Проверить и сравнить следующие стандартные алгоритмы для set и multiset: include, set_intersection, set_difference, set_union
#pragma warning (disable:4786)
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <set>
using namespace std;
void display(int val)
{
	cout << val << ", ";
}
int main()
{
	set<int, less<int>> set1;
	multiset<int, less<int>> multiset1;

	for (int i = 1; i <= 20; i++)
	{
		set1.insert(i*(i - 1));
		multiset1.insert(i*(i - 1));
	}
	multiset1.insert(81);
	multiset1.insert(81);

	set<int, less<int>> set2;
	multiset<int, less<int>> multiset2;

	for (int i = 1; i <= 10; i++)
	{
		set2.insert(i*(i - 1));
		multiset2.insert(i*(i - 1));
	}
	for (int i = 1; i <= 10; i++)
	{
		set2.insert(i*i);
		multiset2.insert(i*i);
	}
	multiset2.insert(81);

	set<int, less<int>> set3;
	multiset<int, less<int>> multiset3;
		
	cout << "First set:" << endl;
	for_each(set1.begin(), set1.end(), display);
	cout << endl;

	cout << "Second set:" << endl;
	for_each(set2.begin(), set2.end(), display);
	cout << endl << endl;


	cout << "First multiset:" << endl;
	for_each(multiset1.begin(), multiset1.end(), display);
	cout << endl;

	cout << "Second multiset:" << endl;
	for_each(multiset2.begin(), multiset2.end(), display);
	cout << endl << endl;

	cout << "Intersection of sets: " << endl;
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set3, set3.begin()));
	for_each(set3.begin(), set3.end(), display);
	cout << endl;
	set3.clear();

	cout << "Intersection of multisets: " << endl;
	set_intersection(multiset1.begin(), multiset1.end(), multiset2.begin(), multiset2.end(), inserter(multiset3, multiset3.begin()));
	for_each(multiset3.begin(), multiset3.end(), display);
	set3.clear();
	multiset3.clear();

	cout << "\n\nIncludes of sets: \n" << includes(set1.begin(), set1.begin(), set2.begin(), set2.end()) << endl;
	cout << "Includes of multisets: \n" << includes(multiset1.begin(), multiset1.begin(), multiset2.begin(), multiset2.end()) << endl << endl;


	cout << "Difference of sets : \n";
	set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set3, set3.begin()));
	for_each(set3.begin(), set3.end(), display);
	set3.clear();

	cout << "\nDifference of multisets : \n";
	set_difference(multiset1.begin(), multiset1.end(), multiset2.begin(), multiset2.end(), inserter(multiset3, multiset3.begin()));
	for_each(multiset3.begin(), multiset3.end(), display);
	cout << endl << endl;
	multiset3.clear();


	cout << "Union of sets : \n";
	set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set3, set3.begin()));
	for_each(set3.begin(), set3.end(), display);
	set3.clear();

	cout << "\nUnion of multisets : \n";
	set_union(multiset1.begin(), multiset1.end(), multiset2.begin(), multiset2.end(), inserter(multiset3, multiset3.begin()));
	for_each(multiset3.begin(), multiset3.end(), display);
	cout << endl << endl;
	multiset3.clear();

	system("pause");
	return 0;
}