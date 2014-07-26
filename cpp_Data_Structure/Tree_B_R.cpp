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

int countleaf(tnode *t)
{
	if (t)
	{
		int m = countleaf(t->lchild);
		int n = countleaf(t->rchild);
		if (m + n == 0)
			return 1;
		else
			return 0;
	}
	return 0;
}

int height(tnode *t)	// Calc tree's height
{
	if (t)
	{
		int m = 1 + height(t->lchild);	// if left side have child, +1
		int n = 1 + height(t->rchild);	// if right side have child, +1
		if (m >= n)
			return m;	// if left greater than right, return left
		else
			return n;
	}
	return 0;	// if t = null, return 0, it's the begining
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
	cout << "Count Leaf: ";
	cout << countleaf(t);
	cout << endl;
	cout << "Tree height: ";
	cout << height(t);
	cout << endl;
	system("pause");
}