#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//栈顶、栈底以及大小
#define MAXSIZE 100

/*
	利用栈的数据结构实现数制转化
*/

typedef struct stack
{
	int* base;
	int* top;
	int stacksize;
}stack;
stack s;

//初始化队列
void stack_Init(stack*s)
{
	s->base = (int*)malloc(sizeof(int)*MAXSIZE);
	if (!s->base)
	{
		printf("overflow\n");
		return;
	}
	s->top = s->base;
	s->stacksize = MAXSIZE;
	printf("栈初始化成功\n");
}
//入栈函数
//先判断是否已满;由于我们是实现数制的转换，所以入栈有参数
void stack_Push(int x,stack*s)
{
	if ((s->top) - (s->base) == s->stacksize)
	{
		printf("栈空间已满\n");
		return;
	}
	*(s->top) = x;
	s->top = s->top + 1;
	printf("入栈成功\n");
}
//出栈，放回对应的元素并且删除栈顶
int stack_Pop(stack*s)
{
	if (s->base == s->top)
	{
		printf("空栈\n");
		return;
	}
	else
		s->top = s->top - 1;
	//printf("出栈成功\n");
	return *(s->top);
}
//写一个函数，实现数制转化
void NumTrasfer(int num, stack*s, int x)
{
	if (num == 0)
	{
		printf("10进制数成功转化为%d进制数\n",x);
		return;
	}	
	stack_Push(num%x,s);
	NumTrasfer(num / x, s, x);
}
//写一个函数，输入十进制数，以及转化的进制，输出结果
void NumTrasform()
{
	printf("输入十进制数，将其转化为X进制数(X<=10&&X>=2)\n");
	printf("输入十进制数:>");
	int num;
	scanf("%d", &num);
	printf("输入X:>");
	int x;
	scanf("%d", &x);
	if (x<2 || x>10)
	{
		printf("X输入错误\n");
		return;
	}
	stack_Init(&s);
	NumTrasfer(num, &s, x);
	printf("%d进制数的输出结果如下:>",x);
	while (s.top != s.base)
	{
		printf("%d", stack_Pop(&s));
	}
	printf("\n---------------------------\n");
}

//int main()
//{
//	while (1)
//	{
//		NumTrasform();
//	}
//	system("pause");
//	return 0;
//}
