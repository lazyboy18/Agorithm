#ifndef _CIRQUEOBJECT_H_
#define _CIRQUE_H_
#include<iostream>
#include<string>
using namespace std;
#define MAXQSIZE1 100
//对象声明,需要注意的是，函数的定义是在文件外的，属性最好私有，函数接口对外
class Dancer
{
	//首先是构造函数，类内声明，类外定义
public:
	//构造函数，直接对队列初始化
	Dancer(string sex);
	//析构函数，释放队列内存
	~Dancer();
	//判断队列是否为空
	bool is_empty();
	//判断队列是否已满
	bool is_full();
	//得到队列的长度
	int Get_len();
	//出队接口
	string Que_Out();
	//入队接口
	void Que_Push(const string name);
	//得到队头元素
	string Que_Gethaed();
	//得到队尾元素
	string Que_Gettail();
	//加载舞会成员
	void Dancer_Loading();
	//寻找队头
	void FirstPer();
	//寻找队尾
	void LastPer();
	//安排舞会，匹配舞者
	void Dancer_Match(Dancer&other);
private:
	string*base;
	string sex;//表明行呗
	int front;
	int rear;
	int maxsize;
	int num;
};
#endif