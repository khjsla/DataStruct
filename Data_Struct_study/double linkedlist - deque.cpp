//#include <iostream>
//using namespace std;
//
//struct node {
//	int data;
//	node *prev, *next;
//
//	static node* getNode(int data) {
//		node* new_node = new node();
//		new_node->data = data;
//		new_node->prev = new_node->next = NULL;
//		return new_node; //���ο� ��� �߰� �� ���ο� ����� ���� ������ null
//	}
//};
//
//class deque {
//	node* front;
//	node* rear;
//	int size;
//
//public:
//	deque() {
//		front = rear = NULL;
//		size = 0;
//	}
//
//	void insertFront(int data);
//	void insertRear(int data);
//	void delFront();
//	void delRear();
//	int getFront();
//	int getRear();
//	int getSize();
//	bool isEmpty();
//	void erase();
//	void display();
//};
//
//bool deque::isEmpty() {
//	return (front == NULL);
//}
//
//int deque::getSize() {
//	return size;
//}
//
//void deque::insertFront(int data) {
//	node* new_node = node::getNode(data);
//	if (new_node == NULL) {
//		cout << "deque overflow";
//	}
//	else {
//		cout << "insertFront : " << data;
//		if (front == NULL) {
//			rear = front = new_node; // ��������� �� ����
//		}
//		else {
//			new_node->next = front; //double�̱� ������ ���ο� ��� ������ ����Ʈ
//			//�տ� �߰��Ǵ� �Ŵϱ�
//			front->prev = new_node; // front���� �����
//			front = new_node; // ������ ����尡 ��
//		}
//
//		size++; //������ ����
//	}
//	cout << endl;
//}
//
//void deque::insertRear(int data) {
//	node* new_node = node::getNode(data);
//	if (new_node == NULL) {
//		cout << "deque overflow"; //new_node�� null�̸� �� á�ٴ� ��
//	}
//	else {
//		cout << "insertRear : " << data;
//		if (rear == NULL) {
//			front = rear = new_node; //�ƹ��͵� ������ �� ����
//		}
//		else {
//			new_node->prev = rear;
//			rear->next = new_node;
//			rear = new_node;
//		}
//		size++;
//	}
//	cout << endl;
//}
//
//void deque::delFront() {
//	if (isEmpty()) {
//		cout << "deque underflow";
//	}
//	else { //ť�� �����ϳ��� �ִٸ�
//		cout << "delFront : " << front->data;
//		node* temp = front; //�ӽ÷� ����Ʈ ����
//		front = front->next; // ����Ʈ�� �����Ǳ� ������ ����Ʈ��
//		//���� ����Ʈ ������ �ȴ�
//
//		if (front == NULL) {
//			rear = NULL; //���ο� ����Ʈ�� ������ rear�� NULL
//		}
//		else {
//			front->prev = NULL; //������ front �� ���� �����Ƿ� NULL
//		}
//		free(temp);
//		size--; //���������Ƿ� ũ�� �پ��
//	}
//	cout << endl;
//}
//
//void deque::delRear() {
//	if (isEmpty()) {
//		cout << "deque underflow";
//	}
//	else {
//		cout << "delRear : " << rear->data;
//
//		node* temp = rear; //�ڿ��� �����ϴϱ� rear�� �ʱ�ȭ
//		rear = rear->prev; //���ο� ����� ���� ���� ��
//
//		if (rear == NULL) {
//			front = NULL; //���� ������ ����Ʈ�� ����(�ֳĸ� ���ο� ����� ���� ���� ���̴ϱ�)
//		}
//		else {
//			rear->next = NULL; //��� null�� �ƴϸ� ��������� null ���̱� ����
//		}
//		free(temp);
//		size--; //�����߱� ������ size ����
//	}
//	cout << endl;
//}
//
//int deque::getFront() {
//	if (isEmpty()) {
//		return -1;
//	}
//	else {
//		return front->data;
//	}
//}
//
//int deque::getRear() {
//	if (isEmpty()) {
//		return -1;
//	}
//	else {
//		return rear->data;
//	}
//}
//
//void deque::erase() { //��ü����
//	rear = NULL;
//	node* temp = front;
//	while (temp != NULL) {
//		free(temp);
//		temp = temp->next;
//	}
//	size = 0;
//}
//
//void deque::display() {
//	node* temp = front;
//	cout << "deque element : ";
//	while (temp != NULL) {
//		cout << temp->data << " ";
//		temp = temp->next;
//	}
//	cout << endl;
//}
//
//int main() {
//	deque dq;
//
//	dq.insertFront(-1);
//	dq.insertFront(-2);
//	dq.insertFront(-3);
//
//	dq.display();
//
//	dq.insertRear(1);
//	dq.insertRear(2);
//	dq.insertRear(3);
//
//	dq.display();
//
//	cout << "current front : " << dq.getFront() << " current rear : " << dq.getRear() << endl;
//
//	dq.delFront();
//	dq.delRear();
//
//	dq.display();
//
//	cout << "current front : " << dq.getFront() << " current rear : " << dq.getRear() << endl;
//
//	return 0;
//}
