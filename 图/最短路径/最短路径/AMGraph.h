#pragma once
#include<iostream>
using namespace std;

//邻接矩阵存储有向网
#define Mvnum 100  //最大顶点数
typedef char VerType;  //顶点数据类型
typedef int ArcType;  //弧的权值
typedef struct AMGraph {
	int vexnum, arcnum;
	VerType vexs[Mvnum];		  //顶点信息表
	ArcType arcs[Mvnum][Mvnum];   //邻接矩阵
}AMGraph;

//创建有向网
void CreateUDN(AMGraph& G);