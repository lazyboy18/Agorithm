#include<iostream>
using namespace std;
#include<string>

//写一个算法遍历二叉树中的全部元素
//基本操作也可以用递归实现
typedef struct Binarytree{

	int data;
	struct Binarytree *leftchild, *rightchild;
}Binarytree;

Binarytree* Binarytree_init()
{
	//单纯开辟空间，无需赋值
	Binarytree* tree = new Binarytree;
	tree->leftchild = tree->rightchild = NULL;
	return tree;
}

//创建，递归实现，从键盘输入是否需要放回
void Binarytree_create(Binarytree* tree, int Row, int Col)
{
	cout << "该结点坐标为" << "(" << Row << ", " << Col << ")" << endl;
	cout << "输入该结点的数据:>";
	cin >> tree->data;
	getchar();
	//判断是否需要创建子树
	string sjudge;
	cout << "该其父结点为" << "(" << Row << ", " << Col << ")" << endl;
	cout << "是否需要创建左子树? :>";
	cin >> sjudge;
	if (sjudge.compare("YES")==0)
	{
		tree->leftchild = new Binarytree;
		tree->leftchild->leftchild = NULL;
		tree->leftchild->rightchild = NULL;
		Binarytree_create(tree->leftchild, Row + 1, 2 * Col - 1);
	}
	cout << "该其父结点为" << "(" << Row << ", " << Col << ")" << endl;
	cout << "是否需要创建右子树? :>";
	cin >> sjudge;
	if (sjudge.compare("YES")==0)
	{
		tree->rightchild = new Binarytree;
		tree->rightchild->leftchild = NULL;
		tree->rightchild->rightchild = NULL;
		Binarytree_create(tree->rightchild, Row + 1, 2 * Col);
	}
}
//输出遍历树的全部内容
void Binarytree_Showout(Binarytree* tree, int Row,int Col)
{
	if (tree == NULL)
		return;
	//输出根节点
	if (Row == 1)
	{
		cout << "根结点"<<"("<<Row<<", "<<Col<<")"<<"的数据域: " << tree->data << endl;
	}
	else
	{
		cout << "子结点" << "(" << Row << ", " << Col << ")" << "的数据域: " << tree->data << endl;
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