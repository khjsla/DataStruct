////#include <iostream>
////using namespace std;
////
/////* 5번쨰 예제
////   배열의 이름은 배열의 첫 칸의 주소를 의미합니다. &형식같지요
////   그러나, 배열의 이름은 포인터 변수가 아닌, 포인터 상수입니다. 연산/변경이 불가능합니다.
////   따라서, *배열이름 은 배열의 첫칸에 들어있는 데이터 값을 의미합니다.
////   배열이름 + 1 은 배열의 둘째칸의 주소를 의미합니다. &형식같지요
////   +1 의 크기는 그 배열의 형식에 따라 달라지는 상대적인 크기입니다.
////   예를들면 char이면 +1, int면 +4, double이면 +8 이지요.
////*/
////
////int main() {
////
////	int i = 0, aryLength;
////	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
////	int point[] = { 95,88,76,54,85,33,65,78,99,82 }; //배열 point 에 성적 10개 초기화
////	int *pi = point;
////
////	aryLength = sizeof(point) / sizeof(int); // point가 전체적으로 몇개의 원소를 가지는지가 return됨.
////	// sizeof(point)는 point가 할당한 저장공간의 크기를 바이트로 반환하므로, aryLength는 배열원소의 수가 저장됨.
////
////	cout << "배열 point[i]를 이용하여 원소값을 출력 \n" << endl;
////	for (i = 0; i < aryLength; i++) { //point 가 가지는 원소 개수만큼 반복. 즉, 10번반복
////		cout << point[i] << (i == aryLength - 1 ? "\n\n" : ",") ;
////		//i는 0부터 9까지로 시작되고, aryLen의 크기는 10이므로, 9가 아니면 [ , ]  출력. 아니면 한줄넘겨서 다음 for실행
//		sum1 += point[i]; //배열의 모든 합
//		sum2 += *(point + i); //point[i] == *(point + i) 이기 때문에, 이는 sum2 += point[i] 와 같습니다.
//		sum3 += pi[i]; // pi는 point와 같습니다. 앞서 정의했듯이. 따라서 이는 point[i]와 같습니다.
//		sum4 += *(pi + i); //pi[i] == *(pi + i) 이므로 위와 같습니다.
//	}
//	cout << "여러방식으로 구한 sum은 각각 " << sum1 << ", " << sum2 << ", " << sum3 << ", " << sum4 << ", ";
//
//	for (i = 0; i < aryLength; i++) {
//		sum5 += *pi++;
//		//배열이름 + i 은 배열의 i칸의 주소를 의미합니다.
//		//*가 붙어있는 포인터는 그가 가리키는 주소안의 데이터를 나타냅니다
//		//따라서 이또한 sum5 += pi[i](=point[i]) 와 같음
//	}
//	cout << sum5 << endl;
//
//	return 0;
//}
