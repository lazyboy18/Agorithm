#pragma once
#include<iostream>
using namespace std;

/*
	������������ĺ���˼���ǣ���ĳ������v��ʼ���ȷ��ʸö���v��
	�ٷ�����ö������ڽ���û�б����ʹ��Ķ���w���Ըö���wΪ�����
	�ظ������Ĳ�����֪��û���¶���ɱ����ʣ�Ȼ����ݵ�w��һ������
	����������֪���ص��������v,�ù��̿��Ա�����һ����ͨͼ��

	���ʷ���ͨͼ�Ĳ����������������ƣ�ֻ��Ҫ�ڷ��ʶ���v��
	�ٷ�����������
*/

//��ʵ���ڽӾ���������㷨
#define Maxw 999999  //�������Ȩֵ
#define Mvnum 100  //��󶥵���
typedef char VerType;  //������������
typedef int ArcType;  //�ߵ���������
typedef struct AMGraph {
	int vexnum, arcnum;
	VerType vexs[Mvnum];  //������Ϣ��
	ArcType arcs[Mvnum][Mvnum];   //�ڽӾ���
}AMGraph;
//����������
void CreateUDN(AMGraph& G);
//��ȱ�������
void DFS_AM(AMGraph& G, int v);
//��������ͨͼ
void DFS_AMFORALL(AMGraph& G);

/*
	�ڽӱ�ʵ�ֱ���
*/
typedef int OtherInfo;    //�ߵ���Ϣ��Ȩֵ��
typedef char VexType;      //�������Ϣ

//�߽��
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	OtherInfo info;
}ArcNode;

//��ͷ����Ĵ洢�ṹ
typedef struct {
	VexType data;   //����vex������
	ArcNode* fisrtarc;
}vNode, Adjlist[Mvnum];

//ͼ�Ĵ洢�ṹ
typedef struct ALGraph {
	Adjlist vertices;    //�����ͷ��������
	int vexnum, arcnum;   //�������Լ���(��)����Ŀ
}ALGraph;

//����һ���ڽӱ���������
void CreateUDNal(ALGraph& G);
//ɾ�����ڽӱ�(�е��Ѷ�)
void DelUDNal(ALGraph& G);
//�����������,
void DFS_AL(ALGraph& G, int v);
//��������ͨͼ
void DFS_ALFORALL(ALGraph& G);

/*
	�㷨����˼�룺������ͨͼ���ԣ��ȷ��ʵ�һ�����㣬
	�ٷ��ʸö���������ڽӵ㣬�ٷ��ʸö��������ڽӵ������
	�ڽӵ㣬���ѭ���ظ���ֱ�����еĶ��㶼������
*/

/*
	���ö��и���ʵ���㷨
	�Ƚ���һ��������ӣ��������ʱ�����������ڽӵ���ӣ��ټ����������
	ֱ������Ϊ��
*/

//����ʵ��
typedef struct ALQue {
	//������20�ѣ��Ͼ���ΪMvnum̫�˷ѿռ���
	int Que[20];//�����ӵĶ�����
	int front, rear;
	int maxsize;    //���е���󳤶�
}ALQue;
//��ӡ�����(��Ҫ����Ԫ��)���пա���ʼ��
void ALQueinit(ALQue& Q);
//�ж��Ƿ�Ϊ��
bool is_emptys(ALQue& Q);
//�ж��Ƿ�Ϊ��
bool is_full(ALQue& Q);
//���
void ALQ_Push(ALQue& Q, const int& v);
//����
void ALQ_Pop(ALQue& Q, int& w);

//����ʵ��
//�����������
void BFS_AL(ALGraph& G, const int v);
