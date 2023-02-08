#pragma once
#include"ALGraph.h"

//�ȶ���edge�ṹ�壬�洢G���еıߣ���������
typedef struct edge {
	//�洢ͷ���㣬���ڴ���������
	VexType head;
	//�洢β���㣬���ڴ���������
	VexType tail;
	//�洢�ߵ�Ȩֵ
	OtherInfo lowcost;
}edge;

//����������ʼ��
void edgeInit(const ALGraph&G, edge*Assistarr);

//������
void edgeSort(edge* Assistarr, const int& length);

//ȷ������λ��
int LocateVex(const ALGraph& G, const VexType& v);

//�ÿ�³˹�����㷨������С������
void MiniSpanTree_Kruaskal(const ALGraph& G);