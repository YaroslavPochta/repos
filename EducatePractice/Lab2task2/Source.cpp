#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <map>
#include <set>
using namespace std;

void display(string str)
{
	cout << str << ", ";
}
char letterForSearching;
void searchingAndDisplay(string str)
{
	if (str[0] == letterForSearching)
		display(str);
}
char letterForDeleting;
bool searching(string str)
{
	if (str[0] == letterForDeleting)
		return true;
	return false;
}
int main()
{
	vector<string> vec;
	fstream fin;
	fin.open("Text.txt");
	string str;
	while (!fin.eof())
	{
		fin >> str;
		vec.push_back(str);
	}

	sort(vec.begin(), vec.end());
	cout << "Sorted words: " << endl;
	for_each(vec.begin(), vec.end(), display);
	cout << "\n\n";

	cout << "Input letter and we display all words that started from it: ";
	cin >> letterForSearching;
	for_each(vec.begin(), vec.end(), searchingAndDisplay);
	cout << "\n\n";

	cout << "Input letter and we delete all words thaty started from it: ";
	cin >> letterForDeleting;
	vector<string>::iterator first = find_if(vec.begin(), vec.end(), searching);
	vector<string>::iterator last = find_if_not(first, vec.end(), searching);
	vec.erase(first, last);
	for_each(vec.begin(), vec.end(), display);
	cout << "\n\n\n";

	set<string> stringSet;
	for_each(vec.begin(), vec.end(), [&stringSet](string str) { stringSet.insert(str); });
	int counter;
	cout << "There are " << stringSet.size() << " unique words:\n";
	for_each(stringSet.begin(), stringSet.end(), display);
	cout << "\n\n";

	map<string, int> wordsMap;
	for_each(vec.begin(), vec.end(), [&wordsMap, &vec](string str) { wordsMap.insert(make_pair(str, count(vec.begin(), vec.end(), str))); });
	for_each(wordsMap.begin(), wordsMap.end(), [](pair<string, int> elem) {cout << "The word <<" << elem.first << ">> meets " << elem.second << " times.\n"; });

	cin >> letterForDeleting;
	return 0;
}