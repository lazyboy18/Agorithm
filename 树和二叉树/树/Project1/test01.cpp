#include<iostream>
using namespace std;
#include<string>

//дһ���㷨�����������е�ȫ��Ԫ��
//��������Ҳ�����õݹ�ʵ��
typedef struct Binarytree{

	int data;
	struct Binarytree *leftchild, *rightchild;
}Binarytree;

Binarytree* Binarytree_init()
{
	//�������ٿռ䣬���踳ֵ
	Binarytree* tree = new Binarytree;
	tree->leftchild = tree->rightchild = NULL;
	return tree;
}

//�������ݹ�ʵ�֣��Ӽ��������Ƿ���Ҫ�Ż�
void Binarytree_create(Binarytree* tree, int Row, int Col)
{
	cout << "�ý������Ϊ" << "(" << Row << ", " << Col << ")" << endl;
	cout << "����ý�������:>";
	cin >> tree->data;
	getchar();
	//�ж��Ƿ���Ҫ��������
	string sjudge;
	cout << "���丸���Ϊ" << "(" << Row << ", " << Col << ")" << endl;
	cout << "�Ƿ���Ҫ����������? :>";
	cin >> sjudge;
	if (sjudge.compare("YES")==0)
	{
		tree->leftchild = new Binarytree;
		tree->leftchild->leftchild = NULL;
		tree->leftchild->rightchild = NULL;
		Binarytree_create(tree->leftchild, Row + 1, 2 * Col - 1);
	}
	cout << "���丸���Ϊ" << "(" << Row << ", " << Col << ")" << endl;
	cout << "�Ƿ���Ҫ����������? :>";
	cin >> sjudge;
	if (sjudge.compare("YES")==0)
	{
		tree->rightchild = new Binarytree;
		tree->rightchild->leftchild = NULL;
		tree->rightchild->rightchild = NULL;
		Binarytree_create(tree->rightchild, Row + 1, 2 * Col);
	}
}
//�����������ȫ������
void Binarytree_Showout(Binarytree* tree, int Row,int Col)
{
	if (tree == NULL)
		return;
	//������ڵ�
	if (Row == 1)
	{
		cout << "�����"<<"("<<Row<<", "<<Col<<")"<<"��������: " << tree->data << endl;
	}
	else
	{
		cout << "�ӽ��" << "(" << Row << ", " << Col << ")" << "��������: " << tree->data << endl;
	}
	Binarytree_Showout(tree->leftchild, Row + 1, 2 * Col - 1);
	Binarytree_Showout(tree->rightchild, Row + 1, 2 * Col);
}

void test01()
{
	Binarytree* tree = Binarytree_init();
	Binarytree_create(tree, 1, 1);
	Binarytree_Showout(tree, 1, 1);
}

int main()
{
	test01();
	system("pause");
	system("cls");
	return 0;
}