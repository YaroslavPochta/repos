/*
Вычислить значение выражения.Выражение задается строкой и содержит арифметическое выражение  из целых и знаков операций + -* "/". 
Например, 22 + 3 * 4 - 7 / 2
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool isFirstHaveHigerPriorityThanSecond(char firstOperaton, char secondOperation) 
{
	int firstOperationPriority;
	int secondOperationPriority;

	switch (firstOperaton) 
	{
		case '*': case '/':
			{
				firstOperationPriority = 1;
				break;
			}

		case '+': case '-':
			{
				firstOperationPriority = 0;
				break;
			}

		default:
			return NULL;
	}
	switch (secondOperation) 
	{
		case '*': case '/':
			{
				secondOperationPriority = 1;
				break;
			}

		case '+': case '-':
			{
				secondOperationPriority = 0;
				break;
			}

	default:
		return NULL;
	}

	if ((firstOperationPriority - secondOperationPriority) >= 0) 
		return true;
	else 
		return false;
}

void vectorOutput(vector<int> vect) 
{
	cout << "Vector:" << endl;
	for (int i = 0; i < vect.size(); ++i) 
		cout << vect[i] << " ";
	cout << endl;
}
int operation(char operation, int a, int b) 
{
	switch (operation)
	{
	case '+': 
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}

}

void calculation(vector<int> & vect, stack<char> & operations) 
{
	int b = vect.back();
	vect.pop_back();
	int a = vect.back();
	vect.pop_back();

	vect.push_back(operation(operations.top(), a, b));

	operations.pop();
}

int reversePolishNotation(string str)
{
	vector<int> vect;
	stack<char> operations;
	str.push_back('+'); 
	int i = 0;

	while (i < str.size()) 
	{
		if (isdigit(str[i]) > 0) 
		{
			string charNumeral;
			int j = 0;
			while (isdigit(str[i + j]) > 0) 
			{
				charNumeral.push_back(str[i + j]);
				++j;
			}
			vect.push_back(stoi(charNumeral));

			i += j;
		}
		else 
		{
			while (true) 
			{
				if (operations.empty() == false) 
				{
					if (isFirstHaveHigerPriorityThanSecond(operations.top(), str[i]) == true) 
						calculation(vect, operations);
					else break;
				}
				else break;
			}
			operations.push(str[i]);
			i++;
		}
	}
	return vect[0];
}


int main()
{
	string str;
	cout << "Input string: ";
	getline(cin, str);
	cout << " = " << reversePolishNotation(str);

	system("pause");
	return 0;
}

