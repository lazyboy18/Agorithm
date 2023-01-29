#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAXSIZE01 7
/*
	����ѭ�����е����˶����Խ��в�ɾ����
	Ϊ���жϿ������㣬���ǹ涨ͷβָ�������Ϊ�գ���1��Ϊ��;
	�涨flagΪ��������0��ʾ����ͷ��������1��ʾβ������
	��Ҫע��ͷβָ��ı仯
	�ֲ������ֻҪ��ͷ��βɾ
*/
//����ṹ��
typedef struct Ique02
{
	int*base;
	int front;
	int rear;
	int max;
}Ique02;
//��ʼ��
void Ique02_Init(Ique02&I)
{
	I.max = MAXSIZE01;
	I.front = I.rear = 0;
	I.base = new int[I.max];
	cout << "Ique02��ʼ���ɹ�" << endl;
}
bool Ique02_Isempty(const Ique02&I)
{
	if (I.front == I.rear)
	{
		cout << "����Ϊ��" << endl;
		return true;
	}
	else
		return false;
}
bool Ique02_Isfull(const Ique02&I)
{
	if ((I.rear+1)%I.max==I.front)
	{
		cout << "����Ϊ��" << endl;
		return true;
	}
	else
		return false;
}
//����
void Ique02_Push(Ique02&I)
{
	if (Ique02_Isfull(I))
	{
		return;
	}
	int x;
	cout << "ͷ������Ԫ��:>";
	cin >> x;
	I.base[I.front] = x;
	I.front = (I.front + I.max - 1) % I.max;
}
//ɾ��
void Ique02_Pop(Ique02&I)
{
	if (Ique02_Isempty(I))
		return;
	int flag;
	cout << "β��ɾ���ɹ�" << endl;
	I.rear=(I.rear + I.max - 1) % I.max;
}
//չʾ
void Ique02_Show(const Ique02&I)
{
	//�Ӷ�ͷ������β
	if (Ique02_Isempty(I))
		return;
	cout << "����Ԫ������:>" << endl;
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
		cout << "��1���룬��2ɾ������3�������Ԫ�أ���0�˳�" << endl;
		cout << "��ѡ��:>";
		cin >> Input;
		switch (Input)
		{
		case 0:
			cout << "�˳��ɹ�" << endl;
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
			cout << "��������"<<endl;
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


