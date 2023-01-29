#include"BTTREE.h"

void test01()
{
	Bitree* root = BTnit();
	BTcreate(root, 1, 1);
	OrderTraverse(root, 1, 1);
}

void test02()
{
	Bitree* root = BTnit();
	BTcreate(root);
	BIpointer newtree = NULL;
	BinaryTreeCopy(root, newtree);
	//OrderTraverse(newtree);
	//int depth = Getdepth(newtree);
	//cout << "depth = " << depth << endl;
	//int nodenum = Getnodenum(newtree);
	//cout << "num = " << nodenum << endl;
	//cout << "leavenum = " << getleavenum(newtree) << endl;
	//cout << "onenodenum = " << getonenodenum(newtree) << endl;
	//cout << "twonodenum = " << gettwonodenum(newtree) << endl;
	Visitbyfloor(newtree);
}

//int main()
//{
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}