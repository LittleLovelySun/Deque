#include <iostream>
#include "Dec.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	WordDeq a;
	string s;
	while(getline(cin, s)) {
		a.pushFront(s);
	}

	a.printFront("front:");
	a.printEnd("end:");

	a.Sort();
	cout << endl;

	a.printFront("front(sort):");
	a.printEnd("end(sort):");

	a.popFront();

	a.printFront("front(popfront):");
	a.printEnd("end(popfront):");

	a.popEnd();

	a.printFront("front(popend):");
	a.printEnd("end(popend):");
}