#include <iostream>
using namespace std;

//�迭�̸� - ������ ����� pointer���� 
/*
int main() {
	int point[] = { 1,2,3 };
	
	cout << point << endl; //
	cout << &point << endl; //
	cout << &point[0] << endl; //���� 2���� �� �迭 ù �κ��� �ּҰ����� ����
	cout << &point[1] << endl; //+4���� int�ϱ�
	cout << &point[2] << endl;

	cout << endl << "���� ��Ȯ��" << endl; 
	cout << *point << endl; // 1
	cout << *&point << endl; // ù �κ��� �ּҰ�
	cout << *(&point[0]) << endl; //1

	//point = &i; //�迭�� �̸��� ������ ����̹Ƿ� ���� ������ �� ����.

	return 0;
}
*/

//���ڿ��� ������
/*
int main() {

	char str1[4] = "abc"; //�̰� �ѱ��ھ� ��ĭ�� �迭�� ���Եȴ�

	const char *str2 = "abc"; //const�� �� �پ�����Ѵ� �ֳ��ϸ� abc�� ���ڿ�����̱� �����̰�, ���� ���� c++�� ����ϱ� ����

	//str2[1] = "d"; //���ڿ� '���'�̹Ƿ� �����Ұ�


}
*/

//������ �迭
/*
int main() {
	double j, f, g, h, i = 0.1;
	double *a = &j;
	double *b = &f;
	double *c = &g;
	double *d = &h;
	double *e = &i;
	const double *pointerARRAY[5] = { a,b,c,d,e }; //�̰͵� const�� �ٿ��־���. �� �迭�� ����.  "a" "b" ,,���� ����ִ� ���� �ּҸ� ����Ű�� ��

	for (int i = 0; i < 5; i++) {
		cout << &*pointerARRAY[i] << endl; //
	}
}*/

//�����͹迭 ������ ����
/*
int main() {
	char *pArr[3] = {NULL};
	pArr[0] = new char[10];
	pArr[1] = new char[100];
	strcpy_s(pArr[0], 10, "HELLOW");

	cout << &pArr[0] << endl;
	cout << pArr[0];
	
	delete[] pArr[0];
	delete[] pArr[1];
}
*/