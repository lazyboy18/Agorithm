#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAXSIZE01 7
/*
	递归已经够难了，非递归更难
*/
#define M 200
#define N 200
int ack[200][200] = { 0 };
int Ack(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (m != 0 && n == 0)
		return Ack(m - 1, 1);
	else
		return Ack(m - 1, Ack(m, n - 1));
}
int Ackman(int m, int n)
{

	for (int i = 0; i < N; i++)
		ack[0][i] = i + 1;
	for (int j = 1; j < M; j++)
	{
		ack[j][0] = ack[j - 1][1];
		for (int i = 1; i < N; i++)
			ack[j][i] = ack[j - 1][ack[j][i - 1]];
	}
	return (ack[m][n]);
}
void test10()
{
	cout << "Ack(2,1)=" << Ack(2, 1) << endl;
}
void test11()
{
	cout << "Ack(2,1)=" << Ackman(2, 1) << endl;
}
//int main()
//{
//	test10();//递归计算
//	test11();
//}