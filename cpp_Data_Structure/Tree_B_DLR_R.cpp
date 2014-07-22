#include "iostream.h"
#include "stdlib.h"

typedef struct tnode
{
	char data;
	tnode *lchild, *rchild;
} tnode;

void create(tnode *&t)
{
	char ch;
	cin >> ch;
	if (ch == '.')
	{
		t = NULL;
	}
	else
	{
		t = new tnode;
		t->data = ch;
		create(t->lchild);
		create(t->rchild);
	}
}

void preorder(tnode *t)
{
	if (t)
	{
		cout << t->data;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void main(void)
{
	tnode *t;
	create(t);
	preorder(t);
	cout << endl;
	system("pause");
}