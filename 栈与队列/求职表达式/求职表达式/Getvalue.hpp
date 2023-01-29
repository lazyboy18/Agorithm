#ifndef _GETVALUE_HPP_
#define _GETVALUE_HPP_
#include<iostream>
#include<string>
using namespace std;
//与书本的单一数据结构多用相比，这道题需要额外定义一个结构体，为了简化运算
typedef struct Istack
{
	int*base;
	int top;
	int maxi;
}Istack;
typedef struct Cstack
{
	char*base;
	int top;
	int maxc;
}Cstack;
//这里使用引用的技术
void Icstack_Init(Istack&a)
{
	a.top = 0;
	a.maxi = 100;
	a.base = new int[a.maxi];
//	cout << "Istack初始化成功" << endl;
}
//判断是否为空
bool Icstack_Empty(const Istack&a)
{
	if (a.top == 0)
	{
		cout << "Istack栈为空" << endl;
		return true;
	}
	else
		return false;
}
//判断是否为满
bool Icstack_Full(const Istack&a)
{
	if (a.top == a.maxi)
		return true;
	else
		return false;
}
//得到栈顶元素
int Icstack_Gethead(const Istack&a)
{
	if (Icstack_Empty(a))
		return -1;
	else
		return a.base[a.top - 1];//务必减1
}
//入栈
void Icstack_Push(Istack&a,const int&x)
{
	if (Icstack_Full(a))
		return;
	a.base[a.top] = x;
	a.top++;
}
//出栈
void Icstack_Pop(Istack&a, int&element)
{
	if (Icstack_Empty(a))
		return;
	a.top--;
	element = a.base[a.top];
}
//空战
void Icstack_Void(Istack&a)
{
	a.top = 0;
}
//----------
void Icstack_Init(Cstack&a)
{
	a.top = 0;
	a.maxc = 100;
	a.base = new char[a.maxc];
//	cout << "Cstack初始化成功" << endl;
}
//判断是否为空
bool Icstack_Empty(const Cstack&a)
{
	if (a.top == 0)
	{
		cout << "Cstack栈为空" << endl;
		return true;
	}
	else
		return false;
}
//判断是否为满
bool Icstack_Full(const Cstack&a)
{
	if (a.top == a.maxc)
		return true;
	else
		return false;
}
//得到栈顶元素
char Icstack_Gethead(const Cstack&a)
{
	if (Icstack_Empty(a))
		return -1;
	else
		return a.base[a.top - 1];//务必减1
}
//入栈
void Icstack_Push(Cstack&a, const char&x)
{
	if (Icstack_Full(a))
		return;
	a.base[a.top] = x;
	a.top++;
}
//出栈
void Icstack_Pop(Cstack&a, char&element)
{
	if (Icstack_Empty(a))
		return;
	a.top--;
	element = a.base[a.top];
}
//空战
void Icstack_Void(Cstack&a)
{
	a.top = 0;
}
//求职表达式的核心功能区
//对比运算符号的优先级
char Icompare(const char&ch1, const char&ch2)
{
	if (ch1 == '#')
		return '<';//执行运算
	else if (ch1 == '(')
		return '>';
	else if (ch1 == ')')
	{
		if (ch2 == '(')
			return '=';//抵消
		else
			return '<';//执行运算
	}
	else if (ch1 == '+' || ch1 == '-')
	{
		if (ch2 == '(' || ch2 == '#')
			return '>';
		else
			return '<';
		//无需考虑')'
	}
	else if (ch1 == '*' || ch1 == '/' || ch1 == '%')
	{
		if (ch2 == '(' || ch2 == '#' || ch2 == '+' || ch2 == '-')
			return '>';//
		else
			return '<';
	}
	else//如果输入错误就跳过
		return '@';
}
int Operator(int num1, char opc, int num2)
{
	if (opc == '+')
		return num1 + num2;
	else if (opc == '-')
		return num1 - num2;
	else if (opc == '*')
		return num1*num2;
	else if (opc == '/')
		return num1 / num2;
	else if (opc == '%')
		return num1%num2;
}

int getvalue()
{
	cout << "输入求值表达式:>";
	//a与c都是局部临时变量
	Istack a;
	Cstack c;
	char ch;
	int num = 0;
	Icstack_Init(a);
	Icstack_Init(c);
	cin >> ch;
	Icstack_Push(c, ch);
	cin >> ch;
	while (ch != '#' || Icstack_Gethead(c)!='#')
	{
		//第一步输入值
		if (ch >= '0'&&ch <= '9')
		{
			num *= 10;
			num += ch - '0';
			//继续输入下一位
			cin >> ch;
			if (ch<'0' || ch>'9')
			{
				Icstack_Push(a, num);//入栈
				num = 0;
			}
		}
		else
		{
			switch (Icompare(ch, Icstack_Gethead(c)))
			{
			case '@':
						cin >> ch;
						break;
			case '>':
			{
						//压入
						Icstack_Push(c, ch);
						cin >> ch;
						break;
			}
			case '<':
			{
						//弹出两个操作数和一个运算符
						int num1, num2;
						char opc;
						Icstack_Pop(a, num2);
						Icstack_Pop(a, num1);
						Icstack_Pop(c, opc);
						Icstack_Push(a, Operator(num1, opc, num2));
						break;
			}
			case '=':
			{
						char opc;
						Icstack_Pop(c, opc);
						cin >> ch;
						break;
			}
			}
		}
	}
	int ret = Icstack_Gethead(a);
	return ret;
}
#endif