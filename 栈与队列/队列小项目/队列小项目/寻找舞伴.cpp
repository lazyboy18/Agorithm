#include"Cirque.h"
/*
	Ҫ����C++ʵ��ѭ�����У�ѭ�����е���󳤶ȱ����������һ
	ģ�黯ʵ��
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