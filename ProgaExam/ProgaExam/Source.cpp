#include "RightHandRobot.h"
using namespace std;
int indexOfMinElementInArray(Power **arr, int size, int startPosition)
{
	int indexOfMin = startPosition;
	for (int i = startPosition+1; i < size; i++)
	{
		if (dynamic_cast<LeftHandRobot*>(arr[i]) && dynamic_cast<LeftHandRobot*>(arr[indexOfMin]))
			if ((*dynamic_cast<LeftHandRobot*>(arr[i])).power < (*dynamic_cast<LeftHandRobot*>(arr[indexOfMin])).power)
				indexOfMin = i;
	}
	return indexOfMin;
}
void selectionSort(Power **arr, int size)
{
	int indexOfMin = 0;
	for (int i = 0; i < size; i++)
	{
		indexOfMin = indexOfMinElementInArray(arr, size, i);
		swap(arr[i], arr[indexOfMin]);
	}
}

int main() 
{
	int size;
	cout << "Enter size:" << endl;
	cin >> size;
	Power **arr = new Power*[size];
	for (int i = 0; i < size; i++)
	{
		char choice = 'a';
		cout << "Choose robot ('r' for right-hand, 'l' for left-hand):" << endl;
		cin >> choice;
		cout << "Enter force" << endl;
		int force;
		cin >> force;
		switch (choice)
		{
			case 'r':
			{
				arr[i] = new RightHandRobot(force);
				break;
			}
			case 'l':
			{
				arr[i] = new LeftHandRobot(force);
				break;
			}
			default:
			{
				cout << "You inputed uncorrect symbol!" << endl;
				return 0;
			}
		}
	}
	ofstream fout("output.txt");
	selectionSort(arr, size);
	for (int i = 0; i < size; i++) arr[i]->print(fout);
	fout << "\n\n";
	for (int i = 0; i < size; i++) 
	{
		if (dynamic_cast<LeftHandRobot*>(arr[i])) 
		{
			arr[i]->print(fout);
			for (int j = 0; j < size; j++) 
				if (arr[i]->deltaPower(*arr[j])) 
					arr[j]->print(fout);
			fout << "\n\n";
		}
	}
	system("pause");
	return 0;
}