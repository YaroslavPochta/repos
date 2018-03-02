#include "Array.h"
//#include <fstream>

int main() 
{
	Array<int> arr;
	for (int i = 0; i < 15; i++)
		arr.push_back(i*i);

	cout << "Array: \n";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << "  ";
	cout << endl;
	cout << "5 last elements: ";
	for (int i = 0; i < 5; i++)
		cout << arr.pop_back() << " ";
	cout << endl;
	cout << arr;
	system("pause");
	return 0;
}