#include "iostream.h"
#include "stdlib.h"

using namespace std;

#define vexnum 4
#define maxint (1<<sizeof(int)*8-1)-1

void CreateGraph(int adj[vexnum][vexnum], int e)
{
	int i, j, u, v, w;
	for (i = 0; i < vexnum; i++)
	{
		for (j = 0; j < vexnum; j++)
		{
			adj[i - 1][j - 1] = maxint;
		}
	}
	for (int k = 0; k < e; k++)
	{
		cin >> u >> v >> w;
		adj[i - 1][j - 1] = w;
	}
}

int degree(int b[4][4], int x)
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum += b[i - 1][0];
	}
	return sum;
}

void main(void)
{
	int a[4][4];
	CreateGraph(a, 4);
	cout << degree(a, 3);
	system("pause");
}