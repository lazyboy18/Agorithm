#include<iostream>
using namespace std;
#include<string>
//��������������
typedef struct Ctree{
	int x;
	int ltag, rtag;//�����ж��Ƿ����ǰ����
	struct Ctree*leftchild, *rightchild;
}Ctree;
//��ʼ������һ�����ǿ���
void Ctree_init(Ctree*& ctree)
{
	ctree = new Ctree;
	ctree->leftchild = ctree->rightchild = NULL;
}
//����ݹ鴴��
void Ctree_create(Ctree* ctree)
{
	//�ݹ��������
	if (ctree == NULL)
		return;
	//�ȴ���������������Ҫ���ж�
	string com;
	cout << "�Ƿ񴴽�������:>" << endl;
	cin >> com;
	if (com.compare("YES")==0)
	{
		ctree->leftchild = new Ctree;
		ctree->leftchild->leftchild = NULL;
		ctree->leftchild->rightchild = NULL;
	}
	//ctree���Һ��ӱ�����Ϊnull
	Ctree_create(ctree->leftchild);
	//�ڴ���������������ֵ
	cout << "����㸳ֵ:>" << endl;
	cin >> ctree->x;
	//�ٴ���������
	cout << "�Ƿ񴴽�������:>" << endl;
	cin >> com;
	if (com.compare("YES") == 0)
	{
		ctree->rightchild = new Ctree;
		ctree->rightchild->leftchild = NULL;
		ctree->rightchild->rightchild = NULL;
	}
	//ctree���Һ��ӱ�����Ϊnull
	Ctree_create(ctree->rightchild);
}
