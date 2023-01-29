#include"Huffman.h"

//ѡ����
void Select(const int i, HuffmanTree &arr, int& s1, int& s2)
{
	int count = 0;
	//ѡ��¶���ΪS1,S2��ֵ
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
	//������j���±꿪ʼ�������ж�
	for (int k = j + 1; k <= i - 1; k++)
	{
		if (arr[k].parent != 0)
			continue;
		if (arr[k].weight < arr[s1].weight || arr[k].weight < arr[s2].weight)
		{
			//���s1�Ƚ�С
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

//����һ����������
void createHuffmanTree(HuffmanTree &arr, const int n)
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;//���������±�
	arr = new HTNode[m + 1];//Ϊ�������ռ�
	//����Ԫ�س�ʼ��
	for (int i = 1; i <= m; i++)
	{
		arr[i].parent = 0;
		arr[i].weight = 0;
		arr[i].lchild = arr[i].rchild = 0;
	}
	//Ϊ����ǰn��Ԫ�ظ�ֵ
	cout << "Ϊ����������ǰ"<<n<<"��Ԫ�ظ�ֵ:>" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].weight;
	}
	//ȡ��С��������һ����������������λ����
	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;//ѡ��������С�������Һϲ�һ��������������i��
		Select(i, arr, s1, s2);
		//���������Сֵs1,s2
		arr[i].lchild = s1;
		arr[i].rchild = s2;
		arr[i].weight = arr[s1].weight + arr[s2].weight;
		arr[s1].parent = i;
		arr[s2].parent = i;
	}
}

//����һ����������
void createHuffmanTrees(HuffmanTree &arr, const int n, Htgraph& graph)
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;//���������±�
	arr = new HTNode[m + 1];//Ϊ�������ռ�
	graph = new HTcode[n + 1];
	//����Ԫ�س�ʼ��
	for (int i = 1; i <= m; i++)
	{
		arr[i].parent = 0;
		arr[i].weight = 0;
		arr[i].lchild = arr[i].rchild = 0;
	}
	//Ϊ����ǰn��Ԫ�ظ�ֵ
	cout << "�ֱ�����" << n << "���ַ��Լ������Ƶ��:>" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> graph[i].s;
		cin >> graph[i].num;
		//�����ַ�����Ƶ�ʾ������������Ľ��Ȩֵ
		arr[i].weight = graph[i].num;
	}
	//ȡ��С��ľ������һ����������������λ����
	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;//ѡ��������С��ľ�����Һϲ�һ��������������i��
		Select(i, arr, s1, s2);
		//���������Сֵs1,s2
		arr[i].lchild = s2;
		arr[i].rchild = s1;
		arr[i].weight = arr[s1].weight + arr[s2].weight;
		arr[s1].parent = i;
		arr[s2].parent = i;
	}
}

//�����ַ�����Ƶ�����ɹ��������
//���֧�ı��Ϊ0���ҷ�֧�ı��Ϊ1
void createCode(HuffmanTree &arr, const int n, Htgraph& graph)
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;//���һ��Ԫ��
	//��������1~n�ַ��Ĺ��������
	for (int i = 1; i <= n; i++)
	{
		int c = i;//����graph[c].s�Ĺ��������
		//����c�ĸ�ĸ
		int f = arr[c].parent;
		int cc = c;//cc��䶯����������
		while (f != 0)
		{
			if (arr[f].lchild == cc)
			{
				graph[c].s = '0' + graph[c].s;//����C++�ַ������͵�����
			}
			if (arr[f].rchild == cc)
			{
				graph[c].s = '1' + graph[c].s;
			}
			cc = f;//��f�ĸ�ĸ
			f = arr[f].parent;
		}
	}
}
//�û�ר������
//�����ַ�Ƶ�ʺ��������������
void Appcreatecode()
{
	HuffmanTree a = NULL;
	Htgraph b = NULL;
	cout << "�����ַ��ĸ���:>" << endl;
	int num;
	cin >> num;
	//���Ĳ���
	createHuffmanTrees(a, num, b);
	createCode(a, num, b);
	cout << "�����ַ������������:>" << endl;
	for (int i = 1; i <=num; i++)
	{
		cout << b[i].s << endl;
	}
	delete[]a;
	a = NULL;
	delete[]b;
	b = NULL;
}