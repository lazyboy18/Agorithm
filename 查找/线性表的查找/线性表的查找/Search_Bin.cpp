#include<iostream>
using namespace std;

//arr[0]����
int arr[10] = { 0,1,3,5,12,32,42,53,56,89};

//�ǵݹ�ʵ��
int Search_Bin(const int key) {
	//����ߵ��±��1��ʼ
	int low = 1, high = 10;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;	//��ʾû���ҵ�
}

//�ݹ�ʵ��
int Search_Bin(const int key, int low, int high) {
	if (low > high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (arr[mid] == key)	
		return  mid;
	else if (arr[mid] > key)  
		return Search_Bin(key, low, mid - 1);
	else 
		return Search_Bin(key, mid+1, high);
}

void test01() {
	cout << "----���÷ǵݹ麯��------" << endl;
	cout << "ret = 1���±�Ϊ" << Search_Bin(1) << endl;
	cout << "ret = 43���±�Ϊ" << Search_Bin(43) << endl;
	cout << "ret = 100���±�Ϊ" << Search_Bin(100) << endl;

	cout << "----���õݹ麯��---------" << endl;
	int len = sizeof(arr) / sizeof(int);
	cout << "ret = 1���±�Ϊ" << Search_Bin(1,1,len) << endl;
	cout << "ret = 43���±�Ϊ" << Search_Bin(43, 1, len) << endl;
	cout << "ret = 100���±�Ϊ" << Search_Bin(100, 1, len) << endl;
}

int main() {
	test01();
	return 0;
}