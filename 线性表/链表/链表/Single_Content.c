#define _CRT_SECURE_NO_WARNINGS 
#include"Single_Content.h"
//菜单函数
void menu()
{
	printf("************************************************\n");
	printf("********  欢迎使用图书管理系统     *************\n");
	printf("1.创建   2.查找    3.删除   4.插入\n");
	printf("5.显示   6.清空    0.退出\n");
	printf("************************************************\n");
}
//退出函数
void Exit(struct Node* head)
{
	Clear(head);
	free(head);
	head = NULL;
	printf("退出成功！欢迎下次使用！\n");
}
//赋值函数
void Input(struct Node*p)
{
	//依次向数据域里面输入书的IBSN,书名，价格，简介
	printf("-----输入新书的信息:>\n");
	printf("输入IBSN号:>");
	gets(p->IBSN);
	printf("输入书名:>");
	gets(p->name);
	printf("输入价格:>");
	scanf("%d", &(p->price));
	printf("输入简介:>");
	getchar();
	gets(p->des);

}
//初始化函数，创建头结点
struct Node* Init()
{
	struct Node*head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	//printf("初始化成功\n");
	//system("pause");
	//system("cls");
	return head;
}
void creat(struct Node* head)
{
	//先判断，如果链表已经创建则不再创建
	if (head->next!=NULL)
	{
		printf("链表也存在，请进行其他操作\n");
		system("pause");
		system("cls");
		return;
	}
	int num;
	printf("输入链表长度：>");
	scanf("%d", &num);
	getchar();
	//先给L赋值
	struct Node* L = head;
	for (int i = 0; i < num; i++)
	{
		//创建
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		//赋值
		Input(p);
		L->next = p;
		L = p;
		L->next = NULL;
	}
	printf("信息输入完毕！\n");
	printf("链表创建成功！\n");
	system("pause");
	system("cls");
}
//查找--缺少一个取值操作与之协调
struct Node* Findbyname(struct Node* head)
{
	char name[30] = { 0 };
	printf("输入所查找的书名:>");
	getchar();
	gets(name);
	struct Node*L = head->next;
	while (L != NULL && strcmp(name, L->name))
	{
		L = L->next;
	}
	if (L == NULL)
	{
		printf("查无此书\n");
		system("pause");
		system("cls");
		return NULL;
	}
	printf("查找成功\n");
	system("pause");
	system("cls");
	return L;
}

void ShowSingle(struct Node* head)
{
	struct Node* temp = Findbyname(head);
	if (temp == NULL)
	{
		return;
	}
	else
	{
		printf("《%s》的信息显示如下:>\n", temp->name);
		printf("IBSN:%s\n", temp->IBSN);
		printf("价格:\n", temp->price);
		printf("简介:%s\n", temp->des);
		system("pause");
		system("cls");
		printf("------- 显示完毕  ----------\n");
	}
}
void Delete(struct Node* head)
{
	if (head->next == NULL)
	{
		printf("图书管理系统暂时无书\n");
		system("pause");
		system("cls");
		return;
	}

	char name[30] = { 0 };
	printf("输入所查找的书名:>");
	getchar();
	gets(name);
	//找该书的前驱
	struct Node* L = head;
	while (strcmp(L->next->name, name) && L->next != NULL)
	{
		L = L->next;
		if (L->next == NULL)
			break;
	}
	if (L->next == NULL)
	{
		printf("查无此书\n");
		system("pause");
		system("cls");
		return ;
	}
	else
	{
		//先保留欲删的书籍
		struct Node*q = L->next;
		L->next = L->next->next;
		free(q);
		q = NULL;
		printf("删除成功\n");
		system("pause");
		system("cls");
	}
}
void Insert(struct Node* head)
{
	//找前驱，前驱不为NULL
	int pos;
	printf("选择插入位置:>");
	scanf("%d", &pos);
	struct Node* L = head;
	int j = 0; 
	while (L != NULL)
	{
		j++;
		if (j == pos)
		{
			break;
		}
		L = L->next;
	}
	if (j != pos)
	{
		printf("位置错误，插入失败\n");
	}
	else
	{
		printf("位置正确!\n");
		getchar();
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		Input(p);
		p->next = L->next;//出现过BUG
		L->next = p;
		printf("插入成功\n");
	}
	system("pause");
	system("cls");
}
void Show(struct Node* head)
{
	struct Node* L = head->next;
	if (L == NULL)
	{
		printf("系统暂时无书\n");
		system("pause");
		system("cls");
		return;
	}
	int i = 1;
	printf("-------图书信息显示如下:>------\n");
	while (L != NULL)
	{
		printf("----------------------\n");
		printf("书本序号:%d\n",i);
		printf("书名:%s\n",L->name);
		printf("IBSN:%s\n", L->IBSN);
		printf("书的简介:%s\n", L->des);
		L = L->next;
		i++;
	}
	printf("------- 全部书籍显示完毕  ----------\n");
	system("pause");
	system("cls");
}
void Clear(struct Node* head)
{
	struct Node* L = head->next;
	while (L != NULL)
	{
		struct Node* H = L->next;
		free(L);
		L = H;
	}
	head->next = L;
	printf("清空成功\n");
	system("pause");
	system("cls");
}