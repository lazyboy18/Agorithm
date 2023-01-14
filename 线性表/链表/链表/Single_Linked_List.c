#define _CRT_SECURE_NO_WARNINGS 
#include"Single_Content.h"
/*
	用单链表实现图书管理系统，基本操作有：
	初始化，后插法创建单链表，单独显示一本书的信息（根据书名），删除
	插入，显示，查简介，销毁
	记事本：
	别轻易使用tyoedef，你不会用
	为什么head初始化后，进入另外一个函数时就变为NULL?
	next的类型写为二级指针了
	L == NULL || strcmp(name, L->name)  当书名不符或者到达最后一个结点时可以进来
	删除时，L->next==NULL时L->next->name无意义
*/
//int main()
//{
//	//初始化
//	struct Node*head = Init();
//	int input = 0;
//	do{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			creat(head);
//			break;
//		case 2:
//			ShowSingle(head);
//			break;
//		case 3:
//			Delete(head);
//			break;
//		case 4:
//			Insert(head);
//			break;
//		case 5:
//			Show(head);
//			break;
//		case 6:
//			Clear(head);
//			break;
//		case 0:
//			Exit(head);
//			break;
//		}
//	} while (input);
//	return 0;
//}
