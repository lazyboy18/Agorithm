#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	дһ��˫������,ʵ���������ط����ӡ
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
	printf("��ʼ���ɹ�\n");
	return double_link;
}
void Double_Create(struct Double_Link*Head)
{
	printf("������˫��������(������ͷ):>");
	int length;
	scanf("%d", &length);
	getchar();
	struct Double_Link*L = Head;
	printf("��������:>");
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
//	//���ط�����������
//	int num;
//	printf("���������ش���:>");
//	scanf("%d", &num);
//	int flag = 1;//'1'��ʾ���������'0'��ʾ�������
//	struct Double_Link*temp = Head;
//	int count = 0;
//	while (num!=count)
//	{
//		if (flag)
//		{
//			//�ܵ��յ�ͻ���
//			//û���յ�
//			if (temp->next)
//			{
//				printf("%3d", temp->data);
//				temp = temp->next;
//			}
//			else
//			{
//				//˵��temp�Ѿ����յ���
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
//				//˵��temp�Ѿ��������
//				printf("%3d", temp->data);
//				count++;
//				flag = 1;
//				printf("\n");
//			}
//		}
//	}
//	return 0;
//}