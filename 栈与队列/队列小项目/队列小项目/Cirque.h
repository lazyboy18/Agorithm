#ifndef _CIRQUE_H_
#define _CIRQUE_H_
#include<iostream>
#include<string>
using namespace std;
//指明队列的最大容量
#define MAXQSIZE 100
//
typedef struct Cirque
{
	//指针的对象指向字符串类型，字符串用于舞伴的名字
	string* base;
	int front;
	int rear;
	int maxqsize;
}Cirque;
//初始化
void Cirque_Init(Cirque*cq);
//求队长度
int Cirque_Getlen(Cirque*cq);
//出队函数需要将队头元素作为返回值
string Cirque_Out(Cirque*cq);
//入队函数传入一个string类型的参数
void Cirque_Push(Cirque*cq,string name);
//获取队头元素
string Cirque_Gethead(Cirque*cq);
//获取队尾元素
string Cirque_Gettail(Cirque*cq);
//加载舞者
void Dancer_Loading(Cirque*md, Cirque*fd);
//输出首位无匹配舞者
void First_Dancer(Cirque*md, Cirque*fd);
//多轮匹配
void Sroll_match(Cirque*md, Cirque*fd);
/*
	我还缺一个判断为空的函数
*/
#endif