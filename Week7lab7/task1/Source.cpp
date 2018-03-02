#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBraketBalanseIsCorrect(string str)
{
	//char openBrackets[] = "([{";
	//char closeBrackets[] = ")]}";
	stack<char> brackets;

	for (int i = 0; i < str.size(); ++i)
	{
		if ((brackets.empty() == true) && ((str[i] == ')') || (str[i] == ']') || (str[i] == '}')))
			return false;

		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			brackets.push(str[i]);

		if (str[i] == ')')
		{
			if (brackets.top() == '(')
				brackets.pop();
			else return false;
		}

		if (str[i] == ']')
		{
			if (brackets.top() == '[')
				brackets.pop();
			else return false;
		}

		if (str[i] == '}')
		{
			if (brackets.top() == '{')
				brackets.pop();
			else return false;
		}
	}

	if (brackets.size() == 0)
		return true;
	else
		return false;
}

int main()
{
	string str;
	cout << "Input string: ";
	getline(cin, str);

	if (isBraketBalanseIsCorrect(str) == true)
		cout << "Brackets balance is correct!" << endl;
	else cout << "Brackets balance isn't correct." << endl;

	system("pause");
	return 0;
}

