#include <iostream>
using namespace std;

int main() {
	printf("%d\n", 32 % 13);
	printf("%d\n", 31 % 13);
	printf("%d\n", 73 % 13);
	printf("%d\n", 18 % 13);
	printf("18충돌해서 %d\n", 7-(18 % 7));
	printf("%d\n", 41 % 13);
	printf("%d\n", 22 % 13);
	printf("%d\n", 44 % 13);
	printf("44충돌해서 %d\n", 7 - (44 % 7));
	printf("%d\n", 57 % 13);
	printf("57충돌해서 %d\n", 7 - (57 % 7));

}