#include"data_struct.hpp"
#include<iostream>
//�����ַ�������Q1�ļ�������ַ����ֵ�Ƶ�Ρ�
void Exercise01()
{
	//�����ļ���
	ofstream ofs;
	ofs.open("Q1.txt", ios::out);
	//����һ����������洢�ַ�����Ƶ��
	int arr[36] = { 0 };
	String s;
	String_init(s);
	String_create(s);
	for (int i = 1; i <= s.length; i++)
	{
		if (s.str[i] >= '0'&&s.str[i] <= '9')
			arr[s.str[i] - '0']++;
		if (s.str[i] >= 'A'&&s.str[i] <= 'Z')
			arr[s.str[i] - 'A' + 10]++;//A��Ӧ������±�Ϊ10
	}
	//������ļ�
	ofs << "�ַ�Ƶ���������:>" << endl;
	for (int i = 0; i < 36; i++)
	{
		if (arr[i] == 0)
			continue;
		if (i < 10)
		{
			char ch = '0' + i;
			ofs << "�ַ��� " << ch << "     " << "����Ƶ��Ϊ:  " << arr[i] << endl;
		}
		else
		{
			char ch = 'A' + i - 10;
			ofs << "�ַ��� " << ch << "     " << "����Ƶ��Ϊ:  " << arr[i] << endl;
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
	cout << "�����ά�������m ����n:>" << endl;
	cin >> m;
	cin >> n;
	cout << "�����ά�����Ԫ��:>" << endl;
	int**arr = new int*[m];//arrָ��һ��int*�����飬�����СΪm
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	cout << "�Աȼ���С�������" << endl;
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
		cout << "�����Ϊ:YES" << endl;
	else
		cout << "�����Ϊ:NO" << endl;
	cout << "ʱ�临�Ӷ�Ϊ:O(m*m*n*n)" << endl;
	for (int i = 0; i < m; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

void Exercise06()
{
	cout << "����һά����Ĵ�С:>" << endl;
	int n;
	cin >> n;
	int*arr = new int[n];
	cout << "����һά����Ԫ��:>" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int i = 0;
	int j = n - 1;
	while (i < j)
	{
		//�ҵ�arr[i]С��0
		if (arr[i]>0)
		{
			i++;
			continue;
		}
		//�ҵ�arr[j]����0
		if (arr[j] < 0)
		{
			j--;
			continue;
		}
		//����arr[i]��arr[j]
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
		i++;
		j--;
	}
	cout << "arr�������:>" << endl;
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