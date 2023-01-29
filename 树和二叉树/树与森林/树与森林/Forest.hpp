#ifndef _FOREST_HPP_
#define _FOREST_HPP_
#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 10

/*
	注意事项：树的根节点是没有右兄弟的
			  二叉树的根节点有右结点
*/

//左边指向孩子，右边指向兄弟
//这种存储结构的优点就是，利用了二叉树的存储结构，其遍历操作可以复用二叉树的函数
typedef struct CSNode{
	string name;
	int ltag, rtag;//只有在线索化之后才使用
	struct CSNode*firstchild, *nextsibling;
}CSNode;
//创建森林
//实际上，森林需要作为一棵二叉树才方便操作，所以森林结构中的CSNode**可以改为CSNode*
typedef struct CSForest{
	CSNode** forest;
	int maxsize;//树的最大容量
	int treenum;//现有树的数量
}CSForest;
//森林的另外一种存储结构
typedef struct CSForests{
	//没有树容限制
	CSNode* forest;
	int treenum;
}CSForests;

//树的操作

//初始化，姑且认为初始化就是给根节点开辟空间
void CSinit(CSNode*& tree)
{
	tree = new CSNode;
	tree->firstchild = tree->nextsibling = NULL;
}
//我们是根据森林的树状图直接创建了其二叉树
//创建,采用中序创建，先创建儿子，再自己，再到右兄弟
//我们在创建的时候需要自己判断树的结构
void CScreate(CSNode*& tree)
{
	if (tree == NULL)
		return;
	string com;
	//判断是否创建左儿子
	cout << "是否创建该结点的儿子:>" << endl;
	cin >> com;
	if (com.compare("YES")==0)
	{
		tree->firstchild = new CSNode;
		tree->firstchild->firstchild = NULL;
		tree->firstchild->nextsibling = NULL;
	}
	CScreate(tree->firstchild);
	//给该结点赋值
	cout << "为该结点赋值，请输入结点名字:>" << endl;
	cin >> tree->name;
	cout << "是否创建该结点的兄弟(注意根节点没有兄弟):>" << endl;
	cin >> com;
	if (com.compare("YES") == 0)
	{
		tree->nextsibling = new CSNode;
		tree->nextsibling->firstchild = NULL;
		tree->nextsibling->nextsibling = NULL;
	}
	CScreate(tree->nextsibling);
}
//采用先根遍历
void Traverse(CSNode*& tree)
{
	//森林与树的遍历共同一个函数
	if (tree == NULL)
		return;
	//先访问根节点
	cout << "该结点的数据域:>" << tree->name << endl;
	//再遍历它的左子树
	Traverse(tree->firstchild);
	//再遍历它的右兄弟
	Traverse(tree->nextsibling);
}

//森林初始化
void CSForestinit(CSForest*& Forest)
{
	Forest = new CSForest;
	Forest->maxsize = MAXSIZE;
	Forest->forest = new CSNode*[Forest->maxsize];
	Forest->treenum = 0;
	for (int i = 0; i < Forest->maxsize; i++)
	{
		Forest->forest[i] = NULL;
	}
}

//创建森林
void CSforestcreate(CSForest*& Forest)
{
	cout << "输入森林中树的数量:>" << endl;
	int num;
	cin >> num;
	if (num > Forest->maxsize)
	{
		cout << "容量不足" << endl;
		return;
	}
	for (int i = 0; i < num; i++)
	{
		cout << "生成第" << i + 1 << "棵树:>" << endl;
		CSinit(Forest->forest[i]);//最初为NULL
		CScreate(Forest->forest[i]);
	}
	Forest->treenum = num;
}

//创建新版森林
void CSforestcreate(CSForests*& Forest)
{
	cout << "请输入树容:>" << endl;
	int num;
	cin >> num;
	if (num < 1)
		return;
	else
	{
		Forest = new CSForests;
		Forest->treenum = num;
		CSinit(Forest->forest);//为第一棵树开辟空间
		CSNode*p = Forest->forest;
		for (int i = 1; i <= Forest->treenum; i++)
		{
			cout << "正在创建第" << i << "棵树:>" << endl;
			//创建第i棵树,p的根节点没有右孩子
			CScreate(p);
			if (i == Forest->treenum)
				break;
			//需要先分配内存，否则第一棵树的右孩子依旧为NULL
			CSinit(p->nextsibling);//给第i棵树的右孩子分配内存
			p = p->nextsibling;//操作第i+1棵树
		}
	}
}

//森林转化成为二叉树(这个二叉树可是有兄弟的啊)
CSNode* ForestTransfer(CSForest*& Forest)
{
	if (Forest->treenum == 0)
	{
		cout << "没有树" << endl;
		return NULL;
	}
	//将前驱树的右孩子指向第二棵树
	for (int i = 0; i < Forest->treenum; i++)
	{
		//新树指向前驱树
		Forest->forest[i]->nextsibling = Forest->forest[i + 1];
	}
	return Forest->forest[0];
}

CSNode* forestCreate()
{
	//先创建数组
	CSForest* forest = NULL;
	CSForestinit(forest);
	CSforestcreate(forest);
	CSNode* Forest = ForestTransfer(forest);
	return Forest;
}

//树转化为森林
CSForest* BinaryTrasver(CSNode* comtree)
{
	//将二叉树转后的森林存储在一个森林结构中，并返回森林结构
	if (comtree == NULL)
		return NULL;
	//创建一个森林
	CSForest* divforest = NULL;
	CSForestinit(divforest);
	//将二叉树comtree分解，插入森林中
	int i = 0;
	while (comtree)
	{
		//入装
		divforest->forest[i] = comtree;
		//根结点没有右兄弟
		divforest->forest[i]->nextsibling = NULL;
		//更新comtree结点
		comtree = comtree->nextsibling;
		//最后一个结点的指针指向NULL
	}
	return divforest;
}
//前驱
CSNode* pre;
//很抱歉，不建议将树线索化
//将由森林（由多棵根结点没有右儿子的二叉树组成)转化得到的二叉树中序线索化
//使每一棵树都在创建后进行中序线索化
//将根节点为p的二叉树线索化
void InThreadings(CSNode*& p)
{
	//先将左子树线索化
	if (p)
	{
		InThreadings(p->firstchild);
		if (!p->firstchild)
		{
			//p的firstchild指向前驱
			p->firstchild = pre;
			p->ltag = 1;
		}
		else
			p->ltag = 0;
		if (!pre->nextsibling)
		{
			//pre的nextsibling指向后驱
			pre->nextsibling = p;
			pre->rtag = 1;
		}
		else
			pre->rtag = 0;
		pre = p;
		//将右子树线索化
		InThreadings(p->nextsibling);
	}
}
//很抱歉，不建议将树线索化
//当头结点存在的情况下，将二叉树线索化
void InOrderThreading(CSNode*& p, CSNode*& thrt)
{
	thrt = new CSNode;
	thrt->nextsibling = thrt;
	if (!p)
	{
		thrt->firstchild = thrt;
		thrt->rtag = 1;
		thrt->ltag = 1;
	}
	else
	{
		thrt->firstchild = p;
		thrt->ltag = 1;
		pre = thrt;
		InThreadings(p);
		pre->nextsibling = thrt;
		pre->rtag = 1;
		thrt->nextsibling = pre;
		thrt->rtag = 1;
	}
}
//很抱歉，不建议将树线索化
//将线索化过后的二叉树遍历一遍
void OrderTrasverse(CSNode*& thrt)
{
	CSNode* p = thrt->firstchild;
	while (p != thrt)
	{
		//中序遍历
		while (p->ltag == 0)
			p = p->firstchild;
		cout << "该结点的数据域:>" << p->name << endl;
		//找p的后驱
		while (p->rtag == 1 && p->nextsibling != thrt)
		{
			p = p->nextsibling;
			cout << "该结点的数据域:>" << p->name << endl;
		}
		p = p->nextsibling;
	}
}

#endif
