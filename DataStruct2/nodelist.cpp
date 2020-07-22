//12163291 ������ �ڷᱸ�� HW3 - Iterator ���
#pragma warning(disable:4996) //for _s ERROR

#include <stdio.h>
#include <stdlib.h>
#include <vector> //for use vector
using namespace std;

//Node List class
typedef int Elem; //Elem = int ��� �� �Դϴ�.

class Nodelist { //Nodelist Ŭ������ �����մϴ�.
private:
	//Node ����
	//Doubly linked list �̹Ƿ� next �Ӹ� �ƴ϶�, prev�� �����մϴ�.
	struct Node { 
		Elem elem; // ������ �������
		Node* prev;
		Node* next;
	};
public:
	//Iterator ����
	class Iterator {
	public:
		Elem& operator*();
		bool operator==(const Iterator& p)const;
		bool operator!=(const Iterator& p)const;
		Iterator& operator++();
		Iterator& operator--();
		friend class Nodelist; //�� friend �������� ����, 
		//iterator�� ������ Nodelist Ŭ������ ����ϴ� ���� �㰡�մϴ�.
	private: 
		Node* v;
		Iterator(Node *u);
	};
public:
	//Nodelist class������ �� �Լ��� �������־����ϴ�.
	Nodelist() { 
		n = 0; //int Nodelist::n �Դϴ�.
		header = new Node; //for header 
		trailer = new Node; //for trailer
		header->next = trailer; //point each other
		trailer->prev = header;
	};
	int size() const {
		return n; //n�� count�̹Ƿ�,
	};
	bool empty() const {
		return (n == 0); //���� n==0 �̸� 1 rtn
	};
	
	Iterator begin() const;
	Iterator end() const; //�ۿ��� ��������

	void insertFront(const Elem& e) { //insert at front
		insert(begin(), e);
	}
	void insertBack(const Elem& e) { //insert at rear
		insert(end(), e);
	}
	void insert(const Iterator &p, const Elem &e) {
		Node* w = p.v; //p�� Node
		Node* u = w->prev; //p�� predecessor
		Node* v = new Node; //! new Node to insert !
		v->elem = e; //New Node�� data(element) �Է�, �̴� int���İ� ����
		v->next = w; w->prev = v; // link in v before w
		v->prev = u; u->next = v; // link in v after u
		n++; //node�� insert�Ǹ� n(=node�� ����)�� +1�� ���ݴϴ�.
	}
	void eraseFront() { //remove at front
		erase(begin());
	};
	void eraseBack() { //remove at last
		erase(--end());
	};
	void erase(const Iterator& p) {
		Node* v = p.v; // node to remove
		Node* w = v->next; // successor
		Node* u = v->prev; // predecessor
		u->next = w; w->prev = u; // unlink p
		delete v; // delete this node
		n--; //node�� delete�Ǹ� n(=node�� ����)�� -1�� ���ݴϴ�.
	}

private: //data��
	int n; 
	Node* header;
	Node* trailer;
};

//Iterator �Լ��� ���⼭ �������� ����. ���� ������ ���൵ �Ǳ� ��

Nodelist::Iterator::Iterator(Node* u) { //Node �� u�� �޾ƿͼ�,
	v = u; 
	//v�� �Է����ݴϴ�. 
	//�̴� Iterator Ŭ���� ���� private: Node* v �����Դϴ�.
}

Elem& Nodelist::Iterator::operator*() { 
	//Elem& = int& �Դϴ�. ��, ���Լ��� int ���� rtn�մϴ�.
	
	return v->elem; //elem�� Node �� data �Դϴ�.
	//v�� element, = node�� ������ �Դϴ�.
}

bool Nodelist::Iterator::operator==(const Iterator& p)const {
	return v == p.v;
	//������ 1 rtn
}

bool Nodelist::Iterator::operator!=(const Iterator& p)const {
	return v != p.v;
	//�ٸ��� 1 rtn
}

//��� �տ� Nodelist::
Nodelist::Iterator& Nodelist::Iterator::operator++() {
	v = v->next; //�� ���� next�� ������ update ������,
	return *this; //�� update�� ���� rtn�մϴ�.
}

Nodelist::Iterator& Nodelist::Iterator::operator--() {
	v = v->prev; //�� ���� prev�� ������ update ������,
	return *this; //�� update�� ���� rtn�մϴ�.
}

 //�̰͵� �ۿ��� �������ذ� ����
Nodelist::Iterator Nodelist::begin() const {
	return Iterator(header->next);
	//()���� ������ ������ Node* �Դϴ�.
	//Iterator ������ �Լ��� �۵��Ǹ鼭,���� update�˴ϴ�.
}

Nodelist::Iterator Nodelist::end() const {
	return Iterator(trailer);
	//trailer = �ǵ��� �ڿ��� �ǵ��� next pointer�� ����Ű�� ������ 
}

//�� �Լ��� iterator�� ������� �ʾҽ��ϴ�.
int vectorSum1(const vector<int>& V) {
	int sum = 0; //������ ���� ���� �� ����

	for (int i = 0; i < V.size(); i++) { //vector�� ũ�⸸ŭ �ݺ��մϴ�.
		sum += V[i]; //vetor[] ���� �� ���� ���մϴ�.
	}
	return sum; //�� ���հ��� rtn�մϴ�.
}

int vectorSum2(vector<int> V) {
	typedef vector<int>::iterator Iterator; 
	//Iterator = vector<int>::iterator
	//Iterator �� int�� vectorŬ������ iterator�Լ����� �ǹ��մϴ�.

	int sum = 0; //������ ���� ���� �� ����
	for (Iterator p = V.begin() ; p != V.end() ; ++p) {
		sum += *p;
		//*p = 10 �� ���� *p�� �� ���氡��
	}
	return sum; //�� ���հ��� rtn�մϴ�.
}

int vectorSum3(const vector<int> V) {
	typedef vector<int>::const_iterator ConstIterator;
	//ConstIterator = vector<int>::const_iterator 
	//ConstIterator �� int�� vectorŬ������ const_iterator�Լ����� �ǹ�

	int sum = 0; //������ ���� ���� �� ����
	for (ConstIterator p = V.begin() ; p != V.end() ; ++p) {
		sum += *p;
		//*p = 10 �� ���� *p�� �� ���� �Ұ���
	}
	return sum; //�� ���հ��� rtn�մϴ�.
}

int main() {
	vector<int> n; //for use vector

	printf("12163291 ������ �ڷᱸ�� HW3\n\nVector values:\n");

	for (int i = 0; i < 10; i++) {
		n.push_back(i + 1);  //1���� 10���� ���ʴ�� vector�� �־��ݴϴ�.
		printf("%d ", n[i]); //vector�� Ȯ�ο�
		if (i==9) printf("\n\n");
	}
	
	printf("Vector_Sum values:\n");
	printf("vectorSum1: %d\n", vectorSum1(n));
	printf("vectorSum2: %d\n", vectorSum2(n));
	printf("vectorSum3: %d\n", vectorSum3(n));

}