#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	线性表实现图书管理系统
	(int*)malloc(sizeof(typedef)*num)
	实现如下功能：插入、输出、排序、打印、计数、修改
*/
#define false 0 
#define ture 1
#define MaxCapacity 100
#define Malloc(typedef,num) (typedef*)malloc(sizeof(typedef)*num)

//数据项类型
struct Book
{
	char ISBN[16];
	char Bookname[30];
	int price;
};
//数据对象类型
struct BookManager
{
	struct Book*Element;
	int length;
};
void Init(struct BookManager*manager)
{
	manager->length = 0;
	manager->Element = Malloc(struct Book, MaxCapacity);
	if (!(manager->Element))
	{
		printf("创建失败\n");
		return;
	}
}
void menu()
{
	printf("********************************************************\n");
	printf("1.计数、2.插入、3.排序、4.展示、5.修改、6.销毁、7、清空、0.退出\n");
	printf("********************************************************\n");
}
int is_empty(int x)
{
	if (!x)
	{
		printf("系统无书\n");
		system("pause");
		system("cls");
		return 1;
	}
	return 0;
}
int is_Destroy(int x)
{
	if (x == -1)
	{
		printf("系统已被销毁!\n");
		system("pause");
		system("cls");
		return 1;
	}
	return 0;
}
void Calculate(struct BookManager*manager)
{
	if (is_Destroy(manager->length))
	{
		return;
	}
	printf("目前图书数量为:>%d", manager->length);
	printf("\n");
	system("pause");
	system("cls");
}
void Exit()
{
	printf("退出成功！欢迎下次使用！\n");
}
void Insert(struct BookManager*manager)
{
	if (is_Destroy(manager->length))
	{
		return;
	}
	int num;
	printf("输入增加个数:>");
	scanf("%d", &num);
	int temp = num;
	if (manager->length + num > MaxCapacity)
	{
		printf("容量不足，添加失败！\n");
		system("pause");
		system("cls");
		return;
	}
	getchar();
	while (num--)
	{
		printf("-------------------------------------------\n");
		printf("输入ISBN号码:>");
		gets(manager->Element[manager->length].ISBN);
		printf("输入书名:>");
		gets(manager->Element[manager->length].Bookname);
		printf("输入该数价格:>");
		scanf("%d", &(manager->Element[manager->length].price));
		//scanf是不会吃\n的
		getchar();
		(manager->length)++;
	}
	printf("成功添加%d本书在管理系统!\n", temp);
	system("pause");
	system("cls");
}
void ManagerShow(struct BookManager*manager)
{
	if (is_Destroy(manager->length))
	{
		return;
	}
	if (is_empty(manager->length))
	{
		return;
	}
	printf("图书信息列表如下:>\n");
	printf("图书的ISBN号:\t\t书名:\t\t\t价格:\t\n");
	for (int i = 0; i < manager->length; i++)
	{
		printf("%s\t\t%s\t\t\t%d\t\n", manager->Element[i].ISBN, manager->Element[i].Bookname, manager->Element[i].price);
	}
	system("pause");
	system("cls");
}
void SortbyPrice(struct BookManager*manager)
{
	if (is_Destroy(manager->length))
	{
		return;
	}
	if (manager->length == 0)
	{
		printf("系统无书\n");
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < manager->length - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < manager->length - i - 1; j++)
		{
			if (manager->Element[j].price>manager->Element[j + 1].price)
			{
				struct Book temp = manager->Element[j];
				manager->Element[j] = manager->Element[j + 1];
				manager->Element[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	printf("降序排列成功！\n");
	system("pause");
	system("cls");
}
void Modify(struct BookManager*manager)
{
	if (is_Destroy(manager->length))
	{
		return;
	}
	if (is_empty(manager->length))
	{
		return ;
	}
	char tname[30] = { 0 };
	printf("输入被修改的书名:>");
	getchar();
	gets(tname);
	int flag = 0;
	for (int i = 0; i < manager->length; i++)
	{
		if (!strcmp(tname, manager->Element[i].Bookname))
		{
			int choice = 0;
			printf("输入1表示需要修改，输入0表示无需修改!\n");
			printf("是否修改ISBN?:>");
			scanf("%d", &choice);
			getchar();
			if (choice)
			{
				printf("输入新ISBN号:>");
				gets(manager->Element[i].ISBN);
			}
			printf("是否修改书名?:>");
			scanf("%d", &choice);
			getchar();
			if (choice)
			{
				printf("输入新书名:>");
				gets(manager->Element[i].Bookname);
			}
			printf("是否修改价格?:>");
			scanf("%d", &choice);
			getchar();
			if (choice)
			{
				printf("输入新价格:>");
				scanf("%d", &(manager->Element[i].price));
			}
			printf("信息修改成功!\n");
			system("pause");
			system("cls");
			return;
		}
	}
	if (flag == 0)
	{
		printf("该书不存在!\n");
		system("pause");
		system("cls");
	}
}
void Clear(struct BookManager*manager)
{
	if (is_Destroy(manager->length))
	{
		return;
	}
	free(manager->Element);
	manager->Element = NULL;
	Init(manager);
	printf("清空成功\n");
	system("pause");
	system("cls");
}
void Destroy(struct BookManager*manager)
{
	free(manager->Element);
	manager->Element = NULL;
	manager->length = -1;
	printf("系统销毁成功\n");
	system("pause");
	system("cls");
}

int main()
{
	//定义一个图书管理系统
	struct BookManager manager;
	//初始化
	Init(&manager);
	int input = 0;
	do{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calculate(&manager);
			break;
		case 2:
			Insert(&manager);
			break;
		case 3:
			SortbyPrice(&manager);
			break;
		case 4:
			ManagerShow(&manager);
			break;
		case 5:
			Modify(&manager);
			break;
		case 6:
			Destroy(&manager);
			break;
		case 7:
			Clear(&manager);
			break;
		case 0:
			Exit();
			break;
		}
	} while (input);
	return 0;
}



