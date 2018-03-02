#include "text.h"
#include <algorithm>

Text::Text() 
{
	sep = ' ';
}
bool isItLetter(char ch) 
{
	if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
		return true;
	else 
		return false;
}

void copyStrToStrN(char* str, char*& to_str, int n) 
{
	if (to_str != nullptr)
		delete to_str;
	to_str = new char[n + 1];
	for (int i = 0; i < n; ++i)
		to_str[i] = str[i];
	to_str[n] = '\0';
}
Text::Text(char* str) 
{
	sep = ' ';
	int lenght = 0;
	char* curWord = nullptr;
	char curMark = '\0';

	while (*str != '\0') 
	{
		while (*str == sep) 
			++str;
		lenght = 0;
		while (str[lenght] != sep && str[lenght] != '\0') 
			++lenght;

		curMark = '\0';
		char lastLetter = str[lenght - 1];
		if (isItLetter(lastLetter) == false) 
		{
			curMark = lastLetter;
			copyStrToStrN(str, curWord, lenght - 1);
		}
		else 
			copyStrToStrN(str, curWord, lenght);

		*this += WordWithMark(curWord, curMark);

		str += lenght;
	}
}

bool Text::operator> (Text text2) 
{
	return (this->size() > text2.size());
}

bool Text::operator< (Text text2) 
{
	return (this->size() < text2.size());
}
Text::~Text() {}

ostream& operator<< (ostream& os, text& text) 
{
	int size = text.size();
	for (int i = 0; i < size; ++i) {
		os << text.words[i] << text.separator;
	}
	return os;
}