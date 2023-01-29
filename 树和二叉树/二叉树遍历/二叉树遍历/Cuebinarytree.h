#include<iostream>
using namespace std;
#include<string>
//定义线索二叉树
typedef struct Ctree{
	int x;
	int ltag, rtag;//用于判断是否存在前后驱
	struct Ctree*leftchild, *rightchild;
}Ctree;
//初始化，树一定不是空树
void Ctree_init(Ctree*& ctree)
{
	ctree = new Ctree;
	ctree->leftchild = ctree->rightchild = NULL;
}
//中序递归创建
void Ctree_create(Ctree* ctree)
{
	//递归结束条件
	if (ctree == NULL)
		return;
	//先创建左子树，就需要先判断
	string com;
	cout << "是否创建左子树:>" << endl;
	cin >> com;
	if (com.compare("YES")==0)
	{
		ctree->leftchild = new Ctree;
		ctree->leftchild->leftchild = NULL;
		ctree->leftchild->rightchild = NULL;
	}
	//ctree左右孩子本来就为null
	Ctree_create(ctree->leftchild);
	//在创建树根，给它赋值
	cout << "给结点赋值:>" << endl;
	cin >> ctree->x;
	//再创建右子树
	cout << "是否创建右子树:>" << endl;
	cin >> com;
	if (com.compare("YES") == 0)
	{
		ctree->rightchild = new Ctree;
		ctree->rightchild->leftchild = NULL;
		ctree->rightchild->rightchild = NULL;
	}
	//ctree左右孩子本来就为null
	Ctree_create(ctree->rightchild);
}
