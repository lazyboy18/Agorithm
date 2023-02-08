#include"prim.h"

//辅助数组
closedge Assistarr[Mvnum];

//查找下标函数
int LocateVex(const AMGraph& G, VerType u)
{
	for (int i = 0;i < G.vexnum;i++)
	{
		if (G.vexs[i] == u)
			return i;
	}
	//表示没有找到，一般都不会出现这种情况
	return -1;
}

//找权值最小边，返回其在辅助数组中的下标
int Findminarc(const AMGraph& G, const closedge*Assistarr)
{
	int mark = 999999999;
	int k = 0;
	for (int i = 0;i < G.vexnum;i++)
	{
		//排除已经在U中的顶点，该顶点下标为i
		if (Assistarr[i].lowcost != 0)
		{
			if (mark > Assistarr[i].lowcost)
			{
				mark = Assistarr[i].lowcost;
				k = i;
			}
		}
	}
	return k;
}

//实现普里姆算法，针对连通图而言
void MiniSpanTree_Prim(const AMGraph& G, VerType u)
{
	//查找到u的下标，更新Assistarr数组的数据
	int k = LocateVex(G, u);
	if (k == -1)
	{
		cout << "顶点不存在" << endl;
		return;
	}
	//更新Assistarr数组
	for (int i = 0;i < G.vexnum;i++)
	{
		if (i != k)
		{
			//最小边(u0,v0)在U上的顶点最初都为u
			Assistarr[i].adject = u;
			//最小边的权值最初都为(u,v0)
			Assistarr[i].lowcost = G.arcs[k][i];
		}
	}
	//规定，如果Assistarr[i].lowcost ==0，则表示下标为i的顶点
	//已经在U中
	//顶点u一开始就在数组中，故Assistarr[k].lowest = 0;
	Assistarr[k].lowcost = 0;
	//紧接着，将剩余的n-1个顶点加入到U中
	for (int i = 1;i < G.vexnum;i++)
	{
		//找到权值最小边(u,v),u在U中，v在V-U中，因此只需要放回最小边在
		//数组中的下标k
		int k = Findminarc(G,Assistarr);
		//在U中的顶点
		VerType u0 = Assistarr[k].adject;
		//通过下标k在vexs数组中找到其顶点值
		VerType v0 = G.vexs[k];
		//打印顶点u0到顶点v0，表示最小权值边(u0,v0)加入到了U中
		cout << u0 << "->" << v0 << endl;
		//将下标为k的顶点加入到U中
		Assistarr[k].lowcost = 0;
		//更新最小权值边
		for (int j = 0;j < G.vexnum;j++)
		{
			//G.arcs[k][j]表示(k,j)的权值，Assistarr[j].lowcost
			//表示目前U中的顶点到V-U下标为j的最小权值
			if (G.arcs[k][j] < Assistarr[j].lowcost)
			{
				Assistarr[j].lowcost = G.arcs[k][j];
				Assistarr[j].adject = G.vexs[k];
			}
		}
	}
}