#pragma once
#include"AMGraph.h"

//���帨������
typedef struct closedge {
	//��С��(u,v)��U�еĶ���
	VerType adject;
	//U��k����СȨֵ
	ArcType lowcost;
}closedge;

//����ķ�㷨����
void MiniSpanTree_Prim(const AMGraph& G, VerType u);

//�����±꺯��
int LocateVex(const AMGraph& G, VerType u);

//��Ȩֵ��С�ߣ��������ڸ��������е��±�
//ע���������������һ��������ַ�����ܴ�����
int Findminarc(const AMGraph& G, const closedge* Assistarr);