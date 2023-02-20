#include"AMGraph.h"

/*
	������ͼ��Ҫ����������֮��Ĺ�ϵ
	���������ʶ����ô�˴�������Ķ������˫��·��
*/

bool is_friend(const int& p1, const int& p2, const ALGraph& G)
{
	//�ж�p1����ϵ�����Ƿ���p2����
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
	//���������Լ���Щ֮���ж��ٶ���ʶ
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
	cout << "�����˵ı��:>(��0��ʼ)" << endl;
	for (int i = 0;i < G.arcnum;i++)
	{
		//����G.arcnum�Σ���ʾ��G.arcnum��
		int p1, p2;
		//����p1��p2��ʶ
		cin >> p1 >> p2;
		if (p1<0 || p1>G.vexnum-1 || p2<0 || p2>G.vexnum-1 || p1 == p2||is_friend(p1, p2, G))
		{
			cout << "��������" << endl;
			i--;
			continue;
		}
		//����p1��p2����ϵ
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



