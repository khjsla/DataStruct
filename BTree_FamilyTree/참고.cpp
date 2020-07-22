#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
using namespace std;

typedef struct person* person_ptr;
typedef struct person {

	char parentName[20];//�θ��� �̸�
	char name[20];
	char birth[20];
	int level;
	int gender;
	int first_degree;//�̼��� ����Ҷ� �Ѹ��� �ö󰡸鼭 count����
	int flag;//������ �θ� ã���� �ʿ�
	person_ptr parent;//�θ��� ������  //�̼����
	person_ptr sibing;//����������
	person_ptr child;//�ڽ�������
	person_ptr child_tail;//�ڽ����� ������ ���� ������ //insert �� ��ȸȽ���� ���̱�����

}person;

//root�� ������ �ʴ� ����
person_ptr root = NULL;
//search�˰��� �ʿ��� pointer
person_ptr find_ = NULL;

void print_menu(); //�޴��� ���
void init();// ������ �������ְ� text���Ͽ� ����� ������ �Է��ϱ� ���� insert_by_conf() �Լ� ȣ��
void insertPerson(person_ptr p);//�ι������� �Է��ϰ� �θ� ã�� ����
void search(char* person);//�̸����� �ι� ã��
void search_preorder(person_ptr p, char* person);//search���� ȣ��Ǵ� �Լ��μ� preorder�� ��ȸ
void deletePerson();//�ι��� ���� ������ ����
void insert_by_console();//consoleâ���� �ι� ������ �Է�
void insert_by_conf();//�ʱ⿡ text���Ͽ��� ����� �ι������� �Է�
void savefile();//������ ������ file�� save //save������ ȣ��
void save(person_ptr p, FILE *fp);//�������� save�� �̷������ �Լ�
void cal_relation();//�̼� ������ִ� �Լ�
void flagset(person_ptr p);//ù��° �ι��� root�� �ö󰡸鼭 flag�� 1�� ����� first_degree�� ������Ű�鼭 ��� �̵�
int  find_common_parent(person_ptr p);//�ι�° �ι��� root�� �ö󰡸� flag�� 1�� ��带 ã�������� count�����ϸ� �̵�
void clear_flag(person_ptr root);//flag, first_degree �ʱ�ȭ

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

	printf("\n����� ����� �̸���\n[name1, name2]�������� �Է�:");
	scanf("%s, %s", person1, person2);

	search(person1);
	if (!find_)
	{
		printf("%s ���� �������� �ʽ��ϴ�.\n", person1);
		return;
	}

	ptr1 = find_;
	search(person2);
	if (!find_)
	{
		printf("%s ���� �������� �ʽ��ϴ�.\n", person2);
		return;
	}

	ptr2 = find_;

	flagset(ptr1);
	degree = find_common_parent(ptr2);

	if (degree == -1)
	{
		printf("�̼��� ����� �� �����ϴ�\n");
		find_ = NULL;
		return;
	}

	find_ = NULL;

	clear_flag(ptr1);
	clear_flag(ptr2);
	printf("���� �̼��� %d �� �Դϴ�.\n", degree);

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
	strcpy(root->name, "�̼���");
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
		printf("  ��    �� | %s, %d���", find_->name, find_->level);
		printf("\n  ��    �� | %s\n  ������� | %s", (find_->gender) ? "��" : "��", find_->birth);
		printf("\n  ��    �� | %s", find_->parentName);
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
