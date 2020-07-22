//#include <iostream>
//using namespace std;
////using std::endl; 이런식으로도 사용가능
//
//template <typename T>
//T myadd(T a, T b) { //하나의 타입 //리턴형식은 T
//	return a + b;
//}
//
//template <typename T1, typename T2>
//void myadd(T1 a, T2 b) { //두개의 타입 입력가능 //리턴 형식은 void
//	cout << a << b;
//}
//
//template <typename T>
//int mySIzeOf(T a) {
//	return sizeof(a);
//}
//
//template <> //mySizeOf의 특수한경우 ! (입력이 str 일 때.)
//int mySIzeOf(const char* s) { //const 꼭 붙여야함!
//	return strlen(s);
//}
//
////클래스 template
//template <typename T>
//class myData {
//	T _data;
//public:
//	myData(T d);
//	void SetData(T d);
//	T GetData();
//}; //형식 나타내는 부분들을 T로!
//
////클래스 선언, 정의 분리
////함수 이름 앞에 myData<T>:: 붙여주고, 위에 template <> 해줌!
//template <typename T>
//myData<T>::myData(T d) {
//	_data = d;
//}
//
//template <typename T>
//void myData<T>::SetData(T d) {
//	_data = d;
//}
//
//template <typename T>
//T myData<T>::GetData() {
//	return _data;
//}
//
//int main() {
//	//template specialization
///*	int i = 123;
//	double e = 3.14;
//	const char * str = "helloww";
//
//	cout << mySIzeOf(i) << endl;
//	cout << mySIzeOf(e) << endl;
//	cout << mySIzeOf(str) << endl; //이건 값이 원하는 값이 아님 -단순히 포인터의 크기가 출력됨. ! 따로 함수 설정하자.
//*/
//	//클래수 template
//	myData<int> d1(0);
//	d1.SetData(3);
//
//	myData<char> d2('A'); //클래스 template는 <형식> 지정이 꼭!꼭!! 필요하다
//	
//	cout << d1.GetData() << endl;
//	cout << d2.GetData() << endl;
//
//	return 0;
//}