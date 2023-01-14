#ifndef _Single_Content_H_
#define _Single_Content_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//typedef是关键字，此处用宏定义简化,注意此处曾出现BUG
//#define Malloc(typedef) (typedef*)malloc(sizeof(typedef))

struct Node
{
	char IBSN[30];
	char name[30];
	int price;
	char des[100];
	struct Node*next;
};
void menu();
void Exit(struct Node* head);
struct Node* Init();
void creat(struct Node* head);
struct Node* Findbyname(struct Node* head);
void ShowSingle(struct Node* head);
void Delete(struct Node* head);
void Insert(struct Node* head);
void Show(struct Node* head);
void Clear(struct Node* head);
#endif 