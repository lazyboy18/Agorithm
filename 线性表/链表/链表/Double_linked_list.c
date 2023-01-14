#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	写一个双向链表,实现数据来回反向打印
*/

#define Mal(typedef) (typedef*)malloc(sizeof(typedef))

struct Double_Link
{
	int data;
	struct Double_Link*prior;
	struct Double_Link*next;
};
struct Double_Link*Double_Init()
{
	struct Double_Link*double_link = Mal(struct Double_Link);
	double_link->data = 0;
	double_link->prior = NULL;
	double_link->next = NULL;
	printf("初始化成功\n");
	return double_link;
}
void Double_Create(struct Double_Link*Head)
{
	printf("请输入双向链表长度(包含表头):>");
	int length;
	scanf("%d", &length);
	getchar();
	struct Double_Link*L = Head;
	printf("输入数据:>");
	scanf("%d", &(Head->data));
	for (int i = 0; i < length-1; i++)
	{
		struct Double_Link*p = Mal(struct Double_Link);
		scanf("%d", &(p->data));
		p->prior = L;
		L->next = p;
		p->next = NULL;
		L = p;
	}
}
//int main()
//{
//	struct Double_Link*Head = Double_Init();
//	Double_Create(Head);
//	//来回反复遍历链表
//	int num;
//	printf("请输入来回次数:>");
//	scanf("%d", &num);
//	int flag = 1;//'1'表示正向输出，'0'表示逆向输出
//	struct Double_Link*temp = Head;
//	int count = 0;
//	while (num!=count)
//	{
//		if (flag)
//		{
//			//跑到终点就换向
//			//没到终点
//			if (temp->next)
//			{
//				printf("%3d", temp->data);
//				temp = temp->next;
//			}
//			else
//			{
//				//说明temp已经是终点了
//				printf("%3d", temp->data);
//				flag = 0;
//			}
//		}
//		else
//		{
//			if (temp->prior)
//			{
//				printf("%3d", temp->data);
//				temp = temp->prior;
//			}
//			else
//			{
//				//说明temp已经是起点了
//				printf("%3d", temp->data);
//				count++;
//				flag = 1;
//				printf("\n");
//			}
//		}
//	}
//	return 0;
//}