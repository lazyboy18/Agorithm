#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	ָ�����ʽ������ʵ�ʲ���
*/


/*
	дһ��ѭ������������ʼ����������������
	����ʵ��ѭ��������������
*/

#define Mal(typedef) (typedef*)malloc(sizeof(typedef))


struct Cir_Link
{
	int i;
	struct Cir_Link*next;
};
//��ʼ������
struct Cir_Link* Cir_Init( )
{
	struct Cir_Link* cir = Mal(struct Cir_Link);
	cir->i = 1;
	cir->next = cir;
	printf("��ʼ���ɹ�\n");
	return cir;
}
void Cir_InsertBytail(struct Cir_Link** tail)
{
	//���ڱ�β
	struct Cir_Link* p = Mal(struct Cir_Link);
	printf("�����β����:>");
	scanf("%d", &(p->i));
	p->next = (*tail)->next;
	(*tail)->next = p;
	*tail = p;
	printf("��β����ɹ�\n");
	system("pause");
	system("cls");
}
void Cir_menu()
{
	printf("---------------------------------\n");
	printf("-1.�ڱ�β����  2.��ʾ  0.�˳�----\n");
	printf("---------------------------------\n");
}
void Cir_Show(struct Cir_Link*tail)
{
	printf("������ѭ������:>");
	int num;
	scanf("%d", &num);
	int count = 0;
	printf("�������:>\n");
	struct Cir_Link* TempTail = tail->next;
	while (1)
	{
		if (count == num)
		{
			break;
		}
		if (TempTail == tail)
		{
			//������β��ʱ�������ӡ
			printf("%3d", TempTail->i);
			count++;
			printf("\n");
		}
		else
		printf("%3d", TempTail->i);
		TempTail = TempTail->next;
	}
	printf("��ʾ���\n");
	system("pause");
	system("cls");
}
//int main()
//{
//	//���������ʼ��,��ʵ��main�����ʼ��Ҳ���ԣ�
//	//��������Ҫϰ�߷�װ�����Գ�ʼ������Ϊ�������������ظ�����
//	//�����ں��ڳ�ʼ�����ݽ϶�ʱ��д��mian�����Եù����Բ���ͻ����
//	struct Cir_Link*tail = Cir_Init();
//	//�ڲ���ѭ������ʱ������ϰ���ñ�β����cir��ʱ���Ǳ�ͷ���Ǳ�β
//	int input = 0;
//	do{
//		Cir_menu();
//		printf("�����빦�ܼ�:>");
//		scanf("%d", &input);
//		getchar();
//		switch (input)
//		{
//		case 1:
//			//��Ҫ�ı�tail��ָ����Ҫ��ָ��
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