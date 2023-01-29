#include<iostream>
using namespace std;
#include<string>
/*
	@ brief �жϻ����ַ���
*/

typedef struct Cstack
{
	char ch;
	struct Cstack*next;
}Cstack;
//��ʼ��
Cstack* Cstack_Init()
{
	return NULL;
}
//�ж��Ƿ�Ϊ��
bool Cstack_Isempty(Cstack*&S)
{
	if (S == NULL)
		return true;
	else
		return false;
}
//��ջ  �����ж�ջ��
void Cstack_Push(Cstack*&S, const char ch)
{
	Cstack* p = new Cstack;
	p->ch = ch;
	p->next = S;
	S = p;
}
//��ջ//����ջ��Ԫ��,��Ҫ�ж��Ƿ�Ϊ��
void Cstack_Pop(Cstack*&S)
{
	if (Cstack_Isempty(S))
		return ;
	Cstack* p = S;
	S = S->next;
	delete p;
	return ;
}
//ȡջ��Ԫ��
char Cstack_Gethead(Cstack*&S)
{
	if (Cstack_Isempty(S))
		return '@';
	return S->ch;
}
//�㷨����,����ǰ�벿����ջ�����ú�벿�ֳ�ջ
bool Ispalindromesstr(Cstack*&S)
{
	string str;
	cout << "�������ַ���:>";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		//ǰһ����ջ��һ���ջ
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

