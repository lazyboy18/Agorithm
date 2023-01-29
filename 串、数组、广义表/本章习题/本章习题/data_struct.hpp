//#ifndef _DATA_STRUCT_HPP_
//#define _DATA_STRUCT_HPP_
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<fstream>
#include<iostream>
//�������ݽṹ
#define MAXLENGTH 201
typedef struct String{
	char str[MAXLENGTH];
	int length;
}String;
//��ʼ���ַ���
void String_init(String& s)
{
	//��һ��λ�����ò���
	s.str[0] = '#';
	s.length = 0;
	cout << "��ʼ���ɹ�" << endl;
}
//�����ַ���
void String_create(String& s)
{
	cout << "�����ַ���:>" << endl;
	gets(&s.str[1]);
	int i = 0;
	//һֱ����'\0',���ַ�����������Ϊi-1
	while (s.str[++i]);
	s.length = i - 1;
}
//�õݹ�ʵ���ַ�������S=elemt+S1
//��S1���򣬲���elemt����S1����
void revstring(String&s, int x)
{
	if (s.str[x] == '\0')
		return;
	char ch = s.str[x];
	revstring(s, x + 1);
	s.str[s.length - x + 1] = ch;
}
//����ַ���
void String_out(String&s)
{
	cout << "�ַ����������:>" << endl;
	cout << &s.str[1] << endl;
}
//�����ַ���,�ڲ��ı�Դ�ַ����������
void String_insert(String& obj, const String& src, const int pos = 1)
{
	if (pos > obj.length + 1 || pos < 1)
		return;
	//�Ƚ�obj��pos��ʼ���ַ���������ƶ�src.lengthλ
	//��Ҫ��'\0'Ҳ�ƶ�
	for (int i = obj.length+1; i >= pos; i--)
	{
		obj.str[i + src.length] = obj.str[i];
	}
	//�ٽ�src���뵽obj����
	for (int i = 1; i <= src.length; i++)
	{
		obj.str[pos + i - 1] = src.str[i];
	}
	obj.length += src.length;
}
//��s��ʽ��
void String_format(String&s1, String&s2, String&s3, const int n)
{
	//��s1�е��ַ���ʽ��
	if (n > s1.length)
		return;
	int i = 0;
	int j = 1;
	int k = 1;
	while (s1.str[++i])
	{
		//��s1Ϊ�ո�ʱ����ȡs1.str[i],���ַ�����s3
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
	//�������Ԫ�ؽ���S3
	s2.length = n;
	s3.length = k - 1;
	s2.str[n + 1] = '\0';
	s3.str[k] = '\0';
}

//#endif

