#define _CRT_SECURE_NO_WARNINGS 
#include"Single_Content.h"
/*
	�õ�����ʵ��ͼ�����ϵͳ�����������У�
	��ʼ������巨����������������ʾһ�������Ϣ��������������ɾ��
	���룬��ʾ�����飬����
	���±���
	������ʹ��tyoedef���㲻����
	Ϊʲôhead��ʼ���󣬽�������һ������ʱ�ͱ�ΪNULL?
	next������дΪ����ָ����
	L == NULL || strcmp(name, L->name)  �������������ߵ������һ�����ʱ���Խ���
	ɾ��ʱ��L->next==NULLʱL->next->name������
*/
//int main()
//{
//	//��ʼ��
//	struct Node*head = Init();
//	int input = 0;
//	do{
//		menu();
//		printf("��ѡ��:>");
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
