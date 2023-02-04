#include"ALGraph.h"

//创建一个邻接表(针对无向图)
void CreateUDNal(ALGraph& G)
{
	//首先需要输入表的顶点vexnum与边数arcnum
	cout << "请输入顶点数以及弧数:>" << endl;
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > Maxvex || G.arcnum > (G.vexnum - 1) * G.vexnum / 2)
	{
		cout << "fail Create" << endl;
		return;
	}
	//输入顶点数据域的数据并且将指针域置空
	cout << "请输入" << G.vexnum << "个顶点的数据域:>";
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].fisrtarc = NULL;
	}
	//连接各个顶点，输入边的权值以及边的指向顶点信息
	for (int i = 0;i < G.arcnum;i++)
	{
		int v1, v2, w;
		cout << "请输入顶点v1与v2，以及(v1,v2)的权值:>" << endl;
		cin >> v1 >> v2 >> w;
		if (v1 > Maxvex || v2 > Maxvex || w > Maxw)
		{
			i--;
			cout << "数据输入有误，请重新输入！" << endl;
			continue;
		}
		//连接v1到v2的边，并且完善该边的信息
		ArcNode* p1 = new ArcNode;
		p1->adjvex = v2;
		p1->info = w;
		//注意编号从0开始
		p1->nextarc = G.vertices[v1-1].fisrtarc;
		G.vertices[v1-1].fisrtarc = p1;
		//连接v2到v1的边，并且完善该边的信息
		ArcNode* p2 = new ArcNode;
		p2->adjvex = v1;
		p2->info = w;
		p2->nextarc = G.vertices[v2 - 1].fisrtarc;
		G.vertices[v2 - 1].fisrtarc = p2;
	}
}

void DelAlg(ArcNode*& p)
{
	if (p == NULL)
	{
		return;
	}
	DelAlg(p->nextarc);
	delete p;
	cout << "删除成功!" << endl;
	p = NULL;
}

//删除该邻接表(有点难度)
void DelUDNal(ALGraph& G)
{
	for (int i = 0;i < G.vexnum;i++)
	{
		DelAlg(G.vertices[i].fisrtarc);
	}
}