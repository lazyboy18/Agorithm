#include"Forest.hpp"

//�ֵܺ��ӷ�����ʾ
void test01()
{
	CSNode*tree = NULL;//�Ƚ�ָ���ÿ�
	CSinit(tree);//��ʼ������ռ�
	CScreate(tree);
}

void test02()
{
	CSForest* forest = NULL;
	CSForestinit(forest);
	CSforestcreate(forest);
}
//����һ��ɭ�֣�Ȼ����ת��Ϊ������
void test03()
{
	CSForest* forest = NULL;
	CSForestinit(forest);
	CSforestcreate(forest);
	CSNode* comtree = ForestTransfer(forest);
}

//����һ����,���ұ�����
void test04()
{
	CSNode* singleTree = NULL;
	CSinit(singleTree);
	//����һ����
	CScreate(singleTree);
	//�������
	Traverse(singleTree);
}
//����ɭ�֣�������ɭ�֣��ٱ�����
void test05()
{
	//ɭ��ͬ����CSNode*����
	CSNode* forest = forestCreate();
	Traverse(forest);
}
//ʹ���µ�ɭ�ֽṹ
void test06()
{
	CSForests* Forest = NULL;
	//����ɭ��
	CSforestcreate(Forest);
	//����ɭ��
	Traverse(Forest->forest);
}


int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}