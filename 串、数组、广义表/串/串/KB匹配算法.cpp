#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
	不推荐使用现成的字符串类型string，建议使用C语言的char类型数组
	KB匹配算法需要一一比对主串与子串的元素，如果相应的某位匹配不成功，则i放回到
	i-j+1(因为子串与主串都走了j-1步，i需要返回j-2步，则i=i-j+2;j则返回到原始位置j=1)
	当j>T.length时，说明匹配成功，否则不成功.
	这也说明需要用到gets
*/
/*
	涉及操作：字符串初始化，字符串创建，字符串匹配（核心）
*/
/*
	
*/
#define MAXSTRING 200
//串对应的结构体
typedef struct str
{
	//静态创建，且读取位置从1开始
	char my_string[MAXSTRING + 1];
	int length;
}str;
//初始化
void str_Init(str& s)
{
	s.length = 0;
	s.my_string[0] = '0';
	//cout << "字符串初始化成功" << endl;
}
//创建:只能一次性创建
void str_Create(str& s)
{
	//cout << "输入字符串:>";
	gets(&s.my_string[1]);
	int i = 0;
	while (s.my_string[++i]);
	s.length = i - 1;
}
//追加
//传两个指针
void str_Append(str& s, str* temp=NULL)
{
	int i = s.length;
	if (temp == NULL)
	{
		//cout << "输入追加字符串:>";
		gets(&s.my_string[s.length + 1]);
		while (s.my_string[++i]);
		s.length = i - 1;
	}
	else
	{
		int length = temp->length;
		int j = 1;
		while (j<=length)//直到读到'\0'
		{
			s.my_string[i + j] = temp->my_string[j];
			j++;
		}
		s.length += length;
		s.my_string[s.length + 1] = '\0';
	}
}
//得到字符串长度
void str_Getlen(const str& s)
{
	cout << "当前字符串长度为:>" << s.length << endl;
}
//输出字符串
void str_Out(const str& s)
{
	cout << "DNA序列:>" << &(s.my_string[1]) << endl;
}
//算法核心，比较子串和主串
void str_BF(const str& S,const str& T,int pos=1)
{
	//默认起始位置为1
	//pos为初始搜索位置
	int i = pos;//S搜索的起始位置
	int j = 1;//T搜索的起始位置
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
		//j与i向右走了j-1步，i需要后退j-1步，即起始位置为i-j+1
		cout << "匹配成功，子串的首字符对应其主串的位置为:>" << i - j + 1 << endl;
	else
		cout << "匹配不成功" << endl;
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
	//默认起始位置为1
	//pos为初始搜索位置
	int i = pos;//S搜索的起始位置
	int j = 1;//T搜索的起始位置
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
		//j与i向右走了j-1步，i需要后退j-1步，即起始位置为i-j+1
		cout << "匹配成功，子串的首字符对应其主串的位置为:>" << i - j + 1 << endl;
	else
		cout << "匹配不成功" << endl;
}

//检验病毒
bool DNA_match(const str& S, const str& T)
{
	int nextval[MAXSTRING] = { 0 };
	get_nextval(T, nextval);
	//默认起始位置为1
	//pos为初始搜索位置
	int i = 1;//S搜索的起始位置
	int j = 1;//T搜索的起始位置
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
	//默认起始位置为1
	//pos为初始搜索位置
	int i = 1;//S搜索的起始位置
	int j = pos;//T搜索的起始位置
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
	//病毒序列增长一倍，但是长度不变
	int length = s.length;
	str_Append(s, &s);
	s.length = length;
}
//
//每调用一次函数只检测一次，以即时释放该函数的局部变量内存
//以避免内存积累过多
void Virus_exam()
{
	str person;
	str Virus;
	str_Init(person);
	str_Init(Virus);
	cout << "输入患者的DNA序列:>>";
	str_Create(person);
	cout << "输入病毒的DNA序列:>>";
	str_Create(Virus);
	Virus_copy(Virus);
	int flag = 0;
	//需要检测Virus.length次
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
		cout << "检测结果：YES" << endl;
	else
		cout << "检测结果：NO" << endl;
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
	cout << "请输入检测患者个数:>";
	cin >> num;
	getchar();
	for (int i = 1; i <= num; i++)
	{
		cout << "--------------第" << i << "次检测--------------" << endl;
		Virus_exam();
	}
	cout << "检测结束" << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
