#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
/*
	曾出现的BUG:
	在Add_Sub_Cal()函数中,(1)误将系数当成指数、(2)循环退出时忘记链接非空表
	(3)在减法中，当pb不为空表时，pc与之链接忘记改变pb的余项的系数符号
*/
struct Pnode
{
	float ceof;
	int expn;
	struct Pnode*next;
};
//初始化
struct Pnode*Pnode_Init()
{
	struct Pnode*pnode = (struct Pnode*)malloc(sizeof(struct Pnode));
	pnode->next = NULL;
	return pnode;
}
//创建
void Pnode_Create(struct Pnode*pnode)
{
	printf("输入多项式的项数:>");
	int num;
	scanf("%d", &num);
	if (num == 0)
		return;
	struct Pnode*ptemp = pnode;
	for (int i = 1; i <= num; i++)
	{
		printf("输入第%d项的系数与指数:>",i);
		struct Pnode*p = (struct Pnode*)malloc(sizeof(struct Pnode));
		scanf("%f%d", &(p->ceof), &(p->expn));
		//用户在输入指数时要确保该指数未曾出现
		//寻找第一个比p指数大的结点，将其作为p的后驱，需要知道p的前驱
		//保留前驱，判断驱是否为空或者指数比p大
		struct Pnode*p1 = pnode;//p1是前驱
		struct Pnode*p2 = p1->next;//p2是后驱
		while (p2&&p2->expn<p->expn)
		{
			p1 = p2;
			p2 = p2->next;
		}
		p->next = p2;
		p1->next = p;
	}
	printf("多项式创建成功\n");
}
//显示多项式
void Pnode_Show(struct Pnode*pnode)
{
	struct Pnode*tpnode = pnode->next;
	//当tpnode不为空
	printf("多项式的系数:>");
	while (tpnode)
	{
		printf("%7.1f", tpnode->ceof);
		tpnode = tpnode->next;
	}
	printf("\n");
	tpnode = pnode->next;
	printf("多项式的指数:>");
	while (tpnode)
	{
		printf("%7d", tpnode->expn);
		tpnode = tpnode->next;
	}
	printf("\n");
}
struct Pnode* Add_Sub_Cal(struct Pnode*LA, struct Pnode*LB, int flag)
{
	//比较LA与LB的系数，分3种情况考虑
	struct Pnode*pa = LA->next;
	struct Pnode*pb = LB->next;
	struct Pnode*pc = LA;
	//当没有出现空表时执行循环语句
	while (pa&&pb)
	{
		if (pa->expn == pb->expn)
		{
			float sum = pa->ceof+ flag*(pb->ceof);
			if (!sum)
			{
				//当sum==0需要特殊处理,将pa与pb都消除
				struct Pnode*t1 = pa;
				struct Pnode*t2 = pb;
				pa = pa->next;
				pb = pb->next;
				free(t1);
				free(t2);
				t1 = NULL;
				t2 = NULL;
			}
			else
			{
				//改变pa的系数
				pa->ceof = sum;
				pc->next = pa;
				pc = pa;
				pa = pa->next;
				struct Pnode*t2 = pb;
				pb = pb->next;
				free(t2);
				t2 = NULL;
			}
		}
		else if (pa->expn < pb->expn)
		{
			//将pa插入pc
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pb->ceof = flag*(pb->ceof);
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	if (pb&&flag==-1)
	{
		//改变pb的系数
		struct Pnode*tpb = pb;
		while (tpb)
		{
			tpb->ceof = flag*(tpb->ceof);
			tpb = tpb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(LB);
	LB = NULL;
	return LA;
}

int main()
{
	//创建两个多项式并且赋值
	struct Pnode*LA = Pnode_Init();
	Pnode_Create(LA);
	struct Pnode*LB = Pnode_Init();
	Pnode_Create(LB);
	Pnode_Show(LA);
	Pnode_Show(LB);
	//将A与B多项式相加减并且结果由LC管理
	//第三个参数表示，当参数为1时执行加法，当参数为-1时执行减法
	struct Pnode*LC = Add_Sub_Cal(LA, LB, -1);
	Pnode_Show(LC);
	return 0;
}