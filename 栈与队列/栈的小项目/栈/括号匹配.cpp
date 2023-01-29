#include<iostream>
#include<string>
using namespace std;
//׼������ջʵ�ָ���Ŀ,��Ȼ�ռ�����Ч�ʲ�̫�ߣ�����ֻ��Ϊ����ϰ
//����ṹ��
typedef struct Stack
{
	char ch;
	struct Stack*next;//ջ�����ſ���
}Stack;
//��ʼ��
Stack*InitStack()
{
	Stack*p = NULL;
	cout << "��ʼ���ɹ�" << endl;
	return p;
}
//�ж��Ƿ�Ϊ��ջ,���ܸı�S������
bool Is_empty(Stack*&S)
{
	if (S == NULL)
	{
		//cout << "��ջ" << endl;
		return true;
	}
	else
		return false;
}
//��ջ���ַ�����ջ,���ܸı�ch
void Push_stack(const char ch, Stack*&S)
{
	Stack*p = new Stack;
	p->ch = ch;
	p->next = S;
	S = p;
}
//��ջ
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
//�õ�ջ��Ԫ��
char Get_head(Stack*&S)
{
	return S->ch;
}
//ƥ��
bool stack_Matching(Stack*&S)
{
	cout << "��������:>" << endl;
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
