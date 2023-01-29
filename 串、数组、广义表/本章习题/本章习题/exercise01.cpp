#include"data_struct.hpp"
#include<iostream>
//输入字符串，在Q1文件中输出字符出现的频次。
void Exercise01()
{
	//创建文件流
	ofstream ofs;
	ofs.open("Q1.txt", ios::out);
	//创建一个整型数组存储字符出现频次
	int arr[36] = { 0 };
	String s;
	String_init(s);
	String_create(s);
	for (int i = 1; i <= s.length; i++)
	{
		if (s.str[i] >= '0'&&s.str[i] <= '9')
			arr[s.str[i] - '0']++;
		if (s.str[i] >= 'A'&&s.str[i] <= 'Z')
			arr[s.str[i] - 'A' + 10]++;//A对应数组的下标为10
	}
	//输出到文件
	ofs << "字符频次情况如下:>" << endl;
	for (int i = 0; i < 36; i++)
	{
		if (arr[i] == 0)
			continue;
		if (i < 10)
		{
			char ch = '0' + i;
			ofs << "字符： " << ch << "     " << "出现频次为:  " << arr[i] << endl;
		}
		else
		{
			char ch = 'A' + i - 10;
			ofs << "字符： " << ch << "     " << "出现频次为:  " << arr[i] << endl;
		}
	}
	ofs.close();
}

void Exercise02()
{
	String s;
	String_init(s);
	String_create(s);
	String_out(s);
	revstring(s, 1);
	String_out(s);
}

void Exercise03()
{
	String s;
	String_init(s);
	String_create(s);
	String_out(s);
	String t;
	String_init(t);
	String_create(t);
	String_out(t);
	String_insert(s, t, 7);
	String_out(s);
}

void Exercise04()
{
	String s1;
	String_init(s1);
	String_create(s1);
	String s2;
	String_init(s2);
	String s3;
	String_init(s3);
	String_format(s1, s2, s3, 7);
	String_out(s1);
	String_out(s2);
	String_out(s3);	
}
void Exercise05()
{
	int m, n;
	cout << "输入二维数组的行m 和列n:>" << endl;
	cin >> m;
	cin >> n;
	cout << "输入二维数组的元素:>" << endl;
	int**arr = new int*[m];//arr指向一个int*的数组，数组大小为m
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	cout << "对比检测中…………" << endl;
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = arr[i][j];
			for (int p = j + 1; p < n; p++)
			{
				if (tmp == arr[i][p])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
			for (int k = i + 1; k < m; k++)
			{
				for (int h = 0; h < n; h++)
				{
					if (tmp == arr[k][h])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}
	if (flag == 0)
		cout << "检测结果为:YES" << endl;
	else
		cout << "检测结果为:NO" << endl;
	cout << "时间复杂度为:O(m*m*n*n)" << endl;
	for (int i = 0; i < m; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

void Exercise06()
{
	cout << "输入一维数组的大小:>" << endl;
	int n;
	cin >> n;
	int*arr = new int[n];
	cout << "输入一维数组元素:>" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int i = 0;
	int j = n - 1;
	while (i < j)
	{
		//找到arr[i]小于0
		if (arr[i]>0)
		{
			i++;
			continue;
		}
		//找到arr[j]大于0
		if (arr[j] < 0)
		{
			j--;
			continue;
		}
		//交换arr[i]与arr[j]
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
		i++;
		j--;
	}
	cout << "arr调整结果:>" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	delete[]arr;
}
int main()
{
	//Exercise01();
	//Exercise02();
	//Exercise03();
	//Exercise04();
	//Exercise05();
	//Exercise06();
	system("pause");
	system("cls");
	return 0;
}