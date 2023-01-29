#ifndef _FOREST_HPP_
#define _FOREST_HPP_
#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 10

/*
	ע��������ĸ��ڵ���û�����ֵܵ�
			  �������ĸ��ڵ����ҽ��
*/

//���ָ���ӣ��ұ�ָ���ֵ�
//���ִ洢�ṹ���ŵ���ǣ������˶������Ĵ洢�ṹ��������������Ը��ö������ĺ���
typedef struct CSNode{
	string name;
	int ltag, rtag;//ֻ����������֮���ʹ��
	struct CSNode*firstchild, *nextsibling;
}CSNode;
//����ɭ��
//ʵ���ϣ�ɭ����Ҫ��Ϊһ�ö������ŷ������������ɭ�ֽṹ�е�CSNode**���Ը�ΪCSNode*
typedef struct CSForest{
	CSNode** forest;
	int maxsize;//�����������
	int treenum;//������������
}CSForest;
//ɭ�ֵ�����һ�ִ洢�ṹ
typedef struct CSForests{
	//û����������
	CSNode* forest;
	int treenum;
}CSForests;

//���Ĳ���

//��ʼ����������Ϊ��ʼ�����Ǹ����ڵ㿪�ٿռ�
void CSinit(CSNode*& tree)
{
	tree = new CSNode;
	tree->firstchild = tree->nextsibling = NULL;
}
//�����Ǹ���ɭ�ֵ���״ͼֱ�Ӵ������������
//����,�������򴴽����ȴ������ӣ����Լ����ٵ����ֵ�
//�����ڴ�����ʱ����Ҫ�Լ��ж����Ľṹ
void CScreate(CSNode*& tree)
{
	if (tree == NULL)
		return;
	string com;
	//�ж��Ƿ񴴽������
	cout << "�Ƿ񴴽��ý��Ķ���:>" << endl;
	cin >> com;
	if (com.compare("YES")==0)
	{
		tree->firstchild = new CSNode;
		tree->firstchild->firstchild = NULL;
		tree->firstchild->nextsibling = NULL;
	}
	CScreate(tree->firstchild);
	//���ý�㸳ֵ
	cout << "Ϊ�ý�㸳ֵ��������������:>" << endl;
	cin >> tree->name;
	cout << "�Ƿ񴴽��ý����ֵ�(ע����ڵ�û���ֵ�):>" << endl;
	cin >> com;
	if (com.compare("YES") == 0)
	{
		tree->nextsibling = new CSNode;
		tree->nextsibling->firstchild = NULL;
		tree->nextsibling->nextsibling = NULL;
	}
	CScreate(tree->nextsibling);
}
//�����ȸ�����
void Traverse(CSNode*& tree)
{
	//ɭ�������ı�����ͬһ������
	if (tree == NULL)
		return;
	//�ȷ��ʸ��ڵ�
	cout << "�ý���������:>" << tree->name << endl;
	//�ٱ�������������
	Traverse(tree->firstchild);
	//�ٱ����������ֵ�
	Traverse(tree->nextsibling);
}

//ɭ�ֳ�ʼ��
void CSForestinit(CSForest*& Forest)
{
	Forest = new CSForest;
	Forest->maxsize = MAXSIZE;
	Forest->forest = new CSNode*[Forest->maxsize];
	Forest->treenum = 0;
	for (int i = 0; i < Forest->maxsize; i++)
	{
		Forest->forest[i] = NULL;
	}
}

//����ɭ��
void CSforestcreate(CSForest*& Forest)
{
	cout << "����ɭ������������:>" << endl;
	int num;
	cin >> num;
	if (num > Forest->maxsize)
	{
		cout << "��������" << endl;
		return;
	}
	for (int i = 0; i < num; i++)
	{
		cout << "���ɵ�" << i + 1 << "����:>" << endl;
		CSinit(Forest->forest[i]);//���ΪNULL
		CScreate(Forest->forest[i]);
	}
	Forest->treenum = num;
}

//�����°�ɭ��
void CSforestcreate(CSForests*& Forest)
{
	cout << "����������:>" << endl;
	int num;
	cin >> num;
	if (num < 1)
		return;
	else
	{
		Forest = new CSForests;
		Forest->treenum = num;
		CSinit(Forest->forest);//Ϊ��һ�������ٿռ�
		CSNode*p = Forest->forest;
		for (int i = 1; i <= Forest->treenum; i++)
		{
			cout << "���ڴ�����" << i << "����:>" << endl;
			//������i����,p�ĸ��ڵ�û���Һ���
			CScreate(p);
			if (i == Forest->treenum)
				break;
			//��Ҫ�ȷ����ڴ棬�����һ�������Һ�������ΪNULL
			CSinit(p->nextsibling);//����i�������Һ��ӷ����ڴ�
			p = p->nextsibling;//������i+1����
		}
	}
}

//ɭ��ת����Ϊ������(����������������ֵܵİ�)
CSNode* ForestTransfer(CSForest*& Forest)
{
	if (Forest->treenum == 0)
	{
		cout << "û����" << endl;
		return NULL;
	}
	//��ǰ�������Һ���ָ��ڶ�����
	for (int i = 0; i < Forest->treenum; i++)
	{
		//����ָ��ǰ����
		Forest->forest[i]->nextsibling = Forest->forest[i + 1];
	}
	return Forest->forest[0];
}

CSNode* forestCreate()
{
	//�ȴ�������
	CSForest* forest = NULL;
	CSForestinit(forest);
	CSforestcreate(forest);
	CSNode* Forest = ForestTransfer(forest);
	return Forest;
}

//��ת��Ϊɭ��
CSForest* BinaryTrasver(CSNode* comtree)
{
	//��������ת���ɭ�ִ洢��һ��ɭ�ֽṹ�У�������ɭ�ֽṹ
	if (comtree == NULL)
		return NULL;
	//����һ��ɭ��
	CSForest* divforest = NULL;
	CSForestinit(divforest);
	//��������comtree�ֽ⣬����ɭ����
	int i = 0;
	while (comtree)
	{
		//��װ
		divforest->forest[i] = comtree;
		//�����û�����ֵ�
		divforest->forest[i]->nextsibling = NULL;
		//����comtree���
		comtree = comtree->nextsibling;
		//���һ������ָ��ָ��NULL
	}
	return divforest;
}
//ǰ��
CSNode* pre;
//�ܱ�Ǹ�������齫��������
//����ɭ�֣��ɶ�ø����û���Ҷ��ӵĶ��������)ת���õ��Ķ���������������
//ʹÿһ�������ڴ������������������
//�����ڵ�Ϊp�Ķ�����������
void InThreadings(CSNode*& p)
{
	//�Ƚ�������������
	if (p)
	{
		InThreadings(p->firstchild);
		if (!p->firstchild)
		{
			//p��firstchildָ��ǰ��
			p->firstchild = pre;
			p->ltag = 1;
		}
		else
			p->ltag = 0;
		if (!pre->nextsibling)
		{
			//pre��nextsiblingָ�����
			pre->nextsibling = p;
			pre->rtag = 1;
		}
		else
			pre->rtag = 0;
		pre = p;
		//��������������
		InThreadings(p->nextsibling);
	}
}
//�ܱ�Ǹ�������齫��������
//��ͷ�����ڵ�����£���������������
void InOrderThreading(CSNode*& p, CSNode*& thrt)
{
	thrt = new CSNode;
	thrt->nextsibling = thrt;
	if (!p)
	{
		thrt->firstchild = thrt;
		thrt->rtag = 1;
		thrt->ltag = 1;
	}
	else
	{
		thrt->firstchild = p;
		thrt->ltag = 1;
		pre = thrt;
		InThreadings(p);
		pre->nextsibling = thrt;
		pre->rtag = 1;
		thrt->nextsibling = pre;
		thrt->rtag = 1;
	}
}
//�ܱ�Ǹ�������齫��������
//������������Ķ���������һ��
void OrderTrasverse(CSNode*& thrt)
{
	CSNode* p = thrt->firstchild;
	while (p != thrt)
	{
		//�������
		while (p->ltag == 0)
			p = p->firstchild;
		cout << "�ý���������:>" << p->name << endl;
		//��p�ĺ���
		while (p->rtag == 1 && p->nextsibling != thrt)
		{
			p = p->nextsibling;
			cout << "�ý���������:>" << p->name << endl;
		}
		p = p->nextsibling;
	}
}

#endif
