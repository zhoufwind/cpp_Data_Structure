#include "iostream.h"
#include "stdlib.h"
/* 线性表的动态分配顺序存储结构 */
#define initlistsize 100	// 线性表存储空间的初始分配量
#define increment 10		// 线性表存储空间的分配增量

using namespace std;

typedef struct
{
	int *elem;			// 存储空间基址
	int listsize;		// 当前分配的存储容量(以sizeof(ElemType)为单位)
	int length;			// 当前长度
}sqlist;

/* 初始化顺序表 */
void initlist(sqlist &l)
{
	l.elem = new int[initlistsize];		// 分配存储空间
	l.listsize = initlistsize;			// 构造空的顺序表
	l.length = 0;						// 初始长度为零
}

/* 设置顺序表长度及各节点的值 */
void initlistn(sqlist &l, int n)
{
	initlist(l);					// 初始化顺序表
	for (int i = 0; i < n; i++)		// 根据节点个数循环输入节点值
	{
		cin >> l.elem[i];
	}
	l.length = n;					// 设置节点长度
}

/* 输出顺序表 */
void print(sqlist l)
{
	for (int i = 0; i < l.length; i++)		// 根据节点长度循环输出节点值
	{
		cout << l.elem[i] << " ";
	}
	cout << endl;
}

/* 插入节点 */
int insertlist(sqlist &l, int i, int e)
{
	if (i < 1 || i > l.length)
	{
		return 0;
	}
	if (l.length >= l.listsize)		// 若节点长度大于或等于顺序表大小，则自增其大小
	{
		int *elem1 = new int[l.listsize + increment];	// 临时创建新表
		for (int i = 0; i < l.length; i++)		// 将旧表节点的值依次赋值到新表
		{
			elem1[i] = l.elem[i];
		}
		delete[]l.elem;				// 删除旧表
		l.elem = elem1;				// 新表赋值到顺序表
		l.listsize += increment;	// 更新顺序表大小
	}
	int *p = &l.elem[l.length - 1];		// 队尾指针
	int *q = &l.elem[i - 1];			// 插入指针位置
	for (; p >= q; p--)					// 循环向后一位复制各节点的值，直至队尾指针位置小于插入指针位置
	{
		*(p + 1) = *p;
	}
	l.elem[i - 1] = e;		// 对插入指针位置赋值
	l.length++;				// 节点长度自加
	return 1;
}

/* 删除节点 */
int deletelist(sqlist &l, int i, int &e)
{
	if (i < 1 || i > l.length)	// 删除位置不合理
	{
		return 0;
	}
	int *p = &l.elem[l.length - 1];
	int *q = &l.elem[i - 1];
	e = *q;		// 先保存
	for (; q < p; q++)
	{
		*q = *(q + 1);	// 移动数据元素
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