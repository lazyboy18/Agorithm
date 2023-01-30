#include"Binarytree.h"
//初始化
void Ainit(Bpa& Btree)
{
	Btree = new BinaryTreeA;
	Btree->lChild = Btree->rChild = NULL;
}
//采用中序创建
void Acreate(Bpa& Btree)
{
	if (Btree == NULL)
		return;
	string com;
	cout << "是否创建左子树?:>" << endl;
	cin >> com;
	if (com.compare("YES") == 0)
	{
		Ainit(Btree->lChild);//重复利用初始化函数
	}
	Acreate(Btree->lChild);
	cout << "输入该结点的数据:>" << endl;
	cin >> Btree->data;
	cout << "是否创建右子树?:>" << endl;
	cin >> com;
	if (com.compare("YES") == 0)
	{
		Ainit(Btree->rChild);
	}
	Acreate(Btree->rChild);
}
//求叶子结点
int AGetleavenum(Bpa& Btree)
{
	//单独一个根算叶子结点
	if (Btree == NULL)//避免结点为空
		return 0;
	if (Btree->lChild == NULL && Btree->rChild == NULL)
		return 1;
	int lnum = 0, rnum = 0;
	//获得整棵树的叶子结点等于左子树与右子树的叶子结点之和
	lnum = AGetleavenum(Btree->lChild);
	rnum = AGetleavenum(Btree->rChild);
	return lnum + rnum;
}
//判断两棵树是否相同,每次比较都在同层级
bool Ais_same(Bpa& Btree1, Bpa& Btree2)
{
	//逐一在相同方向的结点上，比对数据域
	//4四种情况，同为空true,一空一非空false,双非空继续判断
	if (Btree1 == NULL && Btree2 == NULL)
		return true;
	//此时Btree2一定非空，若为空则在第一条语句结束
	else if (Btree1 == NULL)
		return false;
	//此时Btree1一定非空，理由与上述相似
	else if (Btree2 == NULL)
		return false;
	else
	{
		//比对数据域,如果相同则继续判断下一层
		if (Btree1->data == Btree2->data)
		{
			bool ret1 = Ais_same(Btree1->lChild, Btree2->lChild);
			bool ret2 = Ais_same(Btree1->rChild, Btree2->rChild);
			if (ret1 && ret2)//且门
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

//交换二叉树的左右孩子
void AexChild(Bpa& Btree)
{
	//三种情况，Btree为空，没有后戏；
	//Btree非空，但有一个孩子结点为空，也没有后戏；
	//Btree非空，但两孩子也非空，交换元素
	if (Btree == NULL)
		return;
	else if (Btree->lChild == NULL || Btree->rChild == NULL)
		return;
	else
	{
		int t = Btree->lChild->data;
		Btree->lChild->data = Btree->rChild->data;
		Btree->rChild->data = t;
		AexChild(Btree->lChild);
		AexChild(Btree->rChild);
	}
}
//双序遍历
	//先遍历当前的结点，再访问其左子树，再访问一下这个结点
	//再访问其右子树
	//访问的输出方式以及数据类型根据自己而定，这里仅仅输出整型数据
	//Show,如果输出代码较大时，可以独立封装一个函数
void ADO_visit(Bpa& Btree)
{
	if (Btree == NULL)
		return;
	cout << Btree->data << " ";//先访问该结点
	ADO_visit(Btree->lChild);//再访问其左子树
	cout << Btree->data << " ";//再访问该结点
	ADO_visit(Btree->rChild);
}
//计算二叉树的最大宽度
void AGetmaxWidth(Bpa& Btree, int*arr, int floor)
{
	//如果为空说明，宽度不变
	if (Btree == NULL)
		return;
	else
	{
		//完该层的宽度
		arr[floor]++;
		//先检查左子树的层数，再检查右子树的层数
		AGetmaxWidth(Btree->lChild, arr, floor+1);//每一层都从0开始
		AGetmaxWidth(Btree->rChild, arr, floor+1);
	}
}
//用户版本得到最大宽度
void AGetmaxWidthApp(Bpa& tree)
{
	int maxwidth = 0;
	//maxwidth接收最大宽度
	int arr[1000] = { 0 };//树的深度有局限性，最多为1000
	AGetmaxWidth(tree, arr, 0);
	int floor = 0;
	for (int i = 0;i < 1000;i++)
	{
		if (arr[i] > maxwidth)
		{
			maxwidth = arr[i];
			floor = i + 1;
		}
	}
	cout << "tree的最大宽度层在第" << floor << "层"
		<< "  最大宽度为: maxwidth = " << maxwidth << endl;
}


//初始化
void Aque_init(Aque& aque)
{
	aque.quemaxsize = QUEMAXSIZE;
	aque.front = aque.rear = 0;
	aque.arr = new Bpa[aque.quemaxsize];
}
//判断队列是否为空
bool Aqueis_empty(Aque& aque)
{
	if (aque.front == aque.rear)
	{
		//cout << "空" << endl;
		return true;
	}
	else
		return false;
}
//判断循环队列是否已经满
bool Aqueis_full(Aque& aque)
{
	if ((aque.rear + 1) % aque.quemaxsize == aque.front)
	{
		//cout << "满" << endl;
		return true;
	}
	else
		return false;
}
//入队，入队元素是Bpa指针
void Aque_push(Aque& aque, Bpa& tree)
{
	if (Aqueis_full(aque))
		return;
	//先入队，再rear++
	aque.arr[aque.rear] = tree;
	aque.rear = (aque.rear + 1) % aque.quemaxsize;//易忽略步骤
}
//出队,将出队元素放在一个载体上
void Aque_pop(Aque& aque, Bpa& carrier)
{
	if (Aqueis_empty(aque))
		return;
	carrier = aque.arr[aque.front];
	aque.front = (aque.front + 1) % aque.quemaxsize;
}
//销毁队列
void Aque_delete(Aque& aque)
{
	delete[]aque.arr;
	aque.arr = NULL;
	cout << "aque销毁成功" << endl;
}
//层序遍历,为了验证变化结果
void Aque_visit(Bpa& tree)
{
	Aque aque;
	Aque_init(aque);
	//先让tree入队，再让tree出队，再将其子树入队
	Aque_push(aque, tree);
	cout << "二叉树的层序输出如下:>" << endl;
	while (!Aqueis_empty(aque))
	{
		Bpa tmp = NULL;
		Aque_pop(aque, tmp);
		cout << tmp->data << " ";
		//再让左子树入队
		if (tmp->lChild != NULL)
			Aque_push(aque, tmp->lChild);
		if (tmp->rChild != NULL)
			Aque_push(aque, tmp->rChild);
	}
	cout << endl;
	Aque_delete(aque);
}