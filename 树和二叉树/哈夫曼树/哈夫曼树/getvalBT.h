#ifndef _GETVABT_H_
#define _GETVABT_H_
#include<iostream>
using namespace std;
#define MAXSIZE 20
/*
	求值表达式的二叉树的叶子结点一定是操作数
	规定二叉树的数据域为整型类型，该整型类型数据在
	二叉树创建后非叶子结点都是运算符对应的ACSI码值

	数据结构有二叉树与树栈，树栈的元素是二叉树
*/

//二叉树的数据结构
typedef struct valBT
{
	int val;
	struct valBT*lchild, *rchild;
}valBT;
//栈的数据结构
typedef struct valstack
{
	valBT**arr;//存放二叉树的指针
	int top;
}valstack;
//创建二叉树
void createBT(valBT*& B, valBT*& LB, valBT*& RB, const int i);
//创建两个栈区,先初始化
void valStackinit(valstack& vals);
//栈空？
bool is_emptyss(valstack& vals);
//栈满？
bool is_full(valstack& vals);
//入栈
void valPush(valstack& vals, valBT*& B);
//出栈,弹出指针
void valPop(valstack& vals, valBT*& B);
//获取栈顶元素
char Getval(valstack& vals);
//判断是否为数字
bool is_char(const char& ch);
//比较字符优先级
char cCompare(const char&c1, const char&c2);
//算法核心，上面所有的函数,用户直接调用
void coreCalulate();
//获取最终结果
int getresult(valBT*& resulttree);
//通过字符求算
int getbyOP(valBT*&op, valBT*&num1, valBT*&num2);
#endif