#include"Binarytree.h"

//��ȡҶ�ӽ�����
void test01()
{
	Bpa tree = NULL;
	Ainit(tree);
	Acreate(tree);
	int ret = AGetleavenum(tree);
	cout << "Ҷ�ӽ����� ret = " << ret << endl;
}
//�ж��������Ƿ���ͬ
void test02()
{
	Bpa tree1 = NULL;
	Bpa tree2 = NULL;
	Ainit(tree1);
	Ainit(tree2);
	cout << "������һ����" << endl;
	Acreate(tree1);
	cout << "�����ڶ�����" << endl;
	Acreate(tree2);
	if (Ais_same(tree1, tree2))
		cout << "The trees are same!" << endl;
	else
		cout << "The trees are differnet!" << endl;
}
//����һ�ö�������������������������ٽ��������Һ��ӣ��ٲ����������
void test03()
{
	Bpa tree = NULL;
	Ainit(tree);
	cout << "����������:>" << endl;
	Acreate(tree);//����������
	Aque_visit(tree);
	AexChild(tree);
	cout << "�������Һ���֮��:>" << endl;
	Aque_visit(tree);
}
//˫�����
void test04()
{
	Bpa tree = NULL;
	Ainit(tree);
	Acreate(tree);
	cout << "˫������������:>" << endl;
	ADO_visit(tree);
}
//�������
void test05()
{
	Bpa tree = NULL;
	Ainit(tree);
	cout << "�������Զ�����:>" << endl;
	Acreate(tree);
	AGetmaxWidthApp(tree);
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}