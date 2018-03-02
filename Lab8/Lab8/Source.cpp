#include <iostream>
#include "complexNumberStack.h"

int main()
{
	ComplexNumber cn1(1,0);
	ComplexNumber cn2(0, 0);

	elem* stack;
	cout << "pop = ";
	try
	{
		cout << "pop = " << pop(stack);
	}
	catch (Empty& e)
	{
		cout << "Wrong!\n";
		return 0;
	}
	
	for (int i = 1; i < 10; i++)
	{
		cn1.setValue(1, i + 1);
		push(stack, cn1);
	}

	while (!isEmpty(stack))
		cout << "pop()=" << pop(stack);

	cout << "cn1 + cn2 = " << cn1 + cn2 << endl;


	ComplexNumber sum(0,0);
	
	ComplexNumber cnArray[10];
	for (int i = 0; i < 10; i++)
		cnArray[i].setValue(i+1, i);
	cnArray[9].setValue(0, 0);

	for (int i = 0; i < 10; i++)
		cout << cnArray[i] << " ";

	cout << endl << endl;
	ComplexNumber subs(0, 0);
	ComplexNumber mult(1, 1);
	for (int i = 0; i < 9; i++)
	{
		sum = sum + cnArray[i];
		subs = subs - cnArray[i];
		mult = mult * cnArray[i];
	}
	
	cout << "Amount of the elements is " << sum << endl;
	cout << "Substraction of the elements is " << subs << endl;
	cout << "Multiplication of the elements is" << mult << endl;
	ComplexNumber specAmount(0, 0);
	for (int i = 0; i < 9; i++)
	{
		specAmount = specAmount + (cn1 / cnArray[i]);
		cn1.setValue(1, 0);
	}

	cout << "Spac Amount is " << specAmount << endl;

	system("pause");
	return 0;
}