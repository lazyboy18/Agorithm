#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#define MAXSIZE01 2
/*
	亮点：如何解决循环队列空满同义的问题
		  删除与插入都需要对头尾指针做出特殊处理
*/
typedef struct Ique
{
	int*Q;
	int front;
	int rear;
	int max;
	int tag;
}Ique;
void Ique_Init(Ique&I)
{
	I.max = MAXSIZE01;
	I.front = I.rear = I.tag = 0;
	I.Q = new int[I.max];
}
bool Ique_Isempty(const Ique&I)
{
	if (I.tag == 0)
	{
		cout << "队列为空" << endl;
		return true;
	}
	else
		return false;
}
bool Ique_Isfull(const Ique&I)
{
	if (I.tag == 1)
	{
		cout << "队列已满" << endl;
		return true;
	}
	else
		return false;
}
void Ique_enque(Ique&I, const int x)
{
	if (Ique_Isfull(I))
	{
		return;
	}
	I.Q[I.rear] = x;
	I.rear = (I.rear + 1) % I.max;
	if (I.front == I.rear)
		I.tag = 1;
	else
		I.tag = 2;
}
void Ique_dequeue(Ique&I)
{
	if (Ique_Isempty(I))
		return;
	I.rear = (I.rear - 1 + I.max) % I.max;
	if (I.front == I.rear)
		I.tag = 0;
	else
		I.tag = 2;
}
void test08()
{
	Ique I;
	Ique_Init(I);
	Ique_dequeue(I);
	Ique_enque(I, 1);
	Ique_enque(I, 1);
	Ique_enque(I, 1);
	Ique_dequeue(I);
	Ique_dequeue(I);
	Ique_dequeue(I);
}
//int main()
//{
//	test08();
//	return 0;
//}