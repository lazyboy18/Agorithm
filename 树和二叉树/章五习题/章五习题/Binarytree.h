#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include<iostream>
#include<string>
using namespace std;
#define QUEMAXSIZE 20
//��Ƶ�һ�����Ĵ洢�ṹ
typedef struct BinaryTreeA {
	int data;//������ͻ�������ص㣩
	struct BinaryTreeA* lChild, * rChild;
}BinaryTreeA,*Bpa;
//��ʼ��
void Ainit(Bpa& Btree);
//�������򴴽�
void Acreate(Bpa& Btree);
//��Ҷ�ӽ��,������ͬ����������
int AGetleavenum(Bpa& Btree);
//�ж��������Ƿ���ͬ
bool Ais_same(Bpa& Btree1, Bpa& Btree2);
//���������������Һ���
void AexChild(Bpa& Btree);
//˫�����
void ADO_visit(Bpa& Btree);
//����������������
void AGetmaxWidth(Bpa& Btree,int*arr,int floor);
//�û��汾
void AGetmaxWidthApp(Bpa& tree);

//������еĴ洢�ṹ
typedef struct Aque {
	Bpa* arr;//�洢Bpaָ��
	int rear, front;
	int quemaxsize;
}QAque;
//��ʼ��
void Aque_init(Aque& aque);
//�ж϶����Ƿ�Ϊ��
bool Aqueis_empty(Aque& aque);
//�ж�ѭ�������Ƿ��Ѿ���
bool Aqueis_full(Aque& aque);
//��ӣ����Ԫ����Bpaָ��
void Aque_push(Aque& aque, Bpa& tree);
//����,������Ԫ�ط���һ��������
void Aque_pop(Aque& aque, Bpa& carrier);
//�������,Ϊ����֤�仯���
void Aque_visit(Bpa& tree);
//���ٶ���
void Aque_delete(Aque& aque);


#endif