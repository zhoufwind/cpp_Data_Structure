#include "iostream.h"
#include "stdlib.h"

#define initstacksize 15
#define increment 10

using namespace std;

/* define the data struct */
typedef struct{
	int *base;
	int *top;
	int stacksize;
} stack;

/* initialize the stack */
void initstack(stack &s){
	s.base = s.top = new int[initstacksize];
	s.stacksize = initstacksize;
}

/* create initial stack */
void initstackn(stack &s, int n){
	initstack(s);
	for (int i = 0; i < n; i++){
		cin >> *s.top++;
	}
}

void push(stack &s, int e){
	if (s.top - s.base >= s.stacksize){
		int *base1 = new int[initstacksize + increment];
		for (int i = 0; i < s.stacksize; i++){
			base1[i] = s.base[i];
			delete []s.base;
			s.base = base1;
			s.top = s.base + s.stacksize;
			s.stacksize += increment;
		}
	}
	*s.top = e;
	s.top++;
}

int pop(stack &s, int &e){
	if (s.top == s.base){
		return 0;
	}
	e = *--s.top;
	return 1;
}

int emptystack(stack s){
	if (s.top == s.base){
		return 1;
	}
	else {
		return 0;
	}
}

int gettop(stack &s, int &e){
	if (s.top == s.base){
		return 0;
	}
	e = *(s.top - 1);
	return 1;
}

void print(stack s){
	int *p = s.base;
	while (p != s.top){
		cout << *p << " ";
		p++;
	}
	cout << endl;
}

void main(void){
	stack s;
	initstackn(s, 14);
	print(s);
	push(s, 100);
	print(s);
	int e;
	pop(s, e);
	print(s);
	system("pause");
}