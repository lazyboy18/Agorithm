#include<iostream>
using namespace std;
#include<string>
/*
@ brief �����������У���a=-1ʱ���ջ�����ջ
*/
#define MAXISIZE 8
typedef struct Istack
{
	int*base;
	int top;
	int max;
}Istack;
//��ʼ��
void Istack_Init(Istack&I)
{
	I.max = MAXISIZE;
	I.top = 0;
	I.base = new int[I.top];
}
//�ж��Ƿ�Ϊ��
bool Istack_Isempty(Istack&I)
{
	if (I.top == 0)
	{
		cout << "ջΪ��" << endl;
		return true;
	}
	else
		return false;
}
//�ж��Ƿ���
bool Istack_Isfull(Istack&I)
{
	if (I.top == I.max)
	{
		cout << "ջ������" << endl;
		return true;
	}	
	else
		return false;
}
//��ջ
void Istack_Push(Istack&I, const int a)
{
	if (Istack_Isfull(I))
	{
		return;
	}
	I.base[I.top] = a;
	I.top++;
}
//��ջ
int Istack_Pop(Istack&I)
{
	if (Istack_Isempty(I))
		return -1;
	else
		I.top--;
		int a = I.base[I.top];
		return a;
}
//�����㷨
void test03()
{
	Istack a;
	Istack_Init(a);
	int b;
	do
	{
		cin >> b;
		//���b��Ϊ-1������ջ
		if (b != -1)
		{
			Istack_Push(a, b);
		}
		else
		{
			cout << "��ջ�����ջ��:>" << Istack_Pop(a) << endl;
		}
	} while (!Istack_Isfull(a));
}
//int main()
//{
//	test03();
//	return 0;
//}
