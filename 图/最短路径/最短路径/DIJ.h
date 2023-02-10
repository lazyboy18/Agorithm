#pragma once
#include"AMGraph.h"

/*
	迪杰斯特拉算法利用了“中转”点不断更新最短路径,
	直到求出源点到顶点的所有最短路径

	我们知道，又是从某一个顶点到达另外一个顶点或根本不存在路径，
	或直达路径会大于源点到中转点路径加上中转点到终点的路径，
	此时需要将源点到终点的距离更新

*/

//辅助数组初始化函数
void Init(const AMGraph& G, int* Path, int* shortestDis, const int& v, bool* S);
//寻找最短路径<v,vk>的下标k
int findmin(const int* shortestDis, const bool* S, const int& n);
//结束更新，输出最短路径：
void OutshortestPath(const int& v, const int* shortestDis, const int* Path, const AMGraph& G);
//输出该路径上的顶点
void OutvexInpath(const int& v, const int& i, const int* Path, const AMGraph& G);

//计算某源点到其他所有顶点的最短路径
//以邻接矩阵作为存储结构
void ShortestPath_DIJ(const AMGraph& G, const int& v);
