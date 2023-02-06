#pragma once
#include<iostream>
using namespace std;

/*
	深度优先搜索的核心思想是，从某个顶点v开始，先访问该顶点v，
	再访问与该顶点相邻接且没有被访问过的顶点w，以该顶点w为新起点
	重复上述的操作，知道没有新顶点可被访问，然后回溯到w上一个顶点
	继续搜索，知道回到最初顶点v,该过程可以遍历完一个连通图。

	访问非连通图的操作与上述操作相似，只需要在访问顶点v后，
	再访问其他顶点
*/

//先实现邻接矩阵的搜索算法
#define Maxw 999999  //定义最大权值
#define Mvnum 100  //最大顶点数
typedef char VerType;  //顶点数据类型
typedef int ArcType;  //边的数据类型
typedef struct AMGraph {
	int vexnum, arcnum;
	VerType vexs[Mvnum];  //顶点信息表
	ArcType arcs[Mvnum][Mvnum];   //邻接矩阵
}AMGraph;
//创建无向网
void CreateUDN(AMGraph& G);
//深度遍历搜索
void DFS_AM(AMGraph& G, int v);
//遍历非连通图
void DFS_AMFORALL(AMGraph& G);

/*
	邻接表实现遍历
*/
typedef int OtherInfo;    //边的信息，权值等
typedef char VexType;      //顶点的信息

//边结点
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	OtherInfo info;
}ArcNode;

//表头结点表的存储结构
typedef struct {
	VexType data;   //顶点vex数据域
	ArcNode* fisrtarc;
}vNode, Adjlist[Mvnum];

//图的存储结构
typedef struct ALGraph {
	Adjlist vertices;    //定义表头结点表数组
	int vexnum, arcnum;   //顶点数以及边(弧)的数目
}ALGraph;

//创建一个邻接表（无向网）
void CreateUDNal(ALGraph& G);
//删除该邻接表(有点难度)
void DelUDNal(ALGraph& G);
//深度优先搜索,
void DFS_AL(ALGraph& G, int v);
//遍历非连通图
void DFS_ALFORALL(ALGraph& G);

/*
	算法核心思想：对于连通图而言，先访问第一个顶点，
	再访问该顶点的所有邻接点，再访问该顶点所有邻接点的所有
	邻接点，如此循环重复，直到所有的顶点都被遍历
*/

/*
	采用队列辅助实现算法
	先将第一个顶点入队，当其出队时，将其所有邻接点入队，再继续出队入队
	直到队列为空
*/

//队列实现
typedef struct ALQue {
	//随便给个20把，毕竟设为Mvnum太浪费空间了
	int Que[20];//存放入队的顶点编号
	int front, rear;
	int maxsize;    //队列的最大长度
}ALQue;
//入队、出队(需要弹出元素)、判空、初始化
void ALQueinit(ALQue& Q);
//判断是否为空
bool is_emptys(ALQue& Q);
//判断是否为满
bool is_full(ALQue& Q);
//入队
void ALQ_Push(ALQue& Q, const int& v);
//出队
void ALQ_Pop(ALQue& Q, int& w);

//队列实现
//广度优先搜索
void BFS_AL(ALGraph& G, const int v);
