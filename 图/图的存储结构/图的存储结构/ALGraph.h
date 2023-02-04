#pragma once
#include<iostream>
using namespace std;

/*
	邻接表包括表头结点表与边表两部分，
	表头结点表以顺序存储结构为主，其下标代表顶点的编号，
	结点的数据域data存储顶点的数组，firstarc作为边表的表头结点，
	指向链表中的第一个结点；
	边表的数据域有三：adjvex表示该边所指向的顶点编号，info表示该边的信息，如权值
	，nextarc指向下一个结点。
*/

//无需最大权值
//最大结点数
#define Maxvex 100
#define Maxw 1000
//定义边以及顶点的信息

typedef int OtherInfo;    //边的信息，权值等
typedef int VexType;      //顶点的信息

//边表的存储结构
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	OtherInfo info;
}ArcNode;

//表头结点表的存储结构
typedef struct {
	VexType data;   //顶点vex数据域
	ArcNode* fisrtarc;
}vNode,Adjlist[Maxvex];

//图的存储结构
typedef struct ALGraph {
	Adjlist vertices;    //定义表头结点表数组
	int vexnum, arcnum;   //顶点数以及边(弧)的数目
}ALGraph;

//创建一个邻接表（无向网）
void CreateUDNal(ALGraph& G);
//删除该邻接表(有点难度)
void DelUDNal(ALGraph& G);
