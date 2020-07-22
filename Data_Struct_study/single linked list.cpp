////Âü°í
//#include<string>
//#include<iostream>
//using namespace std;
//
//class LinkedListStack {
//
//	struct Node
//	{
//		int data;
//		Node * next;
//	};
//
//public:
//	LinkedListStack(){
//		top = nullptr;
//		size = 0;
//	}
//
//	~LinkedListStack(){
//		Node * tempNode;
//		while (top)	{
//			tempNode = top;
//			delete top;
//			top = tempNode->next;
//		}
//		delete tempNode;
//	}
//
//	void push(int value){
//		Node * n = new Node;
//
//		n->data = value;
//		n->next = top;
//
//		top = n;
//
//		size++;
//	}
//
//	int pop(){
//		if (top != nullptr){
//			int value = top->data;
//			Node * tempNode = top;
//
//			delete top;
//
//			top = tempNode->next;
//
//			delete tempNode;
//
//			return value;
//		}
//		else{
//			cout << "Empty stack" << endl;
//			return 0;
//		}
//	}
//
//	bool isEmpty(){
//		return size == 0;
//	}
//
//private:
//	Node * top;
//	int size;
//};
//
//
//int main() {
//
//}