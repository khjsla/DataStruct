//#include <iostream>
//using namespace std;
//
//void swap(int * const a, int * const b) {
//	int temp;
//	temp = *a;
//	*a = *b; //*붙여도 되고 안붙여도됨
//	*b = temp;
//}
//
//void swap_ref(int &a, int &b) {
//	int temp;
//	temp = a;
//	a = b; //*붙여도 되고 안붙여도됨
//	b = temp;
//}
//
//void printdata(int &p) {
//	int what = 0;
//	int *ptr = &what;
//	p = what;
//
//}
//
//int& addOne(int &val) {
//	val++;
//	return val; //val은 4인데 이는 &형식임
//}
//
//int& addOne_ref() { //지역변수 //외부 fun에서 정의한 변수를 &로 리턴하면 안됨...! 근데 되는ㄷㅔ?
//	int val = 1;
//	return val;
//}
//
//int main() {
//	int *prt; //ptr은 이상태 가능
//	//int &ref; &는 무조건 초기화를 해야함
//	//////////////////////////////////////////////////////////////////////////////////////////////
//
//	int val = 3;
//	//double &ref = val; //형식 맞아야함
//	//////////////////////////////////////////////////////////////////////////////////////////////
//	
//	int a, b;
//	//cin >> a >> b;
//	//swap(a, b); //여기에 & 붙여도 되고안붙여도됨
//	//cout << a << " " << b << endl;
//	//////////////////////////////////////////////////////////////////////////////////////////////
//	
//	int n = 3;
//	//int &ref = addOne(n);
//
//	//cout << "n: " << n << endl;
//	//cout << "ref: " << ref << endl;
//	/*                                         */
//	
//	int &ref = addOne_ref(); //근데 되는데?
//	cout << ref << endl;
//	//////////////////////////////////////////////////////////////////////////////////////////////
//	return 0;
//}
