#include"Huffman.h"

//选择函数
void Select(const int i, HuffmanTree &arr, int& s1, int& s2)
{
	int count = 0;
	//选择孤儿作为S1,S2的值
	int j;
	for (j = 1; j <= i - 1; j++)
	{
		if (arr[j].parent != 0)
			continue;
		count++;
		if (count == 1)
		{
			s1 = j;
		}
		if (count == 2)
		{
			s2 = j;
			break;
		}
	}
	//从现有j的下标开始，继续判断
	for (int k = j + 1; k <= i - 1; k++)
	{
		if (arr[k].parent != 0)
			continue;
		if (arr[k].weight < arr[s1].weight || arr[k].weight < arr[s2].weight)
		{
			//如果s1比较小
			if (arr[s1].weight>=arr[s2].weight)
			{
				s1 = s2;
				s2 = k;
			}
			else
			{
				s2 = s1;
				s1 = k;
			}
		}
	}

}

//创建一个哈曼夫树
void createHuffmanTree(HuffmanTree &arr, const int n)
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;//数组的最大下标
	arr = new HTNode[m + 1];//为数组分配空间
	//数组元素初始化
	for (int i = 1; i <= m; i++)
	{
		arr[i].parent = 0;
		arr[i].weight = 0;
		arr[i].lchild = arr[i].rchild = 0;
	}
	//为数组前n个元素赋值
	cout << "为哈夫曼树的前"<<n<<"个元素赋值:>" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].weight;
	}
	//取最小树，生成一个二叉树放在最新位置上
	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;//选择两个最小树，并且合并一棵新树放在数组i中
		Select(i, arr, s1, s2);
		//获得两个较小值s1,s2
		arr[i].lchild = s1;
		arr[i].rchild = s2;
		arr[i].weight = arr[s1].weight + arr[s2].weight;
		arr[s1].parent = i;
		arr[s2].parent = i;
	}
}

//创建一个哈曼夫树
void createHuffmanTrees(HuffmanTree &arr, const int n, Htgraph& graph)
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;//数组的最大下标
	arr = new HTNode[m + 1];//为数组分配空间
	graph = new HTcode[n + 1];
	//数组元素初始化
	for (int i = 1; i <= m; i++)
	{
		arr[i].parent = 0;
		arr[i].weight = 0;
		arr[i].lchild = arr[i].rchild = 0;
	}
	//为数组前n个元素赋值
	cout << "分别输入" << n << "个字符以及其出现频率:>" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> graph[i].s;
		cin >> graph[i].num;
		//根据字符出现频率决定哈曼夫树的结点权值
		arr[i].weight = graph[i].num;
	}
	//取最小树木，生成一个二叉树放在最新位置上
	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;//选择两个最小树木，并且合并一棵新树放在数组i中
		Select(i, arr, s1, s2);
		//获得两个较小值s1,s2
		arr[i].lchild = s2;
		arr[i].rchild = s1;
		arr[i].weight = arr[s1].weight + arr[s2].weight;
		arr[s1].parent = i;
		arr[s2].parent = i;
	}
}

//根据字符出现频率生成哈曼夫编码
//左分支的编号为0，右分支的编号为1
void createCode(HuffmanTree &arr, const int n, Htgraph& graph)
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;//最后一个元素
	//依次生成1~n字符的哈曼夫编码
	for (int i = 1; i <= n; i++)
	{
		int c = i;//生成graph[c].s的哈曼夫编码
		//查找c的父母
		int f = arr[c].parent;
		int cc = c;//cc会变动，依次生成
		while (f != 0)
		{
			if (arr[f].lchild == cc)
			{
				graph[c].s = '0' + graph[c].s;//利用C++字符串类型的优势
			}
			if (arr[f].rchild == cc)
			{
				graph[c].s = '1' + graph[c].s;
			}
			cc = f;//找f的父母
			f = arr[f].parent;
		}
	}
}
//用户专属函数
//输入字符频率后输出其哈曼夫编码
void Appcreatecode()
{
	HuffmanTree a = NULL;
	Htgraph b = NULL;
	cout << "输入字符的个数:>" << endl;
	int num;
	cin >> num;
	//核心部分
	createHuffmanTrees(a, num, b);
	createCode(a, num, b);
	cout << "各个字符编码输出如下:>" << endl;
	for (int i = 1; i <=num; i++)
	{
		cout << b[i].s << endl;
	}
	delete[]a;
	a = NULL;
	delete[]b;
	b = NULL;
}