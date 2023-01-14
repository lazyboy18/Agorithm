#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
/*
	�����ֵ�BUG:
	��Add_Sub_Cal()������,(1)��ϵ������ָ����(2)ѭ���˳�ʱ�������ӷǿձ�
	(3)�ڼ����У���pb��Ϊ�ձ�ʱ��pc��֮�������Ǹı�pb�������ϵ������
*/
struct Pnode
{
	float ceof;
	int expn;
	struct Pnode*next;
};
//��ʼ��
struct Pnode*Pnode_Init()
{
	struct Pnode*pnode = (struct Pnode*)malloc(sizeof(struct Pnode));
	pnode->next = NULL;
	return pnode;
}
//����
void Pnode_Create(struct Pnode*pnode)
{
	printf("�������ʽ������:>");
	int num;
	scanf("%d", &num);
	if (num == 0)
		return;
	struct Pnode*ptemp = pnode;
	for (int i = 1; i <= num; i++)
	{
		printf("�����%d���ϵ����ָ��:>",i);
		struct Pnode*p = (struct Pnode*)malloc(sizeof(struct Pnode));
		scanf("%f%d", &(p->ceof), &(p->expn));
		//�û�������ָ��ʱҪȷ����ָ��δ������
		//Ѱ�ҵ�һ����pָ����Ľ�㣬������Ϊp�ĺ�������Ҫ֪��p��ǰ��
		//����ǰ�����ж����Ƿ�Ϊ�ջ���ָ����p��
		struct Pnode*p1 = pnode;//p1��ǰ��
		struct Pnode*p2 = p1->next;//p2�Ǻ���
		while (p2&&p2->expn<p->expn)
		{
			p1 = p2;
			p2 = p2->next;
		}
		p->next = p2;
		p1->next = p;
	}
	printf("����ʽ�����ɹ�\n");
}
//��ʾ����ʽ
void Pnode_Show(struct Pnode*pnode)
{
	struct Pnode*tpnode = pnode->next;
	//��tpnode��Ϊ��
	printf("����ʽ��ϵ��:>");
	while (tpnode)
	{
		printf("%7.1f", tpnode->ceof);
		tpnode = tpnode->next;
	}
	printf("\n");
	tpnode = pnode->next;
	printf("����ʽ��ָ��:>");
	while (tpnode)
	{
		printf("%7d", tpnode->expn);
		tpnode = tpnode->next;
	}
	printf("\n");
}
struct Pnode* Add_Sub_Cal(struct Pnode*LA, struct Pnode*LB, int flag)
{
	//�Ƚ�LA��LB��ϵ������3���������
	struct Pnode*pa = LA->next;
	struct Pnode*pb = LB->next;
	struct Pnode*pc = LA;
	//��û�г��ֿձ�ʱִ��ѭ�����
	while (pa&&pb)
	{
		if (pa->expn == pb->expn)
		{
			float sum = pa->ceof+ flag*(pb->ceof);
			if (!sum)
			{
				//��sum==0��Ҫ���⴦��,��pa��pb������
				struct Pnode*t1 = pa;
				struct Pnode*t2 = pb;
				pa = pa->next;
				pb = pb->next;
				free(t1);
				free(t2);
				t1 = NULL;
				t2 = NULL;
			}
			else
			{
				//�ı�pa��ϵ��
				pa->ceof = sum;
				pc->next = pa;
				pc = pa;
				pa = pa->next;
				struct Pnode*t2 = pb;
				pb = pb->next;
				free(t2);
				t2 = NULL;
			}
		}
		else if (pa->expn < pb->expn)
		{
			//��pa����pc
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pb->ceof = flag*(pb->ceof);
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	if (pb&&flag==-1)
	{
		//�ı�pb��ϵ��
		struct Pnode*tpb = pb;
		while (tpb)
		{
			tpb->ceof = flag*(tpb->ceof);
			tpb = tpb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(LB);
	LB = NULL;
	return LA;
}

int main()
{
	//������������ʽ���Ҹ�ֵ
	struct Pnode*LA = Pnode_Init();
	Pnode_Create(LA);
	struct Pnode*LB = Pnode_Init();
	Pnode_Create(LB);
	Pnode_Show(LA);
	Pnode_Show(LB);
	//��A��B����ʽ��Ӽ����ҽ����LC����
	//������������ʾ��������Ϊ1ʱִ�мӷ���������Ϊ-1ʱִ�м���
	struct Pnode*LC = Add_Sub_Cal(LA, LB, -1);
	Pnode_Show(LC);
	return 0;
}