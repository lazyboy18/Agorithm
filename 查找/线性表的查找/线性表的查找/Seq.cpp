//#include<iostream>
//#include<string>
//using namespace std;
//
//
////���㷨����ѧ����ѧ�Ų���ѧ��������
//
//typedef string KeyType;
//typedef string OtherType;
//
////����Ԫ����
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
////SSTable�ĳ�ʼ��
//void Init(SSTable& s) {
//	//��ʼ������
//	s.length = 0;
//	//����ѧ������
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
////���Һ���
//int Search_Seq(SSTable& s, const KeyType& key) {
//	//�����ڱ�
//	s.R[0].id = key;
//	int i;
//	for (i = s.length; s.R[i].id != key;i--);
//		return i;
//}
//
////int main() {
////	SSTable s;
////	Init(s);
////	//�������ֵ
////	KeyType key;
////	cin >> key;
////	int ret = Search_Seq(s, key);
////	if (ret) {
////		cout << "���ҳɹ�����Ϣ���£�" << endl;
////		cout << "id�� " << s.R[ret].id << "  name�� " << s.R[ret].name << endl;
////	}
////	else {
////		cout << "����ʧ��" << endl;
////	}
////	return 0;
////}
