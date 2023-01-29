#ifndef _BTTREE_H_
#define _BTTREE_H_
#include<iostream>
using namespace std;
#include<string>
#define MAXQUENUM 10
/*
	需要完成的任务：
	定义二叉树结构（写一个人际关系表）
	定义初始化函数，创建函数
	最关键的是，遍历结点函数（递归实现，栈实现，队列实现）
	复制二叉树、求树的深度、求结点个数
*/
/*
	遗留问题：链接问题,链栈的创建

*/
//关系谱树
typedef struct Binarytree{
	string name;//名字
	string relationship;//与上一级的关系
	struct Binarytree*leftchild, *rightchild;
}Bitree,*BIpointer;
//栈
typedef struct Bstack{
	Bitree* Bt;//数据域
	struct Bstack*next;//指针域
}Bstack;

//队列实现树的层序遍历
typedef struct Bque{
	//数据域.存放Bitree的指针，能节省空间；
	//如果Base是Bitree数组，那么其元素需要重新赋值
	Bitree** Base;
	int rear;
	int tail;
	int maxsize;
}Bque;

//二叉树的基本操作
Bitree* BTnit();
void BTcreate(Bitree*&Bt, int row = 1, int col = 1);
void OrderTraverse(Bitree* Bt, int row = 1, int col = 1);
void BinaryTreeCopy(Bitree* Bt, Bitree*&newtree);//复制二叉树
int Getdepth(Bitree* Bt);//获得二叉树的深度
int Getnodenum(Bitree* Bt);//获得结点的个数
int getleavenum(Bitree* Bt);//获得叶节点个数
int getonenodenum(Bitree* Bt);
int gettwonodenum(Bitree* Bt);
void Visitbyfloor(Bitree* Bt);//按层序访问

//栈操作
void Bstack_init(Bstack& BT);
//判断栈是否为空
bool Bstack_Isempty(Bstack* BT);
//入栈
void Push(Bitree* root, Bstack**BT);
//出栈
Bitree* Pop(Bstack**BT);
//非递归遍历（中序）
void StackTraverse(Bitree* Bitree);


//循环队列操作  初始化，判断是否为空，入队，出队
void Bque_init(Bque& Que);
//判断是否为空
bool Bque_isempty(Bque& Que);
//判断是否已经满
bool Bque_isfull(Bque& Que);
//入队,入队元素为Bitree*类型
void Bque_push(Bque& Que, Bitree*&Btreepointer);
//出队，出队元素是Bitree*类型
Bitree* Bque_Pop(Bque& Que);

#endif

