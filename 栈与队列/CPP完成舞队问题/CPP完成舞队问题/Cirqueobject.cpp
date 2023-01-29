#include"Cirqueobject.h"
//dancer的构造函数,一定要加定义域
/*
	发现：返回类型写在定义域前是为了方面函数重载？

*/
Dancer::Dancer(const string sex)
{
	cout << "Please assure sex as Gentleman or Lady,or this is wrong" << endl;
	this->sex = sex;
	this->front = this->rear = 0;
	this->maxsize = MAXQSIZE1;
	this->base = new string[this->maxsize];
	this->num = 0;
	//cout << "构造成功" << endl;
}
//析构函数
Dancer::~Dancer()
{
	delete[](this->base);
	//cout << "析构成功" << endl;
}
//得到队列的长度
int Dancer::Get_len()
{
	return (this->rear - this->front + this->maxsize) % (this->maxsize);
}
//判断是否为空
bool Dancer::is_empty()
{
	if (this->rear == this->front)
	{
		cout << "空队列" << endl;
		return true;
	}
	else
		return false;
}
//判断是否已满
bool Dancer::is_full()
{
	if ((this->rear + 1) % (this->maxsize) == this->front)
	{
		cout << "队列已满" << endl;
		return true;
	}
	else
		return false;
}
//出队
string Dancer::Que_Out()
{
	//队头出元素
	if (this->is_empty())
	{
		return "";
	}
	string name;
	name = this->base[this->front];
	this->front++;
	return name;
}
//入队接口
void Dancer::Que_Push(const string name)
{
	if (this->is_full())
	{
		return;
	}
	this->base[this->rear] = name;
	this->rear++;
	return;
}
//得到队头元素
string Dancer::Que_Gethaed()
{
	if (this->is_empty())
	{
		return "";
	}
	else
		return this->base[this->front];
}
//得到队尾
string Dancer::Que_Gettail()
{
	if (this->is_empty())
	{
		return "";
	}
	return this->base[this->rear];
}
void Dancer::Dancer_Loading()
{
	int num;
	cout << "Please input the num of new " << this->sex <<" Participant:>"<< endl;
	cin >> num;
	for (int i = this->num+1; i <= num+this->num; i++)
	{
		cout << "Please input the name of Number " << i <<" "<< this->sex << ":>";
		string name;
		cin >> name;
		this->Que_Push(name);
		//入队
	}
	this->num += num;
}
//寻找队头
void Dancer::FirstPer()
{
	cout << "the first " << this->sex << " in the que is:>" << this->Que_Gethaed() << endl;
	return;
}
//寻找队尾
void Dancer::LastPer()
{
	cout << "the first " << this->sex << " in the que is:>" << this->Que_Gettail() << endl;
	return;
}
//匹配舞伴
void Dancer::Dancer_Match(Dancer&other)
{
	//出队后紧接入队
	int perNum = (this->rear - this->front + this->maxsize) % (this->maxsize);
	int otherNum = (other.rear - other.front + other.maxsize) % (other.maxsize);
	int num;
	cout << "Please input the session number:>";
	cin >> num;
	int num2;
	while (1)
	{
		cout << "Please input the pair number:>";
		cin >> num2;
		if (num2 > perNum || num2 > otherNum)
		{
			cout << "Scarce in menber,please input again!" << endl;
		}
		else
			break;
	}
	for (int i = 1; i <= num; i++)
	{
		cout << "------------Session"<<i<<"'s dancer list is as follow:>" << endl;
		for (int j = 1; j <= num2; j++)
		{
			string per1 = this->Que_Out();
			string per2 = other.Que_Out();
			//赶紧入队
			this->Que_Push(per1);
			other.Que_Push(per2);
			cout << per1 << " 'partner is:>" << per2 << endl;
		}
	}
}
