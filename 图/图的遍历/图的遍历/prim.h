#pragma once
#include"AMGraph.h"

//定义辅助数组
typedef struct closedge {
	//最小边(u,v)在U中的顶点
	VerType adject;
	//U到k的最小权值
	ArcType lowcost;
}closedge;

//普里姆算法声明
void MiniSpanTree_Prim(const AMGraph& G, VerType u);

//查找下标函数
int LocateVex(const AMGraph& G, VerType u);

//找权值最小边，返回其在辅助数组中的下标
//注意数组名本身就是一个常量地址，不能传引用
int Findminarc(const AMGraph& G, const closedge* Assistarr);