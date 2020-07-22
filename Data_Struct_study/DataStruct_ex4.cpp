////#include <iostream>
////using namespace std;
////
/////* 4번쨰 예제
////   배열의 이름은 배열의 첫 칸의 주소를 의미합니다. &형식같지요
////   그러나, 배열의 이름은 포인터 변수가 아닌, 포인터 상수입니다. 연산/변경이 불가능합니다.
////   따라서, *배열이름 은 배열의 첫칸에 들어있는 데이터 값을 의미합니다.
////   배열이름 + 1 은 배열의 둘째칸의 주소를 의미합니다. &형식같지요
////   +1 의 크기는 그 배열의 형식에 따라 달라지는 상대적인 크기입니다.
////   예를들면 char이면 +1, int면 +4, double이면 +8 이지요.
////*/
////
////int sumary(int ary[], int size);
////int sumaryp(int *ary, int size);
////int sump(int *ary, int size);
////int sump2(int *ary, int size);
////
////int main() { 
////
////	int i = 0, sum = 0, arylength;
////	int point[] = { 95,88,76,54,85,33,65,78,99,82 }; //배열 point 에 성적 10개 초기화
////	arylength = sizeof(point) / sizeof(int); // point가 전체적으로 몇개의 원소를 가지는지가 return됨.
////	// sizeof(point)는 point가 할당한 저장공간의 크기를 바이트로 반환하므로, arylength는 배열원소의 수가 저장됨.
////
////	cout << "배열 point[i]를 이용하여 원소값을 출력 \n" << endl;
////	for (i = 0; i < arylength; i++) { //point 가 가지는 원소 개수만큼 반복. 즉, 10번반복
////		cout << point[i] << (i == arylength - 1 ? "\n\n" : ",") ;
////		//i는 0부터 9까지로 시작되고, arylen의 크기는 10이므로, 9가 아니면 [ , ]  출력. 아니면 한줄넘겨서 다음 for실행
////		sum += point[i]; //배열안의 모든 값의 합
////	}
////	cout << "main 에서 구한 sum; " << sum << endl;
////
////	cout << "sumary() 에서 구한 sum; " << sumary(point, arylength) << endl;
////	cout << "sumaryp() 에서 구한 sum; " << sumaryp(point, arylength) << endl;
////	cout << "sump() 에서 구한 sum; " << sump(point, arylength) << endl;
////	cout << "sump2() 에서 구한 sum; " << sump2(point, arylength) << endl;
////
////	return 0;
////}
////
////int sumary(int ary[], int size) { //main과 똑같은 방식
////	int sum = 0, i = 0;
////	for (i = 0; i < size; i++) {
////		sum += ary[i];
////	}
////	return sum;
////}
////int sumaryp(int *ary, int size) { //point는 포인터 상수. 포인터로 받아질 수 있다
////	int sum = 0, i = 0;
////	for (i = 0; i < size; i++) {
////		sum += ary[i];
////	}
////	return sum;
////}
////int sump(int *ary, int size) { //pointer 접근 방식
////	int sum = 0, i = 0;
////	for (i = 0; i < size; i++) {
////		sum += *(ary + i); 
////		//point[i] == *(point + i) 이기 때문에, 이는 sum += point[i] 와 같음
////	}
////	return sum;
////}
////int sump2(int *ary, int size) {
////	int sum = 0, i = 0;
////	for (i = 0; i < size; i++) {
////		sum += *ary++; 
////		//배열이름 + i 은 배열의 i칸의 주소를 의미합니다.
////		//*가 붙어있는 포인터는 그가 가리키는 주소안의 데이터를 나타냅니다
////		//따라서 이또한 sum += point[i] 와 같음
////	}
////	return sum;
////}
