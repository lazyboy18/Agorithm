#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAXSIZE01 7
//用递归算法实现单链表的操作
typedef struct link
{
	int data;
	struct link*next;
}link,*qlink;
//初始化
qlink link_Init()
{
	qlink q = new link;
	q->next = NULL;
	cout << "初始化成功" << endl;
	return q;
}
//创建链表
void link_Create(qlink Q)
{
	if (Q->next != NULL)
	{
		cout << "非空表" << endl;
		return;
	}
	cout << "请输入结点个数:>";
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		qlink q = new link;
		cout << "请输入数据:>";
		cin >> q->data;
		Q->next = q;
		Q = q;
		Q->next = NULL;
	}
	cout << "链表创建成功" << endl;
}
//求链表中的最大值
int link_getmax(qlink Q,int max)
{
	if (Q == NULL)
	{
		return max;
	}
	if (Q->data > max)
	{
		max = Q->data;
	}
	link_getmax(Q->next, max);
}
//用户希望传入表头就能得到最大值，而无需额外读取文档
//得到最大值
void link_Getmax(qlink Q)
{
	int max = Q->next->data;
	max = link_getmax(Q->next, max);
	cout << "链表最大整数 max = " << max << endl;
	return;
}
//求链表中的结点个数
int link_getnodenum(qlink Q, int nodenum)
{
	if (Q == NULL)
		return nodenum;
	link_getnodenum(Q->next, nodenum + 1);
}
void link_Qetnodenum(qlink Q)
{
	int nodenum = link_getnodenum(Q->next, 0);
	cout << "链的结点的数 node = " << nodenum << endl;
	return;
}
//求所有整数的平均值
int link_averagenum(qlink Q, int num,int nodenum)
{
	if (Q == NULL)
	{
		return num / nodenum;
	}
	link_averagenum(Q->next, num+Q->data, nodenum);
}
void link_Averagenum(qlink Q)
{
	int nodenum = link_getnodenum(Q->next, 0);
	int averagenum = link_averagenum(Q->next, 0, nodenum);
	cout << "链表所有整数的平均值 averagenum =  " << averagenum << endl;
	return;
}
void test12()
{
	qlink Q = link_Init();
	link_Create(Q);
	link_Getmax(Q);
	link_Qetnodenum(Q);
	link_Averagenum(Q);
}
//int main()
//{
//	test12();
//	return 0;
//}