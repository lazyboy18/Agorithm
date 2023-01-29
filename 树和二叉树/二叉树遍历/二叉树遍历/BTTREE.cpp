#include"BTTREE.h"
//初始化,放回指针类型
Bitree* BTnit()
{
	Bitree* Newroot = NULL;
	return Newroot;
}

//创建,用递归实现(先序创建)
void BTcreate(Bitree*&Bt, int row, int col)
{
	Bt = new Bitree;
	cout << "该树结点为:>" << "(" << row << " ," << col << ")" << endl;
	cout << "输入该结点与上级结点的关系:>";
	cin >> (Bt->relationship);
	cout << "输入该结点的名字:>";
	cin >> (Bt->name);
	string Judge;
	cout << "是否创建结点" << "(" << row << " ," << col << ")" << "的左儿子?>" << endl;
	cin >> Judge;
	if (Judge.compare("YES") == 0)
	{
		BTcreate(Bt->leftchild, row + 1, 2 * col - 1);
	}
	else
		Bt->leftchild = NULL;
	cout << "是否创建结点" << "(" << row << " ," << col << ")" << "的右儿子?>" << endl;
	cin >> Judge;
	if (Judge.compare("YES") == 0)
	{
		BTcreate(Bt->rightchild, row + 1, 2 * col);
	}
	else
		Bt->rightchild = NULL;
}
//用递归遍历所有的结点(先序)
void OrderTraverse(Bitree* Bt, int row, int col)
{
	if (Bt == NULL)
		return;
	cout << "该树结点为:>" << "(" << row << " ," << col << ")" << "的信息为>" << endl;
	cout << "名字:>" << Bt->name << endl;
	cout << "与上级关系:>" << Bt->relationship << endl;
	cout << "---------------------------------" << endl;
	OrderTraverse(Bt->leftchild, row + 1, 2 * col - 1);
	OrderTraverse(Bt->rightchild, row + 1, 2 * col);
}
//栈的初始化
Bstack* Bstack_init()
{
	Bstack* p = NULL;
	return p;
}
//判断是否为空
bool Bstack_Isempty(Bstack* BT)
{
	if (BT == NULL)
		return true;
	else
		return false;
}
void Push(Bitree* root, Bstack**BT)
{
	Bstack*p = new Bstack;
	p->Bt = root;//插入数据域
	p->next = (*BT);
	*BT = p;
}
Bitree* Pop(Bstack**BT)
{
	//取出数据域
	Bitree* p = (*BT)->Bt;
	*BT = (*BT)->next;
	return p;
}
//非递归遍历,参数是头指针
void StackTraverse(Bitree* BTree)
{
	//无需调用初始化函数
	Bstack* BT = NULL;
	Bitree* p = BTree;
	//p先入栈
	while (p || !Bstack_Isempty(BT))
	{
		//非两种情况
		if (p)
		{
			//入栈
			Push(p, &BT);
			//更新p为p的左子树
			p = p->leftchild;
		}
		else
		{
			Bitree* tmp = Pop(&BT);
			cout << "名字:>" << tmp->name << endl;
			cout << "与上级关系:>" << tmp->relationship << endl;
			cout << "---------------------------------" << endl;
			p = tmp->rightchild;
		}
	}
}

//复制二叉树,递归后序实现
void BinaryTreeCopy(Bitree* Bt, Bitree*&newtree)
{
	if (Bt == NULL)
	{
		newtree = NULL;
		return;
	}
	else
	{
		newtree = new Bitree;
		//将内容拷贝
		newtree->name = Bt->name;
		newtree->relationship = Bt->relationship;
		BinaryTreeCopy(Bt->leftchild, newtree->leftchild);
		BinaryTreeCopy(Bt->rightchild, newtree->rightchild);
	}
}
//获得二叉树的深度,二叉树的深度等于其较深子树的深度加1
int Getdepth(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	int m = Getdepth(Bt->leftchild);
	int n = Getdepth(Bt->rightchild);
	if (m > n)
		return m + 1;
	else
		return n + 1;
}
//获得结点的个数
int Getnodenum(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	else
		return Getnodenum(Bt->leftchild) + Getnodenum(Bt->rightchild) + 1;
}
//获得叶节点个数
int getleavenum(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	else if (Bt->leftchild == NULL&&Bt->rightchild == NULL)
		return 1;
	else
		return getleavenum(Bt->leftchild) + getleavenum(Bt->rightchild);
}
int getonenodenum(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	//Bt非空系列
	else if (Bt->leftchild&&!(Bt->rightchild))
		return getonenodenum(Bt->leftchild) + 1;
	else if (Bt->rightchild&&!(Bt->leftchild))
		return getonenodenum(Bt->rightchild) + 1;
	else 
		return getonenodenum(Bt->leftchild) + getonenodenum(Bt->rightchild);
}
int gettwonodenum(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	//Bt非空系列，4种情况
	else if (Bt->leftchild&&!(Bt->rightchild))//左子树非空，右子树空
		return gettwonodenum(Bt->leftchild);
	else if (Bt->rightchild&&!(Bt->leftchild))//右子树非空，左子树空
		return gettwonodenum(Bt->rightchild);
	else if (Bt->rightchild&&Bt->leftchild)//左右子树非空
		return  gettwonodenum(Bt->leftchild) + gettwonodenum(Bt->rightchild) + 1;
	else
		return 0;
}

void Bque_init(Bque& Que)
{
	Que.maxsize = MAXQUENUM;
	Que.rear = Que.tail = 0;
	//数组元素是Bitree*类型，额外消耗了空间
	Que.Base = new Bitree*[Que.maxsize];
}
bool Bque_isempty(Bque& Que)
{
	if (Que.tail == Que.rear)
		return true;
	else
		return false;
}

bool Bque_isfull(Bque& Que)
{
	if ((Que.tail + 1) % Que.maxsize == Que.rear)
		return true;
	else
		return false;
}
//入队，入队元素是BITREE指针
void Bque_push(Bque& Que, Bitree*&Btreepointer)
{
	//空指针无需入队
	if (Bque_isfull(Que)||!(Btreepointer))
		return;
	else
	{
		//从队尾插入
		Que.Base[Que.tail] = Btreepointer;
		Que.tail = (Que.tail + 1) % Que.maxsize;
	}
}
//出队，出队元素是Bitree指针,没有出队元素是为NULL
Bitree* Bque_Pop(Bque& Que)
{
	if (Bque_isempty(Que))
		return NULL;
	else
	{
		Bitree* t = Que.Base[Que.rear];
		Que.rear = (Que.rear + 1) % Que.maxsize;
		return t;
	}
}
//按层序访问
void Visitbyfloor(Bitree* Bt)
{
	//在这里创建临时队列操作二叉树
	Bque Que;
	Bque_init(Que);
	//先让第一个根入队
	Bque_push(Que, Bt);
	while (!Bque_isempty(Que))
	{
		//先让其出队.在判断左子树如果非空就让其入队，右子树同理
		Bitree* Btree = Bque_Pop(Que);
		cout << "名字:>" << Btree->name << endl;
		cout << "与上级关系:>" << Btree->relationship << endl;
		cout << "---------------------------------" << endl;
		Bque_push(Que, Btree->leftchild);
		Bque_push(Que, Btree->rightchild);
	}
}