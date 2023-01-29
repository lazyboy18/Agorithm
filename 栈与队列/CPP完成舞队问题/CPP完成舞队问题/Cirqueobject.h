#ifndef _CIRQUEOBJECT_H_
#define _CIRQUE_H_
#include<iostream>
#include<string>
using namespace std;
#define MAXQSIZE1 100
//��������,��Ҫע����ǣ������Ķ��������ļ���ģ��������˽�У������ӿڶ���
class Dancer
{
	//�����ǹ��캯�����������������ⶨ��
public:
	//���캯����ֱ�ӶԶ��г�ʼ��
	Dancer(string sex);
	//�����������ͷŶ����ڴ�
	~Dancer();
	//�ж϶����Ƿ�Ϊ��
	bool is_empty();
	//�ж϶����Ƿ�����
	bool is_full();
	//�õ����еĳ���
	int Get_len();
	//���ӽӿ�
	string Que_Out();
	//��ӽӿ�
	void Que_Push(const string name);
	//�õ���ͷԪ��
	string Que_Gethaed();
	//�õ���βԪ��
	string Que_Gettail();
	//��������Ա
	void Dancer_Loading();
	//Ѱ�Ҷ�ͷ
	void FirstPer();
	//Ѱ�Ҷ�β
	void LastPer();
	//������ᣬƥ������
	void Dancer_Match(Dancer&other);
private:
	string*base;
	string sex;//��������
	int front;
	int rear;
	int maxsize;
	int num;
};
#endif