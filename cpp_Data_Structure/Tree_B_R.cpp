#include "iostream.h"
#include "stdlib.h"

using namespace std;

typedef struct tnode	// Define Binary Tree data struct
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

void preorder(tnode *t)		// DLR
{
	if (t)
	{
		cout << t->data;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(tnode *t)		// LDR
{
	if (t)
	{
		inorder(t->lchild);
		cout << t->data;
		inorder(t->rchild);
	}
}

void postorder(tnode *t)	// LRD
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout << t->data;
	}
}

void main(void)
{
	tnode *t;
	create(t);
	cout << "Preorder: ";
	preorder(t);
	cout << endl;
	cout << "Inorder: ";
	inorder(t);
	cout << endl;
	cout << "Postorder: ";
	postorder(t);
	cout << endl;
	system("pause");
}