#include <iostream>
#include "Dec.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

	Deque <int> a;
	for (int i = 0; i < 10; i++) {
		a.pushFront(rand()%100);
	}

	a.printFront();
	a.printEnd();
}