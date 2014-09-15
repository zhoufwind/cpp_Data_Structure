#include "iostream.h"
#include "stdlib.h"

using namespace std;

void input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void BubbleSort(int a[], int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] < a[i + 1])
			{
				int t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void main()
{
	int a[10], n = 10;
	input(a, n);
	BubbleSort(a, n);
	output(a, n);
	system("pause");
}