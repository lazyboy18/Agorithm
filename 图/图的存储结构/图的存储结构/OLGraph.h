#pragma once
#include<iostream>
using namespace std;
/*
	为了解决图在邻接表中寻找出入度个数的难题，
	我们选择使用十字链表。
	顶点结点链表依旧采用顺序存储结构，弧结点依旧
	采用出入度链接指针作为指针域

	对于顶点结点vexNode而言，数据领为data,数据类型为vexType
	firstin与firstout分别指向该顶点的第一条入度弧与第一条出度弧
	数据类型为ArcBox;

	对于弧结点arcNode而言，其数据类型有tailvex与headvex，分别
	指代该弧的弧尾结点与弧头结点;tlink与hlink分别指代弧尾与弧头相同的
	下一个弧结点;很显然，每确定一条路径<v1,v2>就需要同时修改
	v1的firstout与v2的firstin,同时每一个弧结点在创建之时，tlink指向
	v1现任第一个出度弧(同样以v1为弧尾),hlink指向v2的现任第一条入度弧
	（同样以v2为弧头）
*/


#define Maxw 100000
#define Maxvex 100    //最大顶点数
//定义权值与顶点的信息类型
typedef int OtherInfo;
typedef int vexType;

//定义弧结点
typedef struct ArcBox {
	//出度与入度结点编号
	int tailvex, headvex;
	//与该弧有相同出度点的弧，与该弧有相同入度点的弧
	struct ArcBox* tlink, * hlink;
	OtherInfo w;
}ArcBox;
//定义顶点存储结构
typedef struct VexNode {
	vexType data;
	//第一条入度边结点与第一条出度边
	struct ArcBox* firstin, * firstout;
}VexNode;
//定义十字链表
typedef struct OLGraph {
	VexNode xlist[Maxvex];//数组有最大容量
	int vexnum, arcnum;//顶点与弧的个数
}OLGraph;
//创建十字链表
void CreateUDNol(OLGraph& G);

