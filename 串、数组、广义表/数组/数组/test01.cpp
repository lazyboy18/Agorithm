#include<iostream>
using namespace std;

//创建对称矩阵类
class symmetric_matrix{
public:
	//按行存储
	//有参构造函数
	symmetric_matrix(const int n)
	{
		this->n = n;
		this->arr = new int[n*(n + 1) / 2];
	}
	//赋值操作
	void Pushval(const int i, const int j, const int x)
	{
		int loc = i*(i - 1) / 2 + j - 1;
		this->arr[loc] = x;
	}
	//访问某个元素
	int Getval(const int i, const int j)
	{
		int loc = i*(i - 1) / 2 + j - 1;
		return this->arr[loc];
	}
private:
	int n;//阶数
	int*arr;
};

void test01(){
	symmetric_matrix matrix(10);
	for (int i = 0; i < 2; i++)
	{
		int k, j, x;
		cin >> k >> j >> x;
		matrix.Pushval(k, j, x);
	}
	for (int i = 0; i < 2; i++)
	{
		int k, j;
		cin >> k >> j;
		cout << matrix.Getval(k, j) << endl;
	}
}

int main(){
	
	//test01();
	system("pause");
	return 0;
}