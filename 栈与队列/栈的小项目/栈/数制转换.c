#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ջ����ջ���Լ���С
#define MAXSIZE 100

/*
	����ջ�����ݽṹʵ������ת��
*/

typedef struct stack
{
	int* base;
	int* top;
	int stacksize;
}stack;
stack s;

//��ʼ������
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
	printf("ջ��ʼ���ɹ�\n");
}
//��ջ����
//���ж��Ƿ�����;����������ʵ�����Ƶ�ת����������ջ�в���
void stack_Push(int x,stack*s)
{
	if ((s->top) - (s->base) == s->stacksize)
	{
		printf("ջ�ռ�����\n");
		return;
	}
	*(s->top) = x;
	s->top = s->top + 1;
	printf("��ջ�ɹ�\n");
}
//��ջ���Żض�Ӧ��Ԫ�ز���ɾ��ջ��
int stack_Pop(stack*s)
{
	if (s->base == s->top)
	{
		printf("��ջ\n");
		return;
	}
	else
		s->top = s->top - 1;
	//printf("��ջ�ɹ�\n");
	return *(s->top);
}
//дһ��������ʵ������ת��
void NumTrasfer(int num, stack*s, int x)
{
	if (num == 0)
	{
		printf("10�������ɹ�ת��Ϊ%d������\n",x);
		return;
	}	
	stack_Push(num%x,s);
	NumTrasfer(num / x, s, x);
}
//дһ������������ʮ���������Լ�ת���Ľ��ƣ�������
void NumTrasform()
{
	printf("����ʮ������������ת��ΪX������(X<=10&&X>=2)\n");
	printf("����ʮ������:>");
	int num;
	scanf("%d", &num);
	printf("����X:>");
	int x;
	scanf("%d", &x);
	if (x<2 || x>10)
	{
		printf("X�������\n");
		return;
	}
	stack_Init(&s);
	NumTrasfer(num, &s, x);
	printf("%d������������������:>",x);
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
