#ifndef _GETVALUE_HPP_
#define _GETVALUE_HPP_
#include<iostream>
#include<string>
using namespace std;
//���鱾�ĵ�һ���ݽṹ������ȣ��������Ҫ���ⶨ��һ���ṹ�壬Ϊ�˼�����
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
//����ʹ�����õļ���
void Icstack_Init(Istack&a)
{
	a.top = 0;
	a.maxi = 100;
	a.base = new int[a.maxi];
//	cout << "Istack��ʼ���ɹ�" << endl;
}
//�ж��Ƿ�Ϊ��
bool Icstack_Empty(const Istack&a)
{
	if (a.top == 0)
	{
		cout << "IstackջΪ��" << endl;
		return true;
	}
	else
		return false;
}
//�ж��Ƿ�Ϊ��
bool Icstack_Full(const Istack&a)
{
	if (a.top == a.maxi)
		return true;
	else
		return false;
}
//�õ�ջ��Ԫ��
int Icstack_Gethead(const Istack&a)
{
	if (Icstack_Empty(a))
		return -1;
	else
		return a.base[a.top - 1];//��ؼ�1
}
//��ջ
void Icstack_Push(Istack&a,const int&x)
{
	if (Icstack_Full(a))
		return;
	a.base[a.top] = x;
	a.top++;
}
//��ջ
void Icstack_Pop(Istack&a, int&element)
{
	if (Icstack_Empty(a))
		return;
	a.top--;
	element = a.base[a.top];
}
//��ս
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
//	cout << "Cstack��ʼ���ɹ�" << endl;
}
//�ж��Ƿ�Ϊ��
bool Icstack_Empty(const Cstack&a)
{
	if (a.top == 0)
	{
		cout << "CstackջΪ��" << endl;
		return true;
	}
	else
		return false;
}
//�ж��Ƿ�Ϊ��
bool Icstack_Full(const Cstack&a)
{
	if (a.top == a.maxc)
		return true;
	else
		return false;
}
//�õ�ջ��Ԫ��
char Icstack_Gethead(const Cstack&a)
{
	if (Icstack_Empty(a))
		return -1;
	else
		return a.base[a.top - 1];//��ؼ�1
}
//��ջ
void Icstack_Push(Cstack&a, const char&x)
{
	if (Icstack_Full(a))
		return;
	a.base[a.top] = x;
	a.top++;
}
//��ջ
void Icstack_Pop(Cstack&a, char&element)
{
	if (Icstack_Empty(a))
		return;
	a.top--;
	element = a.base[a.top];
}
//��ս
void Icstack_Void(Cstack&a)
{
	a.top = 0;
}
//��ְ���ʽ�ĺ��Ĺ�����
//�Ա�������ŵ����ȼ�
char Icompare(const char&ch1, const char&ch2)
{
	if (ch1 == '#')
		return '<';//ִ������
	else if (ch1 == '(')
		return '>';
	else if (ch1 == ')')
	{
		if (ch2 == '(')
			return '=';//����
		else
			return '<';//ִ������
	}
	else if (ch1 == '+' || ch1 == '-')
	{
		if (ch2 == '(' || ch2 == '#')
			return '>';
		else
			return '<';
		//���迼��')'
	}
	else if (ch1 == '*' || ch1 == '/' || ch1 == '%')
	{
		if (ch2 == '(' || ch2 == '#' || ch2 == '+' || ch2 == '-')
			return '>';//
		else
			return '<';
	}
	else//���������������
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
	cout << "������ֵ���ʽ:>";
	//a��c���Ǿֲ���ʱ����
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
		//��һ������ֵ
		if (ch >= '0'&&ch <= '9')
		{
			num *= 10;
			num += ch - '0';
			//����������һλ
			cin >> ch;
			if (ch<'0' || ch>'9')
			{
				Icstack_Push(a, num);//��ջ
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
						//ѹ��
						Icstack_Push(c, ch);
						cin >> ch;
						break;
			}
			case '<':
			{
						//����������������һ�������
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