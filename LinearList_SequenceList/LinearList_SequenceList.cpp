#include "iostream.h"
#include "stdlib.h"
/* ���Ա�Ķ�̬����˳��洢�ṹ */
#define initlistsize 100	// ���Ա�洢�ռ�ĳ�ʼ������
#define increment 10		// ���Ա�洢�ռ�ķ�������

using namespace std;

typedef struct
{
	int *elem;			// �洢�ռ��ַ
	int listsize;		// ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
	int length;			// ��ǰ����
}sqlist;

/* ��ʼ��˳��� */
void initlist(sqlist &l)
{
	l.elem = new int[initlistsize];		// ����洢�ռ�
	l.listsize = initlistsize;			// ����յ�˳���
	l.length = 0;						// ��ʼ����Ϊ��
}

/* ����˳����ȼ����ڵ��ֵ */
void initlistn(sqlist &l, int n)
{
	initlist(l);					// ��ʼ��˳���
	for (int i = 0; i < n; i++)		// ���ݽڵ����ѭ������ڵ�ֵ
	{
		cin >> l.elem[i];
	}
	l.length = n;					// ���ýڵ㳤��
}

/* ���˳��� */
void print(sqlist l)
{
	for (int i = 0; i < l.length; i++)		// ���ݽڵ㳤��ѭ������ڵ�ֵ
	{
		cout << l.elem[i] << " ";
	}
	cout << endl;
}

/* ����ڵ� */
int insertlist(sqlist &l, int i, int e)
{
	if (i < 1 || i > l.length)
	{
		return 0;
	}
	if (l.length >= l.listsize)		// ���ڵ㳤�ȴ��ڻ����˳����С�����������С
	{
		int *elem1 = new int[l.listsize + increment];	// ��ʱ�����±�
		for (int i = 0; i < l.length; i++)		// ���ɱ�ڵ��ֵ���θ�ֵ���±�
		{
			elem1[i] = l.elem[i];
		}
		delete[]l.elem;				// ɾ���ɱ�
		l.elem = elem1;				// �±�ֵ��˳���
		l.listsize += increment;	// ����˳����С
	}
	int *p = &l.elem[l.length - 1];		// ��βָ��
	int *q = &l.elem[i - 1];			// ����ָ��λ��
	for (; p >= q; p--)					// ѭ�����һλ���Ƹ��ڵ��ֵ��ֱ����βָ��λ��С�ڲ���ָ��λ��
	{
		*(p + 1) = *p;
	}
	l.elem[i - 1] = e;		// �Բ���ָ��λ�ø�ֵ
	l.length++;				// �ڵ㳤���Լ�
	return 1;
}

/* ɾ���ڵ� */
int deletelist(sqlist &l, int i, int &e)
{
	if (i < 1 || i > l.length)	// ɾ��λ�ò�����
	{
		return 0;
	}
	int *p = &l.elem[l.length - 1];
	int *q = &l.elem[i - 1];
	e = *q;		// �ȱ���
	for (; q < p; q++)
	{
		*q = *(q + 1);	// �ƶ�����Ԫ��
	}
	l.length--;
	return 1;
}

void turn(sqlist &l)
{
	int *p = &l.elem[0];
	int *q = &l.elem[l.length - 1];
	int *temp = new int;
	for (; p < q; p++, q--)
	{
		*temp = *p;
		*p = *q;
		*q = *temp;
	}
}

void main(void)
{
	sqlist l;
	initlistn(l, 10);
	print(l);
	insertlist(l, 4, 200);
	print(l);
	int e;
	deletelist(l, 4, e);
	print(l);
	turn(l);
	print(l);
	system("pause");
}