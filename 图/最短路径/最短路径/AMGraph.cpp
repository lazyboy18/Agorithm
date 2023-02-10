#include"AMGraph.h"

//���ڽӾ��󴴽�������
void CreateUDN(AMGraph& G)
{
	//inf��ʾ�������û����·������Ϊ�����
	int inf = 99999999;
	//���붥���뻡�ĸ���
	cin >> G.vexnum >> G.arcnum;
	//�жϺϷ���
	if (G.vexnum > Mvnum || G.arcnum > (G.vexnum - 1) * G.vexnum)
	{
		cout << "��������Ϣ�Ƿ�" << endl;
		return;
	}
	//���붥�����Ϣ������Ϊchar
	for (int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
	}
	//��ͼ�ı߳�ʼ��
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			if (i != j)
				G.arcs[i][j] = inf;
			else
				G.arcs[i][j] = 0;
		}
	}
	//����Ȩֵ
	for (int i = 0;i < G.arcnum;i++)
	{
		//����v1,v2��Ϊ��<v1,v2>�Ķ����Լ��û�Ȩֵw
		//�����±��0��ʼ
		int v1, v2, w;
		//�˴�ʡ���˲���v1,v2��ŵĹ���
		cin >> v1 >> v2 >> w;
		//�жϺϷ���
		if (v1 == v2 || v1 >= G.vexnum || v2 >= G.vexnum
			|| v1 < 0 || v2 < 0)
		{
			i--;
			continue;
		}
		if (G.arcs[v1][v2] != inf)
		{
			i--;
			continue;
		}
		//���뻡<v1,v2>��Ȩֵ
		G.arcs[v1][v2] = w;
	}
	//�������
}


