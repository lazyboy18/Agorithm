#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include"Operator.h"
/*
	思想方法：
	（1）由于算法题的三个小问都适用于这一套模块，
	所以三道题基本操作都相同，只是实现最终目的的函数不同；
	（2）如果涉及删除、插入操作，那么需要找该结点的后驱
	注意点：
	（1）务必在每一个操作后判断是否需要更改结点或者把结点复位
	分析：
	（1）该算法也可以处理非递减或非递增链表的合并
*/

//测试打印输出
void test01()
{
	//初始化
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	//创建且自带非递减排序功能
	Listz_Create(LA);
	Listz_Create(LB);
	//展示输出链表元素
	Listz_Show(LA);
	Listz_Show(LB);
}
void test02()
{
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	Listz_Create(LA);
	Listz_Create(LB);
	//合并两个链表，新链表依旧是非递减的
	Listz_Integrate(LA, LB);
	Listz_Show(LA);
}
//求逆表
void test03()
{
	Listz*LA = Listz_Init();
	Listz_Create(LA);
	Listz_Inverted(LA);
	Listz_Show(LA);
}
//求差集
void test04()
{
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	Listz_Create(LA);
	Listz_Create(LB);
	Listz_Intersection(LA, LB);
	Listz_Show(LA);
}
void test05()
{
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	Listz_Create(LA);
	Listz_Create(LB);
	int ret=Listz_DifSet(LA, LB);
	Listz_Show(LA);
	printf("ret=%d\n", ret);
}
void test06()
{
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	Listz*LC = Listz_Init();
	Listz_NosortCreate(LA);
	Listz_Division(LA, LB,LC);
	Listz_Show(LB);
	Listz_Show(LC);

}
void test07()
{
	Listz*LA = Listz_Init();
	Listz_NosortCreate(LA);
	Listz*maxNode = Listz_FindMax(LA);
	printf("maxNode->i=%d\n", maxNode->i);
}
void test08()
{
	Listz*LA = Listz_Init();
	Listz_NosortCreate(LA);
	Listz*Lnew=Listz_revolve(LA);
	Listz_Show(Lnew);
}
void test09()
{
	Listz*LA = Listz_Init();
	Listz_NosortCreate(LA);
	Listz_Secdel(LA, 4, 6);
	Listz_Show(LA);
}
void test10()
{
	Dlistz*DLA = Dlistz_Init();
	DListz_NosortCreate(DLA);
	//Dlistz_Show(DLA);
	Dlistz_change(DLA);
	Dlistz_Show(DLA);
}
void test11()
{
	Listz*LA = Listz_Init();
	Listz_NosortCreate(LA);
	Listz_Show(LA);
	Listz_SingleDel(LA,10);
	Listz_Show(LA);
}
void test12()
{
	Listz*LA = Listz_Init();
	Listz_Create(LA);
	Listz_Show(LA);
	Listz*LB = Listz_Init();
	Listz_Create(LB);
	Listz_Show(LB);
	Listz_Intersection(LA, LB);
	Listz_Show(LA);

}

int main()
{
	//测试打印输出
//	test01();
	//合并
//	test02();
	//求逆表
//	test03();
	//求差集
//	test04();
	//求差集
//	test05();
	//分解LA为LB
//	test06();
	//求最大结点
//	test07();
	//结点原地转
	//test08();
	//删除在区间里面的结点
//	test09();
	//交换双向链表结点与其前驱
	//test10();
	//删除值为item的值
	//test11();
	//求并集
	test12();
	return 0;
}