#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#define MAXSIZE01 10
int top = 0;
void Push01()
{
	top++;
}
void Pop01()
{
	top--;
}
bool Is_valid()
{
	if (top >= 0)
		return true;
	else
		return false;
}
void test06()
{
	string str;
	cin >> str;
	int i = -1;
	while (str[++i])
	{
		if (str[i] == 'I')
			Push01();
		else
			Pop01();
	}
	if (Is_valid())
		cout << "合法" << endl;
	else
		cout << "非法" << endl;
}
//int main()
//{
//	test06();
//	return 0;
//}