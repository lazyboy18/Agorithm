#define _CRT_SECURE_NO_WARNINGS 
#include"Single_Content.h"
//�˵�����
void menu()
{
	printf("************************************************\n");
	printf("********  ��ӭʹ��ͼ�����ϵͳ     *************\n");
	printf("1.����   2.����    3.ɾ��   4.����\n");
	printf("5.��ʾ   6.���    0.�˳�\n");
	printf("************************************************\n");
}
//�˳�����
void Exit(struct Node* head)
{
	Clear(head);
	free(head);
	head = NULL;
	printf("�˳��ɹ�����ӭ�´�ʹ�ã�\n");
}
//��ֵ����
void Input(struct Node*p)
{
	//�����������������������IBSN,�������۸񣬼��
	printf("-----�����������Ϣ:>\n");
	printf("����IBSN��:>");
	gets(p->IBSN);
	printf("��������:>");
	gets(p->name);
	printf("����۸�:>");
	scanf("%d", &(p->price));
	printf("������:>");
	getchar();
	gets(p->des);

}
//��ʼ������������ͷ���
struct Node* Init()
{
	struct Node*head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	//printf("��ʼ���ɹ�\n");
	//system("pause");
	//system("cls");
	return head;
}
void creat(struct Node* head)
{
	//���жϣ���������Ѿ��������ٴ���
	if (head->next!=NULL)
	{
		printf("����Ҳ���ڣ��������������\n");
		system("pause");
		system("cls");
		return;
	}
	int num;
	printf("���������ȣ�>");
	scanf("%d", &num);
	getchar();
	//�ȸ�L��ֵ
	struct Node* L = head;
	for (int i = 0; i < num; i++)
	{
		//����
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		//��ֵ
		Input(p);
		L->next = p;
		L = p;
		L->next = NULL;
	}
	printf("��Ϣ������ϣ�\n");
	printf("�������ɹ���\n");
	system("pause");
	system("cls");
}
//����--ȱ��һ��ȡֵ������֮Э��
struct Node* Findbyname(struct Node* head)
{
	char name[30] = { 0 };
	printf("���������ҵ�����:>");
	getchar();
	gets(name);
	struct Node*L = head->next;
	while (L != NULL && strcmp(name, L->name))
	{
		L = L->next;
	}
	if (L == NULL)
	{
		printf("���޴���\n");
		system("pause");
		system("cls");
		return NULL;
	}
	printf("���ҳɹ�\n");
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
		printf("��%s������Ϣ��ʾ����:>\n", temp->name);
		printf("IBSN:%s\n", temp->IBSN);
		printf("�۸�:\n", temp->price);
		printf("���:%s\n", temp->des);
		system("pause");
		system("cls");
		printf("------- ��ʾ���  ----------\n");
	}
}
void Delete(struct Node* head)
{
	if (head->next == NULL)
	{
		printf("ͼ�����ϵͳ��ʱ����\n");
		system("pause");
		system("cls");
		return;
	}

	char name[30] = { 0 };
	printf("���������ҵ�����:>");
	getchar();
	gets(name);
	//�Ҹ����ǰ��
	struct Node* L = head;
	while (strcmp(L->next->name, name) && L->next != NULL)
	{
		L = L->next;
		if (L->next == NULL)
			break;
	}
	if (L->next == NULL)
	{
		printf("���޴���\n");
		system("pause");
		system("cls");
		return ;
	}
	else
	{
		//�ȱ�����ɾ���鼮
		struct Node*q = L->next;
		L->next = L->next->next;
		free(q);
		q = NULL;
		printf("ɾ���ɹ�\n");
		system("pause");
		system("cls");
	}
}
void Insert(struct Node* head)
{
	//��ǰ����ǰ����ΪNULL
	int pos;
	printf("ѡ�����λ��:>");
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
		printf("λ�ô��󣬲���ʧ��\n");
	}
	else
	{
		printf("λ����ȷ!\n");
		getchar();
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		Input(p);
		p->next = L->next;//���ֹ�BUG
		L->next = p;
		printf("����ɹ�\n");
	}
	system("pause");
	system("cls");
}
void Show(struct Node* head)
{
	struct Node* L = head->next;
	if (L == NULL)
	{
		printf("ϵͳ��ʱ����\n");
		system("pause");
		system("cls");
		return;
	}
	int i = 1;
	printf("-------ͼ����Ϣ��ʾ����:>------\n");
	while (L != NULL)
	{
		printf("----------------------\n");
		printf("�鱾���:%d\n",i);
		printf("����:%s\n",L->name);
		printf("IBSN:%s\n", L->IBSN);
		printf("��ļ��:%s\n", L->des);
		L = L->next;
		i++;
	}
	printf("------- ȫ���鼮��ʾ���  ----------\n");
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
	printf("��ճɹ�\n");
	system("pause");
	system("cls");
}