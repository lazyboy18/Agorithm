#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#define MAXSIZE01 10
//ʵ��һ��ѭ�����У������βָ��
/*
	ѭ�����ӵ��������ӵ�ע������,ָ����ʵ�Σ������β�Ϊ���û����ָ��
	ɾ�����һ������ע������
*/
typedef struct Cque01
{
	int a;
	struct Cque01*next;
}Cque01;
//��ʼ��
Cque01*Cque01_Init()
{
	Cque01*P = new Cque01;	
	P->next = P;//Pָ���Լ�
	cout << "��ʼ���ɹ�" << endl;
	return P;
}
//�ж��Ƿ�Ϊ�ն���
bool Cque01_Isempty(Cque01*&tail)
{
	if (tail->next == tail)
	{
		cout << "ѭ������Ϊ��" << endl;
		return true;
	}
	else
		return false;
}
//���
void Cque01_Push(Cque01*&tail)
{
	cout << "��������:>" << endl;
	Cque01*P = new Cque01;
	cin >> P->a;
	P->next = tail->next;
	tail->next = P;
	tail = P;
}
//����
void Cque01_Pop(Cque01*&tail)
{
	if (Cque01_Isempty(tail))
	{
		return;
	}
	Cque01*t = tail->next->next;//��ɾ���Ľ��
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
