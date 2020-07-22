#include <iostream> 
#include <string>
using namespace std;

#define MAX_CHILD 5

template<typename T> 
struct Node {
	int lv;
	char name[20];
	Node *child[MAX_CHILD]; //N크기의 자식들을 가질 수 있음
};

template <typename T>
class SearchTree {
public:
	SearchTree() :root(nullptr) {};
	void Insert(Node<T>* node, T val);
	void Searchlv(T val);
	void Remove(T val);
	void setRoot(T val);
private:
	Node<T>* root;
	Node<T>* tail;
	void printall(Node<T>* current) {
		cout << "print all: ";

		if (current != nullptr) {
			for (int i = 0; i < MAX_CHILD; i++) {
				printall(current->child[i]); //아닐수도 있음
				cout << current->name << " ";
			}
		}
		else {
			cout << "아무것도 없어요. " << end;
		}
	}
};

//밖에서 정의 해줍니다.
template <typename T>
void SearchTree<T>::Insert(Node<T>* n, T val) { //어떤 node아래에 어떤 값 val을 가진 node를 추가해줍니다.
	int level = n->lv + 1; //새로 들어오는 node의 lv값은 n의 lv값의 +1이 되게 됩니다.
	
	Node<T> node = new Node<T>(); //node라는 val값을 가지게 될 새 node설정.
	node->name = val; //새 node의 name값은 val입니다.
	node->lv = level; //새 node의 lv값은 앞서 설정한 n노드의 lv값의 +1 한 값 입니다.
	
	int i = 0;
	while (n->child[i]!= nullptr) { //n의 child가 nullptr 가 아닌동안
		i++; //+1하면서 돌려보다가 
	}
	
	if (i < MAX_CHILD) { //빠져나오게 된 떄의 i 가 node가 가질 수 있는 최대 node값 보다 작으면
		n->child[i] = node; //그 node를 n의 i 번째 child로 넣어줍니다.
	}
	else {
		cout << "아이를 더이상 낳을 수 없어요";
		//아닐경우 최대 가질 수 있는 아이보다 더 가진 것이므로 안된다는 cout문 출력
	}
}

template <typename T>
Node<T>* remember; //기억하기용

template <typename T>
void SearchTree<T>::Searchlv(T val) { //값에 맞는 node를 찾아 그의 lv를 출력합니다. cout << lv
	Node<T>* ptr = root;
	Node<T>* tmpRoot = nullptr;

	int i = 0;
	int cnt = 0;
	while (ptr != nullptr) { //포인터가 비지 않을때까지
		if (ptr->name == val) { //포인터의 값이 val와 같으면 그 포인터의 값과, 포인터의 레벨 출력
			cout << val << " 값을 찾았습니다. 레벨은" << ptr->lv << endl;
		}
		else if (cnt!=1&&i == 0) {
			remember = ptr;
			ptr = remember->child[i];
			i++;
		}
		else if (cnt != 1 && 0 < i < MAX_CHILD - 1) {
			ptr = remember->child[i];
			i++;
		}
		else if (cnt != 1 && i == MAX_CHILD - 1) {
			ptr = ptr->child[0];
			i = 0;
			cnt = 1;
		}
		else if (cnt == 1 && i == 0) {

		}

	}
	cout << val << "를 찾지 못했습니다." << endl;
}

template <typename T>
void SearchTree<T>::Remove(T val) { //이름 입력시 삭제할 수 있습니다.

}

template <typename T>
void SearchTree<T>::setRoot(T val) { //root를 설정해줍니다.
	Node<T> node = new Node<T>(); //node라는 node설정.
	node.name = val; //위에서 설정한 node의 val에 입력 값 in
	node.lv = 0; //root의 대손은 0입니다.
	root = node; //이 val값이 name인 node를 root로 설정.
}





//Node* find_node(Node* from, char x) {//x=찾는 이름
//	// stop case
//	if (from == NULL) {
//		return NULL;
//	}
//	if (from->name == x) return from;
//	// first we'll recurse on the siblings
//	struct Node *found;
//	if ((found = find_node(from->right_sibling, x) != NULL)
//		return found;
//		// if not found we recurse on the children
//		return find_node(from->first_child, x);
//}
//
//struct tree_node* find(struct n_tree* tree, int key) {
//	return find_node(tree->root, key);
//}