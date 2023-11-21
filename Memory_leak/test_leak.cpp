#include <iostream>
using namespace std;

int main() {
	int *p = new int[1000]; // we have a memory leak here
	return 0;
}