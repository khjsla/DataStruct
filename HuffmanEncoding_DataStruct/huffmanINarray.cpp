//12162391 ������ �˰��� ���� Huffman
#pragma warning(disable:4996)
#include <string.h>
#include <iostream> 
#include <time.h> 
using namespace std;

// This constant can be avoided by explicitly 
// calculating height of Huffman Tree 
#define MAX 419
// ���ڿ� ���� �Է�
#define SWAP(x,y,temp)( (temp)=(x), (x)=(y), (y)=(temp) )

char what[MAX] = { 0 }; //���ĺ� ���� ���Դ��� ����
int length[MAX] = { 0 }; //�� ���ĺ��� �ش��ϴ� ��Ʈ�� ���̸� ����

/* �� ����, ��ȣ�� ���� ������ �����ڵ带 ����ϴ� �Լ� */
void HuffmanCode_do_and_print(char data[], int freq[], int size);

/* �� ����, ��ȣ�� ���󵵸� ����ϴ� �Լ� */
void print_freq(char alphabet[], int frequency[], int cnt);

void selection_sort_down(int frequency[], char alphabet[], int n);

// Huffman tree ���
struct MinHeapNode {
	char symbol; //�Էµ� ���ĺ�
	unsigned freq; //���ĺ��� �󵵼�
	struct MinHeapNode *left, *right; //����� ����, ������
};

//�ּ� ��: �ּ� ��(�Ǵ� Huffman Ʈ��) ��� ����
struct MinHeap {
	unsigned size;//�ּ� ���� ���� ũ��
	unsigned capacity;//�ּ� ���� �뷮
	struct MinHeapNode** array;//�ּ����� ��� ������ �迭
};

//������ ���� �� �� ������ �󵵼��� ����Ͽ� ���ο� �ּ� �� ��带 �Ҵ��ϴ� ���
struct MinHeapNode* newNode(char data, unsigned freq) {
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->symbol = data;
	temp->freq = freq;

	return temp;
}

//������ �뷮�� �ּ� ���� �����ϴ� ���
struct MinHeap* createMinHeap(unsigned capacity) {
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));

	minHeap->size = 0;// ���� size�� 0 

	minHeap->capacity = capacity;

	minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

//2���� �ּ� �� ��� ���� 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

//minHeapify �Լ� //���������� �񷯳���
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

// ������ �ּҰ� ��带 �����ϴ� �Լ�
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];

	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}

//�ּ� ���� �� ��带 �����ϴ� ���
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {

	++minHeap->size;
	int i = minHeap->size - 1;

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	minHeap->array[i] = minHeapNode;
}

//�ּ� ���� ����� �Լ� 
void buildMinHeap(struct MinHeap* minHeap) {
	int n = minHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}

// n ũ���� �迭�� ����ϴ� ���
void printArr(int arr[], int n) {
	int i;
	for (i = 0; i < n; ++i) {
		cout << arr[i];
	}

	cout << "\n";
}

//�� ��尡 �������� Ȯ���ϴ� ���
int isLeaf(struct MinHeapNode* root) {
	return !(root->left) && !(root->right);
}

// ũ��� ������ �뷮�� �ּ� ���� �����ϰ�, ��� ������[] ���ڸ� �ּ� ���� �����Ͻʽÿ�.
//�ּ� ���� �ʱ� ũ��� �뷮�� ������
struct MinHeap* BuildMinHeap(char data[], int freq[], int size) {

	struct MinHeap* minHeap = createMinHeap(size);

	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}

// Huffman tree �ֿ��ڵ�
// ������ + �󵵼� ��带 ��� insert
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
	struct MinHeapNode *left, *right, *top;

	//�ּ� ���� �뷮�� �����
	//1�ܰ�: size�� ������ �뷮�� �ּ� ���� �����Ͻʽÿ�. ó������ size�� ���� ��尡 �ִ�.
	struct MinHeap* minHeap = BuildMinHeap(data, freq, size);

	// �� ũ�Ⱑ 1�� ���� �ʴ� ���� �ݺ�
	while (!(minHeap->size == 1)) {
		//2�ܰ�: �ּ� ������ �� ���� �ּ� �󵵼� �׸��� ����
		left = extractMin(minHeap); 
		right = extractMin(minHeap); //PQ���� ����

		// 3�ܰ�: �� ����� �󵵼� �հ� ������ �󵵼��� ���� �� ���� ��带 �����Ͻʽÿ�. 
		//����� �� ��带 �� �� ����� ���� �� ������ ���� ���� ����ʽÿ�. 
		//�ּ� ���� �� ��� �߰�.
		top = newNode('?', left->freq + right->freq); 
		//'?'�� ������ �ʴ� ���� ����� Ư�� ����

		top->left = left;
		top->right = right; //��

		insertMinHeap(minHeap, top); //�ٽû���
	}
	//4�ܰ�: ������ ���� root���� Ʈ���� �ϼ��˴ϴ�.
	return extractMin(minHeap); //PQ���� ����
}

int level_t = 0;

// huffman tree�� root���� ������ �ڵ带 ����Ѵ�. arr[]�� ����Ͽ� �ڵ带 �����Ѵ�.
void printCodes(struct MinHeapNode* root, int arr[], int top) {
	// ���� �����ڸ��� 0�� �Ҵ��ϰ� �ٽ� ���� 
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	// ������ �����ڸ��� 1�� �Ҵ��ϰ� �ٽ� ����
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}

	// �� ��尡 ���� ����� ���, �Է� ���� �� �ϳ��� �����ϸ� arr[]���� ���� �� �ڵ带 �μ��Ͻʽÿ�.
	if (isLeaf(root)) {
		cout << root->symbol << ": ";
		printArr(arr, top); //huffman ��Ʈ�� print
		//����������� bit�� �� �����������
		//printf("bit����?: %d\n", top); //top�� ��Ʈ���� �³�Ȯ�ο�
		what[level_t] = root->symbol; //what�� �ִ� symbol
		length[level_t] = top;
		level_t++;
	}
}

//Huffman test
int main() {
	cout << "12163291 ������ �ڷᱸ�� Huffman\n\n";
	char line[MAX] = "The Little Prince draws unflattering portraits of grown-ups as being hopelessly narrow-minded.In contrast, children come to wisdom through open-mindedness and a willingness to explore the world around them and within themselves. The main theme of the fable is expressed in the secret that the fox tells the little prince: [It is only with the heart that one can see rightly: what is essential is invisible to the eye.]";
	cout << line[0]; // a�� ������� ...��

	//char line[MAX] = "AAAAAAABBCCCDEEEEFFFFFFG";
	char alphabet[MAX]; //alphabet //�ߺ��ȵǰ� alphabet�������ؼ�
	int frequency[MAX] = { 0 }; //frequency //�ߺ� �ɶ����� +1 �� �ؼ� ����ڳ��Դ��� Ȯ��
	int cnt = 0; //cnt

	/*
	Huffman ���� ���� �߿��� �κ��� �ϳ���
	character�� ���� �󵵼��� ���ϴ� 
	�κ� 
	*/
	for (int i = 0; i < strlen(line); i++) { //���ڿ� ������ŭ ������
		for (int j = 0; j <= cnt; j++) { //cnt ��ŭ ������

			if ((j < cnt) && (line[i] == alphabet[j])) { //Ư�� ���ĺ� �����ϸ�
				frequency[j] += 1; //�󵵼� +1
				break;
			}
			else if (j == cnt) { //�̹� �ִ��� �ƴϸ�
				frequency[j] = 1; //�󵵼� +1
				alphabet[j] = line[i]; //alphapet�� �� ���� character �Է�����
				cnt++; //cnt +1
				break;
			}

		}
	}

	cout << "�� ���ĺ� �󵵼� �������� ����:" << endl;

	/* Tree �׸��� ���� ���ĺ�, �󵵼� �迭 �������� ���� */
	selection_sort_down(frequency, alphabet, cnt); 

	/* ���ڿ� �� ���ڰ� �����ϴ� �󵵼� ��� */
	print_freq(alphabet, frequency, cnt);
	 
	cout << endl << "Huffman Code�� �� ���ĺ��� �Ҵ�� ��Ʈ:" << endl;

	/* hffman������ ������� ��� */
	HuffmanCode_do_and_print(alphabet, frequency, cnt);

	return 0;
}

//�ϼ��� huffman tree�ڵ带 ����Ͽ� huffman tree�� ����� �ڵ带 ����ϴ� ���
void HuffmanCode_do_and_print(char data[], int freq[], int size) {
	// Huffman Tree ���� root�ȿ� �ֱ� 
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

	//����Ϸ��� ��
	int arr[MAX], top = 0;
	printCodes(root, arr, top);
}

//�������� �迭�ϴ� sort
//for good look
void selection_sort_down(int frequency[], char alphabet[], int n) { //n= ������ ����, []=������ �� ����ִ� �迭
	int min, temp;

	//������ ���ڴ� �ڵ������� ���ĵǹǷ� sort�� �����൵ �ȴ�. ���� n-1��ŭ �ݺ��Ѵ�.
	for (int i = 0; i < n - 1; i++) {
		min = i; //�켱 ó������ �ּڰ��� ó���ڸ� [0]��. 
		//i ���� �ڸ��� �´� ���� ã���ְ� �Ǵ°���
		//���Ŀ� �ּڰ��� Ž���ؼ� �̿� ������,

		//�ּڰ��� Ž���Ѵ�
		for (int j = i + 1; j < n; j++) { //i���� �ڸ��� ã����� �ϹǷ�, i+1���� ������
			if (frequency[j] > frequency[min]) { //���� ���� ���� ���ö����� �ݺ� ���ؼ� 
				min = j; //min�� �������� ���� ����ִ� index���� �־���.
			}
		}

		//�ڱ��ڽ��� �ּڰ��̸� �̵��� �����ʰ�,
		//�ڱ��ڽ��� �ּڰ��� �ƴϸ� swap���� �ڱ��ڽ��� �ڸ��� �ּڰ��� �ڸ��� �ٲ��ݴϴ�.
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