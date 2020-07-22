//12163291 강현지 자료구조 pj1 TREE
#include <iostream> 
#include <string>
using namespace std;

template<typename T> struct
Node {
	Node* left;
	Node* right; //기본 바이너리
	int lv;
	//Node *child[N];//N크기의 자식들을 가직 수 있음?
	T value;
};

template <typename T> class BinarySearchTree {
public:
	BinarySearchTree() :root(nullptr) {};
	~BinarySearchTree() {};
	void AddFamily(T _value);
	bool FindFamilyLevel(T _value);
	void RemoveFamily(T _value);
	void ShowAllFamily();
private:
	Node<T>* root;
	Node<T>* tail;
	void Inorder(Node<T>* current) {
		if (current != nullptr) {
			Inorder(current->left);
			cout << current->value << " ";
			Inorder(current->right);
		}
	}

	Node<T>* SearchMaxNode(Node<T>* node) {
		if (node == NULL) {
			return NULL;
		}
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
	}
	Node<T>* RemoveSeqence(Node<T>* node, T _vaule);
};

template <typename T>
Node<T>* BinarySearchTree<T>::RemoveSeqence(Node<T>* node, T _vaule) {
	if (node == nullptr) {
		return node;
	}
	else if (node->value > _vaule) {
		node->left = RemoveSeqence(node->left, _vaule);
	}
	else if (node->value < _vaule) {
		node->right = RemoveSeqence(node->right, _vaule);
	}
	else {
		Node<T>* ptr = node; //자식이없을떄 
		if (node->right == nullptr && node->left == nullptr) {
			delete node;
			node = nullptr;
		} //자식이 하나일떄 
		else if (node->right == nullptr) {
			node = node->left;
			delete ptr;
		}
		else if (node->left == nullptr) {
			node = node->right; delete ptr;
		} //자식이 두개일떄 :: 왼쪽 노드중 가장큰값 찾아 부모노드로 바꾸기
		else {
			ptr = SearchMaxNode(node->left);
			node->value = ptr->value;
			node->left = RemoveSeqence(node->left, ptr->value);
		}
	}
	return node;
}

template <typename T>
void BinarySearchTree<T>::RemoveFamily(T _value) {
	Node<T>* ptr = root;
	RemoveSeqence(ptr, _value);
}

template<typename T>
void BinarySearchTree<T>::ShowAllFamily() {
	Inorder(root);
}

template <typename T>
bool BinarySearchTree<T>::FindFamilyLevel(T _value) {
	Node<T>* ptr = root;
	Node<T>* tmpRoot = nullptr;
	while (ptr != nullptr) { //root에서 빌때까지 끝까지 쭉 간다
		if (ptr->value == _value) {
			cout << _value << " 는(은) " << ptr->lv << "대손 입니다." << endl;
			return true;
		}
		else if (ptr->value > _value) {
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;
		}
	}
	cout << _value << " 값을 찾지 못했습니다." << endl;
	return false;
}

template <typename T>
void BinarySearchTree<T>::AddFamily(T _value) {
	Node<T>* node = new Node<T>();
	Node<T>* tmpRoot = nullptr;
	node->value = _value;
	int i = 0;
	if (root == nullptr) {
		root = node;
		root->lv = 0;
	}
	else { //root가있으면
		Node<T>* ptr = root; //ptr이 현 root 값임.
		while (ptr != nullptr) { //root가 null이 아닐때까지 
			tmpRoot = ptr; //tmproot = root값임
			if (node->value < ptr->value) { //지금 입력하려는 노드의 값< 원래있던 노드의값
				ptr = ptr->left;  //현포인터의 아래. 왼값이 현 포인터가 되게 된다
			}
			else {
				ptr = ptr->right;
			}
			i++; //root에서 child로 내려갈 떄 마다, i값에 +1을 해줍니다.
			//따라서, i는 node의 depth 값이 됩니다.
		}
		//넣을 위치에 대입 
		if (node->value < tmpRoot->value) {
			node->lv = i;
			//앞에서 i로 구한, depth (node의 lv) 을 node의 lv값에 입력합니다.
			tmpRoot->left = node;
		}
		else {
			node->lv = i;
			//앞에서 i로 구한, depth (node의 lv) 을 node의 lv값에 입력합니다.
			tmpRoot->right = node;
		}
	}
}

void first() {
	printf("1. 가족 추가\n");
	printf("2. 가족 삭제\n");
	printf("3. 몇대손 일까요?\n");
	printf("4. 가족 구성원 확인\n");
	printf("- 7 입력시 프로그램이 종료됩니다. -\n");
}
int main() {
	printf("12163291 강현지 자료구조 HW3 <<TREE>>\n");

	string name; //이름 확인
	int mode = 5; //mode 선택
	BinarySearchTree<string>* BST = new BinarySearchTree<string>();

	while (mode != 9)//9입력되면 끝
	{
		first();
		cin >> mode;
		switch (mode)
		{
		default:
			break;
		case 1:
			cout << "(0 입력시 가족 추가를 멈출 수 있습니다.)\n추가할 가족의 이름을 입력하세요:\n";
			while (true) {
				cin >> name;
				if (name == "0") break;
				BST->AddFamily(name);
			}
			cout << endl;
			break;
		case 2:
			cout << "삭제할 가족의 이름을 입력하세요:\n";
			cin >> name;
			BST->RemoveFamily(name);
			cout << endl;
			break;
		case 3:
			cout << "몇대손인지 확인할 가족의 이름을 입력하세요:\n";
			cin >> name;
			BST->FindFamilyLevel(name);
			cout << endl;
			break;
		case 4:
			BST->ShowAllFamily();
			cout << endl;
			cout << endl;
			break;
		}
	}

	return 0;
}
