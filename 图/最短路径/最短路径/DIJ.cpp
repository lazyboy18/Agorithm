#include"DIJ.h"

//inf��ʾ�������û����·������Ϊ�����
int inf = 99999999;

//���������ʼ������
void Init(const AMGraph& G, int* Path, int* shortestDis, const int& v ,bool*S)
{
	//���<v,vi>֮���л�����ôvi��ֱ��ǰ��Ϊv
	for (int i = 0;i < G.vexnum;i++)
	{
		if (inf != G.arcs[v][i])
			Path[i] = v;
		else
			Path[i] = -1;
	}
	//��ʼ��Դ�㵽��������֮������·��
	for (int i = 0;i < G.vexnum;i++)
	{
		shortestDis[i] = G.arcs[v][i];
	}
	//v��Ȼ�����·��Դ�㼯��
	S[v] = true;
}


//����ĳԴ�㵽�������ж�������·��
int findmin(const int* shortestDis, const bool* S,const int&n)
{
	int k = 0;
	int minroad = inf;
	for (int i = 0;i < n;i++)
	{
		if (!S[i])
		{
			if (minroad > shortestDis[i])
			{
				k = i;
				minroad = shortestDis[i];
			}
		}
	}
	return k;
}


//�����·���ϵĶ���
void OutvexInpath(const int& v, const int& i, const int* Path, const AMGraph& G)
{
	//���ҵ�Դ��vΪֹ
	if (i == v)
	{
		cout << G.vexs[v];
	}
	else
	{
		//�����±�Ϊi�Ķ����ֱ��ǰ��
		OutvexInpath(v, Path[i], Path, G);
		cout << "->" << G.vexs[i];
	}

}

//�������£�������·����
void OutshortestPath(const int& v, const int* shortestDis, const int* Path, const AMGraph& G)
{
	cout << "���·���������:>" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		cout << "�Ӷ���" << G.vexs[v] << "������" << G.vexs[i] << "�����·��Ϊ" << shortestDis[i] << endl;
		//�����·���ϵĶ���
		cout << "��·������:>" << endl;
		OutvexInpath(v, i, Path, G);
		//�������
		cout << endl;
	}
}

//���ڽӾ�����Ϊ�洢�ṹ
void ShortestPath_DIJ(const AMGraph& G, const int& v)
{
	//�ж��±�ĺϷ���
	if (v > G.vexnum || v < 0)
	{
		return;
	}
	//���ȶ��帨������
	//1.��¼�ö����Ƿ��Ѿ��������·���յ㼯��
	bool S[Mvnum] = { 0 };	
	//2.��¼Դ��v0���յ�vi�����·���ϣ�vi��ֱ��ǰ���������ڽӾ����е��±�
	int Path[Mvnum] = { 0 };
	//3.��¼��ǰԴ�㵽�����յ�����·��
	int shortestDis[Mvnum] = { 0 };
	Init(G, Path, shortestDis, v, S);
	//�������Ķ������
	int n = G.vexnum;
	//������n-1��������뵽S��
	for (int i = 1;i < n;i++)
	{
		//Ѱ�ҵ�ǰԴ�㵽û����S���еĶ�������·��(v,vk)
		//���ҷ������±�k
		int k = findmin(shortestDis, S, n);
		//��k�±���뵽S��
		S[k] = true;
		//ͨ������ת�㡱k,�������·��
		for (int j = 0;j < n;j++)
		{
			if (!S[j])
			{
				//��Ҫ�õ�<v,k>������������Ϊ�ж�����
				if (shortestDis[j] > shortestDis[k] + G.arcs[k][j])
				{
					//�������·��
					shortestDis[j] = shortestDis[k] + G.arcs[k][j];
					//����j��ֱ��ǰ��Ϊk
					Path[j] = k;
				}
			}
		}
	}
	//�������£�������·����
	OutshortestPath(v, shortestDis, Path, G);
}

//���������Ż��ĵط�Ϊ������G,Path,Shortest,S�Ĵ洢�ṹΪȫ�ֱ���
//�Ӷ����ٺ�������