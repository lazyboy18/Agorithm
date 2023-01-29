#include"Cirque.h"
//初始化
void Cirque_Init(Cirque*cq)
{
	cq->maxqsize = MAXQSIZE;
	cq->base = new string[MAXQSIZE];
	cq->front = cq->rear = 0;
	cout << "队列初始化成功" << endl;
}
//求队长度
int Cirque_Getlen(Cirque*cq)
{
	if (cq->base == NULL)
	{
		cout << "队列已被销毁" << endl;
		return -1;
	}
	return (cq->rear - cq->front + cq->maxqsize) % cq->maxqsize;
}
//出队函数需要将队头元素作为返回值
string Cirque_Out(Cirque*cq)
{
	if (cq->front == cq->rear)
	{
		cout << "空队列" << endl;
		return "";
	}
	else
	{
		string tmp = cq->base[cq->front];
		cq->front = (cq->front + 1) % cq->maxqsize;
		//cout << tmp << "成功出队" << endl;
		return tmp;
	}
}
//入队函数传入一个string类型的参数
void Cirque_Push(Cirque*cq, string name)
{
	if ((cq->rear + 1) % cq->maxqsize == cq->front)
	{
		cout << "队列已经达到最大长度" << endl;
		return;
	}
	cq->base[cq->rear] = name;
	cq->rear = (cq->rear + 1) % cq->maxqsize;
//	cout << name << "成功入队" << endl;
}
//获取队头元素
string Cirque_Gethead(Cirque*cq)
{
	if (cq->front == cq->rear)
	{
		cout << "空队列" << endl;
		return "无输出";
	}
	return cq->base[cq->front];
}
//获取队尾元素
string Cirque_Gettail(Cirque*cq)
{
	if (cq->front == cq->rear)
	{
		cout << "空队列" << endl;
		return "无输出";
	}
	return cq->base[cq->rear];
}
//加载舞者
void Dancer_Loading(Cirque*md, Cirque*fd)
{
	int num;
	cout << "输入男舞者的数量:>" << endl;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cout << "输入第" << i << "位男舞者的名字:>";
		string name;
		cin >> name;
		Cirque_Push(md, name);
	}
	cout << "输入女舞者的数量:>" << endl;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cout << "输入第" << i << "位女舞者的名字:>";
		string name;
		cin >> name;
		Cirque_Push(fd, name);
	}
}
void First_Dancer(Cirque*md, Cirque*fd)
{
	if (md->front==md->rear)
	{
		cout << "此时女舞者队列的首位女士:>" << Cirque_Gethead(fd) << endl;
	}
	else
	{
		cout << "此时男舞者队列的首位男士:>" << Cirque_Gethead(md) << endl;
	}
}
//多轮匹配
void Sroll_match(Cirque*md, Cirque*fd)
{
	//出队后紧接入队
	int manNum=(md->rear - md->front + md->maxqsize) % md->maxqsize;
	int felNum=(fd->rear - fd->front + fd->maxqsize) % fd->maxqsize;
	int num;
	cout << "输入舞会总场次:>";
	cin >> num;
	int num2;
	while (1)
	{
		cout << "输入每场次的队数:>";
		cin >> num2;
		if (num2 > manNum || num2 > felNum)
		{
			cout << "队数不足，请重新输入" << endl;
		}
		else
			break;
	}
	for (int i = 1; i <= num; i++)
	{
		cout << "------------第" << i << "场的舞者名单如下:>" << endl;
		for (int j = 1; j <= num2; j++)
		{
			string man = Cirque_Out(md);
			string felman = Cirque_Out(fd);
			Cirque_Push(md, man);
			Cirque_Push(fd, felman);
			cout << man << "--的舞伴是:>" << felman << endl;
		}
	}
}