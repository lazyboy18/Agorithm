#pragma once
#include<iostream>
#include<string>
using namespace std;

#define Maxvex 100

typedef char VexType;   //������Ϣ      
typedef int OtherInfo;  //Ȩֵ��Ϣ

//�߱�Ĵ洢�ṹ
typedef struct ArcNode {
	int adjvex;				   	 //�ڽӶ���
	struct ArcNode* nextarc;     //��һ�����
}ArcNode;

//��ͷ����Ĵ洢�ṹ
typedef struct {
	ArcNode* fisrtarc;
}vNode, Adjlist[Maxvex];

//ͼ�Ĵ洢�ṹ
typedef struct ALGraph {
	Adjlist  vertices;    //�����ͷ��������
	int vexnum, arcnum;   //�������Լ���(��)����Ŀ
}ALGraph;

//����һ���ڽӱ�
void CreateUDN(ALGraph& G);
