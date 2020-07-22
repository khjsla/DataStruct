//12163291 ������ �ڷᱸ�� pj1 TREE
#include <iostream> 
#include <string>
using namespace std;

template<typename T> struct
Node {
	Node* left;
	Node* right; //�⺻ ���̳ʸ�
	int lv;
	//Node *child[N];//Nũ���� �ڽĵ��� ���� �� ����?
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
		Node<T>* ptr = node; //�ڽ��̾����� 
		if (node->right == nullptr && node->left == nullptr) {
			delete node;
			node = nullptr;
		} //�ڽ��� �ϳ��ϋ� 
		else if (node->right == nullptr) {
			node = node->left;
			delete ptr;
		}
		else if (node->left == nullptr) {
			node = node->right; delete ptr;
		} //�ڽ��� �ΰ��ϋ� :: ���� ����� ����ū�� ã�� �θ���� �ٲٱ�
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
	while (ptr != nullptr) { //root���� �������� ������ �� ����
		if (ptr->value == _value) {
			cout << _value << " ��(��) " << ptr->lv << "��� �Դϴ�." << endl;
			return true;
		}
		else if (ptr->value > _value) {
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;
		}
	}
	cout << _value << " ���� ã�� ���߽��ϴ�." << endl;
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
	else { //root��������
		Node<T>* ptr = root; //ptr�� �� root ����.
		while (ptr != nullptr) { //root�� null�� �ƴҶ����� 
			tmpRoot = ptr; //tmproot = root����
			if (node->value < ptr->value) { //���� �Է��Ϸ��� ����� ��< �����ִ� ����ǰ�
				ptr = ptr->left;  //���������� �Ʒ�. �ް��� �� �����Ͱ� �ǰ� �ȴ�
			}
			else {
				ptr = ptr->right;
			}
			i++; //root���� child�� ������ �� ����, i���� +1�� ���ݴϴ�.
			//����, i�� node�� depth ���� �˴ϴ�.
		}
		//���� ��ġ�� ���� 
		if (node->value < tmpRoot->value) {
			node->lv = i;
			//�տ��� i�� ����, depth (node�� lv) �� node�� lv���� �Է��մϴ�.
			tmpRoot->left = node;
		}
		else {
			node->lv = i;
			//�տ��� i�� ����, depth (node�� lv) �� node�� lv���� �Է��մϴ�.
			tmpRoot->right = node;
		}
	}
}

void first() {
	printf("1. ���� �߰�\n");
	printf("2. ���� ����\n");
	printf("3. ���� �ϱ��?\n");
	printf("4. ���� ������ Ȯ��\n");
	printf("- 7 �Է½� ���α׷��� ����˴ϴ�. -\n");
}
int main() {
	printf("12163291 ������ �ڷᱸ�� HW3 <<TREE>>\n");

	string name; //�̸� Ȯ��
	int mode = 5; //mode ����
	BinarySearchTree<string>* BST = new BinarySearchTree<string>();

	while (mode != 9)//9�ԷµǸ� ��
	{
		first();
		cin >> mode;
		switch (mode)
		{
		default:
			break;
		case 1:
			cout << "(0 �Է½� ���� �߰��� ���� �� �ֽ��ϴ�.)\n�߰��� ������ �̸��� �Է��ϼ���:\n";
			while (true) {
				cin >> name;
				if (name == "0") break;
				BST->AddFamily(name);
			}
			cout << endl;
			break;
		case 2:
			cout << "������ ������ �̸��� �Է��ϼ���:\n";
			cin >> name;
			BST->RemoveFamily(name);
			cout << endl;
			break;
		case 3:
			cout << "�������� Ȯ���� ������ �̸��� �Է��ϼ���:\n";
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
