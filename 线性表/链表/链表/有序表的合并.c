#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>

//这是一道书本的例题，再次实现以便
/*
	实现两个非递减集合的合并
*/

struct Col
{
	int i;
	struct Col*next;
};
//初始化
struct Col*Col_Init()
{
	struct Col*col = (struct Col*)malloc(sizeof(struct Col));
	col->next = NULL;
	return col;
}
//创建
void Col_Create(struct Col*col)
{
	printf("输入链表长度:>");
	int num;
	scanf("%d", &num);
	if (num == 0)
		return;
	struct Col*L = col;
	printf("输入数据:>");
	for (int i = 0; i < num; i++)
	{
		struct Col*p = (struct Col*)malloc(sizeof(struct Col));
		scanf("%d", &(p->i));
		L->next = p;
		L = p;
		L->next = NULL;
	}
	printf("链表创建成功\n");
}
//输出链表
void Col_Show(struct Col*col)
{
	printf("链表数据输出如下:>\n");
	struct Col*L = col->next;
	int flag = 1;
	while (L)
	{
		if (flag == 1)
			flag = 0;
		printf("%3d", L->i);
		L = L->next;
	}
	if (flag == 1)
		printf("空表");
	printf("\n");
}
/*
	链表的合并方法的精髓在于创建一个新空表，
	然后调整原LA与LB的结点链接顺序即可，
	这过程只产生了少量的辅助空间，相比于
	顺序表而言空间效率大大提升，而且顺序表
	的存取优势在这种情况下不突出，所以
	用链表优势最大
*/
//int main()
//{
//	//创建两个链表
//	struct Col*LA = Col_Init();
//	struct Col*LB = Col_Init();
//	//输入有序链表
//	Col_Create(LA);
//	Col_Create(LB);
//	Col_Show(LA);
//	Col_Show(LB);
//	//归并两个链表，新表依旧是有序表
//	struct Col*LC = LA;
//	//当没有出现空表的时候，需要逐一比较两个表的元素
//	struct Col*pa = LA->next;
//	struct Col*pb = LB->next;
//	struct Col*pc = LC;
//	while (pa&&pb)
//	{
//		if (pa->i <= pb->i)
//		{
//			//加入pa结点
//			pc->next = pa;
//			pc = pa;
//			pa = pa->next;
//		}
//		else
//		{
//			pc->next = pb;
//			pc = pb;
//			pb = pb->next;
//		}
//	}
//	pc->next = pa ? pa : pb;
//	free(LB);
//	LB = NULL;
//	Col_Show(LC);
//	return 0;
//}