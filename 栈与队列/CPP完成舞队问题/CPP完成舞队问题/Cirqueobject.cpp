#include"Cirqueobject.h"
//dancer�Ĺ��캯��,һ��Ҫ�Ӷ�����
/*
	���֣���������д�ڶ�����ǰ��Ϊ�˷��溯�����أ�

*/
Dancer::Dancer(const string sex)
{
	cout << "Please assure sex as Gentleman or Lady,or this is wrong" << endl;
	this->sex = sex;
	this->front = this->rear = 0;
	this->maxsize = MAXQSIZE1;
	this->base = new string[this->maxsize];
	this->num = 0;
	//cout << "����ɹ�" << endl;
}
//��������
Dancer::~Dancer()
{
	delete[](this->base);
	//cout << "�����ɹ�" << endl;
}
//�õ����еĳ���
int Dancer::Get_len()
{
	return (this->rear - this->front + this->maxsize) % (this->maxsize);
}
//�ж��Ƿ�Ϊ��
bool Dancer::is_empty()
{
	if (this->rear == this->front)
	{
		cout << "�ն���" << endl;
		return true;
	}
	else
		return false;
}
//�ж��Ƿ�����
bool Dancer::is_full()
{
	if ((this->rear + 1) % (this->maxsize) == this->front)
	{
		cout << "��������" << endl;
		return true;
	}
	else
		return false;
}
//����
string Dancer::Que_Out()
{
	//��ͷ��Ԫ��
	if (this->is_empty())
	{
		return "";
	}
	string name;
	name = this->base[this->front];
	this->front++;
	return name;
}
//��ӽӿ�
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
//�õ���ͷԪ��
string Dancer::Que_Gethaed()
{
	if (this->is_empty())
	{
		return "";
	}
	else
		return this->base[this->front];
}
//�õ���β
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
		//���
	}
	this->num += num;
}
//Ѱ�Ҷ�ͷ
void Dancer::FirstPer()
{
	cout << "the first " << this->sex << " in the que is:>" << this->Que_Gethaed() << endl;
	return;
}
//Ѱ�Ҷ�β
void Dancer::LastPer()
{
	cout << "the first " << this->sex << " in the que is:>" << this->Que_Gettail() << endl;
	return;
}
//ƥ�����
void Dancer::Dancer_Match(Dancer&other)
{
	//���Ӻ�������
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
			//�Ͻ����
			this->Que_Push(per1);
			other.Que_Push(per2);
			cout << per1 << " 'partner is:>" << per2 << endl;
		}
	}
}
