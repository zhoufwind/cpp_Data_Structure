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

void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)		// last element don't need compare
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
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
	SelectionSort(a, n);
	output(a, n);
	system("pause");
}