#pragma once
#include"AMGraph.h"
//���������㷨��ͷ�ļ�

/*
	���㷨��˼���ǣ�ÿһ�����㶼�п������������������������ת�㣬
	����������е�ÿһ�����㶼��Ҫ������Ϊ�������������������ת��
*/

//������ⶥ��֮������·��
void OutshortestPath_Floyd(const AMGraph& G, int(*D)[Mvnum], int(*Path)[Mvnum]);

//���ⶥ��֮�����·���Ķ���˳��
void OutvexInPath_Floyd(const int& i, const int& j, int(*Path)[Mvnum], const AMGraph& G);
//��ʼ������
void Init_Floyd(const AMGraph& G, int(*D)[Mvnum], int(*Path)[Mvnum]);

//���������㷨
void ShortestPath_Floyd(const AMGraph& G);


