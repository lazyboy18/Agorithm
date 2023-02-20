#pragma once
#include<iostream>
#include<string>
using namespace std;

#define Maxvex 100

typedef char VexType;   //顶点信息      
typedef int OtherInfo;  //权值信息

//边表的存储结构
typedef struct ArcNode {
	int adjvex;				   	 //邻接顶点
	struct ArcNode* nextarc;     //下一个结点
}ArcNode;

//表头结点表的存储结构
typedef struct {
	ArcNode* fisrtarc;
}vNode, Adjlist[Maxvex];

//图的存储结构
typedef struct ALGraph {
	Adjlist  vertices;    //定义表头结点表数组
	int vexnum, arcnum;   //顶点数以及边(弧)的数目
}ALGraph;

//创建一个邻接表
void CreateUDN(ALGraph& G);
