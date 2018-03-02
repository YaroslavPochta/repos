#pragma once
#include<iostream> 
#include <time.h>
#define USE_MATH_DEFINES
using namespace std;
void initRandom(int mas[], int size, int a, int b);
void output(int *mas, int size, char title[]);
int indexOfMinElementInArray(int *arr, int first, int last);
int minInTheArray(int mas[], int first, int last);
void InputingArray(int mas[], int size);
int searchingValueInArray(int mas[], int size, int value);
int* selectionSort(int*arr, int size, int& newArraySize);
void selectionSortV(int*arr, int size);
bool isItSimple(int n);
int deletingSimpleNumerals(int *mas, int size);
int* simpleNumeralsArray(int *mas, int size, int&);
int* medianOfArray(int *arr, int size, int &);