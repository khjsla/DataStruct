//#include <iostream>
//#include <string> //�ƿ� !! string ���� ������� �����
//using namespace std;
//
//class MathException {
//public:
//	string errMsg;
//public:
//	MathException(const string & err) {
//		errMsg = err;
//	}
//};
//class ZeroDivideException :public MathException {
//public:
//	ZeroDivideException(const string & err) :MathException(err) {
//	}
//};
//class NegativeRootException :public MathException {
//public:
//	NegativeRootException(const string & err) :MathException(err) {
//	}
//};
//
//int main() {
///*	int num;
//
//	cout << "���� �Է�:";
//	cin >> num;
//
//	try {
//		if (num > 0) {
//			throw 10;
//		}
//		else {
//			throw 'A';
//		}
//	}
//	catch (int ex) { //�������� int���̸� (�Է��� >0)
//		cout << ">0 int ���� �Է��� ���ܳ�," << endl;
//	}
//	catch (char ex) { //�������� char�� ���̸� (�Է��� <0)
//		cout << "<0 char ���� �Է��� ���ܳ�," << endl;
//	}
//	*/
//
////���� Ŭ����, ���� ��ü ����
//	int div=4;
//	try {
//		if (div == 0) {
//			throw ZeroDivideException("ZeroDivideException");
//		}
//		if (div == 1) {
//			throw MathException("MathException");
//		}
//		if (div == 2) {
//			throw NegativeRootException("NegativeRootException");
//		}
//		if (div == 3) {
//			throw 10;
//		}
//		if (div == 4) {
//			throw "A";
//		}
//	}
//	catch (ZeroDivideException & ex1) {
//		cout << ex1.errMsg << endl;
//	}
//	catch (MathException& ex1) {
//		cout << ex1.errMsg << endl;
//	}
//	catch (NegativeRootException& ex1) {
//		cout << ex1.errMsg << endl;
//	}
//	catch (...) { //��� ���� handle
//		cout << "erroe";
//	}
//
//	return 0;
//}