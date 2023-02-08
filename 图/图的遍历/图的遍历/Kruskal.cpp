#include"Kruskal.h"

//注意操作对象必须为连通网，否则生成个屁

//辅助函数初始化
void edgeInit(const ALGraph& G, edge* Assistarr)
{
	int pos = 0;
	//将G的所有边的放进辅助数组中
	//时间复杂度:O(e)
	for (int i = 0;i < G.vexnum;i++)
	{
		//边的数组都在p里面
		ArcNode* p = G.vertices[i].fisrtarc;
		while (p)
		{
			//铛邻接表存储有向网时，需要分清楚弧头与弧尾
			//说明有边可入
			Assistarr[pos].head = G.vertices[p->adjvex].data;
			Assistarr[pos].tail = G.vertices[i].data;
			Assistarr[pos].lowcost = p->info;
			pos++;
			p = p->nextarc;
		}
	}
}

//排序函数
void edgeSort(edge* Assistarr,const int& length)
{
	int flag = 0;
	for (int i = 0;i < length - 1 ;i++)
	{
		//将较大的元素放在后面
		for (int j = 0;j < length - 1 - i;j++)
		{
			if (Assistarr[j].lowcost > Assistarr[j + 1].lowcost)
			{
				//将两个元素交换
				edge t = Assistarr[j];
				Assistarr[j] = Assistarr[j + 1];
				Assistarr[j + 1] = t;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

//初始化setvex
void setvexInit(int* setvex, const int& length)
{
	for (int i = 0;i < length;i++)
	{
		setvex[i] = i;
	}
}

int LocateVex(const ALGraph& G, const VexType& v)
{
	for (int i = 0;i < G.vexnum;i++)
	{
		if (G.vertices[i].data == v)
			return i;
	}
}

//用克鲁斯卡尔算法生成最小生成树
void MiniSpanTree_Kruaskal(const ALGraph& G)
{
	//定义辅助数组，存储图的边，并且排序
	edge Assistarr[Marc];
	//初始化辅助数组,数组大小为arcnum
	edgeInit(G, Assistarr);
	//将数组排序
	edgeSort(Assistarr, 2*G.arcnum);
	int setvex[Mvnum] = { 0 };
	setvexInit(setvex, G.vexnum);

	//生成最小生成树
	int pos = 0;
	for (int i = 1;i < G.vexnum;i++)
	{
		//每一次循环都加入一条新的路径
		VexType head = Assistarr[pos].head;
		VexType tail = Assistarr[pos].tail;
		//先判断这两个顶点是否相连
		//找这两个顶点的下标
		int h = LocateVex(G, head);
		int t = LocateVex(G, tail);

		//判断两个顶点是否同在一个连通分量里面
		if (setvex[h] != setvex[t])
		{
			cout << G.vertices[h].data << "->" << G.vertices[t].data << endl;
		}
		else
		{
			pos++;
			i--;
			continue;
		}
		int s = setvex[t];
		for (int k = 0;k < G.vexnum;k++)
		{
			if (setvex[k] == s)
			{
				setvex[k] = setvex[h];
			}
		}
		pos++;
	}
}

