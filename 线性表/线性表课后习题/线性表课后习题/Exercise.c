#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include"Operator.h"
/*
	˼�뷽����
	��1�������㷨�������С�ʶ���������һ��ģ�飬
	���������������������ͬ��ֻ��ʵ������Ŀ�ĵĺ�����ͬ��
	��2������漰ɾ���������������ô��Ҫ�Ҹý��ĺ���
	ע��㣺
	��1�������ÿһ���������ж��Ƿ���Ҫ���Ľ����߰ѽ�㸴λ
	������
	��1�����㷨Ҳ���Դ���ǵݼ���ǵ�������ĺϲ�
*/

//���Դ�ӡ���
void test01()
{
	//��ʼ��
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	//�������Դ��ǵݼ�������
	Listz_Create(LA);
	Listz_Create(LB);
	//չʾ�������Ԫ��
	Listz_Show(LA);
	Listz_Show(LB);
}
void test02()
{
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	Listz_Create(LA);
	Listz_Create(LB);
	//�ϲ��������������������Ƿǵݼ���
	Listz_Integrate(LA, LB);
	Listz_Show(LA);
}
//�����
void test03()
{
	Listz*LA = Listz_Init();
	Listz_Create(LA);
	Listz_Inverted(LA);
	Listz_Show(LA);
}
//��
void test04()
{
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	Listz_Create(LA);
	Listz_Create(LB);
	Listz_Intersection(LA, LB);
	Listz_Show(LA);
}
void test05()
{
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	Listz_Create(LA);
	Listz_Create(LB);
	int ret=Listz_DifSet(LA, LB);
	Listz_Show(LA);
	printf("ret=%d\n", ret);
}
void test06()
{
	Listz*LA = Listz_Init();
	Listz*LB = Listz_Init();
	Listz*LC = Listz_Init();
	Listz_NosortCreate(LA);
	Listz_Division(LA, LB,LC);
	Listz_Show(LB);
	Listz_Show(LC);

}
void test07()
{
	Listz*LA = Listz_Init();
	Listz_NosortCreate(LA);
	Listz*maxNode = Listz_FindMax(LA);
	printf("maxNode->i=%d\n", maxNode->i);
}
void test08()
{
	Listz*LA = Listz_Init();
	Listz_NosortCreate(LA);
	Listz*Lnew=Listz_revolve(LA);
	Listz_Show(Lnew);
}
void test09()
{
	Listz*LA = Listz_Init();
	Listz_NosortCreate(LA);
	Listz_Secdel(LA, 4, 6);
	Listz_Show(LA);
}
void test10()
{
	Dlistz*DLA = Dlistz_Init();
	DListz_NosortCreate(DLA);
	//Dlistz_Show(DLA);
	Dlistz_change(DLA);
	Dlistz_Show(DLA);
}
void test11()
{
	Listz*LA = Listz_Init();
	Listz_NosortCreate(LA);
	Listz_Show(LA);
	Listz_SingleDel(LA,10);
	Listz_Show(LA);
}
void test12()
{
	Listz*LA = Listz_Init();
	Listz_Create(LA);
	Listz_Show(LA);
	Listz*LB = Listz_Init();
	Listz_Create(LB);
	Listz_Show(LB);
	Listz_Intersection(LA, LB);
	Listz_Show(LA);

}

int main()
{
	//���Դ�ӡ���
//	test01();
	//�ϲ�
//	test02();
	//�����
//	test03();
	//��
//	test04();
	//��
//	test05();
	//�ֽ�LAΪLB
//	test06();
	//�������
//	test07();
	//���ԭ��ת
	//test08();
	//ɾ������������Ľ��
//	test09();
	//����˫������������ǰ��
	//test10();
	//ɾ��ֵΪitem��ֵ
	//test11();
	//�󲢼�
	test12();
	return 0;
}