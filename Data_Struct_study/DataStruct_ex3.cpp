//#include <iostream>
//using namespace std;
//
///* 배열과 포인터 예제
//   배열의 이름은 배열의 첫 칸의 주소를 의미합니다. &형식같지요
//   그러나, 배열의 이름은 포인터 변수가 아닌, 포인터 상수입니다. 연산/변경이 불가능합니다.
//   따라서, *배열이름 은 배열의 첫칸에 들어있는 데이터 값을 의미합니다.
//   배열이름 + 1 은 배열의 둘째칸의 주소를 의미합니다. &형식같지요
//   +1 의 크기는 그 배열의 형식에 따라 달라지는 상대적인 크기입니다. 
//   예를들면 char이면 +1, int면 +4, double이면 +8 이지요.
//*/
//
//int main() { //배열 point의 원소와 주소값을 각각 출력하는 프로그램
//
//	int i = 0, aryLength;
//	int point[] = { 95,88,76,54,85,33,65,78,99,82 }; //배열 point 에 성적 10개 초기화
//	aryLength = sizeof(point) / sizeof(int); // point가 전체적으로 몇개의 원소를 가지는지가 return됨.
//	// sizeof(point)는 point가 할당한 저장공간의 크기를 바이트로 반환하므로, aryLength는 배열원소의 수가 저장됨.
//
//	cout << "배열 point[i]를 이용하여 원소값을 출력 \n" << endl;
//	for (i = 0; i < aryLength; i++) { //point 가 가지는 원소 개수만큼 반복. 즉, 10번반복
//		cout << point[i] << (i == aryLength - 1 ? "\n\n" : ",");
//		//i는 0부터 9까지로 시작되고, aryLen의 크기는 10이므로, 9가 아니면 [ , ]  출력. 아니면 한줄넘겨서 다음 for실행
//	}
//
//	cout << "주소상수 point를 이용하여 원소의 주소값과 원소값을 출력 \n" << endl;
//	for (i = 0; i < aryLength; i++) { //10번반복
//		cout << "(point + " << i << ") == " << (point + i) << ", *(point + " << i << ") == " << *(point + i) << endl; 
//		//배열이름에 +1 될때마다, 주소값은 얼마나 커지는지. 값은 맞게 다음게 나오는지 확인하는 반복문
//	}
//
//	return 0;
//}