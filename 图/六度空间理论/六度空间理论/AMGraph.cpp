#include"AMGraph.h"

/*
	该无向图需要建立人与人之间的关系
	如果两人相识，那么彼此所代表的顶点间有双向路径
*/

bool is_friend(const int& p1, const int& p2, const ALGraph& G)
{
	//判断p1的联系人中是否有p2即可
	ArcNode* p = G.vertices[p1].fisrtarc;
	while (p)
	{
		if (p->adjvex == p2)
		{
			return true;
		}
		p = p->nextarc;
	}
	return false;
}

void CreateUDN(ALGraph& G)
{
	//输入人数以及这些之间有多少对相识
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > Maxvex || G.arcnum > (G.vexnum - 1) * G.vexnum/2)
	{
		cout << "fail Create" << endl;
		return;
	}
	for (int i = 0;i < G.vexnum;i++)
	{
		G.vertices[i].fisrtarc = NULL;
	}
	cout << "输入人的编号:>(从0开始)" << endl;
	for (int i = 0;i < G.arcnum;i++)
	{
		//输入G.arcnum次，表示有G.arcnum次
		int p1, p2;
		//表明p1与p2相识
		cin >> p1 >> p2;
		if (p1<0 || p1>G.vexnum-1 || p2<0 || p2>G.vexnum-1 || p1 == p2||is_friend(p1, p2, G))
		{
			cout << "重新输入" << endl;
			i--;
			continue;
		}
		//建立p1与p2的联系
		ArcNode* p = new ArcNode;
		p->adjvex = p2;
		p->nextarc = G.vertices[p1].fisrtarc;
		G.vertices[p1].fisrtarc = p;

		ArcNode* pp = new ArcNode;
		pp->adjvex = p1;
		pp->nextarc = G.vertices[p2].fisrtarc;
		G.vertices[p2].fisrtarc = pp;
	}
}



