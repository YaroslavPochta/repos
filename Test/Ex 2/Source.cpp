#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main()
{
	int intmin = -INT_MAX;
	int n, m;
	cout << " n and m" << endl;
	cin >> n >> m;
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)   arr[i][j] = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the row #" << i << endl;
		for (int j = 0; j < m; j++)
		{
			cout << "A[" << i << "]["<< j<<"] = ";
			cin >> arr[i][i];
		}
	}
	int *count = new int[n];
	for (int i = 0; i < n; i++) { count[i] = 0; }
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			count[i] += arr[i][j];
			cout << "count[" << i << "] = " << count[i] << "step " << i << j << endl;
		}
	}
	
	for (int i = 0; i < n; i++)
		cout << count[i] << /*"\t"*/ endl;







	for (int i = 0; i < n; i++)
		delete[] arr[i];
	
	system("pause");
	return 0;
}