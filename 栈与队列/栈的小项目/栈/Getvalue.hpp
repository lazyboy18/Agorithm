#ifndef _GETVALUE_H_
#define _GETVALUE_H_
#include<iostream>
#include<string>
using namespace std;
typedef struct Sint
{
	int*base;
	int top;
	int max;
}Sint;
typedef struct Schar
{
	char*base;
	int top;
	int max;
}Schar;
void initInt(Sint* s)
{
	s->max = 100;
	s->top = 0;
	s->base = new int[s->max];
	//cout << "int初始化成功" << endl;
}
void initChar(Schar* s)
{
	s->max = 100;
	s->top = 0;
	s->base = new char[s->max];
	//cout << "char初始化成功" << endl;
}
bool is_Sintempty(Sint* s)
{
	if (s->top == 0)
		return true;
	else
		return false;
}
bool is_Scharempty(Schar* s)
{
	if (s->top == 0)
		return true;
	else
		return false;
}
bool is_Sintfull(Sint*s)
{
	if (s->top == s->max)
	{
		return true;
	}
	else
		return false;
}
bool is_Scharfull(Schar*s)
{
	if (s->top == s->max)
	{
		return true;
	}
	else
		return false;
}
int Sint_gethead(Sint* s)
{
	if (is_Sintempty(s))
	{
		return -1;
	}
	else
		return s->base[s->top-1];
}
char Schar_gethead(Schar* s)
{
	if (is_Scharempty(s))
	{
		return '@';
	}
	else
		return s->base[s->top-1];
}
//入栈与出栈
void Sint_Push(Sint*s, int x)
{
	if (is_Sintfull(s))
	{
		return;
	}
	else
		s->base[s->top] = x;
		s->top++;
}
void Schar_Push(Schar*s, char x)
{
	if (is_Scharfull(s))
	{
		return;
	}
	else
		s->base[s->top] = x;
		s->top++;
}
void Sint_Pop(Sint*s)
{
	if (is_Sintempty(s))
	{
		return;
	}
	else
		s->top--;
}
void Schar_Pop(Schar*s)
{
	if (is_Scharempty(s))
	{
		return;
	}
	else
		s->top--;
}
char Compare(char ch1, char ch2)
{
	if (ch1 == '(')
	{
		//优先级最大
		return '>';
	}
	else if (ch1 == ')')
	{
		if (ch2 == '(')
			return '=';
		else
			return '<';
	}
	else if (ch1 == '+' || ch1 == '-')
	{
		if (ch2 == '('||ch2=='#')
			return '>';
		else
			return '<';
	}
	else if (ch1 == '*' || ch1 == '/' || ch1 == '%')
	{
		if (ch2 == '*' || ch2 == '/' || ch2 == '%')
		{
			return '<';
		}
		else
			return '>';
	}
	else if (ch1 == '#')
		return '<';
}

int operat(int a, char b, int c)
{
	if (b == '+')
		return a + c;
	else if (b == '-')
		return a - c;
	else if (b == '*')
		return a*c;
	else if (b == '/')
		return a / c;
	else if (b == '%')
		return a%c;
}



int Evaluate()
{
	Sint Opnum;
	Schar Opchar;
	initInt(&Opnum);
	initChar(&Opchar);
	char ch;
	cin >> ch;
	Schar_Push(&Opchar, ch);
	string op;
	cin >> op;
	int i = 0;
	int num = 0;
	while (op[i]!='#'||Schar_gethead(&Opchar) != '#')
	{
		ch = op[i];
		//先输入整数
		if (ch >= '0'&&ch <= '9')
		{
			int s = ch - '0';
			num *= 10;
			num += s;
			if (op[i + 1] > '9' || op[i + 1] < '0')
			{
				Sint_Push(&Opnum, num);
				num = 0;
			}
			i++;
		}
		else
		{
			switch (Compare(ch, Schar_gethead(&Opchar)))
			{
			case '<':
			{
				int c = Sint_gethead(&Opnum);
				Sint_Pop(&Opnum);
				int a = Sint_gethead(&Opnum);
				Sint_Pop(&Opnum);
				char b = Schar_gethead(&Opchar);
				Schar_Pop(&Opchar);
				int ret = operat(a, b, c);
				Sint_Push(&Opnum, ret);
				break;
			}
			case '>':
			{
				Schar_Push(&Opchar, ch);
				i++;
				break;

			}
			case '=':
			{
				Schar_Pop(&Opchar);
				if (ch != '#')
					i++;
				break;
			}

			}
		}
	}
	return Sint_gethead(&Opnum);
}


#endif