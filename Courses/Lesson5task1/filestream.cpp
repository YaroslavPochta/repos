#pragma warning (disable : 4996)
#include <stdio.h>
#include <iostream>
#include "func.h"
int main()
{
	FILE * fin;
	if ((fin = fopen("in.txt", "r")) == NULL)
	{
		printf("Error!");
		return 0;
	}

	int size;
	fscanf(fin, "%d", &size);
	int *arr = new int[size];

	for (int i = 0; i < size; i++)
		fscanf(fin, "%d", &(arr[i]));

	for (int i = 0; i < size; i++)
		//printf("%d ", arr[i]);
		printf("arr[%d] = %d\n", i, arr[i]);
	fclose(fin);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FILE * fout = fopen("out.txt", "w");
	if (fout == NULL)
	{
		printf("Error!");
		return 0;
	}
	for (int i = 0; i < size; i++)
		fprintf(fout, "arr[%d] = %d\n", i, arr[i]);

	fclose(fout);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	fout = fopen("in.txt", "a");
	fprintf(fout, "\nWhat a fuck is going on?");
	fclose(fout);

	delete[] arr;
	system("pause");
	return 0;
}