#include <iostream>
using namespace std;

/**
 * Recursive version to compute faculty
 */
int fakultaet(int n) {
	if (n <= 1) {
		return 1;
	} else {
		return (n * fakultaet(n - 1)); /* call recursively */
	}
}

int main(int argc, char **argv) {
	int fak[10];

	cout << "Fakultaeten:" << endl;
	for (int i = 0; i < 10; i++) {
		fak[i] = fakultaet(i);
		cout << "Die Fakultaet von " << i << " ist " << fak[i] << endl;
	}

	return 0;
}
