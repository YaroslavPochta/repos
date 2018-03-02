#include <iostream>
using namespace std;
void initRandom(int mas[], int size, int a, int b)
{
	for (int i = 0; i < size; i++)
		mas[i] =a + rand()%(b-a);
}
void output(int mas[], int size, char title[])
{
	cout << title;
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0) { cout << endl; }
		cout << mas[i] << '\t';
	}
}
int maxInTheIntArray( int mas[], int size)
{
	int max = mas[0];
	for (int i = 0; i < size; i++)
	{
		if (mas[i] > max) max = mas[i];
	}

	return max;
}
int main()
{
	int arr[100];
	int n;
	cout << "Enter number of the elements in your array ";
	cin >> n; 
	initRandom(arr, n, 0, 100);
	output(arr, n, "A:");
	cout << endl;
	
	char choice = '0';
	cout << "Do you want to  find maximal element in this array?(y/n)" << endl;
	cin >> choice;
	if (choice == 'y') 
		cout  << "Maximal element is "<< maxInTheIntArray(arr, n) << endl;
	
	system("pause");
	return 0;
}
