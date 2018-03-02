#include <iostream>
#include <vector>

using namespace std;

void vectorOutput(vector<int> vect)
{
	cout << endl <<  " Vector: " << endl;
	for (int i = 0; i < vect.size(); ++i)
		cout << vect[i] << " ";
	cout << endl;
}

vector<int> findConstants(char* str) {
	vector<int> arrayOfConstansts;
	char digits[] = "1234567890";
	int i;

	while (str != NULL)
	{
		i = 0;
		while (isdigit(str[i]) > 0)
			++i;

		char* charNumeral = new char[i];
		for (int j = 0; j < i; ++j)
			charNumeral[j] = str[j];
		
		int intNumeral = atoi(charNumeral);
		delete charNumeral;

		if (i != 0)
			arrayOfConstansts.push_back(intNumeral);

		str = strpbrk(str + i, digits);
	}
	return arrayOfConstansts;
}

int main3()
{
	char* str = new char[100];
	vector<int> numbers;

	cout << "Input string: ";
	cin.getline(str, 100);

	numbers = findConstants(str);

	cout << "Decimal constants in the string: ";
	vectorOutput(numbers);
	delete str;
	system("pause");
	return 0;
}