//#include"AMGraph.h"
#include"ALGraph.h"
#include"OLGraph.h"

//void test01()
//{
//	//创建一个图并且销毁
//	AMGraph G;
//	CreateUDN(G);
//	DelUDM(G);
//}
//void test02()
//{
//	AMGraphs G;
//	CreateUDNs(G);
//	//遍历各个顶点
//	for (int i = 0;i < G.vexnum;i++)
//	{
//		cout << G.vexs[i] << endl;
//	}
//	for (int i = 0;i < G.arcnum;i++)
//	{
//		cout << G.arcs[i] << " ";
//	}
//	cout << endl;
//}

//创建邻接表（无向网）
void test03()
{
	ALGraph G;
	CreateUDNal(G);
	DelUDNal(G);
}

void test04()
{
	OLGraph G;
	CreateUDNol(G);
}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}

