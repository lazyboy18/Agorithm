#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include"Operator.h"
#define Mal(typedef) (typedef*)malloc(sizeof(typedef))

//��ʼ��
Listz*Listz_Init()
{
	Listz*list=Mal(Listz);
	list->next = NULL;
	return list;
}
//��������Ҫ���Զ�����
void Listz_Create(Listz*list)
{
	printf("����������ĳ���:>");
	int num;
	Listz*p = list;
	scanf("%d", &num);
	printf("����������:>");
	for (int i = 1; i <= num; i++)
	{
		Listz*temp = Mal(Listz);
		scanf("%d", &(temp->i));
		//������ǰ��
		while (p->next)
		{
			//��p���ڱ�����ĵ�һ�����ǰ��
			if (p->next->i <= temp->i)
			{
				p = p->next;
			}
			else
				break;
		}
		temp->next = p->next;
		p->next = temp;
		p = list;//p��Ҫ���¸�ֵ
	}
}
//���򴴱�
void Listz_NosortCreate(Listz*list)
{
	printf("����������ĳ���:>");
	int num;
	Listz*p = list;
	scanf("%d", &num);
	printf("����������:>");
	for (int i = 1; i <= num; i++)
	{
		Listz*temp = Mal(Listz);
		scanf("%d", &(temp->i));
		p->next = temp;
		temp->next = NULL;
		p = temp;
	}
}

//�����������
void Listz_Show(Listz*list)
{
	printf("���������������:>\n");
	if (list->next == NULL)
	{
		printf("�ձ�\n");
		return;
	}
	Listz*p = list->next;
	while (p)
	{
		printf("%5d", p->i);
		p = p->next;
	}
	printf("\n");
}
//�ϲ�
void Listz_Integrate(Listz*LA, Listz*LB)
{
	Listz*pa = LA->next;
	Listz*pb = LB->next;
	Listz*pc = LA;
	while (pa&&pb)
	{
		if (pa->i <= pb->i)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	printf("�ϲ��ɹ�\n");
}
//���ǵݼ������Ϊ�ǵ���
Listz*Listz_Inverted(Listz*LA)
{
	//������ʱָ��
	Listz*tmpList = Mal(Listz);
	tmpList->next = NULL;
	Listz*List = LA->next;
	while (List)
	{
		//��һ��ָ���
		Listz*tmpList2 = List->next;//�ؼ�һ��
		List->next = tmpList->next;
		tmpList->next = List;
		List = tmpList2;
	}
	LA->next = tmpList->next;
	free(tmpList);
	tmpList = NULL;
	printf("��������ɹ�\n");
}
//�󽻼�
void Listz_Intersection(Listz*LA, Listz*LB)
{
	//����LA
	//�ϰ汾
	//ֻ��Ҫ����ȡ��LA��Ԫ�أ���LB��Ԫ����һ�Ա�
	//��Ԫ��ͬ������Ԫ�أ�ɾ��LB��ӦԪ�أ�����ɾ��LA��ӦԪ��
	//�����漰ɾ������������Ҫ��pa��pb�ĺ������Ժ�����ɾ������
	//�°汾
	//����Ԫ�ص��������ԣ�ֻҪLB��Ԫ��С�ڻ����LA�Ϳ���ɾ��
	Listz*pa = LA;//��ǰ��
	Listz*pb = LB;
	while (pa->next&&pb->next)
	{
		//��������������pb������pa->nextΪNULL������pb->nextΪNULL
		//��һ��������������pa�Ĳ���
		if (pa->next->i > pb->next->i)
		{
			//��pa->next֮�󲻿�������pb->next��ͬ��Ԫ��
			Listz*t1 = pb->next;
			pb->next = pb->next->next;
			free(t1);
			t1 = NULL;
		}
		else if (pa->next->i == pb->next->i)
		{
			Listz*t1 = pb->next;
			pb->next = pb->next->next;
			free(t1);
			t1 = NULL;
			//˵��pa->nextû����
			pa = pa->next;
		}
		else
		{
			Listz*t1 = pa->next;
			pa->next = pa->next->next;
			free(t1);
			t1 = NULL;
		}
	}
	//���LB����
	if (pb->next == NULL)
	{
		free(pb);
		while (pa->next)
		{
			Listz*t1 = pa->next;
			pa->next = pa->next->next;
			free(t1);
			t1 = NULL;
		}
	}
	else
	{
		while (pb)
		{
			Listz*t1 = pb->next;
			free(pb);
			pb = t1;
		}
	}
	printf("��������ɹ�\n");
}

//���������ϵĲ��Ҫ�󼯺�Ԫ�ص������ҷŻ��½��,�˳�����ǰ��Ҫ��LA��ͷ�����LB����������
int Listz_DifSet(Listz*LA, Listz*LB)
{
	//��ɾ������ǰ��
	Listz*pa = LA;
	Listz*pb = LB;
	int count = 0;
	//���LB��Ԫ����LA����ͬ������ɾ����������λ�����LBС��LA����ɾLB������LA��λ��
	//��������Ԫ�ص������ص�
	while (pa->next&&pb->next)
	{
		//ʱ�临�Ӷ�ΪO(n)
		if (pb->next->i < pa->next->i)
		{
			//ɾ��pb->next->i
			Listz*t1 = pb->next;
			pb->next = pb->next->next;
			free(t1);
			t1 = NULL;
		}
		else if (pb->next->i == pa->next->i)
		{
			Listz*t1 = pb->next;
			Listz*t2 = pa->next;
			pb->next = pb->next->next;
			pa->next = pa->next->next;
			free(t1);
			t1 = NULL;
			free(t2);
			t2 = NULL;
		}
		else
		{
			//˵��pa�����Ա���
			count++;
			//��ȷ����λ��ʽ 
			pa = pa->next;
		}
	}
	//����ɾ��pb
	pb = LB;
	while (pb)
	{
		Listz*t1 = pb->next;
		free(pb);
		pb = t1;
	}
	printf("���ɹ�\n");
	return count;
}

//�ֽ�LA����Ϊ������LC�븺����LB
void Listz_Division(Listz*LA, Listz*LB, Listz*LC)
{
	Listz*pa = LA->next;
	Listz*pb = LB;
	Listz*pc = LC;
	while (pa)
	{
		//�ȱȽ�pa���Ĵ�С
		if (pa->i > 0)
		{
			pc->next = pa;
			pa = pa->next;
			pc->next->next = NULL;
			pc = pc->next;
		}
		else if (pa->i < 0)
		{
			pb->next = pa;
			pa = pa->next;
			pb->next->next = NULL;
			pb = pb->next;
		}
		else
		{
			pa = pa->next;
		}
	}
	printf("����ֽ�ɹ�\n");
}
//�������
Listz*Listz_FindMax(Listz*LA)
{
	Listz*pa = LA->next;
	Listz*max = pa;
	pa = pa->next;
	while (pa)
	{
		if (pa->i > max->i)
		{
			max = pa;
		}
		pa = pa->next;
	}
	return max;
}
Listz* Listz_revolve(Listz*LA)
{
	Listz*p = LA;
	Listz*t1 = p->next;
	free(LA);
	p = NULL;
	while (t1)
	{
		Listz*t2 = t1;
		t1 = t1->next;
		t2->next = p;
		p = t2;
	}
	Listz*Lnew = Mal(Listz);
	Lnew->next = p;
	printf("�����ת�ɹ���������ͷ���\n");
	return Lnew;
}
void Listz_Secdel(Listz*LA, int mink, int maxk)
{
	//ɾ��������ǰ������������ɾ����������λ
	Listz*p = LA;
	//��ǰ��
	while (p->next)
	{
		if (p->next->i > mink&&p->next->i < maxk)
		{
			//���p->next
			Listz*tmp = p->next;
			p->next = tmp->next;
			free(tmp);
			tmp = NULL;
		}
		else
			p = p->next;//������λ
	}
	printf("����ɾ���ɹ�\n");
}
//��ʼ��
Dlistz*Dlistz_Init()
{
	Dlistz*dlist = Mal(Dlistz);
	dlist->next = NULL;
	dlist->prior = NULL;
	return dlist;
}
//˫�򴴽�
void DListz_NosortCreate(Dlistz*dlist)
{
	Dlistz*p = dlist;
	printf("����˫������ĳ���:>");
	int num;
	scanf("%d", &num);
	printf("��������:>");
	for (int i = 1; i <= num; i++)
	{
		Dlistz*tmp = Mal(Dlistz);
		scanf("%d", &(tmp->i));
		p->next = tmp;
		tmp->prior = p;
		p = tmp;
		p->next = NULL;
	}
	printf("˫���������ɹ�\n");
}
void Dlistz_Show(Dlistz*dlist)
{
	printf("˫�����������������:>\n");
	if (dlist->next == NULL)
	{
		printf("�ձ�\n");
		return;
	}
	Listz*p = dlist->next;
	while (p)
	{
		printf("%5d", p->i);
		p = p->next;
	}
	printf("\n");
}
void Dlistz_change(Dlistz*dlist)
{
	//�������������ǰ��
	Dlistz*p = dlist;
	if (p->next == NULL)
	{
		return;
	}
	printf("���������������������:>");
	int dat;
	scanf("%d", &dat);
	while (p&&p->i != dat)
	{
		p = p->next;
	}
	if (p == NULL)
		printf("�ý�㲻����\n");
	else if (p->prior->prior == NULL)
	{
		printf("�޷�����\n");
	}
	else
	{
		Dlistz*t = p->prior->prior;
		p->prior->prior->next = p;
		p->next->prior = p->prior;
		p->prior->next = p->next;
		p->prior->prior = p;
		p->next = p->prior;
		p->prior = t;
		printf("��㽻���ɹ�\n");
	}
}
void Listz_SingleDel(Listz*list,int item)
{
	//ɾ����������ֵΪitem�Ľ�㣬ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
	Listz*p = list;
	if (p->next == NULL)
		return;
	while (p->next)
	{
		if (p->next->i == item)
		{
			Listz*t = p->next;
			p->next = p->next->next;
			free(t);
			t = NULL;
		}
		else
		p = p->next;
	}
	printf("�ɹ����������ֵΪitem�Ľ��\n");
}