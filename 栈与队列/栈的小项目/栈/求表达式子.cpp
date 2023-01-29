/*
	我们需要解决的第一个问题是，将字符型数据转化为整型数据；

*/
#include"Getvalue.hpp"
int main()
{
	cout << "输入求值式子:>" << endl;
	while (1)
	{
		int ret = Evaluate();
		cout << "=" << ret << endl;
	}
	return 0;
}