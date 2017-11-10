#include <iostream>
#include "Dec.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

	Deque <int> a;
	for (int i = 0; i < 10; i++) {
		a.pushFront(i);
		cout << i << endl;
	}

	a.printFront();
	a.printEnd();

	a.popFront();

	a.printFront();
	a.printEnd();

	a.popEnd();

	a.printFront();
	a.printEnd();

}