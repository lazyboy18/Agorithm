#ifndef _OPERATOR_H_
#define _OPERATOR_H_
typedef struct Listz
{
	int i;
	struct Listz*next;
}Listz;
//双向链表
typedef struct Dlistz
{
	int i;
	struct Dlistz*next;
	struct Dlistz*prior;
}Dlistz;
Listz*Listz_Init();//初始化
Dlistz*Dlistz_Init();//双向链表初始化
void Listz_Create(Listz*list);//非递减创建链表
void Listz_NosortCreate(Listz*list);//无排序创建链表
void DListz_NosortCreate(Dlistz*dlist);//无排序创建链表
void Listz_Show(Listz*list);//展示输出
void Dlistz_Show(Dlistz*dlist);//双向展示输出
void Listz_Integrate(Listz*LA, Listz*LB);//合并
Listz*Listz_Inverted(Listz*LA);//改为非递增
void Listz_Intersection(Listz*LA, Listz*LB);//求交集
int Listz_DifSet(Listz*LA, Listz*LB);//求差集
void Listz_Division(Listz*LA, Listz*LB, Listz*LC);//分离链表
Listz*Listz_FindMax(Listz*LA);//找最大结点
Listz* Listz_revolve(Listz*LA);//结点反向
void Listz_Secdel(Listz*LA,int mink,int maxk);//区间删除
void Dlistz_change(Dlistz*dlist);//交换双向结点
void Listz_SingleDel(Listz*list, int item);//删除单链表中值为item的结点
#endif