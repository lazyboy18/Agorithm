#include"DIJ.h"

//inf表示两顶点间没有线路，距离为无穷大
int inf = 99999999;

//辅助数组初始化函数
void Init(const AMGraph& G, int* Path, int* shortestDis, const int& v ,bool*S)
{
	//如果<v,vi>之间有弧，那么vi的直接前驱为v
	for (int i = 0;i < G.vexnum;i++)
	{
		if (inf != G.arcs[v][i])
			Path[i] = v;
		else
			Path[i] = -1;
	}
	//初始化源点到各个顶点之间的最短路径
	for (int i = 0;i < G.vexnum;i++)
	{
		shortestDis[i] = G.arcs[v][i];
	}
	//v自然在最短路径源点集中
	S[v] = true;
}


//计算某源点到其他所有顶点的最短路径
int findmin(const int* shortestDis, const bool* S,const int&n)
{
	int k = 0;
	int minroad = inf;
	for (int i = 0;i < n;i++)
	{
		if (!S[i])
		{
			if (minroad > shortestDis[i])
			{
				k = i;
				minroad = shortestDis[i];
			}
		}
	}
	return k;
}


//输出该路径上的顶点
void OutvexInpath(const int& v, const int& i, const int* Path, const AMGraph& G)
{
	//查找到源点v为止
	if (i == v)
	{
		cout << G.vexs[v];
	}
	else
	{
		//查找下标为i的顶点的直接前驱
		OutvexInpath(v, Path[i], Path, G);
		cout << "->" << G.vexs[i];
	}

}

//结束更新，输出最短路径：
void OutshortestPath(const int& v, const int* shortestDis, const int* Path, const AMGraph& G)
{
	cout << "最短路径输出如下:>" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		cout << "从顶点" << G.vexs[v] << "到顶点" << G.vexs[i] << "的最短路径为" << shortestDis[i] << endl;
		//输出该路径上的顶点
		cout << "其路径如下:>" << endl;
		OutvexInpath(v, i, Path, G);
		//输出换行
		cout << endl;
	}
}

//以邻接矩阵作为存储结构
void ShortestPath_DIJ(const AMGraph& G, const int& v)
{
	//判断下标的合法性
	if (v > G.vexnum || v < 0)
	{
		return;
	}
	//首先定义辅助数组
	//1.记录该顶点是否已经加入最短路径终点集合
	bool S[Mvnum] = { 0 };	
	//2.记录源点v0到终点vi的最短路径上，vi的直接前驱顶点在邻接矩阵中的下标
	int Path[Mvnum] = { 0 };
	//3.记录当前源点到各个终点的最短路径
	int shortestDis[Mvnum] = { 0 };
	Init(G, Path, shortestDis, v, S);
	//有向网的顶点个数
	int n = G.vexnum;
	//将其余n-1个顶点加入到S中
	for (int i = 1;i < n;i++)
	{
		//寻找当前源点到没加入S集中的顶点的最短路径(v,vk)
		//并且返回其下标k
		int k = findmin(shortestDis, S, n);
		//将k下标加入到S集
		S[k] = true;
		//通过“中转点”k,更新最短路径
		for (int j = 0;j < n;j++)
		{
			if (!S[j])
			{
				//需要用到<v,k>的最新数据作为判断依据
				if (shortestDis[j] > shortestDis[k] + G.arcs[k][j])
				{
					//更新最短路径
					shortestDis[j] = shortestDis[k] + G.arcs[k][j];
					//更新j的直接前驱为k
					Path[j] = k;
				}
			}
		}
	}
	//结束更新，输出最短路径：
	OutshortestPath(v, shortestDis, Path, G);
}

//本例可以优化的地方为：定义G,Path,Shortest,S的存储结构为全局变量
//从而减少函数参数