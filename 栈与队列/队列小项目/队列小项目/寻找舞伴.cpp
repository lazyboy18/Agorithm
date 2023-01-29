#include"Cirque.h"
/*
	要求用C++实现循环队列，循环队列的最大长度比最大容量少一
	模块化实现
*/
void test01()
{
	Cirque MD;
	Cirque_Init(&MD);
	Cirque FD;
	Cirque_Init(&FD);
	Dancer_Loading(&MD, &FD);
	Sroll_match(&MD, &FD);
	First_Dancer(&MD, &FD);
}

int main()
{
	test01();
	system("pause");
	return 0;
}