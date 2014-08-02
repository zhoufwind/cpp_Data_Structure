#include "iostream.h"
#include "stdlib.h"

#define max 20

using namespace std;

typedef struct Lnode
{
	char data;
	Lnode *lchild, *rchild;
} Lnode, *tnode;

typedef struct
{
	tnode *base;
	tnode *top;
	int stacksize;
} stack;

void initstack(stack &s)
{
	s.top = s.base = new tnode[max];
	s.stacksize = max;
}

int emptystack(stack s)
{
	if (s.top == s.base)
	{
		return 1;	// empty stack, return 1
	}
	else
	{
		return 0;
	}
}

void push(stack &s, tnode e)
{
	if (s.top - s.base == s.stacksize)
	{
		return;
	}
	*s.top = e;
	s.top++;
}

void pop(stack &s, tnode &e)
{
	if (s.top == s.base)
	{
		return;
	}
	e = *--s.top;
}

void create(Lnode *&t)
{
	char ch;
	cin >> ch;
	if (ch == '.')
	{
		t = NULL;
	}
	else
	{
		t = new Lnode;
		t->data = ch;
		create(t->lchild);
		create(t->rchild);
	}
}

void preorder(Lnode *t)
{
	Lnode *p = t;
	stack s;
	initstack(s);
	while (p || !emptystack(s))
	{
		if (p)
		{
			cout << p->data;
			push(s, p);
			p = p->lchild;
		}
		else
		{
			pop(s, p);
			p = p->rchild;
		}
	}
}

void main()
{
	Lnode *t;
	create(t);
	cout << "Preorder: ";
	preorder(t);
	cout << endl;
	system("pause");
}