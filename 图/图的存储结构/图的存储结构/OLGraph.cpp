#include"OLGraph.h"

void CreateUDNol(OLGraph& G)
{
	//常规操作，确定顶点数与弧数
	cout << "输入顶点个数以及弧数:>" << endl;
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > Maxvex || G.arcnum > (G.vexnum - 1) * G.vexnum)
	{
		cout << "数据有误" << endl;
		return;
	}
	//将顶点数据初始化,输入顶点数据
	cout << "请输入" << G.vexnum << "个顶点的数据域:>";
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.xlist[i].data;
		G.xlist[i].firstin = G.xlist[i].firstout = NULL;
	}
	//输入边的数据，出入度结点以及权值并连接结点
	for (int i = 0;i < G.arcnum;i++)
	{
		cout << "请输入<v1,v2>中的顶点v1、v2以及该路径的权值w:>" << endl;
		//无需寻找v1与v2
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		if (v1 > G.vexnum || v2 > G.vexnum || w > Maxw||v1<1||v2<1)
		{
			i--;
			cout << "数据有误,请重新输入！" << endl;
			continue;
		}
		ArcBox* p = new ArcBox;
		p->headvex = v2;   //v2是该弧的头结点
		p->tailvex = v1;   //v1是该弧的尾结点
		p->w = w;
		//连接p与其有相同出度点的弧结点
		p->tlink = G.xlist[v1 - 1].firstout;
		G.xlist[v1 - 1].firstout = p;
		//连接p与其有相同入度点的弧结点
		p->hlink = G.xlist[v2 - 1].firstout;
		G.xlist[v2 - 1].firstout = p;
	}
}