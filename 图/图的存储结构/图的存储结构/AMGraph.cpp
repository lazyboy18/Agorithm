#include"AMGraph.h"
//非压缩矩阵
//创建无向网
void CreateUDN(AMGraph& G)
{
	//输入顶点个数以及边数
	cout << "输入顶点个数以及边数:>" << endl;
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > MVNum)
	{
		cout << "超出顶点的最大个数!!!" << endl;
		return;
	}
	//动态创建数组
	G.vexs = new VerTexType[G.vexnum];
	//输入各个顶点之间的信息
	cout << "输入各个路口的车流量:>" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
		G.vexs[i] = "该路口的车流量为:" + G.vexs[i];
	}
	//创建动态数组
	G.arcs = new ArcType* [G.vexnum];
	for (int i = 0;i < G.vexnum;i++)
	{
		G.arcs[i] = new ArcType[G.vexnum];
	}
	//初始化权值
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	//判断合法性
	for (int k = 0;k < G.arcnum;k++)
	{
		//输入边的信息
		cout << "输入v1到v2的权值:>" << endl;
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		if (v1 == v2 || v1 > G.vexnum || v2 > G.vexnum)
		{
			k--;
			continue;
		}
		if(w > MaxInt || G.arcs[v1-1][v2-1] != MaxInt)
		{
			k--;
			continue;
		}
		//编译器太太聪明了
		G.arcs[v1-1][v2-1] = G.arcs[v2-1][v1-1] = w;
	}
}
//删除该图
void DelUDM(AMGraph& G)
{
	delete[]G.vexs;
	for (int i = 0;i < G.vexnum;i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
}
//压缩矩阵

void CreateUDNs(AMGraphs& G)
{
	cout << "输入顶点个数以及边数:>" << endl;
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > MVNum)
	{
		return;
	}
	G.vexs = new VerTexType[G.vexnum];
	cout << "输入各个路口的车流量:>" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
		G.vexs[i] = "该路口的车流量为:" + G.vexs[i];
	}
	G.arcs = new ArcType[G.vexnum * (G.vexnum - 1) / 2];
	//c初始化
	for (int k = 0;k < G.vexnum * (G.vexnum - 1) / 2;k++)
		G.arcs[k] = MaxInt;
	for (int k = 0;k < G.arcnum;k++)
	{
		//输入边的信息
		cout << "输入v1到v2的权值:>" << endl;
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		int loc = 0;
		if (v1 > v2&&v1<=G.vexnum)
		{
			loc = (v2 - 1) * (2 * G.vexnum - v2) / 2 + v1 - v2 - 1;
		}
		else if (v1 < v2 && v2 <= G.vexnum)
		{
			loc = (v1 - 1) * (2 * G.vexnum - v1) / 2 + v2 - v1 - 1;
		}
		else
		{
			k--;
			continue;
		}
		G.arcs[loc] = w;
	}
}

void DelUDMs(AMGraphs& G)
{
	delete[]G.arcs;
	delete[]G.vexs;
}