#pragma once
#include"AMGraph.h"

/*
	�Ͻ�˹�����㷨�����ˡ���ת���㲻�ϸ������·��,
	ֱ�����Դ�㵽������������·��

	����֪�������Ǵ�ĳһ�����㵽������һ����������������·����
	��ֱ��·�������Դ�㵽��ת��·��������ת�㵽�յ��·����
	��ʱ��Ҫ��Դ�㵽�յ�ľ������

*/

//���������ʼ������
void Init(const AMGraph& G, int* Path, int* shortestDis, const int& v, bool* S);
//Ѱ�����·��<v,vk>���±�k
int findmin(const int* shortestDis, const bool* S, const int& n);
//�������£�������·����
void OutshortestPath(const int& v, const int* shortestDis, const int* Path, const AMGraph& G);
//�����·���ϵĶ���
void OutvexInpath(const int& v, const int& i, const int* Path, const AMGraph& G);

//����ĳԴ�㵽�������ж�������·��
//���ڽӾ�����Ϊ�洢�ṹ
void ShortestPath_DIJ(const AMGraph& G, const int& v);
