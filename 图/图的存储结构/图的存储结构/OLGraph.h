#pragma once
#include<iostream>
using namespace std;
/*
	Ϊ�˽��ͼ���ڽӱ���Ѱ�ҳ���ȸ��������⣬
	����ѡ��ʹ��ʮ������
	�������������ɲ���˳��洢�ṹ�����������
	���ó��������ָ����Ϊָ����

	���ڶ�����vexNode���ԣ�������Ϊdata,��������ΪvexType
	firstin��firstout�ֱ�ָ��ö���ĵ�һ����Ȼ����һ�����Ȼ�
	��������ΪArcBox;

	���ڻ����arcNode���ԣ�������������tailvex��headvex���ֱ�
	ָ���û��Ļ�β����뻡ͷ���;tlink��hlink�ֱ�ָ����β�뻡ͷ��ͬ��
	��һ�������;����Ȼ��ÿȷ��һ��·��<v1,v2>����Ҫͬʱ�޸�
	v1��firstout��v2��firstin,ͬʱÿһ��������ڴ���֮ʱ��tlinkָ��
	v1���ε�һ�����Ȼ�(ͬ����v1Ϊ��β),hlinkָ��v2�����ε�һ����Ȼ�
	��ͬ����v2Ϊ��ͷ��
*/


#define Maxw 100000
#define Maxvex 100    //��󶥵���
//����Ȩֵ�붥�����Ϣ����
typedef int OtherInfo;
typedef int vexType;

//���廡���
typedef struct ArcBox {
	//��������Ƚ����
	int tailvex, headvex;
	//��û�����ͬ���ȵ�Ļ�����û�����ͬ��ȵ�Ļ�
	struct ArcBox* tlink, * hlink;
	OtherInfo w;
}ArcBox;
//���嶥��洢�ṹ
typedef struct VexNode {
	vexType data;
	//��һ����ȱ߽�����һ�����ȱ�
	struct ArcBox* firstin, * firstout;
}VexNode;
//����ʮ������
typedef struct OLGraph {
	VexNode xlist[Maxvex];//�������������
	int vexnum, arcnum;//�����뻡�ĸ���
}OLGraph;
//����ʮ������
void CreateUDNol(OLGraph& G);

