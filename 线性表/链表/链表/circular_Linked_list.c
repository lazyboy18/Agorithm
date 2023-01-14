#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	指针的形式参数与实际参数
*/


/*
	写一个循环链表，包括初始化、插入两个操作
	另外实现循环输出表的数据域
*/

#define Mal(typedef) (typedef*)malloc(sizeof(typedef))


struct Cir_Link
{
	int i;
	struct Cir_Link*next;
};
//初始化函数
struct Cir_Link* Cir_Init( )
{
	struct Cir_Link* cir = Mal(struct Cir_Link);
	cir->i = 1;
	cir->next = cir;
	printf("初始化成功\n");
	return cir;
}
void Cir_InsertBytail(struct Cir_Link** tail)
{
	//查在表尾
	struct Cir_Link* p = Mal(struct Cir_Link);
	printf("输入表尾数据:>");
	scanf("%d", &(p->i));
	p->next = (*tail)->next;
	(*tail)->next = p;
	*tail = p;
	printf("表尾插入成功\n");
	system("pause");
	system("cls");
}
void Cir_menu()
{
	printf("---------------------------------\n");
	printf("-1.在表尾插入  2.显示  0.退出----\n");
	printf("---------------------------------\n");
}
void Cir_Show(struct Cir_Link*tail)
{
	printf("请输入循环次数:>");
	int num;
	scanf("%d", &num);
	int count = 0;
	printf("输出如下:>\n");
	struct Cir_Link* TempTail = tail->next;
	while (1)
	{
		if (count == num)
		{
			break;
		}
		if (TempTail == tail)
		{
			//遍历到尾部时在这里打印
			printf("%3d", TempTail->i);
			count++;
			printf("\n");
		}
		else
		printf("%3d", TempTail->i);
		TempTail = TempTail->next;
	}
	printf("显示完成\n");
	system("pause");
	system("cls");
}
//int main()
//{
//	//变量必须初始化,其实在main里面初始化也可以，
//	//但是我们要习惯封装函数以初始化，因为函数不仅可以重复利用
//	//而且在后期初始化内容较多时，写在mian里面显得功能性不够突出了
//	struct Cir_Link*tail = Cir_Init();
//	//在操作循环链表时，我们习惯用表尾，而cir此时即是表头又是表尾
//	int input = 0;
//	do{
//		Cir_menu();
//		printf("请输入功能键:>");
//		scanf("%d", &input);
//		getchar();
//		switch (input)
//		{
//		case 1:
//			//若要改变tail的指向需要传指针
//			Cir_InsertBytail(&tail);
//			break;
//		case 2:
//			Cir_Show(tail);
//			break;
//		case 0:
//			printf("Exit Successfully\n");
//			break;
//		default :
//			printf("Erro Input\n");
//			break;
//		}
//
//	} while (input);
//
//
//	return 0;
//}