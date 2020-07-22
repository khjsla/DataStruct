//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//void heapify(int i);
//void heapsort(int i); /**///표시된곳 바꾸면 오름차, 내림차 바뀌어짐
//
//void do1(int x);
////void do2(int x);
//int heap1[101] = { 0 }; //처음에 0으로 채워나야함
//int n1;
//
//int main() {
//	int what;
//	int cham = 0;
//
//	do {
//		cin >> what;
//
//		if (what > 20200101) { //숫자 크면 날짜로 생각
//			cham = cham + 1;
//			n1 = cham;
//			heap1[cham] = what;
//		}
//		else if (what <= 20) { //먹을 참치양  
//			if (what > 20) exit(1); //20보다 크면 꺼져
//			for (int i = 1; i <= what; i++) {
//				do1(what); //sorting
//				cout << heap1[1] << endl;
//				cham--;
//				for (int i = 1; i <= cham; i++) { //다시 
//					heap1[i] = heap1[i + 1];
//				}
//			}
//		}
//	} while (what != 0); //0들어오기 전까지 반복
//}
//
////오름차 //자식>부모 //min heap //항상 root에는 가장 작은 값이 오게 됩니다.
//
//void heapify(int i) //현 노드의 인덱스 값을 받습니다.
//{
//	int cur = 2 * i; //현 노드의 인덱스 * 2는 좌측 자식 인덱스입니다 +1하면 우측 자식 인덱스입니다.
//
//	if (cur < n1 && heap1[cur] < heap1[cur + 1]) cur++; /**///자식들간의 비교를 하여 cur에 저장합니다.
//
//	if (heap1[i] < heap1[cur]) /**///현 노드와 자식중 더 큰값인 애를 비교합니다.
//	{
//		swap(heap1[i], heap1[cur]); //만약에 자식이 더 크면 자리는 그대로, 서로 배열안의 값을 swap합니다
//		if (cur <= n1 / 2) heapify(cur); //만약 현노드와 자식의 값이 바뀌었다면,
//		//앞서 설정했던 자식간의 대소관계가 깨졌을수도 있으므로 다시 재귀를 통해 
//		//자식간의 대소관계를 설정합니다.
//	}
//}
////우선 배열값을 받고, heapify를 통해 첫 root값을 찾으면, 그 다음은 sorting입니다.
//
//void heapsort(int i)
//{
//	swap(heap1[1], heap1[i]); //root와 마지막 노드의 값을 바꿉니다.
//	//이후 루트에는 최하단의 랜덤 자식노드 값이 들어오게 됩니다.
//	//커서(cur)를 루트의 왼쪽 자식노드쪽에 두고 구성을 시작합니다.
//
//	int root = 1; //root의 인덱스는 1이니까. 설정
//	int cur = 2; //root의 좌측하단에 커서 설정
//
//	while (cur / 2 < i) //커서위치가 마지막 인덱스위치보다 위에있을때까지
//	{
//		cur = 2 * root; //지금의 커서 값에 root*2.
//		if (cur < i - 1 && heap1[cur] < heap1[cur + 1]) cur++; /**/ 
//		//자식비교, 오른쪽이 더크면 오른쪽에 커서옮김
//		if (cur < i && heap1[root] < heap1[cur]) /**/
//			swap(heap1[root], heap1[cur]);
//		//root값이랑 지금 자식중에 더 큰애랑 바꿔줌 
//
//		root = cur;
//		//루트값을 지금 커서값으로 변경,
//		//루트위치를 하나 내려준 것임
//	}
//}
//
//
//void do1(int x) {
//	for (int i = n1 / 2; i > 0; i--) { // 최초 맨 위의 heap 생성하기  
//		heapify(i); //첫 heapify값은 처음에 입력받은 숫자*1/2
//	}
//	for (int i = n1; i > 0; i--) { // heap 정렬해나가기
//		heapsort(i); //첫 heapsort입력값은 처음에 입력받은 숫자 = 인덱스 마지막 값
//	}
//}
//

//heapsort 전과제

//#include <iostream>
//using namespace std;
//
//void heapify(int i);
//void heapsort(int i); /**///표시된곳 바꾸면 오름차, 내림차 바뀌어짐
//
//void heapify_(int i);
//void heapsort_(int i); /**///표시된곳 바꾸면 오름차, 내림차 바뀌어짐
//
//void do1(int x);
//void do2(int x);
//
//int n, heap1[101], heap2[101]; //인덱스 크기는 max값 인데 0을 안쓰므로 +1해줍니다.
//int n1, n2;
//
//int main() //오름차순의 heap입니다.
//{
//	int sum = 0;
//
//	scanf("%d", &n); //n이라는 숫자를 입력받아
//
//	for (int i = 1; i <= n; i++) { //그 숫자만큼의 데이터를 heap이라는 배열에 저장
//		scanf("%d", &heap1[i]); //[1]에서부터 값이 넣어집니다.
//	}
//	for (int i = 1; i <= n; i++) { //그 숫자만큼의 데이터를 heap이라는 배열에 저장
//		scanf("%d", &heap2[i]); //[1]에서부터 값이 넣어집니다.
//	}
//
//	n1 = n;
//	n2 = n;
//
//	do1(n1);
//	do2(n2);
//
//	for (int j = 1; j <= n; j++) {// 마지막에 heap출력하기
//		sum += heap1[j] * heap2[j];
//	}
//
//	printf("%d ", sum);
//}
//
//void heapify(int i) //현 노드의 인덱스 값을 받습니다.
//{
//	int cur = 2 * i; //현 노드의 인덱스 * 2는 좌측 자식 인덱스입니다 +1하면 우측 자식 인덱스입니다.
//
//	if (cur < n1 && heap1[cur] < heap1[cur + 1]) cur++; /**///자식들간의 비교를 하여 cur에 저장합니다.
//
//	if (heap1[i] < heap1[cur]) /**///현 노드와 자식중 더 큰값인 애를 비교합니다.
//	{
//		swap(heap1[i], heap1[cur]); //만약에 자식이 더 크면 자리는 그대로, 서로 배열안의 값을 swap합니다
//		if (cur <= n1 / 2) heapify(cur); //만약 현노드와 자식의 값이 바뀌었다면,
//		//앞서 설정했던 자식간의 대소관계가 깨졌을수도 있으므로 다시 재귀를 통해 
//		//자식간의 대소관계를 설정합니다.
//	}
//}
////우선 배열값을 받고, heapify를 통해 첫 root값을 찾으면, 그 다음은 sorting입니다.
//
//void heapsort(int i)
//{
//	swap(heap1[1], heap1[i]); //root와 마지막 노드의 값을 바꿉니다.
//	//이후 루트에는 최하단의 랜덤 자식노드 값이 들어오게 됩니다.
//	//커서(cur)를 루트의 왼쪽 자식노드쪽에 두고 구성을 시작합니다.
//
//	int root = 1; //root의 인덱스는 1이니까. 설정
//	int cur = 2; //root의 좌측하단에 커서 설정
//
//	while (cur / 2 < i) //커서위치가 마지막 인덱스위치보다 위에있을때까지
//	{
//		cur = 2 * root; //지금의 커서 값에 root*2.
//		if (cur < i - 1 && heap1[cur] < heap1[cur + 1]) cur++; /**/
//		//자식비교, 오른쪽이 더크면 오른쪽에 커서옮김
//		if (cur < i && heap1[root] < heap1[cur]) /**/
//			swap(heap1[root], heap1[cur]);
//		//root값이랑 지금 자식중에 더 큰애랑 바꿔줌 
//
//		root = cur;
//		//루트값을 지금 커서값으로 변경,
//		//루트위치를 하나 내려준 것임
//	}
//}
//
//void heapify_(int i) //현 노드의 인덱스 값을 받습니다.
//{
//	int cur_ = 2 * i; //현 노드의 인덱스 * 2는 좌측 자식 인덱스입니다 +1하면 우측 자식 인덱스입니다.
//
//	if (cur_ < n2 && heap2[cur_] > heap2[cur_ + 1]) cur_++; /**///자식들간의 비교를 하여 cur에 저장합니다.
//
//	if (heap2[i] > heap2[cur_]) /**///현 노드와 자식중 더 큰값인 애를 비교합니다.
//	{
//		swap(heap2[i], heap2[cur_]); //만약에 자식이 더 크면 자리는 그대로, 서로 배열안의 값을 swap합니다
//		if (cur_ <= n2 / 2) heapify_(cur_); //만약 현노드와 자식의 값이 바뀌었다면,
//		//앞서 설정했던 자식간의 대소관계가 깨졌을수도 있으므로 다시 재귀를 통해 
//		//자식간의 대소관계를 설정합니다.
//	}
//}
////우선 배열값을 받고, heapify를 통해 첫 root값을 찾으면, 그 다음은 sorting입니다.
//
//void heapsort_(int i)
//{
//	swap(heap2[1], heap2[i]); //root와 마지막 노드의 값을 바꿉니다.
//	//이후 루트에는 최하단의 랜덤 자식노드 값이 들어오게 됩니다.
//	//커서(cur)를 루트의 왼쪽 자식노드쪽에 두고 구성을 시작합니다.
//
//	int root_ = 1; //root의 인덱스는 1이니까. 설정
//	int cur_ = 2; //root의 좌측하단에 커서 설정
//
//	while (cur_ / 2 < i) //커서위치가 마지막 인덱스위치보다 위에있을때까지
//	{
//		cur_ = 2 * root_; //지금의 커서 값에 root*2.
//		if (cur_ < i - 1 && heap2[cur_] > heap2[cur_ + 1]) cur_++; /**/
//		//자식비교, 오른쪽이 더크면 오른쪽에 커서옮김
//		if (cur_ < i && heap2[root_] > heap2[cur_]) /**/
//			swap(heap2[root_], heap2[cur_]);
//		//root값이랑 지금 자식중에 더 큰애랑 바꿔줌 
//
//		root_ = cur_;
//		//루트값을 지금 커서값으로 변경,
//		//루트위치를 하나 내려준 것임
//	}
//}
//
//void do1(int x) {
//	for (int i = n1 / 2; i > 0; i--) { // 최초 맨 위의 heap 생성하기  
//		heapify(i); //첫 heapify값은 처음에 입력받은 숫자*1/2
//	}
//	for (int i = n1; i > 0; i--) { // heap 정렬해나가기
//		heapsort(i); //첫 heapsort입력값은 처음에 입력받은 숫자 = 인덱스 마지막 값
//	}
//}
//
//void do2(int x) {
//	for (int i = n2 / 2; i > 0; i--) { // 최초 맨 위의 heap 생성하기  
//		heapify_(i); //첫 heapify값은 처음에 입력받은 숫자*1/2
//	}
//	for (int i = n2; i > 0; i--) { // heap 정렬해나가기
//		heapsort_(i); //첫 heapsort입력값은 처음에 입력받은 숫자 = 인덱스 마지막 값
//	}
//}
