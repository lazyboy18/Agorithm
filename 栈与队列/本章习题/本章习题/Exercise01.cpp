#include<iostream>
using namespace std;
/*
@ brief ʵ��һ��˫��ջ
*/
#define MAXSIZE 5
typedef struct
{
	int top[2];
	int maxsize;
	int*base;
}DblStack;
//��ʼ��
void DblStack_Init(DblStack&d)
{
	d.maxsize = MAXSIZE;
	d.top[0] = -1;
	d.top[1] = d.maxsize;
	d.base = new int[d.maxsize];
	cout << "˫��ջ��ʼ���ɹ�" << endl;
}
//�ж�ջ�Ƿ�Ϊ��
bool DblStack_Isempty(const DblStack&d, const int&num)
{
	if (num == 0)
	{
		if (d.top[0] == -1)
		{
			//cout << "0��ջΪ��" << endl;
			return true;
		}
		else
			return false;
	}
	else if (num == 1)
	{
		if (d.top[1] == d.maxsize)
		{
			//cout << "1��ջΪ��" << endl;
			return true;
		}
		else
			return false;
	}
	else
		cout << "num�������" << endl;
	return false;
}
bool DblStack_Isfull(const DblStack&d)
{
	if (d.top[0] + 1 == d.top[1])
		return true;
	else
		return false;
}
//��ջ
void DblStack_Push(DblStack&d, const int&num, const int&x)
{
	if (DblStack_Isfull(d))
		return;
	d.base[d.top[num]] = x;
	if (num == 0)
		d.top[0]++;
	else
		d.top[1]--;
}
//��ջ
int DblStack_Pop(DblStack&d, const int&num)
{
	if (DblStack_Isempty(d, num))
		return -1;
	if (num == 0)
		d.top[0]--;
	else
		d.top[1]++;
	return d.base[d.top[num]];
}
void test()
{
	DblStack d;
	DblStack_Init(d);
	int a, b;
	while (!DblStack_Isfull(d))
	{
		cout << "������������:>" << endl;
		cin >> a >> b;
		DblStack_Push(d, a, b);
	}
	cout << "0��ջ������:>" << endl;
	while (!DblStack_Isempty(d, 0))
	{
		cout << DblStack_Pop(d, 0) << " ";
	}
	cout << endl;
	cout << "1��ջ������:>" << endl;
	while (!DblStack_Isempty(d, 1))
	{
		cout << DblStack_Pop(d, 1) << " ";
	}
	cout << endl;
}
//int main()
//{
//	test();
//	return 0;
//}

