#include <iostream>
#include "CVector.h"
#include "vectorex.h"
//#include "vectorex.h"

int main()
{
	vectorex<int> vec(10,0);

	//vectorex vec1;
	for (int i = 0; i < vec.getSize(); i++)
		vec[i] = i;

	cout << vec << endl; 
	
	vec.popFront();
	vec.popFront();
	vec.pushBack(12);


	cout << vec << endl;
	system("pause");
	return 0;
}