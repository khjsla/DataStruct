//#include <iostream>
//using namespace std;
//
//int main() {
//	int i = 10;
//	int j = 5;
//
//	//����Ű�� �� ���ȭ
//	
//	/*const int *p = &i;
//	cout << "p��: " << p << endl;
//	cout << "*p��: " << *p << endl;
//	cout << "i��: " << i << endl;
//	//*p = 30; //�����Ͱ� ����Ű�� ���� �ٲٴ� ���� �Ұ���
//
//	i = 30; //�������� �����ϴ� �� ����
//	cout << "i=30\n";
//	cout << "p��: " << p << endl;
//	cout << "*p��: " << *p << endl;
//	cout << "i��: " << i << endl;
//	p = &j; //������ �ּҰ� ������ ����
//	cout << "p = &j\n";
//	cout << "p��: " << p << endl;
//	cout << "*p��: " << *p << endl;
//	cout << "i��: " << i << endl;
//	*/
//
//	//������ - �ּҰ� ���ȭ //const�� ������ �ٷξտ� ����
//	
//	int * const p = &i; //������ -�ּҰ� ���ȭ
//	cout << "p��: " << p << endl;
//	cout << "*p��: " << *p << endl;
//	cout << "i��: " << i << endl << endl;
//	i = 30;
//	cout << "i=30\n";
//	cout << "p��: " << p << endl;
//	cout << "*p��: " << *p << endl;
//	cout << "i��: " << i << endl << endl;
//	*p = 5;
//	cout << "*p = 30\n";
//	cout << "p��: " << p << endl;
//	cout << "*p��: " << *p << endl;
//	cout << "i��: " << i << endl;
//
//	//p = &j;
//
//}
