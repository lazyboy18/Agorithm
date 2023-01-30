#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include<iostream>
#include<string>
using namespace std;
#define QUEMAXSIZE 20
//设计第一棵树的存储结构
typedef struct BinaryTreeA {
	int data;//数据域（突出问题重点）
	struct BinaryTreeA* lChild, * rChild;
}BinaryTreeA,*Bpa;
//初始化
void Ainit(Bpa& Btree);
//采用中序创建
void Acreate(Bpa& Btree);
//求叶子结点,参数不同会引发重载
int AGetleavenum(Bpa& Btree);
//判断两棵树是否相同
bool Ais_same(Bpa& Btree1, Bpa& Btree2);
//交换二叉树的左右孩子
void AexChild(Bpa& Btree);
//双序遍历
void ADO_visit(Bpa& Btree);
//计算二叉树的最大宽度
void AGetmaxWidth(Bpa& Btree,int*arr,int floor);
//用户版本
void AGetmaxWidthApp(Bpa& tree);

//定义队列的存储结构
typedef struct Aque {
	Bpa* arr;//存储Bpa指针
	int rear, front;
	int quemaxsize;
}QAque;
//初始化
void Aque_init(Aque& aque);
//判断队列是否为空
bool Aqueis_empty(Aque& aque);
//判断循环队列是否已经满
bool Aqueis_full(Aque& aque);
//入队，入队元素是Bpa指针
void Aque_push(Aque& aque, Bpa& tree);
//出队,将出队元素放在一个载体上
void Aque_pop(Aque& aque, Bpa& carrier);
//层序遍历,为了验证变化结果
void Aque_visit(Bpa& tree);
//销毁队列
void Aque_delete(Aque& aque);


#endif