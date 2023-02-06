#include"DFS.h"
//标记该顶点是否被访问过
bool visited[Mvnum];
//用邻接矩阵创建无向网
void CreateUDN(AMGraph& G)
{
	//输入顶点与边的个数，图的第一部分信息
	cin >> G.vexnum >> G.arcnum;
	//判断合法性
	if (G.vexnum > Mvnum || G.arcnum > (G.vexnum - 1) * G.vexnum / 2)
	{
		cout << "所输入信息非法" << endl;
		return;
	}
	//紧接着输入顶点的信息,图的第二部分信息
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
	}
	//将图的边初始化,权值全部置为0
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
			G.arcs[i][j] = 0;
	}
	//输入权值
	for (int i = 0;i < G.arcnum;i++)
	{
		//输入v1,v2作为边(v1,v2)的顶点以及边之间的权值w
		//编号从0开始
		int v1, v2, w;
		//此处省略了查找v1,v2编号的过程
		cin >> v1 >> v2 >> w;
		//时刻关注合法性
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
		//输入边的权值
		G.arcs[v1][v2] = G.arcs[v2][v1] = w;
	}
	//创建完毕
}

//深度遍历搜索
void DFS_AM(AMGraph& G, int v)
{
	if (visited[v])
	{
		return;
	}
	//由于邻接矩阵查找邻接点过于简单，无需再定义Firstvex与Nextvex
	//访问v结点，并输出其数据
	cout << "顶点编号为：" << v << "  顶点数据域：" << G.vexs[v] << endl;
	//并标记该顶点
	visited[v] = true;
	for (int i = 0;i < G.vexnum;i++)
	{
		//查找与v相互连通的顶点
		if (G.arcs[v][i] != 0 && !visited[i])
		{
			DFS_AM(G, i);
		}
	}
}

//遍历非连通图
void DFS_AMFORALL(AMGraph& G)
{
	for (int i = 0;i < G.vexnum;i++)
	{
		DFS_AM(G, i);
	}
}


//以邻接表为存储结构
void CreateUDNal(ALGraph& G)
{
	cin >> G.vexnum >> G.arcnum;
	if (G.vexnum > Mvnum || G.arcnum > (G.vexnum - 1) * G.vexnum / 2)
	{
		return;
	}
	//输入顶点数据域的数据并且将指针域置空
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].fisrtarc = NULL;
	}
	//连接各个顶点，输入边的权值以及边的指向顶点信息
	for (int i = 0;i < G.arcnum;i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		if (v1 >= Mvnum || v2 >= Mvnum || w > Maxw)
		{
			i--;
			continue;
		}
		//连接v1到v2的边，并且完善该边的信息
		ArcNode* p1 = new ArcNode;
		p1->adjvex = v2;
		p1->info = w;
		//注意编号从0开始
		p1->nextarc = G.vertices[v1].fisrtarc;
		G.vertices[v1].fisrtarc = p1;
		//连接v2到v1的边，并且完善该边的信息
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
	cout << "删除成功!" << endl;
	p = NULL;
}

//删除该邻接表(有点难度)
void DelUDNal(ALGraph& G)
{
	for (int i = 0;i < G.vexnum;i++)
	{
		DelAlg(G.vertices[i].fisrtarc);
	}
}

//深度优先搜索
void DFS_AL(ALGraph& G, int v)
{
	if (visited[v])
	{
		return;
	}
	visited[v] = true;
	//输出该顶点编号与数据域
	cout << "该顶点编号：" << v << " " << "该顶点的数据域：" << G.vertices[v].data << endl;

	//查找与顶点v相互连通的其没有被访问过的顶点
	ArcNode* p = G.vertices[v].fisrtarc;

	//p指向v的下一条边
	while (p)
	{
		//i为与v先连通的点
		int i = p->adjvex;
		if (!visited[i])
		{
			DFS_AL(G, i);
		}
		p = p->nextarc;
	}
}

//遍历非连通图
void DFS_ALFORALL(ALGraph& G)
{
	//从0开始
	for (int i = 0;i < G.vexnum;i++)
	{
		DFS_AL(G, i);
	}
}

//队列函数实现
//初始化
void ALQueinit(ALQue& Q)
{
	Q.maxsize = Mvnum;
	Q.front = Q.rear = 0;
}
//判断是否为空
bool is_emptys(const ALQue& Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
//判断是否为满
bool is_full(const ALQue& Q)
{
	if ((Q.rear + 1) % Q.maxsize == Q.front)
	{
		cout << "队列已满" << endl;
		return true;
	}
	else
		return false;
}
//入队,无需返回值
void ALQ_Push(ALQue& Q, const int& v)
{
	//v为下标
	if (is_full(Q))
	{
		return;
	}
	Q.Que[Q.rear] = v;
	Q.rear = (Q.rear + 1) % Q.maxsize;
}
//出队
void ALQ_Pop(ALQue& Q, int& w)
{
	if (is_emptys(Q))
	{
		return;
	}
	Q.rear--;
	w = Q.Que[Q.rear];
}
//队列函数实现

//广度优先搜索
void BFS_AL(ALGraph& G,const int v)
{
	//v首访问顶点
	if (visited[v])
	{
		//在遍历非连通图时需要访问多个顶点
		return;
	}
	ALQue Q;//创建队列
	ALQueinit(Q);
	//访问该顶点并输出其数据域
	visited[v] = true;
	//先将顶点v入队,并且将入队视为已被访问的标志
	ALQ_Push(Q, v);
	while (!is_emptys(Q))
	{
		int u;  //存储顶点编号
		ALQ_Pop(Q, u);//出队,并将与u相互邻接的顶点入队
		cout << "顶点编号为：" << u << " 其数据域：" << G.vertices[u].data << endl;
		//除非查找过程的代码量巨大，否则两个查找函数就显得有点多余
		//for (w = FirstAdject(G, u);w >= 0;w = NextAdject(G, u, w));
		ArcNode* p = G.vertices[u].fisrtarc;
		while (p)
		{
			//当u的邻接点的还没有入队时，则将其入队
			if (!visited[p->adjvex])
			{
				ALQ_Push(Q, p->adjvex);
				visited[p->adjvex] = true;
			}
			p = p->nextarc;
		}
	}
}