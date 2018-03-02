#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>

int val;

bool isItGraterThanValue(int vectorValue)
{
	return (vectorValue > val);
}

using namespace std;
int main()
{
	vector<int> vec;

	ifstream fin("in.txt");
	int n;
	fin >> n;
	int buf;
	for (int i = 0; i < n; ++i)
	{
		fin >> buf;
		vec.push_back(buf);
		cout << vec.back() << " ";
	}
	cout << endl;

	cout << "Input your value " << endl;
	cin >> val;
	cout << "There are " << count(vec.begin(), vec.end(), val) << " numerals equal " << val << endl;
	cout << "Input the value, greater than you want to find " << endl;
	cin >> val;
	cout << "There are " << count_if(vec.begin(), vec.end(), isItGraterThanValue) << " numerals greater than " << val << endl;
	cout << "Size of vector: " << vec.size() << endl;
	cout << "The sum of all numerals in vector is " << accumulate(vec.begin(), vec.end(), 0) << endl;
	cout << "Average value: " << ((double)(accumulate(vec.begin(), vec.end(), 0)) / vec.size()) << endl << endl;
	sort(vec.begin(), vec.end());
	cout << "The biggest value in vector is " << vec[vec.size() - 1] << endl;
	system("pause");
	return 0;