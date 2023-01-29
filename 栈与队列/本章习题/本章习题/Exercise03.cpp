#include<iostream>
using namespace std;
#include<string>
/*
@ brief 输入整型序列，当a=-1时输出栈顶与出栈
*/
#define MAXISIZE 8
typedef struct Istack
{
	int*base;
	int top;
	int max;
}Istack;
//初始化
void Istack_Init(Istack&I)
{
	I.max = MAXISIZE;
	I.top = 0;
	I.base = new int[I.top];
}
//判断是否为空
bool Istack_Isempty(Istack&I)
{
	if (I.top == 0)
	{
		cout << "栈为空" << endl;
		return true;
	}
	else
		return false;
}
//判断是否满
bool Istack_Isfull(Istack&I)
{
	if (I.top == I.max)
	{
		cout << "栈已满了" << endl;
		return true;
	}	
	else
		return false;
}
//入栈
void Istack_Push(Istack&I, const int a)
{
	if (Istack_Isfull(I))
	{
		return;
	}
	I.base[I.top] = a;
	I.top++;
}
//出栈
int Istack_Pop(Istack&I)
{
	if (Istack_Isempty(I))
		return -1;
	else
		I.top--;
		int a = I.base[I.top];
		return a;
}
//核心算法
void test03()
{
	Istack a;
	Istack_Init(a);
	int b;
	do
	{
		cin >> b;
		//如果b不为-1，则入栈
		if (b != -1)
		{
			Istack_Push(a, b);
		}
		else
		{
			cout << "出栈并输出栈顶:>" << Istack_Pop(a) << endl;
		}
	} while (!Istack_Isfull(a));
}
//int main()
//{
//	test03();
//	return 0;
//}
