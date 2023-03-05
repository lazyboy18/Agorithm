#include<iostream>
using namespace std;

//arr[0]废弃
int arr[10] = { 0,1,3,5,12,32,42,53,56,89};

//非递归实现
int Search_Bin(const int key) {
	//最左边的下标从1开始
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
	return -1;	//表示没有找到
}

//递归实现
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
	cout << "----调用非递归函数------" << endl;
	cout << "ret = 1的下标为" << Search_Bin(1) << endl;
	cout << "ret = 43的下标为" << Search_Bin(43) << endl;
	cout << "ret = 100的下标为" << Search_Bin(100) << endl;

	cout << "----调用递归函数---------" << endl;
	int len = sizeof(arr) / sizeof(int);
	cout << "ret = 1的下标为" << Search_Bin(1,1,len) << endl;
	cout << "ret = 43的下标为" << Search_Bin(43, 1, len) << endl;
	cout << "ret = 100的下标为" << Search_Bin(100, 1, len) << endl;
}

int main() {
	test01();
	return 0;
}