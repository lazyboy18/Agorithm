//#include"AMGraph.h"
#include"ALGraph.h"
#include"OLGraph.h"

//void test01()
//{
//	//����һ��ͼ��������
//	AMGraph G;
//	CreateUDN(G);
//	DelUDM(G);
//}
//void test02()
//{
//	AMGraphs G;
//	CreateUDNs(G);
//	//������������
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

//�����ڽӱ���������
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

