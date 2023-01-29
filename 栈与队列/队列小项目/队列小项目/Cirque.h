#ifndef _CIRQUE_H_
#define _CIRQUE_H_
#include<iostream>
#include<string>
using namespace std;
//ָ�����е��������
#define MAXQSIZE 100
//
typedef struct Cirque
{
	//ָ��Ķ���ָ���ַ������ͣ��ַ���������������
	string* base;
	int front;
	int rear;
	int maxqsize;
}Cirque;
//��ʼ��
void Cirque_Init(Cirque*cq);
//��ӳ���
int Cirque_Getlen(Cirque*cq);
//���Ӻ�����Ҫ����ͷԪ����Ϊ����ֵ
string Cirque_Out(Cirque*cq);
//��Ӻ�������һ��string���͵Ĳ���
void Cirque_Push(Cirque*cq,string name);
//��ȡ��ͷԪ��
string Cirque_Gethead(Cirque*cq);
//��ȡ��βԪ��
string Cirque_Gettail(Cirque*cq);
//��������
void Dancer_Loading(Cirque*md, Cirque*fd);
//�����λ��ƥ������
void First_Dancer(Cirque*md, Cirque*fd);
//����ƥ��
void Sroll_match(Cirque*md, Cirque*fd);
/*
	�һ�ȱһ���ж�Ϊ�յĺ���
*/
#endif