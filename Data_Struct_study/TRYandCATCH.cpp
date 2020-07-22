//#include <iostream>
//#include <string> //아오 !! string 쓸때 까먹지좀 말어라
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
//	cout << "정수 입력:";
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
//	catch (int ex) { //던져진게 int값이면 (입력이 >0)
//		cout << ">0 int 형식 입력의 예외네," << endl;
//	}
//	catch (char ex) { //던져진게 char형 값이면 (입력이 <0)
//		cout << "<0 char 형식 입력의 예외네," << endl;
//	}
//	*/
//
////예외 클래스, 예외 객체 예시
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
//	catch (...) { //모든 에러 handle
//		cout << "erroe";
//	}
//
//	return 0;
//}