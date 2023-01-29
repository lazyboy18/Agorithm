#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
	���Ƽ�ʹ���ֳɵ��ַ�������string������ʹ��C���Ե�char��������
	KBƥ���㷨��Ҫһһ�ȶ��������Ӵ���Ԫ�أ������Ӧ��ĳλƥ�䲻�ɹ�����i�Żص�
	i-j+1(��Ϊ�Ӵ�������������j-1����i��Ҫ����j-2������i=i-j+2;j�򷵻ص�ԭʼλ��j=1)
	��j>T.lengthʱ��˵��ƥ��ɹ������򲻳ɹ�.
	��Ҳ˵����Ҫ�õ�gets
*/
/*
	�漰�������ַ�����ʼ�����ַ����������ַ���ƥ�䣨���ģ�
*/
/*
	
*/
#define MAXSTRING 200
//����Ӧ�Ľṹ��
typedef struct str
{
	//��̬�������Ҷ�ȡλ�ô�1��ʼ
	char my_string[MAXSTRING + 1];
	int length;
}str;
//��ʼ��
void str_Init(str& s)
{
	s.length = 0;
	s.my_string[0] = '0';
	//cout << "�ַ�����ʼ���ɹ�" << endl;
}
//����:ֻ��һ���Դ���
void str_Create(str& s)
{
	//cout << "�����ַ���:>";
	gets(&s.my_string[1]);
	int i = 0;
	while (s.my_string[++i]);
	s.length = i - 1;
}
//׷��
//������ָ��
void str_Append(str& s, str* temp=NULL)
{
	int i = s.length;
	if (temp == NULL)
	{
		//cout << "����׷���ַ���:>";
		gets(&s.my_string[s.length + 1]);
		while (s.my_string[++i]);
		s.length = i - 1;
	}
	else
	{
		int length = temp->length;
		int j = 1;
		while (j<=length)//ֱ������'\0'
		{
			s.my_string[i + j] = temp->my_string[j];
			j++;
		}
		s.length += length;
		s.my_string[s.length + 1] = '\0';
	}
}
//�õ��ַ�������
void str_Getlen(const str& s)
{
	cout << "��ǰ�ַ�������Ϊ:>" << s.length << endl;
}
//����ַ���
void str_Out(const str& s)
{
	cout << "DNA����:>" << &(s.my_string[1]) << endl;
}
//�㷨���ģ��Ƚ��Ӵ�������
void str_BF(const str& S,const str& T,int pos=1)
{
	//Ĭ����ʼλ��Ϊ1
	//posΪ��ʼ����λ��
	int i = pos;//S��������ʼλ��
	int j = 1;//T��������ʼλ��
	while (i <= S.length&&j <= T.length)
	{
		if (S.my_string[i] == T.my_string[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)
		//j��i��������j-1����i��Ҫ����j-1��������ʼλ��Ϊi-j+1
		cout << "ƥ��ɹ����Ӵ������ַ���Ӧ��������λ��Ϊ:>" << i - j + 1 << endl;
	else
		cout << "ƥ�䲻�ɹ�" << endl;
}

void get_nextval(const str& T, int nextval[])

{
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.my_string[i] == T.my_string[j])
		{
			++i, ++j;
			if (T.my_string[i] != T.my_string[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}

void str_KMP(const str& S, const str& T, int pos = 1)
{
	int nextval[MAXSTRING + 1] = { 0 };
	get_nextval(T, nextval);
	//Ĭ����ʼλ��Ϊ1
	//posΪ��ʼ����λ��
	int i = pos;//S��������ʼλ��
	int j = 1;//T��������ʼλ��
	while (i <= S.length&&j <= T.length)
	{
		if (j==0||S.my_string[i] == T.my_string[j])
		{
			i++;
			j++;
		}
		else
		{
			j = nextval[j];
		}
	}
	if (j > T.length)
		//j��i��������j-1����i��Ҫ����j-1��������ʼλ��Ϊi-j+1
		cout << "ƥ��ɹ����Ӵ������ַ���Ӧ��������λ��Ϊ:>" << i - j + 1 << endl;
	else
		cout << "ƥ�䲻�ɹ�" << endl;
}

//���鲡��
bool DNA_match(const str& S, const str& T)
{
	int nextval[MAXSTRING] = { 0 };
	get_nextval(T, nextval);
	//Ĭ����ʼλ��Ϊ1
	//posΪ��ʼ����λ��
	int i = 1;//S��������ʼλ��
	int j = 1;//T��������ʼλ��
	while (i <= S.length&&j <= T.length)
	{
		if (j == 0 || S.my_string[i] == T.my_string[j])
		{
			i++;
			j++;
		}
		else
		{
			j = nextval[j];
		}
	}
	if (j > T.length)
		return true;
	else
		return false;
}

bool DNA_matchs(const str& S, const str& T, const int pos = 1)
{
	//Ĭ����ʼλ��Ϊ1
	//posΪ��ʼ����λ��
	int i = 1;//S��������ʼλ��
	int j = pos;//T��������ʼλ��
	while (i <= S.length&&j <= T.length+pos-1)
	{
		if (S.my_string[i] == T.my_string[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = pos;
		}
	}
	if (j > T.length+pos-1)
		return true;
	else
		return false;
}

void Virus_copy(str& s)
{
	//������������һ�������ǳ��Ȳ���
	int length = s.length;
	str_Append(s, &s);
	s.length = length;
}
//
//ÿ����һ�κ���ֻ���һ�Σ��Լ�ʱ�ͷŸú����ľֲ������ڴ�
//�Ա����ڴ���۹���
void Virus_exam()
{
	str person;
	str Virus;
	str_Init(person);
	str_Init(Virus);
	cout << "���뻼�ߵ�DNA����:>>";
	str_Create(person);
	cout << "���벡����DNA����:>>";
	str_Create(Virus);
	Virus_copy(Virus);
	int flag = 0;
	//��Ҫ���Virus.length��
	for (int i = 1; i <= Virus.length; i++)
	{
		if (DNA_matchs(person, Virus,i))
			flag = 1;
		if (flag == 1)
		{
			break;
		}
	}
	if (flag == 1)
		cout << "�������YES" << endl;
	else
		cout << "�������NO" << endl;
}


void test01()
{
	str S;
	str_Init(S);
	str_Create(S);
	str_Append(S, &S);
	str_Out(S);
}

void test02()
{
	int num;
	cout << "�������⻼�߸���:>";
	cin >> num;
	getchar();
	for (int i = 1; i <= num; i++)
	{
		cout << "--------------��" << i << "�μ��--------------" << endl;
		Virus_exam();
	}
	cout << "������" << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
