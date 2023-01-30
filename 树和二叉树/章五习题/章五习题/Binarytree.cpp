#include"Binarytree.h"
//��ʼ��
void Ainit(Bpa& Btree)
{
	Btree = new BinaryTreeA;
	Btree->lChild = Btree->rChild = NULL;
}
//�������򴴽�
void Acreate(Bpa& Btree)
{
	if (Btree == NULL)
		return;
	string com;
	cout << "�Ƿ񴴽�������?:>" << endl;
	cin >> com;
	if (com.compare("YES") == 0)
	{
		Ainit(Btree->lChild);//�ظ����ó�ʼ������
	}
	Acreate(Btree->lChild);
	cout << "����ý�������:>" << endl;
	cin >> Btree->data;
	cout << "�Ƿ񴴽�������?:>" << endl;
	cin >> com;
	if (com.compare("YES") == 0)
	{
		Ainit(Btree->rChild);
	}
	Acreate(Btree->rChild);
}
//��Ҷ�ӽ��
int AGetleavenum(Bpa& Btree)
{
	//����һ������Ҷ�ӽ��
	if (Btree == NULL)//������Ϊ��
		return 0;
	if (Btree->lChild == NULL && Btree->rChild == NULL)
		return 1;
	int lnum = 0, rnum = 0;
	//�����������Ҷ�ӽ���������������������Ҷ�ӽ��֮��
	lnum = AGetleavenum(Btree->lChild);
	rnum = AGetleavenum(Btree->rChild);
	return lnum + rnum;
}
//�ж��������Ƿ���ͬ,ÿ�αȽ϶���ͬ�㼶
bool Ais_same(Bpa& Btree1, Bpa& Btree2)
{
	//��һ����ͬ����Ľ���ϣ��ȶ�������
	//4���������ͬΪ��true,һ��һ�ǿ�false,˫�ǿռ����ж�
	if (Btree1 == NULL && Btree2 == NULL)
		return true;
	//��ʱBtree2һ���ǿգ���Ϊ�����ڵ�һ��������
	else if (Btree1 == NULL)
		return false;
	//��ʱBtree1һ���ǿգ���������������
	else if (Btree2 == NULL)
		return false;
	else
	{
		//�ȶ�������,�����ͬ������ж���һ��
		if (Btree1->data == Btree2->data)
		{
			bool ret1 = Ais_same(Btree1->lChild, Btree2->lChild);
			bool ret2 = Ais_same(Btree1->rChild, Btree2->rChild);
			if (ret1 && ret2)//����
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

//���������������Һ���
void AexChild(Bpa& Btree)
{
	//���������BtreeΪ�գ�û�к�Ϸ��
	//Btree�ǿգ�����һ�����ӽ��Ϊ�գ�Ҳû�к�Ϸ��
	//Btree�ǿգ���������Ҳ�ǿգ�����Ԫ��
	if (Btree == NULL)
		return;
	else if (Btree->lChild == NULL || Btree->rChild == NULL)
		return;
	else
	{
		int t = Btree->lChild->data;
		Btree->lChild->data = Btree->rChild->data;
		Btree->rChild->data = t;
		AexChild(Btree->lChild);
		AexChild(Btree->rChild);
	}
}
//˫�����
	//�ȱ�����ǰ�Ľ�㣬�ٷ��������������ٷ���һ��������
	//�ٷ�����������
	//���ʵ������ʽ�Լ��������͸����Լ�������������������������
	//Show,����������ϴ�ʱ�����Զ�����װһ������
void ADO_visit(Bpa& Btree)
{
	if (Btree == NULL)
		return;
	cout << Btree->data << " ";//�ȷ��ʸý��
	ADO_visit(Btree->lChild);//�ٷ�����������
	cout << Btree->data << " ";//�ٷ��ʸý��
	ADO_visit(Btree->rChild);
}
//����������������
void AGetmaxWidth(Bpa& Btree, int*arr, int floor)
{
	//���Ϊ��˵������Ȳ���
	if (Btree == NULL)
		return;
	else
	{
		//��ò�Ŀ��
		arr[floor]++;
		//�ȼ���������Ĳ������ټ���������Ĳ���
		AGetmaxWidth(Btree->lChild, arr, floor+1);//ÿһ�㶼��0��ʼ
		AGetmaxWidth(Btree->rChild, arr, floor+1);
	}
}
//�û��汾�õ������
void AGetmaxWidthApp(Bpa& tree)
{
	int maxwidth = 0;
	//maxwidth���������
	int arr[1000] = { 0 };//��������о����ԣ����Ϊ1000
	AGetmaxWidth(tree, arr, 0);
	int floor = 0;
	for (int i = 0;i < 1000;i++)
	{
		if (arr[i] > maxwidth)
		{
			maxwidth = arr[i];
			floor = i + 1;
		}
	}
	cout << "tree������Ȳ��ڵ�" << floor << "��"
		<< "  �����Ϊ: maxwidth = " << maxwidth << endl;
}


//��ʼ��
void Aque_init(Aque& aque)
{
	aque.quemaxsize = QUEMAXSIZE;
	aque.front = aque.rear = 0;
	aque.arr = new Bpa[aque.quemaxsize];
}
//�ж϶����Ƿ�Ϊ��
bool Aqueis_empty(Aque& aque)
{
	if (aque.front == aque.rear)
	{
		//cout << "��" << endl;
		return true;
	}
	else
		return false;
}
//�ж�ѭ�������Ƿ��Ѿ���
bool Aqueis_full(Aque& aque)
{
	if ((aque.rear + 1) % aque.quemaxsize == aque.front)
	{
		//cout << "��" << endl;
		return true;
	}
	else
		return false;
}
//��ӣ����Ԫ����Bpaָ��
void Aque_push(Aque& aque, Bpa& tree)
{
	if (Aqueis_full(aque))
		return;
	//����ӣ���rear++
	aque.arr[aque.rear] = tree;
	aque.rear = (aque.rear + 1) % aque.quemaxsize;//�׺��Բ���
}
//����,������Ԫ�ط���һ��������
void Aque_pop(Aque& aque, Bpa& carrier)
{
	if (Aqueis_empty(aque))
		return;
	carrier = aque.arr[aque.front];
	aque.front = (aque.front + 1) % aque.quemaxsize;
}
//���ٶ���
void Aque_delete(Aque& aque)
{
	delete[]aque.arr;
	aque.arr = NULL;
	cout << "aque���ٳɹ�" << endl;
}
//�������,Ϊ����֤�仯���
void Aque_visit(Bpa& tree)
{
	Aque aque;
	Aque_init(aque);
	//����tree��ӣ�����tree���ӣ��ٽ����������
	Aque_push(aque, tree);
	cout << "�������Ĳ����������:>" << endl;
	while (!Aqueis_empty(aque))
	{
		Bpa tmp = NULL;
		Aque_pop(aque, tmp);
		cout << tmp->data << " ";
		//�������������
		if (tmp->lChild != NULL)
			Aque_push(aque, tmp->lChild);
		if (tmp->rChild != NULL)
			Aque_push(aque, tmp->rChild);
	}
	cout << endl;
	Aque_delete(aque);
}