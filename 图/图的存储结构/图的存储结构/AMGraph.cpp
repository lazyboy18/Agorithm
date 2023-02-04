#include"AMGraph.h"
//��ѹ������
//����������
void CreateUDN(AMGraph& G)
{
	//���붥������Լ�����
	cout << "���붥������Լ�����:>" << endl;
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > MVNum)
	{
		cout << "���������������!!!" << endl;
		return;
	}
	//��̬��������
	G.vexs = new VerTexType[G.vexnum];
	//�����������֮�����Ϣ
	cout << "�������·�ڵĳ�����:>" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
		G.vexs[i] = "��·�ڵĳ�����Ϊ:" + G.vexs[i];
	}
	//������̬����
	G.arcs = new ArcType* [G.vexnum];
	for (int i = 0;i < G.vexnum;i++)
	{
		G.arcs[i] = new ArcType[G.vexnum];
	}
	//��ʼ��Ȩֵ
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	//�жϺϷ���
	for (int k = 0;k < G.arcnum;k++)
	{
		//����ߵ���Ϣ
		cout << "����v1��v2��Ȩֵ:>" << endl;
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		if (v1 == v2 || v1 > G.vexnum || v2 > G.vexnum)
		{
			k--;
			continue;
		}
		if(w > MaxInt || G.arcs[v1-1][v2-1] != MaxInt)
		{
			k--;
			continue;
		}
		//������̫̫������
		G.arcs[v1-1][v2-1] = G.arcs[v2-1][v1-1] = w;
	}
}
//ɾ����ͼ
void DelUDM(AMGraph& G)
{
	delete[]G.vexs;
	for (int i = 0;i < G.vexnum;i++)
	{
		delete[]G.arcs[i];
	}
	delete[]G.arcs;
}
//ѹ������

void CreateUDNs(AMGraphs& G)
{
	cout << "���붥������Լ�����:>" << endl;
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > MVNum)
	{
		return;
	}
	G.vexs = new VerTexType[G.vexnum];
	cout << "�������·�ڵĳ�����:>" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
		G.vexs[i] = "��·�ڵĳ�����Ϊ:" + G.vexs[i];
	}
	G.arcs = new ArcType[G.vexnum * (G.vexnum - 1) / 2];
	//c��ʼ��
	for (int k = 0;k < G.vexnum * (G.vexnum - 1) / 2;k++)
		G.arcs[k] = MaxInt;
	for (int k = 0;k < G.arcnum;k++)
	{
		//����ߵ���Ϣ
		cout << "����v1��v2��Ȩֵ:>" << endl;
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		int loc = 0;
		if (v1 > v2&&v1<=G.vexnum)
		{
			loc = (v2 - 1) * (2 * G.vexnum - v2) / 2 + v1 - v2 - 1;
		}
		else if (v1 < v2 && v2 <= G.vexnum)
		{
			loc = (v1 - 1) * (2 * G.vexnum - v1) / 2 + v2 - v1 - 1;
		}
		else
		{
			k--;
			continue;
		}
		G.arcs[loc] = w;
	}
}

void DelUDMs(AMGraphs& G)
{
	delete[]G.arcs;
	delete[]G.vexs;
}