#pragma once
#include"AMGraph.h"
//弗洛伊德算法的头文件

/*
	该算法的思想是，每一个顶点都有可能是其他任意两个顶点的中转点，
	因此有向网中的每一个顶点都需要尝试作为其他任意两个顶点的中转点
*/

//输出任意顶点之间的最短路径
void OutshortestPath_Floyd(const AMGraph& G, int(*D)[Mvnum], int(*Path)[Mvnum]);

//任意顶点之间最短路径的顶点顺序
void OutvexInPath_Floyd(const int& i, const int& j, int(*Path)[Mvnum], const AMGraph& G);
//初始化函数
void Init_Floyd(const AMGraph& G, int(*D)[Mvnum], int(*Path)[Mvnum]);

//弗洛伊德算法
void ShortestPath_Floyd(const AMGraph& G);


