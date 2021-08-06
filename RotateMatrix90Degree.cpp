#include <iostream>
using namespace std;
#define N 4

void RotateMatrix90Degree(int (*m)[N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = i; j < N - 1 - i; j++)
		{
			int temp = m[i][j];
			m[i][j] = m[N - 1 - j][i];
			m[N - 1 - j][i] = m[N - 1 - i][N - 1 - j];
			m[N - 1 - i][N - 1 - j] = m[j][N - 1 - i];
			m[j][N - 1 - i] = temp;
		}
	}
	
}

void print(int (*m)[N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << m[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int m[N][N];
	cout << "Enter value of matrix" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> m[i][j];
		}
	}
	cout << endl;
	RotateMatrix90Degree(m);
	print(m);
	return 0;
}


