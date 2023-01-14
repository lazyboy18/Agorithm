#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include"Operator.h"
#define Mal(typedef) (typedef*)malloc(sizeof(typedef))

//初始化
Listz*Listz_Init()
{
	Listz*list=Mal(Listz);
	list->next = NULL;
	return list;
}
//创建链表，要求自动排序
void Listz_Create(Listz*list)
{
	printf("请输入链表的长度:>");
	int num;
	Listz*p = list;
	scanf("%d", &num);
	printf("请输入数据:>");
	for (int i = 1; i <= num; i++)
	{
		Listz*temp = Mal(Listz);
		scanf("%d", &(temp->i));
		//插入找前驱
		while (p->next)
		{
			//将p插在比它大的第一个结点前面
			if (p->next->i <= temp->i)
			{
				p = p->next;
			}
			else
				break;
		}
		temp->next = p->next;
		p->next = temp;
		p = list;//p需要重新赋值
	}
}
//无序创表
void Listz_NosortCreate(Listz*list)
{
	printf("请输入链表的长度:>");
	int num;
	Listz*p = list;
	scanf("%d", &num);
	printf("请输入数据:>");
	for (int i = 1; i <= num; i++)
	{
		Listz*temp = Mal(Listz);
		scanf("%d", &(temp->i));
		p->next = temp;
		temp->next = NULL;
		p = temp;
	}
}

//输出链表内容
void Listz_Show(Listz*list)
{
	printf("链表数据输出如下:>\n");
	if (list->next == NULL)
	{
		printf("空表\n");
		return;
	}
	Listz*p = list->next;
	while (p)
	{
		printf("%5d", p->i);
		p = p->next;
	}
	printf("\n");
}
//合并
void Listz_Integrate(Listz*LA, Listz*LB)
{
	Listz*pa = LA->next;
	Listz*pb = LB->next;
	Listz*pc = LA;
	while (pa&&pb)
	{
		if (pa->i <= pb->i)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	printf("合并成功\n");
}
//将非递减链表变为非递增
Listz*Listz_Inverted(Listz*LA)
{
	//创建临时指针
	Listz*tmpList = Mal(Listz);
	tmpList->next = NULL;
	Listz*List = LA->next;
	while (List)
	{
		//第一次指向空
		Listz*tmpList2 = List->next;//关键一步
		List->next = tmpList->next;
		tmpList->next = List;
		List = tmpList2;
	}
	LA->next = tmpList->next;
	free(tmpList);
	tmpList = NULL;
	printf("链表逆序成功\n");
}
//求交集
void Listz_Intersection(Listz*LA, Listz*LB)
{
	//保留LA
	//老版本
	//只需要依次取出LA的元素，与LB的元素逐一对比
	//若元素同则保留该元素，删除LB相应元素；否则，删除LA相应元素
	//由于涉及删除操作，故需要找pa，pb的后驱，对后驱做删除操作
	//新版本
	//利用元素递增的特性，只要LB的元素小于或等于LA就可以删除
	Listz*pa = LA;//找前驱
	Listz*pb = LB;
	while (pa->next&&pb->next)
	{
		//分两种情况，如果pb过长，pa->next为NULL，否则pb->next为NULL
		//第一种情况，可以求出pa的并集
		if (pa->next->i > pb->next->i)
		{
			//在pa->next之后不可能有与pb->next相同的元素
			Listz*t1 = pb->next;
			pb->next = pb->next->next;
			free(t1);
			t1 = NULL;
		}
		else if (pa->next->i == pb->next->i)
		{
			Listz*t1 = pb->next;
			pb->next = pb->next->next;
			free(t1);
			t1 = NULL;
			//说明pa->next没事了
			pa = pa->next;
		}
		else
		{
			Listz*t1 = pa->next;
			pa->next = pa->next->next;
			free(t1);
			t1 = NULL;
		}
	}
	//输出LB链表
	if (pb->next == NULL)
	{
		free(pb);
		while (pa->next)
		{
			Listz*t1 = pa->next;
			pa->next = pa->next->next;
			free(t1);
			t1 = NULL;
		}
	}
	else
	{
		while (pb)
		{
			Listz*t1 = pb->next;
			free(pb);
			pb = t1;
		}
	}
	printf("交集求算成功\n");
}

//求两个集合的差集，要求集合元素递增，且放回新结点,退出函数前需要把LA的头结点与LB整条链销毁
int Listz_DifSet(Listz*LA, Listz*LB)
{
	//找删除结点的前驱
	Listz*pa = LA;
	Listz*pb = LB;
	int count = 0;
	//如果LB的元素与LA的相同两个都删，两个都移位；如果LB小于LA，就删LB，否则LA移位；
	//这是利用元素递增的特点
	while (pa->next&&pb->next)
	{
		//时间复杂度为O(n)
		if (pb->next->i < pa->next->i)
		{
			//删除pb->next->i
			Listz*t1 = pb->next;
			pb->next = pb->next->next;
			free(t1);
			t1 = NULL;
		}
		else if (pb->next->i == pa->next->i)
		{
			Listz*t1 = pb->next;
			Listz*t2 = pa->next;
			pb->next = pb->next->next;
			pa->next = pa->next->next;
			free(t1);
			t1 = NULL;
			free(t2);
			t2 = NULL;
		}
		else
		{
			//说明pa结点可以保留
			count++;
			//正确的移位方式 
			pa = pa->next;
		}
	}
	//彻底删除pb
	pb = LB;
	while (pb)
	{
		Listz*t1 = pb->next;
		free(pb);
		pb = t1;
	}
	printf("求差集成功\n");
	return count;
}

//分解LA，非为正数表LC与负数表LB
void Listz_Division(Listz*LA, Listz*LB, Listz*LC)
{
	Listz*pa = LA->next;
	Listz*pb = LB;
	Listz*pc = LC;
	while (pa)
	{
		//先比较pa结点的大小
		if (pa->i > 0)
		{
			pc->next = pa;
			pa = pa->next;
			pc->next->next = NULL;
			pc = pc->next;
		}
		else if (pa->i < 0)
		{
			pb->next = pa;
			pa = pa->next;
			pb->next->next = NULL;
			pb = pb->next;
		}
		else
		{
			pa = pa->next;
		}
	}
	printf("链表分解成功\n");
}
//求最大结点
Listz*Listz_FindMax(Listz*LA)
{
	Listz*pa = LA->next;
	Listz*max = pa;
	pa = pa->next;
	while (pa)
	{
		if (pa->i > max->i)
		{
			max = pa;
		}
		pa = pa->next;
	}
	return max;
}
Listz* Listz_revolve(Listz*LA)
{
	Listz*p = LA;
	Listz*t1 = p->next;
	free(LA);
	p = NULL;
	while (t1)
	{
		Listz*t2 = t1;
		t1 = t1->next;
		t2->next = p;
		p = t2;
	}
	Listz*Lnew = Mal(Listz);
	Lnew->next = p;
	printf("结点逆转成功，返回新头结点\n");
	return Lnew;
}
void Listz_Secdel(Listz*LA, int mink, int maxk)
{
	//删除操作找前驱，符合条件删除，否则移位
	Listz*p = LA;
	//找前驱
	while (p->next)
	{
		if (p->next->i > mink&&p->next->i < maxk)
		{
			//输出p->next
			Listz*tmp = p->next;
			p->next = tmp->next;
			free(tmp);
			tmp = NULL;
		}
		else
			p = p->next;//否则移位
	}
	printf("区间删除成功\n");
}
//初始化
Dlistz*Dlistz_Init()
{
	Dlistz*dlist = Mal(Dlistz);
	dlist->next = NULL;
	dlist->prior = NULL;
	return dlist;
}
//双向创建
void DListz_NosortCreate(Dlistz*dlist)
{
	Dlistz*p = dlist;
	printf("输入双向链表的长度:>");
	int num;
	scanf("%d", &num);
	printf("输入数据:>");
	for (int i = 1; i <= num; i++)
	{
		Dlistz*tmp = Mal(Dlistz);
		scanf("%d", &(tmp->i));
		p->next = tmp;
		tmp->prior = p;
		p = tmp;
		p->next = NULL;
	}
	printf("双向链表创建成功\n");
}
void Dlistz_Show(Dlistz*dlist)
{
	printf("双向链表数据输出如下:>\n");
	if (dlist->next == NULL)
	{
		printf("空表\n");
		return;
	}
	Listz*p = dlist->next;
	while (p)
	{
		printf("%5d", p->i);
		p = p->next;
	}
	printf("\n");
}
void Dlistz_change(Dlistz*dlist)
{
	//交换结点与它的前驱
	Dlistz*p = dlist;
	if (p->next == NULL)
	{
		return;
	}
	printf("输入该所交换结点的数据域:>");
	int dat;
	scanf("%d", &dat);
	while (p&&p->i != dat)
	{
		p = p->next;
	}
	if (p == NULL)
		printf("该结点不存在\n");
	else if (p->prior->prior == NULL)
	{
		printf("无法交换\n");
	}
	else
	{
		Dlistz*t = p->prior->prior;
		p->prior->prior->next = p;
		p->next->prior = p->prior;
		p->prior->next = p->next;
		p->prior->prior = p;
		p->next = p->prior;
		p->prior = t;
		printf("结点交换成功\n");
	}
}
void Listz_SingleDel(Listz*list,int item)
{
	//删除单链表中值为item的结点，时间复杂度为O(n)、空间复杂度为O(1)
	Listz*p = list;
	if (p->next == NULL)
		return;
	while (p->next)
	{
		if (p->next->i == item)
		{
			Listz*t = p->next;
			p->next = p->next->next;
			free(t);
			t = NULL;
		}
		else
		p = p->next;
	}
	printf("成功输出链表中值为item的结点\n");
}