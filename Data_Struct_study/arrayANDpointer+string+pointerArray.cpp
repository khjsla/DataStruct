#include <iostream>
using namespace std;

//배열이름 - 포인터 상수와 pointer관계 
/*
int main() {
	int point[] = { 1,2,3 };
	
	cout << point << endl; //
	cout << &point << endl; //
	cout << &point[0] << endl; //위의 2개값 다 배열 첫 부분의 주소값으로 같음
	cout << &point[1] << endl; //+4씩됨 int니까
	cout << &point[2] << endl;

	cout << endl << "안의 값확인" << endl; 
	cout << *point << endl; // 1
	cout << *&point << endl; // 첫 부분의 주소값
	cout << *(&point[0]) << endl; //1

	//point = &i; //배열의 이름은 포인터 상수이므로 값을 수정할 수 없다.

	return 0;
}
*/

//문자열과 포인터
/*
int main() {

	char str1[4] = "abc"; //이건 한글자씩 한칸의 배열에 들어가게된다

	const char *str2 = "abc"; //const가 꼭 붙어줘야한다 왜냐하면 abc는 문자열상수이기 때문이고, 지금 나는 c++을 사용하기 때문

	//str2[1] = "d"; //문자열 '상수'이므로 수정불가


}
*/

//포인터 배열
/*
int main() {
	double j, f, g, h, i = 0.1;
	double *a = &j;
	double *b = &f;
	double *c = &g;
	double *d = &h;
	double *e = &i;
	const double *pointerARRAY[5] = { a,b,c,d,e }; //이것도 const꼭 붙여둬야함. 각 배열의 값은.  "a" "b" ,,값을 담고있는 방의 주소를 가리키게 됨

	for (int i = 0; i < 5; i++) {
		cout << &*pointerARRAY[i] << endl; //
	}
}*/

//포인터배열 교수님 예씨
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