#pragma once
#include<iostream>
using namespace std;

/*
	�ڽӱ������ͷ������߱������֣�
	��ͷ������˳��洢�ṹΪ�������±������ı�ţ�
	����������data�洢��������飬firstarc��Ϊ�߱�ı�ͷ��㣬
	ָ�������еĵ�һ����㣻
	�߱��������������adjvex��ʾ�ñ���ָ��Ķ����ţ�info��ʾ�ñߵ���Ϣ����Ȩֵ
	��nextarcָ����һ����㡣
*/

//�������Ȩֵ
//�������
#define Maxvex 100
#define Maxw 1000
//������Լ��������Ϣ

typedef int OtherInfo;    //�ߵ���Ϣ��Ȩֵ��
typedef int VexType;      //�������Ϣ

//�߱�Ĵ洢�ṹ
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	OtherInfo info;
}ArcNode;

//��ͷ����Ĵ洢�ṹ
typedef struct {
	VexType data;   //����vex������
	ArcNode* fisrtarc;
}vNode,Adjlist[Maxvex];

//ͼ�Ĵ洢�ṹ
typedef struct ALGraph {
	Adjlist vertices;    //�����ͷ��������
	int vexnum, arcnum;   //�������Լ���(��)����Ŀ
}ALGraph;

//����һ���ڽӱ���������
void CreateUDNal(ALGraph& G);
//ɾ�����ڽӱ�(�е��Ѷ�)
void DelUDNal(ALGraph& G);
