#include <forward_list>
#include <algorithm>
#include <iostream>
using namespace std;
template <typename type>
class Array :  public forward_list<type>
{
public:
	Array();
	Array(int);
	Array(int, type);
	
	int size();
	type& operator[] (int);
	void push_back(type);
	type pop_back();
	friend ostream& operator << (ostream&, Array<type>&);
	~Array();
};
int sizeCounter(int size)
{
	return (++size);
}
template <class type>
Array<type>::Array() : forward_list() {}

template <class type>
Array<type>::Array(int size) : forward_list(size) {}

template <class type>
Array<type>::Array(int size, type value) : forward_list(size, value) {}

template <class type>
Array<type>::~Array() {}

template <class type>
type& Array<type>::operator[] (int position) 
{
	auto iter = this->begin();
	for (int i = 0; i < position; ++i) 
		iter++;
	return *iter;
}

template <class type>
int Array<type>::size() 
{
	int size = 0;
	for_each(this->begin(), this->end(), [&size](type i) {++size; });
	return size;
}

template <class type>
void Array<type>::push_back(type element) 
{
	this->reverse();
	this->push_front(element);
	this->reverse();
}

template <class type>
type Array<type>::pop_back() 
{
	type value;
	this->reverse();
	value = this->front();
	this->pop_front();
	this->reverse();
	return value;
}

template <typename type>
ostream& operator << (ostream &stream, Array<type>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		stream << arr[i] << " ";
	stream << endl;
	return stream;
}