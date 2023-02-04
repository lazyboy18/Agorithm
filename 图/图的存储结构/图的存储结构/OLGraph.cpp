#include"OLGraph.h"

void CreateUDNol(OLGraph& G)
{
	//���������ȷ���������뻡��
	cout << "���붥������Լ�����:>" << endl;
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > Maxvex || G.arcnum > (G.vexnum - 1) * G.vexnum)
	{
		cout << "��������" << endl;
		return;
	}
	//���������ݳ�ʼ��,���붥������
	cout << "������" << G.vexnum << "�������������:>";
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.xlist[i].data;
		G.xlist[i].firstin = G.xlist[i].firstout = NULL;
	}
	//����ߵ����ݣ�����Ƚ���Լ�Ȩֵ�����ӽ��
	for (int i = 0;i < G.arcnum;i++)
	{
		cout << "������<v1,v2>�еĶ���v1��v2�Լ���·����Ȩֵw:>" << endl;
		//����Ѱ��v1��v2
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		if (v1 > G.vexnum || v2 > G.vexnum || w > Maxw||v1<1||v2<1)
		{
			i--;
			cout << "��������,���������룡" << endl;
			continue;
		}
		ArcBox* p = new ArcBox;
		p->headvex = v2;   //v2�Ǹû���ͷ���
		p->tailvex = v1;   //v1�Ǹû���β���
		p->w = w;
		//����p��������ͬ���ȵ�Ļ����
		p->tlink = G.xlist[v1 - 1].firstout;
		G.xlist[v1 - 1].firstout = p;
		//����p��������ͬ��ȵ�Ļ����
		p->hlink = G.xlist[v2 - 1].firstout;
		G.xlist[v2 - 1].firstout = p;
	}
}