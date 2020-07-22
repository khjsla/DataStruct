//#include <iostream>
//using namespace std;
//
///* 포인터에 대한 예시.
//   포인터는 주소값과 + 자료형을 저장합니다. -> 따라서 포인터 사용시, 형식도 신경써야합니다.
//   포인터의 크기는 항상 [ 4 BYTE ] 입니다.
//   포인터를 한번에 많이 선언하는 것은 안됩니다. 일반변수와 동시에 선언하는 것도 안됩니다. 
//   임의의 주소값(0xFF7C등,,)을 대입하는 것도 안됩니다.
//   *를 뗀 이름 자체만은 그 포인터가 가리키는 주소값을 나타냅니다
//   *가 붙어있는 포인터는 그 포인터가 가리키는 주소칸 안에 있는 데이터를 나타냅니다
//*/
//
//int main() {
//	int a = 1;
//	int b = 2;
//
//	int *ptra = &a;
//	int *ptrb = &b;
//	int *temp;
//
//	cout << "before : *ptra=" << *ptra << ", *ptrb=" << *ptrb << endl;
//
//	temp = ptra; //*를 뗸 포인터는 주소칸 안의 데이터가 아닌, 순수 주소값을 나타내게 됩니다.
//	ptra = ptrb;
//	ptrb = temp; //주소값 끼리 swap 해줍니다.
//
//	cout << "after : *ptra=" << *ptra << ", *ptrb=" << *ptrb << endl;
//
//	return 0;
//}