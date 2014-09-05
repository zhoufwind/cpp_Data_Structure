#include "iostream.h"
#include "stdlib.h"

using namespace std;

/* Lnode data struct */
typedef struct Lnode
{
	int data;		// store node info
	Lnode *next;	// sotre next node location
}Lnode;

/* Create new empty Lnode */
void create(Lnode *&l)
{
	l = new Lnode;
	l->next = NULL;
}

/* Create Lnode by imput info */
void createn(Lnode *&l, int n)
{
	create(l);
	Lnode *s;
	for (int i = 0; i < n; i++)	// FIFO, first input will store at List's tail
	{
		s = new Lnode;
		cin >> s->data;
		s->next = l->next;
		l->next = s;
	}
}

/* Print the link */
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

/* Insert node into the link */
int insertlist(Lnode *&l, int i, int e)
{
	Lnode *p = l;
	int j = 0;
	while (p && j < i - 1)	// locate insert position, store into p
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

/* delete node from the link */
int deletelist(Lnode *&l, int i, int &e)
{
	Lnode *p = l;
	int j = 0;
	while (p->next && j < i - 1)	// locate delete position, store into p
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

/* searching for keyword: "x", if exist, returning 1, otherwise 0 */
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

/* calc even counts */
int count(Lnode *l)
{
	Lnode *p = l->next;
	int s = 0;	// setting counter
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