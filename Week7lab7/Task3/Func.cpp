#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isFirstHaveHigerPriorityThanSecond(char firstOperation, char secondOperation) 
{
	int firstOperationPriority;
	int secondOperationPriority;

	switch (firstOperation)
	{
		case '*': case '/':{ firstOperationPriority = 1;  break; }
		case '+': case '-':{ firstOperationPriority = 0;  break; }
		default: return NULL;
	}
	switch (secondOperation)
	{
		case '*': case '/': { secondOperationPriority = 1;  break; }
		case '+': case '-': { secondOperationPriority = 0;  break; }
		default: return NULL;
	}

	if ((firstOperationPriority - secondOperationPriority) >= 0)
		return true;
	else
		return false;
}
bool isUnaryOperation(string str, int i)
{
	if (i >= 0)
		if (str[i] == '-' || str[i] == '+')
			if (i == 0) return true;
			else if (str[i - 1] == '(')	return true;
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
void calculationWithBrakets(vector<int>& vect, stack<char>& operations) 
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
			string stringNumeral;
			int j = 0;
			while (isdigit(str[i + j]) > 0)
			{
				stringNumeral.push_back(str[i + j]);
				++j;
			}

			if (isUnaryOperation(str, i - 1) == false)
				vect.push_back(stoi(stringNumeral));
		
			else 
			{
				if (str[i - 1] == '+') 
					vect.push_back(stoi(stringNumeral));
				
				if (str[i - 1] == '-') 
					vect.push_back((-1) * stoi(stringNumeral));
			}
					i += j;
		}
		else 
		{
			if (str[i] == '(')
			{
				operations.push(str[i]);
				++i;
			}
			else
			{
				if (str[i] == ')')
				{
					while (operations.top() != '(')
						calculationWithBrakets(vect, operations);
					operations.pop();
					++i;
				}
				else
				{
					while (true)
					{
						if (operations.empty() == false)
						{
							if (isFirstHaveHigerPriorityThanSecond(operations.top(), str[i]) == true)
								calculationWithBrakets(vect, operations);
							else break;
						}
						else break;
					}
					if (isUnaryOperation(str, i) == false)
						operations.push(str[i]);
					++i;
				}
			}
		}
	}
	return vect[0];
}