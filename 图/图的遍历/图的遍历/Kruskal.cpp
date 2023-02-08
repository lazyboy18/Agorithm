#include"Kruskal.h"

//ע������������Ϊ��ͨ�����������ɸ�ƨ

//����������ʼ��
void edgeInit(const ALGraph& G, edge* Assistarr)
{
	int pos = 0;
	//��G�����бߵķŽ�����������
	//ʱ�临�Ӷ�:O(e)
	for (int i = 0;i < G.vexnum;i++)
	{
		//�ߵ����鶼��p����
		ArcNode* p = G.vertices[i].fisrtarc;
		while (p)
		{
			//���ڽӱ�洢������ʱ����Ҫ�������ͷ�뻡β
			//˵���б߿���
			Assistarr[pos].head = G.vertices[p->adjvex].data;
			Assistarr[pos].tail = G.vertices[i].data;
			Assistarr[pos].lowcost = p->info;
			pos++;
			p = p->nextarc;
		}
	}
}

//������
void edgeSort(edge* Assistarr,const int& length)
{
	int flag = 0;
	for (int i = 0;i < length - 1 ;i++)
	{
		//���ϴ��Ԫ�ط��ں���
		for (int j = 0;j < length - 1 - i;j++)
		{
			if (Assistarr[j].lowcost > Assistarr[j + 1].lowcost)
			{
				//������Ԫ�ؽ���
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

//��ʼ��setvex
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

//�ÿ�³˹�����㷨������С������
void MiniSpanTree_Kruaskal(const ALGraph& G)
{
	//���帨�����飬�洢ͼ�ıߣ���������
	edge Assistarr[Marc];
	//��ʼ����������,�����СΪarcnum
	edgeInit(G, Assistarr);
	//����������
	edgeSort(Assistarr, 2*G.arcnum);
	int setvex[Mvnum] = { 0 };
	setvexInit(setvex, G.vexnum);

	//������С������
	int pos = 0;
	for (int i = 1;i < G.vexnum;i++)
	{
		//ÿһ��ѭ��������һ���µ�·��
		VexType head = Assistarr[pos].head;
		VexType tail = Assistarr[pos].tail;
		//���ж������������Ƿ�����
		//��������������±�
		int h = LocateVex(G, head);
		int t = LocateVex(G, tail);

		//�ж����������Ƿ�ͬ��һ����ͨ��������
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

