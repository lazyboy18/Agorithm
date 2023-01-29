#include"BTTREE.h"
//��ʼ��,�Ż�ָ������
Bitree* BTnit()
{
	Bitree* Newroot = NULL;
	return Newroot;
}

//����,�õݹ�ʵ��(���򴴽�)
void BTcreate(Bitree*&Bt, int row, int col)
{
	Bt = new Bitree;
	cout << "�������Ϊ:>" << "(" << row << " ," << col << ")" << endl;
	cout << "����ý�����ϼ����Ĺ�ϵ:>";
	cin >> (Bt->relationship);
	cout << "����ý�������:>";
	cin >> (Bt->name);
	string Judge;
	cout << "�Ƿ񴴽����" << "(" << row << " ," << col << ")" << "�������?>" << endl;
	cin >> Judge;
	if (Judge.compare("YES") == 0)
	{
		BTcreate(Bt->leftchild, row + 1, 2 * col - 1);
	}
	else
		Bt->leftchild = NULL;
	cout << "�Ƿ񴴽����" << "(" << row << " ," << col << ")" << "���Ҷ���?>" << endl;
	cin >> Judge;
	if (Judge.compare("YES") == 0)
	{
		BTcreate(Bt->rightchild, row + 1, 2 * col);
	}
	else
		Bt->rightchild = NULL;
}
//�õݹ�������еĽ��(����)
void OrderTraverse(Bitree* Bt, int row, int col)
{
	if (Bt == NULL)
		return;
	cout << "�������Ϊ:>" << "(" << row << " ," << col << ")" << "����ϢΪ>" << endl;
	cout << "����:>" << Bt->name << endl;
	cout << "���ϼ���ϵ:>" << Bt->relationship << endl;
	cout << "---------------------------------" << endl;
	OrderTraverse(Bt->leftchild, row + 1, 2 * col - 1);
	OrderTraverse(Bt->rightchild, row + 1, 2 * col);
}
//ջ�ĳ�ʼ��
Bstack* Bstack_init()
{
	Bstack* p = NULL;
	return p;
}
//�ж��Ƿ�Ϊ��
bool Bstack_Isempty(Bstack* BT)
{
	if (BT == NULL)
		return true;
	else
		return false;
}
void Push(Bitree* root, Bstack**BT)
{
	Bstack*p = new Bstack;
	p->Bt = root;//����������
	p->next = (*BT);
	*BT = p;
}
Bitree* Pop(Bstack**BT)
{
	//ȡ��������
	Bitree* p = (*BT)->Bt;
	*BT = (*BT)->next;
	return p;
}
//�ǵݹ����,������ͷָ��
void StackTraverse(Bitree* BTree)
{
	//������ó�ʼ������
	Bstack* BT = NULL;
	Bitree* p = BTree;
	//p����ջ
	while (p || !Bstack_Isempty(BT))
	{
		//���������
		if (p)
		{
			//��ջ
			Push(p, &BT);
			//����pΪp��������
			p = p->leftchild;
		}
		else
		{
			Bitree* tmp = Pop(&BT);
			cout << "����:>" << tmp->name << endl;
			cout << "���ϼ���ϵ:>" << tmp->relationship << endl;
			cout << "---------------------------------" << endl;
			p = tmp->rightchild;
		}
	}
}

//���ƶ�����,�ݹ����ʵ��
void BinaryTreeCopy(Bitree* Bt, Bitree*&newtree)
{
	if (Bt == NULL)
	{
		newtree = NULL;
		return;
	}
	else
	{
		newtree = new Bitree;
		//�����ݿ���
		newtree->name = Bt->name;
		newtree->relationship = Bt->relationship;
		BinaryTreeCopy(Bt->leftchild, newtree->leftchild);
		BinaryTreeCopy(Bt->rightchild, newtree->rightchild);
	}
}
//��ö����������,����������ȵ����������������ȼ�1
int Getdepth(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	int m = Getdepth(Bt->leftchild);
	int n = Getdepth(Bt->rightchild);
	if (m > n)
		return m + 1;
	else
		return n + 1;
}
//��ý��ĸ���
int Getnodenum(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	else
		return Getnodenum(Bt->leftchild) + Getnodenum(Bt->rightchild) + 1;
}
//���Ҷ�ڵ����
int getleavenum(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	else if (Bt->leftchild == NULL&&Bt->rightchild == NULL)
		return 1;
	else
		return getleavenum(Bt->leftchild) + getleavenum(Bt->rightchild);
}
int getonenodenum(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	//Bt�ǿ�ϵ��
	else if (Bt->leftchild&&!(Bt->rightchild))
		return getonenodenum(Bt->leftchild) + 1;
	else if (Bt->rightchild&&!(Bt->leftchild))
		return getonenodenum(Bt->rightchild) + 1;
	else 
		return getonenodenum(Bt->leftchild) + getonenodenum(Bt->rightchild);
}
int gettwonodenum(Bitree* Bt)
{
	if (Bt == NULL)
		return 0;
	//Bt�ǿ�ϵ�У�4�����
	else if (Bt->leftchild&&!(Bt->rightchild))//�������ǿգ���������
		return gettwonodenum(Bt->leftchild);
	else if (Bt->rightchild&&!(Bt->leftchild))//�������ǿգ���������
		return gettwonodenum(Bt->rightchild);
	else if (Bt->rightchild&&Bt->leftchild)//���������ǿ�
		return  gettwonodenum(Bt->leftchild) + gettwonodenum(Bt->rightchild) + 1;
	else
		return 0;
}

void Bque_init(Bque& Que)
{
	Que.maxsize = MAXQUENUM;
	Que.rear = Que.tail = 0;
	//����Ԫ����Bitree*���ͣ����������˿ռ�
	Que.Base = new Bitree*[Que.maxsize];
}
bool Bque_isempty(Bque& Que)
{
	if (Que.tail == Que.rear)
		return true;
	else
		return false;
}

bool Bque_isfull(Bque& Que)
{
	if ((Que.tail + 1) % Que.maxsize == Que.rear)
		return true;
	else
		return false;
}
//��ӣ����Ԫ����BITREEָ��
void Bque_push(Bque& Que, Bitree*&Btreepointer)
{
	//��ָ���������
	if (Bque_isfull(Que)||!(Btreepointer))
		return;
	else
	{
		//�Ӷ�β����
		Que.Base[Que.tail] = Btreepointer;
		Que.tail = (Que.tail + 1) % Que.maxsize;
	}
}
//���ӣ�����Ԫ����Bitreeָ��,û�г���Ԫ����ΪNULL
Bitree* Bque_Pop(Bque& Que)
{
	if (Bque_isempty(Que))
		return NULL;
	else
	{
		Bitree* t = Que.Base[Que.rear];
		Que.rear = (Que.rear + 1) % Que.maxsize;
		return t;
	}
}
//���������
void Visitbyfloor(Bitree* Bt)
{
	//�����ﴴ����ʱ���в���������
	Bque Que;
	Bque_init(Que);
	//���õ�һ�������
	Bque_push(Que, Bt);
	while (!Bque_isempty(Que))
	{
		//���������.���ж�����������ǿվ�������ӣ�������ͬ��
		Bitree* Btree = Bque_Pop(Que);
		cout << "����:>" << Btree->name << endl;
		cout << "���ϼ���ϵ:>" << Btree->relationship << endl;
		cout << "---------------------------------" << endl;
		Bque_push(Que, Btree->leftchild);
		Bque_push(Que, Btree->rightchild);
	}
}