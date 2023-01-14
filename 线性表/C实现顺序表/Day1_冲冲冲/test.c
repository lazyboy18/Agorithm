#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	���Ա�ʵ��ͼ�����ϵͳ
	(int*)malloc(sizeof(typedef)*num)
	ʵ�����¹��ܣ����롢��������򡢴�ӡ���������޸�
*/
#define false 0 
#define ture 1
#define MaxCapacity 100
#define Malloc(typedef,num) (typedef*)malloc(sizeof(typedef)*num)

//����������
struct Book
{
	char ISBN[16];
	char Bookname[30];
	int price;
};
//���ݶ�������
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
		printf("����ʧ��\n");
		return;
	}
}
void menu()
{
	printf("********************************************************\n");
	printf("1.������2.���롢3.����4.չʾ��5.�޸ġ�6.���١�7����ա�0.�˳�\n");
	printf("********************************************************\n");
}
int is_empty(int x)
{
	if (!x)
	{
		printf("ϵͳ����\n");
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
		printf("ϵͳ�ѱ�����!\n");
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
	printf("Ŀǰͼ������Ϊ:>%d", manager->length);
	printf("\n");
	system("pause");
	system("cls");
}
void Exit()
{
	printf("�˳��ɹ�����ӭ�´�ʹ�ã�\n");
}
void Insert(struct BookManager*manager)
{
	if (is_Destroy(manager->length))
	{
		return;
	}
	int num;
	printf("�������Ӹ���:>");
	scanf("%d", &num);
	int temp = num;
	if (manager->length + num > MaxCapacity)
	{
		printf("�������㣬���ʧ�ܣ�\n");
		system("pause");
		system("cls");
		return;
	}
	getchar();
	while (num--)
	{
		printf("-------------------------------------------\n");
		printf("����ISBN����:>");
		gets(manager->Element[manager->length].ISBN);
		printf("��������:>");
		gets(manager->Element[manager->length].Bookname);
		printf("��������۸�:>");
		scanf("%d", &(manager->Element[manager->length].price));
		//scanf�ǲ����\n��
		getchar();
		(manager->length)++;
	}
	printf("�ɹ����%d�����ڹ���ϵͳ!\n", temp);
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
	printf("ͼ����Ϣ�б�����:>\n");
	printf("ͼ���ISBN��:\t\t����:\t\t\t�۸�:\t\n");
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
		printf("ϵͳ����\n");
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
	printf("�������гɹ���\n");
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
	printf("���뱻�޸ĵ�����:>");
	getchar();
	gets(tname);
	int flag = 0;
	for (int i = 0; i < manager->length; i++)
	{
		if (!strcmp(tname, manager->Element[i].Bookname))
		{
			int choice = 0;
			printf("����1��ʾ��Ҫ�޸ģ�����0��ʾ�����޸�!\n");
			printf("�Ƿ��޸�ISBN?:>");
			scanf("%d", &choice);
			getchar();
			if (choice)
			{
				printf("������ISBN��:>");
				gets(manager->Element[i].ISBN);
			}
			printf("�Ƿ��޸�����?:>");
			scanf("%d", &choice);
			getchar();
			if (choice)
			{
				printf("����������:>");
				gets(manager->Element[i].Bookname);
			}
			printf("�Ƿ��޸ļ۸�?:>");
			scanf("%d", &choice);
			getchar();
			if (choice)
			{
				printf("�����¼۸�:>");
				scanf("%d", &(manager->Element[i].price));
			}
			printf("��Ϣ�޸ĳɹ�!\n");
			system("pause");
			system("cls");
			return;
		}
	}
	if (flag == 0)
	{
		printf("���鲻����!\n");
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
	printf("��ճɹ�\n");
	system("pause");
	system("cls");
}
void Destroy(struct BookManager*manager)
{
	free(manager->Element);
	manager->Element = NULL;
	manager->length = -1;
	printf("ϵͳ���ٳɹ�\n");
	system("pause");
	system("cls");
}

int main()
{
	//����һ��ͼ�����ϵͳ
	struct BookManager manager;
	//��ʼ��
	Init(&manager);
	int input = 0;
	do{
		menu();
		printf("��ѡ��:>");
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



