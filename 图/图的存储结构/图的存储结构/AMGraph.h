#pragma once
#ifndef _AMGRAPH_H_
#define _AMGRAPH_H_
#include<string>
#include<iostream>
using namespace std;
//2-2-2023要求学习无向网的邻接矩阵表示法，以及探索其压缩矩阵
//有向网就不适合使用压缩矩阵了。另外由于无向图的表示法与无向网差不多
//故只需要讨论无向网

//无向网的邻接矩阵存储法
/*
	基本要素:顶点个数，边的个数
	顶点表数组、邻接矩阵二维数组
*/
#define MaxInt 999999
//最大顶点数
#define MVNum 100
//顶点类型
typedef string VerTexType;
//权值类型
typedef int ArcType;
typedef struct {
	//顶点类型数组,动态数组
	VerTexType* vexs;
	ArcType** arcs;
	//顶点个数，以及边的个数
	int vexnum, arcnum;
}AMGraph;
//创建无向网
void CreateUDN(AMGraph& G);
//销毁无向网
void DelUDM(AMGraph& G);

//无向网的压缩矩阵
typedef struct {
	//顶点类型数组,动态数组
	VerTexType* vexs;
	ArcType* arcs;
	//顶点个数，以及边的个数
	int vexnum, arcnum;
}AMGraphs;
//创建无向网
void CreateUDNs(AMGraphs& G);
//销毁无向网
void DelUDMs(AMGraphs& G);
#endif

