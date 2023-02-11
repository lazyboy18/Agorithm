#include"Floyd.h"

//inf��ʾ�������û����·������Ϊ�����
int infs = 99999999;
//��ʼ������
void Init_Floyd(const AMGraph& G, int(*D)[Mvnum], int(*Path)[Mvnum])
{
	//D�ĳ�ʼ״̬ΪG.arcs[Mvnum][Mvnum]
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			D[i][j] = G.arcs[i][j];
		}
	}
	//��ʼ��Path������<vi,vj>֮�仡����vj��ֱ��ǰ��Ϊvi,����Ϊ-1
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			if (G.arcs[i][j] != infs && i != j)
				Path[i][j] = i;
			else
				Path[i][j] = -1;
		}
	}
}

//���ⶥ��֮�����·���Ķ���˳��
void OutvexInPath_Floyd(const int& i, const int& j, int(*Path)[Mvnum], const AMGraph& G)
{
	if (Path[i][j] == -1)
	{
		cout << G.vexs[i];
	}
	else
	{
		OutvexInPath_Floyd(i, Path[i][j], Path, G);
		cout << "->" << G.vexs[j];
	}
}

//������ⶥ��֮������·��
void OutshortestPath_Floyd(const AMGraph& G, int(*D)[Mvnum], int(*Path)[Mvnum])
{
	cout << "����������֮������·������:>" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			if (i == j)
				continue;
			if (Path[i][j] == -1)
			{
				cout << "<" << G.vexs[i] << "," << G.vexs[j] << ">" << "��·��ͨ!!!" << endl;
			}
			else
			{
				cout << "����" << G.vexs[i] << "������";
				cout << G.vexs[j] << "�����·��Ϊ:>" << D[i][j] << endl;
				//Դ��Ϊvi,�յ�Ϊvj
				OutvexInPath_Floyd(i, j, Path, G);
				cout << endl;
			}
		}
	}
}

//���������㷨
void ShortestPath_Floyd(const AMGraph& G)
{
	//��������

	//1.������������֮�����·����״̬����
	//����дΪArcType D[Mvnum][Mvnum] = { 0 };
	int D[Mvnum][Mvnum] = { 0 };
	//2.�洢�ڵ�ǰ�����·��<vi,vj>�У�����vj��ֱ��ǰ�������±�ΪPath[i][j]
	int Path[Mvnum][Mvnum] = { 0 };

	//��ʼ������
	Init_Floyd(G, D, Path);

	//���±�Ϊk�Ķ�����Ϊ��̽��ת��
	for (int k = 0;k < G.vexnum;k++)
	{
		for (int i = 0;i < G.vexnum;i++)
		{
			for (int j = 0;j < G.vexnum;j++)
			{
				if (D[i][j] > D[i][k] + D[k][j])
				{
					//���»�<vi,vi>�����·��
					D[i][j] = D[i][k] + D[k][j];
					//���������·��<vi,vj>�У�vj��ֱ��ǰ�����
					//��Ϊ���<vi,vj>��·����·��<vi,vk>��<vk,vj>���
					//���vj��<vi,vj>�е�ֱ��ǰ����ͬ��vj��<vk,vj>��ֱ��ǰ��
					Path[i][j] = Path[k][j];
				}
			}
		}
	}
	//������ⶥ��֮������·��
	OutshortestPath_Floyd(G, D, Path);
}