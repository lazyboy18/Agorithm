#ifndef _GETVABT_H_
#define _GETVABT_H_
#include<iostream>
using namespace std;
#define MAXSIZE 20
/*
	��ֵ���ʽ�Ķ�������Ҷ�ӽ��һ���ǲ�����
	�涨��������������Ϊ�������ͣ�����������������
	�������������Ҷ�ӽ�㶼���������Ӧ��ACSI��ֵ

	���ݽṹ�ж���������ջ����ջ��Ԫ���Ƕ�����
*/

//�����������ݽṹ
typedef struct valBT
{
	int val;
	struct valBT*lchild, *rchild;
}valBT;
//ջ�����ݽṹ
typedef struct valstack
{
	valBT**arr;//��Ŷ�������ָ��
	int top;
}valstack;
//����������
void createBT(valBT*& B, valBT*& LB, valBT*& RB, const int i);
//��������ջ��,�ȳ�ʼ��
void valStackinit(valstack& vals);
//ջ�գ�
bool is_emptyss(valstack& vals);
//ջ����
bool is_full(valstack& vals);
//��ջ
void valPush(valstack& vals, valBT*& B);
//��ջ,����ָ��
void valPop(valstack& vals, valBT*& B);
//��ȡջ��Ԫ��
char Getval(valstack& vals);
//�ж��Ƿ�Ϊ����
bool is_char(const char& ch);
//�Ƚ��ַ����ȼ�
char cCompare(const char&c1, const char&c2);
//�㷨���ģ��������еĺ���,�û�ֱ�ӵ���
void coreCalulate();
//��ȡ���ս��
int getresult(valBT*& resulttree);
//ͨ���ַ�����
int getbyOP(valBT*&op, valBT*&num1, valBT*&num2);
#endif