#include <iostream>
using namespace std;

/**
 * Iterative version
 *
 * fib(47) > 2^32 => overflow!!
 * use unsigned or long int types!
 */
int fib(int n) {
	int prevFib = 0;
	int curFib = 1;

	if (n < 2) {
		return n;
	}

	for (int i = 2; i <= n; i++) {
		int newFib = prevFib + curFib;
		prevFib = curFib;
		curFib = newFib;
	}

	return curFib;
}

int main(int argc, char **argv) {
	cout << "Fibonacci-Zahlen:" << endl;
	for (int i = 1; i <= 42; i++) {
		cout << "f(" << i << ") = " << fib(i) << endl;
	}

	return 0;
}

