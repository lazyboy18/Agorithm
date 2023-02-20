#include<iostream>
using namespace std;
#include"AMGraph.h"
#include<queue>
/*
	���ȿռ�����ָ������������һ����ͨ���Լ������ѣ�
	�����ѵ����ѡ���ͨ��6���м��˱������ʶ����������һ����

	�����֤������⣿
	���Խ���һ������ͼ��ͼ�Ķ���ͱ�ʾһ���������ˣ�
	���㽫�Ƿ�����ϵ���ʾ�������Ƿ���ʶ��

*/

void InitVisited(bool* visited,const int&size)
{
	for (int i = 0;i < size;i++)
	{
		//��ʾû�з��ʹ�
		visited[i] = true;
	}
}

//�����������
void Sixdegree_BFS(const ALGraph& G, const int& start)
{
	//���visited�����ʾ�Ƿ��ѱ�����
	bool visited[Maxvex] = { 0 };
	int visit_num = 0;
	//len[i],��ʾ��i-1����������
	int len[8] = { 0 };
	len[1] = 1;
	//��������ʵ�ֲ������
	queue<int> Q;
	Q.push(start);
	visited[start] = true;
	//�������6��,��ѭ������������7�����Ҳ�Ϊ��
	for (int i = 1;i <= 6&&!Q.empty();i++)
	{

		//i��ʾ����,�ò���Ҫ����len[i]���˵���������
		for (int j = 0;j < len[i];j++)
		{
			int w = Q.front();
			Q.pop();//�Ӷ�ͷ����
			//����w������
			ArcNode* p = G.vertices[w].fisrtarc;
			while (p)
			{
				int l = p->adjvex;
				//�ж��Ƿ�û�����
				if (!visited[l])
				{
					//l���
					Q.push(l);
					visited[l] = true;
					//��i+1�������Ϊ
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
	//�ӱ��Ϊ0���Ǹ��˿�ʼ����
	Sixdegree_BFS(G, 0);
}

int main()
{
	test01();
	return 0;
}

