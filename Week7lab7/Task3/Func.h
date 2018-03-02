#pragma once
#include <string>
#include <vector>
#include <stack>
using namespace std;
bool isFirstHaveHigerPriorityThanSecond(char op1, char op2);
void vectorOutput(vector<int> v);
int operation(char op, int a, int b);
void calculationWithBrakets(vector<int>& vect, stack<char>& operations);
int reversePolishNotation(string str);
bool isUnaryOperation(string str, int i);