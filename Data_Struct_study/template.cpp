//#include <iostream>
//using namespace std;
////using std::endl; �̷������ε� ��밡��
//
//template <typename T>
//T myadd(T a, T b) { //�ϳ��� Ÿ�� //���������� T
//	return a + b;
//}
//
//template <typename T1, typename T2>
//void myadd(T1 a, T2 b) { //�ΰ��� Ÿ�� �Է°��� //���� ������ void
//	cout << a << b;
//}
//
//template <typename T>
//int mySIzeOf(T a) {
//	return sizeof(a);
//}
//
//template <> //mySizeOf�� Ư���Ѱ�� ! (�Է��� str �� ��.)
//int mySIzeOf(const char* s) { //const �� �ٿ�����!
//	return strlen(s);
//}
//
////Ŭ���� template
//template <typename T>
//class myData {
//	T _data;
//public:
//	myData(T d);
//	void SetData(T d);
//	T GetData();
//}; //���� ��Ÿ���� �κе��� T��!
//
////Ŭ���� ����, ���� �и�
////�Լ� �̸� �տ� myData<T>:: �ٿ��ְ�, ���� template <> ����!
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
//	cout << mySIzeOf(str) << endl; //�̰� ���� ���ϴ� ���� �ƴ� -�ܼ��� �������� ũ�Ⱑ ��µ�. ! ���� �Լ� ��������.
//*/
//	//Ŭ���� template
//	myData<int> d1(0);
//	d1.SetData(3);
//
//	myData<char> d2('A'); //Ŭ���� template�� <����> ������ ��!��!! �ʿ��ϴ�
//	
//	cout << d1.GetData() << endl;
//	cout << d2.GetData() << endl;
//
//	return 0;
//}