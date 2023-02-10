#include"DIJ.h"


void test()
{
	AMGraph G;
	CreateUDN(G);
	ShortestPath_DIJ(G, 0);
}

int main()
{
	test();
	return 0;
}