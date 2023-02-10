#include"AMGraph.h"

//用邻接矩阵创建有向网
void CreateUDN(AMGraph& G)
{
	//inf表示两顶点间没有线路，距离为无穷大
	int inf = 99999999;
	//输入顶点与弧的个数
	cin >> G.vexnum >> G.arcnum;
	//判断合法性
	if (G.vexnum > Mvnum || G.arcnum > (G.vexnum - 1) * G.vexnum)
	{
		cout << "所输入信息非法" << endl;
		return;
	}
	//输入顶点的信息，类型为char
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
	}
	//将图的边初始化
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			if (i != j)
				G.arcs[i][j] = inf;
			else
				G.arcs[i][j] = 0;
		}
	}
	//输入权值
	for (int i = 0;i < G.arcnum;i++)
	{
		//输入v1,v2作为弧<v1,v2>的顶点以及该弧权值w
		//顶点下标从0开始
		int v1, v2, w;
		//此处省略了查找v1,v2编号的过程
		cin >> v1 >> v2 >> w;
		//判断合法性
		if (v1 == v2 || v1 >= G.vexnum || v2 >= G.vexnum
			|| v1 < 0 || v2 < 0)
		{
			i--;
			continue;
		}
		if (G.arcs[v1][v2] != inf)
		{
			i--;
			continue;
		}
		//输入弧<v1,v2>的权值
		G.arcs[v1][v2] = w;
	}
	//创建完毕
}


