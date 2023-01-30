#include"Binarytree.h"

//获取叶子结点个数
void test01()
{
	Bpa tree = NULL;
	Ainit(tree);
	Acreate(tree);
	int ret = AGetleavenum(tree);
	cout << "叶子结点个数 ret = " << ret << endl;
}
//判断两棵树是否相同
void test02()
{
	Bpa tree1 = NULL;
	Bpa tree2 = NULL;
	Ainit(tree1);
	Ainit(tree2);
	cout << "创建第一棵树" << endl;
	Acreate(tree1);
	cout << "创建第二棵树" << endl;
	Acreate(tree2);
	if (Ais_same(tree1, tree2))
		cout << "The trees are same!" << endl;
	else
		cout << "The trees are differnet!" << endl;
}
//创建一棵二叉树，层序遍历其输出结果，再交换其左右孩子，再层序输出其结果
void test03()
{
	Bpa tree = NULL;
	Ainit(tree);
	cout << "创建二叉树:>" << endl;
	Acreate(tree);//创建二叉树
	Aque_visit(tree);
	AexChild(tree);
	cout << "交换左右孩子之后:>" << endl;
	Aque_visit(tree);
}
//双序遍历
void test04()
{
	Bpa tree = NULL;
	Ainit(tree);
	Acreate(tree);
	cout << "双序遍历结果如下:>" << endl;
	ADO_visit(tree);
}
//求最大宽度
void test05()
{
	Bpa tree = NULL;
	Ainit(tree);
	cout << "创建测试二叉树:>" << endl;
	Acreate(tree);
	AGetmaxWidthApp(tree);
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}