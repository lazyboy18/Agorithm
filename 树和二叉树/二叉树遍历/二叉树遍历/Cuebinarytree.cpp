#include"Cuebinarytree.h"
//������������������
/*
	���ǹ涨�������е�һ������ǰ��Ϊ����㣬���һ������ǰ���ض����ڣ�
	�������ָ����ڵ�
	���������������������������㣬�ٸ����ٵ����������
	�������������ĺ����ض��Ǹ����,�������Ľ���ǰ���ض���
	�����
*/
//pre�ǵ�ǰ���p��ǰ��
/*
	�������������࣬�����������������Ҳ�Ǵ���������ʼ���ٵ�������
	�涨��һ��ǰ��preΪ���ڵ㣬�����еĵ�һ������ǰ��Ϊ����㣬����Ϊ
	��һ��ݹ�ĸ����
	����p��ǰ��pre�ĺ�������p��������ÿһ��ݹ��У�����Ҫʹp��������ҲҪʹ
	pre���������ܹ�������������£�������Ҳֻ�ܽ�������������
	���⣬��ʹ������������֮ǰ��Ӧ��Ҫ����ǰ����pre=p(��ΪԽ��������Ľ�㣬����Խ��ǰ)
*/
Ctree* pre;
//�Խ��pΪ������������������
void InTreading(Ctree* p)
{
	if (p)
	{
		//��ʹ������������
		InTreading(p->leftchild);
		//�ý��û������
		if (!p->leftchild)
		{
			p->ltag = 1;
			p->leftchild = pre;//p����ָ��ָ��ǰ��
		}
		else
			p->ltag = 0;//p�Ѿ���������
		//������Ŀǰp��ǰ��pre��p�����жϣ�pre�ĺ����Ƿ�Ӧ��Ϊp
		if (!pre->rightchild)
		{
			pre->rtag = 1;
			pre->rightchild = p;
		}
		else
			pre->rtag = 0;
		//��ʹ������������
		pre = p;//����ǰ��
		InTreading(p->rightchild);
	}
}
void My_InOrderThreding(Ctree* p)
{
	if (p)
	{
		//��ʹ���������������ҵ������еĵ�һ�����
		My_InOrderThreding(p->leftchild);
		//�������������ľ���ʵ�����£�
		if (!p->leftchild)
		{
			p->leftchild = pre;
			p->ltag = 1;
		}
		else
			p->ltag = 0;
		//pre��Ҫ�������ĺ���
		if (!pre->rightchild)
		{
			pre->rightchild = p;
			pre->rtag = 1;
		}
		else
			pre->rtag = 0;
		pre = p;//����ǰ��preΪp
		My_InOrderThreding(p->rightchild);
	}
}


void test03()
{
	Ctree*ctree = NULL;
	Ctree_init(ctree);
	Ctree_create(ctree);
	//head = new Ctree;
	//head->leftchild = ctree;
	//head->rightchild = NULL;
	//pre = head;
	//My_InOrderThreding(head);
	//pre = ctree;
	//InTreading(ctree);
}

void InOrderThreading(Ctree*& head,Ctree* p)
{
	//ͷ��������ָ������Һ��������ʼʱָ���Լ��Ա�������Ϊpre==NULLʱ��ı�
	//ָ�򣬸��������������ɿ��Ը���InThreading()����
	head = new Ctree;
	head->ltag = 0;
	head->rtag = 0;
	head->rightchild = head;
	if (!p)
		head->leftchild = head;
	else
	{
		head->leftchild = p;
		pre = head;
		InTreading(p);//����pΪ���Ķ�������������
		pre->rightchild = head;
		head->rightchild = pre;
		head->rtag = 1;
		pre->rtag = 1;
	}
}
//���������Ϊ����
/*
	���������������֮�������е�ÿһ����㶼����ǰ�����ߺ��������Һ��ӻ�����
	�����������������Ҫ���ҵ������������½�㣬���ʸý��֮�����Ҹý��ĺ���
	���ж�������p->rtag==1���������������Ҳ�Ϊͷ��㣬��ô�͸���pΪp->rchild�����ʸý��;
	����ú��������ڣ�˵���ý�����Һ��ӣ���p����Ϊp=p->rchild��Ȼ��ʼ���ʸý���������
	����ͷ��ʼ�Ҹ��������ĵ�һ���������
*/
//���贴�������ջ�ռ�
void InOrderTraverse(Ctree*& head)
{
	//�Ӹ���㿪ʼ����	
	Ctree* p = head->leftchild;
	while (p != head)
	{
		//�ȱ�������������,�ҵ������еĵ�һ����㣬�����ʸý��
		while (p->ltag == 0)
			p = p->leftchild;
		//���ʸý��
		cout << p->x << " ";
		//��ʼ��������ĺ���,�ú�����Ϊͷ���
		while (p->rtag == 1 && p->rightchild != head)
		{
			p = p->rightchild;
			cout << p->x << " ";
		}
		//���û���ҵ��ú�����˵�����Һ��ӣ���ʼ�����Һ���
		p = p->rightchild;
		//���ú���Ϊheadʱ��˵���Ѿ������������е����һ����㣬��������ѭ��
	}
	cout << endl;
}

void test04()
{
	Ctree*ctree = NULL;
	Ctree_init(ctree);
	//���򴴽�
	Ctree_create(ctree);
	Ctree* head = NULL;
	InOrderThreading(head, ctree);
	InOrderTraverse(head);
}

int main()
{
	//test03();
	//test04();
	system("pause");
	return 0;
}