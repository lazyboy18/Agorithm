#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>

//����һ���鱾�����⣬�ٴ�ʵ���Ա�
/*
	ʵ�������ǵݼ����ϵĺϲ�
*/

struct Col
{
	int i;
	struct Col*next;
};
//��ʼ��
struct Col*Col_Init()
{
	struct Col*col = (struct Col*)malloc(sizeof(struct Col));
	col->next = NULL;
	return col;
}
//����
void Col_Create(struct Col*col)
{
	printf("����������:>");
	int num;
	scanf("%d", &num);
	if (num == 0)
		return;
	struct Col*L = col;
	printf("��������:>");
	for (int i = 0; i < num; i++)
	{
		struct Col*p = (struct Col*)malloc(sizeof(struct Col));
		scanf("%d", &(p->i));
		L->next = p;
		L = p;
		L->next = NULL;
	}
	printf("�������ɹ�\n");
}
//�������
void Col_Show(struct Col*col)
{
	printf("���������������:>\n");
	struct Col*L = col->next;
	int flag = 1;
	while (L)
	{
		if (flag == 1)
			flag = 0;
		printf("%3d", L->i);
		L = L->next;
	}
	if (flag == 1)
		printf("�ձ�");
	printf("\n");
}
/*
	����ĺϲ������ľ������ڴ���һ���¿ձ�
	Ȼ�����ԭLA��LB�Ľ������˳�򼴿ɣ�
	�����ֻ�����������ĸ����ռ䣬�����
	˳�����Կռ�Ч�ʴ������������˳���
	�Ĵ�ȡ��������������²�ͻ��������
	�������������
*/
//int main()
//{
//	//������������
//	struct Col*LA = Col_Init();
//	struct Col*LB = Col_Init();
//	//������������
//	Col_Create(LA);
//	Col_Create(LB);
//	Col_Show(LA);
//	Col_Show(LB);
//	//�鲢���������±������������
//	struct Col*LC = LA;
//	//��û�г��ֿձ��ʱ����Ҫ��һ�Ƚ��������Ԫ��
//	struct Col*pa = LA->next;
//	struct Col*pb = LB->next;
//	struct Col*pc = LC;
//	while (pa&&pb)
//	{
//		if (pa->i <= pb->i)
//		{
//			//����pa���
//			pc->next = pa;
//			pc = pa;
//			pa = pa->next;
//		}
//		else
//		{
//			pc->next = pb;
//			pc = pb;
//			pb = pb->next;
//		}
//	}
//	pc->next = pa ? pa : pb;
//	free(LB);
//	LB = NULL;
//	Col_Show(LC);
//	return 0;
//}