#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAXSIZE01 7
//�õݹ��㷨ʵ�ֵ�����Ĳ���
typedef struct link
{
	int data;
	struct link*next;
}link,*qlink;
//��ʼ��
qlink link_Init()
{
	qlink q = new link;
	q->next = NULL;
	cout << "��ʼ���ɹ�" << endl;
	return q;
}
//��������
void link_Create(qlink Q)
{
	if (Q->next != NULL)
	{
		cout << "�ǿձ�" << endl;
		return;
	}
	cout << "�����������:>";
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		qlink q = new link;
		cout << "����������:>";
		cin >> q->data;
		Q->next = q;
		Q = q;
		Q->next = NULL;
	}
	cout << "�������ɹ�" << endl;
}
//�������е����ֵ
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
//�û�ϣ�������ͷ���ܵõ����ֵ������������ȡ�ĵ�
//�õ����ֵ
void link_Getmax(qlink Q)
{
	int max = Q->next->data;
	max = link_getmax(Q->next, max);
	cout << "����������� max = " << max << endl;
	return;
}
//�������еĽ�����
int link_getnodenum(qlink Q, int nodenum)
{
	if (Q == NULL)
		return nodenum;
	link_getnodenum(Q->next, nodenum + 1);
}
void link_Qetnodenum(qlink Q)
{
	int nodenum = link_getnodenum(Q->next, 0);
	cout << "���Ľ����� node = " << nodenum << endl;
	return;
}
//������������ƽ��ֵ
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
	cout << "��������������ƽ��ֵ averagenum =  " << averagenum << endl;
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