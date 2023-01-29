//#ifndef _DATA_STRUCT_HPP_
//#define _DATA_STRUCT_HPP_
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<fstream>
#include<iostream>
//输入数据结构
#define MAXLENGTH 201
typedef struct String{
	char str[MAXLENGTH];
	int length;
}String;
//初始化字符串
void String_init(String& s)
{
	//第一个位置闲置不用
	s.str[0] = '#';
	s.length = 0;
	cout << "初始化成功" << endl;
}
//创建字符串
void String_create(String& s)
{
	cout << "输入字符串:>" << endl;
	gets(&s.str[1]);
	int i = 0;
	//一直读到'\0',故字符串长度最终为i-1
	while (s.str[++i]);
	s.length = i - 1;
}
//用递归实现字符串逆序，S=elemt+S1
//将S1逆序，并将elemt放在S1后面
void revstring(String&s, int x)
{
	if (s.str[x] == '\0')
		return;
	char ch = s.str[x];
	revstring(s, x + 1);
	s.str[s.length - x + 1] = ch;
}
//输出字符串
void String_out(String&s)
{
	cout << "字符串输出如下:>" << endl;
	cout << &s.str[1] << endl;
}
//插入字符串,在不改变源字符串的情况下
void String_insert(String& obj, const String& src, const int pos = 1)
{
	if (pos > obj.length + 1 || pos < 1)
		return;
	//先将obj从pos开始的字符串向后面移动src.length位
	//需要把'\0'也移动
	for (int i = obj.length+1; i >= pos; i--)
	{
		obj.str[i + src.length] = obj.str[i];
	}
	//再将src插入到obj里面
	for (int i = 1; i <= src.length; i++)
	{
		obj.str[pos + i - 1] = src.str[i];
	}
	obj.length += src.length;
}
//将s格式化
void String_format(String&s1, String&s2, String&s3, const int n)
{
	//将s1中的字符格式化
	if (n > s1.length)
		return;
	int i = 0;
	int j = 1;
	int k = 1;
	while (s1.str[++i])
	{
		//当s1为空格时，不取s1.str[i],将字符交给s3
		if (s1.str[i] == ' ')
		{
			s3.str[k] = s1.str[i];
			k++;
			continue;
		}
		if (j != n + 1)
		{
			s2.str[j] = s1.str[i];
			j++;
		}
		else
		{
			s3.str[k] = s1.str[i];
			k++;
		}
	}
	//将多余的元素交给S3
	s2.length = n;
	s3.length = k - 1;
	s2.str[n + 1] = '\0';
	s3.str[k] = '\0';
}

//#endif

