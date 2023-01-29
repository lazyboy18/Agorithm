#ifndef _BTTREE_H_
#define _BTTREE_H_
#include<iostream>
using namespace std;
#include<string>
#define MAXQUENUM 10
/*
	��Ҫ��ɵ�����
	����������ṹ��дһ���˼ʹ�ϵ��
	�����ʼ����������������
	��ؼ����ǣ�������㺯�����ݹ�ʵ�֣�ջʵ�֣�����ʵ�֣�
	���ƶ���������������ȡ��������
*/
/*
	�������⣺��������,��ջ�Ĵ���

*/
//��ϵ����
typedef struct Binarytree{
	string name;//����
	string relationship;//����һ���Ĺ�ϵ
	struct Binarytree*leftchild, *rightchild;
}Bitree,*BIpointer;
//ջ
typedef struct Bstack{
	Bitree* Bt;//������
	struct Bstack*next;//ָ����
}Bstack;

//����ʵ�����Ĳ������
typedef struct Bque{
	//������.���Bitree��ָ�룬�ܽ�ʡ�ռ䣻
	//���Base��Bitree���飬��ô��Ԫ����Ҫ���¸�ֵ
	Bitree** Base;
	int rear;
	int tail;
	int maxsize;
}Bque;

//�������Ļ�������
Bitree* BTnit();
void BTcreate(Bitree*&Bt, int row = 1, int col = 1);
void OrderTraverse(Bitree* Bt, int row = 1, int col = 1);
void BinaryTreeCopy(Bitree* Bt, Bitree*&newtree);//���ƶ�����
int Getdepth(Bitree* Bt);//��ö����������
int Getnodenum(Bitree* Bt);//��ý��ĸ���
int getleavenum(Bitree* Bt);//���Ҷ�ڵ����
int getonenodenum(Bitree* Bt);
int gettwonodenum(Bitree* Bt);
void Visitbyfloor(Bitree* Bt);//���������

//ջ����
void Bstack_init(Bstack& BT);
//�ж�ջ�Ƿ�Ϊ��
bool Bstack_Isempty(Bstack* BT);
//��ջ
void Push(Bitree* root, Bstack**BT);
//��ջ
Bitree* Pop(Bstack**BT);
//�ǵݹ����������
void StackTraverse(Bitree* Bitree);


//ѭ�����в���  ��ʼ�����ж��Ƿ�Ϊ�գ���ӣ�����
void Bque_init(Bque& Que);
//�ж��Ƿ�Ϊ��
bool Bque_isempty(Bque& Que);
//�ж��Ƿ��Ѿ���
bool Bque_isfull(Bque& Que);
//���,���Ԫ��ΪBitree*����
void Bque_push(Bque& Que, Bitree*&Btreepointer);
//���ӣ�����Ԫ����Bitree*����
Bitree* Bque_Pop(Bque& Que);

#endif

