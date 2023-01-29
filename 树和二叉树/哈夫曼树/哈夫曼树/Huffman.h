#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_
#include<iostream>
using namespace std;
#include<string>
//哈曼夫树的存储结构——结构体数组

typedef struct HTNode{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode, *HuffmanTree;

//输入字符出现频率，输出各个字符的哈夫曼编码
typedef struct HTcode{
	string s;
	int num;//出现频率
}HTcode,*Htgraph;

void createHuffmanTree(HuffmanTree& arr,const int n);
void createHuffmanTrees(HuffmanTree &arr, const int n, Htgraph& graph);
void createCode(HuffmanTree &arr, const int n, Htgraph& graph);
void Appcreatecode();
#endif 