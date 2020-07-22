//12162391 강현지 알고리즘 설계 Huffman
#pragma warning(disable:4996)
#include <string.h>
#include <iostream> 
#include <time.h> 
using namespace std;

// This constant can be avoided by explicitly 
// calculating height of Huffman Tree 
#define MAX 419
// 문자열 길이 입력
#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )

char what[MAX] = { 0 }; //알파벳 뭐가 들어왔는지 저장
int length[MAX] = { 0 }; //그 알파벳에 해당하는 비트의 길이를 저장

/* 각 문자, 부호에 대한 허프만 이진코드를 출력하는 함수 */
void HuffmanCode_do_and_print(char data[], int freq[], int size);

/* 각 문자, 부호의 사용빈도를 출력하는 함수 */
void print_freq(char alphabet[], int frequency[], int cnt);

void selection_sort_down(int frequency[], char alphabet[], int n);

// Huffman tree 노드
struct MinHeapNode {
	char symbol; //입력된 알파벳
	unsigned freq; //알파벳의 빈도수
	struct MinHeapNode *left, *right; //노드의 왼쪽, 오른쪽
};

//최소 힙: 최소 힙(또는 Huffman 트리) 노드 모음
struct MinHeap {
	unsigned size;//최소 힙의 현재 크기
	unsigned capacity;//최소 힙의 용량
	struct MinHeapNode** array;//최소힙의 노드 포인터 배열
};

//지정된 문자 및 그 문자의 빈도수를 사용하여 새로운 최소 힙 노드를 할당하는 기능
struct MinHeapNode* newNode(char data, unsigned freq) {
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->symbol = data;
	temp->freq = freq;

	return temp;
}

//지정된 용량의 최소 힙을 생성하는 기능
struct MinHeap* createMinHeap(unsigned capacity) {
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));

	minHeap->size = 0;// 현재 size는 0 

	minHeap->capacity = capacity;

	minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

//2개의 최소 힙 노드 스왑 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

//minHeapify 함수 //가장작은거 골러내기
void minHeapify(struct MinHeap* minHeap, int idx) {
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

// 힙에서 최소값 노드를 추출하는 함수
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];

	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}

//최소 힙에 새 노드를 삽입하는 기능
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {

	++minHeap->size;
	int i = minHeap->size - 1;

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	minHeap->array[i] = minHeapNode;
}

//최소 힙을 만드는 함수 
void buildMinHeap(struct MinHeap* minHeap) {
	int n = minHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}

// n 크기의 배열을 출력하는 기능
void printArr(int arr[], int n) {
	int i;
	for (i = 0; i < n; ++i) {
		cout << arr[i];
	}

	cout << "\n";
}

//이 노드가 리프인지 확인하는 기능
int isLeaf(struct MinHeapNode* root) {
	return !(root->left) && !(root->right);
}

// 크기와 동일한 용량의 최소 힙을 생성하고, 모든 데이터[] 문자를 최소 힙에 삽입하십시오.
//최소 힙의 초기 크기는 용량과 동일함
struct MinHeap* BuildMinHeap(char data[], int freq[], int size) {

	struct MinHeap* minHeap = createMinHeap(size);

	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}

// Huffman tree 주요코드
// 데이터 + 빈도수 노드를 모두 insert
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
	struct MinHeapNode *left, *right, *top;

	//최소 힙의 용량을 만든다
	//1단계: size와 동일한 용량의 최소 힙을 생성하십시오. 처음에는 size와 같은 모드가 있다.
	struct MinHeap* minHeap = BuildMinHeap(data, freq, size);

	// 힙 크기가 1이 되지 않는 동안 반복
	while (!(minHeap->size == 1)) {
		//2단계: 최소 힙에서 두 개의 최소 빈도수 항목을 추출
		left = extractMin(minHeap); 
		right = extractMin(minHeap); //PQ에서 삭제

		// 3단계: 두 노드의 빈도수 합과 동일한 빈도수를 가진 새 내부 노드를 생성하십시오. 
		//추출된 두 노드를 이 새 노드의 왼쪽 및 오른쪽 하위 노드로 만드십시오. 
		//최소 힙에 이 노드 추가.
		top = newNode('?', left->freq + right->freq); 
		//'?'는 사용되지 않는 내부 노드의 특수 값임

		top->left = left;
		top->right = right; //논리

		insertMinHeap(minHeap, top); //다시삽입
	}
	//4단계: 나머지 노드는 root노드고 트리는 완성됩니다.
	return extractMin(minHeap); //PQ에서 삭제
}

int level_t = 0;

// huffman tree의 root에서 허프만 코드를 출력한다. arr[]를 사용하여 코드를 저장한다.
void printCodes(struct MinHeapNode* root, int arr[], int top) {
	// 왼쪽 가장자리에 0을 할당하고 다시 시작 
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	// 오른쪽 가장자리에 1을 할당하고 다시 시작
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}

	// 이 노드가 리프 노드인 경우, 입력 문자 중 하나를 포함하면 arr[]에서 문자 및 코드를 인쇄하십시오.
	if (isLeaf(root)) {
		cout << root->symbol << ": ";
		printArr(arr, top); //huffman 비트값 print
		//여기까지오면 bit가 다 만들어진거임
		//printf("bit길이?: %d\n", top); //top이 비트길이 맞나확인용
		what[level_t] = root->symbol; //what에 있는 symbol
		length[level_t] = top;
		level_t++;
	}
}

//Huffman test
int main() {
	cout << "12163291 강현지 자료구조 Huffman\n\n";
	char line[MAX] = "The Little Prince draws unflattering portraits of grown-ups as being hopelessly narrow-minded.In contrast, children come to wisdom through open-mindedness and a willingness to explore the world around them and within themselves. The main theme of the fable is expressed in the secret that the fox tells the little prince: [It is only with the heart that one can see rightly: what is essential is invisible to the eye.]";
	cout << line[0]; // a임 순서대로 ...쭉

	//char line[MAX] = "AAAAAAABBCCCDEEEEFFFFFFG";
	char alphabet[MAX]; //alphabet //중복안되게 alphabet정렬위해서
	int frequency[MAX] = { 0 }; //frequency //중복 될때마다 +1 씩 해서 몇글자나왔는지 확인
	int cnt = 0; //cnt

	/*
	Huffman 에서 가장 중요한 부분중 하나인
	character당 등장 빈도수를 구하는 
	부분 
	*/
	for (int i = 0; i < strlen(line); i++) { //문자열 개수만큼 돌려서
		for (int j = 0; j <= cnt; j++) { //cnt 만큼 돌려서

			if ((j < cnt) && (line[i] == alphabet[j])) { //특정 알파벳 등장하면
				frequency[j] += 1; //빈도수 +1
				break;
			}
			else if (j == cnt) { //이미 있던거 아니면
				frequency[j] = 1; //빈도수 +1
				alphabet[j] = line[i]; //alphapet에 새 등장 character 입력해줌
				cnt++; //cnt +1
				break;
			}

		}
	}

	cout << "각 알파벳 빈도수 내림차순 나열:" << endl;

	/* Tree 그리기 쉽게 알파벳, 빈도수 배열 내림차로 정리 */
	selection_sort_down(frequency, alphabet, cnt); 

	/* 글자와 그 글자가 등장하는 빈도수 출력 */
	print_freq(alphabet, frequency, cnt);
	 
	cout << endl << "Huffman Code로 각 알파벳에 할당된 비트:" << endl;

	/* hffman돌리고 결과값도 출력 */
	HuffmanCode_do_and_print(alphabet, frequency, cnt);

	return 0;
}

//완성된 huffman tree코드를 사용하여 huffman tree를 만들고 코드를 출력하는 기능
void HuffmanCode_do_and_print(char data[], int freq[], int size) {
	// Huffman Tree 만들어서 root안에 넣기 
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

	//출력하려고 함
	int arr[MAX], top = 0;
	printCodes(root, arr, top);
}

//내림차순 배열하는 sort
//for good look
void selection_sort_down(int frequency[], char alphabet[], int n) { //n= 데이터 개수, []=데이터 값 들어있는 배열
	int min, temp;

	//마지막 숫자는 자동적으로 정렬되므로 sort를 안해줘도 된다. 따라서 n-1만큼 반복한다.
	for (int i = 0; i < n - 1; i++) {
		min = i; //우선 처음에는 최솟값이 처음자리 [0]임. 
		//i 숫자 자리에 맞는 값을 찾아주게 되는것임
		//이후에 최솟값을 탐색해서 이와 비교해줌,

		//최솟값을 탐색한다
		for (int j = i + 1; j < n; j++) { //i값의 자리를 찾아줘야 하므로, i+1부터 비교해줌
			if (frequency[j] > frequency[min]) { //가장 작은 수가 나올때까지 반복 비교해서 
				min = j; //min에 가장작은 수가 들어있는 index값을 넣어줌.
			}
		}

		//자기자신이 최솟값이면 이동을 하지않고,
		//자기자신이 최솟값이 아니면 swap으로 자기자신의 자리와 최솟값의 자리를 바꿔줍니다.
		if (i != min) {
			SWAP(frequency[i], frequency[min], temp);
			SWAP(alphabet[i], alphabet[min], temp);
		}
	}
}

void print_freq(char alphabet[], int frequency[], int cnt) {
	for (int i = 0; i < cnt; i++) {
		cout << alphabet[i] << " = " << frequency[i] << endl;
	}
}