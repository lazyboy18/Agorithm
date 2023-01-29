#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAXSIZE01 7
/*
	允许循环队列的两端都可以进行插删操作
	为了判断空满方便，我们规定头尾指针相等则为空，差1则为满;
	规定flag为操作数，0表示进行头部操作，1表示尾部操作
	需要注意头尾指针的变化
	怪不得题干只要求头插尾删
*/
//定义结构体
typedef struct Ique02
{
	int*base;
	int front;
	int rear;
	int max;
}Ique02;
//初始化
void Ique02_Init(Ique02&I)
{
	I.max = MAXSIZE01;
	I.front = I.rear = 0;
	I.base = new int[I.max];
	cout << "Ique02初始化成功" << endl;
}
bool Ique02_Isempty(const Ique02&I)
{
	if (I.front == I.rear)
	{
		cout << "队列为空" << endl;
		return true;
	}
	else
		return false;
}
bool Ique02_Isfull(const Ique02&I)
{
	if ((I.rear+1)%I.max==I.front)
	{
		cout << "队列为满" << endl;
		return true;
	}
	else
		return false;
}
//插入
void Ique02_Push(Ique02&I)
{
	if (Ique02_Isfull(I))
	{
		return;
	}
	int x;
	cout << "头部插入元素:>";
	cin >> x;
	I.base[I.front] = x;
	I.front = (I.front + I.max - 1) % I.max;
}
//删除
void Ique02_Pop(Ique02&I)
{
	if (Ique02_Isempty(I))
		return;
	int flag;
	cout << "尾部删除成功" << endl;
	I.rear=(I.rear + I.max - 1) % I.max;
}
//展示
void Ique02_Show(const Ique02&I)
{
	//从队头看到队尾
	if (Ique02_Isempty(I))
		return;
	cout << "队列元素如下:>" << endl;
	int begin = I.front;
	int end = I.rear;
	do
	{
		begin = (begin + 1) % I.max;
		cout << I.base[begin] << " ";	
	} while (begin != end);
	cout << endl;
}

void test09()
{
	Ique02 I;
	Ique02_Init(I);
	int Input;
	do
	{
		cout << "按1插入，按2删除，按3输出队列元素，按0退出" << endl;
		cout << "请选择:>";
		cin >> Input;
		switch (Input)
		{
		case 0:
			cout << "退出成功" << endl;
			break;
		case 1:
			Ique02_Push(I);
			break;
		case 2:
			Ique02_Pop(I);
			break;
		case 3:
			Ique02_Show(I);
			break;
		default:
			cout << "输入有误"<<endl;
			break;
		}
		system("pause");
		system("cls");
	} while (Input);
}

//int main()
//{
//	test09();
//	return 0;
//}


