#include"DFS.h"
//��Ǹö����Ƿ񱻷��ʹ�
bool visited[Mvnum];
//���ڽӾ��󴴽�������
void CreateUDN(AMGraph& G)
{
	//���붥����ߵĸ�����ͼ�ĵ�һ������Ϣ
	cin >> G.vexnum >> G.arcnum;
	//�жϺϷ���
	if (G.vexnum > Mvnum || G.arcnum > (G.vexnum - 1) * G.vexnum / 2)
	{
		cout << "��������Ϣ�Ƿ�" << endl;
		return;
	}
	//���������붥�����Ϣ,ͼ�ĵڶ�������Ϣ
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
	}
	//��ͼ�ı߳�ʼ��,Ȩֵȫ����Ϊ0
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
			G.arcs[i][j] = 0;
	}
	//����Ȩֵ
	for (int i = 0;i < G.arcnum;i++)
	{
		//����v1,v2��Ϊ��(v1,v2)�Ķ����Լ���֮���Ȩֵw
		//��Ŵ�0��ʼ
		int v1, v2, w;
		//�˴�ʡ���˲���v1,v2��ŵĹ���
		cin >> v1 >> v2 >> w;
		//ʱ�̹�ע�Ϸ���
		if (v1 == v2 || v1 >= G.vexnum || v2 >= G.vexnum
			|| w > Maxw || v1 < 0 || v2 < 0)
		{
			i--;
			continue;
		}
		if (G.arcs[v1][v2] != 0)
		{
			i--;
			continue;
		}
		//����ߵ�Ȩֵ
		G.arcs[v1][v2] = G.arcs[v2][v1] = w;
	}
	//�������
}

//��ȱ�������
void DFS_AM(AMGraph& G, int v)
{
	if (visited[v])
	{
		return;
	}
	//�����ڽӾ�������ڽӵ���ڼ򵥣������ٶ���Firstvex��Nextvex
	//����v��㣬�����������
	cout << "������Ϊ��" << v << "  ����������" << G.vexs[v] << endl;
	//����Ǹö���
	visited[v] = true;
	for (int i = 0;i < G.vexnum;i++)
	{
		//������v�໥��ͨ�Ķ���
		if (G.arcs[v][i] != 0 && !visited[i])
		{
			DFS_AM(G, i);
		}
	}
}

//��������ͨͼ
void DFS_AMFORALL(AMGraph& G)
{
	for (int i = 0;i < G.vexnum;i++)
	{
		DFS_AM(G, i);
	}
}


//���ڽӱ�Ϊ�洢�ṹ
void CreateUDNal(ALGraph& G)
{
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > Mvnum || G.arcnum > (G.vexnum - 1) * G.vexnum / 2)
	{
		return;
	}
	//���붥������������ݲ��ҽ�ָ�����ÿ�
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].fisrtarc = NULL;
	}
	//���Ӹ������㣬����ߵ�Ȩֵ�Լ��ߵ�ָ�򶥵���Ϣ
	for (int i = 0;i < G.arcnum;i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		if (v1 >= Mvnum || v2 >= Mvnum || w > Maxw)
		{
			i--;
			continue;
		}
		//����v1��v2�ıߣ��������Ƹñߵ���Ϣ
		ArcNode* p1 = new ArcNode;
		p1->adjvex = v2;
		p1->info = w;
		//ע���Ŵ�0��ʼ
		p1->nextarc = G.vertices[v1].fisrtarc;
		G.vertices[v1].fisrtarc = p1;
		//����v2��v1�ıߣ��������Ƹñߵ���Ϣ
		ArcNode* p2 = new ArcNode;
		p2->adjvex = v1;
		p2->info = w;
		p2->nextarc = G.vertices[v2].fisrtarc;
		G.vertices[v2].fisrtarc = p2;
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

//�����������
void DFS_AL(ALGraph& G, int v)
{
	if (visited[v])
	{
		return;
	}
	visited[v] = true;
	//����ö�������������
	cout << "�ö����ţ�" << v << " " << "�ö����������" << G.vertices[v].data << endl;

	//�����붥��v�໥��ͨ����û�б����ʹ��Ķ���
	ArcNode* p = G.vertices[v].fisrtarc;

	//pָ��v����һ����
	while (p)
	{
		//iΪ��v����ͨ�ĵ�
		int i = p->adjvex;
		if (!visited[i])
		{
			DFS_AL(G, i);
		}
		p = p->nextarc;
	}
}

//��������ͨͼ
void DFS_ALFORALL(ALGraph& G)
{
	//��0��ʼ
	for (int i = 0;i < G.vexnum;i++)
	{
		DFS_AL(G, i);
	}
}

//���к���ʵ��
//��ʼ��
void ALQueinit(ALQue& Q)
{
	Q.maxsize = Mvnum;
	Q.front = Q.rear = 0;
}
//�ж��Ƿ�Ϊ��
bool is_emptys(const ALQue& Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
//�ж��Ƿ�Ϊ��
bool is_full(const ALQue& Q)
{
	if ((Q.rear + 1) % Q.maxsize == Q.front)
	{
		cout << "��������" << endl;
		return true;
	}
	else
		return false;
}
//���,���践��ֵ
void ALQ_Push(ALQue& Q, const int& v)
{
	//vΪ�±�
	if (is_full(Q))
	{
		return;
	}
	Q.Que[Q.rear] = v;
	Q.rear = (Q.rear + 1) % Q.maxsize;
}
//����
void ALQ_Pop(ALQue& Q, int& w)
{
	if (is_emptys(Q))
	{
		return;
	}
	Q.rear--;
	w = Q.Que[Q.rear];
}
//���к���ʵ��

//�����������
void BFS_AL(ALGraph& G,const int v)
{
	//v�׷��ʶ���
	if (visited[v])
	{
		//�ڱ�������ͨͼʱ��Ҫ���ʶ������
		return;
	}
	ALQue Q;//��������
	ALQueinit(Q);
	//���ʸö��㲢�����������
	visited[v] = true;
	//�Ƚ�����v���,���ҽ������Ϊ�ѱ����ʵı�־
	ALQ_Push(Q, v);
	while (!is_emptys(Q))
	{
		int u;  //�洢������
		ALQ_Pop(Q, u);//����,������u�໥�ڽӵĶ������
		cout << "������Ϊ��" << u << " ��������" << G.vertices[u].data << endl;
		//���ǲ��ҹ��̵Ĵ������޴󣬷����������Һ������Ե��е����
		//for (w = FirstAdject(G, u);w >= 0;w = NextAdject(G, u, w));
		ArcNode* p = G.vertices[u].fisrtarc;
		while (p)
		{
			//��u���ڽӵ�Ļ�û�����ʱ���������
			if (!visited[p->adjvex])
			{
				ALQ_Push(Q, p->adjvex);
				visited[p->adjvex] = true;
			}
			p = p->nextarc;
		}
	}
}