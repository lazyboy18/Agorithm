#include<iostream>
using namespace std;
#include<string>
/*
	@ brief 判断回文字符串
*/

typedef struct Cstack
{
	char ch;
	struct Cstack*next;
}Cstack;
//初始化
Cstack* Cstack_Init()
{
	return NULL;
}
//判断是否为空
bool Cstack_Isempty(Cstack*&S)
{
	if (S == NULL)
		return true;
	else
		return false;
}
//入栈  无需判断栈满
void Cstack_Push(Cstack*&S, const char ch)
{
	Cstack* p = new Cstack;
	p->ch = ch;
	p->next = S;
	S = p;
}
//出栈//弹出栈顶元素,需要判断是否为空
void Cstack_Pop(Cstack*&S)
{
	if (Cstack_Isempty(S))
		return ;
	Cstack* p = S;
	S = S->next;
	delete p;
	return ;
}
//取栈顶元素
char Cstack_Gethead(Cstack*&S)
{
	if (Cstack_Isempty(S))
		return '@';
	return S->ch;
}
//算法核心,先让前半部分入栈，再让后半部分出栈
bool Ispalindromesstr(Cstack*&S)
{
	string str;
	cout << "请输入字符串:>";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		//前一半入栈后一半出栈
		if (i < str.length() / 2)
		{
			Cstack_Push(S, str[i]);
		}
		else
		{
			if (str[i] == Cstack_Gethead(S))
			{
				Cstack_Pop(S);
			}
		}
	}
	if (Cstack_Isempty(S))
		return true;
	else
		return false;
}
void test01()
{
	Cstack*S = Cstack_Init();
	if (Ispalindromesstr(S))
		cout << "This is a palindromes string!" << endl;
	else
		cout << "This is not a palindromes string!" << endl;
}
//int main()
//{
//	test01();
//	return 0;
//}

