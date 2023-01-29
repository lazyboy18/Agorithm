#include<iostream>
#include<string>
using namespace std;
//准备用链栈实现该项目,虽然空间利用效率不太高，但是只是为了练习
//定义结构体
typedef struct Stack
{
	char ch;
	struct Stack*next;//栈是竖着看地
}Stack;
//初始化
Stack*InitStack()
{
	Stack*p = NULL;
	cout << "初始化成功" << endl;
	return p;
}
//判断是否为空栈,不能改变S的内容
bool Is_empty(Stack*&S)
{
	if (S == NULL)
	{
		//cout << "空栈" << endl;
		return true;
	}
	else
		return false;
}
//入栈，字符型入栈,不能改变ch
void Push_stack(const char ch, Stack*&S)
{
	Stack*p = new Stack;
	p->ch = ch;
	p->next = S;
	S = p;
}
//出栈
void Pop_stack(Stack*&S)
{
	if (Is_empty(S))
	{
		return ;
	}
	Stack*tmp = S;
	S = S->next;
	delete tmp;
	return ;
}
//得到栈顶元素
char Get_head(Stack*&S)
{
	return S->ch;
}
//匹配
bool stack_Matching(Stack*&S)
{
	cout << "输入括号:>" << endl;
	int flag = 1;
	char ch = '1';
	cin >> ch;
	while (flag == 1 && ch != '#')
	{
		switch (ch)
		{
		case '{':
		case '(':
			Push_stack(ch, S);
			break;
		case '}':
		{
			if ('{' == Get_head(S))
				{
					flag = 1;
					Pop_stack(S);
				}
			else
				{
					flag = 0;
				}
			break;
		}
		case ')':
		{
			if ('(' == Get_head(S))
				{
					flag = 1;
					Pop_stack(S);
				}
			else
				{
					flag = 0;
				}
			break;
		}
		}
		cin >> ch;
	}
	if (flag&& Is_empty(S))
		return true;
	else
		return false;
}

void test01()
{
	Stack*S = InitStack();
	if (stack_Matching(S))
	{
		cout << "Match successfully" << endl;
	}
	else
	{
		cout << "Fail" << endl;
	}
}
//int main()
//{
//	test01();
//	return 0;
//}
