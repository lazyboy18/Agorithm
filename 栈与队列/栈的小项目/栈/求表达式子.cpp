/*
	������Ҫ����ĵ�һ�������ǣ����ַ�������ת��Ϊ�������ݣ�

*/
#include"Getvalue.hpp"
int main()
{
	cout << "������ֵʽ��:>" << endl;
	while (1)
	{
		int ret = Evaluate();
		cout << "=" << ret << endl;
	}
	return 0;
}