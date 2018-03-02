#pragma once
#include "Functions.cpp"
void initRandom(int mas[], int size, int a, int b);
void output(int* mas, int size, char title[]);
int indexOfMinElementInArray(int *arr, int first, int last);
int minInTheArray(int mas[], int first, int last);
void InputingArray(int mas[], int size);
int searchingValueInArray(int mas[], int size, int value);
void selectionSortV(int*arr, int size);
//int binarySearch(int*arr, int left, int right, int value);
//void insertionSortUsingBinarySearch(int *mas, int size);
int isSubstring(int *mas1, int *mas2, int size1, int size2);
//bool isSubset(int *mas1, int *mas2, int size1, int size2);
bool isItSimple(int n);
int deletingSimpleNumerals(int *mas, int size);
int* simpleNumeralsArray(int *mas, int size, int&);

