#include"prim.h"

//��������
closedge Assistarr[Mvnum];

//�����±꺯��
int LocateVex(const AMGraph& G, VerType u)
{
	for (int i = 0;i < G.vexnum;i++)
	{
		if (G.vexs[i] == u)
			return i;
	}
	//��ʾû���ҵ���һ�㶼��������������
	return -1;
}

//��Ȩֵ��С�ߣ��������ڸ��������е��±�
int Findminarc(const AMGraph& G, const closedge*Assistarr)
{
	int mark = 999999999;
	int k = 0;
	for (int i = 0;i < G.vexnum;i++)
	{
		//�ų��Ѿ���U�еĶ��㣬�ö����±�Ϊi
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

//ʵ������ķ�㷨�������ͨͼ����
void MiniSpanTree_Prim(const AMGraph& G, VerType u)
{
	//���ҵ�u���±꣬����Assistarr���������
	int k = LocateVex(G, u);
	if (k == -1)
	{
		cout << "���㲻����" << endl;
		return;
	}
	//����Assistarr����
	for (int i = 0;i < G.vexnum;i++)
	{
		if (i != k)
		{
			//��С��(u0,v0)��U�ϵĶ��������Ϊu
			Assistarr[i].adject = u;
			//��С�ߵ�Ȩֵ�����Ϊ(u,v0)
			Assistarr[i].lowcost = G.arcs[k][i];
		}
	}
	//�涨�����Assistarr[i].lowcost ==0�����ʾ�±�Ϊi�Ķ���
	//�Ѿ���U��
	//����uһ��ʼ���������У���Assistarr[k].lowest = 0;
	Assistarr[k].lowcost = 0;
	//�����ţ���ʣ���n-1��������뵽U��
	for (int i = 1;i < G.vexnum;i++)
	{
		//�ҵ�Ȩֵ��С��(u,v),u��U�У�v��V-U�У����ֻ��Ҫ�Ż���С����
		//�����е��±�k
		int k = Findminarc(G,Assistarr);
		//��U�еĶ���
		VerType u0 = Assistarr[k].adject;
		//ͨ���±�k��vexs�������ҵ��䶥��ֵ
		VerType v0 = G.vexs[k];
		//��ӡ����u0������v0����ʾ��СȨֵ��(u0,v0)���뵽��U��
		cout << u0 << "->" << v0 << endl;
		//���±�Ϊk�Ķ�����뵽U��
		Assistarr[k].lowcost = 0;
		//������СȨֵ��
		for (int j = 0;j < G.vexnum;j++)
		{
			//G.arcs[k][j]��ʾ(k,j)��Ȩֵ��Assistarr[j].lowcost
			//��ʾĿǰU�еĶ��㵽V-U�±�Ϊj����СȨֵ
			if (G.arcs[k][j] < Assistarr[j].lowcost)
			{
				Assistarr[j].lowcost = G.arcs[k][j];
				Assistarr[j].adject = G.vexs[k];
			}
		}
	}
}