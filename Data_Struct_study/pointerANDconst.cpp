//#include <iostream>
//using namespace std;
//
//int main() {
//	int i = 10;
//	int j = 5;
//
//	//가리키는 곳 상수화
//	
//	/*const int *p = &i;
//	cout << "p값: " << p << endl;
//	cout << "*p값: " << *p << endl;
//	cout << "i값: " << i << endl;
//	//*p = 30; //포인터가 가리키는 곳을 바꾸는 것은 불가능
//
//	i = 30; //변수값을 변경하는 건 가능
//	cout << "i=30\n";
//	cout << "p값: " << p << endl;
//	cout << "*p값: " << *p << endl;
//	cout << "i값: " << i << endl;
//	p = &j; //포인터 주소값 변경은 가능
//	cout << "p = &j\n";
//	cout << "p값: " << p << endl;
//	cout << "*p값: " << *p << endl;
//	cout << "i값: " << i << endl;
//	*/
//
//	//포인터 - 주소값 상수화 //const가 포인터 바로앞에 있음
//	
//	int * const p = &i; //포인터 -주소값 상수화
//	cout << "p값: " << p << endl;
//	cout << "*p값: " << *p << endl;
//	cout << "i값: " << i << endl << endl;
//	i = 30;
//	cout << "i=30\n";
//	cout << "p값: " << p << endl;
//	cout << "*p값: " << *p << endl;
//	cout << "i값: " << i << endl << endl;
//	*p = 5;
//	cout << "*p = 30\n";
//	cout << "p값: " << p << endl;
//	cout << "*p값: " << *p << endl;
//	cout << "i값: " << i << endl;
//
//	//p = &j;
//
//}
