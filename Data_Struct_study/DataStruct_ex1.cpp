//#include <iostream>
//#include <iomanip>
//using namespace std;
//
///* �ּҿ����� & �� ���� ����1 
//   � ������ �ּҸ� �˾Ƴ��� ���ؼ��� �����տ� & �����ڸ� �߰����ݴϴ�.
//   �׷��� �Ǹ� �� ������ �ּҰ��� return �ϰ� �˴ϴ�. */
//
//int main() {
//
//	char a, b, c; //char�� ����3�� //char�� ũ�Ⱑ 1
//	char str1[4]; //char�� str1 array, ũ��� 4
//	chark str2[5]; 
//	short s1, s2; //short�� ũ�Ⱑ2
//	double d; //double�� ũ�Ⱑ6
//	int i, j, k; //int�� ũ�Ⱑ4
//
//	//hex = 16�������ǹ��մϴ� = 10 - a / 11 - b / ...
//
//	cout << endl << "a,b,c �ּ�=" << hex << (int)&a << "," << (int)&b << "," << (int)&c << endl << endl;
//	cout << "str1�� �ּ�=" << hex << (int)str1 << endl; //��� ���� ��� ù ĭ�� �ּҿ� �����ϴ�.
//	cout << "str1[0]�� �ּ�=" << hex << (int)&str1[0] << endl; //str1 �� &str1[0] �� ������ �����Դϴ�.
//	cout << "str1[1]�� �ּ�=" << hex << (int)&str1[1] << endl; //char���̹Ƿ� 1�� Ŀ���ϴ�.
//	cout << "str1[2]�� �ּ�=" << hex << (int)&str1[2] << endl;
//	cout << "str1[3]�� �ּ�=" << hex << (int)&str1[3] << endl << endl;
//
//	cout << "str2�� �ּ�=" << hex << (int)str2 << endl;
//	cout << "str2[0]�� �ּ�=" << hex << (int)&str2[0] << endl; //str2 �� &str2[0] �� ������ �����Դϴ�.
//	cout << "str2[1]�� �ּ�=" << hex << (int)&str2[1] << endl;
//	cout << "str2[2]�� �ּ�=" << hex << (int)&str2[2] << endl;
//	cout << "str2[3]�� �ּ�=" << hex << (int)&str2[3] << endl << endl;
//
//	cout << "s1 �� �ּ�=" << &s1 << endl; //&�� ���̸� �� �����͸� ����ִ� ������ �ּҸ� �ǹ��ϰ� ������
//	cout << "s2 �� �ּ�=" << &s2 << endl;
//	cout << "d �� �ּ�=" << &d << endl;
//	cout << "i �� �ּ�=" << &i << endl;
//	cout << "j �� �ּ�=" << &j << endl;
//	cout << "k �� �ּ�=" << &k << endl;
//
//	return 0;
//}