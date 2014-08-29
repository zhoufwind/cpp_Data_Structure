#include "iostream.h"
#include "stdlib.h"

using namespace std;

typedef struct Lnode
{
	int data;
	Lnode *next;
}Lnode;

void create(Lnode *&l)
{
	l = new Lnode;
	l->next = NULL;
}

void createn(Lnode *&l, int n)
{
	create(l);
	Lnode *s;
	for (int i = 0; i < n; i++)
	{
		s = new Lnode;
		cin >> s->data;
		s->next = l->next;
		l->next = s;
	}
}

void print(Lnode *l)
{
	Lnode *p = l->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void main()
{
	Lnode *l;
	createn(l, 5);
	print(l);
	system("pause");
}