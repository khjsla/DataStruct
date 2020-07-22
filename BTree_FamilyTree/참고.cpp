#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
using namespace std;

typedef struct person* person_ptr;
typedef struct person {

	char parentName[20];//부모의 이름
	char name[20];
	char birth[20];
	int level;
	int gender;
	int first_degree;//촌수를 계산할때 뿌리로 올라가면서 count증가
	int flag;//동일한 부모를 찾을때 필요
	person_ptr parent;//부모의 포인터  //촌수계산
	person_ptr sibing;//형제포인터
	person_ptr child;//자식포인터
	person_ptr child_tail;//자식중의 막내에 대한 포인터 //insert 시 순회횟수를 줄이기위함

}person;

//root는 변하지 않는 시조
person_ptr root = NULL;
//search알고리즘에 필요한 pointer
person_ptr find_ = NULL;

void print_menu(); //메뉴를 출력
void init();// 시조를 생성해주고 text파일에 저장된 정보를 입력하기 위해 insert_by_conf() 함수 호출
void insertPerson(person_ptr p);//인물정보를 입력하고 부모를 찾아 삽입
void search(char* person);//이름으로 인물 찾기
void search_preorder(person_ptr p, char* person);//search에서 호출되는 함수로서 preorder로 순회
void deletePerson();//인물에 대한 정보를 지움
void insert_by_console();//console창으로 인물 정보를 입력
void insert_by_conf();//초기에 text파일에서 저장된 인물정보를 입력
void savefile();//수정된 정보를 file에 save //save파일을 호출
void save(person_ptr p, FILE *fp);//실질적인 save가 이루어지는 함수
void cal_relation();//촌수 계산해주는 함수
void flagset(person_ptr p);//첫번째 인물이 root로 올라가면서 flag를 1로 만들며 first_degree를 증가시키면서 노드 이동
int  find_common_parent(person_ptr p);//두번째 인물이 root로 올라가며 flag가 1인 노드를 찾을떄까지 count증가하며 이동
void clear_flag(person_ptr root);//flag, first_degree 초기화

void main()
{
	init();
	print_menu();
}

void cal_relation()
{
	char person1[32];
	char person2[32];
	person_ptr ptr1;
	person_ptr ptr2;
	int degree = -1;

	printf("\n계산할 사람의 이름을\n[name1, name2]형식으로 입력:");
	scanf("%s, %s", person1, person2);

	search(person1);
	if (!find_)
	{
		printf("%s 님이 존재하지 않습니다.\n", person1);
		return;
	}

	ptr1 = find_;
	search(person2);
	if (!find_)
	{
		printf("%s 님이 존재하지 않습니다.\n", person2);
		return;
	}

	ptr2 = find_;

	flagset(ptr1);
	degree = find_common_parent(ptr2);

	if (degree == -1)
	{
		printf("촌수를 계산할 수 없습니다\n");
		find_ = NULL;
		return;
	}

	find_ = NULL;

	clear_flag(ptr1);
	clear_flag(ptr2);
	printf("계산된 촌수는 %d 촌 입니다.\n", degree);

}

void flagset(person_ptr p)
{
	int count = 0;
	while (p)
	{
		p->flag = 1;
		p->first_degree += count;
		count++;
		p = p->parent;
	}
}

int find_common_parent(person_ptr p)
{
	int count = 0;
	while (p)
	{
		if (!p)
			return -1;
		if (p->flag)
			return p->first_degree + count;
		count++;
		p = p->parent;
	}
	return -1;
}
void clear_flag(person_ptr p) {

	while (p != root) {
		p->flag = 0;
		p->first_degree = 0;
		p = p->parent;
	}
	root->flag = 0;
	root->first_degree = 0;
}

void savefile() {
	FILE *fp = fopen("conf.txt", "w");
	save(root, fp);
	fclose(fp);
	printf("\nConfiguration file saved!!\n");
}

void save(person_ptr p, FILE *fp) {
	if (p != root) {
		if (p == NULL) return;
		fprintf(fp, "%s %s %s %d\n",
			p->parentName, p->name, p->birth, p->gender);
	}
	save(p->sibing, fp);
	save(p->child, fp);
}

void insert_by_conf() {

	//FILE *fp;
	//char line[128];
	//char name[32];
	//char parent[32];
	//char birth[32];
	//int gender;

	//fp = fopen("conf.txt", "r");

	//while (fgets(line, sizeof(line), fp) != NULL)
	//{
	//	person_ptr temp;

	//	temp = (person_ptr)malloc(sizeof(person));

	//	memset(temp, 0, sizeof(person));

	//	memset(parent, 0, sizeof(parent));
	//	memset(name, 0, sizeof(name));
	//	memset(birth, 0, sizeof(birth));

	//	sscanf(line, "%s %s %s %d", parent, name, birth, &gender);

	//	strcpy(temp->parentName, parent);
	//	strcpy(temp->name, name);
	//	strcpy(temp->birth, birth);
	//	temp->gender = gender;

	//	insertPerson(temp);
	//}
}

void insertPerson(person_ptr p)
{
	search(p->parentName);

	if (find_ == NULL)
	{
		printf("A parent doesn't exist!!\n");
		return;
	}

	if (!(find_->child))
	{
		p->level = (find_->level) + 1;
		find_->child = p;
		find_->child_tail = p;
	}
	else {
		p->level = (find_->level) + 1;
		find_->child_tail->sibing = p;
		find_->child_tail = p;

	}
	p->parent = find_;

	find_ = NULL;
}

void search(char* person) {
	person_ptr p = root;
	search_preorder(p, person);

}

void search_preorder(person_ptr p, char* person) {

	if (p == NULL) return;
	if (!strcmp(p->name, person))
	{
		find_ = p;
		return;
	}
	search_preorder(p->sibing, person);
	search_preorder(p->child, person);
}

void init() {
	root = (person_ptr)malloc(sizeof(person));
	memset(root, 0, sizeof(person));
	strcpy(root->name, "이성계");
	root->level = 1;
	root->sibing = root->child = NULL;

	insert_by_conf();
}


void deletePerson() {
	char insert_name[32];

	printf("\nDelete Name\n: ");
	scanf("%s", insert_name);
	search(insert_name);

	if (find_ == NULL)
	{
		printf("A person doesn't exist!!\n");
		return;
	}
	else {
		printf("find_ name %s is removed!\n", find_->name);
		strcpy(find_->name, " ");
	}
	find_ = NULL;
}


void insert_by_console() {

	person_ptr new_node;
	char parent[32];
	char insert_name[32];
	char insert_birth[32];
	int insert_gender;


	new_node = (person_ptr)malloc(sizeof(person));

	memset(new_node, 0, sizeof(person));

	printf("\nEnter Name\n: ");
	scanf("%s", insert_name);
	strcpy(new_node->name, insert_name);


	printf("\nEnter Parent\n: ");
	scanf("%s", parent);
	strcpy(new_node->parentName, parent);


	printf("\nEnter Birthday(YYYY/MM/DD)\n: ");
	scanf("%s", insert_birth);
	strcpy(new_node->birth, insert_birth);

	printf("\nEnter gender (male 0 / female 1)\n:");
	scanf("%d", &insert_gender);
	new_node->gender = insert_gender;

	insertPerson(new_node);
}


void search_person() {
	char insert_name[32];

	printf("\nSearch Name\n: ");
	scanf("%s", insert_name);
	search(insert_name);

	if (find_ == NULL)
	{
		printf("person doesn't exist!!\n");
		return;
	}
	else {
		printf("\n---------------------------------\n");
		printf("  이    름 | %s, %d대손", find_->name, find_->level);
		printf("\n  성    별 | %s\n  생년월일 | %s", (find_->gender) ? "남" : "여", find_->birth);
		printf("\n  부    모 | %s", find_->parentName);
		printf("\n---------------------------------\n");
	}

	find_ = NULL;
}


void print_menu()
{
	int c;

	printf("\n\t\t  ***************** Command ***************\n");
	printf("\t\t      1 : Command lists\n");
	printf("\t\t      2 : Insert person\n");
	printf("\t\t      3 : Search person\n");
	printf("\t\t      4 : Delete person\n");
	printf("\t\t      5 : Print degree of Relationship\n");
	printf("\t\t      6 : sAve\n");
	printf("\t\t      7 : Quit\n");
	printf("\t\t  *****************************************\n");

	while (1)
	{
		printf("\nCommand> ");
		cin >> c;

		switch (c) {
		case 1:
			putch(c);
			savefile();
			puts(" ");
			break;

		case 2:
			putch(c);
			print_menu();
			puts(" ");
			break;

		case 3:
			putch(c);
			insert_by_console();
			break;

		case 4:
			putch(c);
			search_person();
			puts(" ");
			break;

		case 5:
			putch(c);
			deletePerson();
			break;

		case 6:
			putch(c);
			puts(" ");
			exit(1);

		case 7:
			putch(c);
			cal_relation();
			break;
		default:
			printf("\nWrong Command!!!");
			break;
		}
	}
}
