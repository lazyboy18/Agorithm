#include"Cuebinarytree.h"
//创建中序线索二叉树
/*
	我们规定，序列中第一个结点的前驱为根结点，最后一个结点的前驱必定存在，
	其后驱就指向根节点
	由于中序遍历是先搜索左子树结点，再根，再到右子树结点
	所以左子树结点的后驱必定是根结点,右子树的结点的前驱必定是
	根结点
*/
//pre是当前结点p的前驱
/*
	与遍历二叉树差不多，中序二叉树的线索化也是从左子树开始，再到右子树
	规定第一个前驱pre为根节点，序列中的第一个结点的前驱为根结点，后驱为
	上一层递归的根结点
	由于p的前驱pre的后驱就是p，所以在每一层递归中，不仅要使p线索化，也要使
	pre线索化（能够线索化的情况下），而且也只能进行这两步操作
	另外，在使右子树线索化之前，应该要更新前驱，pre=p(因为越早遍历到的结点，排序越靠前)
*/
Ctree* pre;
//以结点p为根的子树中序线索化
void InTreading(Ctree* p)
{
	if (p)
	{
		//先使左子树线索化
		InTreading(p->leftchild);
		//该结点没有左孩子
		if (!p->leftchild)
		{
			p->ltag = 1;
			p->leftchild = pre;//p的左指针指向前驱
		}
		else
			p->ltag = 0;//p已经有了左孩子
		//再链接目前p的前驱pre与p，再判断，pre的后驱是否应该为p
		if (!pre->rightchild)
		{
			pre->rtag = 1;
			pre->rightchild = p;
		}
		else
			pre->rtag = 0;
		//再使右子树线索化
		pre = p;//更新前驱
		InTreading(p->rightchild);
	}
}
void My_InOrderThreding(Ctree* p)
{
	if (p)
	{
		//先使左子树线索化，找到序列中的第一个结点
		My_InOrderThreding(p->leftchild);
		//左子树线索化的具体实现如下：
		if (!p->leftchild)
		{
			p->leftchild = pre;
			p->ltag = 1;
		}
		else
			p->ltag = 0;
		//pre需要更新它的后驱
		if (!pre->rightchild)
		{
			pre->rightchild = p;
			pre->rtag = 1;
		}
		else
			pre->rtag = 0;
		pre = p;//更改前驱pre为p
		My_InOrderThreding(p->rightchild);
	}
}


void test03()
{
	Ctree*ctree = NULL;
	Ctree_init(ctree);
	Ctree_create(ctree);
	//head = new Ctree;
	//head->leftchild = ctree;
	//head->rightchild = NULL;
	//pre = head;
	//My_InOrderThreding(head);
	//pre = ctree;
	//InTreading(ctree);
}

void InOrderThreading(Ctree*& head,Ctree* p)
{
	//头结点的左孩子指向根，右孩子在最初始时指向自己以避免其作为pre==NULL时会改变
	//指向，该线索化过程依旧可以复用InThreading()函数
	head = new Ctree;
	head->ltag = 0;
	head->rtag = 0;
	head->rightchild = head;
	if (!p)
		head->leftchild = head;
	else
	{
		head->leftchild = p;
		pre = head;
		InTreading(p);//对以p为根的二叉树做线索化
		pre->rightchild = head;
		head->rightchild = pre;
		head->rtag = 1;
		pre->rtag = 1;
	}
}
//以中序遍历为例子
/*
	二叉树完成线索化之后，序列中的每一个结点都有了前驱或者后驱或者右孩子或左孩子
	如需遍历二叉树则需要先找到左子树最左下结点，访问该结点之后，则找该结点的后驱
	（判断条件是p->rtag==1），若后驱存在且不为头结点，那么就更新p为p->rchild，访问该结点;
	如果该后驱不存在，说明该结点有右孩子，则将p更新为p=p->rchild；然后开始访问该结点的右子树
	，从头开始找该右子树的第一个遍历结点
*/
//无需创建过多的栈空间
void InOrderTraverse(Ctree*& head)
{
	//从根结点开始遍历	
	Ctree* p = head->leftchild;
	while (p != head)
	{
		//先遍历该树的左结点,找到序列中的第一个结点，并访问该结点
		while (p->ltag == 0)
			p = p->leftchild;
		//访问该结点
		cout << p->x << " ";
		//开始找这个结点的后驱,该后驱不为头结点
		while (p->rtag == 1 && p->rightchild != head)
		{
			p = p->rightchild;
			cout << p->x << " ";
		}
		//如果没有找到该后驱，说明有右孩子，则开始遍历右孩子
		p = p->rightchild;
		//当该后驱为head时，说明已经遍历到序列中的最后一个结点，程序跳出循环
	}
	cout << endl;
}

void test04()
{
	Ctree*ctree = NULL;
	Ctree_init(ctree);
	//中序创建
	Ctree_create(ctree);
	Ctree* head = NULL;
	InOrderThreading(head, ctree);
	InOrderTraverse(head);
}

int main()
{
	//test03();
	//test04();
	system("pause");
	return 0;
}