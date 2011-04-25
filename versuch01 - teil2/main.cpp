#include <iostream>
using namespace std;

/**
 * Recursive version to compute the fibonacci numbers
 */
unsigned int fib(unsigned int n) {
	if (n < 2) {
		return n;
	}
	else {
		return fib(n - 1) + fib(n - 2); /* call recursively */
	}
}

int main(int argc, char **argv) {
	cout << "Fibonacci-Zahlen:" << endl;
	for (int i = 1; i <= 42; i++) {
		cout << "f(" << i << ") = " << fib(i) << endl;
	}

	return 0;
}
