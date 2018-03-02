#include <iostream>
#include "func.h"

using namespace std;

void matrOutput(int** matrix, int rows, int columns) {
	cout << "Matrix: \n";
	for (int i = 0; i < rows; ++i) 
	{
		for (int j = 0; j < columns; ++j) 
			cout << matrix[i][j] << " ";
		
		cout << "\n";
	}
	cout << "\n";
}
int** insertRow(int** matrix, int &rows, int columns) 
{
	int newRows = rows + 1;
	int** newMatr = new int*[newRows];

	int* insertingRow = new int[columns];
	int index;

	cout << "Enter inserting row ( " << columns << " elements ):";
	for (int i = 0; i < columns; ++i) 
		cin >> insertingRow[i];
	
	cout << "Enter position: ";
	cin >> index;

	for (int i = 0; i < index; ++i) 
		newMatr[i] = matrix[i];
	
	newMatr[index] = insertingRow;
	for (int i = index + 1; i < newRows+1; ++i) 
		newMatr[i] = matrix[i - 1];

	return newMatr;
}
int** eraseRow(int** matrix, int &rows, int columns) {
	int** newMatr = new int*[rows - 1];
	int newRows = rows - 1;

	int index;
	cout << "Enter position: ";
	cin >> index;


	for (int i = 0; i < index; ++i) 
		newMatr[i] = matrix[i];
	
	for (int i = index; i < newRows; ++i) 
		newMatr[i] = matrix[i + 1];
	
	return newMatr;
}
int** matrInput(int** &matr, int& rows, int& columns)
{
	cout << "Enter number of rows and columns and matrix: ";
	cin >> rows >> columns;

	matr = new int*[rows];
	for (int i = 0; i < rows; ++i) 
		matr[i] = new int[columns];

	cout << "Enter matrix: " << endl;
	for (int i = 0; i < rows; ++i) 
		for (int j = 0; j < columns; ++j)
		{
			cout << "Matr[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
			if (j == (columns - 1)) cout << endl;
		}
	return matr;
}

int main2()
{ 
	int rows;
	int columns;
	int** matr;

	matr = matrInput(matr, rows, columns);
	
	int choice;
	cout << "What do you want to do?\n1.Insert row\n2.Erase row\nPlease choose(1/2): ";
	cin >> choice;
	int newRows = rows;
	for (int i = 0; i <3; i++)
	{
		int** (*pointer)(int **matr, int &rows, int columns);
		switch (choice)
		{
		case 1:
		{
			pointer = insertRow;
			newRows++;
			break;
		}
		case 2:
		{
			pointer = eraseRow;
			newRows--;
			break;
		}
		default:
		{
			cout << "There in no such operation";
			return 0;
		}
		}
		int** bufMatr = pointer(matr, rows, columns);
		delete[] matr;
		matr = bufMatr;
		matrOutput(bufMatr, newRows, columns);
		switch (choice)
		{
		case 1: rows++; break;
		case 2: rows--; break;
		}
	}
	
	for (int i = 0; i < rows; ++i)
		delete[] matr[i];
	delete[] matr;

	system("pause");
	return 0;
}