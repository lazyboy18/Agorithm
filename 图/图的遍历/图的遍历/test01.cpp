#include"DFS.h"

/*
	图的深度优先搜索的总体思路相差无异，
	根据图的具体存储结构而略微不同，
	主要在于如何寻找下一个邻接点

*/

/*
	需求，输出图各个顶点的编号以及数据域
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

//使用广度优先搜索遍历连通图
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
