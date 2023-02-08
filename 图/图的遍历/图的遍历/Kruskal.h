#pragma once
#include"ALGraph.h"

//先定义edge结构体，存储G所有的边，并且排序
typedef struct edge {
	//存储头顶点，用于处理有向网
	VexType head;
	//存储尾顶点，用于处理有向网
	VexType tail;
	//存储边的权值
	OtherInfo lowcost;
}edge;

//辅助函数初始化
void edgeInit(const ALGraph&G, edge*Assistarr);

//排序函数
void edgeSort(edge* Assistarr, const int& length);

//确定顶点位置
int LocateVex(const ALGraph& G, const VexType& v);

//用克鲁斯卡尔算法生成最小生成树
void MiniSpanTree_Kruaskal(const ALGraph& G);