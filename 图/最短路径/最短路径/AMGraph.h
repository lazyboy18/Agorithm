#pragma once
#include<iostream>
using namespace std;

//�ڽӾ���洢������
#define Mvnum 100  //��󶥵���
typedef char VerType;  //������������
typedef int ArcType;  //����Ȩֵ
typedef struct AMGraph {
	int vexnum, arcnum;
	VerType vexs[Mvnum];		  //������Ϣ��
	ArcType arcs[Mvnum][Mvnum];   //�ڽӾ���
}AMGraph;

//����������
void CreateUDN(AMGraph& G);