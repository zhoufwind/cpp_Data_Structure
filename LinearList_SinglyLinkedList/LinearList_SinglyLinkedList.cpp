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

int insertlist(Lnode *&l, int i, int e)
{
	Lnode *p = l;
	int j = 0;
	while (p && j < i - 1)	// locate insert position
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)	// node isn't exist
	{
		return 0;
	}
	Lnode *s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}

int deletelist(Lnode *&l, int i, int &e)
{
	Lnode *p = l;
	int j = 0;
	while (p->next && j < i - 1)	// locate delete position
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)	// node isn't exist
	{
		return 0;
	}
	Lnode *q = p->next;
	e = q->data;
	p->next = q->next;
	delete q;
	return 1;
}

int searchX(Lnode *l, int x)
{
	Lnode *p = l->next;
	while (p)
	{
		if (p->data == x)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

int count(Lnode *l)
{
	Lnode *p = l->next;
	int s = 0;
	while (p)
	{
		if (p->data % 2 == 0)
		{
			s++;
		}
		p = p->next;
	}
	return s;
}

void main()
{
	Lnode *l;
	createn(l, 5);
	print(l);
	insertlist(l, 4, 200);
	print(l);
	int e;
	deletelist(l, 4, e);
	print(l);
	cout << searchX(l, 5) << endl;
	cout << count(l) << endl;
	system("pause");
}