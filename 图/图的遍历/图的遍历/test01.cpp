#include"DFS.h"

/*
	ͼ�������������������˼·������죬
	����ͼ�ľ���洢�ṹ����΢��ͬ��
	��Ҫ�������Ѱ����һ���ڽӵ�

*/

/*
	�������ͼ��������ı���Լ�������
*/
//void test01()
//{
//	AMGraph G;
//	CreateUDN(G);
//	DFS_AMFORALL(G);
//}

//void test02()
//{
//	ALGraph G;
//	CreateUDNal(G);
//	DFS_ALFORALL(G);
//	DelUDNal(G);
//}

//ʹ�ù����������������ͨͼ
void test03()
{
	ALGraph G;
	CreateUDNal(G);
	BFS_AL(G, 0);
}



int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
