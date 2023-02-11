#include"Floyd.h"

//inf表示两顶点间没有线路，距离为无穷大
int infs = 99999999;
//初始化函数
void Init_Floyd(const AMGraph& G, int(*D)[Mvnum], int(*Path)[Mvnum])
{
	//D的初始状态为G.arcs[Mvnum][Mvnum]
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			D[i][j] = G.arcs[i][j];
		}
	}
	//初始化Path，假如<vi,vj>之间弧，则vj的直接前驱为vi,否则为-1
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			if (G.arcs[i][j] != infs && i != j)
				Path[i][j] = i;
			else
				Path[i][j] = -1;
		}
	}
}

//任意顶点之间最短路径的顶点顺序
void OutvexInPath_Floyd(const int& i, const int& j, int(*Path)[Mvnum], const AMGraph& G)
{
	if (Path[i][j] == -1)
	{
		cout << G.vexs[i];
	}
	else
	{
		OutvexInPath_Floyd(i, Path[i][j], Path, G);
		cout << "->" << G.vexs[j];
	}
}

//输出任意顶点之间的最短路径
void OutshortestPath_Floyd(const AMGraph& G, int(*D)[Mvnum], int(*Path)[Mvnum])
{
	cout << "任意两顶点之间的最短路径如下:>" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			if (i == j)
				continue;
			if (Path[i][j] == -1)
			{
				cout << "<" << G.vexs[i] << "," << G.vexs[j] << ">" << "无路可通!!!" << endl;
			}
			else
			{
				cout << "顶点" << G.vexs[i] << "到顶点";
				cout << G.vexs[j] << "的最短路径为:>" << D[i][j] << endl;
				//源点为vi,终点为vj
				OutvexInPath_Floyd(i, j, Path, G);
				cout << endl;
			}
		}
	}
}

//弗洛伊德算法
void ShortestPath_Floyd(const AMGraph& G)
{
	//辅助数组

	//1.任意两个顶点之间最短路径的状态数组
	//或者写为ArcType D[Mvnum][Mvnum] = { 0 };
	int D[Mvnum][Mvnum] = { 0 };
	//2.存储在当前的最短路径<vi,vj>中，顶点vj的直接前驱顶点下标为Path[i][j]
	int Path[Mvnum][Mvnum] = { 0 };

	//初始化函数
	Init_Floyd(G, D, Path);

	//将下标为k的顶点作为试探中转点
	for (int k = 0;k < G.vexnum;k++)
	{
		for (int i = 0;i < G.vexnum;i++)
		{
			for (int j = 0;j < G.vexnum;j++)
			{
				if (D[i][j] > D[i][k] + D[k][j])
				{
					//更新弧<vi,vi>的最短路径
					D[i][j] = D[i][k] + D[k][j];
					//更新在最短路径<vi,vj>中，vj的直接前驱结点
					//因为如今<vi,vj>的路径由路径<vi,vk>与<vk,vj>组成
					//因此vj在<vi,vj>中的直接前驱等同于vj在<vk,vj>的直接前驱
					Path[i][j] = Path[k][j];
				}
			}
		}
	}
	//输出任意顶点之间的最短路径
	OutshortestPath_Floyd(G, D, Path);
}