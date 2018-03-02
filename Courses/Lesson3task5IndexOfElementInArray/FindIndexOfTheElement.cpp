/*#include <iostream>
using namespace std;
void initRandom(int mas[], int size, int a, int b)
{
	for (int i = 0; i < size; i++)
		mas[i] = a + rand() % (b - a);
}
/////////////////////////////////////////////////////
int searchingValueInArray(int mas[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == value) 
			return i;
		else return -1;
	}
}
/////////////////////////////////////////////////////
void output(int mas[], int size, char title[])
{
	cout << title;
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0) { cout << endl; }
		cout << mas[i] << '\t';
	}
}
/////////////////////////////////////////////////////////
int main1()
{
	int n;
	cout << "Enter number of the elements in your array ";
	cin >> n;
	int *arr = new int[n];
	initRandom(arr, n, 0, 100);
	output(arr, n, "A:");
	cout << endl;

	int number;
	cout << "Input your number : ";
	cin >> number;
	
	if (searchingValueInArray(arr, n, number) == -1)
		cout << "There is no such number";
	else cout << "Your number on the " << searchingValueInArray(arr, n, number) << " position";

	system("pause");
	return 0;
}
*/