#include"Cirque.h"
//��ʼ��
void Cirque_Init(Cirque*cq)
{
	cq->maxqsize = MAXQSIZE;
	cq->base = new string[MAXQSIZE];
	cq->front = cq->rear = 0;
	cout << "���г�ʼ���ɹ�" << endl;
}
//��ӳ���
int Cirque_Getlen(Cirque*cq)
{
	if (cq->base == NULL)
	{
		cout << "�����ѱ�����" << endl;
		return -1;
	}
	return (cq->rear - cq->front + cq->maxqsize) % cq->maxqsize;
}
//���Ӻ�����Ҫ����ͷԪ����Ϊ����ֵ
string Cirque_Out(Cirque*cq)
{
	if (cq->front == cq->rear)
	{
		cout << "�ն���" << endl;
		return "";
	}
	else
	{
		string tmp = cq->base[cq->front];
		cq->front = (cq->front + 1) % cq->maxqsize;
		//cout << tmp << "�ɹ�����" << endl;
		return tmp;
	}
}
//��Ӻ�������һ��string���͵Ĳ���
void Cirque_Push(Cirque*cq, string name)
{
	if ((cq->rear + 1) % cq->maxqsize == cq->front)
	{
		cout << "�����Ѿ��ﵽ��󳤶�" << endl;
		return;
	}
	cq->base[cq->rear] = name;
	cq->rear = (cq->rear + 1) % cq->maxqsize;
//	cout << name << "�ɹ����" << endl;
}
//��ȡ��ͷԪ��
string Cirque_Gethead(Cirque*cq)
{
	if (cq->front == cq->rear)
	{
		cout << "�ն���" << endl;
		return "�����";
	}
	return cq->base[cq->front];
}
//��ȡ��βԪ��
string Cirque_Gettail(Cirque*cq)
{
	if (cq->front == cq->rear)
	{
		cout << "�ն���" << endl;
		return "�����";
	}
	return cq->base[cq->rear];
}
//��������
void Dancer_Loading(Cirque*md, Cirque*fd)
{
	int num;
	cout << "���������ߵ�����:>" << endl;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cout << "�����" << i << "λ�����ߵ�����:>";
		string name;
		cin >> name;
		Cirque_Push(md, name);
	}
	cout << "����Ů���ߵ�����:>" << endl;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cout << "�����" << i << "λŮ���ߵ�����:>";
		string name;
		cin >> name;
		Cirque_Push(fd, name);
	}
}
void First_Dancer(Cirque*md, Cirque*fd)
{
	if (md->front==md->rear)
	{
		cout << "��ʱŮ���߶��е���λŮʿ:>" << Cirque_Gethead(fd) << endl;
	}
	else
	{
		cout << "��ʱ�����߶��е���λ��ʿ:>" << Cirque_Gethead(md) << endl;
	}
}
//����ƥ��
void Sroll_match(Cirque*md, Cirque*fd)
{
	//���Ӻ�������
	int manNum=(md->rear - md->front + md->maxqsize) % md->maxqsize;
	int felNum=(fd->rear - fd->front + fd->maxqsize) % fd->maxqsize;
	int num;
	cout << "��������ܳ���:>";
	cin >> num;
	int num2;
	while (1)
	{
		cout << "����ÿ���εĶ���:>";
		cin >> num2;
		if (num2 > manNum || num2 > felNum)
		{
			cout << "�������㣬����������" << endl;
		}
		else
			break;
	}
	for (int i = 1; i <= num; i++)
	{
		cout << "------------��" << i << "����������������:>" << endl;
		for (int j = 1; j <= num2; j++)
		{
			string man = Cirque_Out(md);
			string felman = Cirque_Out(fd);
			Cirque_Push(md, man);
			Cirque_Push(fd, felman);
			cout << man << "--�������:>" << felman << endl;
		}
	}
}