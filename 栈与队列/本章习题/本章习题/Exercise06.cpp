#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#define MAXSIZE01 10
//实现一个循环队列，管理队尾指针
/*
	循环链队的入队与出队的注意事项,指针做实参，函数形参为引用或二级指针
	删除最后一个结点的注意事项
*/
typedef struct Cque01
{
	int a;
	struct Cque01*next;
}Cque01;
//初始化
Cque01*Cque01_Init()
{
	Cque01*P = new Cque01;	
	P->next = P;//P指向自己
	cout << "初始化成功" << endl;
	return P;
}
//判断是否为空队列
bool Cque01_Isempty(Cque01*&tail)
{
	if (tail->next == tail)
	{
		cout << "循环队列为空" << endl;
		return true;
	}
	else
		return false;
}
//入队
void Cque01_Push(Cque01*&tail)
{
	cout << "输入数据:>" << endl;
	Cque01*P = new Cque01;
	cin >> P->a;
	P->next = tail->next;
	tail->next = P;
	tail = P;
}
//出队
void Cque01_Pop(Cque01*&tail)
{
	if (Cque01_Isempty(tail))
	{
		return;
	}
	Cque01*t = tail->next->next;//被删除的结点
	if (t == tail)
	{
		tail = tail->next;
		tail->next = tail;
	}
	else
		tail->next->next = t->next;
	delete t;
}
void test07()
{
	Cque01*tail = Cque01_Init();
	Cque01_Push(tail);
	Cque01_Push(tail);
	Cque01_Pop(tail);
	Cque01_Pop(tail);
	Cque01_Pop(tail);
}
//int main()
//{
//	test07();
//	return 0;
//}
