#include "Set.h"

Set::Set(): size(0) { mas[size] = '\0';}

Set::Set(const Set &obj): size(obj.size) 
{
	for (int i = 0; i < size; i++)
		this->mas[i] = obj.mas[i];
	mas[size] = '\0';
}
void Set::addNewElement(char value) 
{
	int i = 0;

	while ((value > mas[i]) && (i < size)) i++;
	if (value == mas[i]) return;
	
	size++;

	for (int j = size; j > i; --j)
		mas[j] = mas[j - 1];

	mas[i] = value;
}
ostream& operator<< (ostream& os, const Set& set)
{
	for (int i = 0; i < set.size; ++i)
		os << set.mas[i] << " ";
	return os;
}

istream& operator>> (istream& is, Set& set)
{
	char* str = new char[256];
	is.getline(str, 256);
	for (int i = 0; i < strlen(str); ++i)
		set.addNewElement(str[i]);
	return is;
}


bool Set::IsItHasSuchElement(char element) 
{
	for (int i = 0; i < size; ++i) 
		if (element == mas[i]) 
			return true;
	return false;
}


void Set::operator= (Set set2) 
{
	this->size = set2.size;
	for (int i = 0; i < size; ++i)
		this->mas[i] = set2.mas[i];
	mas[size] = '\0';
}

Set Set::operator* (Set set2) 
{
	Set newSet;
	for (int i = 0; i < this->size; ++i)
		if (set2.IsItHasSuchElement(this->mas[i]) == true)
			newSet.addNewElement(this->mas[i]);
	return newSet;
}

Set Set::operator+ (Set set2) 
{
	Set newSet;
	for (int i = 0; i < this->size; ++i) 
		newSet.addNewElement(this->mas[i]);
	for (int i = 0; i < set2.size; ++i) 
		newSet.addNewElement(set2.mas[i]);
	return newSet;
}
Set Set::operator- (Set set2) 
{
	Set newSet;
	for (int i = 0; i < this->size; ++i)
		if (set2.IsItHasSuchElement(this->mas[i]) == false)
			newSet.addNewElement(this->mas[i]);
	return newSet;
}
bool Set::operator< (Set set2) 
{
	for (int i = 0; i < this->size; ++i)
		if (set2.IsItHasSuchElement(this->mas[i]) == false)
			return false;
	return true;
}
bool Set::operator== (Set set2) 
{
	if ((((*this) - set2).isEmpty() == true) && ((set2 - (*this)).isEmpty() == true))
		return true;
	else 
		return false;
}
Set::~Set() {}