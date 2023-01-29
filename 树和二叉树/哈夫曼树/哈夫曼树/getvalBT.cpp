#include"getvalBT.h"
bool is_empty(valstack& vals);
void createBT(valBT*& B, valBT*& LB, valBT*& RB, const int i)
{
	//如果B为空说明只是创建根结点
	if (B == NULL)
	{
		B = new valBT;
		B->lchild = NULL;
		B->rchild = NULL;
		//该值既可以是字符的ASCI码值，也可以是操作数
		B->val = i;
	}
	else
	{
		//如果B为空说明需要合并B,LB,RB
		B->lchild = LB;
		B->rchild = RB;
	}
}

void valStackinit(valstack& vals)
{
	vals.top = 0;//从栈底开始
	//栈区的最大数据量，栈的数据类型为valBT*
	vals.arr = new valBT*[MAXSIZE];
}

//栈空？
bool is_emptyss(valstack& vals)
{
	if (vals.top == 0)
		return true;
	else
		return false;
}
//栈满？
bool is_full(valstack& vals)
{
	if (vals.top == MAXSIZE)
		return true;
	else
		return false;
}
//入栈
void valPush(valstack& vals, valBT*& B)
{
	if (is_full(vals))
	{
		cout << "栈区已经满" << endl;
		return;
	}
	else
	{
		vals.arr[vals.top] = B;
		vals.top++;
	}
}
//出栈,弹出指针
void valPop(valstack& vals, valBT*& B)
{
	if (is_emptyss(vals))
	{
		cout << "栈为空" << endl;
		return;
	}
	else
	{
		vals.top--;
		B = vals.arr[vals.top];
	}
}

//获取栈顶元素
char Getval(valstack& vals)
{
	if (is_emptyss(vals))
	{
		cout << "栈为空" << endl;
		return '#';
	}
	else
	{
		valBT* target = vals.arr[vals.top - 1];
		return target->val;
	}
}
//判断是否为数字
bool is_char(const char& ch)
{
	if (ch >= '0'&&ch <= '9')
		return false;
	else
		return true;
}
//比较字符优先级，c1为输入，c2为栈顶元素
char cCompare(const char&c1, const char&c2)
{
	//比较C1与C2
	if (c1 == '#')
		return '<';//执行运算
	else if (c1 == '(')
		return '>';
	else if (c1 == ')')
	{
		if (c2 == '(')
			return '=';//抵消
		else
			return '<';//执行运算
	}
	else if (c1 == '+' || c1 == '-')
	{
		if (c2 == '(' || c2 == '#')
			return '>';
		else
			return '<';
		//无需考虑')'
	}
	else if (c1 == '*' || c1 == '/' || c1 == '%')
	{
		if (c2 == '(' || c2 == '#' || c2 == '+' || c2 == '-')
			return '>';//
		else
			return '<';
	}
	else//如果输入错误就跳过
		return '@';
}

//通过字符求算
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


//获取最终结果
int getresult(valBT*& resulttree)
{
	//除了叶子结点，其他结点都是运算符的ASCI码值
	if (resulttree->lchild == NULL)//只要有一个孩子为空，说明该结点就是叶子结点
	{
		return resulttree->val;
	}
	int left = getresult(resulttree->lchild);//获得左子树的值
	int right = getresult(resulttree->rchild);//获得右子树的值
	int result = getbyOP(resulttree, left, right);
	return result;
}



void coreCalulate()
{
	//先创建两个栈区
	valstack OPTR;
	valstack EXPT;
	//栈的初始化
	valStackinit(OPTR);
	valStackinit(EXPT);
	cout << "输入求值表达式:>" << endl;
	char ch;
	valBT* A = NULL;
	cin >> ch;
	createBT(A, A, A, ch);//如果不是合并，那么就直接传3个B
	valPush(OPTR, A);
	cin >> ch;
	int num = 0;
	while (ch != '#' || Getval(OPTR) != '#')
	{
		if (!is_char(ch))//判断是否为数字字符
		{
			//将数字入栈
			num *= 10;
			num += ch - '0';
			cin >> ch;//更新ch
			if (is_char(ch))//如果不再是数字字符，就选择入栈
			{
				valBT* C = NULL;//创建B树根，并且入栈EXPT
				createBT(C, C, C, num);
				valPush(EXPT, C);//入栈
				num = 0;//num清零
			}
		}
		else
		{
			//比对字符的优先级别
			switch (cCompare(ch, Getval(OPTR)))
			{
				//如果是输入运算符号的优先级较大，就入栈
			case '>':
			{
					valBT* B = NULL;
					createBT(B, B, B, ch);
					valPush(OPTR, B);
					cin >> ch;//输入另外一个字符
					break;
			}
			case '<':
			{
					//弹出两个数值以及一个
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
					//如果是等于号，那么就直接弹出(,输入下一个字符
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
