//#include<iostream>
//#include<string>
//using namespace std;
//
//
////该算法根据学生的学号查找学生的名字
//
//typedef string KeyType;
//typedef string OtherType;
//
////定义元素项
//typedef struct {
//	KeyType id;
//	OtherType name;
//}element;
//
//typedef struct {
//	element* R;
//	int length;
//}SSTable;
//
////SSTable的初始化
//void Init(SSTable& s) {
//	//初始化长度
//	s.length = 0;
//	//输入学生个数
//	s.R = new element[1005];
//	int n;
//	cin >> n;
//	for (int i = 1;i <= n;i++) {
//		cin >> s.R[i].id;
//		cin >> s.R[i].name;
//	}
//	s.length = n;
//}
//
////查找函数
//int Search_Seq(SSTable& s, const KeyType& key) {
//	//设置哨兵
//	s.R[0].id = key;
//	int i;
//	for (i = s.length; s.R[i].id != key;i--);
//		return i;
//}
//
////int main() {
////	SSTable s;
////	Init(s);
////	//输入给定值
////	KeyType key;
////	cin >> key;
////	int ret = Search_Seq(s, key);
////	if (ret) {
////		cout << "查找成功，信息如下：" << endl;
////		cout << "id： " << s.R[ret].id << "  name： " << s.R[ret].name << endl;
////	}
////	else {
////		cout << "查找失败" << endl;
////	}
////	return 0;
////}
