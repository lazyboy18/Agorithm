#pragma once
#ifndef _AMGRAPH_H_
#define _AMGRAPH_H_
#include<string>
#include<iostream>
using namespace std;
//2-2-2023Ҫ��ѧϰ���������ڽӾ����ʾ�����Լ�̽����ѹ������
//�������Ͳ��ʺ�ʹ��ѹ�������ˡ�������������ͼ�ı�ʾ�������������
//��ֻ��Ҫ����������

//���������ڽӾ���洢��
/*
	����Ҫ��:����������ߵĸ���
	��������顢�ڽӾ����ά����
*/
#define MaxInt 999999
//��󶥵���
#define MVNum 100
//��������
typedef string VerTexType;
//Ȩֵ����
typedef int ArcType;
typedef struct {
	//������������,��̬����
	VerTexType* vexs;
	ArcType** arcs;
	//����������Լ��ߵĸ���
	int vexnum, arcnum;
}AMGraph;
//����������
void CreateUDN(AMGraph& G);
//����������
void DelUDM(AMGraph& G);

//��������ѹ������
typedef struct {
	//������������,��̬����
	VerTexType* vexs;
	ArcType* arcs;
	//����������Լ��ߵĸ���
	int vexnum, arcnum;
}AMGraphs;
//����������
void CreateUDNs(AMGraphs& G);
//����������
void DelUDMs(AMGraphs& G);
#endif

