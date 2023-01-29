#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_
#include<iostream>
using namespace std;
#include<string>
//���������Ĵ洢�ṹ�����ṹ������

typedef struct HTNode{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode, *HuffmanTree;

//�����ַ�����Ƶ�ʣ���������ַ��Ĺ���������
typedef struct HTcode{
	string s;
	int num;//����Ƶ��
}HTcode,*Htgraph;

void createHuffmanTree(HuffmanTree& arr,const int n);
void createHuffmanTrees(HuffmanTree &arr, const int n, Htgraph& graph);
void createCode(HuffmanTree &arr, const int n, Htgraph& graph);
void Appcreatecode();
#endif 