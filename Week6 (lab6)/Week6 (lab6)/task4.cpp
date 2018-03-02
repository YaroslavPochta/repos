#include <iostream>
#include <vector>

using namespace std;

void vectorOutput(vector<double> vect) {
	cout << "Real constants in your string: " << endl;
	for (int i = 0; i < vect.size(); ++i) {
		cout << vect[i] << " ";
	}
	cout << endl;
}
bool isItDigits(char* str, int length)
{
	for (int i = 0; i < length; ++i)
		if (isdigit(str[i]) > 0)
			return true;
	return false;
}
vector<double> searchingRealConstants(char* str)
{
	vector<double> arrayOfRealConstants;
	char digits[] = "123456789.0";
	int lenght = 0;

	while (str != NULL)
	{
		lenght = 0;
		int numberOfDots = 0;
		while ((numberOfDots != 2) && (isdigit(str[lenght]) > 0 || str[lenght] == '.'))
		{
			++lenght;
			if (str[lenght] == '.')
				++numberOfDots;
		}

		char* charNumeral = new char[lenght];
		for (int j = 0; j < lenght; ++j) 
			charNumeral[j] = str[j];
		
		double intNumeral = atof(charNumeral);

		if (isItDigits(charNumeral, lenght))
			arrayOfRealConstants.push_back(intNumeral);

		delete[] charNumeral;
		str = strpbrk(str + lenght, digits);
	}
	return arrayOfRealConstants;
}

int main() 
{
	char* str = new char[100];
	vector<double> numbers;

	cout << "Input string: ";
	cin.getline(str, 100);

	numbers = searchingRealConstants(str);

	cout << "Real constants in string: ";
	vectorOutput(numbers);
	delete[] str;
	system("pause");
	return 0;
}
