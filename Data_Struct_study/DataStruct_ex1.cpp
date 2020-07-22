//#include <iostream>
//#include <iomanip>
//using namespace std;
//
///* 주소연산자 & 에 대한 예시1 
//   어떤 변수의 주소를 알아내기 위해서는 변수앞에 & 연산자를 추가해줍니다.
//   그렇게 되면 그 변수의 주소값을 return 하게 됩니다. */
//
//int main() {
//
//	char a, b, c; //char형 변수3개 //char는 크기가 1
//	char str1[4]; //char형 str1 array, 크기는 4
//	chark str2[5]; 
//	short s1, s2; //short는 크기가2
//	double d; //double은 크기가6
//	int i, j, k; //int는 크기가4
//
//	//hex = 16진수를의미합니다 = 10 - a / 11 - b / ...
//
//	cout << endl << "a,b,c 주소=" << hex << (int)&a << "," << (int)&b << "," << (int)&c << endl << endl;
//	cout << "str1의 주소=" << hex << (int)str1 << endl; //어레이 명은 어레이 첫 칸의 주소와 같습니다.
//	cout << "str1[0]의 주소=" << hex << (int)&str1[0] << endl; //str1 과 &str1[0] 이 같은게 요점입니다.
//	cout << "str1[1]의 주소=" << hex << (int)&str1[1] << endl; //char형이므로 1씩 커집니다.
//	cout << "str1[2]의 주소=" << hex << (int)&str1[2] << endl;
//	cout << "str1[3]의 주소=" << hex << (int)&str1[3] << endl << endl;
//
//	cout << "str2의 주소=" << hex << (int)str2 << endl;
//	cout << "str2[0]의 주소=" << hex << (int)&str2[0] << endl; //str2 과 &str2[0] 이 같은게 요점입니다.
//	cout << "str2[1]의 주소=" << hex << (int)&str2[1] << endl;
//	cout << "str2[2]의 주소=" << hex << (int)&str2[2] << endl;
//	cout << "str2[3]의 주소=" << hex << (int)&str2[3] << endl << endl;
//
//	cout << "s1 의 주소=" << &s1 << endl; //&를 붙이면 그 데이터를 담고있는 공간의 주소를 의미하게 되지요
//	cout << "s2 의 주소=" << &s2 << endl;
//	cout << "d 의 주소=" << &d << endl;
//	cout << "i 의 주소=" << &i << endl;
//	cout << "j 의 주소=" << &j << endl;
//	cout << "k 의 주소=" << &k << endl;
//
//	return 0;
//}