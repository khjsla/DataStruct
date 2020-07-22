#include <iostream> 
#include <string>
using namespace std;

#define MAX_CHILD 5

template<typename T> 
struct Node {
	int lv;
	char name[20];
	Node *child[MAX_CHILD]; //Nũ���� �ڽĵ��� ���� �� ����
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
				printall(current->child[i]); //�ƴҼ��� ����
				cout << current->name << " ";
			}
		}
		else {
			cout << "�ƹ��͵� �����. " << end;
		}
	}
};

//�ۿ��� ���� ���ݴϴ�.
template <typename T>
void SearchTree<T>::Insert(Node<T>* n, T val) { //� node�Ʒ��� � �� val�� ���� node�� �߰����ݴϴ�.
	int level = n->lv + 1; //���� ������ node�� lv���� n�� lv���� +1�� �ǰ� �˴ϴ�.
	
	Node<T> node = new Node<T>(); //node��� val���� ������ �� �� node����.
	node->name = val; //�� node�� name���� val�Դϴ�.
	node->lv = level; //�� node�� lv���� �ռ� ������ n����� lv���� +1 �� �� �Դϴ�.
	
	int i = 0;
	while (n->child[i]!= nullptr) { //n�� child�� nullptr �� �ƴѵ���
		i++; //+1�ϸ鼭 �������ٰ� 
	}
	
	if (i < MAX_CHILD) { //���������� �� ���� i �� node�� ���� �� �ִ� �ִ� node�� ���� ������
		n->child[i] = node; //�� node�� n�� i ��° child�� �־��ݴϴ�.
	}
	else {
		cout << "���̸� ���̻� ���� �� �����";
		//�ƴҰ�� �ִ� ���� �� �ִ� ���̺��� �� ���� ���̹Ƿ� �ȵȴٴ� cout�� ���
	}
}

template <typename T>
Node<T>* remember; //����ϱ��

template <typename T>
void SearchTree<T>::Searchlv(T val) { //���� �´� node�� ã�� ���� lv�� ����մϴ�. cout << lv
	Node<T>* ptr = root;
	Node<T>* tmpRoot = nullptr;

	int i = 0;
	int cnt = 0;
	while (ptr != nullptr) { //�����Ͱ� ���� ����������
		if (ptr->name == val) { //�������� ���� val�� ������ �� �������� ����, �������� ���� ���
			cout << val << " ���� ã�ҽ��ϴ�. ������" << ptr->lv << endl;
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
	cout << val << "�� ã�� ���߽��ϴ�." << endl;
}

template <typename T>
void SearchTree<T>::Remove(T val) { //�̸� �Է½� ������ �� �ֽ��ϴ�.

}

template <typename T>
void SearchTree<T>::setRoot(T val) { //root�� �������ݴϴ�.
	Node<T> node = new Node<T>(); //node��� node����.
	node.name = val; //������ ������ node�� val�� �Է� �� in
	node.lv = 0; //root�� ����� 0�Դϴ�.
	root = node; //�� val���� name�� node�� root�� ����.
}





//Node* find_node(Node* from, char x) {//x=ã�� �̸�
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