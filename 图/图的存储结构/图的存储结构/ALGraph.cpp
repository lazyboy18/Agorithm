#include"ALGraph.h"

//����һ���ڽӱ�(�������ͼ)
void CreateUDNal(ALGraph& G)
{
	//������Ҫ�����Ķ���vexnum�����arcnum
	cout << "�����붥�����Լ�����:>" << endl;
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > Maxvex || G.arcnum > (G.vexnum - 1) * G.vexnum / 2)
	{
		cout << "fail Create" << endl;
		return;
	}
	//���붥������������ݲ��ҽ�ָ�����ÿ�
	cout << "������" << G.vexnum << "�������������:>";
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].fisrtarc = NULL;
	}
	//���Ӹ������㣬����ߵ�Ȩֵ�Լ��ߵ�ָ�򶥵���Ϣ
	for (int i = 0;i < G.arcnum;i++)
	{
		int v1, v2, w;
		cout << "�����붥��v1��v2���Լ�(v1,v2)��Ȩֵ:>" << endl;
		cin >> v1 >> v2 >> w;
		if (v1 > Maxvex || v2 > Maxvex || w > Maxw)
		{
			i--;
			cout << "���������������������룡" << endl;
			continue;
		}
		//����v1��v2�ıߣ��������Ƹñߵ���Ϣ
		ArcNode* p1 = new ArcNode;
		p1->adjvex = v2;
		p1->info = w;
		//ע���Ŵ�0��ʼ
		p1->nextarc = G.vertices[v1-1].fisrtarc;
		G.vertices[v1-1].fisrtarc = p1;
		//����v2��v1�ıߣ��������Ƹñߵ���Ϣ
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
	cout << "ɾ���ɹ�!" << endl;
	p = NULL;
}

//ɾ�����ڽӱ�(�е��Ѷ�)
void DelUDNal(ALGraph& G)
{
	for (int i = 0;i < G.vexnum;i++)
	{
		DelAlg(G.vertices[i].fisrtarc);
	}
}