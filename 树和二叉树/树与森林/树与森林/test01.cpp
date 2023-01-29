#include"Forest.hpp"

//兄弟孩子法的演示
void test01()
{
	CSNode*tree = NULL;//先将指针置空
	CSinit(tree);//初始化分配空间
	CScreate(tree);
}

void test02()
{
	CSForest* forest = NULL;
	CSForestinit(forest);
	CSforestcreate(forest);
}
//创建一个森林，然后将其转化为二叉树
void test03()
{
	CSForest* forest = NULL;
	CSForestinit(forest);
	CSforestcreate(forest);
	CSNode* comtree = ForestTransfer(forest);
}

//创建一棵树,并且遍历它
void test04()
{
	CSNode* singleTree = NULL;
	CSinit(singleTree);
	//创建一颗树
	CScreate(singleTree);
	//先序遍历
	Traverse(singleTree);
}
//遍历森林，先生成森林，再遍历它
void test05()
{
	//森林同样是CSNode*类型
	CSNode* forest = forestCreate();
	Traverse(forest);
}
//使用新的森林结构
void test06()
{
	CSForests* Forest = NULL;
	//创建森林
	CSforestcreate(Forest);
	//遍历森林
	Traverse(Forest->forest);
}


int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}