#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#define MAXSIZE01 10
//����һ���沨�����ʽ��ֵ���������ֵ���ʽ��(����Ϊ��ĿҪ���)
/*
	Q:�ַ�������Ҫ��ȡ�ո񣬾���Ҫ�õ�char str[20]={0};
	gets(str);
*/


int Calculate01(int a, char b, int c)
{
	if (b == '+')
		return a + c;
	else if (b == '-')
		return a - c;
	else if (b == '*')
		return a*c;
	else
		return a / c;
}
//ֻ��Ҫһ���洢���͵�ջ
typedef struct Istack01
{
	int*base;
	int top;
	int max;
}Istack01;
//��ʼ��
void Istack01_Init(Istack01& I)
{
	I.max = MAXSIZE01;
	I.top = 0;
	I.base = new int[I.top];
	cout << "Istack01��ʼ���ɹ�" << endl;
}
//�ж��Ƿ�Ϊ��
bool Istack01_Isempty(Istack01& I)
{
	if (I.top == 0)
		return true;
	else
		return false;
}
//�ж��Ƿ�Ϊ��
bool Istack01_Isfull(Istack01& I)
{
	if (I.top == I.max)
		return true;
	else
		return false;
}
//��ջ
void Istack01_Push(Istack01& I, const int x)
{
	if (Istack01_Isfull(I))
	{
		return;
	}
	I.base[I.top] = x;
	I.top++;
}
//��ջ
int Istack01_Pop(Istack01& I)
{
	if (Istack01_Isempty(I))
		return -1;
	I.top--;
	return I.base[I.top];
}
//�㷨����   �������ʽ
void Cor01()
{
	Istack01 I;
	Istack01_Init(I);
	cout << "������ֻ������+��-��*��/����" << endl;
	cout << "�����沨�����ʽ:>" << endl;
	int num = 0;
	char str[20] = { 0 };
	gets(str);
	int i = -1;
	while (str[++i]!= '$')
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			num *= 10;
			num += str[i] - '0';
			if (str[i+1]<'0' || str[i+1]>'9')
			{
				Istack01_Push(I, num);
				num = 0;
			}
		}
		else if (str[i] == ' ');
		else
		{
			int c = Istack01_Pop(I);
			int a = Istack01_Pop(I);
			Istack01_Push(I, Calculate01(a, str[i], c));
		}
	}
	cout << '=' << Istack01_Pop(I) << endl;
}

void test04()
{
	Cor01();
}

//int main()
//{
//	test04();
//	return 0;
//}


