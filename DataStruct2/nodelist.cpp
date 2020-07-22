//12163291 강현지 자료구조 HW3 - Iterator 사용
#pragma warning(disable:4996) //for _s ERROR

#include <stdio.h>
#include <stdlib.h>
#include <vector> //for use vector
using namespace std;

//Node List class
typedef int Elem; //Elem = int 라는 뜻 입니다.

class Nodelist { //Nodelist 클래스를 정의합니다.
private:
	//Node 정의
	//Doubly linked list 이므로 next 뿐만 아니라, prev도 존재합니다.
	struct Node { 
		Elem elem; // 데이터 저장장소
		Node* prev;
		Node* next;
	};
public:
	//Iterator 정의
	class Iterator {
	public:
		Elem& operator*();
		bool operator==(const Iterator& p)const;
		bool operator!=(const Iterator& p)const;
		Iterator& operator++();
		Iterator& operator--();
		friend class Nodelist; //이 friend 선언으로 인해, 
		//iterator의 모든것을 Nodelist 클래스가 사용하는 것을 허가합니다.
	private: 
		Node* v;
		Iterator(Node *u);
	};
public:
	//Nodelist class내에서 각 함수를 정의해주었습니다.
	Nodelist() { 
		n = 0; //int Nodelist::n 입니다.
		header = new Node; //for header 
		trailer = new Node; //for trailer
		header->next = trailer; //point each other
		trailer->prev = header;
	};
	int size() const {
		return n; //n이 count이므로,
	};
	bool empty() const {
		return (n == 0); //만약 n==0 이면 1 rtn
	};
	
	Iterator begin() const;
	Iterator end() const; //밖에서 정의해줌

	void insertFront(const Elem& e) { //insert at front
		insert(begin(), e);
	}
	void insertBack(const Elem& e) { //insert at rear
		insert(end(), e);
	}
	void insert(const Iterator &p, const Elem &e) {
		Node* w = p.v; //p의 Node
		Node* u = w->prev; //p의 predecessor
		Node* v = new Node; //! new Node to insert !
		v->elem = e; //New Node에 data(element) 입력, 이는 int형식과 같음
		v->next = w; w->prev = v; // link in v before w
		v->prev = u; u->next = v; // link in v after u
		n++; //node가 insert되면 n(=node의 개수)에 +1을 해줍니다.
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
		n--; //node가 delete되면 n(=node의 개수)에 -1을 해줍니다.
	}

private: //data들
	int n; 
	Node* header;
	Node* trailer;
};

//Iterator 함수들 여기서 정의해준 것임. 저기 위에서 해줘도 되긴 함

Nodelist::Iterator::Iterator(Node* u) { //Node 값 u를 받아와서,
	v = u; 
	//v에 입력해줍니다. 
	//이는 Iterator 클래스 안의 private: Node* v 변수입니다.
}

Elem& Nodelist::Iterator::operator*() { 
	//Elem& = int& 입니다. 즉, 이함수는 int 값을 rtn합니다.
	
	return v->elem; //elem은 Node 의 data 입니다.
	//v의 element, = node의 포인터 입니다.
}

bool Nodelist::Iterator::operator==(const Iterator& p)const {
	return v == p.v;
	//같으면 1 rtn
}

bool Nodelist::Iterator::operator!=(const Iterator& p)const {
	return v != p.v;
	//다르면 1 rtn
}

//얘네 앞에 Nodelist::
Nodelist::Iterator& Nodelist::Iterator::operator++() {
	v = v->next; //현 값을 next의 값으로 update 해준후,
	return *this; //그 update된 값을 rtn합니다.
}

Nodelist::Iterator& Nodelist::Iterator::operator--() {
	v = v->prev; //현 값을 prev의 값으로 update 해준후,
	return *this; //그 update된 값을 rtn합니다.
}

 //이것도 밖에서 정의해준것 뿐임
Nodelist::Iterator Nodelist::begin() const {
	return Iterator(header->next);
	//()안의 내용의 형식은 Node* 입니다.
	//Iterator 생성자 함수가 작동되면서,값이 update됩니다.
}

Nodelist::Iterator Nodelist::end() const {
	return Iterator(trailer);
	//trailer = 맨뒤의 뒤에서 맨뒤의 next pointer를 가리키는 포인터 
}

//이 함수는 iterator를 사용하지 않았습니다.
int vectorSum1(const vector<int>& V) {
	int sum = 0; //총합의 값이 들어가게 될 변수

	for (int i = 0; i < V.size(); i++) { //vector의 크기만큼 반복합니다.
		sum += V[i]; //vetor[] 안의 총 합을 구합니다.
	}
	return sum; //그 총합값을 rtn합니다.
}

int vectorSum2(vector<int> V) {
	typedef vector<int>::iterator Iterator; 
	//Iterator = vector<int>::iterator
	//Iterator 는 int형 vector클래스의 iterator함수임을 의미합니다.

	int sum = 0; //총합의 값이 들어가게 될 변수
	for (Iterator p = V.begin() ; p != V.end() ; ++p) {
		sum += *p;
		//*p = 10 과 같이 *p의 값 변경가능
	}
	return sum; //그 총합값을 rtn합니다.
}

int vectorSum3(const vector<int> V) {
	typedef vector<int>::const_iterator ConstIterator;
	//ConstIterator = vector<int>::const_iterator 
	//ConstIterator 는 int형 vector클래스의 const_iterator함수임을 의미

	int sum = 0; //총합의 값이 들어가게 될 변수
	for (ConstIterator p = V.begin() ; p != V.end() ; ++p) {
		sum += *p;
		//*p = 10 과 같이 *p의 값 변경 불가능
	}
	return sum; //그 총합값을 rtn합니다.
}

int main() {
	vector<int> n; //for use vector

	printf("12163291 강현지 자료구조 HW3\n\nVector values:\n");

	for (int i = 0; i < 10; i++) {
		n.push_back(i + 1);  //1부터 10까지 차례대로 vector에 넣어줍니다.
		printf("%d ", n[i]); //vector값 확인용
		if (i==9) printf("\n\n");
	}
	
	printf("Vector_Sum values:\n");
	printf("vectorSum1: %d\n", vectorSum1(n));
	printf("vectorSum2: %d\n", vectorSum2(n));
	printf("vectorSum3: %d\n", vectorSum3(n));

}