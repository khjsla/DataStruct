#include <stdio.h>
using namespace std;

int main() {
	int i;
	float f = 0.0f;
	for (i = 0; i < 1000;i++) {
		f += 0.1f;
	}

	printf("f=%f\n", f);
	return 0;
}