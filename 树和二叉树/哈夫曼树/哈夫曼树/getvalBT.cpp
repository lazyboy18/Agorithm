#include"getvalBT.h"
bool is_empty(valstack& vals);
void createBT(valBT*& B, valBT*& LB, valBT*& RB, const int i)
{
	//���BΪ��˵��ֻ�Ǵ��������
	if (B == NULL)
	{
		B = new valBT;
		B->lchild = NULL;
		B->rchild = NULL;
		//��ֵ�ȿ������ַ���ASCI��ֵ��Ҳ�����ǲ�����
		B->val = i;
	}
	else
	{
		//���BΪ��˵����Ҫ�ϲ�B,LB,RB
		B->lchild = LB;
		B->rchild = RB;
	}
}

void valStackinit(valstack& vals)
{
	vals.top = 0;//��ջ�׿�ʼ
	//ջ���������������ջ����������ΪvalBT*
	vals.arr = new valBT*[MAXSIZE];
}

//ջ�գ�
bool is_emptyss(valstack& vals)
{
	if (vals.top == 0)
		return true;
	else
		return false;
}
//ջ����
bool is_full(valstack& vals)
{
	if (vals.top == MAXSIZE)
		return true;
	else
		return false;
}
//��ջ
void valPush(valstack& vals, valBT*& B)
{
	if (is_full(vals))
	{
		cout << "ջ���Ѿ���" << endl;
		return;
	}
	else
	{
		vals.arr[vals.top] = B;
		vals.top++;
	}
}
//��ջ,����ָ��
void valPop(valstack& vals, valBT*& B)
{
	if (is_emptyss(vals))
	{
		cout << "ջΪ��" << endl;
		return;
	}
	else
	{
		vals.top--;
		B = vals.arr[vals.top];
	}
}

//��ȡջ��Ԫ��
char Getval(valstack& vals)
{
	if (is_emptyss(vals))
	{
		cout << "ջΪ��" << endl;
		return '#';
	}
	else
	{
		valBT* target = vals.arr[vals.top - 1];
		return target->val;
	}
}
//�ж��Ƿ�Ϊ����
bool is_char(const char& ch)
{
	if (ch >= '0'&&ch <= '9')
		return false;
	else
		return true;
}
//�Ƚ��ַ����ȼ���c1Ϊ���룬c2Ϊջ��Ԫ��
char cCompare(const char&c1, const char&c2)
{
	//�Ƚ�C1��C2
	if (c1 == '#')
		return '<';//ִ������
	else if (c1 == '(')
		return '>';
	else if (c1 == ')')
	{
		if (c2 == '(')
			return '=';//����
		else
			return '<';//ִ������
	}
	else if (c1 == '+' || c1 == '-')
	{
		if (c2 == '(' || c2 == '#')
			return '>';
		else
			return '<';
		//���迼��')'
	}
	else if (c1 == '*' || c1 == '/' || c1 == '%')
	{
		if (c2 == '(' || c2 == '#' || c2 == '+' || c2 == '-')
			return '>';//
		else
			return '<';
	}
	else//���������������
		return '@';
}

//ͨ���ַ�����
int getbyOP(valBT*&OP, const int& num1, const int& num2)
{
	char op = OP->val;
	int result = 0;
	if (op == '-')
		result = num1 - num2;
	else if (op == '+')
		result = num1 + num2;
	else if (op == '/')
		result = num1 / num2;
	else if (op == '*')
		result = num1*num2;
	else if (op == '%')
		result = num1%num2;
	return result;
}


//��ȡ���ս��
int getresult(valBT*& resulttree)
{
	//����Ҷ�ӽ�㣬������㶼���������ASCI��ֵ
	if (resulttree->lchild == NULL)//ֻҪ��һ������Ϊ�գ�˵���ý�����Ҷ�ӽ��
	{
		return resulttree->val;
	}
	int left = getresult(resulttree->lchild);//�����������ֵ
	int right = getresult(resulttree->rchild);//�����������ֵ
	int result = getbyOP(resulttree, left, right);
	return result;
}



void coreCalulate()
{
	//�ȴ�������ջ��
	valstack OPTR;
	valstack EXPT;
	//ջ�ĳ�ʼ��
	valStackinit(OPTR);
	valStackinit(EXPT);
	cout << "������ֵ���ʽ:>" << endl;
	char ch;
	valBT* A = NULL;
	cin >> ch;
	createBT(A, A, A, ch);//������Ǻϲ�����ô��ֱ�Ӵ�3��B
	valPush(OPTR, A);
	cin >> ch;
	int num = 0;
	while (ch != '#' || Getval(OPTR) != '#')
	{
		if (!is_char(ch))//�ж��Ƿ�Ϊ�����ַ�
		{
			//��������ջ
			num *= 10;
			num += ch - '0';
			cin >> ch;//����ch
			if (is_char(ch))//��������������ַ�����ѡ����ջ
			{
				valBT* C = NULL;//����B������������ջEXPT
				createBT(C, C, C, num);
				valPush(EXPT, C);//��ջ
				num = 0;//num����
			}
		}
		else
		{
			//�ȶ��ַ������ȼ���
			switch (cCompare(ch, Getval(OPTR)))
			{
				//���������������ŵ����ȼ��ϴ󣬾���ջ
			case '>':
			{
					valBT* B = NULL;
					createBT(B, B, B, ch);
					valPush(OPTR, B);
					cin >> ch;//��������һ���ַ�
					break;
			}
			case '<':
			{
					//����������ֵ�Լ�һ��
					valBT*OP = NULL;
					valBT*num2 = NULL;
					valBT*num1 = NULL;
					valPop(OPTR, OP);
					valPop(EXPT, num2);
					valPop(EXPT, num1);
					createBT(OP, num1, num2, 0);
					valPush(EXPT, OP);
					break;
			}
			case '=':
			{
					//����ǵ��ںţ���ô��ֱ�ӵ���(,������һ���ַ�
					valBT*OP = NULL;
					valPop(OPTR, OP);
					cin >> ch;
					break;
			}
			}
		}
	}
	valBT*resulttree = NULL;
	valPop(EXPT, resulttree);
	int ret = getresult(resulttree);
	cout << "result==" << ret << endl;
}
