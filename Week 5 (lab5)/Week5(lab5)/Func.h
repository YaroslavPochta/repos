#pragma once

void initRandom(int mas[], int size, int a, int b);
void output(int mas[], int size, char title[]);
int indexOfMinElementInArray(int *arr, int first, int last);
int minInTheArray(int mas[], int first, int last);
void InputingArray(int mas[], int size);
int searchingValueInArray(int mas[], int size, int value);
void selectionSort(int*arr, int size);
void insertionSortUsingBinarySearch(int *mas, int size);
int isSubstring(int *mas1, int *mas2, int size1, int size2);
bool isSubset(int *mas1, int *mas2, int size1, int size2);
bool isItSimple(int n);
int deletingSimpleNumerals(int *mas, int size);