#include <iostream>
using namespace std;

int main() {
	int a = 10;
	int b = 100;
	int const * ptr1 = &a;
	//*ptr1 = &b;
	//*ptr1 = 20;
	a = 30;
	cout << a;
}