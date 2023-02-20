#include<iostream>
using namespace std;
#include"AMGraph.h"
#include<queue>
/*
	六度空间理论指，地球人任意一个人通过自己的朋友，
	或朋友的朋友……通过6个中间人便可以认识世界人任意一个人

	如何验证这个问题？
	可以建立一个无向图，图的顶点就表示一个独立的人，
	顶点将是否有联系则表示该两人是否认识。

*/

void InitVisited(bool* visited,const int&size)
{
	for (int i = 0;i < size;i++)
	{
		//表示没有访问过
		visited[i] = true;
	}
}

//广度优先搜索
void Sixdegree_BFS(const ALGraph& G, const int& start)
{
	//解决visited数组表示是否已被遍历
	bool visited[Maxvex] = { 0 };
	int visit_num = 0;
	//len[i],表示第i-1层的入队人数
	int len[8] = { 0 };
	len[1] = 1;
	//建立队列实现层序遍历
	queue<int> Q;
	Q.push(start);
	visited[start] = true;
	//层序遍历6次,当循环层数不超过7，而且不为空
	for (int i = 1;i <= 6&&!Q.empty();i++)
	{

		//i表示层数,该层需要访问len[i]个人的其他朋友
		for (int j = 0;j < len[i];j++)
		{
			int w = Q.front();
			Q.pop();//从队头出队
			//访问w的朋友
			ArcNode* p = G.vertices[w].fisrtarc;
			while (p)
			{
				int l = p->adjvex;
				//判断是否没有入队
				if (!visited[l])
				{
					//l入队
					Q.push(l);
					visited[l] = true;
					//第i+1层的人数为
					len[i + 1]++;
					visit_num++;
				}
				p = p->nextarc;
			}
		}
	}
	float f = visit_num * 1.0 / G.vexnum;
	cout << f * 100 << "%" << endl;
}

void test01()
{
	ALGraph G;
	CreateUDN(G);
	//从编号为0的那个人开始查找
	Sixdegree_BFS(G, 0);
}

int main()
{
	test01();
	return 0;
}

